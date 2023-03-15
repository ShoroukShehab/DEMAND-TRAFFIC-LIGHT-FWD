/*
 * APPLICATION.h
 *
 * Created: 10/30/2022 12:36:08 AM
 *  Author: Shorouk Shehab
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "BUTTON.h"
#include "LED.h"
#include "util/delay.h"


//INITIALIZATIONS
void APP_Init(void);

//BLINKING YELLOW LIGHTS IN THE TWO TRAFIICS
void BLINK_YELLOW (void);

//NORMAL MODE
void APP_START_NORMAL(void);

//PEDESTERIAN MODE
void APP_PED(void);




#endif /* APPLICATION_H_ */