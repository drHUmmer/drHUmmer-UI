#ifndef UI_H
#define	UI_H

#include <pic16f724.h>
#include "UIinfo.h"
#include "pinConfiguration.h"

#define NR_OF_BUTTONS_REG   4
#define NR_OF_ROTARYENC     11

unsigned char   UIsendButton        (unsigned char address);
signed char     UIsendRotaryEnc     (unsigned char address);

// Reset
void            UIresetButton       (void);
void            UIresetRotaryEnc    (void);

// Button
void            UIgetButtonValues   (void);
void            UIsetButtonValue    (unsigned char offset, unsigned char val);

// Rotary Encoder
void            UIgetRotEncValue    (unsigned char number);
void            UIsetRotEncValue    (unsigned char offset, signed char val);

#endif	// UI_H

