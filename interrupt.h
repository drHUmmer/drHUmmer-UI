#ifndef INTERRUPT_H
#define	INTERRUPT_H

#include <pic16f724.h>
#include <stdio.h>
#include "UI.h"

// Command list         //
// 111  RESET           
// 000  Button
// 001  Rotary Encoder

#define SPI_COMMAND_SIZE    3                   // bits
#define SPI_ADDR_SIZE       (8 - COMMAND_SIZE)  // bits

#define COMMAND_MASK        0xE0                // 1110 0000
#define ADDR_MASK           0x1F                // 0001 1111

#define COMMAND_RESET       (0b11100000)        // 111
#define COMMAND_BUTT        (0b00000000)        // 000
#define COMMAND_RE          (0b00100000)        // 001

void interrupt MainInterrupt ();

#endif	// INTERRUPT_H

