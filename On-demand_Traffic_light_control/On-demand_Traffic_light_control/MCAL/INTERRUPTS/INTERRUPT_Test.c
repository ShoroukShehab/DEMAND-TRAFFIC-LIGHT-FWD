/*
 * INTERRUPT_Test.c
 *
 * Created: 10/29/2022 10:20:35 PM
 *  Author: Shorouk Shehab
 */ 
/*
#include "INTERRUPT.h"
#include "LED.h"
#include "BUTTON.h"
#include "TIMER.h"


void INTERRUPT_TEST ()
{
	LED_Init(GPIOC , PIN2);
	Button_Init(GPIOD , PIN2);
	Timer0_Init();
	
	
	
	LED_ON(GPIOC , PIN2);
	Timer0_Delay(5000);
	
	Interrupt0_INIT();
	LED_OFF(GPIOC,PIN2);
}*/



#include "BUTTON.h"
#include "LED.h"
#include "INTERRUPT.h"
#include "DIO_interface.h"
#include "util/delay.h"
void main_for_testing_interrupts ()
{

	LED_Init (GPIOC,PIN2);
	Button_Init(GPIOD, PIN2);
	//Button_Read(GPIOD , PIN2) == LOW;
	Interrupt0_INIT ();
	LED_ON (GPIOC,PIN2);
	



}
