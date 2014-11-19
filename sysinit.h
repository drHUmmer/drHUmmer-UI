#ifndef SYSINIT_H
#define SYSINIT_H

// Includes
#include <pic16f724.h>
#include "SPI.h"
#include "UART.h"

// CONFIG1
#pragma config FOSC     = INTOSCIO  // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE     = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE    = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE    = ON        // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP       = OFF       // Code Protection bit (Program memory code protection is disabled)
#pragma config BOREN    = ON        // Brown-out Reset Selection bits (BOR enabled)
#pragma config BORV     = 19        // Brown-out Reset Voltage selection bit (Brown-out Reset Voltage (VBOR) set to 1.9 V nominal)
#pragma config PLLEN    = ON        // INTOSC PLLEN Enable Bit (INTOSC Frequency is 16MHz (32x))

// CONFIG2
#pragma config VCAPEN   = RA6       // Voltage Regulator Capacitor Enable bits (VCAP functionality is enabled on RA6)

// Defines
#define INPUT       1
#define OUTPUT      0

// Function Prototypes
void    SysInit             (void);
void    PORTinit            (void);
void    ButtonSettingSetup  (void);

#endif // SYSINIT_H