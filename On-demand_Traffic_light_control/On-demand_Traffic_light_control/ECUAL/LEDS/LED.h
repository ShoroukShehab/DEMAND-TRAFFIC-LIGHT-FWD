/*
 * LED.h
 *
 * Created: 10/29/2022 6:51:08 PM
 *  Author: Shorouk Shehab
 */ 


#ifndef LED_H_
#define LED_H_



#include "DIO_interface.h"
//INITIALIZATION
void LED_Init (_enuGPIOx LED_PORT , _enuPINx LED_PIN);

//MAKE LED ON
void LED_ON (_enuGPIOx LED_PORT , _enuPINx LED_PIN);

//MAKE LED OFF
void LED_OFF (_enuGPIOx LED_PORT , _enuPINx LED_PIN);

//TOGGLE LED
void LED_TOGGLE (_enuGPIOx LED_PORT , _enuPINx LED_PIN);



#endif /* LED_H_ */