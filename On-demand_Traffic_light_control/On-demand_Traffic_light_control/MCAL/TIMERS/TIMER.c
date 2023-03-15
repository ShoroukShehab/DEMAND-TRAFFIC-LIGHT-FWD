/*
 * TIMER.c
 *
 * Created: 10/29/2022 6:49:43 PM
 *  Author: Shorouk Shehab
 */ 




#include "TIMER.h"
#include <math.h>
#include <avr/io.h>



void Timer0_Init(void)
{
	//Choosing the normal mode
	TCCR0 |= 0x00;
	//Setting the initial value
	TCNT0 |= 0x00;
	
}

void Start_Timer(void)
{
	
	// Setting prescaler 1024
	TCCR0 |= (1 << CS00) | (1<< CS02);
}








void Timer0_Delay(int time_delay)
{
	unsigned int Overflow_Counter = 0;
	unsigned int Number_of_Overflows;
	double T_MaxDelay , T_Tick;
	int Timer_InitialValue;
	// at Frequency 1MHZ & prescaler 1024
	//T_tick= prescaler/ CPU frequency
	T_Tick = 1024/1000;
	
	// Tmaxdelay = Ttick * 2^n -> 8-bit timer
	T_MaxDelay = T_Tick * 256;
	
	
	// FIRST CASE
	if(time_delay < T_MaxDelay)
	{
		Timer_InitialValue = (T_MaxDelay - time_delay)/T_Tick;
		Number_of_Overflows = 1;
	}
	
	
	// SECOND CASE
	else if (time_delay == (int)T_MaxDelay)
	{
		Timer_InitialValue =0;
		Number_of_Overflows = 1;
	}
	
	
	
	// THIRD CASE
	else if (time_delay > T_MaxDelay)
	{
		Number_of_Overflows = ceil ((double)time_delay/T_MaxDelay);
		Timer_InitialValue = 256 - ((double) time_delay / T_Tick)/Number_of_Overflows;
	}
	
	
	
	
	// WAITING FOR OVERFLOW FLAG
	while (Overflow_Counter < Number_of_Overflows)
	{
		while (( TIFR & (1<<0) )==0 )
		{
			//	 wait for the flag
		}
		//clear the overflow flag
		TIFR |= (1<<0);
		Overflow_Counter++;
	}
	Overflow_Counter =0;
}





