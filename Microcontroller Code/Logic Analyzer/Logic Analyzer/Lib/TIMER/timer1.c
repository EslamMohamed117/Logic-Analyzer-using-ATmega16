/*
 * timer0.c
 *
 * Created: 12/8/2022 12:52:23 PM
 *  Author: Eslam M.Ashour
 */ 
#include "timer1.h"

void TIMER_Init()
{
	// Setting Prescaler to 8
	CLR_BIT(TCCR1B,CS10); //CS10
	SET_BIT(TCCR1B,CS11); //CS11
	CLR_BIT(TCCR1B,CS12); //CS12
	
	// Starting Timer
	TIMER_Reset();
	
	// Setting Timer1 to Normal Mode
	CLR_BIT(TCCR1A,WGM10); //WGM10
	CLR_BIT(TCCR1A,WGM11); //WGM11
	CLR_BIT(TCCR1B,WGM12); //WGM12
	CLR_BIT(TCCR1B,WGM13); //WGM13
	
	
	// Setting Timer ov interrupt on
	SET_BIT(TIMSK,TOIE1);
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