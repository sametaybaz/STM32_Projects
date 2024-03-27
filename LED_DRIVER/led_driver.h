#ifndef LED_DRIVER_H
#define LED_DRIVER_H

/* Defines *******************************************************************/
#define LED_PORT GPIOF
#define LED_1 GPIO_PIN_2
#define LED_2 GPIO_PIN_3
#define LED_3 GPIO_PIN_4
#define LED_4 GPIO_PIN_5

/* Functions *****************************************************************/
void open(void);
void close(void);
void toggle(void);
void GPIO_Init(void);
void GPIO_DeInit(void);

#endif
