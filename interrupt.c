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
                resetButtons();
                resetREs();
                break;

            ////////////
            // Button //
            ////////////
            case (COMMAND_BUTT):
                if (address == 0) {
                    unsigned char registerNr = 0;
                    for (registerNr = 1; registerNr <= NR_OF_BUTTONS_REG; registerNr ++) {
                        SPIsend(getButtonRegValue(registerNr));
                    }
                }
                
                else if (address > 0 && address <= NR_OF_BUTTONS_REG) {
                    SPIsend(getButtonRegValue(address));
                }
                break;
                
            ////////////////////
            // Rotary Encoder //
            ////////////////////
            case (COMMAND_RE):
                if (address == 0) {
                    unsigned char status        = 0;
                    unsigned char counter       = 0;

                    for (counter = 1; counter <= NR_OF_ROTARYENC; counter ++) {
                        // If the RE value is not 0, then put 1 in the status byte
//                        if (getREvalue(counter, 0)) {
//                            status |= 1 << (counter - 1);
//                        }

//                        if (counter % 8 == 0) {         // Every 8th time
//                            SPIsend(status);            // Send the status byte
//                            status = 0;
//                        }
                    }

                    // After sending status bytes. Send the data of te REs with value
//                    for (counter = 1; counter <= NR_OF_ROTARYENC; counter ++) {
//                        status = getREvalue(counter, 1);
//                        if (status != 0) {
//                            SPIsend(status);
//                        }
//                    }
                }
                
                else if (address > 0 && address <= NR_OF_ROTARYENC) {
//                    SPIsend(getREvalue(address, 1));
                }
                break;
            default:    break;
        }
        SSPIF = 0;              // Clear interrupt flag
    }    
}

