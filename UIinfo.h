#ifndef UIINFO_H
#define	UIINFO_H

//////////////////
// Button Modes //
//////////////////
typedef enum {
    MOMENTARY = 0,
    TOGGLED
} ButtonMode_t;

typedef enum {
    RISING = 0,
    FALLING
} Edge_t;


////////////////////
// Rotary Encoder //
////////////////////
typedef struct {
    signed char     value;          // Current value
    unsigned char   prevValA : 1;
    unsigned char   prevValB : 1;
} RotaryEncoder_t;
RotaryEncoder_t rotary_encoder_default = {0,0,0};

////////////
// Button //
////////////
typedef struct {
    unsigned char   value   : 1;    // Self explanatory
    unsigned char   prevVal : 1;    // Previous value
    unsigned char   edge    : 1;    // Falling or rising edge
    char   mode    : 1;    // ButtonMode_t
} Button_t;
Button_t button_default = {0,0,0,0};

////////
// UI //
////////
typedef struct {
    Button_t  Butt_1;
    Button_t  Butt_2;
    Button_t  Butt_3;
    Button_t  Butt_4;
    Button_t  Butt_5;
    Button_t  Butt_6;
    Button_t  Butt_7;
    Button_t  Butt_8;
    Button_t  Butt_9;
    Button_t  Butt_10;
    Button_t  Butt_11;
    Button_t  Butt_12;
    Button_t  Butt_13;
    Button_t  Butt_14;
    Button_t  Butt_15;
    Button_t  Butt_16;
    Button_t  Butt_17;
    Button_t  Butt_18;
    Button_t  Butt_19;
    Button_t  Butt_20;
    Button_t  Butt_21;
    Button_t  Butt_22;
    Button_t  Butt_23;
    Button_t  Butt_24;
    Button_t  Butt_25;
    Button_t  Butt_26;
    Button_t  Butt_27;
    Button_t  Butt_28;
    Button_t  Butt_29;
    Button_t  Butt_30;
    Button_t  Butt_31;
    Button_t  Butt_32;

    RotaryEncoder_t RE_1;
    RotaryEncoder_t RE_2;
    RotaryEncoder_t RE_3;
    RotaryEncoder_t RE_4;
    RotaryEncoder_t RE_5;
    RotaryEncoder_t RE_6;
    RotaryEncoder_t RE_7;
    RotaryEncoder_t RE_8;
    RotaryEncoder_t RE_9;
    RotaryEncoder_t RE_10;
    RotaryEncoder_t RE_11;
} UI_TypeDef;
UI_TypeDef UIinfo;

#endif	// UIINFO_H