

#ifndef __button_H__
#define __button_H__

/* includes */
#include "stm32f746xx.h"
#include "stm32f7xx_hal.h"

/* functions */
void 		button_init(void);																	//inicjalizacjia przycisku
void    setButtonIrqFunc(void (*button_callback)(void));		//odczyt stanu

#endif // __button_H__
