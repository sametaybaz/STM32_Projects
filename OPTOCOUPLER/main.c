#include "main.h"
#include "opto_driver.h"

/*
Kullanim: 

Opto1 ile tetik okumasi(interrupt yöntemi ile) yaparak user_led6 
Opto2 ile tetik okumasi(interrupt yöntemi ile) yaparak user_led7 
yanmasi saglandi. 

Kart üzerinde opto1 yada opto2 hangisi tetiklenecekse ona göre 
"select.h" dosyasinda ilgili define'nin önündeki yorum satiri silinmelidir.

*/

int main(void)
{
    /* Configure the MPU attributes as Write Through */
    MPU_Config();

		/* Initialize the Hardware Abstraction Layer (HAL) */
    HAL_Init();

		/* OPTO and USERLED Pins Initialization */
    GPIO_Init();

    /* Configure the System clock*/
    SystemClock_Config();
	
    while (1)
    {
				
    }
}

