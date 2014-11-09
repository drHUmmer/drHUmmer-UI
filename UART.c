#include "UART.h"

void UARTsend (unsigned char data) {
    while (TRMT == 0);  // Wait till previous transfer is complete

    TXREG = data;       // Send data to UART buffer
}