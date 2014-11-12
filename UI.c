#include "UI.h"
#include "pinConfiguration.h"

////////////
// Button //
////////////
void setButtonValue (unsigned char buttonNr, unsigned char value) {
    if (buttonNr > 0 && buttonNr <= 8 * NR_OF_BUTTONS_REG) {
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
    }

    // Invalid buttonNr
    return;                                     // RETURN //
}

void updateButtons () {
    BUTTON_LOAD_PORT |= BUTTON_LOAD_BIT;

    Button_t* button = &UIinfo.Butt_1;

    unsigned char counter = 0;
    for (counter = 1; counter <= NR_OF_BUTTONS_REG * 8; counter ++) {
        setButtonValue(counter, !!(BUTTON_IN_PORT & BUTTON_IN_BIT));

        // Clock pulse
        BUTTON_CLOCK_PORT |= BUTTON_CLOCK_BIT;
        BUTTON_CLOCK_PORT &= BUTTON_CLOCK_BIT;
    }

    BUTTON_LOAD_PORT &= BUTTON_LOAD_BIT;
}

unsigned char getButtonRegValue (unsigned char registerNr) {
    if (registerNr > 0 && registerNr <= NR_OF_BUTTONS_REG) {
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

    return 0;                                   // RETURN //
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
    if (buttonNr > 0 && buttonNr <= 8 * NR_OF_BUTTONS_REG) {
        Button_t* button = &UIinfo.Butt_1;
        button += buttonNr - 1;                 // Jump to correct button address

        button->edge = mode;
    }

    return;                                     // RETURN //
}

////////////////////
// Rotary Encoder //
////////////////////
void updateRotaryEnc (unsigned char REnr) {
    
}

signed char getREvalue (unsigned char REnr, unsigned char reset) {

}

void resetRE (unsigned char REnr) {

}

void resetREs (void) {

}