/*
 * BUTTON.h
 *
 * Created: 10/29/2022 6:50:23 PM
 *  Author: Shorouk Shehab
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "DIO_interface.h"

//INITIALIZATION
void Button_Init(_enuGPIOx  Button_Port ,_enuPINx Button_Pin);
//READ BUTTON STATUS
void Button_Read (_enuGPIOx  Button_Port ,_enuPINx Button_Pin , uint8 * value);





#endif /* BUTTON_H_ */