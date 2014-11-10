#include "UART.h"

void UARTinit() {
    SPBRG   =   416;        // Fosc / ( 4 * (SPBRG + 1) )
                            // Baudrate = (Fosc / (4 * SPBRG)) - 1
    TXEN    =   1;          // Enables transmitter
    SYNC    =   1;          // Synchronous transmission
    ADDEN   =   0;          // In sync. mode, must be set to 0
}

void UARTsend (unsigned char data) {
    while (TRMT == 0);  // Wait till previous transfer is complete

    TXREG = data;       // Send data to UART buffer
}