#include "SPI.h"

void SPIsend (unsigned char data) {
    SSPBUF = data;
}