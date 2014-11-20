#include "interrupt.h"
#include "SPI.h"
#include "UIinfo.h"
#include "UART.h"

void interrupt MainInterrupt () {
    PORTA |= (1<<7);        // Set debug pin    // DEBUG //

    if (SSPIE && SSPIF) {
        unsigned char transmit  = RingBufferPull(interruptDataBuf_p);
        unsigned char rawData   = 0x40;//SPItransmit(transmit);
        unsigned char address   = rawData & ADDR_MASK;
        unsigned char command   = rawData & COMMAND_MASK;


//        UARTsend(transmit);

        switch (command) {
//            case DUMMY_DATA             :                                   break;  // 000
            case COMMAND_BUTT_GET       : command_butt_get  (address);      break;  // 001
            case COMMAND_RE_GET         : command_re_get    (address);      break;  // 010
            // empty                                                                // 011
            case COMMAND_BUTT_EDGE      : command_butt_edge (address);      break;  // 100
            case COMMAND_BUTT_MODE      : command_butt_mode (address);      break;  // 101
            // empty                                                                // 110
            case COMMAND_RESET          : command_reset     ();             break;  // 111
        }

        if (command != DUMMY_DATA) {
            SPI_DATA_REG = RingBufferPull(interruptDataBuf_p);
//            SPI_DATA_REG = &UIinfo.RE_1 + datcnt;
        }

        SSPIF = 0;                  // Clear interrupt flag
    }
    PORTA &= ~(1<<7);           // Set debug pin    // DEBUG //
}
