/*
 * timer0.c
 *
 * Created: 12/8/2022 12:52:23 PM
 *  Author: Eslam M.Ashour
 */ 
#include "timer1.h"

void TIMER_Init()
{
	// Setting Timer ov interrupt on
	DIO_SET_PIN_VAL(TIMSK,2,1);
	
	// Setting Timer1 to Normal Mode
	DIO_SET_PIN_VAL(TCCR1A,0,0); //WGM10
	DIO_SET_PIN_VAL(TCCR1A,1,0); //WGM11
	DIO_SET_PIN_VAL(TCCR1B,3,0); //WGM12
	DIO_SET_PIN_VAL(TCCR1B,4,0); //WGM13
	
	// Setting Prescaler to 64
	DIO_SET_PIN_VAL(TCCR1B,0,1); //CS10
	DIO_SET_PIN_VAL(TCCR1B,1,1); //CS11
	DIO_SET_PIN_VAL(TCCR1B,2,0); //CS12
	
	TIMER_Reset();
}

void TIMER_Reset()
{
	TCNT1L = 0;
	TCNT1H = 0;
	timerOVFs = 0;
	TCNT1 = 0;
}

ISR(TIMER1_OVF_vect)
{
	timerOVFs+=1;	
}