/* second project 
	Michal K
*/


/*=============includes============== */
#include "stm32f746xx.h"
#include "stm32f7xx_hal.h"
#include "hal.h"



/*=============variables==============*/

/*=============macros=================*/

/*=============functions==============*/

/*===============main=================*/

int main(void) {
	
			//Wywolanie hala stm
			HAL_Init();				
			//nasz hal
			HAL->Init();
			//test LCD
			
			HAL -> uartWriteS("\n\rSTM32F7 TEST \n\r "); 
		//	lcd_test();
			while(1) {
					
		}
	}
		
		

