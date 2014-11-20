#include "UART.h"

void UARTinit(void) {
    SPBRG   =   17;         // 25 for 9600 @16MHz, with BRGH = 0
    BRGH    =   1;          // High speed

    TXEN    =   1;          // Enables transmitter
    SYNC    =   0;          // Asynchronous transmission
    SPEN    =   1;
}

void UARTsend (unsigned char data) {
    //while (TRMT == 0);  // Wait till previous transfer is complete
    TXREG   =   data;
}