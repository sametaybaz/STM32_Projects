
#include "main.h"
#include "led_driver.h"

/* kullanim : 

open()
close()
toggle()

fonksiyonlari while icine yazilarak led driver kontrolu yapilir.
*/

int main(void)
{

  /* Configure the MPU attributes as Write Through */
  MPU_Config();
	
	/* Initialize the Hardware Abstraction Layer (HAL) */
  HAL_Init();
	
	/* User Led Pins Initialization */
	GPIO_Init();
	
  /* Configure the System clock*/
  SystemClock_Config();

  /* Infinite loop */
  while (1)
  {
		toggle();
		HAL_Delay(300);
  }
}





