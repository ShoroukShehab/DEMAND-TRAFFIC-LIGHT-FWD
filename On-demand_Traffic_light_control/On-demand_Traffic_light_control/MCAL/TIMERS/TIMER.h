/*
 * TIMER.h
 *
 * Created: 10/29/2022 6:49:06 PM
 *  Author: Shorouk Shehab
 */ 


#ifndef TIMER_H_
#define TIMER_H_



#include "DIO_interface.h"

/*Description:
Choosing the normal mode
Setting the initial value
Setting prescaler 1024
*/

void Timer0_Init(void);


/*Description: start timer  */
void Start_Timer(void);


/*Description: this function takes the time needed for delay in ms and return void  */
void Timer0_Delay(int time_delay);





#endif /* TIMER_H_ */