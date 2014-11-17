#include "main.h"

int main() {
    SysInit();

//    setButtonMode(BUTT_SEQ_1, TOGGLED);
    
    while (1) {
        
        PORTD |= (1<<3);        // Set debug pin
        
        updateAllRotaryEnc();   // Read all Rotary encoders
        updateButtons();        // Read all button

        UARTsend(getREvalue(7, 0));
//        UARTsend(RE_7_A | RE_7_B);


        PORTD &= ~(1<<3);       // Clear debug pin
    }

    return 1;
}
