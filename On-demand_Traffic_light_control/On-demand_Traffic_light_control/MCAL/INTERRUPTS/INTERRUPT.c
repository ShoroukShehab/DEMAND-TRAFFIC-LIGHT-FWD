/*
 * INTERRUPT.c
 *
 * Created: 10/29/2022 6:48:45 PM
 *  Author: Shorouk Shehab
 */ 






#include "INTERRUPT.h"



void Interrupt0_INIT (void)
{
	// enable global interrupt: by setting bit 7 in SREG to 1 or sei
	sei();
	// Choose the external interrupt sense: Rising edge
	MCUCR |= (1 << ISC00)| (1 << ISC01);

	// enable external interrupt 0: INT0
	GICR |= ( 1 << INT0 );
}

