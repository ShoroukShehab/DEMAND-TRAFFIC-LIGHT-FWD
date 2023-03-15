/*
 * LED.c
 *
 * Created: 10/29/2022 6:50:56 PM
 *  Author: Shorouk Shehab
 */ 




#include "LED.h"

void LED_Init (_enuGPIOx LED_PORT , _enuPINx LED_PIN)
{
	//MAKE LED OUTPUT
	 DIO_vidSetPinMode(LED_PORT , LED_PIN , OUTPUT);

}




void LED_ON (_enuGPIOx LED_PORT , _enuPINx LED_PIN)
{
	//MAKE LED HIGH
	 DIO_vidWritePin(LED_PORT, LED_PIN , HIGH);


}

void LED_OFF (_enuGPIOx LED_PORT , _enuPINx LED_PIN)
{
	//MAKE LED LOW
	 DIO_vidWritePin(LED_PORT, LED_PIN , LOW);
}


void LED_TOGGLE (_enuGPIOx LED_PORT , _enuPINx LED_PIN)
{
	//TOGGLE LED
	 DIO_toggle(LED_PORT ,LED_PIN);
 
}




