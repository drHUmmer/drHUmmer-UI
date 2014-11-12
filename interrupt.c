#include "interrupt.h"
#include "SPI.h"
#include "UIinfo.h"

void interrupt MainInterrupt () {
    if (SSPIE && SSPIF) {
        unsigned char rawData   = SPIget();
        unsigned char address   = rawData & ADDR_MASK;
        unsigned char command   = rawData & COMMAND_MASK;

        switch (command) {
            ///////////
            // RESET //
            ///////////
            case COMMAND_RESET:
//                UIresetButton();
//                UIresetRotaryEnc();
                break;

            ////////////
            // Button //
            ////////////
            case (COMMAND_BUTT):
                if (address == 0) {
//                    unsigned char registerNr;
//                    for (registerNr = 1; registerNr <= NR_OF_BUTTONS_REG; registerNr ++) {
//                        SPIsend(UIsendButton(registerNr));
//                    }
                }
                
                else if (address > 0 && address <= NR_OF_BUTTONS_REG) {
//                    SPIsend(UIsendButton(address));
                }
                break;
                
            ////////////////////
            // Rotary Encoder //
            ////////////////////
            case (COMMAND_RE):
                if (address == 0) {
//                    unsigned char registerNr;
//                    for (registerNr = 1; registerNr <= NR_OF_ROTARYENC; registerNr ++) {
//                        SPIsend(UIsendRotaryEnc(registerNr));
//                    }
                }
                
                else if (address > 0 && address <= NR_OF_ROTARYENC) {
//                    SPIsend(UIsendRotaryEnc(address));
                }
                break;
            default:    break;
        }
        SSPIF = 0;              // Clear interrupt flag
    }    
}

