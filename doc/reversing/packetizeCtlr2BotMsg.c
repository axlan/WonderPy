RobotHW_rev0 * __thiscall
HAL::RobotHW_rev0::packetizeCtlr2BotMsg(RobotHW_rev0 *this,Ctlr2BotMsg *param_1,RobotHW *param_2)
{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  uchar uVar6;
  uchar uVar7;
  uchar uVar8;
  undefined4 uVar9;
  uint32_t uVar10;
  packet_data *ppVar11;
  robot_hw0_cmd_data *prVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  char *pcVar15;
  RobotHW_rev0 *this_00;
  char *pcVar16;
  RobotHW *this_01;
  byte bVar17;
  int iVar18;
  ulong uVar19;
  char *is_stop;
  size_t sVar20;
  HALPacket_t **ppHVar21;
  long lVar22;
  long lVar23;
  HALPacket_t ***pppHVar24;
  uint uVar25;
  double dVar26;
  undefined8 local_730;
  HALPacket_t **local_728;
  ushort local_71e;
  ushort local_71c;
  ushort local_71a;
  robot_hw0_cmd_data *local_718;
  ushort local_70c;
  ushort local_70a;
  undefined4 local_708;
  ushort local_702;
  robot_hw0_cmd_data *local_700;
  ushort local_6f2;
  undefined4 local_6f0;
  uchar local_6e9;
  int local_6e8;
  short local_6e2;
  double local_6e0;
  double local_6d8;
  double local_6d0;
  double local_6c8;
  double local_6c0;
  double local_6b8;
  double local_6b0;
  double local_6a8;
  double local_6a0;
  double local_698;
  double local_690;
  int local_688;
  int mode;
  double local_680;
  double local_678;
  double local_670;
  double local_668;
  double local_660;
  double local_658;
  double local_650;
  double local_648;
  undefined1 local_639;
  robot_hw0_cmd_data *local_638;
  double local_630;
  ulonglong local_628;
  undefined4 local_61c;
  undefined8 local_618;
  undefined8 local_610;
  double local_608;
  ulonglong local_600;
  undefined4 local_5f4;
  undefined8 local_5f0;
  undefined8 local_5e8;
  double local_5e0;
  double local_5d8;
  double local_5d0;
  double local_5c8;
  double local_5c0;
  double local_5b8;
  double local_5b0;
  double local_5a8;
  double local_5a0;
  double local_598;
  double local_590;
  double local_588;
  double local_580;
  double local_578;
  double local_570;
  double local_568;
  double local_560;
  robot_hw0_cmd_data *local_558;
  double local_550;
  double local_548;
  double local_540;
  robot_hw0_cmd_data *local_538;
  undefined4 local_52c;
  ulonglong local_528;
  char *local_520;
  int local_514;
  char *local_510;
  size_t local_508;
  char *local_500;
  robot_hw0_cmd_data *local_4f8;
  ushort local_4ea;
  double local_4e8;
  char *local_4e0;
  char *local_4d8;
  double local_4d0;
  double local_4c8;
  undefined4 local_4bc;
  undefined8 local_4b8;
  RobotHW_rev0 *local_4b0;
  RobotHW_rev0 *local_4a8;
  packet_data *local_4a0;
  int local_494;
  undefined8 local_490;
  int local_484;
  undefined8 local_480;
  int local_474;
  undefined8 local_470;
  int local_468;
  byte local_461;
  undefined8 local_460;
  int local_454;
  undefined2 local_450;
  short local_44e;
  undefined2 local_44c;
  undefined2 local_44a;
  double local_448;
  double local_440;
  double local_438;
  double local_430;
  double local_428;
  undefined8 msg_len;
  char local_411;
  undefined2 local_410;
  undefined2 local_40e;
  undefined2 local_40c;
  undefined2 local_40a;
  double local_408;
  double local_400;
  double local_3f8;
  double local_3f0;
  uint8_t local_3e1;
  undefined8 pose_origin_msg_len;
  int i;
  ushort local_3d4;
  undefined2 local_3d2;
  double local_3d0;
  double local_3c8;
  ushort local_3bc;
  undefined2 local_3ba;
  double local_3b8;
  double local_3b0;
  undefined1 local_3a1;
  undefined8 local_3a0;
  int local_398;
  uchar local_391;
  double local_390;
  undefined8 local_388;
  int local_37c;
  double local_378;
  undefined8 local_370;
  int local_364;
  double local_360;
  ushort local_352;
  double local_350;
  undefined8 local_348;
  int local_33c;
  double local_338;
  ushort local_32a;
  double local_328;
  undefined8 local_320;
  int local_314;
  int local_310;
  undefined4 local_30c;
  undefined8 local_308;
  int local_2fc;
  int local_2f8;
  undefined4 local_2f4;
  undefined8 local_2f0;
  int local_2e8;
  int local_2e4;
  undefined8 local_2e0;
  int local_2d8;
  int local_2d4;
  undefined8 local_2d0;
  int local_2c8;
  uint local_2c4;
  undefined1 *local_2c0;
  long local_2b8;
  char *local_2b0;
  char *local_2a8;
  int local_2a0;
  undefined1 local_299;
  undefined8 local_298;
  int local_28c;
  int local_288;
  byte local_282;
  byte local_281;
  undefined8 local_280;
  int local_278;
  int local_274;
  undefined8 local_270;
  int local_268;
  int local_264;
  undefined8 local_260;
  int local_258;
  int local_254;
  undefined8 local_250;
  int local_248;
  int local_244;
  undefined8 local_240;
  int local_238;
  int local_234;
  undefined8 local_230;
  int local_224;
  undefined8 local_220;
  int idx;
  robot_hw0_cmd_data *msg_hw_ptr;
  robot_hw0_cmd_data *msg_hw_data;
  RobotHW *local_200;
  Ctlr2BotMsg *local_1f8;
  undefined8 *local_1f0;
  undefined8 *local_1e8;
  undefined8 *local_1e0;
  undefined8 *local_1d8;
  undefined8 local_1d0;
  undefined8 *local_1c8;
  undefined8 local_1c0;
  undefined8 *local_1b8;
  undefined8 *local_1b0;
  undefined8 local_1a8;
  undefined8 *local_1a0;
  undefined8 *local_198;
  undefined8 *local_190;
  char *local_188;
  char *local_180;
  char *local_178;
  char *local_170;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 local_148;
  undefined8 local_140;
  undefined1 local_138 [8];
  packet_data **local_130;
  HALPacket_t **local_128;
  HALPacket_t **local_120;
  ulong *local_118;
  ulong *local_110;
  undefined8 local_108;
  HALPacket_t **local_100;
  undefined1 *local_f8;
  undefined8 local_f0;
  HALPacket_t **local_e8;
  undefined1 *local_e0;
  packet_data **local_d8;
  undefined1 *local_d0;
  packet_data **local_c0;
  long *local_b8;
  undefined *local_b0;
  packet_data **local_a8;
  packet_data **local_a0;
  long *local_98;
  undefined *local_90;
  packet_data **local_88;
  packet_data **local_80;
  long *local_78;
  undefined *local_70;
  packet_data **local_68;
  packet_data **local_60;
  long *local_58;
  HALPacket_t **local_50;
  undefined *local_48;
  undefined *local_40;
  long local_38;
  ushort volume;
  double x_enc;
  
  pppHVar24 = &local_728;
  local_38 = *(long *)PTR____stack_chk_guard_000e21b8;
  local_730 = 0x79e10;
  local_4b0 = this;
  local_4a8 = this;
  local_200 = param_2;
  local_1f8 = param_1;
  msg_hw_data = (robot_hw0_cmd_data *)Ctlr2BotMsg::GetHwData(param_1);
  if (packetizeCtlr2BotMsg(HAL::Ctlr2BotMsg*,HAL::RobotHW*)::nopackets == '\0') {
    local_730 = 0x79e30;
    iVar18 = ___cxa_guard_acquire(&packetizeCtlr2BotMsg(HAL::Ctlr2BotMsg*,HAL::RobotHW*)::nopackets)
    ;
    if (iVar18 != 0) {
      local_190 = &local_1a8;
      local_1b0 = &local_1c0;
      local_1f0 = &packetizeCtlr2BotMsg(HAL::Ctlr2BotMsg*,HAL::RobotHW*)::nopackets;
      local_1e8 = &packetizeCtlr2BotMsg(HAL::Ctlr2BotMsg*,HAL::RobotHW*)::nopackets;
      local_1e0 = &packetizeCtlr2BotMsg(HAL::Ctlr2BotMsg*,HAL::RobotHW*)::nopackets;
      local_1d8 = &packetizeCtlr2BotMsg(HAL::Ctlr2BotMsg*,HAL::RobotHW*)::nopackets;
      packetizeCtlr2BotMsg(HAL::Ctlr2BotMsg*,HAL::RobotHW*)::nopackets = 0;
      DAT_000f09f0 = 0;
      local_1c8 = &DAT_000f09f8;
      local_1d0 = 0;
      local_1c0 = 0;
      local_1a8 = 0;
      DAT_000f09f8 = 0;
      local_4b8 = 0;
      local_730 = 0x79f38;
      local_1b8 = local_1c8;
      local_1a0 = local_1c8;
      local_198 = local_1c8;
      local_4bc = ___cxa_atexit(std::vector<HALPacket_t*,std::allocator<HALPacket_t*>>::~vector,
                                &packetizeCtlr2BotMsg(HAL::Ctlr2BotMsg*,HAL::RobotHW*)::nopackets,0)
      ;
      local_730 = 0x79f4a;
      ___cxa_guard_release(&packetizeCtlr2BotMsg(HAL::Ctlr2BotMsg*,HAL::RobotHW*)::nopackets);
    }
  }
  msg_hw_ptr = msg_hw_data;
  if (msg_hw_data == (robot_hw0_cmd_data *)0x0) {
    local_730 = 0x7fbb7;
    std::vector<HALPacket_t*,std::allocator<HALPacket_t*>>::vector
              ((vector<HALPacket_t*,std::allocator<HALPacket_t*>> *)local_4a8,
               (vector *)&packetizeCtlr2BotMsg(HAL::Ctlr2BotMsg*,HAL::RobotHW*)::nopackets);
  }
  else {
    local_730 = 0x79f79;
    uVar19 = testAndClearCommandMaskBit(msg_hw_data,0x1acb);
    if ((uVar19 & 1) != 0) {
      *(ulong *)msg_hw_ptr->field0_0x0 = *(ulong *)msg_hw_ptr->field0_0x0 & 0xfffff7fffffffeef;
      for (idx = 0; idx < 3; idx = idx + 1) {
        local_220 = 0x14;
        if (0x13 < 0x14 - msg_hw_ptr->packets[idx].size) {
          msg_hw_ptr->packets[idx].data[msg_hw_ptr->packets[idx].size] = -0x56;
          local_4c8 = 0.0003333333333333334;
          local_4d0 = 100.0;
          local_730 = 0x7a078;
          enBig16(msg_hw_ptr->packets[idx].data + (msg_hw_ptr->packets[idx].size + 1),
                  (ushort)(int)((*(double *)(msg_hw_ptr->field2_0x50 + 0xa8) / 100.0) /
                               0.0003333333333333334));
          local_730 = 0x7a0cd;
          enBig16(msg_hw_ptr->packets[idx].data + (msg_hw_ptr->packets[idx].size + 3),
                  (ushort)(int)((*(double *)(msg_hw_ptr->field2_0x50 + 0xb8) / local_4d0) /
                               local_4c8));
          local_4d8 = msg_hw_ptr->packets[idx].data + (msg_hw_ptr->packets[idx].size + 5);
          local_730 = 0x7a111;
          x_enc = (double)_round(*(double *)(msg_hw_ptr->field2_0x50 + 0xd8) * local_4d0);
          local_730 = 0x7a129;
          enBig16(local_4d8,(ushort)(int)x_enc);
          local_4e0 = msg_hw_ptr->packets[idx].data + (msg_hw_ptr->packets[idx].size + 7);
          local_730 = 0x7a16d;
          local_4e8 = (double)_round(*(double *)(msg_hw_ptr->field2_0x50 + 0x100) * local_4d0);
          local_730 = 0x7a190;
          enBig16(local_4e0,(ushort)(int)local_4e8);
          msg_hw_ptr->packets[idx].data[msg_hw_ptr->packets[idx].size + 9] =
               msg_hw_ptr->field2_0x50[0x2c];
          msg_hw_ptr->packets[idx].data[(ulong)(msg_hw_ptr->packets[idx].size + 9) + 1] =
               msg_hw_ptr->field2_0x50[0x2d];
          msg_hw_ptr->packets[idx].data[(ulong)(msg_hw_ptr->packets[idx].size + 9) + 2] =
               msg_hw_ptr->field2_0x50[0x2e];
          msg_hw_ptr->packets[idx].data[msg_hw_ptr->packets[idx].size + 0xc] =
               msg_hw_ptr->field2_0x50[0x38];
          msg_hw_ptr->packets[idx].data[(ulong)(msg_hw_ptr->packets[idx].size + 0xc) + 1] =
               msg_hw_ptr->field2_0x50[0x39];
          msg_hw_ptr->packets[idx].data[(ulong)(msg_hw_ptr->packets[idx].size + 0xc) + 2] =
               msg_hw_ptr->field2_0x50[0x3a];
          msg_hw_ptr->packets[idx].data[msg_hw_ptr->packets[idx].size + 0xf] =
               msg_hw_ptr->field2_0x50[0x44];
          msg_hw_ptr->packets[idx].data[(ulong)(msg_hw_ptr->packets[idx].size + 0xf) + 1] =
               msg_hw_ptr->field2_0x50[0x45];
          msg_hw_ptr->packets[idx].data[(ulong)(msg_hw_ptr->packets[idx].size + 0xf) + 2] =
               msg_hw_ptr->field2_0x50[0x46];
          local_730 = 0x7a49a;
          enBig16(msg_hw_ptr->packets[idx].data + (msg_hw_ptr->packets[idx].size + 0x12),
                  *(ushort *)(msg_hw_ptr->field2_0x50 + 0x18));
          msg_hw_ptr->packets[idx].size = msg_hw_ptr->packets[idx].size + (int)local_220;
          break;
        }
      }
    }
    local_4ea = (ushort)(int)((*(double *)(msg_hw_ptr->field2_0x50 + 0xa8) / 100.0) /
                             0.0003333333333333334);
    local_730 = 0x7a559;
    tryEncodeCommandBig16_2
              (msg_hw_ptr,3,'\x01',local_4ea,
               (ushort)(int)((*(double *)(msg_hw_ptr->field2_0x50 + 0xb8) / 100.0) /
                            0.0003333333333333334));
    local_730 = 0x7a57f;
    tryEncodeCommandRGB(msg_hw_ptr,8,'\x03',(HALRGB_t *)(msg_hw_ptr->field2_0x50 + 0x24));
    local_730 = 0x7a5a5;
    tryEncodeCommandRGB(msg_hw_ptr,0x800,'\v',(HALRGB_t *)(msg_hw_ptr->field2_0x50 + 0x30));
    local_730 = 0x7a5cb;
    tryEncodeCommandRGB(msg_hw_ptr,0x1000,'\f',(HALRGB_t *)(msg_hw_ptr->field2_0x50 + 0x3c));
    local_730 = 0x7a5f4;
    tryEncodeCommandRGB(msg_hw_ptr,0x40000000000,'0',(HALRGB_t *)(msg_hw_ptr->field2_0x50 + 0x48));
    local_4f8 = msg_hw_ptr;
    local_730 = 0x7a651;
    tryEncodeCommand___8_3
              (msg_hw_ptr,0x100000000000,'1',msg_hw_ptr->field2_0x50[0x74],
               msg_hw_ptr->field2_0x50[0x75],msg_hw_ptr->field2_0x50[0x76]);
    local_730 = 0x7a67b;
    tryEncodeCommand___8_1(msg_hw_ptr,0x200000000000,'3',msg_hw_ptr->field2_0x50[0x80]);
    local_730 = 0x7a6a5;
    tryEncodeCommand___8_1(msg_hw_ptr,0x400000000000,'4',msg_hw_ptr->field2_0x50[0x8c]);
    local_730 = 0x7a6cf;
    tryEncodeCommand___8_1(msg_hw_ptr,0x800000000000,'5',msg_hw_ptr->field2_0x50[0x98]);
    local_730 = 0x7a6f6;
    tryEncodeCommand___8_1(msg_hw_ptr,0x10,'\x04',msg_hw_ptr->field2_0x50[0x5c]);
    local_730 = 0x7a71d;
    tryEncodeCommand___8_1(msg_hw_ptr,0x2000,'\r',msg_hw_ptr->field2_0x50[0x68]);
    local_730 = 0x7a730;
    uVar19 = testAndClearCommandMaskBit(msg_hw_ptr,0x800000);
    if ((uVar19 & 1) != 0) {
      local_224 = 0;
LAB_0007a747:
      if (local_224 < 3) {
        local_230 = 0xf;
        if (0x14 - msg_hw_ptr->packets[local_224].size < 0xf) goto LAB_0007a95e;
        local_180 = (msg_hw_ptr->speaker).file;
        local_188 = "STOPSOUND";
        local_178 = "STOPSOUND";
        local_730 = 0x7a7e9;
        local_170 = local_180;
        is_stop = _strstr(local_180,"STOPSOUND");
        if (is_stop == (char *)0x0) {
          msg_hw_ptr->packets[local_224].data[msg_hw_ptr->packets[local_224].size] = '\x18';
          for (local_234 = 0; local_234 < 0xe; local_234 = local_234 + 1) {
            msg_hw_ptr->packets[local_224].data[local_234 + 1 + msg_hw_ptr->packets[local_224].size]
                 = (msg_hw_ptr->speaker).file[local_234];
          }
          msg_hw_ptr->packets[local_224].size = msg_hw_ptr->packets[local_224].size + (int)local_230
          ;
        }
        else {
          msg_hw_ptr->packets[local_224].data[msg_hw_ptr->packets[local_224].size] = '\x1a';
          msg_hw_ptr->packets[local_224].size = msg_hw_ptr->packets[local_224].size + 1;
        }
        local_730 = 0x7a954;
        RobotHW::invalidateCachedSynthSettings(local_200);
      }
    }
    local_730 = 0x7a98d;
    uVar19 = testAndClearCommandMaskBit(msg_hw_ptr,0x2000000000);
    if ((uVar19 & 1) != 0) {
      local_238 = 0;
LAB_0007a9a4:
      if (local_238 < 3) {
        local_240 = 0xf;
        if (0x14 - msg_hw_ptr->packets[local_238].size < 0xf) goto LAB_0007aaea;
        msg_hw_ptr->packets[local_238].data[msg_hw_ptr->packets[local_238].size] = '&';
        for (local_244 = 0; local_244 < 0xe; local_244 = local_244 + 1) {
          msg_hw_ptr->packets[local_238].data[local_244 + 1 + msg_hw_ptr->packets[local_238].size] =
               (msg_hw_ptr->pose).field0_0x0[(long)local_244 + 0xe];
        }
        msg_hw_ptr->packets[local_238].size = msg_hw_ptr->packets[local_238].size + 0xf;
      }
    }
    local_730 = 0x7ab1e;
    tryEncodeCommand___8_0(msg_hw_ptr,0x4000000000,'+');
    local_730 = 0x7ab31;
    uVar19 = testAndClearCommandMaskBit(msg_hw_ptr,0x2000000);
    if ((uVar19 & 1) != 0) {
      local_248 = 0;
LAB_0007ab48:
      if (local_248 < 3) {
        local_250 = 0x14;
        if (0x14 - msg_hw_ptr->packets[local_248].size < 0x14) goto LAB_0007ad3a;
        msg_hw_ptr->packets[local_248].data[msg_hw_ptr->packets[local_248].size] = '\x1c';
        msg_hw_ptr->packets[local_248].data[msg_hw_ptr->packets[local_248].size + 1] = '\x01';
        for (local_254 = 0; local_254 < 0x12; local_254 = local_254 + 1) {
          msg_hw_ptr->packets[local_248].data[local_254 + 2 + msg_hw_ptr->packets[local_248].size] =
               msg_hw_ptr[1].field2_0x50[(long)local_254 + 0x25];
        }
        for (; local_254 < 0x12; local_254 = local_254 + 1) {
          msg_hw_ptr->packets[local_248].data[local_254 + 2 + msg_hw_ptr->packets[local_248].size] =
               '\0';
        }
        msg_hw_ptr->packets[local_248].size = msg_hw_ptr->packets[local_248].size + 0x14;
      }
    }
    local_730 = 0x7ad66;
    uVar19 = testAndClearCommandMaskBit(msg_hw_ptr,0x4000000);
    if ((uVar19 & 1) != 0) {
      local_258 = 0;
LAB_0007ad7d:
      if (local_258 < 3) {
        local_260 = 0x14;
        if (0x14 - msg_hw_ptr->packets[local_258].size < 0x14) goto LAB_0007af3c;
        msg_hw_ptr->packets[local_258].data[msg_hw_ptr->packets[local_258].size] = '\x1c';
        msg_hw_ptr->packets[local_258].data[msg_hw_ptr->packets[local_258].size + 1] = '\x03';
        msg_hw_ptr->packets[local_258].data[msg_hw_ptr->packets[local_258].size + 2] =
             (char)*(undefined4 *)(msg_hw_ptr[1].field2_0x50 + 0x39);
        for (local_264 = 3; local_264 < 0x14; local_264 = local_264 + 1) {
          msg_hw_ptr->packets[local_258].data[local_264 + msg_hw_ptr->packets[local_258].size] =
               '\0';
        }
        msg_hw_ptr->packets[local_258].size = msg_hw_ptr->packets[local_258].size + 0x14;
      }
    }
    local_730 = 0x7af68;
    uVar19 = testAndClearCommandMaskBit(msg_hw_ptr,0x8000000);
    if ((uVar19 & 1) != 0) {
      local_268 = 0;
LAB_0007af7f:
      if (local_268 < 3) {
        local_270 = 0x14;
        if (0x14 - msg_hw_ptr->packets[local_268].size < 0x14) goto LAB_0007b13e;
        msg_hw_ptr->packets[local_268].data[msg_hw_ptr->packets[local_268].size] = '\x1c';
        msg_hw_ptr->packets[local_268].data[msg_hw_ptr->packets[local_268].size + 1] = '\x04';
        msg_hw_ptr->packets[local_268].data[msg_hw_ptr->packets[local_268].size + 2] =
             (char)*(undefined4 *)(msg_hw_ptr[1].field2_0x50 + 0x3d);
        for (local_274 = 3; local_274 < 0x14; local_274 = local_274 + 1) {
          msg_hw_ptr->packets[local_268].data[local_274 + msg_hw_ptr->packets[local_268].size] =
               '\0';
        }
        msg_hw_ptr->packets[local_268].size = msg_hw_ptr->packets[local_268].size + 0x14;
      }
    }
    local_730 = 0x7b16a;
    uVar19 = testAndClearCommandMaskBit(msg_hw_ptr,0x10000000);
    if ((uVar19 & 1) != 0) {
      local_278 = 0;
LAB_0007b181:
      if (local_278 < 3) {
        local_280 = 0x14;
        if (0x14 - msg_hw_ptr->packets[local_278].size < 0x14) goto LAB_0007b3c2;
        local_281 = 0;
        local_282 = (byte)*(undefined4 *)(msg_hw_ptr[1].field2_0x50 + 0x3d);
        if (local_282 == 7) {
          local_281 = 0x40;
          local_282 = 1;
        }
        local_281 = local_281 | (byte)*(undefined4 *)(msg_hw_ptr[1].field2_0x50 + 0x39) & 7 |
                    (local_282 & 7) << 3;
        msg_hw_ptr->packets[local_278].data[msg_hw_ptr->packets[local_278].size] = '\x1c';
        msg_hw_ptr->packets[local_278].data[msg_hw_ptr->packets[local_278].size + 1] = '\n';
        msg_hw_ptr->packets[local_278].data[msg_hw_ptr->packets[local_278].size + 2] = local_281;
        for (local_288 = 3; local_288 < 0x14; local_288 = local_288 + 1) {
          msg_hw_ptr->packets[local_278].data[local_288 + msg_hw_ptr->packets[local_278].size] =
               '\0';
        }
        msg_hw_ptr->packets[local_278].size = msg_hw_ptr->packets[local_278].size + 0x14;
      }
    }
    local_730 = 0x7b3f1;
    uVar19 = testAndClearCommandMaskBit(msg_hw_ptr,0x1000000000000);
    pppHVar24 = &local_728;
    if ((uVar19 & 1) != 0) {
      local_28c = 0;
LAB_0007b408:
      pppHVar24 = &local_728;
      if (local_28c < 3) {
        local_298 = 0x14;
        if (0x14 - msg_hw_ptr->packets[local_28c].size < 0x14) goto LAB_0007b888;
        local_299 = 1;
        for (local_2a0 = 0; local_2a0 < 0x14; local_2a0 = local_2a0 + 1) {
          msg_hw_ptr->packets[local_28c].data[local_2a0 + msg_hw_ptr->packets[local_28c].size] =
               '\0';
        }
        msg_hw_ptr->packets[local_28c].data[msg_hw_ptr->packets[local_28c].size] = '\x1c';
        msg_hw_ptr->packets[local_28c].data[msg_hw_ptr->packets[local_28c].size + 1] = '\b';
        msg_hw_ptr->packets[local_28c].data[msg_hw_ptr->packets[local_28c].size + 2] =
             (char)*(undefined4 *)(msg_hw_ptr[1].field2_0x50 + 0x41);
        uVar25 = msg_hw_ptr->packets[local_28c].size + 3;
        msg_hw_ptr->packets[local_28c].data[uVar25] =
             msg_hw_ptr->packets[local_28c].data[uVar25] | msg_hw_ptr[1].field2_0x50[0x45] & 1;
        uVar25 = msg_hw_ptr->packets[local_28c].size + 3;
        msg_hw_ptr->packets[local_28c].data[uVar25] =
             msg_hw_ptr->packets[local_28c].data[uVar25] | 4;
        pppHVar24 = &local_728;
        if ((msg_hw_ptr[1].field2_0x50[0x45] & 1) != 0) {
          local_2a8 = msg_hw_ptr[1].field2_0x50 + 0x46;
          local_500 = "%s%s";
          local_730 = 0x7b6e6;
          local_2b0 = (char *)RobotHW::getUniqueId(local_200);
          local_730 = 0x7b6f9;
          local_508 = _strlen(local_2a8);
          local_730 = 0x7b70c;
          sVar20 = _strlen(local_2b0);
          pcVar16 = local_2a8;
          pcVar15 = local_2b0;
          is_stop = local_500;
          local_2b8 = local_508 + sVar20;
          lVar23 = -(local_2b8 + 0x10U & 0xfffffffffffffff0);
          sVar20 = local_2b8 + 1;
          local_510 = (char *)((long)&local_728 + lVar23);
          local_2c0 = (undefined1 *)&local_728;
          *(undefined8 *)((long)&local_730 + lVar23) = 0x7b776;
          local_514 = _snprintf((char *)((long)&local_728 + lVar23),sVar20,is_stop,pcVar16,pcVar15);
          is_stop = local_510;
          *(undefined8 *)((long)&local_730 + lVar23) = 0x7b788;
          _wwToUpper(is_stop);
          is_stop = local_510;
          local_520 = msg_hw_ptr->packets[local_28c].data +
                      (msg_hw_ptr->packets[local_28c].size + 2);
          *(undefined8 *)((long)&local_730 + lVar23) = 0x7b7dd;
          sVar20 = _strlen(is_stop);
          pcVar15 = local_510;
          is_stop = local_520;
          *(undefined8 *)((long)&local_730 + lVar23) = 0x7b7f3;
          uVar25 = _wwTwiddler(is_stop,pcVar15,sVar20);
          lVar22 = (long)local_28c;
          uVar10 = msg_hw_ptr->packets[local_28c].size;
          ppVar11 = msg_hw_ptr->packets;
          local_2c4 = uVar25;
          *(undefined8 *)((long)&local_730 + lVar23) = 0x7b849;
          enBig32(ppVar11[lVar22].data + (uVar10 + 4),uVar25);
          pppHVar24 = (HALPacket_t ***)local_2c0;
        }
        msg_hw_ptr->packets[local_28c].size = msg_hw_ptr->packets[local_28c].size + (int)local_298;
      }
    }
    prVar12 = msg_hw_ptr;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7b8b7;
    uVar19 = testAndClearCommandMaskBit(prVar12,0x100000000);
    prVar12 = msg_hw_ptr;
    if ((uVar19 & 1) != 0) {
      local_2c8 = 0;
LAB_0007b8ce:
      if (local_2c8 < 3) {
        local_2d0 = 0x14;
        if (0x14 - msg_hw_ptr->packets[local_2c8].size < 0x14) goto LAB_0007ba63;
        msg_hw_ptr->packets[local_2c8].data[msg_hw_ptr->packets[local_2c8].size] = '\x1c';
        msg_hw_ptr->packets[local_2c8].data[msg_hw_ptr->packets[local_2c8].size + 1] = '\x06';
        msg_hw_ptr->packets[local_2c8].data[msg_hw_ptr->packets[local_2c8].size + 2] =
             (char)(int)(*(double *)(msg_hw_ptr[1].field2_0x50 + 0x85) * 100.0);
        for (local_2d4 = 3; local_2d4 < 0x14; local_2d4 = local_2d4 + 1) {
          msg_hw_ptr->packets[local_2c8].data[local_2d4 + msg_hw_ptr->packets[local_2c8].size] =
               '\0';
        }
        msg_hw_ptr->packets[local_2c8].size = msg_hw_ptr->packets[local_2c8].size + 0x14;
      }
    }
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7ba92;
    uVar19 = testAndClearCommandMaskBit(prVar12,0x400000000);
    prVar12 = msg_hw_ptr;
    if ((uVar19 & 1) != 0) {
      local_2d8 = 0;
LAB_0007baa9:
      if (local_2d8 < 3) {
        local_2e0 = 0x14;
        if (0x14 - msg_hw_ptr->packets[local_2d8].size < 0x14) goto LAB_0007bc3e;
        msg_hw_ptr->packets[local_2d8].data[msg_hw_ptr->packets[local_2d8].size] = '\x1c';
        msg_hw_ptr->packets[local_2d8].data[msg_hw_ptr->packets[local_2d8].size + 1] = '\a';
        msg_hw_ptr->packets[local_2d8].data[msg_hw_ptr->packets[local_2d8].size + 2] =
             (char)(int)(*(double *)(msg_hw_ptr[1].field2_0x50 + 0x8d) * 255.0);
        for (local_2e4 = 3; local_2e4 < 0x14; local_2e4 = local_2e4 + 1) {
          msg_hw_ptr->packets[local_2d8].data[local_2e4 + msg_hw_ptr->packets[local_2d8].size] =
               '\0';
        }
        msg_hw_ptr->packets[local_2d8].size = msg_hw_ptr->packets[local_2d8].size + 0x14;
      }
    }
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7bc6a;
    uVar19 = testAndClearCommandMaskBit(prVar12,0x20000000);
    if ((uVar19 & 1) != 0) {
      local_2e8 = 0;
LAB_0007bc81:
      if (local_2e8 < 3) {
        local_2f0 = 0x14;
        if (0x14 - msg_hw_ptr->packets[local_2e8].size < 0x14) goto LAB_0007bf0e;
        msg_hw_ptr->packets[local_2e8].data[msg_hw_ptr->packets[local_2e8].size] = '\x1f';
        msg_hw_ptr->packets[local_2e8].data[msg_hw_ptr->packets[local_2e8].size + 1] = '\x01';
        *(undefined8 *)((long)pppHVar24 + -8) = 0x7bd16;
        x_enc = (double)_PIEpoch();
        lVar23 = (long)x_enc;
        local_2f4 = (undefined4)lVar23;
        msg_hw_ptr->packets[local_2e8].data[msg_hw_ptr->packets[local_2e8].size + 2] =
             (char)((ulong)lVar23 >> 0x18);
        msg_hw_ptr->packets[local_2e8].data[msg_hw_ptr->packets[local_2e8].size + 3] =
             (char)((ulong)lVar23 >> 0x10);
        msg_hw_ptr->packets[local_2e8].data[msg_hw_ptr->packets[local_2e8].size + 4] =
             (char)((ulong)lVar23 >> 8);
        msg_hw_ptr->packets[local_2e8].data[msg_hw_ptr->packets[local_2e8].size + 5] = (char)lVar23;
        for (local_2f8 = 6; local_2f8 < 0x14; local_2f8 = local_2f8 + 1) {
          msg_hw_ptr->packets[local_2e8].data[local_2f8 + msg_hw_ptr->packets[local_2e8].size] =
               '\0';
        }
        msg_hw_ptr->packets[local_2e8].size = msg_hw_ptr->packets[local_2e8].size + (int)local_2f0;
      }
    }
    prVar12 = msg_hw_ptr;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7bf3a;
    uVar19 = testAndClearCommandMaskBit(prVar12,0x40000000);
    if ((uVar19 & 1) != 0) {
      local_2fc = 0;
LAB_0007bf51:
      if (local_2fc < 3) {
        local_308 = 0x14;
        if (0x14 - msg_hw_ptr->packets[local_2fc].size < 0x14) goto LAB_0007c20f;
        msg_hw_ptr->packets[local_2fc].data[msg_hw_ptr->packets[local_2fc].size] = '\x1f';
        msg_hw_ptr->packets[local_2fc].data[msg_hw_ptr->packets[local_2fc].size + 1] = '\x02';
        *(undefined8 *)((long)pppHVar24 + -8) = 0x7c022;
        local_30c = _WWAppHash();
        msg_hw_ptr->packets[local_2fc].data[msg_hw_ptr->packets[local_2fc].size + 2] =
             (char)((uint)local_30c >> 0x18);
        msg_hw_ptr->packets[local_2fc].data[msg_hw_ptr->packets[local_2fc].size + 3] =
             (char)((uint)local_30c >> 0x10);
        msg_hw_ptr->packets[local_2fc].data[msg_hw_ptr->packets[local_2fc].size + 4] =
             (char)((uint)local_30c >> 8);
        msg_hw_ptr->packets[local_2fc].data[msg_hw_ptr->packets[local_2fc].size + 5] =
             (char)local_30c;
        for (local_310 = 6; local_310 < 0x14; local_310 = local_310 + 1) {
          msg_hw_ptr->packets[local_2fc].data[local_310 + msg_hw_ptr->packets[local_2fc].size] =
               '\0';
        }
        msg_hw_ptr->packets[local_2fc].size = msg_hw_ptr->packets[local_2fc].size + (int)local_308;
      }
    }
    prVar12 = msg_hw_ptr;
    local_528 = 0x80;
    local_52c = 7;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7c25e;
    tryEncodeCommand___8_0(prVar12,0x1000000,'\x1a');
    x_enc = *(double *)(msg_hw_ptr->field2_0x50 + 0xd8);
    local_538 = msg_hw_ptr;
    local_540 = -100.0;
    local_548 = 6.283185307179586;
    local_550 = 360.0;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7c2b5;
    x_enc = (double)_round(((x_enc * -100.0) / 6.283185307179586) * 360.0);
    prVar12 = local_538;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7c2d9;
    tryEncodeCommandBig16_1(prVar12,0x40,'\x06',(ushort)(int)x_enc);
    x_enc = ((*(double *)(msg_hw_ptr->field2_0x50 + 0x100) * local_540) / local_548) * local_550;
    local_558 = msg_hw_ptr;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7c318;
    local_560 = (double)_round(x_enc);
    uVar13 = local_528;
    uVar9 = local_52c;
    prVar12 = local_558;
    iVar18 = (int)local_560;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7c348;
    tryEncodeCommandBig16_1(prVar12,uVar13,(uchar)uVar9,(ushort)iVar18);
    prVar12 = msg_hw_ptr;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7c35b;
    uVar19 = testAndClearCommandMaskBit(prVar12,0x100000);
    if ((uVar19 & 1) != 0) {
      for (local_314 = 0; local_314 < 3; local_314 = local_314 + 1) {
        local_320 = 5;
        if (4 < 0x14 - msg_hw_ptr->packets[local_314].size) {
          local_568 = -32768.0;
          *(undefined8 *)((long)pppHVar24 + -8) = 0x7c405;
          local_570 = (double)_round();
          if (local_570 <= local_568) {
            local_570 = -32768.0;
          }
          if (32767.0 <= local_570) {
            local_578 = 32767.0;
          }
          else {
            local_578 = local_570;
          }
          local_328 = local_578;
          if ((msg_hw_ptr->field2_0x50[0x130] & 1) == 0) {
            local_580 = -32768.0;
            *(undefined8 *)((long)pppHVar24 + -8) = 0x7c63e;
            local_588 = (double)_round();
            if (local_588 <= local_580) {
              local_588 = -32768.0;
            }
            if (32767.0 <= local_588) {
              local_590 = 32767.0;
            }
            else {
              local_590 = local_588;
            }
            local_338 = local_590;
            msg_hw_ptr->packets[local_314].data[msg_hw_ptr->packets[local_314].size] = '\x11';
            lVar23 = (long)local_314;
            uVar10 = msg_hw_ptr->packets[lVar23].size;
            ppVar11 = msg_hw_ptr->packets;
            iVar18 = (int)local_328;
            *(undefined8 *)((long)pppHVar24 + -8) = 0x7c743;
            enBig16(ppVar11[lVar23].data + (uVar10 + 1),(ushort)iVar18);
            lVar23 = (long)local_314;
            uVar10 = msg_hw_ptr->packets[lVar23].size;
            ppVar11 = msg_hw_ptr->packets;
            iVar18 = (int)local_338;
            *(undefined8 *)((long)pppHVar24 + -8) = 0x7c780;
            enBig16(ppVar11[lVar23].data + (uVar10 + 3),(ushort)iVar18);
          }
          else {
            x_enc = *(double *)(msg_hw_ptr->field2_0x50 + 0x118);
            *(undefined8 *)((long)pppHVar24 + -8) = 0x7c4e5;
            x_enc = (double)_round(x_enc * 100.0);
            local_32a = (ushort)(int)x_enc;
            msg_hw_ptr->packets[local_314].data[msg_hw_ptr->packets[local_314].size] = 'p';
            lVar23 = (long)local_314;
            uVar10 = msg_hw_ptr->packets[lVar23].size;
            ppVar11 = msg_hw_ptr->packets;
            iVar18 = (int)local_328;
            *(undefined8 *)((long)pppHVar24 + -8) = 0x7c54e;
            enBig16(ppVar11[lVar23].data + (uVar10 + 1),(ushort)iVar18);
            lVar23 = (long)local_314;
            uVar10 = msg_hw_ptr->packets[local_314].size;
            ppVar11 = msg_hw_ptr->packets;
            volume = local_32a & 0x3fff;
            *(undefined8 *)((long)pppHVar24 + -8) = 0x7c5ab;
            enBig16(ppVar11[lVar23].data + (uVar10 + 3),volume);
            if ((msg_hw_ptr->field2_0x50[0x130] & 1) != 0) {
              uVar25 = msg_hw_ptr->packets[local_314].size + 3;
              msg_hw_ptr->packets[local_314].data[uVar25] =
                   msg_hw_ptr->packets[local_314].data[uVar25] | 0x40;
            }
          }
          msg_hw_ptr->packets[local_314].size = msg_hw_ptr->packets[local_314].size + (int)local_320
          ;
          break;
        }
      }
    }
    prVar12 = msg_hw_ptr;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7c7e1;
    uVar19 = testAndClearCommandMaskBit(prVar12,0x40000);
    if ((uVar19 & 1) != 0) {
      for (local_33c = 0; local_33c < 3; local_33c = local_33c + 1) {
        local_348 = 5;
        if (4 < 0x14 - msg_hw_ptr->packets[local_33c].size) {
          local_598 = -32768.0;
          *(undefined8 *)((long)pppHVar24 + -8) = 0x7c88b;
          local_5a0 = (double)_round();
          if (local_5a0 <= local_598) {
            local_5a0 = -32768.0;
          }
          if (32767.0 <= local_5a0) {
            local_5a8 = 32767.0;
          }
          else {
            local_5a8 = local_5a0;
          }
          local_350 = local_5a8;
          if ((msg_hw_ptr->field2_0x50[0x158] & 1) == 0) {
            local_5b0 = -32768.0;
            *(undefined8 *)((long)pppHVar24 + -8) = 0x7cac4;
            local_5b8 = (double)_round();
            if (local_5b8 <= local_5b0) {
              local_5b8 = -32768.0;
            }
            if (32767.0 <= local_5b8) {
              local_5c0 = 32767.0;
            }
            else {
              local_5c0 = local_5b8;
            }
            local_360 = local_5c0;
            msg_hw_ptr->packets[local_33c].data[msg_hw_ptr->packets[local_33c].size] = '\x12';
            lVar23 = (long)local_33c;
            uVar10 = msg_hw_ptr->packets[lVar23].size;
            ppVar11 = msg_hw_ptr->packets;
            iVar18 = (int)local_350;
            *(undefined8 *)((long)pppHVar24 + -8) = 0x7cbc9;
            enBig16(ppVar11[lVar23].data + (uVar10 + 1),(ushort)iVar18);
            lVar23 = (long)local_33c;
            uVar10 = msg_hw_ptr->packets[lVar23].size;
            ppVar11 = msg_hw_ptr->packets;
            iVar18 = (int)local_360;
            *(undefined8 *)((long)pppHVar24 + -8) = 0x7cc06;
            enBig16(ppVar11[lVar23].data + (uVar10 + 3),(ushort)iVar18);
          }
          else {
            x_enc = *(double *)(msg_hw_ptr->field2_0x50 + 0x140);
            *(undefined8 *)((long)pppHVar24 + -8) = 0x7c96b;
            x_enc = (double)_round(x_enc * 100.0);
            local_352 = (ushort)(int)x_enc;
            msg_hw_ptr->packets[local_33c].data[msg_hw_ptr->packets[local_33c].size] = 'q';
            lVar23 = (long)local_33c;
            uVar10 = msg_hw_ptr->packets[lVar23].size;
            ppVar11 = msg_hw_ptr->packets;
            iVar18 = (int)local_350;
            *(undefined8 *)((long)pppHVar24 + -8) = 0x7c9d4;
            enBig16(ppVar11[lVar23].data + (uVar10 + 1),(ushort)iVar18);
            lVar23 = (long)local_33c;
            uVar10 = msg_hw_ptr->packets[local_33c].size;
            ppVar11 = msg_hw_ptr->packets;
            volume = local_352 & 0x3fff;
            *(undefined8 *)((long)pppHVar24 + -8) = 0x7ca31;
            enBig16(ppVar11[lVar23].data + (uVar10 + 3),volume);
            if ((msg_hw_ptr->field2_0x50[0x158] & 1) != 0) {
              uVar25 = msg_hw_ptr->packets[local_33c].size + 3;
              msg_hw_ptr->packets[local_33c].data[uVar25] =
                   msg_hw_ptr->packets[local_33c].data[uVar25] | 0x40;
            }
          }
          msg_hw_ptr->packets[local_33c].size = msg_hw_ptr->packets[local_33c].size + (int)local_348
          ;
          break;
        }
      }
    }
    prVar12 = msg_hw_ptr;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7cc67;
    uVar19 = testAndClearCommandMaskBit(prVar12,0x200000);
    if ((uVar19 & 1) != 0) {
      for (local_364 = 0; local_364 < 3; local_364 = local_364 + 1) {
        local_370 = 3;
        if (2 < 0x14 - msg_hw_ptr->packets[local_364].size) {
          local_5c8 = (*(double *)(msg_hw_ptr->field2_0x50 + 0x170) * 1000.0) / 8.0;
          if (local_5c8 <= -32768.0) {
            local_5c8 = -32768.0;
          }
          if (32767.0 <= local_5c8) {
            local_5d0 = 32767.0;
          }
          else {
            local_5d0 = local_5c8;
          }
          local_378 = local_5d0;
          msg_hw_ptr->packets[local_364].data[msg_hw_ptr->packets[local_364].size] = '\x13';
          lVar23 = (long)local_364;
          uVar10 = msg_hw_ptr->packets[lVar23].size;
          ppVar11 = msg_hw_ptr->packets;
          iVar18 = (int)local_5d0;
          *(undefined8 *)((long)pppHVar24 + -8) = 0x7cdf6;
          enBig16(ppVar11[lVar23].data + (uVar10 + 1),(ushort)iVar18);
          msg_hw_ptr->packets[local_364].size = msg_hw_ptr->packets[local_364].size + (int)local_370
          ;
          break;
        }
      }
    }
    prVar12 = msg_hw_ptr;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7ce57;
    uVar19 = testAndClearCommandMaskBit(prVar12,0x80000);
    if ((uVar19 & 1) != 0) {
      for (local_37c = 0; local_37c < 3; local_37c = local_37c + 1) {
        local_388 = 3;
        if (2 < 0x14 - msg_hw_ptr->packets[local_37c].size) {
          local_5d8 = (*(double *)(msg_hw_ptr->field2_0x50 + 0x198) * 1000.0) / 8.0;
          if (local_5d8 <= -32768.0) {
            local_5d8 = -32768.0;
          }
          if (32767.0 <= local_5d8) {
            local_5e0 = 32767.0;
          }
          else {
            local_5e0 = local_5d8;
          }
          local_390 = local_5e0;
          msg_hw_ptr->packets[local_37c].data[msg_hw_ptr->packets[local_37c].size] = '\x14';
          lVar23 = (long)local_37c;
          uVar10 = msg_hw_ptr->packets[lVar23].size;
          ppVar11 = msg_hw_ptr->packets;
          iVar18 = (int)local_5e0;
          *(undefined8 *)((long)pppHVar24 + -8) = 0x7cfe6;
          enBig16(ppVar11[lVar23].data + (uVar10 + 1),(ushort)iVar18);
          msg_hw_ptr->packets[local_37c].size = msg_hw_ptr->packets[local_37c].size + (int)local_388
          ;
          break;
        }
      }
    }
    if (*(double *)(msg_hw_ptr->field2_0x50 + 0x1b8) <= 100.0) {
      if (-100.0 < *(double *)(msg_hw_ptr->field2_0x50 + 0x1b8) ||
          *(double *)(msg_hw_ptr->field2_0x50 + 0x1b8) == -100.0) {
        local_5f0 = *(undefined8 *)(msg_hw_ptr->field2_0x50 + 0x1b8);
      }
      else {
        local_5f0 = 0xc059000000000000;
      }
      local_5e8 = local_5f0;
    }
    else {
      local_5e8 = 0x4059000000000000;
    }
    uVar14 = local_5e8;
    local_5f4 = 0x75;
    local_600 = 0x2000000000000;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7d0ec;
    local_608 = (double)_round(uVar14);
    prVar12 = msg_hw_ptr;
    uVar9 = local_5f4;
    uVar13 = local_600;
    iVar18 = (int)local_608;
    local_391 = (uchar)iVar18;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7d123;
    tryEncodeCommand___8_1(prVar12,uVar13,(uchar)uVar9,(uchar)iVar18);
    if (*(double *)(msg_hw_ptr->field2_0x50 + 0x1c8) <= 100.0) {
      if (-100.0 < *(double *)(msg_hw_ptr->field2_0x50 + 0x1c8) ||
          *(double *)(msg_hw_ptr->field2_0x50 + 0x1c8) == -100.0) {
        local_618 = *(undefined8 *)(msg_hw_ptr->field2_0x50 + 0x1c8);
      }
      else {
        local_618 = 0xc059000000000000;
      }
      local_610 = local_618;
    }
    else {
      local_610 = 0x4059000000000000;
    }
    uVar14 = local_610;
    local_61c = 0x76;
    local_628 = 0x4000000000000;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7d1db;
    local_630 = (double)_round(uVar14);
    prVar12 = msg_hw_ptr;
    uVar9 = local_61c;
    uVar13 = local_628;
    iVar18 = (int)local_630;
    local_391 = (uchar)iVar18;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7d212;
    tryEncodeCommand___8_1(prVar12,uVar13,(uchar)uVar9,(uchar)iVar18);
    prVar12 = msg_hw_ptr;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7d22a;
    tryEncodeCommand___8_0(prVar12,0x400000,'\x10');
    prVar12 = msg_hw_ptr;
    uVar6 = msg_hw_ptr->field2_0x50[0x1d8];
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7d254;
    tryEncodeCommand___8_1(prVar12,0x800000000,'r',uVar6);
    prVar12 = msg_hw_ptr;
    uVar6 = msg_hw_ptr->field2_0x50[0x1e4];
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7d27e;
    tryEncodeCommand___8_1(prVar12,0x1000000000,'s',uVar6);
    prVar12 = msg_hw_ptr;
    uVar6 = msg_hw_ptr->field2_0x50[0xc];
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7d2a2;
    tryEncodeCommand___8_1(prVar12,0x100,'\b',uVar6);
    prVar12 = msg_hw_ptr;
    uVar6 = msg_hw_ptr->field2_0x50[0x1a];
    uVar7 = msg_hw_ptr->field2_0x50[0x1b];
    uVar8 = msg_hw_ptr->field2_0x50[0x1c];
    local_638 = msg_hw_ptr;
    *(uint *)((long)pppHVar24 + -0x10) = (uint)(byte)msg_hw_ptr->field2_0x50[0x1d];
    *(undefined8 *)((long)pppHVar24 + -0x18) = 0x7d30e;
    tryEncodeCommand___8_4
              (prVar12,0x80000000000,'2',uVar6,uVar7,uVar8,*(uchar *)((long)pppHVar24 + -0x10));
    prVar12 = msg_hw_ptr;
    volume = *(ushort *)(msg_hw_ptr->field2_0x50 + 0x18);
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7d335;
    tryEncodeCommandBig16_1(prVar12,0x200,'\t',volume);
    prVar12 = msg_hw_ptr;
    uVar9 = *(undefined4 *)(msg_hw_ptr->field2_0x50 + 8);
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7d368;
    tryEncodeCommand___8_3(prVar12,0x400,'\n',(uchar)uVar9,0xff,'\x01');
    prVar12 = msg_hw_ptr;
    volume = (msg_hw_ptr->speaker).volume;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7d395;
    tryEncodeCommand___8_1(prVar12,0x4000,'\x0e',(uchar)volume);
    prVar12 = msg_hw_ptr;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7d3a8;
    uVar19 = testAndClearCommandMaskBit(prVar12,4);
    prVar12 = msg_hw_ptr;
    if ((uVar19 & 1) != 0) {
      for (local_398 = 0; local_398 < 3; local_398 = local_398 + 1) {
        local_168 = *(undefined8 *)(msg_hw_ptr[1].packets[0].data + 0x11);
        local_150 = *(undefined8 *)(msg_hw_ptr[1].packets[1].data + 1);
        local_639 = 0;
        local_3a1 = 0;
        local_3a0 = 7;
        uVar14 = local_3a0;
        local_3a0 = 7;
        local_160 = local_168;
        local_158 = local_168;
        local_148 = local_150;
        local_140 = local_150;
        if (6 < 0x14 - msg_hw_ptr->packets[local_398].size) {
          msg_hw_ptr->packets[local_398].data[msg_hw_ptr->packets[local_398].size] = '%';
          local_648 = (*(double *)(msg_hw_ptr[1].packets[0].data + 1) * 10.0) / 2.0;
          if (750.0 <= local_648) {
            local_648 = 750.0;
          }
          if (local_648 <= -750.0) {
            local_650 = -750.0;
          }
          else {
            local_650 = local_648;
          }
          local_3b0 = local_650;
          local_658 = (*(double *)(msg_hw_ptr[1].packets[0].data + 9) * 1000.0) / 8.0;
          if (1000.0 <= local_658) {
            local_658 = 1000.0;
          }
          if (local_658 <= -1000.0) {
            local_660 = -1000.0;
          }
          else {
            local_660 = local_658;
          }
          local_3b8 = local_660;
          iVar18 = (int)local_650;
          local_3ba = (undefined2)iVar18;
          local_3bc = (ushort)(int)local_660;
          msg_hw_ptr->packets[local_398].data[msg_hw_ptr->packets[local_398].size + 1] =
               (char)iVar18;
          msg_hw_ptr->packets[local_398].data[msg_hw_ptr->packets[local_398].size + 2] =
               (char)(int)local_660;
          msg_hw_ptr->packets[local_398].data[msg_hw_ptr->packets[local_398].size + 3] =
               (byte)((short)(local_3bc & 0x700) >> 5) | (byte)((uint)iVar18 >> 8) & 7;
          local_668 = ABS(*(double *)(msg_hw_ptr[1].packets[0].data + 0x11));
          if (1023.0 <= local_668) {
            local_668 = 1023.0;
          }
          if (local_668 <= 0.0) {
            local_670 = 0.0;
          }
          else {
            local_670 = local_668;
          }
          local_678 = (ABS(*(double *)(msg_hw_ptr[1].packets[1].data + 1)) * 1000.0) / 64.0;
          if (1023.0 <= local_678) {
            local_678 = 1023.0;
          }
          if (local_678 <= 0.0) {
            local_680 = 0.0;
          }
          else {
            local_680 = local_678;
          }
          iVar18 = (int)local_670;
          local_3d2 = (undefined2)iVar18;
          local_3d4 = (ushort)(int)local_680;
          msg_hw_ptr->packets[local_398].data[msg_hw_ptr->packets[local_398].size + 4] =
               (char)iVar18;
          msg_hw_ptr->packets[local_398].data[msg_hw_ptr->packets[local_398].size + 5] =
               (char)(int)local_680;
          msg_hw_ptr->packets[local_398].data[msg_hw_ptr->packets[local_398].size + 6] =
               (byte)((short)(local_3d4 & 0x300) >> 6) | (byte)((uint)iVar18 >> 8) & 3;
          local_3c8 = local_670;
          local_3d0 = local_680;
          msg_hw_ptr->packets[local_398].size = msg_hw_ptr->packets[local_398].size + 7;
          break;
        }
        local_3a1 = 0;
        local_3a0 = uVar14;
      }
    }
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7dc16;
    uVar19 = testAndClearCommandMaskBit(prVar12,0x20000);
    if ((uVar19 & 1) != 0) {
      mode = *(int *)(msg_hw_ptr[1].field2_0x50 + 0xd);
      if ((mode == 0) || (local_688 = mode + -6, mode - 2U < 4)) {
        *(double *)local_200 = 0.0;
      }
      for (i = 0; i < 3; i = i + 1) {
        if ((*(int *)(msg_hw_ptr[1].field2_0x50 + 0xd) == 3) ||
           (*(int *)(msg_hw_ptr[1].field2_0x50 + 0xd) == 4)) {
          pose_origin_msg_len = 9;
          if (8 < 0x14 - msg_hw_ptr->packets[i].size) {
            if (*(int *)(msg_hw_ptr[1].field2_0x50 + 0xd) == 3) {
              local_3e1 = '\x17';
            }
            else {
              local_3e1 = ')';
            }
            local_690 = *(double *)(msg_hw_ptr[1].packets[2].data + 1) * 10.0;
            if (32767.0 <= local_690) {
              local_690 = 32767.0;
            }
            if (local_690 <= -32768.0) {
              local_698 = -32768.0;
            }
            else {
              local_698 = local_690;
            }
            x_enc = local_698;
            local_3f0 = local_698;
            local_6a0 = *(double *)(msg_hw_ptr[1].packets[2].data + 9) * 10.0;
            if (32767.0 <= local_6a0) {
              local_6a0 = 32767.0;
            }
            if (local_6a0 <= -32768.0) {
              local_6a8 = -32768.0;
            }
            else {
              local_6a8 = local_6a0;
            }
            local_3f8 = local_6a8;
            local_6b0 = *(double *)(msg_hw_ptr[1].packets[2].data + 0x11) * 100.0;
            if (32767.0 <= local_6b0) {
              local_6b0 = 32767.0;
            }
            if (local_6b0 <= -32768.0) {
              local_6b8 = -32768.0;
            }
            else {
              local_6b8 = local_6b0;
            }
            local_400 = local_6b8;
            local_6c0 = *(double *)(msg_hw_ptr[1].field2_0x50 + 5) * 1000.0;
            if (65535.0 <= local_6c0) {
              local_6c0 = 65535.0;
            }
            if (local_6c0 <= 0.0) {
              local_6c8 = 0.0;
            }
            else {
              local_6c8 = local_6c0;
            }
            local_408 = local_6c8;
            *(undefined8 *)((long)pppHVar24 + -8) = 0x7e067;
            dVar26 = (double)_round(x_enc);
            x_enc = local_3f8;
            local_40a = (undefined2)(int)dVar26;
            *(undefined8 *)((long)pppHVar24 + -8) = 0x7e082;
            dVar26 = (double)_round(x_enc);
            x_enc = local_400;
            local_40c = (undefined2)(int)dVar26;
            *(undefined8 *)((long)pppHVar24 + -8) = 0x7e09d;
            dVar26 = (double)_round(x_enc);
            x_enc = local_408;
            local_40e = (undefined2)(int)dVar26;
            *(undefined8 *)((long)pppHVar24 + -8) = 0x7e0b8;
            local_6d0 = (double)_round(x_enc);
            iVar18 = (int)local_6d0;
            local_410 = (undefined2)iVar18;
            msg_hw_ptr->packets[i].data[msg_hw_ptr->packets[i].size] = local_3e1;
            msg_hw_ptr->packets[i].data[msg_hw_ptr->packets[i].size + 1] =
                 (char)((ushort)local_40a >> 8);
            msg_hw_ptr->packets[i].data[msg_hw_ptr->packets[i].size + 2] = (char)local_40a;
            msg_hw_ptr->packets[i].data[msg_hw_ptr->packets[i].size + 3] =
                 (char)((ushort)local_40c >> 8);
            msg_hw_ptr->packets[i].data[msg_hw_ptr->packets[i].size + 4] = (char)local_40c;
            msg_hw_ptr->packets[i].data[msg_hw_ptr->packets[i].size + 5] =
                 (char)((ushort)local_40e >> 8);
            msg_hw_ptr->packets[i].data[msg_hw_ptr->packets[i].size + 6] = (char)local_40e;
            msg_hw_ptr->packets[i].data[msg_hw_ptr->packets[i].size + 7] = (char)((uint)iVar18 >> 8)
            ;
            msg_hw_ptr->packets[i].data[msg_hw_ptr->packets[i].size + 8] = (char)iVar18;
            msg_hw_ptr->packets[i].size = msg_hw_ptr->packets[i].size + (int)pose_origin_msg_len;
            break;
          }
        }
        else {
          local_411 = '#';
          msg_len = 9;
          if (8 < 0x14 - msg_hw_ptr->packets[i].size) {
            x_enc = *(double *)(msg_hw_ptr[1].packets[2].data + 1) * 10.0;
            local_430 = *(double *)(msg_hw_ptr[1].packets[2].data + 9) * 10.0;
            local_438 = *(double *)(msg_hw_ptr[1].packets[2].data + 0x11) * 100.0;
            local_440 = local_438 - *(double *)local_200;
            local_6d8 = *(double *)(msg_hw_ptr[1].field2_0x50 + 5) * 1000.0;
            if (65535.0 <= local_6d8) {
              local_6d8 = 65535.0;
            }
            if (local_6d8 <= 0.0) {
              local_6e0 = 0.0;
            }
            else {
              local_6e0 = local_6d8;
            }
            local_448 = local_6e0;
            local_428 = x_enc;
            *(undefined8 *)((long)pppHVar24 + -8) = 0x7e580;
            dVar26 = (double)_round(x_enc);
            x_enc = local_430;
            local_44a = (undefined2)(int)dVar26;
            *(undefined8 *)((long)pppHVar24 + -8) = 0x7e59b;
            dVar26 = (double)_round(x_enc);
            x_enc = local_440;
            local_44c = (undefined2)(int)dVar26;
            *(undefined8 *)((long)pppHVar24 + -8) = 0x7e5b6;
            x_enc = (double)_round(x_enc);
            local_6e2 = (short)(int)x_enc;
            iVar18 = (int)local_448;
            local_450 = (undefined2)iVar18;
            *(double *)local_200 = (double)(int)local_6e2 - local_440;
            msg_hw_ptr->packets[i].data[msg_hw_ptr->packets[i].size] = local_411;
            msg_hw_ptr->packets[i].data[msg_hw_ptr->packets[i].size + 1] = (char)local_44a;
            msg_hw_ptr->packets[i].data[msg_hw_ptr->packets[i].size + 2] = (char)local_44c;
            msg_hw_ptr->packets[i].data[msg_hw_ptr->packets[i].size + 3] = (char)(int)x_enc;
            msg_hw_ptr->packets[i].data[msg_hw_ptr->packets[i].size + 4] = (char)((uint)iVar18 >> 8)
            ;
            msg_hw_ptr->packets[i].data[msg_hw_ptr->packets[i].size + 5] = (char)iVar18;
            msg_hw_ptr->packets[i].data[msg_hw_ptr->packets[i].size + 6] =
                 (byte)((ushort)local_44a >> 8) & 0x3f;
            msg_hw_ptr->packets[i].data[msg_hw_ptr->packets[i].size + 7] =
                 (byte)((ushort)local_44c >> 8) & 0x3f;
            uVar25 = msg_hw_ptr->packets[i].size + 6;
            msg_hw_ptr->packets[i].data[uVar25] =
                 msg_hw_ptr->packets[i].data[uVar25] | (byte)(local_6e2 >> 2) & 0xc0;
            uVar25 = msg_hw_ptr->packets[i].size + 7;
            msg_hw_ptr->packets[i].data[uVar25] =
                 msg_hw_ptr->packets[i].data[uVar25] | (byte)(local_6e2 >> 4) & 0xc0;
            msg_hw_ptr->packets[i].data[msg_hw_ptr->packets[i].size + 8] = '\0';
            if (*(int *)(msg_hw_ptr[1].field2_0x50 + 0xd) == 5) {
              local_6e8 = 3;
            }
            else {
              local_6e8 = *(int *)(msg_hw_ptr[1].field2_0x50 + 0xd);
            }
            uVar25 = msg_hw_ptr->packets[i].size + 8;
            msg_hw_ptr->packets[i].data[uVar25] =
                 msg_hw_ptr->packets[i].data[uVar25] | (byte)(local_6e8 << 6);
            uVar25 = msg_hw_ptr->packets[i].size + 8;
            msg_hw_ptr->packets[i].data[uVar25] =
                 msg_hw_ptr->packets[i].data[uVar25] | (msg_hw_ptr[1].field2_0x50[0x19] & 1) << 5;
            uVar25 = msg_hw_ptr->packets[i].size + 8;
            msg_hw_ptr->packets[i].data[uVar25] =
                 msg_hw_ptr->packets[i].data[uVar25] |
                 (byte)(*(int *)(msg_hw_ptr[1].field2_0x50 + 0x15) << 4);
            uVar25 = msg_hw_ptr->packets[i].size + 8;
            msg_hw_ptr->packets[i].data[uVar25] =
                 msg_hw_ptr->packets[i].data[uVar25] |
                 (byte)*(undefined4 *)(msg_hw_ptr[1].field2_0x50 + 0x11);
            msg_hw_ptr->packets[i].size = msg_hw_ptr->packets[i].size + (int)msg_len;
            local_44e = local_6e2;
            break;
          }
        }
      }
    }
    prVar12 = msg_hw_ptr;
    uVar9 = *(undefined4 *)((long)&(msg_hw_ptr->pose).mode + 2);
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7eb91;
    tryEncodeCommand___8_1(prVar12,0x8000,200,(uchar)uVar9);
    prVar12 = msg_hw_ptr;
    volume = *(ushort *)(msg_hw_ptr[1].field0_0x0 + 1);
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7ebbb;
    tryEncodeCommandLtl16_1(prVar12,0x8000000000,0xff,volume);
    prVar12 = msg_hw_ptr;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7ebd3;
    tryEncodeCommand___8_0(prVar12,0x80000000,'\'');
    prVar12 = msg_hw_ptr;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7ebe9;
    uVar19 = testAndClearCommandMaskBit(prVar12,0x200000000);
    this_01 = local_200;
    if ((uVar19 & 1) != 0) {
      for (local_454 = 0; local_454 < 3; local_454 = local_454 + 1) {
        local_460 = 0x14;
        if (0x13 < 0x14 - msg_hw_ptr->packets[local_454].size) {
          volume = *(ushort *)(msg_hw_ptr[1].field2_0x50 + 0xa9);
          uVar6 = msg_hw_ptr[1].field2_0x50[0xbd];
          uVar7 = msg_hw_ptr[1].field2_0x50[0xdd];
          uVar8 = msg_hw_ptr[1].field2_0x50[0xfd];
          x_enc = *(double *)(msg_hw_ptr[1].field2_0x50 + 0xc5);
          dVar26 = *(double *)(msg_hw_ptr[1].field2_0x50 + 0xe5);
          dVar1 = *(double *)(msg_hw_ptr[1].field2_0x50 + 0x105);
          dVar2 = *(double *)(msg_hw_ptr[1].field2_0x50 + 0x125);
          dVar3 = *(double *)(msg_hw_ptr[1].field2_0x50 + 0xcd);
          dVar4 = *(double *)(msg_hw_ptr[1].field2_0x50 + 0xed);
          local_6e9 = uVar6;
          dVar5 = *(double *)(msg_hw_ptr[1].field2_0x50 + 0x12d);
          local_6f0 = 0;
          local_6f2 = *(ushort *)(msg_hw_ptr[1].field2_0x50 + 0xab);
          local_700 = msg_hw_ptr;
          local_702 = (ushort)(int)*(double *)(msg_hw_ptr[1].field2_0x50 + 0x10d);
          *(uint *)((long)pppHVar24 + -0x60) = (uint)(byte)msg_hw_ptr[1].field2_0x50[0x11d];
          *(uint *)((long)pppHVar24 + -0x58) = (int)(x_enc * 10.0) & 0xffff;
          *(uint *)((long)pppHVar24 + -0x50) = (int)(dVar26 * 10.0) & 0xffff;
          *(uint *)((long)pppHVar24 + -0x48) = (int)(dVar1 * 10.0) & 0xffff;
          *(uint *)((long)pppHVar24 + -0x40) = (int)(dVar2 * 10.0) & 0xffff;
          *(uint *)((long)pppHVar24 + -0x38) = (int)dVar3 & 0xffff;
          *(uint *)((long)pppHVar24 + -0x30) = (int)dVar4 & 0xffff;
          *(uint *)((long)pppHVar24 + -0x28) = (uint)local_702;
          *(uint *)((long)pppHVar24 + -0x20) = (int)dVar5 & 0xffff;
          *(uint *)((long)pppHVar24 + -0x18) = (uint)local_6f2;
          *(uint *)((long)pppHVar24 + -0x10) = (uint)*(ushort *)(local_700[1].field2_0x50 + 0xad);
          *(undefined8 *)((long)pppHVar24 + -0x68) = 0x7edd7;
          bVar17 = RobotHW::setSynthStateAndCheckForChange
                             (this_01,'\0',volume,uVar6,uVar7,uVar8,
                              *(uchar *)((long)pppHVar24 + -0x60),
                              *(ushort *)((long)pppHVar24 + -0x58),
                              *(ushort *)((long)pppHVar24 + -0x50),
                              *(ushort *)((long)pppHVar24 + -0x48),
                              *(ushort *)((long)pppHVar24 + -0x40),
                              *(ushort *)((long)pppHVar24 + -0x38),
                              *(ushort *)((long)pppHVar24 + -0x30),
                              *(ushort *)((long)pppHVar24 + -0x28),
                              *(ushort *)((long)pppHVar24 + -0x20),
                              *(ushort *)((long)pppHVar24 + -0x18),
                              *(ushort *)((long)pppHVar24 + -0x10));
          local_461 = bVar17 & 1;
          if ((bVar17 & 1) == 0) {
            msg_hw_ptr->packets[local_454].data[msg_hw_ptr->packets[local_454].size] = '(';
            lVar23 = (long)local_454;
            uVar10 = msg_hw_ptr->packets[lVar23].size;
            ppVar11 = msg_hw_ptr->packets;
            x_enc = *(double *)(msg_hw_ptr[1].field2_0x50 + 0xc5);
            dVar26 = *(double *)(msg_hw_ptr[1].field2_0x50 + 0xe5);
            dVar1 = *(double *)(msg_hw_ptr[1].field2_0x50 + 0x105);
            dVar2 = *(double *)(msg_hw_ptr[1].field2_0x50 + 0x125);
            *(undefined8 *)((long)pppHVar24 + -8) = 0x7f09b;
            btCommandSetAudioSynthUpdate
                      ((btCommandAudioSynthUpdate_t *)(ppVar11[lVar23].data + (uVar10 + 1)),
                       (ushort)(int)(x_enc * 10.0),(ushort)(int)(dVar26 * 10.0),
                       (ushort)(int)(dVar1 * 10.0),(ushort)(int)(dVar2 * 10.0));
          }
          else {
            msg_hw_ptr->packets[local_454].data[msg_hw_ptr->packets[local_454].size] = '!';
            lVar23 = (long)local_454;
            uVar10 = msg_hw_ptr->packets[lVar23].size;
            ppVar11 = msg_hw_ptr->packets;
            volume = *(ushort *)(msg_hw_ptr[1].field2_0x50 + 0xa9);
            uVar6 = msg_hw_ptr[1].field2_0x50[0xbd];
            uVar7 = msg_hw_ptr[1].field2_0x50[0xdd];
            bVar17 = msg_hw_ptr[1].field2_0x50[0x11d];
            x_enc = *(double *)(msg_hw_ptr[1].field2_0x50 + 0xc5);
            dVar26 = *(double *)(msg_hw_ptr[1].field2_0x50 + 0xe5);
            dVar1 = *(double *)(msg_hw_ptr[1].field2_0x50 + 0x105);
            dVar2 = *(double *)(msg_hw_ptr[1].field2_0x50 + 0xcd);
            local_708 = 0;
            dVar3 = *(double *)(msg_hw_ptr[1].field2_0x50 + 0x10d);
            local_70a = (ushort)(int)(*(double *)(msg_hw_ptr[1].field2_0x50 + 0x125) * 10.0);
            local_70c = *(ushort *)(msg_hw_ptr[1].field2_0x50 + 0xab);
            local_718 = msg_hw_ptr;
            local_71a = volume;
            local_71c = (ushort)(int)*(double *)(msg_hw_ptr[1].field2_0x50 + 0xed);
            local_71e = (ushort)(int)*(double *)(msg_hw_ptr[1].field2_0x50 + 0x12d);
            *(uint *)((long)pppHVar24 + -0x60) = (uint)(byte)msg_hw_ptr[1].field2_0x50[0xfd];
            *(uint *)((long)pppHVar24 + -0x58) = (uint)bVar17;
            *(uint *)((long)pppHVar24 + -0x50) = (int)(x_enc * 10.0) & 0xffff;
            *(uint *)((long)pppHVar24 + -0x48) = (int)(dVar26 * 10.0) & 0xffff;
            *(uint *)((long)pppHVar24 + -0x40) = (int)(dVar1 * 10.0) & 0xffff;
            *(uint *)((long)pppHVar24 + -0x38) = (uint)local_70a;
            *(uint *)((long)pppHVar24 + -0x30) = (int)dVar2 & 0xffff;
            *(uint *)((long)pppHVar24 + -0x28) = (uint)local_71c;
            *(uint *)((long)pppHVar24 + -0x20) = (int)dVar3 & 0xffff;
            *(uint *)((long)pppHVar24 + -0x18) = (uint)local_71e;
            *(uint *)((long)pppHVar24 + -0x10) = (uint)local_70c;
            *(uint *)((long)pppHVar24 + -8) = (uint)*(ushort *)(local_718[1].field2_0x50 + 0xad);
            *(undefined8 *)((long)pppHVar24 + -0x68) = 0x7efe1;
            btCommandSetAudioSynth
                      ((btCommandAudioSynth_t *)(ppVar11[lVar23].data + (uVar10 + 1)),'\0','\0',
                       volume,uVar6,uVar7,*(uchar *)((long)pppHVar24 + -0x60),
                       *(uchar *)((long)pppHVar24 + -0x58),*(ushort *)((long)pppHVar24 + -0x50),
                       *(ushort *)((long)pppHVar24 + -0x48),*(ushort *)((long)pppHVar24 + -0x40),
                       *(ushort *)((long)pppHVar24 + -0x38),*(ushort *)((long)pppHVar24 + -0x30),
                       *(ushort *)((long)pppHVar24 + -0x28),*(ushort *)((long)pppHVar24 + -0x20),
                       *(ushort *)((long)pppHVar24 + -0x18),*(ushort *)((long)pppHVar24 + -0x10),
                       *(ushort *)((long)pppHVar24 + -8));
          }
          msg_hw_ptr->packets[local_454].size = msg_hw_ptr->packets[local_454].size + (int)local_460
          ;
          break;
        }
      }
    }
    prVar12 = msg_hw_ptr;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7f0ff;
    uVar19 = testAndClearCommandMaskBit(prVar12,0x10000000000);
    prVar12 = msg_hw_ptr;
    if ((uVar19 & 1) != 0) {
      for (local_468 = 0; local_468 < 3; local_468 = local_468 + 1) {
        local_470 = 10;
        if (9 < 0x14 - msg_hw_ptr->packets[local_468].size) {
          msg_hw_ptr->packets[local_468].data[msg_hw_ptr->packets[local_468].size] = '@';
          msg_hw_ptr->packets[local_468].data[msg_hw_ptr->packets[local_468].size + 1] =
               (char)((ushort)*(undefined2 *)(msg_hw_ptr[1].field2_0x50 + 0x13f) >> 8);
          msg_hw_ptr->packets[local_468].data[msg_hw_ptr->packets[local_468].size + 2] =
               (char)*(undefined2 *)(msg_hw_ptr[1].field2_0x50 + 0x13f);
          msg_hw_ptr->packets[local_468].data[msg_hw_ptr->packets[local_468].size + 3] =
               msg_hw_ptr[1].field2_0x50[0x141];
          msg_hw_ptr->packets[local_468].data[msg_hw_ptr->packets[local_468].size + 4] =
               msg_hw_ptr[1].field2_0x50[0x142];
          msg_hw_ptr->packets[local_468].data[msg_hw_ptr->packets[local_468].size + 5] =
               msg_hw_ptr[1].field2_0x50[0x143];
          msg_hw_ptr->packets[local_468].data[msg_hw_ptr->packets[local_468].size + 6] =
               msg_hw_ptr[1].field2_0x50[0x144];
          msg_hw_ptr->packets[local_468].data[msg_hw_ptr->packets[local_468].size + 7] =
               msg_hw_ptr[1].field2_0x50[0x145];
          msg_hw_ptr->packets[local_468].data[msg_hw_ptr->packets[local_468].size + 8] =
               msg_hw_ptr[1].field2_0x50[0x146];
          msg_hw_ptr->packets[local_468].data[msg_hw_ptr->packets[local_468].size + 9] =
               msg_hw_ptr[1].field2_0x50[0x147];
          msg_hw_ptr->packets[local_468].size = msg_hw_ptr->packets[local_468].size + 10;
          break;
        }
      }
    }
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7f4dc;
    uVar19 = testAndClearCommandMaskBit(prVar12,0x20000000000);
    prVar12 = msg_hw_ptr;
    if ((uVar19 & 1) != 0) {
      for (local_474 = 0; local_474 < 3; local_474 = local_474 + 1) {
        local_480 = 3;
        if (2 < 0x14 - msg_hw_ptr->packets[local_474].size) {
          msg_hw_ptr->packets[local_474].data[msg_hw_ptr->packets[local_474].size] = 'A';
          msg_hw_ptr->packets[local_474].data[msg_hw_ptr->packets[local_474].size + 1] =
               (char)((ushort)*(undefined2 *)(msg_hw_ptr[1].field2_0x50 + 0x153) >> 8);
          msg_hw_ptr->packets[local_474].data[msg_hw_ptr->packets[local_474].size + 2] =
               (char)*(undefined2 *)(msg_hw_ptr[1].field2_0x50 + 0x153);
          msg_hw_ptr->packets[local_474].size = msg_hw_ptr->packets[local_474].size + 3;
          break;
        }
      }
    }
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7f697;
    uVar19 = testAndClearCommandMaskBit(prVar12,0x8000000000000);
    if ((uVar19 & 1) != 0) {
      for (local_484 = 0; local_484 < 3; local_484 = local_484 + 1) {
        local_490 = 3;
        if (2 < 0x14 - msg_hw_ptr->packets[local_484].size) {
          msg_hw_ptr->packets[local_484].data[msg_hw_ptr->packets[local_484].size] = -0x4e;
          msg_hw_ptr->packets[local_484].data[msg_hw_ptr->packets[local_484].size + 1] = '\0';
          uVar25 = msg_hw_ptr->packets[local_484].size + 1;
          msg_hw_ptr->packets[local_484].data[uVar25] =
               msg_hw_ptr->packets[local_484].data[uVar25] | msg_hw_ptr->field2_0x50[0x1f2] << 7;
          uVar25 = msg_hw_ptr->packets[local_484].size + 1;
          msg_hw_ptr->packets[local_484].data[uVar25] =
               msg_hw_ptr->packets[local_484].data[uVar25] |
               (msg_hw_ptr->field2_0x50[0x1f1] & 1) << 6;
          uVar25 = msg_hw_ptr->packets[local_484].size + 1;
          msg_hw_ptr->packets[local_484].data[uVar25] =
               msg_hw_ptr->packets[local_484].data[uVar25] | msg_hw_ptr->field2_0x50[0x1f0] & 0x3f;
          msg_hw_ptr->packets[local_484].data[msg_hw_ptr->packets[local_484].size + 2] =
               msg_hw_ptr->field2_0x50[499];
          msg_hw_ptr->packets[local_484].size = msg_hw_ptr->packets[local_484].size + 3;
          break;
        }
      }
    }
    for (local_494 = 0; this_00 = local_4a8, local_494 < 3; local_494 = local_494 + 1) {
      if (msg_hw_ptr->packets[local_494].size != 0) {
        local_130 = &local_4a0;
        ppHVar21 = (HALPacket_t **)(msg_hw_ptr[1].field2_0x50 + 0x15d);
        local_4a0 = msg_hw_ptr->packets + local_494;
        local_118 = (ulong *)(msg_hw_ptr[1].field2_0x50 + 0x16d);
        local_728 = ppHVar21;
        local_128 = ppHVar21;
        local_120 = ppHVar21;
        local_110 = local_118;
        if (*(ulong *)(msg_hw_ptr[1].field2_0x50 + 0x165) < *local_118) {
          local_f8 = local_138;
          local_108 = 1;
          local_f0 = 1;
          local_b0 = msg_hw_ptr[1].field2_0x50 + 0x16d;
          local_b8 = *(long **)(msg_hw_ptr[1].field2_0x50 + 0x165);
          *local_b8 = (long)local_4a0;
          *(long *)(msg_hw_ptr[1].field2_0x50 + 0x165) =
               *(long *)(msg_hw_ptr[1].field2_0x50 + 0x165) + 8;
          local_100 = ppHVar21;
          local_e8 = ppHVar21;
          local_e0 = local_f8;
          local_d0 = local_f8;
          local_c0 = local_130;
          local_a8 = local_130;
          local_a0 = local_130;
          local_98 = local_b8;
          local_90 = local_b0;
          local_88 = local_130;
          local_80 = local_130;
          local_78 = local_b8;
          local_70 = local_b0;
          local_68 = local_130;
          local_60 = local_130;
          local_58 = local_b8;
          local_50 = ppHVar21;
          local_48 = local_b0;
          local_40 = local_b0;
        }
        else {
          local_d8 = local_130;
          *(undefined8 *)((long)pppHVar24 + -8) = 0x7fb65;
          std::vector<HALPacket_t*,std::allocator<HALPacket_t*>>::
          __push_back_slow_path<HALPacket_t*>(ppHVar21);
        }
      }
    }
    prVar12 = msg_hw_ptr + 1;
    *(undefined8 *)((long)pppHVar24 + -8) = 0x7fb9f;
    std::vector<HALPacket_t*,std::allocator<HALPacket_t*>>::vector
              ((vector<HALPacket_t*,std::allocator<HALPacket_t*>> *)this_00,
               (vector *)(prVar12->field2_0x50 + 0x15d));
  }
  if (*(long *)PTR____stack_chk_guard_000e21b8 != local_38) {
                    /* WARNING: Subroutine does not return */
    *(undefined **)((long)pppHVar24 + -8) = &UNK_0007fbe9;
    ___stack_chk_fail();
  }
  return local_4b0;
LAB_0007a95e:
  local_224 = local_224 + 1;
  goto LAB_0007a747;
LAB_0007aaea:
  local_238 = local_238 + 1;
  goto LAB_0007a9a4;
LAB_0007ad3a:
  local_248 = local_248 + 1;
  goto LAB_0007ab48;
LAB_0007af3c:
  local_258 = local_258 + 1;
  goto LAB_0007ad7d;
LAB_0007b13e:
  local_268 = local_268 + 1;
  goto LAB_0007af7f;
LAB_0007b3c2:
  local_278 = local_278 + 1;
  goto LAB_0007b181;
LAB_0007b888:
  local_28c = local_28c + 1;
  goto LAB_0007b408;
LAB_0007ba63:
  local_2c8 = local_2c8 + 1;
  goto LAB_0007b8ce;
LAB_0007bc3e:
  local_2d8 = local_2d8 + 1;
  goto LAB_0007baa9;
LAB_0007bf0e:
  local_2e8 = local_2e8 + 1;
  goto LAB_0007bc81;
LAB_0007c20f:
  local_2fc = local_2fc + 1;
  goto LAB_0007bf51;
}

