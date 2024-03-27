#include "main.h"
#include "relay_driver.h"

/* kullanim : 

relay_driver() fonksiyonu while in içine yazilarak imoca board 
üstündeki s1 switch'i ile röle aç , kapa makro fonksiyonlari 
kontrol edilibilir.

*/

int main(void)
{

  /* Configure the MPU attributes as Write Through */
  MPU_Config();
	
	/* Initialize the Hardware Abstraction Layer (HAL) */
  HAL_Init();
	
	/* Relay and Switch Pins Initialization */
	GPIO_Init();
	
  /* Configure the System clock*/
  SystemClock_Config();

  /* Infinite loop */
  while (1)
  {
		
		relay_driver();

  }
}



