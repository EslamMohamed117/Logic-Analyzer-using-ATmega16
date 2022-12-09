#ifndef LED_H_
#define LED_H_

#include <avr/io.h>
#include <util/delay.h>

#define LED_Port 'C'
#define LED_pin 0
#define PIN_In 0
#define PIN_Out 1
#define Logic_High 1
#define Logic_Low 0

extern void LED_On();
extern void LED_Off();
extern void LED_Blink();
extern void LED_Init();

#endif /* LED_H_ */