/*
 * timer0.c
 *
 * Created: 12/8/2022 12:52:23 PM
 *  Author: Eslam M.Ashour
 */ 
#include "timer1.h"

void TIMER_Init()
{
	// Setting Prescaler to 64
	DIO_SET_PIN_VAL(TCCR1B,CS10,1); //CS10
	DIO_SET_PIN_VAL(TCCR1B,CS11,1); //CS11
	DIO_SET_PIN_VAL(TCCR1B,CS12,0); //CS12
	
	// Starting Timer
	TIMER_Reset();
	
	// Setting Timer1 to Normal Mode
	DIO_SET_PIN_VAL(TCCR1A,WGM10,0); //WGM10
	DIO_SET_PIN_VAL(TCCR1A,WGM11,0); //WGM11
	DIO_SET_PIN_VAL(TCCR1B,WGM12,0); //WGM12
	DIO_SET_PIN_VAL(TCCR1B,WGM13,0); //WGM13
	
	
	// Setting Timer ov interrupt on
	DIO_SET_PIN_VAL(TIMSK,TOIE1,1);
}

void TIMER_Reset()
{
	TCNT1 = 0;
	timerOVFs = 0;
}

ISR(TIMER1_OVF_vect)
{
	timerOVFs+=1;	
}