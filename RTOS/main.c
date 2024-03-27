/*----------------------------------------------------------------------------
 * CMSIS-RTOS 'main' function template
 *---------------------------------------------------------------------------*/
 
#include "RTE_Components.h"
#include  CMSIS_device_header
#include "cmsis_os2.h"
#include "main.h"
#include "led_driver.h"
#include "relay_driver.h"

#define APP_MAIN_STK_SZ (1024U)

static uint8_t						oneshot_trigger = 0;
static uint8_t						counter = 0;
static osTimerId_t				timerId;
static osTimerId_t				oneshot_timer_id;
static osThreadId_t				periodic_id;
static osThreadId_t				oneshot_id;
static osEventFlagsId_t		oneshot_event_id;
static osEventFlagsId_t		oneshot_event_id;

void oneshot_timer_callback(void *argument);

void oneshot(void *arg);
void timerCallback(void *arg);
void periodic(void *arg);


static const osTimerAttr_t timerAttr = {
	.name = "Periodic Timer"
};

static const osTimerAttr_t timerAttr_2 = {
	.name = "Oneshot Timer"
};


uint64_t app_main_stk[APP_MAIN_STK_SZ / 8];

const osThreadAttr_t app_main_attr = 
{
  .stack_mem  = &app_main_stk[0],
  .stack_size = sizeof(app_main_stk)
};
 

void timerCallback(void *arg)
{	
	(void)arg;
	counter++;
}

void __NO_RETURN periodic(void *arg)
{
	(void)arg;
	
	timerId = osTimerNew(timerCallback,osTimerPeriodic,NULL,&timerAttr);
	
	osTimerStart(timerId,1000);
	
	while (1)
	{
		HAL_GPIO_TogglePin(LED_PORT, LED_1);
		osDelay(100);
	}
	
}

void __NO_RETURN oneshot(void *arg)
{
    (void)arg;
		
    for (;;)
    {
       osEventFlagsWait(oneshot_event_id, 1, osFlagsWaitAny, osWaitForever);
        if (oneshot_trigger == 1)
        {
						osTimerStart(oneshot_timer_id, 10000);
						oneshot_trigger = 0;
        } 
				
    }
	
}

void oneshot_timer_callback(void *argument)
{
    (void)argument;
		osThreadSuspend(periodic_id);
    RELAY_OPEN;
		// osThreadResume(periodic_id);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == ID_SWITCH1)
    {		
				
			
				if (READ_SWITCH == GPIO_PIN_SET)
				{ 
					oneshot_trigger = 1;
					osEventFlagsSet(oneshot_event_id, 1);
				}
				

    }
}

void EXTI1_IRQHandler(void)
{	
  HAL_GPIO_EXTI_IRQHandler(ID_SWITCH1);
}

/*----------------------------------------------------------------------------
 * Application main thread
 *---------------------------------------------------------------------------*/
__NO_RETURN void app_main (void *argument) {
  (void)argument;
	
	periodic_id = osThreadNew(periodic,NULL,NULL);
	oneshot_id = osThreadNew(oneshot,NULL,NULL);
	
  for (;;) {}
}
 
int main (void) {
 
  // System Initialization
  SystemCoreClockUpdate();
  
	HAL_Init();
	GPIO_Init();
	HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI1_IRQn);
	
  osKernelInitialize();                 					// Initialize CMSIS-RTOS 
	
	oneshot_event_id = osEventFlagsNew(NULL);   
	oneshot_timer_id = osTimerNew(oneshot_timer_callback, osTimerOnce, NULL, &timerAttr_2);
	
	osThreadNew(app_main, NULL, &app_main_attr);    // Create application main thread
	osKernelStart();                      // Start thread execution
  
	for (;;) {}
}
