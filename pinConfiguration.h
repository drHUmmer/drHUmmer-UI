#ifndef PINCONFIGURATION_H
#define	PINCONFIGURATION_H

#include <pic16f724.h>

/////////////////////////
// Button Pin Location //
/////////////////////////
#define BUTTON_IN_PORT      PORTD
#define BUTTON_IN_BIT       (1 << 0)

#define BUTTON_LOAD_PORT    PORTD
#define BUTTON_LOAD_BIT     (1 << 1)

#define BUTTON_CLOCK_PORT   PORTD
#define BUTTON_CLOCK_BIT    (1 << 2)

///////////////////////////////
// Button Location in Struct //
///////////////////////////////
typedef enum {
    BUTT_SEQ_16  = 0,
    BUTT_SEQ_15,
    BUTT_SEQ_14,
    BUTT_SEQ_13,
    BUTT_SEQ_12,
    BUTT_SEQ_11,
    BUTT_SEQ_10,
    BUTT_SEQ_9,
    BUTT_SEQ_8,
            
    BUTT_SEQ_7,
    BUTT_SEQ_6,
    BUTT_SEQ_5,
    BUTT_SEQ_4,
    BUTT_SEQ_3,
    BUTT_SEQ_2,
    BUTT_SEQ_1,

    BUTT_CLEAR,
    BUTT_PLAY,
    BUTT_DRUM_6,
    BUTT_DRUM_5,
    BUTT_DRUM_4,
    BUTT_DRUM_3,
    BUTT_DRUM_2,
    BUTT_DRUM_1,

    BUTT_EXTRA_1,
    BUTT_EXTRA_2,
    BUTT_MENU_2,
    BUTT_MENU_1,
    BUTT_FX,
    BUTT_PATT_LEN,
    BUTT_PATT_SEL,
    BUTT_SHIFT
} Buttons_t;

//////////////////////////////
// Rotary Encoders Location //
//////////////////////////////
#define RE_1_A      PORTE & BIT_2  // RE2
#define RE_1_B      PORTC & BIT_0  // RC0

#define RE_2_A      PORTE & BIT_0  // RE0
#define RE_2_B      PORTE & BIT_1  // RE1

#define RE_3_A      PORTA & BIT_3  // RA3
#define RE_3_B      PORTA & BIT_4  // RA4

#define RE_4_A      PORTA & BIT_1  // RA1
#define RE_4_B      PORTA & BIT_2  // RA2

#define RE_5_A      PORTB & BIT_5  // RB5
#define RE_5_B      PORTA & BIT_0  // RA0

#define RE_6_A      PORTB & BIT_3  // RB3
#define RE_6_B      PORTB & BIT_4  // RB4

#define RE_7_A      PORTC & BIT_1  // RC1
#define RE_7_B      PORTC & BIT_2  // RC2

#define RE_8_A      PORTD & BIT_4  // RD4
#define RE_8_B      PORTC & BIT_7  // RC7

#define RE_9_A      PORTD & BIT_5  // RD5
#define RE_9_B      PORTD & BIT_6  // RD6

#define RE_10_A     PORTD & BIT_7  // RD7
#define RE_10_B     PORTB & BIT_0  // RB0

#define RE_11_A     PORTB & BIT_1  // RB1
#define RE_11_B     PORTB & BIT_2  // RB2

/////////////////
// BIT defines //
/////////////////
#define BIT_0   (1 << 0)
#define BIT_1   (1 << 1)
#define BIT_2   (1 << 2)
#define BIT_3   (1 << 3)
#define BIT_4   (1 << 4)
#define BIT_5   (1 << 5)
#define BIT_6   (1 << 6)
#define BIT_7   (1 << 7)

#endif	// PINCONFIGURATION_H

