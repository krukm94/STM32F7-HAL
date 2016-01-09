/* incldes */

#include "button.h"

static void (*button)(void);

void button_init(void){
	
		GPIO_InitTypeDef    GPIO;
	
	// set RCC for GPIOI
	__HAL_RCC_GPIOI_CLK_ENABLE();				
	// set GPIO pin 
	GPIO.Pin = GPIO_PIN_11;
	// set GPIO mode
	GPIO.Mode = GPIO_MODE_IT_RISING;
	//rezytor podciagajacy
	GPIO.Pull = GPIO_PULLDOWN;
	//
	GPIO.Speed = GPIO_SPEED_FAST;
	
	//przesyBanie inicjalizacji 
	HAL_GPIO_Init(GPIOI, &GPIO);
}



void setButtonIrqFunc(void (*button_callback)(void))
{
	if(button_callback)
	{
		button = button_callback;
		
		NVIC_SetPriority(EXTI15_10_IRQn, 0x0F);
		NVIC_EnableIRQ(EXTI15_10_IRQn);
	}
}

void EXTI15_10_IRQHandler(void)
{
	__HAL_GPIO_EXTI_CLEAR_FLAG(GPIO_PIN_11);
  button();
}
