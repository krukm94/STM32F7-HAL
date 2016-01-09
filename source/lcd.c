
#include "lcd.h"


/* VARIABLES */

/* FUNCTIONS */

void lcd_test(void){
			

	
		/* Powitanie */
			HAL -> uartWriteS("\n\r\n\r\n\r---LCD TEST---\n\r Compilation Time \n\r  -->");
			HAL -> uartWriteS(__TIME__);
			HAL -> uartWriteS("<--\n\r\n\r");
	
	
		/* Inicjalizacja LCD */
			if(BSP_LCD_Init() != 0 ) {
					HAL -> uartWriteS("\n\rInit FAILED\n\r");
			}
					else{
								/* LCD Initialization */ 
								BSP_LCD_LayerDefaultInit(0, LCD_FB_START_ADDRESS);
								BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS+(BSP_LCD_GetXSize()*BSP_LCD_GetYSize()*4));
						
								/* Enable the LCD */ 
								BSP_LCD_DisplayOn(); 
								
								/* Select the LCD Background Layer  */
								BSP_LCD_SelectLayer(0);

								/* Clear the Background Layer */ 
								BSP_LCD_Clear(LCD_COLOR_BLACK);  
								
								/* Select the LCD Foreground Layer  */
								BSP_LCD_SelectLayer(1);

								/* Clear the Foreground Layer */ 
								BSP_LCD_Clear(LCD_COLOR_GREEN);
								
								/* Configure the transparency for foreground and background :
									 Increase the transparency */
								BSP_LCD_SetTransparency(0, 0);			//przezroczystosc pierwszego planu
								BSP_LCD_SetTransparency(1, 100);		//przezroczystosc drugiego planu

							}
														
												//		BSP_LCD_Clear(LCD_COLOR_RED);		//czysci wszystko i zmienie kolor
														BSP_LCD_Clear(LCD_COLOR_TRANSPARENT);
														BSP_LCD_SetBackColor(LCD_COLOR_BLACK);	//kolor ramki pod tekstem
										        BSP_LCD_SetTextColor(LCD_COLOR_WHITE);	//kolor napisow
														/* wyswietlanie stringow 
														mozna to tez robic funkcja BSP_LCD_DisplayStringAtLine */
														BSP_LCD_DisplayStringAt(0,130, (uint8_t*)"ELO*",CENTER_MODE);
													//	BSP_LCD_DisplayStringAt(0,50,(uint8_t*)"MK",CENTER_MODE);
														
														
												//		BSP_LCD_DisplayStringAt(0,20,(uint8_t*)"ELO",RIGHT_MODE);
							
												//		BSP_LCD_DisplayChar(20,40,69);
												/*		BSP_LCD_ClearStringLine(0);  //czysci cala linie ( nie jeden wiersz pixeli ale cala linie ) */
														
														
							
														//BSP_LCD_DrawHLine(60,60,10);	// rysuje linie 
							
													//	BSP_LCD_DrawRect(100,100,100,100);
														
													//	BSP_LCD_DrawCircle(200,200,50);
														
													//	BSP_LCD_FillRect(400,200,50,50);

													while(1){
																	BSP_LCD_Clear(LCD_COLOR_GREEN);
																	BSP_LCD_DisplayStringAt(0,130, (uint8_t*)"USZANOWANKO",CENTER_MODE);
																	HAL_Delay(1000);
																	BSP_LCD_Clear(LCD_COLOR_BLUE);
																	BSP_LCD_DisplayStringAt(0,130, (uint8_t*)"USZANOWANKO",CENTER_MODE);
																	HAL_Delay(1000);
																	BSP_LCD_Clear(LCD_COLOR_RED);
																	BSP_LCD_DisplayStringAt(0,130, (uint8_t*)"USZANOWANKO",CENTER_MODE);
																	HAL_Delay(1000);
																	BSP_LCD_Clear(LCD_COLOR_YELLOW);
																	BSP_LCD_DisplayStringAt(0,130, (uint8_t*)"USZANOWANKO",CENTER_MODE);
																	HAL_Delay(1000);
																	BSP_LCD_Clear(LCD_COLOR_CYAN);
																	BSP_LCD_DisplayStringAt(0,130, (uint8_t*)"USZANOWANKO",CENTER_MODE);
																	HAL_Delay(1000);
																	BSP_LCD_DisplayStringAt(0,130, (uint8_t*)"USZANOWANKO",CENTER_MODE);
																	BSP_LCD_Clear(LCD_COLOR_MAGENTA);
																	BSP_LCD_DisplayStringAt(0,130, (uint8_t*)"USZANOWANKO",CENTER_MODE);
																	HAL_Delay(1000);
																	BSP_LCD_Clear(LCD_COLOR_BROWN);
																	BSP_LCD_DisplayStringAt(0,130, (uint8_t*)"USZANOWANKO",CENTER_MODE);
																	HAL_Delay(1000);
																	BSP_LCD_Clear(LCD_COLOR_ORANGE);
																	BSP_LCD_DisplayStringAt(0,130, (uint8_t*)"USZANOWANKO",CENTER_MODE);
																	HAL_Delay(1000);
																	BSP_LCD_Clear(LCD_COLOR_TRANSPARENT);
																	BSP_LCD_DisplayStringAt(0,130, (uint8_t*)"USZANOWANKO",CENTER_MODE);
																	HAL_Delay(1000);
																	BSP_LCD_Clear(LCD_COLOR_LIGHTBLUE);
																	BSP_LCD_DisplayStringAt(0,130, (uint8_t*)"USZANOWANKO",CENTER_MODE);
																	HAL_Delay(1000);
																	BSP_LCD_Clear(LCD_COLOR_LIGHTRED);
																	BSP_LCD_DisplayStringAt(0,130, (uint8_t*)"USZANOWANKO",CENTER_MODE);
																	HAL_Delay(1000);
																	BSP_LCD_Clear(LCD_COLOR_LIGHTYELLOW);
																	BSP_LCD_DisplayStringAt(0,130, (uint8_t*)"USZANOWANKO",CENTER_MODE);
																	HAL_Delay(1000);

					}									
}
