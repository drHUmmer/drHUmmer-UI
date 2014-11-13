#include "SPI.h"

void SPIinit(void) {
    // SPI Slave Mode
    SMP     =   0;          // Setting must be cleared in Slave Mode

    CKP     =   0;          // Idle state for clock is LOW
    CKE     =   0;          // Data stable on FALLING EDGE

    SSPM0   =   0;          // Synchronous Serial Port Mode
    SSPM1   =   0;          // "0100" = SPI Slave Mode,
    SSPM2   =   1;          // clock = SCK,
    SSPM3   =   0;          // SS pin enabled

    SSPEN   =   1;          // Enables serial port and
                            // configures SCK, SDI and SDO pins

    SSPIE   =   1;          // Enable interrupt on data receive
}

void SPIsend (unsigned char data) {
    // IMPLENENT:
    // While BF bit is set in SSPSTAT. Wait
    while (BF == 1);
    SPI_DATA_REG    = data;
}

unsigned char SPIget (void) {
    
    return SPI_DATA_REG;
}