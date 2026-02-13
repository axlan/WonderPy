#include <stdint.h>

typedef enum nx_json_type {
  NX_JSON_NULL,    // this is null value
  NX_JSON_OBJECT,  // this is an object; properties can be found in child nodes
  NX_JSON_ARRAY,   // this is an array; items can be found in child nodes
  NX_JSON_STRING,  // this is a string; value can be found in text_value field
  NX_JSON_INTEGER, // this is an integer; value can be found in int_value field
  NX_JSON_DOUBLE,  // this is a double; value can be found in dbl_value field
  NX_JSON_BOOL     // this is a boolean; value can be found in int_value field
} nx_json_type;

typedef struct nx_json {
  nx_json_type type;       // type of json node, see above
  const char* key;         // key of the property; for object's children only
  const char* text_value;  // text value of STRING node
  long int_value;          // the value of INTEGER or BOOL node
  double dbl_value;        // the value of DOUBLE node
  int length;              // number of children of OBJECT or ARRAY
  nx_json* child;          // points to first child
  nx_json* next;           // points to next child
} nx_json;

typedef enum {
    HAL_LAUNCHER_RELOAD_LEFT  = 0,
    HAL_LAUNCHER_RELOAD_RIGHT = 1,
} HALLauncherDirection_e;

typedef struct {
    uint8_t _pad[8];       /* bytes 0–7: not accessed in this function */
    uint8_t speed_or_dir;  /* byte 8:    0–255 scaled speed (speed / 255 cm_s),
                                         or 0/1 direction flag (dir) */
} HALLauncher_t;

typedef enum {
    HAL_LED_LEFT_EAR         = 0x01,  /* 0x66 = 102: WW_COMMAND_LIGHT_RGB_LEFT_EAR */
    HAL_LED_RIGHT_EAR        = 0x02,  /* 0x67 = 103: WW_COMMAND_LIGHT_RGB_RIGHT_EAR */
    HAL_LED_EYE              = 0x04,  /* 0x65 = 101: WW_COMMAND_LIGHT_RGB_EYE */
    HAL_LED_CHEST            = 0x04,  /* 0x68 = 104: WW_COMMAND_LIGHT_RGB_CHEST — shares bit with EYE */
    HAL_LED_BUTTON_MAIN_MONO = 0x08,  /* 0x6a = 106: WW_COMMAND_LIGHT_MONO_BUTTON_MAIN */
    HAL_LED_BUTTON_MAIN_RGB  = 0x08,  /* 0x6b = 107: WW_COMMAND_LIGHT_RGB_BUTTON_MAIN — shares bit with MONO */
} HALLedFlags_e;

typedef struct {
    uint8_t _pad[8];    /* bytes 0–7:  unknown */
    uint8_t leds;       /* byte 8:     bitmask of HALLedFlags_e */
    uint8_t _pad2[2];   /* bytes 9–10: unknown */
    uint8_t message;    /* byte 11:    message ID, range 0–255 */
} HALLedMsg_t;

typedef struct HALBodyPose_t {
    uint8_t padding[8];        // Offset 0x00 - unknown/padding
    double x;                  // Offset 0x08
    double y;                  // Offset 0x10
    double theta;              // Offset 0x18 (angle in radians, converted from degrees)
    double time;               // Offset 0x20
    int32_t mode;              // Offset 0x28
    int32_t dir;               // Offset 0x2C
    int32_t wrap_theta;        // Offset 0x30
    uint8_t ease;              // Offset 0x34 (boolean: 0 or 1)
    uint8_t padding2[3];       // Offset 0x35-0x37 (alignment padding)
} HALBodyPose_t;

typedef struct {
    uint32_t component_id;  /* offset 0:  component identifier, referenced in error logging */
    uint8_t  _pad[4];       /* offset 4:  alignment padding for double */
    double   prcnt;         /* offset 8:  percentage, clamped to [-100.0, 100.0] */
} HALComponentScalar_t;

typedef struct {
    uint32_t component_id;  /* offset 0: component identifier (consistent with HALComponentScalar_t) */
    uint8_t  _pad[4];       /* offset 4: alignment padding for double */
    double   cm_s;          /* offset 8: wheel velocity in cm/s, unclamped */
} HALMotorWheel_t;

typedef struct {
    uint32_t component_id;  /* offset 0 */
    uint8_t  _pad[4];       /* offset 4 */
    uint8_t  brightness;    /* offset 8: 0–255, scaled from 0.0–1.0 */
} HALLED_t;

typedef struct {
    uint32_t component_id;  /* offset 0 */
    uint8_t  _pad[4];       /* offset 4 */
    uint8_t  ch1;           /* offset 8:  channel 1 brightness, 0–255 */
    uint8_t  ch2;           /* offset 9:  channel 2 brightness, 0–255 */
    uint8_t  ch3;           /* offset 10: channel 3 brightness, 0–255 */
} HALLED3_t;

typedef struct {
    uint32_t component_id;  /* offset 0 */
    uint8_t  _pad[4];       /* offset 4 */
    uint8_t  r;             /* offset 8 */
    uint8_t  g;             /* offset 9 */
    uint8_t  b;             /* offset 10 */
} HALRGB_t;

typedef enum {
    HAL_EYE_BRIGHTNESS_UNIFORM    = 0,
    HAL_EYE_BRIGHTNESS_QUADRANT   = 1,
} HALEyeBrightnessMode_e;

// The index_mask and quad[] fields overlap in usage — index_mask is written
// when parsing the "index" key, while quad[] is only written when
// brightness_mode == 1. They don't conflict since they're controlled by
// different JSON keys, but the layout is tight. The assert confirms ledNum is
// 1-based and <= 12, with LED 12 wrapping to bit 0, so it's a ring of exactly
// 12 LEDs. The 5 bytes of _pad2 at offsets 13–17 are genuinely unknown — other
// functions will be needed to reveal them.
typedef struct {
    uint32_t component_id;      /* offset 0 */
    uint8_t  _pad[4];           /* offset 4 */
    int32_t  animation;         /* offset 8:  animation ID, or 0xffff = all LEDs */
    uint8_t  brightness;        /* offset 12: uniform brightness, 0–255 */
    uint8_t  _pad2[5];          /* offset 13–17: unknown */
    uint16_t index_mask;        /* offset 24: bitmask of active LEDs (bits 0–11, 12 LEDs) */
    uint8_t  quad[4];           /* offset 26: per-quadrant brightness [0–3], 0–255 each */
    uint8_t  _pad3[2];          /* offset 30–31: alignment padding */
    uint32_t brightness_mode;   /* offset 32: HALEyeBrightnessMode_e */
} HALEyeRing_t;

typedef struct {
    uint32_t component_id;  /* offset 0 */
    uint8_t  _pad[4];       /* offset 4 */
    char     file[16];      /* offset 8:  filename, max 15 chars + null */
    uint16_t volume;        /* offset 24: playback volume (0-100) */
} HALSpeaker_t;

typedef struct {
    uint32_t component_id;  /* offset 0 */
    uint8_t  _pad[4];       /* offset 4 */
    char     file[16];      /* offset 8: animation filename, max 15 chars + null */
} HALAnim_t;

#include <stdint.h>

typedef struct {
    uint32_t component_id;  /* offset 0 */
    uint8_t  _pad[4];       /* offset 4 */
    char     name[19];      /* offset 8:  user name, max 18 chars + null */
    uint8_t  _pad2[1];      /* offset 27: alignment padding */
    int32_t  color;         /* offset 28: personality color ID, 0xff = unset */
    int32_t  anim;          /* offset 32: personality anim ID, 0xff = unset */
    int32_t  avatar;        /* offset 36: avatar ID, 0xff = unset */
    uint8_t  s;             /* offset 40: boolean flag */
    char     entr[50];      /* offset 41: entry string, max 50 chars */
    uint8_t  _pad3[5];      /* offset 91-95: alignment padding to 8-byte boundary */
    uint64_t entr_len;      /* offset 96: cached strlen of entr */
    double   pvolume;       /* offset 104: personality volume */
    double   peyebright;    /* offset 112: personality eye brightness */
} HALUserSetting_t;

typedef struct {
    uint32_t component_id;      /* offset 0 */
    uint8_t  _pad[4];           /* offset 4 */
    double   linear_cm_s;       /* offset 8:  linear velocity, cm/s */
    double   angular_rad_s;     /* offset 16: angular velocity, rad/s (accepts cm_s or deg_s input) */
    double   linear_acc_cm_s2;  /* offset 24: linear acceleration, cm/s², NaN = unset */
    double   angular_acc_rad_s2;/* offset 32: angular acceleration, rad/s², NaN = unset */
    uint8_t  pose;              /* offset 40: pose flag, boolean */
} HALBodyMotionLinearAngular_t;

typedef struct {
    uint32_t component_id;  /* offset 0 */
    uint8_t  _pad[4];       /* offset 4 */
    int32_t  pwr;           /* offset 8: power cmd (4 is soft reset) */
} HALPower_t;

typedef struct {
    uint32_t component_id;  /* offset 0 */
    uint8_t  _pad[4];       /* offset 4 */
    int16_t  pingID;        /* offset 8 */
} HALPing_t;

typedef struct {
    uint8_t  _pad[8];   /* offset 0:  reserved/unknown */
    int32_t  type;      /* offset 8:  tone type */
    uint8_t  _pad2[4];  /* offset 12: alignment padding */
    double   freq;      /* offset 16: frequency */
    double   phase;     /* offset 24: phase */
} HALAudioSynthTone_t;  /* total: 32 bytes */

typedef struct {
    uint32_t          component_id;  /* offset 0 */
    uint8_t           _pad[4];       /* offset 4 */
    int32_t           type;          /* offset 8:  synth type */
    int16_t           duration;      /* offset 12: duration */
    int16_t           perc1;         /* offset 14: percent param 1 */
    int16_t           perc2;         /* offset 16: percent param 2 */
    uint8_t           _pad2[6];      /* offset 18: alignment padding to 8-byte boundary */
    HALAudioSynthTone_t tone[4];     /* offset 24: tones 1–4, 4 * 32 = 128 bytes */
} HALAudioSynth_t;                   /* total: at least 152 bytes */

typedef struct {
    uint32_t component_id;    /* offset 0 */
    uint8_t  _pad[4];         /* offset 4 */
    double   time;            /* offset 8:  movement duration */
    double   angular_rad_s;   /* offset 16: angular velocity, rad/s */
    double   angle_rad;       /* offset 24: target angle, rad (float-precision, from degrees) */
    uint8_t  hold;            /* offset 32: hold position flag, boolean */
} HALMotorServo_t;

typedef struct {
    uint32_t component_id;  /* offset 0 */
    uint8_t  _pad[4];       /* offset 4 */
    uint8_t  pressed;       /* offset 8: 1 = pressed (inverted from JSON int_value) */
} HALButton_t;

typedef struct {
    uint32_t component_id;  /* offset 0 */
    uint8_t  _pad[4];       /* offset 4 */
    double   refl;          /* offset 8:  reflectance */
    double   cm;            /* offset 16: distance in cm */
} HALDistance_t;


typedef enum {
    HAL_PAMP_CMD_OBSTACLES  = 0,
    HAL_PAMP_CMD_ANIM       = 10,
    HAL_PAMP_CMD_UNK_14     = 0x14,
    HAL_PAMP_CMD_SQUARE     = 0x1e,
    HAL_PAMP_CMD_PERIODIC_PAN   = 0x28,
    HAL_PAMP_CMD_PERIODIC_TILT  = 0x32,
    HAL_PAMP_CMD_PERIODIC_ROT   = 0x3c,
    HAL_PAMP_CMD_PERIODIC_VEL   = 0x46,
} HALPampCmd_e;

/* Per-command parameter layouts, all occupying bytes 0xd–0x12 */
typedef struct {
    uint8_t backup;         /* offset 0: bkup boolean */
    uint8_t _pad[5];
} HALPampObstaclesParams_t;

typedef struct {
    uint8_t anim_id_lo;     /* offset 0: low bits of anim ID */
    uint8_t anim_id_hi;     /* offset 1: high bits of anim ID (>> 1) */
    uint8_t max_scl;        /* offset 2: max scale, (val/2)*255, only if not NaN */
    uint8_t _pad[2];
    uint8_t flags;          /* offset 5: bit0=repeat, bit1=has_scale */
} HALPampAnimParams_t;

typedef struct {
    uint8_t sidelen_cm;     /* offset 0: side length, truncated float */
    uint8_t sidetm_ds;      /* offset 1: side time * 10 (deciseconds) */
    uint8_t turntm_ds;      /* offset 2: turn time * 10 (deciseconds) */
    uint8_t _pad[3];
} HALPampSquareParams_t;

/* periodic commands use encodePeriodic/encodePeriodicZeroMean — layout
   determined by those functions, not directly visible here */
typedef struct {
    uint8_t encoded[6];     /* offset 0: opaque encoded periodic params */
} HALPampPeriodicParams_t;

// The name "Pamplemousse" (French for grapefruit) is almost certainly an
// internal codename for the autonomous behavior/motion planning system.
typedef struct {
    uint32_t component_id;          /* offset 0 */
    uint8_t  _pad[4];               /* offset 4 */
    uint8_t  is_start;              /* offset 8:  start vs stop flag */
    uint8_t  _pad2;                 /* offset 9:  unused */
    int16_t  cmd_id;                /* offset 10: HALPampCmd_e, -1 = unset */
    uint8_t  weight;                /* offset 12: blending weight 0–255 */
    union {
        uint8_t                  raw[6];      /* raw param bytes */
        HALPampObstaclesParams_t obstacles;
        HALPampAnimParams_t      anim;
        HALPampSquareParams_t    square;
        HALPampPeriodicParams_t  periodic;
    } params;                       /* offset 13: command-specific params */
} HALPamplemousse_t;                /* total: at least 19 bytes */
