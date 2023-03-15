/*
 * BUTTON_Test.c
 *
 * Created: 10/29/2022 6:50:43 PM
 *  Author: Shorouk Shehab
 */ 



#include "BUTTON.h"
#include "LED.h"
#include "DIO_interface.h"
#include <util/delay.h>

void BUTTON_TEST ()
{
	
	LED_Init(GPIOC , PIN2);
	Button_Init (GPIOD, PIN2);
	while (1)
	{
		  uint8 button_state ;
		  Button_Read(GPIOD, PIN2, &button_state );
	
		if(	button_state == HIGH)
		{
			LED_ON(GPIOC, PIN2);
		}
		else if ( button_state == LOW)
		{
			
			LED_OFF( GPIOC, PIN2);
			
		}
		
	}
	
}

/*
void main_for_testing_buttons ()
{
	uint8_t button_state ;
	// TESTING Buttons DRIVER ////
	LED_Init (GPIOC,PIN2);
	Button_Init (GPIOD, PIN2);
	while (1)
	{
		
		Button_Read(GPIOD, PIN2, &button_state );
		if (button_state == LOGIC_HIGH)
		{
			LED_ON (GPIOC_ID,PIN2_ID);
		}
		else if (button_state == LOGIC_LOW)
		{
			LED_OFF (GPIOC_ID,PIN2_ID);
		}

	}
}*/