/*
 * DIO_private.h
 *
 * Created: 10/29/2022 6:56:07 PM
 *  Author: Shorouk Shehab
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/*For PORT A*/
#define DDRA     (*((volatile uint8 *)0x3A))
#define PORTA    (*((volatile uint8 *)0x3B))
#define PINA     (*((volatile uint8 *)0x39))


/*For PORT B*/
#define DDRB     (*((volatile uint8 *)0x37))
#define PORTB    (*((volatile uint8 *)0x38))
#define PINB     (*((volatile uint8 *)0x36))


/*For PORT C*/
#define DDRC     (*((volatile uint8 *)0x34))
#define PORTC    (*((volatile uint8 *)0x35))
#define PINC     (*((volatile uint8 *)0x33))


/*For PORT D*/
#define DDRD    (*((volatile uint8 *)0x31))
#define PORTD   (*((volatile uint8 *)0x32))
#define PIND    (*((volatile uint8 *)0x30))




#endif /* DIO_PRIVATE_H_ */