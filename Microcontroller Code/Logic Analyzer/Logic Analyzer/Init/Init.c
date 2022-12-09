#include "Init.h"

void init()
{

	UART_Config();
	
	LED_Init();
	LOGIC_Init();
	TIMER_Init();
	sei();
}