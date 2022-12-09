#ifndef INIT_H_
#define INIT_H_

//Include
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "../Lib/DIO/DIO.h"
#include "../Lib/USART/uart.h"
#include "../Lib/TIMER/timer1.h"

#define F_CPU 8000000UL
//-----------------

// LED
#include "../LED/LED.h"

// Logic Analyzer
#include "../LogicAnalyzer/logicAnalyzer.h"

extern void init();


#endif /* INIT_H_ */