#ifndef INTERRUPTFUNCTIONS_H
#define	INTERRUPTFUNCTIONS_H

#include "interrupt.h"
#include "UART.h"
#include "UIinfo.h"
#include "ringbuffer.h"

void command_butt_get   (unsigned char address);    // 001
void command_re_get     (unsigned char address);    // 010
// empty                                            // 011
void command_butt_edge  (unsigned char address);    // 100
void command_butt_mode  (unsigned char address);    // 101
// empty                                            // 110
void command_reset      (void);                     // 111

void setButtonEdgeINT   (unsigned char address, Edge_t mode);
void setButtonModeINT   (unsigned char address, ButtonMode_t mode);
//void clearInterruptData (void);
//void shiftInterruptData (void);

#endif	/* INTERRUPTFUNCTIONS_H */
