#include "uart.h"
#include "hal.h"

volatile uint8_t temp;
volatile char rx;

static void (*uartRE)(char data);

	UART_HandleTypeDef  USART_HandleStruct;



void uart_init(void) 
{

	GPIO_InitTypeDef     GPIO_InitStruct;

	
 
/* Enable GPIO clock */
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
 
// Enable clock for USART1 peripheral
	__HAL_RCC_USART1_CLK_ENABLE();
	

	
/* Configure USART Tx as alternate function */
GPIO_InitStruct.Pin = GPIO_PIN_9;
GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
GPIO_InitStruct.Pull = GPIO_PULLUP;
GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
/* Configure USART Rx as alternate function */
GPIO_InitStruct.Pin = GPIO_PIN_7;
GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
GPIO_InitStruct.Pull = GPIO_PULLUP;
GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);


//Enable RX interrupt
	
		NVIC_SetPriority(USART1_IRQn, 0x00);
		NVIC_EnableIRQ (USART1_IRQn);	


//Handle
		USART_HandleStruct.Instance = USART1;
		USART_HandleStruct.Init.BaudRate = 115200;
		USART_HandleStruct.Init.StopBits = USART_STOPBITS_1;
		USART_HandleStruct.Init.Parity = USART_PARITY_NONE;
		USART_HandleStruct.Init.Mode = USART_MODE_TX_RX;
//Init
HAL_UART_Init(&USART_HandleStruct);
//USART1 enable
__HAL_UART_ENABLE(&USART_HandleStruct);

USART1 -> CR1 |= USART_CR1_RXNEIE;

}
void uartWrite(char data)
{
	//HAL_USART_Transmit(&USART_HandleStruct, DATA, 8, 5);
	while(!(USART1-> ISR & USART_ISR_TXE)); 
	USART1 ->TDR = data;
	//while(!(__HAL_USART_GET_FLAG(&USART_HandleStruct, USART_FLAG_TC)));

}
void setIrqFunc(void (*pFunc)(char data))
{
	if(pFunc)
	{
		uartRE = pFunc;
		
		__HAL_USART_ENABLE_IT(&USART_HandleStruct,USART_IT_RXNE);
		//USART1 ->CR1 |= USART_CR1_RXNEIE;
	}
	else
	{
		__HAL_USART_DISABLE_IT(&USART_HandleStruct,USART_IT_RXNE);
		//USART1 ->CR1 &= ~USART_CR1_RXNEIE;
		
		uartRE = NULL;
	}
}

void USART1_IRQHandler(void)
{		

		if(USART1 -> ISR & USART_FLAG_RXNE){

			rx = USART1 -> RDR;
			uartWriteS("\n\rODEBRANO: ");
			uartWrite(rx);

		}
}

void uartWriteS(char *s)
{
	while(*s)
	{
		while(!(__HAL_USART_GET_FLAG(&USART_HandleStruct, USART_FLAG_TC)));
		uartWrite(*s++);
		
	}
}
