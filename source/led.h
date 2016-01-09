#ifndef __led_H__
#define __led_H__

#include "stm32f746xx.h"
#include "stm32f7xx_hal.h"


void led_port_init(void);

void 		led_port_init(void); 
void 		ledOn(void);
void 		ledOff(void);
void		ledToggle(void);


#endif  //__led_H__
