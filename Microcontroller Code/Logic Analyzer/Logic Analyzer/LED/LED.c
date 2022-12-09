#include "LED.h"

void LED_On()
{
	DIO_SET_PIN_VAL(LED_Port,LED_pin,Logic_High);
}
void LED_Off()
{
	DIO_SET_PIN_VAL(LED_Port,LED_pin,Logic_Low);
}
void LED_Blink()
{
	DIO_SET_PIN_VAL(LED_Port,LED_pin,Logic_High);
	_delay_ms(500);
	DIO_SET_PIN_VAL(LED_Port,LED_pin,Logic_Low);
	_delay_ms(500);
	DIO_SET_PIN_VAL(LED_Port,LED_pin,Logic_High);
	_delay_ms(500);
	DIO_SET_PIN_VAL(LED_Port,LED_pin,Logic_Low);
	_delay_ms(500);
}

void LED_Init()
{
	DIO_SET_PIN_DIR(LED_Port,LED_pin,PIN_Out);
	LED_Off();
}