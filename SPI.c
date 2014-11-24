#include "SPI.h"

void SPIinit(void) {
    // SPI Slave Mode
    SMP     =   0;          // Setting must be cleared in Slave Mode

    CKP     =   0;  // CPOL // Idle state for clock is (0 low, 1 high)
    CKE     =   0;  //NCPHA // Data stable on (0 falling, 1 rising) edge

    SSPM0   =   0;          // Synchronous Serial Port Mode
    SSPM1   =   0;          // "0100" = SPI Slave Mode,
    SSPM2   =   1;          // clock = SCK,
    SSPM3   =   0;          // SS pin enabled

    SSPEN   =   1;          // Enables serial port and
                            // configures SCK, SDI and SDO pins
    
    SSPIE   =   1;          // Enable interrupt on data receive

    SPI_DATA_REG = 0x00;    // Clear Data register
}

unsigned char SPItransmit (unsigned char data) {
    unsigned char returnValue = SPI_DATA_REG;
    SPI_DATA_REG = data;
    return returnValue;
}
