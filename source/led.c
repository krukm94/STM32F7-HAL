#include "led.h"

//===============================================================================================================
/* inicjalizacja odpowiedniego portu GPIO */
void led_port_init(void)
{
		GPIO_InitTypeDef    GPIO;
	
	// set RCC for GPIOI
	__HAL_RCC_GPIOI_CLK_ENABLE();				
	// set GPIO pin 
	GPIO.Pin = GPIO_PIN_1;
	// set GPIO mode
	GPIO.Mode = GPIO_MODE_OUTPUT_PP;
	//
	GPIO.Pull = GPIO_PULLUP;
	//
	GPIO.Speed = GPIO_SPEED_FAST;
	
	//gpioi port init 
	HAL_GPIO_Init(GPIOI, &GPIO);
}

//===============================================================================================================
void ledOn( void )
{
	HAL_GPIO_WritePin(GPIOI,GPIO_PIN_1,GPIO_PIN_SET);
}

//===============================================================================================================
void ledOff( void )
{
	HAL_GPIO_WritePin(GPIOI,GPIO_PIN_1,GPIO_PIN_RESET);
}

//===============================================================================================================
void ledToggle( void)
{
	HAL_GPIO_TogglePin(GPIOI,GPIO_PIN_1);
}
