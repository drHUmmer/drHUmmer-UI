#ifndef UIINFO_H
#define	UIINFO_H

//////////////////
// Button Modes //
//////////////////
#define MOMENTARY   0
#define TOGGLED     1

////////////////////
// Rotary Encoder //
////////////////////
typedef struct {
    signed char     value;          // Current value
    unsigned char   prevValA : 1;
    unsigned char   prevValB : 1;
} RotaryEncoder_TypeDef;
RotaryEncoder_TypeDef rotary_encoder_default = {0,0,0};

////////////
// Button //
////////////
typedef struct {
    unsigned char   value   : 1;    // Self explanatory
    unsigned char   prevVal : 1;    // Previous value
    unsigned char   mode    : 1;    // LIVE / PULSE
} Button_TypeDef;
Button_TypeDef button_default = {0,0,0};

////////
// UI //
////////
typedef struct {
    Button_TypeDef  Butt_1;
    Button_TypeDef  Butt_2;
    Button_TypeDef  Butt_3;
    Button_TypeDef  Butt_4;
    Button_TypeDef  Butt_5;
    Button_TypeDef  Butt_6;
    Button_TypeDef  Butt_7;
    Button_TypeDef  Butt_8;
    Button_TypeDef  Butt_9;
    Button_TypeDef  Butt_10;
    Button_TypeDef  Butt_11;
    Button_TypeDef  Butt_12;
    Button_TypeDef  Butt_13;
    Button_TypeDef  Butt_14;
    Button_TypeDef  Butt_15;
    Button_TypeDef  Butt_16;
    Button_TypeDef  Butt_17;
    Button_TypeDef  Butt_18;
    Button_TypeDef  Butt_19;
    Button_TypeDef  Butt_20;
    Button_TypeDef  Butt_21;
    Button_TypeDef  Butt_22;
    Button_TypeDef  Butt_23;
    Button_TypeDef  Butt_24;
    Button_TypeDef  Butt_25;
    Button_TypeDef  Butt_26;
    Button_TypeDef  Butt_27;
    Button_TypeDef  Butt_28;
    Button_TypeDef  Butt_29;
    Button_TypeDef  Butt_30;
    Button_TypeDef  Butt_31;
    Button_TypeDef  Butt_32;

    RotaryEncoder_TypeDef RE_1;
    RotaryEncoder_TypeDef RE_2;
    RotaryEncoder_TypeDef RE_3;
    RotaryEncoder_TypeDef RE_4;
    RotaryEncoder_TypeDef RE_5;
    RotaryEncoder_TypeDef RE_6;
    RotaryEncoder_TypeDef RE_7;
    RotaryEncoder_TypeDef RE_8;
    RotaryEncoder_TypeDef RE_9;
    RotaryEncoder_TypeDef RE_10;
    RotaryEncoder_TypeDef RE_11;
} UI_TypeDef;
UI_TypeDef UIinfo;

#endif	// UIINFO_H