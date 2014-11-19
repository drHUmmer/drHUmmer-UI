#ifndef INTERRUPT_H
#define	INTERRUPT_H

#include <pic16f724.h>
#include "UI.h"

// Command list         //
// 111  RESET           
// 000  Button
// 001  Rotary Encoder

//#define SPI_COMMAND_SIZE    3                   // bits
//#define SPI_ADDR_SIZE       (8 - COMMAND_SIZE)  // bits

#define COMMAND_MASK        0xE0                // 1110 0000
#define ADDR_MASK           0x1F                // 0001 1111

#define DUMMY_DATA              0x00
#define COMMAND_RESET           (0b11100000)    // 111
#define COMMAND_BUTT_GET        (0b00100000)    // 001
#define COMMAND_RE_GET          (0b01000000)    // 010
#define COMMAND_RE_GET_UPDATE   (0b01100000)    // 011
#define COMMAND_BUTT_EDGE       (0b10000000)    // 100
#define COMMAND_BUTT_MODE       (0b10100000)    // 101

void interrupt MainInterrupt (void);
void setButtonEdgeINT   (unsigned char address, Edge_t mode);
void setButtonModeINT   (unsigned char address, ButtonMode_t mode);
void clearInterruptData (void);
void shiftInterruptData (void);

typedef struct {
    unsigned char   data1;
    unsigned char   data2;
    unsigned char   data3;
    unsigned char   data4;
    unsigned char   data5;
    unsigned char   data6;
    unsigned char   data7;
    unsigned char   data8;
    unsigned char   data9;
    unsigned char   data10;
    unsigned char   data11;
    unsigned char   data12;
    unsigned char   data13;
    unsigned char   data14;
    unsigned char   data15;
    unsigned char   data16;
} InterruptData_t;
InterruptData_t InterruptData;

#endif	// INTERRUPT_H

