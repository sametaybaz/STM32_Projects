#include "main.h"
#include "relay_driver.h"

/********** Control the Relay Based on the Switch State **********/
void relay_driver(void)
{			
			/* If the switch is pressed, open the relay */
			if (READ_SWITCH == GPIO_PIN_SET)
				RELAY_OPEN;
			/* If the switch is not pressed, close the relay */
			else if (READ_SWITCH == GPIO_PIN_RESET)
				RELAY_CLOSE;
}
