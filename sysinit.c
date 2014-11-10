#include "sysinit.h"

void SysInit(void) {
    PORTinit();
    SPIinit();
    UARTinit();

    // Interrupt
    PEIE    =   1;          // Enable internal interrupts
    GIE     =   1;          // Global interrupt enable
}

void PORTinit(void) {
    SSSEL   =   0;          // CS (RA5)
//    ANSELA  =

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
    TRISB0  =   INPUT;
    TRISB1  =   INPUT;
    TRISB2  =   INPUT;
    TRISB3  =   INPUT;
    TRISB4  =   INPUT;
    TRISB5  =   INPUT;
    TRISB6  =   INPUT;
    TRISB7  =   INPUT;

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



