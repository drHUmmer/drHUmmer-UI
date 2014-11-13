#include "main.h"

int main() {

    SysInit();

    while (69) {
        PORTD |= 1<<3;

        updateAllRotaryEnc();
        updateButtons();

        PORTD &= 1<<3;
    }

    return 1;
}
