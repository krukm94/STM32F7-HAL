


/* includes */ 
#include "sd_card.h"

/* FatFs includes component */
#include "ff_gen_drv.h"
#include "sd_diskio.h"

/*variables*/

FATFS SDFatFs;  /* File system object for SD card logical drive */
FIL MyFile;     /* File object */
char SDPath[4]; /* SD card logical drive path */

volatile 	uint8_t linkdriver;
volatile FRESULT res;

/* functions ------------------------------------------------------------------------*/
void fatFS_test(void){

                                          /* FatFs function common result code */
  uint32_t byteswritten, bytesread;                     /* File write/read counts */
  uint8_t wtext[] = "DUPY DUPY dupa"; /* File write buffer */
  uint8_t rtext[100];                                   /* File read buffer */
	

	
			HAL -> uartWriteS("\n\r\n\rSTM32F7 fatFS test\n\r  Compilation Time\n\r  --> ");
			HAL -> uartWriteS(__TIME__);
			HAL -> uartWriteS(" <--\n\r");
//=========================================================================	
		
		/* inicjalizuje karte SD i automatycznie inkrementuje liczbe aktywnych dysków */
		FATFS_LinkDriver(&SD_Driver, SDPath);
		
		if (f_mount(&SDFatFs, (TCHAR const*)SDPath, 0) != 0){
		HAL -> uartWriteS("Initialization FAILED\n\r");
		}
		else{	
			
				if(f_open(&MyFile, "DUPA.TXT", FA_CREATE_ALWAYS | FA_WRITE) != 0){
					res = f_open(&MyFile, "DUPA.TXT", FA_CREATE_ALWAYS | FA_WRITE);
					HAL -> uartWriteS("OPEN1 FAILED ");
				}
					else{
							if(f_write(&MyFile, wtext, sizeof(wtext), (void *)&byteswritten) != 0 ){
								HAL -> uartWriteS("WRITE FAILED\n\r");
							}
							else{
										f_close(&MyFile);
										f_open(&MyFile, "DUPA.TXT", FA_READ) ;

										if (f_read(&MyFile, rtext, sizeof(rtext), (UINT*)&bytesread) != 0 ){
										HAL -> uartWriteS("OPEN FAILED\n\r");
										}
										else{
												HAL -> uartWriteS("POSZLO\n\r");
											//	HAL -> ledOn();
												}
									}
						}
					}
		FATFS_UnLinkDriver(SDPath);
		HAL_Delay(100);
	
}


