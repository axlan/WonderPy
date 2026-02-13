/*
 * Decompiled export
 * Program : libWWHAL.dylib
 * Pattern : ^getProt1Sensor.+
 * Matched : 29
 * Failed  : 0
 */

/* ===== getProt1Sensor0Timestamp @ 00060210 ===== */

/* getProt1Sensor0Timestamp(prot1_packet_sensor0_t*) */

uint getProt1Sensor0Timestamp(prot1_packet_sensor0_t *param_1)

{
  return (uint)(byte)param_1[1] | ((byte)*param_1 & 0xf) << 8;
}



/* ===== getProt1Sensor0AccelX @ 000603a0 ===== */

/* getProt1Sensor0AccelX(prot1_packet_sensor0_t*) */

int getProt1Sensor0AccelX(prot1_packet_sensor0_t *param_1)

{
  ushort uVar1;
  
  uVar1 = 0;
  if (((int)((byte)param_1[4] & 0xf0) >> 4 & 8U) != 0) {
    uVar1 = 0xf000;
  }
  return (int)(short)((ushort)(byte)param_1[2] |
                      (ushort)(((int)((byte)param_1[4] & 0xf0) >> 4) << 8) | uVar1);
}



/* ===== getProt1Sensor0AccelY @ 00060420 ===== */

/* getProt1Sensor0AccelY(prot1_packet_sensor0_t*) */

int getProt1Sensor0AccelY(prot1_packet_sensor0_t *param_1)

{
  ushort uVar1;
  
  uVar1 = 0;
  if (((byte)param_1[4] & 8) != 0) {
    uVar1 = 0xf000;
  }
  return (int)(short)((ushort)(byte)param_1[3] | ((byte)param_1[4] & 0xf) << 8 | uVar1);
}



/* ===== getProt1Sensor0AccelZ @ 00060490 ===== */

/* getProt1Sensor0AccelZ(prot1_packet_sensor0_t*) */

int getProt1Sensor0AccelZ(prot1_packet_sensor0_t *param_1)

{
  ushort uVar1;
  
  uVar1 = 0;
  if (((int)((byte)param_1[5] & 0xf0) >> 4 & 8U) != 0) {
    uVar1 = 0xf000;
  }
  return (int)(short)((ushort)(byte)param_1[6] |
                      (ushort)(((int)((byte)param_1[5] & 0xf0) >> 4) << 8) | uVar1);
}



/* ===== getProt1Sensor0Event1Type @ 000605d0 ===== */

/* getProt1Sensor0Event1Type(prot1_packet_sensor0_t*) */

prot1_packet_sensor0_t getProt1Sensor0Event1Type(prot1_packet_sensor0_t *param_1)

{
  return param_1[0x13];
}



/* ===== getProt1Sensor0Event1Data @ 000605f0 ===== */

/* getProt1Sensor0Event1Data(prot1_packet_sensor0_t*) */

prot1_packet_sensor0_t * getProt1Sensor0Event1Data(prot1_packet_sensor0_t *param_1)

{
  return param_1 + 0x10;
}



/* ===== getProt1Sensor0Event2Type @ 00060610 ===== */

/* getProt1Sensor0Event2Type(prot1_packet_sensor0_t*) */

prot1_packet_sensor0_t getProt1Sensor0Event2Type(prot1_packet_sensor0_t *param_1)

{
  return param_1[0xf];
}



/* ===== getProt1Sensor0Event2Data @ 00060630 ===== */

/* getProt1Sensor0Event2Data(prot1_packet_sensor0_t*) */

prot1_packet_sensor0_t * getProt1Sensor0Event2Data(prot1_packet_sensor0_t *param_1)

{
  return param_1 + 0xc;
}



/* ===== getProt1Sensor0Buttons @ 00060650 ===== */

/* getProt1Sensor0Buttons(prot1_packet_sensor0_t*) */

int getProt1Sensor0Buttons(prot1_packet_sensor0_t *param_1)

{
  return (int)((byte)param_1[8] & 0xf0) >> 4;
}



/* ===== getProt1Sensor0FlagClap @ 00060730 ===== */

/* getProt1Sensor0FlagClap(prot1_packet_sensor0_t*) */

bool getProt1Sensor0FlagClap(prot1_packet_sensor0_t *param_1)

{
  return ((byte)param_1[0xb] & 1) != 0;
}



/* ===== getProt1Sensor0MicAmplitude @ 00060a50 ===== */

/* getProt1Sensor0MicAmplitude(prot1_packet_sensor0_t*) */

prot1_packet_sensor0_t getProt1Sensor0MicAmplitude(prot1_packet_sensor0_t *param_1)

{
  return param_1[7];
}



/* ===== getProt1Sensor0Event1Or2ClapCount @ 00060c40 ===== */

/* getProt1Sensor0Event1Or2ClapCount(unsigned char*) */

byte getProt1Sensor0Event1Or2ClapCount(uchar *param_1)

{
  return *param_1 & 0xf;
}



/* ===== getProt1Sensor0FlagKidnap @ 00060e00 ===== */

/* getProt1Sensor0FlagKidnap(prot1_packet_sensor0_t*) */

bool getProt1Sensor0FlagKidnap(prot1_packet_sensor0_t *param_1)

{
  return ((byte)param_1[0xb] & 4) != 0;
}



/* ===== getProt1Sensor0FlagStallBump @ 00060ef0 ===== */

/* getProt1Sensor0FlagStallBump(prot1_packet_sensor0_t*) */

bool getProt1Sensor0FlagStallBump(prot1_packet_sensor0_t *param_1)

{
  return ((byte)param_1[0xb] & 8) != 0;
}



/* ===== getProt1Sensor0FlagSoundPlaying @ 00060f20 ===== */

/* getProt1Sensor0FlagSoundPlaying(prot1_packet_sensor0_t*) */

bool getProt1Sensor0FlagSoundPlaying(prot1_packet_sensor0_t *param_1)

{
  return ((byte)param_1[0xb] & 2) != 0;
}



/* ===== getProt1Sensor0FlagAnimationIsPlaying @ 00060f50 ===== */

/* getProt1Sensor0FlagAnimationIsPlaying(prot1_packet_sensor0_t*) */

bool getProt1Sensor0FlagAnimationIsPlaying(prot1_packet_sensor0_t *param_1)

{
  return ((byte)param_1[0xb] & 0x40) != 0;
}



/* ===== getProt1Sensor1GyroR @ 00061140 ===== */

/* getProt1Sensor1GyroR(prot1_packet_sensor1_t*) */

int getProt1Sensor1GyroR(prot1_packet_sensor1_t *param_1)

{
  ushort uVar1;
  
  uVar1 = 0;
  if (((byte)param_1[4] & 8) != 0) {
    uVar1 = 0xf000;
  }
  return (int)(short)((ushort)(byte)param_1[5] | ((byte)param_1[4] & 0xf) << 8 | uVar1);
}



/* ===== getProt1Sensor1GyroP @ 000611b0 ===== */

/* getProt1Sensor1GyroP(prot1_packet_sensor1_t*) */

int getProt1Sensor1GyroP(prot1_packet_sensor1_t *param_1)

{
  ushort uVar1;
  
  uVar1 = 0;
  if (((int)((byte)param_1[4] & 0xf0) >> 4 & 8U) != 0) {
    uVar1 = 0xf000;
  }
  return (int)(short)((ushort)(byte)param_1[3] |
                      (ushort)(((int)((byte)param_1[4] & 0xf0) >> 4) << 8) | uVar1);
}



/* ===== getProt1Sensor1GyroY @ 00061230 ===== */

/* getProt1Sensor1GyroY(prot1_packet_sensor1_t*) */

int getProt1Sensor1GyroY(prot1_packet_sensor1_t *param_1)

{
  ushort uVar1;
  
  uVar1 = 0;
  if (((byte)*param_1 & 8) != 0) {
    uVar1 = 0xf000;
  }
  return (int)(short)((ushort)(byte)param_1[2] | ((byte)*param_1 & 0xf) << 8 | uVar1);
}



/* ===== getProt1Sensor1DistRight @ 00061430 ===== */

/* getProt1Sensor1DistRight(prot1_packet_sensor1_t*) */

prot1_packet_sensor1_t getProt1Sensor1DistRight(prot1_packet_sensor1_t *param_1)

{
  return param_1[7];
}



/* ===== getProt1Sensor1DistLeft @ 00061450 ===== */

/* getProt1Sensor1DistLeft(prot1_packet_sensor1_t*) */

prot1_packet_sensor1_t getProt1Sensor1DistLeft(prot1_packet_sensor1_t *param_1)

{
  return param_1[6];
}



/* ===== getProt1Sensor1DistRear @ 00061470 ===== */

/* getProt1Sensor1DistRear(prot1_packet_sensor1_t*) */

prot1_packet_sensor1_t getProt1Sensor1DistRear(prot1_packet_sensor1_t *param_1)

{
  return param_1[8];
}



/* ===== getProt1Sensor1EncoderLeft @ 00061710 ===== */

/* getProt1Sensor1EncoderLeft(prot1_packet_sensor1_t*) */

undefined2 getProt1Sensor1EncoderLeft(prot1_packet_sensor1_t *param_1)

{
  return *(undefined2 *)(param_1 + 0xe);
}



/* ===== getProt1Sensor1EncoderRight @ 00061730 ===== */

/* getProt1Sensor1EncoderRight(prot1_packet_sensor1_t*) */

int getProt1Sensor1EncoderRight(prot1_packet_sensor1_t *param_1)

{
  return (int)*(short *)(param_1 + 0x10);
}



/* ===== getProt1Sensor1HeadPan @ 00061850 ===== */

/* getProt1Sensor1HeadPan(prot1_packet_sensor1_t*) */

int getProt1Sensor1HeadPan(prot1_packet_sensor1_t *param_1)

{
  ushort uVar1;
  
  uVar1 = 0;
  if (((byte)param_1[0x12] & 1) != 0) {
    uVar1 = 0xfe00;
  }
  return (int)(short)((ushort)(byte)param_1[0x13] | ((byte)param_1[0x12] & 1) << 8 | uVar1);
}



/* ===== getProt1Sensor1HeadTilt @ 000618b0 ===== */

/* getProt1Sensor1HeadTilt(prot1_packet_sensor1_t*) */

int getProt1Sensor1HeadTilt(prot1_packet_sensor1_t *param_1)

{
  ushort uVar1;
  
  uVar1 = 0;
  if (((int)(uint)(byte)param_1[0x12] >> 1 & 0x40U) != 0) {
    uVar1 = 0xff80;
  }
  return (int)(short)((ushort)((int)(uint)(byte)param_1[0x12] >> 1) | uVar1);
}



/* ===== getProt1Sensor1PoseX @ 00061aa0 ===== */

/* getProt1Sensor1PoseX(prot1_packet_sensor1_t*) */

int getProt1Sensor1PoseX(prot1_packet_sensor1_t *packet_data)

{
  ushort uVar1;
  
  uVar1 = 0;
  if (((int)((byte)packet_data[9] & 0xf0) >> 4 & 8U) != 0) {
    uVar1 = 0xf000;
  }
  return (int)(short)((ushort)(byte)packet_data[10] |
                      (ushort)(((int)((byte)packet_data[9] & 0xf0) >> 4) << 8) | uVar1);
}



/* ===== getProt1Sensor1PoseY @ 00061b20 ===== */

/* getProt1Sensor1PoseY(prot1_packet_sensor1_t*) */

int getProt1Sensor1PoseY(prot1_packet_sensor1_t *param_1)

{
  ushort uVar1;
  
  uVar1 = 0;
  if (((byte)param_1[9] & 8) != 0) {
    uVar1 = 0xf000;
  }
  return (int)(short)((ushort)(byte)param_1[0xb] | ((byte)param_1[9] & 0xf) << 8 | uVar1);
}



/* ===== getProt1Sensor1PoseTheta @ 00061b90 ===== */

/* getProt1Sensor1PoseTheta(prot1_packet_sensor1_t*) */

int getProt1Sensor1PoseTheta(prot1_packet_sensor1_t *param_1)

{
  return (int)*(short *)(param_1 + 0xc);
}
