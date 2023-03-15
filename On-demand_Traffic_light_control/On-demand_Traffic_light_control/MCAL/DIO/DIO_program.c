/*
 * DIO_program.c
 *
 * Created: 10/29/2022 6:57:10 PM
 *  Author: Shorouk Shehab
 */ 


/* Common Includes */
#include "STD_TYPES.h"
#include "BIT_MATH.h"


/* Driver files Includes */
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"



/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void DIO_vidSetPinMode(_enuGPIOx enuPortNum , _enuPINx enuPinNum , _enuDirectionx enuDirection)
{
	
	switch (enuPortNum)
	{
		case GPIOA:
		if (enuDirection == OUTPUT )
		{
			SET_BIT(DDRA , enuPinNum);
		}
		else
		{
			CLR_BIT (DDRA , enuPinNum);
		}

		break;

		case GPIOB:
		if (enuDirection == OUTPUT)
		{
			SET_BIT(DDRB , enuPinNum);
		}
		else
		{
			CLR_BIT (DDRB , enuPinNum);
		}
		break;


		case GPIOC:
		if (enuDirection == OUTPUT)
		{
			SET_BIT(DDRC , enuPinNum);
		}
		else
		{
			CLR_BIT (DDRC , enuPinNum);
		}
		break;


		case GPIOD:
		if (enuDirection == OUTPUT)
		{
			SET_BIT(DDRD , enuPinNum);
		}
		else
		{
			CLR_BIT (DDRD , enuPinNum);
		}

		break;
	}
}



/*
 * Description :
 * Write the value Logic High or Logic Low on the required pin.
 * If the input port number or pin number are not correct, The function will not handle the request.
 * If the pin is input, this function will enable/disable the internal pull-up resistor.
 */
void DIO_vidWritePin(_enuGPIOx enuPortNum , _enuPINx enuPinNum , _enuLogicalOutput enuOutput)
{
	switch (enuPortNum)
	{
		case GPIOA:
		if (HIGH == enuOutput)
		{
			SET_BIT(PORTA , enuPinNum);
		}
		else
		{
			CLR_BIT (PORTA , enuPinNum);
		}

		break;

		case GPIOB:
		if (HIGH == enuOutput)
		{
			SET_BIT(PORTB , enuPinNum);
		}
		else
		{
			CLR_BIT (PORTB , enuPinNum);
		}
		break;


		case GPIOC:
		if (HIGH == enuOutput)
		{
			SET_BIT(PORTC , enuPinNum);
		}
		else
		{
			CLR_BIT (PORTC , enuPinNum);
		}
		break;


		case GPIOD:
		if (HIGH == enuOutput)
		{
			SET_BIT(PORTD , enuPinNum);
		}
		else
		{
			CLR_BIT (PORTD , enuPinNum);
		}

		break;
	}
}




/*
 * Description :
 * Read and return the value for the required pin, it should be Logic High or Logic Low.
 * If the input port number or pin number are not correct, The function will return Logic Low.
 */
void DIO_enuReadPin (_enuGPIOx enuPortNum , _enuPINx enuPinNum , uint8 *value )
{
//	_enuLogicalOutput enuReturnedLogical;
	switch(enuPortNum)
	{
		case GPIOA:
	if(BIT_IS_SET(PINA, enuPinNum))
	{
		*value=LOGIC_HIGH;
		//return  value	;
	}
	else
	{
		*value= LOGIC_LOW;
		//return value	;
	}
	break;
		case GPIOB:
		if(BIT_IS_SET(PINB, enuPinNum))
		{
			*value=LOGIC_HIGH;
			//	return  value	;
		}
		else
		{
			* value= LOGIC_LOW;
			//return value	;
		}
		break;

		case GPIOC:
		if(BIT_IS_SET(PINC,enuPinNum))
		{
			* value=LOGIC_HIGH;
			//return  value	;
		}
		else
		{
			* value= LOGIC_LOW;
			//return value	;

		}
		break;
		case GPIOD:
		if(BIT_IS_SET(PIND ,enuPinNum))
		{
			* value=LOGIC_HIGH;
			//	return  value	;
		}
		else
		{
			* value= LOGIC_LOW;
			// return value	;

		}
		break;
	}
	//return enuReturnedLogical;
}






void DIO_toggle(_enuGPIOx enuPortNum , _enuPINx enuPinNum)
{
	switch(enuPortNum){
		case GPIOA:
		TOGGLE_BIT(PORTA,enuPinNum);
		break;
		case GPIOB:
		TOGGLE_BIT(PORTB,enuPinNum);
		break;
		case GPIOC:
		TOGGLE_BIT(PORTC,enuPinNum);
		break;
		case GPIOD:
		TOGGLE_BIT(PORTD,enuPinNum);
		break;
	}
}