/*
 * INTERRUPT.h
 *
 * Created: 10/29/2022 6:48:57 PM
 *  Author: Shorouk Shehab
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include <avr/io.h>
#include <avr/interrupt.h>
//#include "DIO_interface.h"


/* For INTERRUPT INITIALIZATION 
 * this function takes void and return void 
 * SET global interrupt enable 
 * Choose control sense of interrupt
 * Enable external interrupt 0
*/



void Interrupt0_INIT (void);



#endif /* INTERRUPT_H_ */