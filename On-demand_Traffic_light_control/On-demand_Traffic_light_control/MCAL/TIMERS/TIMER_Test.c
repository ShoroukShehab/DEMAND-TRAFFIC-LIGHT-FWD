/*
 * TIMER_Test.c
 *
 * Created: 10/29/2022 7:09:28 PM
 *  Author: Shorouk Shehab
 */ 




#include "TIMER.h"
#include "LED.h"
//#include "DIO_interface.h"
void TIMER_TEST (void)
{
	LED_Init( GPIOC , PIN2);
	Timer0_Init();
	
	while (1)
	{
		Start_Timer();
		LED_ON(GPIOC, PIN2);
		Timer0_Delay(5000);
		LED_OFF(GPIOC , PIN2);
		Timer0_Delay(5000);
	}
}
