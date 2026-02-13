/* ===== parseLauncher @ 00066820 ===== */

/* APICore::BotMessengerBuffer::parseLauncher(nx_json const*, HALLauncher_t*) */

void __thiscall
APICore::BotMessengerBuffer::parseLauncher
          (BotMessengerBuffer *this,nx_json *param_1,HALLauncher_t *param_2)

{
  int iVar1;
  long lVar2;
  double local_40;
  double local_38;
  int local_24;
  
  if (param_2 != (HALLauncher_t *)0x0) {
    for (local_24 = 0; local_24 < param_1->length; local_24 = local_24 + 1) {
      lVar2 = _nx_json_item(param_1,local_24);
      iVar1 = _strcmp(*(char **)(lVar2 + 8),"cm_s");
      if (iVar1 == 0) {
        if (*(double *)(lVar2 + 0x20) <= 1.0) {
          if (0.0 < *(double *)(lVar2 + 0x20) || *(double *)(lVar2 + 0x20) == 0.0) {
            local_40 = *(double *)(lVar2 + 0x20);
          }
          else {
            local_40 = 0.0;
          }
          local_38 = local_40;
        }
        else {
          local_38 = 1.0;
        }
        param_2[8] = SUB41((int)(local_38 * 255.0),0);
      }
      else {
        iVar1 = _strcmp(*(char **)(lVar2 + 8),"dir");
        if (iVar1 == 0) {
          if (*(long *)(lVar2 + 0x18) == 1) {
            param_2[8] = (HALLauncher_t)0x1;
          }
          else {
            param_2[8] = (HALLauncher_t)0x2;
          }
        }
      }
    }
  }
  return;
}



/* ===== parseLedMsg @ 00066980 ===== */

/* APICore::BotMessengerBuffer::parseLedMsg(nx_json const*, HALLedMsg_t*) */

void __thiscall
APICore::BotMessengerBuffer::parseLedMsg
          (BotMessengerBuffer *this,nx_json *param_1,HALLedMsg_t *param_2)

{
  int iVar1;
  int *piVar2;
  long local_38;
  int local_24;
  
  if (param_2 != (HALLedMsg_t *)0x0) {
    for (local_24 = 0; local_24 < param_1->length; local_24 = local_24 + 1) {
      piVar2 = (int *)_nx_json_item(param_1,local_24);
      iVar1 = _strcmp(*(char **)(piVar2 + 2),"message");
      if (iVar1 == 0) {
        param_2[0xb] = SUB81(*(undefined8 *)(piVar2 + 6),0);
        if ((*(long *)(piVar2 + 6) < 0) || (0xff < *(long *)(piVar2 + 6))) {
          _printf("Parsing LedMsg: message out of range : %ld",*(undefined8 *)(piVar2 + 6));
          _printf("\n");
        }
      }
      else {
        iVar1 = _strcmp(*(char **)(piVar2 + 2),"LEDs");
        if (iVar1 == 0) {
          if (*piVar2 == 2) {
            for (local_38 = *(long *)(piVar2 + 0xc); local_38 != 0;
                local_38 = *(long *)(local_38 + 0x38)) {
              if (*(long *)(local_38 + 0x18) == 0x66) {
                param_2[8] = (HALLedMsg_t)((byte)param_2[8] | 1);
              }
              else if (*(long *)(local_38 + 0x18) == 0x67) {
                param_2[8] = (HALLedMsg_t)((byte)param_2[8] | 2);
              }
              else if (*(long *)(local_38 + 0x18) == 0x65) {
                param_2[8] = (HALLedMsg_t)((byte)param_2[8] | 4);
              }
              else if (*(long *)(local_38 + 0x18) == 0x68) {
                param_2[8] = (HALLedMsg_t)((byte)param_2[8] | 4);
              }
              else if (*(long *)(local_38 + 0x18) == 0x6b) {
                param_2[8] = (HALLedMsg_t)((byte)param_2[8] | 8);
              }
              else if (*(long *)(local_38 + 0x18) == 0x6a) {
                param_2[8] = (HALLedMsg_t)((byte)param_2[8] | 8);
              }
              else {
                _printf("Parsing LedMsg: unrecognized LED: \"%s\"",*(undefined8 *)(local_38 + 0x10))
                ;
                _printf("\n");
              }
            }
          }
          else {
            _printf("Parsing LedMsg: LEDs not at array");
            _printf("\n");
          }
        }
      }
    }
  }
  return;
}



/* ===== parseScalarPercentage @ 00066cb0 ===== */

/* APICore::BotMessengerBuffer::parseScalarPercentage(nx_json const*, HALComponentScalar_t*) */

void __thiscall
APICore::BotMessengerBuffer::parseScalarPercentage
          (BotMessengerBuffer *this,nx_json *param_1,HALComponentScalar_t *param_2)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  undefined8 local_40;
  undefined8 local_38;
  int local_28;
  
  if (param_2 != (HALComponentScalar_t *)0x0) {
    bVar1 = false;
    for (local_28 = 0; local_28 < param_1->length; local_28 = local_28 + 1) {
      lVar3 = _nx_json_item(param_1,local_28);
      iVar2 = _strcmp(*(char **)(lVar3 + 8),"prcnt");
      if (iVar2 == 0) {
        if (*(double *)(lVar3 + 0x20) <= 100.0) {
          if (-100.0 < *(double *)(lVar3 + 0x20) || *(double *)(lVar3 + 0x20) == -100.0) {
            local_40 = *(undefined8 *)(lVar3 + 0x20);
          }
          else {
            local_40 = 0xc059000000000000;
          }
          local_38 = local_40;
        }
        else {
          local_38 = 0x4059000000000000;
        }
        *(undefined8 *)(param_2 + 8) = local_38;
        bVar1 = true;
      }
    }
    if (!bVar1) {
      _printf("malformed json for component %d: missing %s\n",(ulong)*(uint *)param_2,"prcnt");
      _printf("\n");
    }
  }
  return;
}



/* ===== parseMotorWheel @ 00066df0 ===== */

/* APICore::BotMessengerBuffer::parseMotorWheel(nx_json const*, HALMotorWheel_t*) */

void __thiscall
APICore::BotMessengerBuffer::parseMotorWheel
          (BotMessengerBuffer *this,nx_json *param_1,HALMotorWheel_t *param_2)

{
  int iVar1;
  long lVar2;
  int local_24;
  
  if (param_2 != (HALMotorWheel_t *)0x0) {
    for (local_24 = 0; local_24 < param_1->length; local_24 = local_24 + 1) {
      lVar2 = _nx_json_item(param_1,local_24);
      iVar1 = _strcmp(*(char **)(lVar2 + 8),"cm_s");
      if (iVar1 == 0) {
        *(undefined8 *)(param_2 + 8) = *(undefined8 *)(lVar2 + 0x20);
      }
    }
  }
  return;
}



/* ===== parseBodyWheels @ 00066e90 ===== */

/* APICore::BotMessengerBuffer::parseBodyWheels(nx_json const*, HALMotorWheel_t*, HALMotorWheel_t*)
    */

void __thiscall
APICore::BotMessengerBuffer::parseBodyWheels
          (BotMessengerBuffer *this,nx_json *param_1,HALMotorWheel_t *param_2,
          HALMotorWheel_t *param_3)

{
  int iVar1;
  nx_json *lVar2;
  int local_2c;
  
  if ((param_2 != (HALMotorWheel_t *)0x0) && (param_3 != (HALMotorWheel_t *)0x0)) {
    for (local_2c = 0; local_2c < param_1->length; local_2c = local_2c + 1) {
      lVar2 = (nx_json *)_nx_json_item(param_1,local_2c);
      iVar1 = _strcmp(lVar2->key,"left_cm_s");
      if (iVar1 == 0) {
        *(double *)(param_2 + 8) = lVar2->dbl_value;
      }
      iVar1 = _strcmp(lVar2->key,"right_cm_s");
      if (iVar1 == 0) {
        *(double *)(param_3 + 8) = lVar2->dbl_value;
      }
    }
  }
  return;
}



/* ===== parseLightLED @ 00066f70 ===== */

/* APICore::BotMessengerBuffer::parseLightLED(nx_json const*, HALLED_t*) */

void __thiscall
APICore::BotMessengerBuffer::parseLightLED
          (BotMessengerBuffer *this,nx_json *param_1,HALLED_t *param_2)

{
  int iVar1;
  long lVar2;
  int local_24;
  
  if (param_2 != (HALLED_t *)0x0) {
    for (local_24 = 0; local_24 < param_1->length; local_24 = local_24 + 1) {
      lVar2 = _nx_json_item(param_1,local_24);
      iVar1 = _strcmp(*(char **)(lVar2 + 8),"brightness");
      if (iVar1 == 0) {
        param_2[8] = SUB41((int)(*(double *)(lVar2 + 0x20) * 255.0),0);
      }
    }
  }
  return;
}



/* ===== parseLightLED3 @ 00067020 ===== */

/* APICore::BotMessengerBuffer::parseLightLED3(nx_json const*, HALLED3_t*) */

void __thiscall
APICore::BotMessengerBuffer::parseLightLED3
          (BotMessengerBuffer *this,nx_json *param_1,HALLED3_t *param_2)

{
  int iVar1;
  long lVar2;
  int local_24;
  
  if (param_2 != (HALLED3_t *)0x0) {
    for (local_24 = 0; local_24 < param_1->length; local_24 = local_24 + 1) {
      lVar2 = _nx_json_item(param_1,local_24);
      iVar1 = _strcmp(*(char **)(lVar2 + 8),"1");
      if (iVar1 == 0) {
        param_2[8] = SUB41((int)(*(double *)(lVar2 + 0x20) * 255.0),0);
      }
      else {
        iVar1 = _strcmp(*(char **)(lVar2 + 8),"2");
        if (iVar1 == 0) {
          param_2[9] = SUB41((int)(*(double *)(lVar2 + 0x20) * 255.0),0);
        }
        else {
          iVar1 = _strcmp(*(char **)(lVar2 + 8),"3");
          if (iVar1 == 0) {
            param_2[10] = SUB41((int)(*(double *)(lVar2 + 0x20) * 255.0),0);
          }
        }
      }
    }
  }
  return;
}



/* ===== parseLightRGB @ 00067160 ===== */

/* APICore::BotMessengerBuffer::parseLightRGB(nx_json const*, HALRGB_t*) */

void __thiscall
APICore::BotMessengerBuffer::parseLightRGB
          (BotMessengerBuffer *this,nx_json *param_1,HALRGB_t *param_2)

{
  int iVar1;
  long lVar2;
  int local_24;
  
  if (param_2 != (HALRGB_t *)0x0) {
    for (local_24 = 0; local_24 < param_1->length; local_24 = local_24 + 1) {
      lVar2 = _nx_json_item(param_1,local_24);
      iVar1 = _strcmp(*(char **)(lVar2 + 8),"r");
      if (iVar1 == 0) {
        param_2[8] = SUB41((int)(*(double *)(lVar2 + 0x20) * 255.0),0);
      }
      else {
        iVar1 = _strcmp(*(char **)(lVar2 + 8),"g");
        if (iVar1 == 0) {
          param_2[9] = SUB41((int)(*(double *)(lVar2 + 0x20) * 255.0),0);
        }
        else {
          iVar1 = _strcmp(*(char **)(lVar2 + 8),"b");
          if (iVar1 == 0) {
            param_2[10] = SUB41((int)(*(double *)(lVar2 + 0x20) * 255.0),0);
          }
        }
      }
    }
  }
  return;
}



/* ===== parseEyeRing @ 000672a0 ===== */

/* APICore::BotMessengerBuffer::parseEyeRing(nx_json const*, HALEyeRing_t*) */

void __thiscall
APICore::BotMessengerBuffer::parseEyeRing
          (BotMessengerBuffer *this,nx_json *param_1,HALEyeRing_t *param_2)

{
  HALEyeRing_t HVar1;
  int iVar2;
  nx_json *pnVar3;
  long lVar4;
  int local_54;
  int local_44;
  int local_34;
  int local_24;
  
  if (param_2 != (HALEyeRing_t *)0x0) {
    for (local_24 = 0; local_24 < param_1->length; local_24 = local_24 + 1) {
      pnVar3 = (nx_json *)_nx_json_item(param_1,local_24);
      iVar2 = _strcmp(pnVar3->key,"animation");
      if (iVar2 == 0) {
        *(int *)(param_2 + 8) = (int)pnVar3->int_value;
      }
      else {
        iVar2 = _strcmp(pnVar3->key,"brightness");
        if (iVar2 == 0) {
          if ((int)pnVar3->type == 2) {
            if (pnVar3->length == 1) {
              *(undefined4 *)(param_2 + 0x20) = 0;
              HVar1 = (HALEyeRing_t)parseBrightnessValue(*(nx_json **)((long)&pnVar3->child + 4));
              param_2[0xc] = HVar1;
            }
            else if (pnVar3->length == 4) {
              *(undefined4 *)(param_2 + 0x20) = 1;
              HVar1 = (HALEyeRing_t)parseBrightnessValue(*(nx_json **)((long)&pnVar3->child + 4));
              param_2[0x1a] = HVar1;
              HVar1 = (HALEyeRing_t)
                      parseBrightnessValue
                                (*(nx_json **)(*(long *)((long)&pnVar3->child + 4) + 0x38));
              param_2[0x1b] = HVar1;
              HVar1 = (HALEyeRing_t)
                      parseBrightnessValue
                                (*(nx_json **)
                                  (*(long *)(*(long *)((long)&pnVar3->child + 4) + 0x38) + 0x38));
              param_2[0x1c] = HVar1;
              HVar1 = (HALEyeRing_t)
                      parseBrightnessValue
                                (*(nx_json **)
                                  (*(long *)(*(long *)(*(long *)((long)&pnVar3->child + 4) + 0x38) +
                                            0x38) + 0x38));
              param_2[0x1d] = HVar1;
            }
            else {
              *(undefined4 *)(param_2 + 0x20) = 0;
              param_2[0xc] = (HALEyeRing_t)0xff;
              _printf("error: unsupported brightness mode: %d\n",(ulong)(uint)pnVar3->length);
            }
          }
          else {
            HVar1 = (HALEyeRing_t)parseBrightnessValue(pnVar3);
            param_2[0xc] = HVar1;
            *(undefined4 *)(param_2 + 0x20) = 0;
          }
        }
        else {
          iVar2 = _strcmp(pnVar3->key,"index");
          if (iVar2 == 0) {
            *(undefined4 *)(param_2 + 8) = 0xffff;
            *(undefined2 *)(param_2 + 0x18) = 0;
            if ((int)pnVar3->type == 2) {
              for (local_34 = 0; local_34 < pnVar3->length; local_34 = local_34 + 1) {
                lVar4 = _nx_json_item(pnVar3,local_34);
                if (0 < *(long *)(lVar4 + 0x18)) {
                  *(ushort *)(param_2 + 0x18) =
                       *(ushort *)(param_2 + 0x18) | (ushort)(1 << ((byte)local_34 & 0x1f));
                }
              }
            }
            else if ((int)pnVar3->type == 1) {
              for (local_44 = 0; local_44 < pnVar3->length; local_44 = local_44 + 1) {
                lVar4 = _nx_json_item(pnVar3,local_44);
                if (0 < *(long *)(lVar4 + 0x18)) {
                  local_54 = _atoi(*(char **)(lVar4 + 8));
                  if (local_54 < 1) {
                    /* WARNING: Subroutine does not return */
                    ___assert_rtn("parseEyeRing",
                                  "/Users/orion/git/playi/APIPy/WWLib/WWHAL/CoreUtility/BotMessengerBuffer.cpp"
                                  ,0x22c,"ledNum >= 1");
                  }
                  if (0xc < local_54) {
                    /* WARNING: Subroutine does not return */
                    ___assert_rtn("parseEyeRing",
                                  "/Users/orion/git/playi/APIPy/WWLib/WWHAL/CoreUtility/BotMessengerBuffer.cpp"
                                  ,0x22d,"ledNum <= _WW_EYE_LED_COUNT");
                  }
                  if (local_54 == 0xc) {
                    local_54 = 0;
                  }
                  *(ushort *)(param_2 + 0x18) =
                       *(ushort *)(param_2 + 0x18) | (ushort)(1 << ((byte)local_54 & 0x1f));
                }
              }
            }
            else {
              _printf("error: malformed json for eyering");
              _printf("\n");
            }
          }
        }
      }
    }
  }
  return;
}



/* ===== parseSpeaker @ 00067670 ===== */

/* APICore::BotMessengerBuffer::parseSpeaker(nx_json const*, HALSpeaker_t*) */

void __thiscall
APICore::BotMessengerBuffer::parseSpeaker
          (BotMessengerBuffer *this,nx_json *param_1,HALSpeaker_t *param_2)

{
  if (param_2 != (HALSpeaker_t *)0x0) {
    _parseMediaCommand(param_1,param_2->file,0xf,&param_2->volume);
  }
  return;
}



/* ===== parseOnRobotAnim @ 000676d0 ===== */

/* APICore::BotMessengerBuffer::parseOnRobotAnim(nx_json const*, HALAnim_t*) */

void __thiscall
APICore::BotMessengerBuffer::parseOnRobotAnim
          (BotMessengerBuffer *this,nx_json *param_1,HALAnim_t *param_2)

{
  if (param_2 != (HALAnim_t *)0x0) {
    _parseMediaCommand(param_1,(char *)(param_2 + 8),0xf,(ushort *)0x0);
  }
  return;
}



/* ===== parseUserSettings @ 00067720 ===== */

/* APICore::BotMessengerBuffer::parseUserSettings(nx_json const*, HALUserSetting_t*) */

void __thiscall
APICore::BotMessengerBuffer::parseUserSettings
          (BotMessengerBuffer *this,nx_json *param_1,HALUserSetting_t *param_2)

{
  byte bVar1;
  int iVar2;
  long lVar3;
  size_t sVar4;
  size_t local_48;
  int local_24;
  
  if (param_2 != (HALUserSetting_t *)0x0) {
    _memset(param_2 + 8,0,0x13);
    *(undefined4 *)(param_2 + 0x20) = 0xff;
    *(undefined4 *)(param_2 + 0x1c) = 0xff;
    *(undefined4 *)(param_2 + 0x24) = 0xff;
    param_2[0x28] = (HALUserSetting_t)0x0;
    param_2[0x29] = (HALUserSetting_t)0x0;
    *(undefined8 *)(param_2 + 0x60) = 0;
    for (local_24 = 0; local_24 < param_1->length; local_24 = local_24 + 1) {
      lVar3 = _nx_json_item(param_1,local_24);
      iVar2 = _strcmp(*(char **)(lVar3 + 8),"name");
      if (iVar2 == 0) {
        sVar4 = _strlen(*(char **)(lVar3 + 0x10));
        if (sVar4 < 0x13) {
          local_48 = _strlen(*(char **)(lVar3 + 0x10));
        }
        else {
          local_48 = 0x12;
        }
        _strncpy((char *)(param_2 + 8),*(char **)(lVar3 + 0x10),local_48);
      }
      else {
        iVar2 = _strcmp(*(char **)(lVar3 + 8),"color");
        if (iVar2 == 0) {
          *(int *)(param_2 + 0x1c) = (int)*(undefined8 *)(lVar3 + 0x18);
        }
        else {
          iVar2 = _strcmp(*(char **)(lVar3 + 8),"anim");
          if (iVar2 == 0) {
            *(int *)(param_2 + 0x20) = (int)*(undefined8 *)(lVar3 + 0x18);
          }
          else {
            iVar2 = _strcmp(*(char **)(lVar3 + 8),"pvolume");
            if (iVar2 == 0) {
              *(undefined8 *)(param_2 + 0x68) = *(undefined8 *)(lVar3 + 0x20);
            }
            else {
              iVar2 = _strcmp(*(char **)(lVar3 + 8),"peyebright");
              if (iVar2 == 0) {
                *(undefined8 *)(param_2 + 0x70) = *(undefined8 *)(lVar3 + 0x20);
              }
              else {
                iVar2 = _strcmp(*(char **)(lVar3 + 8),"avatar");
                if (iVar2 == 0) {
                  *(int *)(param_2 + 0x24) = (int)*(undefined8 *)(lVar3 + 0x18);
                }
                else {
                  iVar2 = _strcmp(*(char **)(lVar3 + 8),"s");
                  if (iVar2 == 0) {
                    param_2[0x28] = (HALUserSetting_t)(*(long *)(lVar3 + 0x18) != 0);
                  }
                  else {
                    iVar2 = _strcmp(*(char **)(lVar3 + 8),"entr");
                    if (iVar2 == 0) {
                      _strncpy((char *)(param_2 + 0x29),*(char **)(lVar3 + 0x10),0x32);
                      sVar4 = _strlen((char *)(param_2 + 0x29));
                      *(size_t *)(param_2 + 0x60) = sVar4;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if ((*(int *)(param_2 + 0x1c) != 0xff) && (*(int *)(param_2 + 0x20) == 0xff)) {
      bVar1 = HAL::RobotHW::getRobotPersonalityAnimId(*(RobotHW **)(this + 0x20));
      *(uint *)(param_2 + 0x20) = (uint)bVar1;
    }
    if ((*(int *)(param_2 + 0x1c) == 0xff) && (*(int *)(param_2 + 0x20) != 0xff)) {
      bVar1 = HAL::RobotHW::getRobotPersonalityColorId(*(RobotHW **)(this + 0x20));
      *(uint *)(param_2 + 0x1c) = (uint)bVar1;
    }
  }
  return;
}



/* ===== parseBodyMotionLinearAngular @ 00067a90 ===== */

/* APICore::BotMessengerBuffer::parseBodyMotionLinearAngular(nx_json const*,
   HALBodyMotionLinearAngular_t*) */

void __thiscall
APICore::BotMessengerBuffer::parseBodyMotionLinearAngular
          (BotMessengerBuffer *this,nx_json *param_1,HALBodyMotionLinearAngular_t *param_2)

{
  int iVar1;
  long lVar2;
  int local_24;
  
  if (param_2 != (HALBodyMotionLinearAngular_t *)0x0) {
    param_2[0x28] = (HALBodyMotionLinearAngular_t)0x0;
    *(undefined8 *)(param_2 + 0x20) = 0x7ff8000000000000;
    *(undefined8 *)(param_2 + 0x18) = 0x7ff8000000000000;
    for (local_24 = 0; local_24 < param_1->length; local_24 = local_24 + 1) {
      lVar2 = _nx_json_item(param_1,local_24);
      iVar1 = _strcmp(*(char **)(lVar2 + 8),"linear_cm_s");
      if (iVar1 == 0) {
        *(undefined8 *)(param_2 + 8) = *(undefined8 *)(lVar2 + 0x20);
      }
      else {
        iVar1 = _strcmp(*(char **)(lVar2 + 8),"angular_cm_s");
        if (iVar1 == 0) {
          *(undefined8 *)(param_2 + 0x10) = *(undefined8 *)(lVar2 + 0x20);
        }
        else {
          iVar1 = _strcmp(*(char **)(lVar2 + 8),"angular_deg_s");
          if (iVar1 == 0) {
            *(double *)(param_2 + 0x10) = (*(double *)(lVar2 + 0x20) * 6.283185307179586) / 360.0;
          }
          else {
            iVar1 = _strcmp(*(char **)(lVar2 + 8),"linear_acc_cm_s_s");
            if (iVar1 == 0) {
              *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)(lVar2 + 0x20);
            }
            else {
              iVar1 = _strcmp(*(char **)(lVar2 + 8),"angular_acc_deg_s_s");
              if (iVar1 == 0) {
                *(double *)(param_2 + 0x20) =
                     (*(double *)(lVar2 + 0x20) * 6.283185307179586) / 360.0;
              }
              else {
                iVar1 = _strcmp(*(char **)(lVar2 + 8),"pose");
                if (iVar1 == 0) {
                  param_2[0x28] = (HALBodyMotionLinearAngular_t)(*(long *)(lVar2 + 0x18) != 0);
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}



/* ===== parseBodyPose @ 00067c90 ===== */

/* APICore::BotMessengerBuffer::parseBodyPose(nx_json const*, HALBodyPose_t*) */

void __thiscall
APICore::BotMessengerBuffer::parseBodyPose
          (BotMessengerBuffer *this,nx_json *param_1,HALBodyPose_t *param_2)

{
  int iVar1;
  nx_json *lVar2;
  int i;
  
  if (param_2 != (HALBodyPose_t *)0x0) {
    for (i = 0; i < param_1->length; i = i + 1) {
      lVar2 = (nx_json *)_nx_json_item(param_1,i);
      iVar1 = _strcmp(lVar2->key,"x");
      if (iVar1 == 0) {
        param_2->x = lVar2->dbl_value;
      }
      else {
        iVar1 = _strcmp(lVar2->key,"y");
        if (iVar1 == 0) {
          param_2->y = lVar2->dbl_value;
        }
        else {
          iVar1 = _strcmp(lVar2->key,"degree");
          if (iVar1 == 0) {
            param_2->theta = (lVar2->dbl_value * 6.283185307179586) / 360.0;
          }
          else {
            iVar1 = _strcmp(lVar2->key,"time");
            if (iVar1 == 0) {
              param_2->time = lVar2->dbl_value;
            }
            else {
              iVar1 = _strcmp(lVar2->key,"mode");
              if (iVar1 == 0) {
                param_2->mode = (uint32_t)lVar2->int_value;
              }
              else {
                iVar1 = _strcmp(lVar2->key,"dir");
                if (iVar1 == 0) {
                  param_2->dir = (uint32_t)lVar2->int_value;
                }
                else {
                  iVar1 = _strcmp(lVar2->key,"wrap_theta");
                  if (iVar1 == 0) {
                    param_2->wrap_theta = (uint32_t)lVar2->int_value;
                  }
                  else {
                    iVar1 = _strcmp(lVar2->key,"ease");
                    if (iVar1 == 0) {
                      param_2->ease = lVar2->int_value != 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}



/* ===== parsePower @ 00067ed0 ===== */

/* APICore::BotMessengerBuffer::parsePower(nx_json const*, HALPower_t*) */

void __thiscall
APICore::BotMessengerBuffer::parsePower
          (BotMessengerBuffer *this,nx_json *param_1,HALPower_t *param_2)

{
  int iVar1;
  long lVar2;
  int local_24;
  
  if (param_2 != (HALPower_t *)0x0) {
    for (local_24 = 0; local_24 < param_1->length; local_24 = local_24 + 1) {
      lVar2 = _nx_json_item(param_1,local_24);
      iVar1 = _strcmp(*(char **)(lVar2 + 8),"pwr");
      if (iVar1 == 0) {
        *(int *)(param_2 + 8) = (int)*(undefined8 *)(lVar2 + 0x18);
      }
    }
  }
  return;
}



/* ===== parsePing @ 00067f70 ===== */

/* APICore::BotMessengerBuffer::parsePing(nx_json const*, HALPing_t*) */

void __thiscall
APICore::BotMessengerBuffer::parsePing(BotMessengerBuffer *this,nx_json *param_1,HALPing_t *param_2)

{
  int iVar1;
  long lVar2;
  int local_24;
  
  if (param_2 != (HALPing_t *)0x0) {
    for (local_24 = 0; local_24 < param_1->length; local_24 = local_24 + 1) {
      lVar2 = _nx_json_item(param_1,local_24);
      iVar1 = _strcmp(*(char **)(lVar2 + 8),"pingID");
      if (iVar1 == 0) {
        *(short *)(param_2 + 8) = (short)*(undefined8 *)(lVar2 + 0x18);
      }
    }
  }
  return;
}



/* ===== parseAudioSynth @ 00068010 ===== */

/* APICore::BotMessengerBuffer::parseAudioSynth(nx_json const*, HALAudioSynth_t*) */

void __thiscall
APICore::BotMessengerBuffer::parseAudioSynth
          (BotMessengerBuffer *this,nx_json *param_1,HALAudioSynth_t *param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  int local_54;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined8 local_40;
  undefined8 local_38;
  int local_24;
  
  if (param_2 != (HALAudioSynth_t *)0x0) {
    for (local_24 = 0; local_24 < param_1->length; local_24 = local_24 + 1) {
      lVar2 = _nx_json_item(param_1,local_24);
      iVar1 = _strcmp(*(char **)(lVar2 + 8),"type");
      if (iVar1 == 0) {
        *(int *)(param_2 + 8) = (int)*(undefined8 *)(lVar2 + 0x18);
      }
      else {
        iVar1 = _strcmp(*(char **)(lVar2 + 8),"duration");
        if (iVar1 == 0) {
          *(short *)(param_2 + 0xc) = (short)*(undefined8 *)(lVar2 + 0x18);
        }
        else {
          iVar1 = _strcmp(*(char **)(lVar2 + 8),"perc1");
          if (iVar1 == 0) {
            *(short *)(param_2 + 0xe) = (short)*(undefined8 *)(lVar2 + 0x18);
          }
          else {
            iVar1 = _strcmp(*(char **)(lVar2 + 8),"perc2");
            if (iVar1 == 0) {
              *(short *)(param_2 + 0x10) = (short)*(undefined8 *)(lVar2 + 0x18);
            }
            else {
              iVar1 = _strcmp(*(char **)(lVar2 + 8),"type");
              if (iVar1 == 0) {
                *(int *)(param_2 + 8) = (int)*(undefined8 *)(lVar2 + 0x18);
              }
              else {
                iVar1 = _strncmp(*(char **)(lVar2 + 8),"tone",4);
                if (iVar1 == 0) {
                  local_48 = 0;
                  local_40 = 0;
                  local_38 = 0;
                  for (local_54 = 0; local_54 < *(int *)(lVar2 + 0x28); local_54 = local_54 + 1) {
                    lVar3 = _nx_json_item(lVar2,local_54);
                    iVar1 = _strcmp(*(char **)(lVar3 + 8),"type");
                    if (iVar1 == 0) {
                      local_48 = (undefined4)*(undefined8 *)(lVar3 + 0x18);
                    }
                    else {
                      iVar1 = _strcmp(*(char **)(lVar3 + 8),"freq");
                      if (iVar1 == 0) {
                        local_40 = *(undefined8 *)(lVar3 + 0x20);
                      }
                      else {
                        iVar1 = _strcmp(*(char **)(lVar3 + 8),"phase");
                        if (iVar1 == 0) {
                          local_38 = *(undefined8 *)(lVar3 + 0x20);
                        }
                      }
                    }
                  }
                  iVar1 = _strcmp(*(char **)(lVar2 + 8),"tone1");
                  if (iVar1 == 0) {
                    *(undefined8 *)(param_2 + 0x18) = local_50;
                    *(ulong *)(param_2 + 0x20) = CONCAT44(uStack_44,local_48);
                    *(undefined8 *)(param_2 + 0x28) = local_40;
                    *(undefined8 *)(param_2 + 0x30) = local_38;
                  }
                  else {
                    iVar1 = _strcmp(*(char **)(lVar2 + 8),"tone2");
                    if (iVar1 == 0) {
                      *(undefined8 *)(param_2 + 0x38) = local_50;
                      *(ulong *)(param_2 + 0x40) = CONCAT44(uStack_44,local_48);
                      *(undefined8 *)(param_2 + 0x48) = local_40;
                      *(undefined8 *)(param_2 + 0x50) = local_38;
                    }
                    else {
                      iVar1 = _strcmp(*(char **)(lVar2 + 8),"tone3");
                      if (iVar1 == 0) {
                        *(undefined8 *)(param_2 + 0x58) = local_50;
                        *(ulong *)(param_2 + 0x60) = CONCAT44(uStack_44,local_48);
                        *(undefined8 *)(param_2 + 0x68) = local_40;
                        *(undefined8 *)(param_2 + 0x70) = local_38;
                      }
                      else {
                        iVar1 = _strcmp(*(char **)(lVar2 + 8),"tone4");
                        if (iVar1 == 0) {
                          *(undefined8 *)(param_2 + 0x78) = local_50;
                          *(ulong *)(param_2 + 0x80) = CONCAT44(uStack_44,local_48);
                          *(undefined8 *)(param_2 + 0x88) = local_40;
                          *(undefined8 *)(param_2 + 0x90) = local_38;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}


/* ===== parseMotorServo @ 00068db0 ===== */

/* APICore::BotMessengerBuffer::parseMotorServo(nx_json const*, HALMotorServo_t*, bool) */

void __thiscall
APICore::BotMessengerBuffer::parseMotorServo
          (BotMessengerBuffer *this,nx_json *param_1,HALMotorServo_t *param_2,bool is_pan_not_tilt)

{
  int iVar1;
  nx_json *lVar2;
  double dVar2;
  int local_28;
  
  if (param_2 != (HALMotorServo_t *)0x0) {
    for (local_28 = 0; local_28 < param_1->length; local_28 = local_28 + 1) {
      lVar2 = (nx_json *)_nx_json_item(param_1,local_28);
      iVar1 = _strcmp(lVar2->key,"degree");
      if (iVar1 == 0) {
        dVar2 = (double)clampHeadServoValue(this,lVar2->dbl_value,param_3);
        *(double *)(param_2 + 0x18) = ((double)(float)dVar2 * 6.283185307179586) / 360.0;
      }
      iVar1 = _strcmp(lVar2->key,"time");
      if (iVar1 == 0) {
        *(double *)(param_2 + 8) = lVar2->dbl_value;
      }
      iVar1 = _strcmp(lVar2->key,"angular_cm_s");
      if (iVar1 == 0) {
        *(double *)(param_2 + 0x10) = lVar2->dbl_value;
      }
      iVar1 = _strcmp(lVar2->key,"angular_deg_s");
      if (iVar1 == 0) {
        *(double *)(param_2 + 0x10) = (lVar2->dbl_value * 6.283185307179586) / 360.0;
      }
      iVar1 = _strcmp(lVar2->key,"hold");
      if (iVar1 == 0) {
        param_2[0x20] = (HALMotorServo_t)(lVar2->int_value != 0);
      }
    }
  }
  return;
}



/* ===== parseBrightnessValue @ 00068f60 ===== */

/* APICore::parseBrightnessValue(nx_json const&) */

undefined1 APICore::parseBrightnessValue(nx_json *param_1)

{
  undefined1 local_9;
  
  if (param_1->dbl_value <= 1.0) {
    local_9 = (undefined1)(int)(param_1->dbl_value * 255.0);
  }
  else {
    local_9 = (undefined1)param_1->int_value;
  }
  return local_9;
}



/* ===== parseButton @ 00069160 ===== */

/* APICore::BotMessengerBuffer::parseButton(nx_json const*, HALButton_t*) */

void __thiscall
APICore::BotMessengerBuffer::parseButton
          (BotMessengerBuffer *this,nx_json *param_1,HALButton_t *param_2)

{
  int *piVar1;
  
  if ((param_2 != (HALButton_t *)0x0) && (piVar1 = (int *)_nx_json_get(param_1,"s"), *piVar1 != 0))
  {
    param_2[8] = (HALButton_t)(*(long *)(piVar1 + 6) == 0);
  }
  return;
}



/* ===== parseDistance @ 000691d0 ===== */

/* APICore::BotMessengerBuffer::parseDistance(nx_json const*, HALDistance_t*) */

void __thiscall
APICore::BotMessengerBuffer::parseDistance
          (BotMessengerBuffer *this,nx_json *param_1,HALDistance_t *param_2)

{
  int *piVar1;
  
  if (param_2 != (HALDistance_t *)0x0) {
    piVar1 = (int *)_nx_json_get(param_1,"cm");
    if (*piVar1 != 0) {
      *(undefined8 *)(param_2 + 0x10) = *(undefined8 *)(piVar1 + 8);
    }
    piVar1 = (int *)_nx_json_get(param_1,"refl");
    if (*piVar1 != 0) {
      *(undefined8 *)(param_2 + 8) = *(undefined8 *)(piVar1 + 8);
    }
  }
  return;
}



/* ===== parsePamplemousse @ 00069260 ===== */

/* APICore::parsePamplemousse(nx_json const*, HALPamplemousse_t*, bool) */

void APICore::parsePamplemousse(nx_json *param_1,HALPamplemousse_t *param_2,bool is_start)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  byte bVar4;
  double local_a8;
  double local_a0;
  ulong local_88;
  long local_80;
  int local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  uint local_50;
  float local_4c;
  float local_48;
  uint local_44;
  double local_40;
  float local_34;
  float local_30;
  
  if (param_2 != (HALPamplemousse_t *)0x0) {
    param_2[8] = (HALPamplemousse_t)param_3;
    *(undefined2 *)(param_2 + 10) = 0xffff;
    bVar1 = false;
    local_30 = NAN;
    local_34 = NAN;
    local_40 = NAN;
    local_44 = 0xffffffff;
    local_48 = NAN;
    local_4c = NAN;
    local_50 = 0xffffffff;
    local_54 = NAN;
    local_58 = NAN;
    local_5c = NAN;
    local_60 = NAN;
    for (local_64 = 0; local_64 < param_1->length; local_64 = local_64 + 1) {
      piVar3 = (int *)_nx_json_item(param_1);
      iVar2 = _strcmp(*(char **)(piVar3 + 2),"id");
      if (iVar2 == 0) {
        *(short *)(param_2 + 10) = (short)*(undefined8 *)(piVar3 + 6);
      }
      else {
        iVar2 = _strcmp(*(char **)(piVar3 + 2),"weight");
        if (iVar2 == 0) {
          local_a8 = *(double *)(piVar3 + 8);
          if (local_a8 <= 1.0) {
            if (local_a8 < 0.0) {
              local_a8 = 0.0;
            }
            local_a0 = local_a8;
          }
          else {
            local_a0 = 1.0;
          }
          param_2[0xc] = SUB41((int)(local_a0 * 255.0),0);
        }
        else {
          iVar2 = _strcmp(*(char **)(piVar3 + 2),"params");
          if (iVar2 == 0) {
            if (*piVar3 == 2) {
              local_80 = *(long *)(piVar3 + 0xc);
              local_88 = 0;
              for (; local_80 != 0; local_80 = *(long *)(local_80 + 0x38)) {
                param_2[local_88 + 0xd] = SUB81(*(undefined8 *)(local_80 + 0x18),0);
                local_88 = local_88 + 1;
                if (5 < local_88) {
                  _printf("error: too many parameter bytes\n");
                  break;
                }
              }
              if (local_88 == 6) {
                bVar1 = true;
              }
              else {
                _printf("error: too few parameter bytes\n");
              }
            }
            else {
              _printf("error: parameters not an array\n");
            }
          }
          else {
            iVar2 = _strcmp(*(char **)(piVar3 + 2),"amp_deg");
            if (iVar2 == 0) {
              local_34 = (float)*(double *)(piVar3 + 8);
            }
            else {
              iVar2 = _strcmp(*(char **)(piVar3 + 2),"amp_cm_s");
              if (iVar2 == 0) {
                local_30 = (float)*(double *)(piVar3 + 8);
              }
              else {
                iVar2 = _strcmp(*(char **)(piVar3 + 2),"anim");
                if (iVar2 == 0) {
                  local_40 = *(double *)(piVar3 + 8);
                }
                else {
                  iVar2 = _strcmp(*(char **)(piVar3 + 2),"bkup");
                  if (iVar2 == 0) {
                    local_44 = (uint)(*(long *)(piVar3 + 6) != 0);
                  }
                  else {
                    iVar2 = _strcmp(*(char **)(piVar3 + 2),"avg_deg");
                    if (iVar2 == 0) {
                      local_48 = (float)*(double *)(piVar3 + 8);
                    }
                    else {
                      iVar2 = _strcmp(*(char **)(piVar3 + 2),"prd_s");
                      if (iVar2 == 0) {
                        local_4c = (float)*(double *)(piVar3 + 8);
                      }
                      else {
                        iVar2 = _strcmp(*(char **)(piVar3 + 2),"rpt");
                        if (iVar2 == 0) {
                          local_50 = (uint)(*(long *)(piVar3 + 6) != 0);
                        }
                        else {
                          iVar2 = _strcmp(*(char **)(piVar3 + 2),"max_scl");
                          if (iVar2 == 0) {
                            local_54 = (float)*(double *)(piVar3 + 8);
                          }
                          else {
                            iVar2 = _strcmp(*(char **)(piVar3 + 2),"sidelen_cm");
                            if (iVar2 == 0) {
                              local_58 = (float)*(double *)(piVar3 + 8);
                            }
                            else {
                              iVar2 = _strcmp(*(char **)(piVar3 + 2),"sidetm_s");
                              if (iVar2 == 0) {
                                local_5c = (float)*(double *)(piVar3 + 8);
                              }
                              else {
                                iVar2 = _strcmp(*(char **)(piVar3 + 2),"turntm_s");
                                if (iVar2 == 0) {
                                  local_60 = (float)*(double *)(piVar3 + 8);
                                }
                                else {
                                  _printf("unrecognized value in json: %s\n",
                                          *(undefined8 *)(piVar3 + 2));
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    if (*(short *)(param_2 + 10) == -1) {
      _printf("error: no command ID in pamplemousse jason.\n");
                    /* WARNING: Subroutine does not return */
      ___assert_rtn("parsePamplemousse",
                    "/Users/orion/git/playi/APIPy/WWLib/WWHAL/CoreUtility/BotMessengerBuffer.cpp",
                    0x407,"false");
    }
    if ((!bVar1) && (param_3)) {
      switch(*(undefined2 *)(param_2 + 10)) {
      case 0:
        validateBoolParamIsSet(local_44,"obstacles needs backup");
        param_2[0x12] = (HALPamplemousse_t)(local_44 == 1);
        break;
      default:
        _printf("error: unhandled command id: %d.\n",(ulong)*(ushort *)(param_2 + 10));
        break;
      case 10:
        validateIntParamIsSet(local_40,"anim needs id");
        validateBoolParamIsSet(local_50,"anim needs repeat");
        param_2[0xd] = (HALPamplemousse_t)((byte)param_2[0xd] | (byte)(int)local_40);
        param_2[0xe] = (HALPamplemousse_t)
                       ((byte)param_2[0xe] | (byte)((int)((int)local_40 & 0xffffU) >> 1));
        bVar4 = 0;
        if (!NAN(local_54)) {
          bVar4 = 2;
        }
        param_2[0x12] = (HALPamplemousse_t)((byte)param_2[0x12] | bVar4);
        param_2[0x12] = (HALPamplemousse_t)((byte)param_2[0x12] | local_50 == 1);
        if (!NAN(local_54)) {
          if ((local_54 < 0.0) || (2.0 < local_54)) {
            _printf("error: animation scale out of range. using 1. %f\n",(double)local_54);
            local_54 = 1.0;
          }
          param_2[0xf] = SUB41((int)((local_54 / 2.0) * 255.0),0);
        }
        break;
      case 0x14:
        break;
      case 0x1e:
        validateFloatParamIsSet(local_58,"square needs sideLength");
        validateFloatParamIsSet(local_5c,"square needs sideTime");
        validateFloatParamIsSet(local_60,"square needs turnTime");
        param_2[0xd] = SUB41((int)local_58,0);
        param_2[0xe] = SUB41((int)(local_5c * 10.0),0);
        param_2[0xf] = SUB41((int)(local_60 * 10.0),0);
        break;
      case 0x28:
        encodePeriodic(local_48,local_34,local_4c,-7.5,22.5,0.0,30.0,param_2);
        break;
      case 0x32:
        encodePeriodic(local_48,local_34,local_4c,-120.0,120.0,0.0,240.0,param_2);
        break;
      case 0x3c:
        encodePeriodicZeroMean(local_34,local_4c,0.0,360.0,param_2);
        break;
      case 0x46:
        encodePeriodicZeroMean(local_30,local_4c,0.0,80.0,param_2);
      }
    }
  }
  return;
}
