#include "UI.h"
#include "pinConfiguration.h"

////////////
// Button //
////////////
void setButtonValue (unsigned char buttonNr, unsigned char value) {
    if (!(buttonNr > 0 && buttonNr <= 8 * NR_OF_BUTTONS_REG)) {
        return;                             // RETURN //
    }
    Button_t* button = &UIinfo.Butt_1;

    button += buttonNr - 1;                 // Jump to correct button address

    // Momentary
    if (button->mode == MOMENTARY) {
        button->value = value;
    }

    // Toggled
    else if (button->mode == TOGGLED) {
        // Rising Edge
        if (button->edge == RISING) {
            if (button->prevVal == 0 && value == 1) {
                button->value |= 1;
            }
        }
        // Falling Edge
        else if (button->edge == FALLING) {
            if (button->prevVal == 1 && value == 0) {
                button->value |= 1;
            }
        }
    }
    button->prevVal = value;

    return;                                     // RETURN //
}

void updateButtons (void) {
    BUTTON_LOAD_PORT |= BUTTON_LOAD_BIT;

    unsigned char counter = 0;
    for (counter = 1; counter <= NR_OF_BUTTONS_REG * 8; counter ++) {
        setButtonValue(counter, !!(BUTTON_IN_PORT & BUTTON_IN_BIT));

        // Clock pulse
        BUTTON_CLOCK_PORT |= BUTTON_CLOCK_BIT;
        BUTTON_CLOCK_PORT &= ~(BUTTON_CLOCK_BIT);
    }

    BUTTON_LOAD_PORT &= ~(BUTTON_LOAD_BIT);
}

unsigned char getButtonRegValue (unsigned char registerNr) {
    if (!(registerNr > 0 && registerNr <= NR_OF_BUTTONS_REG)) {
        return 0;                           // RETURN //
    }

    unsigned char counter       = 0;
    unsigned char returnValue   = 0;
    Button_t* button            = &UIinfo.Butt_1;

    switch (registerNr) {
        case 1: button += 8;    break;
        case 2: button += 0;    break;
        case 3: button += 16;   break;
        case 4: button += 24;   break;
        default:                return 0;   // RETURN //
    }


    for (counter = 0; counter < 8; counter ++) {
        returnValue |= button->value << 7 - counter;
        button ++;
    }

    return returnValue;                     // RETURN //
}

void setButtonMode (unsigned char buttonNr, ButtonMode_t mode) {
    if (buttonNr > 0 && buttonNr <= 8 * NR_OF_BUTTONS_REG) {
        Button_t* button = &UIinfo.Butt_1;
        button += buttonNr - 1;                 // Jump to correct button address

        button->mode = mode;
    }
    
    return;                                     // RETURN //
}

void setButtonEdge (unsigned char buttonNr, Edge_t mode) {
    if (!(buttonNr > 0 && buttonNr <= 8 * NR_OF_BUTTONS_REG)) {
        return;                                 // RETURN //
    }

    Button_t* button = &UIinfo.Butt_1;
    button += buttonNr - 1;                 // Jump to correct button address

    button->edge = mode;
}

void resetButtons (void) {
    unsigned char counter = 0;
    for (counter = 1; counter <= NR_OF_BUTTONS_REG; counter ++) {
        resetButton(counter);
    }
}

void resetButton (unsigned char buttonNr) {
    if (!(buttonNr > 0 && buttonNr <= NR_OF_BUTTONS_REG)) {
        return;                                 // RETURN //
    }
    
    Button_t* button = &UIinfo.Butt_1;
    button += buttonNr - 1;

    button->value   = 0;
    button->prevVal = 0;
}
////////////////////
// Rotary Encoder //
////////////////////
void updateAllRotaryEnc (void) {
    unsigned char counter;

    for (counter = 1; counter <= NR_OF_ROTARYENC; counter ++) {
        updateRotaryEnc(counter);
    }

    return;
}

void updateRotaryEnc (unsigned char REnr) {
    if (!(REnr > 0 && REnr <= NR_OF_ROTARYENC)) {
        // Invalid range
        return;
    }

    RotaryEncoder_t* RE = &UIinfo.RE_1 + REnr - 1;

    unsigned char valA  = 0;
    unsigned char valB  = 0;
    unsigned char prevValA = RE->prevValA;
    unsigned char prevValB = RE->prevValB;

//    valA = RE_1_A;
//    valB = RE_1_B;

    switch (REnr) {
        case 1:
            valA = RE_1_A;
            valB = RE_1_B;
            break;
        case 2:
            valA = RE_2_A;
            valB = RE_2_B;
            break;
        case 3:
            valA = RE_3_A;
            valB = RE_3_B;
            break;
        case 4:
            valA = RE_4_A;
            valB = RE_4_B;
            break;
        case 5:
            valA = RE_5_A;
            valB = RE_5_B;
            break;
        case 6:
            valA = RE_6_A;
            valB = RE_6_B;
            break;
        case 7:
            valA = RE_7_A;
            valB = RE_7_B;
            break;
        case 8:
            valA = RE_8_A;
            valB = RE_8_B;
            break;
        case 9:
            valA = RE_9_A;
            valB = RE_9_B;
            break;
        case 10:
            valA = RE_10_A;
            valB = RE_10_B;
            break;
        case 11:
            valA = RE_11_A;
            valB = RE_11_B;
            break;
    }

    if (!(prevValA) && !(prevValB)) {
        if (valA || valB) {
            if (valA && !(valB)){
                RE->value ++;
            }
            else if (!(valA) && valB) {
                RE->value --;
            }
            // else do nothing
        }
    }

    // Update "previous" values
    RE->prevValA    = valA;
    RE->prevValB    = valB;
}

signed char getREvalue (unsigned char REnr, unsigned char reset) {
    if (!(REnr > 0 && REnr <= NR_OF_ROTARYENC)) {
        // Invalid Range
        return 0;                               // RETURN //
    }
    
    RotaryEncoder_t* RE = &UIinfo.RE_1 + REnr - 1;

    signed char returnValue = RE->value;

    if (reset) {
        RE->value = 0;
    }

    return returnValue;                         // RETURN //
}

void resetREs (void) {
    unsigned char counter = 0;
    RotaryEncoder_t* RE = &UIinfo.RE_1;

    for (counter = 0; counter < NR_OF_ROTARYENC; counter ++) {
        RE->value = 0;
        RE ++;
    }
}