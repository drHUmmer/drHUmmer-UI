#include "init.h"

void init() {
    PORTinit();
    SPIinit();
    UARTinit();

    // Interrupt
    PEIE    =   1;          // Enable internal interrupts
    GIE     =   1;          // Global interrupt enable
}

void PORTinit() {
    SSSEL   =   0;          // CS (RA5)
    ANSELA  =

    // I/O setup
    TRISA0  =   INPUT;
    TRISA1  =   INPUT;      // RE
    TRISA2  =   INPUT;      // RE
    TRISA3  =   INPUT;      // RE
    TRISA4  =   INPUT;      // RE
    TRISA5  =   INPUT;      // RE
    TRISA7  =   OUTPUT;     // N.C.

    // Port B
    WPUB    =   0x00;       // Weak pull-up disabled
    IOCB    =   0x00;       // Interrupt on change disabled
    TRISB   =   ALL_INPUT;  // RE

    // Port C
    TRISC0  =   INPUT;      // RE
    TRISC1  =   INPUT;      // RE
    TRISC2  =   INPUT;      // RE
    TRISC3  =   INPUT;      // SPI Clock
    TRISC4  =   INPUT;      // SPI MOSI
    TRISC5  =   OUTPUT;     // SPI MISO
    TRISC6  =   OUTPUT;     // UART TX (DEBUG)
    TRISC7  =   INPUT;      // RE

    // Port D
    TRISD0  =   INPUT;      // Button Input
    TRISD1  =   OUTPUT;     // Button Load
    TRISD2  =   OUTPUT;     // Button Clock
    TRISD3  =   OUTPUT;     // N.C.
    TRISD4  =   INPUT;      // RE
    TRISD5  =   INPUT;      // RE
    TRISD6  =   INPUT;      // RE
    TRISD7  =   INPUT;      // RE

    // Port E
    TRISE0  =   INPUT;      // RE
    TRISE1  =   INPUT;      // RE
    TRISE2  =   INPUT;      // RE
}

void UARTinit() {
    SPBRG   =   416;        // Fosc / ( 4 * (SPBRG + 1) )
                            // Baudrate = (Fosc / (4 * SPBRG)) - 1
    TXEN    =   1;          // Enables transmitter
    SYNC    =   1;          // Synchronous transmission
    ADDEN   =   0;          // In sync. mode, must be set to 0
}

void SPIinit() {
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
