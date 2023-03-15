/*
 * APPLICATION.c
 *
 * Created: 10/30/2022 12:36:22 AM
 *  Author: Shorouk Shehab
 */ 


#include "APPLICATION.h"




Bool YELLOW; 
Bool car_flag_green = 0;
Bool car_flag_red = 0;

void APP_Init()
{
	//GREEN CAR
	LED_Init(GPIOA , PIN0);
	//YELLOW CAR
	LED_Init(GPIOA , PIN1);
	//RED CAR
	LED_Init(GPIOA , PIN2);
	
	//GREEN
	LED_Init(GPIOB , PIN0);
	//YELLOW
	LED_Init(GPIOB , PIN1);
	//RED
	LED_Init(GPIOB , PIN2);
	
	
	Button_Init(GPIOD , PIN2);
	
	Timer0_Init();
	Start_Timer();
	
	Interrupt0_INIT();
	
}

void BLINK_YELLOW ()
{
	YELLOW = 1;
	//YELLOW
	LED_TOGGLE(GPIOB , PIN1);
	LED_TOGGLE(GPIOA , PIN1); 
	
	Timer0_Delay(1000);
	LED_TOGGLE(GPIOA , PIN1);
	LED_TOGGLE(GPIOB , PIN1);
	
	
	Timer0_Delay(1000);
	
	LED_TOGGLE(GPIOB , PIN1);
	LED_TOGGLE(GPIOA , PIN1);
	
	Timer0_Delay(1000);
	
	LED_TOGGLE(GPIOA , PIN1);
	LED_TOGGLE(GPIOB , PIN1);
	
	
	Timer0_Delay(1000);
	LED_TOGGLE(GPIOB , PIN1);
	LED_TOGGLE(GPIOA , PIN1);
	
	
	
	
	Timer0_Delay(1000);

	
	YELLOW = 0;
}


void APP_START_NORMAL()
{ 
	LED_ON(GPIOB,PIN2);
	LED_ON(GPIOA,PIN0);  // GREEN LED FOR CARS
	  // RED LED FOR PEDESTRIANS
	//car_flag_green =1;
	//car_flag_red = 0;
	Timer0_Delay(5000);
	
	// After 5 second  Green led for cars & Red led for ped. switched OFF
	// And yellow LEDs of both will blinking for five second
	
	LED_OFF(GPIOA,PIN0);  // GREEN LED FOR CARS
	LED_OFF(GPIOB,PIN2);  // RED LED FOR PEDESTRIANS
	BLINK_YELLOW ();
	LED_OFF(GPIOA,PIN1);  // YELLOW LED FOR CARS
	LED_OFF(GPIOB,PIN1);  // YELLOW LED FOR PEDESTRIANS
	
	// After yellow blinking for 5 seconds
	// Red led for cars & green led for ped. is on for five seconds
	// then yellow blinking again
	LED_ON(GPIOB,PIN0); 
	LED_ON(GPIOA,PIN2);  // RED LED FOR CARS
	 // GREEN LED FOR PEDESTRIANS
		//car_flag_green =0;
		//car_flag_red = 1;
	Timer0_Delay(5000);
	LED_OFF(GPIOA,PIN2); // RED LED FOR CARS
	LED_OFF(GPIOB,PIN0);  // GREEN LED FOR PEDESTRIANS
	
	BLINK_YELLOW ();
	
	LED_OFF(GPIOA,PIN1);  // YELLOW LED FOR CARS
	LED_OFF(GPIOB,PIN1);  // YELLOW LED FOR PEDESTRIANS
	
}


void APP_PED()
{
	if ( BIT_IS_SET(PINA,PIN2) )  // check if the button is pressed when the cars' RED LED is on
	 {   LED_ON(GPIOB,PIN0);
		 LED_ON(GPIOA,PIN2);  // RED LED FOR CARS
		   // GREEN LED FOR PEDESTRIANS
	   	Timer0_Delay(5000);	   
	 }
	 /*                  SECOND CASE 
	      If BUTTON is pressed when the cars' Green LED is on or the cars' Yellow LED is blinking,
	*/ 
	 else if ( BIT_IS_SET(PINA,PIN0) ||   YELLOW ==1) 
	 {   
  // the pedestrian Red LED will be on 
  
		 LED_ON(GPIOB,PIN2); 
		 LED_OFF(GPIOA,PIN0);  // GREEN LED FOR CARS
		  // RED LED FOR PEDESTRIANS
// then both Yellow LEDs start to blink for five seconds,
	    	BLINK_YELLOW ();
		 LED_OFF(GPIOA,PIN1);  // YELLOW LED FOR CARS
		 LED_OFF(GPIOB,PIN1);  // YELLOW LED FOR PEDESTRIANS
		  LED_OFF(GPIOB,PIN2);  // RED LED FOR PEDESTRIANS
// then the cars' Red LED and pedestrian Green LEDs are on for five seconds,
		LED_ON(GPIOB,PIN0);  
		 LED_ON(GPIOA,PIN2);  // RED LED FOR CARS
		 // GREEN LED FOR PEDESTRIANS
		  Timer0_Delay(5000);
	 }
// 	 -------------->>>>>>> At the end of the two states  <<<<<<------------------

// 	 the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds
// 	 and the pedestrian's Green LED is still on
	  LED_OFF(GPIOA,PIN2);  // RED LED FOR CARS
		BLINK_YELLOW ();
	  LED_OFF(GPIOA,PIN1);  // YELLOW LED FOR CARS
	  LED_OFF(GPIOB,PIN1);  // YELLOW LED FOR PEDESTRIANS
	  
//   After 5 seconds the pedestrian Green LED will be off 
//   and both the pedestrian Red LED and the cars' Green LED will be on.
	  LED_OFF(GPIOB,PIN0);  // GREEN LED FOR PEDESTRIANS
	   LED_ON(GPIOB,PIN2); 
	  LED_ON(GPIOA,PIN0);  // GREEN LED FOR CARS
	  // RED LED FOR PEDESTRIANS
	  Timer0_Delay(5000);
	  LED_OFF(GPIOA,PIN0);  // GREEN LED FOR CARS
	  LED_OFF(GPIOB,PIN2);  // RED LED FOR PEDESTRIANS
	  
}


ISR (INT0_vect)
{
	APP_PED();
	
}


