#include <avr/interrupt.h>

#include "Init/Init.h"

int main(void)
{
	init();
    while (1) 
    {
		LOGIC_MainFunction();
	}
}		
