/*
 * BUTTON.c
 *
 * Created: 10/29/2022 6:50:07 PM
 *  Author: Shorouk Shehab
 */ 


#include "DIO_private.h"

#include "BUTTON.h"

//INITIALIZATION
void Button_Init(_enuGPIOx  Button_Port ,_enuPINx Button_Pin)
{
	//set it as input
	 DIO_vidSetPinMode(Button_Port , Button_Pin , INPUT);
	
}


//READ BUTTON STATUS
 void Button_Read (_enuGPIOx  Button_Port ,_enuPINx Button_Pin , uint8 * value)
{
	
	 DIO_enuReadPin (Button_Port , Button_Pin, value);
	
	
}
