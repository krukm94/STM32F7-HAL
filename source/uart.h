

#ifndef __uart_H__
#define __uart_H__

#include <string.h>
#include "stm32f746xx.h"
#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_gpio.h"



#define APB1_CLK   42000000
#define BAUDRATE   115200

void uart_init(void);
void uartWrite(char dana);
void setIrqFunc(void (*pFunc)(char data));
void uartWriteS(char *s);

#endif // __uart_H__

