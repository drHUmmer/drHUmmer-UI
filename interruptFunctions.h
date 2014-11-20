#ifndef INTERRUPTFUNCTIONS_H
#define	INTERRUPTFUNCTIONS_H

#include "interrupt.h"
#include "UART.h"
#include "UIinfo.h"
#include "ringbuffer.h"

void command_butt_edge  (unsigned char address);    // 100
void command_butt_mode  (unsigned char address);    // 101
void command_reset      (void);                     // 111

void setButtonEdgeINT   (unsigned char address, Edge_t mode);
void setButtonModeINT   (unsigned char address, ButtonMode_t mode);

#endif	/* INTERRUPTFUNCTIONS_H */
