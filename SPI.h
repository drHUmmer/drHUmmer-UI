#ifndef SPI_H
#define	SPI_H

#include <pic16f724.h>

#define SPI_DATA_REG    SSPBUF

// Function prototypes
void            SPIinit (void);
unsigned char SPItransmit (unsigned char data);
//void            SPIsend (unsigned char data);
//unsigned char   SPIget  (void);

#endif	// SPI_H

