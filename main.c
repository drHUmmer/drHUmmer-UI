#include "main.h"

int main() {

    SysInit();

//    while (1) {
//        PORTD |= (1<<3);
//        PORTD &= ~(1<<3);
//    }


    while (1) {
        PORTA |= (1<<7);
        updateAllRotaryEnc();
        PORTA &= ~(1<<7);

        PORTD |= 1<<3;
        updateButtons();
        PORTD &= ~(1<<3);
    }

    return 1;
}
