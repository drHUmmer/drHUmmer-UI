#include "interrupt.h"

static void interrupt MainInterrupt () {
    PORTA |= (1<<7);        // Set debug pin    // DEBUG //
    
    if (SSPIE && SSPIF) {
        unsigned char result            = 0x00;

        static unsigned char counter    = 0x00;
        static unsigned char operation  = 0x00;
        static unsigned char remaining  = 0x00;

        unsigned char rawData   = SPI_DATA_REG;

        unsigned char address   = rawData & ADDR_MASK;
        unsigned char command   = rawData & COMMAND_MASK;

        switch (command) {
            case COMMAND_BUTT_GET :
                operation = COMMAND_BUTT_GET;
                if (address) {
                    remaining   = 1;
                    counter     = address;
                }
                else {
                    remaining   = 4;
                    counter     = 1;
                }
            break;  // 001

            case COMMAND_RE_GET :
                operation = COMMAND_RE_GET;
                if (address) {
                    remaining   = 1;
                    counter     = address;
                }
                else {
                    remaining   = 11;
                    counter     = 1;
                }
                break;  // 010
                
            //case COMMAND_BUTT_EDGE  : command_butt_edge (address);  break;  // 100
            //case COMMAND_BUTT_MODE  : command_butt_mode (address);  break;  // 101
            case COMMAND_RESET      : command_reset     ();         break;  // 111
        }

        if (remaining) {
            switch (operation) {
                case COMMAND_BUTT_GET:
                    result = getButtonRegValue(counter);
                    SPI_DATA_REG = result;
                    counter ++;
                    remaining --;
                    break;
                    
                case COMMAND_RE_GET:
                    result = getREvalue(counter - 1);
                    SPI_DATA_REG = result;
                    counter ++;
                    remaining --;
                    break;
            }
        }
        else {
            SPI_DATA_REG = 0x00;
        }

        UARTsend(SPI_DATA_REG);

    PORTA &= ~(1<<7);           // Clear debug pin    // DEBUG //
    SSPIF   = 0;                // Clear interrupt flag
    }
}
