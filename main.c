#include "main.h"

int main() {
    SysInit();
    ButtonSettingSetup();       // Default button modes
    
    while (1) {
        if (PORTD & (1<<3))
            PORTD &= ~(1<<3);       // Clear debug pin
        else
            PORTD |= (1<<3);        // Set debug pin
        
        updateAllRotaryEnc();   // Read all Rotary encoders
        updateButtons();        // Read all button

//        UARTsend(0xAA);
//        UARTsend(SSPSTAT);
//        UARTsend(SSPCON);

    }

    return 1;
}
