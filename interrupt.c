#include "interrupt.h"
#include "SPI.h"
#include "UIinfo.h"
#include "UART.h"

void interrupt MainInterrupt () {
    PORTA |= (1<<7);        // Set debug pin    // DEBUG //

    if (SSPIE && SSPIF) {    
        unsigned char rawData   = SPItransmit(InterruptData.data1);
        unsigned char address   = rawData & ADDR_MASK;
        unsigned char command   = rawData & COMMAND_MASK;

        switch (command) {
            case DUMMY_DATA             : shiftInterruptData();             break;  // 000
            case COMMAND_BUTT_GET       : command_butt_get  (address);      break;  // 001
            case COMMAND_RE_GET         : command_re_get    (address);      break;  // 010
            case COMMAND_RE_GET_UPDATE  : command_re_update ();             break;  // 011
            case COMMAND_BUTT_EDGE      : command_butt_edge (address);      break;  // 100
            case COMMAND_BUTT_MODE      : command_butt_mode (address);      break;  // 101
            // empty                                                                // 110
            case COMMAND_RESET          : command_reset     ();             break;  // 111
        }

        UARTsend(command);

//        BF = 0;
//        SSPOV = 0;
//        SSPIE = 1;
//        WCOL = 0;
//        SSPEN = 1;

        SSPIF = 0;                  // Clear interrupt flag
    }
    PORTA &= ~(1<<7);           // Set debug pin    // DEBUG //
}
