#include "UI.h"
#include "pinConfiguration.h"

///////////////////
// Send commands //
///////////////////
unsigned char UIsendButton(unsigned char address) {
    unsigned char returnValue   = 0;
    unsigned char counter       = 0;
    
    // Check for valid range
    if (address > 0 && address <= NR_OF_BUTTONS_REG) {
        Button_TypeDef* Button = &UIinfo.Butt_1;        // Set address to first button

        switch (address) {
            case 1: Button += 8;    break;              // Select the proper
            case 2: Button += 0;    break;              // memory location
            case 3: Button += 16;   break;              //
            case 4: Button += 24;   break;              //
            default: return 0;                          // RETURN //
        }

        for (counter = 0; counter < 8; counter ++) {
            returnValue    |= (Button->value << 7 - counter);

            if (Button->mode == TOGGLED) {              // Reset button value
                Button->value   = 0;                    // if in TOGGLED mode
            }
            
            Button += 1;                                // Jump to next button
        }

        return returnValue;                             // RETURN //
    }

    else {  // Invalid address given
        return 0;                                       // RETURN //
    }
}

signed char UIsendRotaryEnc (unsigned char address) {
    unsigned char counter       = 0;

    if (address > 0 && address <= NR_OF_ROTARYENC) {
        RotaryEncoder_TypeDef* RE = &UIinfo.RE_1;

        for (counter = 1; counter < address; counter ++) {
            RE += 1;
        }

        return RE->value;                               // RETURN //
    }

    else {  // Invalid address given
        return 0;                                       // RETURN //
    }
}

////////////////////
// Reset commands //
////////////////////
void UIresetButton(void) {
    unsigned char counter = 0;
    Button_TypeDef* Button = &UIinfo.Butt_1;

    for (counter = 0; counter < NR_OF_BUTTONS_REG; counter ++) {
        Button->value   = 0;
    }
}

void UIresetRotaryEnc(void) {
    unsigned char counter = 0;
    RotaryEncoder_TypeDef* RE = &UIinfo.RE_1;

    for (counter = 0; counter < NR_OF_ROTARYENC; counter ++) {
        RE->value   = 0;
    }
}

////////////
// Button //
////////////
void UIgetButtonValues(void) {
    // Enable serial shift
    BUTTON_LOAD_PORT |= BUTTON_LOAD_BIT;

    unsigned char counter = 0;
    for (counter = 0; counter < NR_OF_BUTTONS_REG * 8; counter ++) {
        UIsetButtonValue(counter, !!(BUTTON_IN_PORT & BUTTON_IN_BIT));
    }

    // Enable parallel load
    BUTTON_LOAD_PORT &= BUTTON_LOAD_BIT;
}

void UIsetButtonValue(unsigned char offset, unsigned char val) {
    Button_TypeDef* button = &UIinfo.Butt_1;
    button += offset;
    
    if (button->mode == MOMENTARY) {
        button->value = val;
    }
    else if (button->mode == TOGGLED) {
        if (button->prevVal == 0) {
            button->value |= val;
        }
        button->prevVal = button->value;
    }
}

////////////////////
// Rotary Encoder //
////////////////////
void UIsetRotEncValue(unsigned char offset, signed char val) {
    
}