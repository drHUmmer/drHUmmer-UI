#include "main.h"

int main() {
    SysInit();
    ButtonSettingSetup();       // Default button modes
    
    while (1) {
        PORTD |= (1<<3);        // Set debug pin
        
        updateAllRotaryEnc();   // Read all Rotary encoders
        updateButtons();        // Read all button

        PORTD &= ~(1<<3);       // Clear debug pin
    }

    return 1;
}
