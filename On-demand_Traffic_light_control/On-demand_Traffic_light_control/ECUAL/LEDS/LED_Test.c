/*
 * LED_Test.c
 *
 * Created: 10/29/2022 6:51:22 PM
 *  Author: Shorouk Shehab
 */ 




#include "LED.h"

 #include "util/delay.h"




void LED_TEST ()
{
	// TESTING LEDS DRIVER ////
	
	LED_Init (GPIOC,PIN2);
	while (1)
	{
		LED_ON (GPIOC,PIN2);
		_delay_ms (5000);
		LED_OFF (GPIOC,PIN2);
		_delay_ms (5000);
		//LED_TOGGLE (GPIOC,PIN2);
		
	}
}