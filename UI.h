#ifndef UI_H
#define	UI_H

#include <pic16f724.h>
#include "UIinfo.h"
#include "pinConfiguration.h"

#define NR_OF_BUTTONS_REG   4
#define NR_OF_ROTARYENC     11

////////////
// Button //
////////////
void            updateButtons       (void);
unsigned char   getButtonRegValue   (unsigned char registerNr, unsigned char reset);
void            setButtonValue      (Buttons_t buttonNr, unsigned char value);
void            setButtonMode       (Buttons_t buttonNr, ButtonMode_t mode);
void            setButtonEdge       (Buttons_t buttonNr, Edge_t edgeMode);
void            resetButton         (Buttons_t buttonNr);
void            resetButtons        (void);

////////////////////
// Rotary Encoder //
////////////////////
void            updateAllRotaryEnc  (void);
void            updateRotaryEnc     (unsigned char REnr);
signed char     getREvalue          (unsigned char REnr, unsigned char reset);
void            resetREs            (void);

#endif	// UI_H