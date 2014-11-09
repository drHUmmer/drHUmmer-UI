#include "interrupt.h"

void interrupt MainInterrupt () {
    if (SSPIE && SSPIF) {

        // Interrupt stuff

        SSPIF = 0;              // Clear interrupt flag
    }    
}
