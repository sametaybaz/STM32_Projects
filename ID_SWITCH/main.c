#include "main.h"
#include "id_switch_driver.h"

/* 
Kulllanim: 

display_seven_segment(id_value) fonksiyonunu while(1) içine yazarak 
imoca board üstünde entegre olan id switch ile switchleri on 
moduna getirerek 7-segment üzerinde ayarlanan id degerleri görülür.

*/

uint8_t id_value = 0;

int main(void)
{

  /* Configure the MPU attributes as Write Through */
  MPU_Config();
	
	/* Initialize the Hardware Abstraction Layer (HAL) */
  HAL_Init();

  /* Configure the System clock to have a frequency of 216 MHz */
  SystemClock_Config();
	
	/* ID Switch and 7-Segment Pins Initialization */
	GPIO_Init();

  /* Infinite loop */
  while (1)
  {
			display_seven_segment(id_value);
  }
}





