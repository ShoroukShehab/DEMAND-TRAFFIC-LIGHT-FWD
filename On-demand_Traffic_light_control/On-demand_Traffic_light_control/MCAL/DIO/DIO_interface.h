/*
 * DIO_interface.h
 *
 * Created: 10/29/2022 6:55:52 PM
 *  Author: Shorouk Shehab
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/* Common Includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_private.h"


typedef enum
{
	GPIOA = 0,
	GPIOB,
	GPIOC,
	GPIOD
}_enuGPIOx;


typedef enum
{
	PIN0 = 0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}_enuPINx;


typedef enum
{
	INPUT = 0,
	OUTPUT
}_enuDirectionx;


typedef enum
{
	LOW = 0,
	HIGH
}_enuLogicalOutput;


void DIO_vidSetPinMode(_enuGPIOx enuPortNum , _enuPINx enuPinNum , _enuDirectionx enuDirection);
void DIO_vidWritePin(_enuGPIOx enuPortNum , _enuPINx enuPinNum , _enuLogicalOutput enuOutput);
void DIO_enuReadPin (_enuGPIOx enuPortNum , _enuPINx enuPinNum , uint8 *value );
 void DIO_toggle(_enuGPIOx enuPortNum , _enuPINx enuPinNum);





#endif /* DIO_INTERFACE_H_ */