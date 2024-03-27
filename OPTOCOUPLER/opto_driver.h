#ifndef OPTO_DRIVER_H
#define OPTO_DRIVER_H

#include <stdint.h>

/* Defines *******************************************************************/
#define OPTO1_Pin			GPIO_PIN_7
#define OPTO2_Pin			GPIO_PIN_8
#define OPTO_PORT			GPIOB

#define USERLED_6			GPIO_PIN_4
#define USERLED_7			GPIO_PIN_5 
#define USERLED_PORT	GPIOF


/* Functions *****************************************************************/
void GPIO_Init(void);
void GPIO_DeInit(void);
void EXTI9_5_IRQHandler(void);

#endif
