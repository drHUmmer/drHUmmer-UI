#include "sysinit.h"

void SysInit(void) {
    PORTinit();
    SPIinit();
    UARTinit();

    // PLL (switch from 8 MHz to 16 MHz)
    // PLL enabled with CONFIG setting
    IRCF0   =   1;
    IRCF1   =   1;

    // Interrupt
    PEIE    =   1;          // Enable internal interrupts
    GIE     =   1;          // Global interrupt enable
}

void PORTinit(void) {
    SSSEL   =   0;          // CS (RA5)

    // I/O setup
    ANSELA  =   0x00;       // Set as Digital I/O
    ANSA5   =   1;          // SPI CS as analog input (NEEDED FOR SPI)
    TRISA0  =   INPUT;
    TRISA1  =   INPUT;      // RE
    TRISA2  =   INPUT;      // RE
    TRISA3  =   INPUT;      // RE
    TRISA4  =   INPUT;      // RE
    TRISA5  =   INPUT;      // SPI CS
    TRISA7  =   OUTPUT;     // Debug 1

    // Port B
    WPUB    =   0x00;       // Weak pull-up disabled
    IOCB    =   0x00;       // Interrupt on change disabled
    ANSELB  =   0x00;       // Set as Digital I/O
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
    TRISC4  =   INPUT;      // SPI MOSI SDI SDA
    TRISC5  =   OUTPUT;     // SPI MISO SDO
    TRISC6  =   OUTPUT;     // UART TX (DEBUG)
    TRISC7  =   INPUT;      // RE

    // Port D
    CPSON   =   0x00;       // No capacitive touch
    ANSELD  =   0x00;       // Set as Digital I/O
    TRISD0  =   INPUT;      // Button Input
    TRISD1  =   OUTPUT;     // Button Load
    TRISD2  =   OUTPUT;     // Button Clock
    TRISD3  =   OUTPUT;     // Debug 2
    TRISD4  =   INPUT;      // RE
    TRISD5  =   INPUT;      // RE
    TRISD6  =   INPUT;      // RE
    TRISD7  =   INPUT;      // RE

    // Port E
    ANSELE  =   0x00;       // Set as Digital I/O
    TRISE0  =   INPUT;      // RE
    TRISE1  =   INPUT;      // RE
    TRISE2  =   INPUT;      // RE
}
