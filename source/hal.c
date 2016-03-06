#include "hal.h"

volatile uint8_t sd_status;


//===============================================================================================================
void halLib_Init(void){
  

	
		SystemClock_Config();				// konfiguracja zegarów
	
		led_port_init();
		//button_init();
	  uart_init(); 
	
	//sd_status =	BSP_SD_Init();
	
}

//===============================================================================================================
const t_halLib halLib ={
	
	/*
   //system
	*/
   halLib_Init,               //void     (*Init)(void);
	/*
   NVIC_SystemReset,          //void     (*mcuRst)(void);
   0,                         //void     (*mcuGetID)(char *id25char);
   timerSetIrqFun,                         //int8_t  (*timerSetIrqFun)(uint8_t nrTim, void (*tim_Irq)(void), uint32_t timeMs, uint32_t priority);
   0, 
   //LCD
   0,                         //void     (*lcdWrite)(uint8_t xPoz, uint8_t yPoz, char *txt);	//void     (*dbgWriteData)(char data);
  */
	
	//UART 
   uart_init,                 //void     (*uart_init)(void);
   uartWrite,                 //void 		 (*uartWrite)(char dana);
	 setIrqFunc,								//void     (*setIrqFunc)(void (*pFunc)(char dana));
	 uartWriteS,								//void 		(*uartWriteS)(char *s);
	
	//button
 
	 button_init,                         //void     (*button_init)(void);
   setButtonIrqFunc,                    //void     (*button_read)(void);
	
   //Diody
   led_port_init,             //void     (*ledWriteData)(uint8_t data);
   ledOn,                     //void     (*ledOn)(uint8_t nrLed);
   ledOff,                    //void     (*ledOff)(uint8_t nrLed);
   ledToggle,                 //void     (*ledToggle)(uint8_t nrLed);
	 /*
   //dyski - kartaSD
   0,                         //int32_t  (*discInit)(uint8_t pdrv);
   0,                         //int32_t  (*discRead)(uint8_t pdrv, uint8_t *buff, uint32_t sector, uint32_t count);
   0,                         //int32_t  (*discWrite)(uint8_t pdrv, uint8_t *buff, uint32_t sector, uint32_t count);
   0,                         //int32_t  (*discIoctl)(uint8_t pdrv, uint8_t ctr, uint8_t *buff);
   0,                         //int32_t  (*sdIoctl)(uint8_t ctrl, uint8_t *buff);
	 //delay systick
	 delay_ms,									//void 		(*delay_ms)(int ms);
	 delay_us,									//void 		(*delay_us)(int us);
	 //accelerometer
	 lis3dsh_init,							//void 		(*accInit)(void);
	 set_OutputDataRate,				//void 		(*accSetDataRate)(lis3dsh_register odr_selection);
	 AxesEnable,								//void 		(*accAxesEnable)(lis3dsh_register axes);
	 ReadAxes,									//void 		(*accReadAxes)(LIS3DSH_OutXYZTypeDef* axes);
 

//terminal
	 tr_cursor_hide,						//void		(*tr_cursor_hide)( uint8_t hide );
	 tr_cls,										//void  	(*tr_cls)(uint8_t cur_onoff);
	 tr_locate,									//void 		(*tr_locate)( uint8_t y, uint8_t x );;-
	 tr_pen_color,							//void 		(*tr_pen_color)( uint8_t cl );
	 tr_brush_color,						//void 		(*tr_brush_color)( uint8_t cl );
	 tr_attr,										//void 		(*tr_attr)( uint8_t atr, uint8_t fg, uint8_t bg );
*/
};
t_halLib *HAL=(t_halLib *)&halLib;

//===============================================================================================================
/**		System Clock Configuration

  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 216000000
  *            HCLK(Hz)                       = 216000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 25
  *            PLL_N                          = 432
  *            PLL_P                          = 2
  *            PLL_Q                          = 9
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 7
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  HAL_StatusTypeDef ret = HAL_OK;

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 432;  
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 9;
  
  ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
  if(ret != HAL_OK)
  {
    while(1);
  }
  
  /* Activate the OverDrive to reach the 216 MHz Frequency */  
  ret = HAL_PWREx_EnableOverDrive();
  if(ret != HAL_OK)
  {
    while(1);
  }
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2; 
  
  ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7);
  if(ret != HAL_OK)
  {
    while(1);
  }  
} // static void SystemClock_Config(void)
