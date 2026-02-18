from typing import Optional
import uuid
import sys
import argparse
import asyncio
import struct

from bleak import BleakScanner, BleakClient
from bleak.backends.device import BLEDevice
from bleak.backends.scanner import AdvertisementData
from bleak.backends.characteristic import BleakGATTCharacteristic

from .packet_data_converter import dot_sensor_decode, dash_sensor_decode, encode_cmd
from .wwRobot import WWRobot
from .wwConstants import WWRobotConstants
from WonderPy.core import wwMain


class WWException(Exception):
        pass

ScanResults = tuple[BLEDevice, AdvertisementData]

def robot_from_device(result: ScanResults) -> WWRobot:
    name = result[0].name if result[0].name else ''
    # Usually the manufacturer data is a key for the manufacturer's official Bluetooth ID:
    # https://www.bluetooth.com/specifications/assigned-numbers/company-identifiers/
    # Instead, these bots use the key to store data. In fact, all the relevant data for
    # identifying the bot is in this key.
    if len(result[1].manufacturer_data) == 1:
        key = next(iter(result[1].manufacturer_data))
        data = struct.pack('<H', key)
    else:
        data = b''
    return WWRobot(data, name) 

# Define service and characteristic UUIDs used by the WW devices.
WW_SERVICE_UUID_D1     = uuid.UUID('AF237777-879D-6186-1F49-DECA0E85D9C1')   # dash and dot
WW_SERVICE_UUID_D2     = uuid.UUID('AF237778-879D-6186-1F49-DECA0E85D9C1')   # cue
WW_SERVICE_IDS         = [WW_SERVICE_UUID_D1, WW_SERVICE_UUID_D2]

CHAR_UUID_CMD          = uuid.UUID('AF230002-879D-6186-1F49-DECA0E85D9C1')   # command channel
CHAR_UUID_SENSOR0      = uuid.UUID('AF230003-879D-6186-1F49-DECA0E85D9C1')   # sensor channel 0 (all robots)
CHAR_UUID_SENSOR1      = uuid.UUID('AF230006-879D-6186-1F49-DECA0E85D9C1')   # sensor channel 1 (dash and cue)

# this is used to renegotiate the BTLE connection interval exactly once after establishing connection.
# this value should be as large as possible while being less than about 50ms
# and also without accumulating ping latency.
# typically we're able to just use the default of about 30ms,
# but with the python/osx version we find that a smaller value is needed.
CONNECTION_INTERVAL_MS  = 12


class WWBTLEManager:

    def __init__(self, delegate, arguments=None):

        if arguments is None:
            parser = argparse.ArgumentParser(description='Options.')
            WWBTLEManager.setup_argument_parser(parser)
            arguments = parser.parse_args()

        self._args = arguments

        self.delegate = delegate

        self.robot:Optional[WWRobot] = None

        self.client: Optional[BleakClient] = None

    @staticmethod
    def setup_argument_parser(parser):
        parser.add_argument('--connect-name', metavar='a_robot_name', type=str, nargs='+',
                            help='only connect to robots of this name')
        parser.add_argument('--connect-type', metavar='(dash | dot | cue)', type=str, nargs='+',
                            help='only connect to robots of this name')
        parser.add_argument('--connect-eager', action='store_true',
                            help='immediately connect upon finding any qualifying robot')
        parser.add_argument('--connect-patient', action='store_true',
                            help='always wait the full scan period before looking at what we\'ve caught')
        parser.add_argument('--connect-ask', action='store_true',
                            help='interactively ask which of the qualifying robots you\'d like to connect to')

    async def scan_and_connect(self):
        # Capture the asyncio loop used for Bleak
        wwMain.thread_local_data.bleak_loop = asyncio.get_running_loop()

        # Scan for WW devices
        filter_types = "(all)"
        if self._args.connect_type is not None:
            filter_types = ', '.join(self._args.connect_type)
        filter_names = "(any)"
        if self._args.connect_name is not None:
            filter_names = ', '.join(self._args.connect_name)
        print('Searching for robot types: {} with names: {}.'.format(filter_types, filter_names))

        # Bleak requires scanning with a timeout
        ticks_min = 5
        ticks_max = 20
        ticks = 0
        devices: dict[str, ScanResults] = {}
        devices_no: dict[str, ScanResults] = {}

        scanner = BleakScanner()

        while ticks < ticks_max:
            # Scan for devices with the WW service UUIDs
            detected_devices = await scanner.discover(timeout=1.0, return_adv=True)
            
            for scanned_device, advertisement_data in detected_devices.values():
                # Check if device has any of the WW service UUIDs
                service_uuids = advertisement_data.service_uuids
                has_ww_service = any(
                    str(uuid.UUID(service_uuid)).lower() == str(ww_uuid).lower()
                    for service_uuid in service_uuids
                    for ww_uuid in WW_SERVICE_IDS
                )
                
                if not has_ww_service:
                    continue

                # Try to create a WWRobot from the detected device
                # We need to connect temporarily to get device info
                try:
                    async with BleakClient(scanned_device.address, timeout=30) as temp_client:
                        rob = robot_from_device((scanned_device, advertisement_data))
                        
                        # Apply filters
                        it_passes = True

                        # Filter by name
                        if self._args.connect_name is not None:
                            p = False
                            for n in self._args.connect_name:
                                if n.lower() == rob.name.lower():
                                    p = True
                            it_passes = it_passes and p

                        # Filter by type
                        if self._args.connect_type is not None:
                            p = False
                            for t in self._args.connect_type:
                                t = t.lower()
                                if t == "cue":
                                    rt = WWRobotConstants.RobotType.WW_ROBOT_CUE
                                elif t == "dash":
                                    rt = WWRobotConstants.RobotType.WW_ROBOT_DASH
                                elif t == "dot":
                                    rt = WWRobotConstants.RobotType.WW_ROBOT_DOT
                                else:
                                    raise RuntimeError("unhandled robot type option: %s" % (t))

                                if rob.robot_type == rt:
                                    p = True

                            it_passes = it_passes and p

                        if it_passes:
                            devices[str(scanned_device)] = (scanned_device, advertisement_data)
                        else:
                            devices_no[str(scanned_device)] = (scanned_device, advertisement_data)
                except Exception:
                    # If we can't connect, skip this device for now
                    raise

            ticks += 1
            sys.stdout.write('\rmatching robots: %d  non-matching robots: %d %s%s' %
                             (len(devices), len(devices_no), '.' * ticks, ' ' * 8))
            sys.stdout.flush()

            try_right_now = False
            try_right_now = try_right_now or ((self._args.connect_eager) and (len(devices) > 0))
            try_right_now = try_right_now or ((ticks > ticks_min) and (len(devices) > 0))
            try_right_now = try_right_now and not self._args.connect_patient

            if try_right_now:
                ticks = ticks_max

        if len(devices_no) > 0:
            sys.stdout.write("found but skipping: ")
            delim = ""
            for d in devices_no.values():
                r = robot_from_device(d)
                sys.stdout.write("{}{} '{}'".format(delim, r.robot_type_name, r.name))
                delim = ', '
            sys.stdout.write('.\n')

        sys.stdout.write('\n')
        sys.stdout.flush()

        if len(devices) == 0:
            print("no suitable robots found!")
            sys.exit(1)

        # Find device with strongest signal (highest RSSI)
        loudest_device: Optional[ScanResults] = None
        for d, data in devices.values():
            if loudest_device is None or data.rssi > loudest_device[1].rssi:
                loudest_device = (d, data)

        device: Optional[ScanResults] = None

        if len(devices) == 1:
            device = next(iter(devices.values())) 
        else:
            if self._args.connect_ask:
                print("Suitable robots:")
                map = {}
                for d in devices.values():
                    r = robot_from_device(d)
                    n = len(map) + 1
                    map[str(n)] = d
                    icon = '📶' if d == loudest_device else '⏹'
                    print("%2d. %s %14s '%s'" % (n, icon, r.robot_type_name, r.name))

                device = None
                while device is None:
                    user_choice = input("Enter [%d - %d]: " % (1, len(devices)))
                    if user_choice in map:
                        device = map[user_choice]
                    elif user_choice == '':
                        device = loudest_device
                    else:
                        print("bzzzt")
            else:
                device = loudest_device
                print("found %d suitable robots, choosing the best signal" % (len(devices)))

        if device is None:
            print("no suitable robots found!")
            sys.exit(1)

        self.robot = robot_from_device(device)
        # Create a wrapper to call async sendJson from sync context
        def sync_sendJson(json_dict):
            # NOTE: The caller does not block for this to complete.
            asyncio.run_coroutine_threadsafe(self.sendJson(json_dict), wwMain.thread_local_data.bleak_loop)
        self.robot._sendJson = sync_sendJson

        print('Connecting to ' + self.robot.robot_type_name + ' "%s"' % (self.robot.name))

        # Connect to the device
        self.client = BleakClient(device[0].address)
        await self.client.connect()

        await self._send_connection_interval_renegotiation()

        # Setup notification callbacks
        async def on_data_sensor(sender: BleakGATTCharacteristic, data: bytearray):
            assert self.robot is not None
            new_sensor_data = None
 
            if uuid.UUID(sender.uuid) == CHAR_UUID_SENSOR0:
                if not self.robot.expect_sensor_packet_2:
                    new_sensor_data = dot_sensor_decode(data)
                else:
                    self.robot._sensor_packet_1 = data
            else:
                if self.robot._sensor_packet_1 is not None:
                    new_sensor_data = dot_sensor_decode(self.robot._sensor_packet_1)
                    new_sensor_data.update(dash_sensor_decode(self.robot._sensor_packet_1, data))
                    self.robot._sensor_packet_1 = None

            if new_sensor_data is not None:
                self.robot._parse_sensors(new_sensor_data)
                if hasattr(self.delegate, 'on_sensors'):
                    wwMain.thread_local_data.in_on_sensors = True
                    if asyncio.iscoroutinefunction(self.delegate.on_sensors):
                        await self.delegate.on_sensors(self.robot)
                    elif callable(self.delegate.on_sensors):
                        self.delegate.on_sensors(self.robot)
                    wwMain.thread_local_data.in_on_sensors = False

            # actually send the commands which have queued up via stage_foo()
            self.robot.send_staged()

        # Start notifications
        await self.client.start_notify(CHAR_UUID_SENSOR0, on_data_sensor)
        if self.robot.expect_sensor_packet_2:
            await self.client.start_notify(CHAR_UUID_SENSOR1, on_data_sensor)

        print('Connected to \'%s\'!' % (self.robot.name))

        if hasattr(self.delegate, 'on_connect'):
            wwMain.thread_local_data.in_on_connect = True
            if asyncio.iscoroutinefunction(self.delegate.on_connect):
                await self.delegate.on_connect(self.robot)
            elif callable(self.delegate.on_connect):
                self.delegate.on_connect(self.robot)
            wwMain.thread_local_data.in_on_connect = False

        try:
            while True:
                await asyncio.sleep(1)
        except (KeyboardInterrupt, asyncio.CancelledError):
            sys.stdout.write('Stopping...\n')
            sys.stdout.flush()
    
        finally:
            await self.client.stop_notify(CHAR_UUID_SENSOR0)
            if self.robot.expect_sensor_packet_2:
                await self.client.stop_notify(CHAR_UUID_SENSOR1)
            await self.client.disconnect()

    async def _send_connection_interval_renegotiation(self):
        assert self.client is not None
        # print('Sending renegotiation request for %dms' % (CONNECTION_INTERVAL_MS))
        ba = bytearray(3)
        ba[0] = 0xc9
        ba[1] = CONNECTION_INTERVAL_MS
        ba[2] = CONNECTION_INTERVAL_MS
        await self.client.write_gatt_char(CHAR_UUID_CMD, ba)

    async def sendJson(self, cmd_dict):
        assert self.client is not None
        if len(cmd_dict) == 0:
            return

        packets = encode_cmd(cmd_dict)
        for packet in packets:
            await self.client.write_gatt_char(CHAR_UUID_CMD, packet)

    def run(self):
        # Run the async scan_and_connect method using asyncio
        asyncio.run(self.scan_and_connect())

    @staticmethod
    def stop():
        bleak_loop = getattr(wwMain.thread_local_data, 'bleak_loop', None)
        if bleak_loop is not None:
            async def stop_task():
                tasks = [t for t in asyncio.all_tasks(bleak_loop) if t is not asyncio.current_task()]
                for task in tasks:
                    task.cancel()

            future = asyncio.run_coroutine_threadsafe(stop_task(), bleak_loop)
            # Wait for tasks to be canceled.
            future.result()
