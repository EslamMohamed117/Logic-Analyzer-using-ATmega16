#include <avr/io.h>
#include "STD_MACROS.h"

void DIO_SET_PIN_DIR(unsigned char port, unsigned char pin, unsigned char dir)
{
	switch(port)
	{
		//Direction of Pin in port A
		case 'A':
		case 'a':
		if(dir == 1)
		{
			SET_BIT(DDRA,pin);
		}
		else
		{
			CLR_BIT(DDRA,pin);
		}
		break;
		
		//Direction of Pin in port B
		case 'B':
		case 'b':
		if(dir == 1)
		{
			SET_BIT(DDRB,pin);
		}
		else
		{
			CLR_BIT(DDRB,pin);
		}
		break;
		
		//Direction of Pin in port C
		case 'C':
		case 'c':
		if(dir == 1)
		{
			SET_BIT(DDRC,pin);
		}
		else
		{
			CLR_BIT(DDRC,pin);
		}
		break;
		
		//Direction of Pin in port D
		case 'D':
		case 'd':
		if(dir == 1)
		{
			SET_BIT(DDRD,pin);
		}
		else
		{
			CLR_BIT(DDRD,pin);
		}
		break;
		
		default:
		break;
	}
}

void DIO_SET_PIN_VAL(unsigned char port, unsigned char pin, unsigned char val)
{
	switch(port)
	{
		//Value of Pin in port A
		case 'A':
		case 'a':
		if(val == 1)
		{
			SET_BIT(PORTA,pin);
		}
		else
		{
			CLR_BIT(PORTA,pin);
		}
		break;
		
		//Value of Pin in port B
		case 'B':
		case 'b':
		if(val == 1)
		{
			SET_BIT(PORTB,pin);
		}
		else
		{
			CLR_BIT(PORTB,pin);
		}
		break;
		
		//Value of Pin in port C
		case 'C':
		case 'c':
		if(val == 1)
		{
			SET_BIT(PORTC,pin);
		}
		else
		{
			CLR_BIT(PORTC,pin);
		}
		break;
		
		//Value of Pin in port D
		case 'D':
		case 'd':
		if(val == 1)
		{
			SET_BIT(PORTD,pin);
		}
		else
		{
			CLR_BIT(PORTD,pin);
		}
		break;
		
		default:
		break;
	}
}

void DIO_TOG_PIN_VAL(unsigned char port, unsigned char pin) 
{
	switch(port)
	{
		//Toggle Pin in port A
		case 'A':
		case 'a':
		TOG_BIT(PORTA,pin);
		break;
		
		//Toggle Pin in port B
		case 'B':
		case 'b':
		TOG_BIT(PORTB,pin);
		break;
		
		//Toggle Pin in port C
		case 'C':
		case 'c':
		TOG_BIT(PORTC,pin);
		break;
		
		//Toggle Pin in port D
		case 'D':
		case 'd':
		TOG_BIT(PORTD,pin);
		break;
		
		default:
		break;
	}
}

unsigned char DIO_u8READ_PIN_VAL(unsigned char port, unsigned char pin) //u8 means unsigned char (To know return value)
{
	unsigned char val = 0;
	switch(port)
	{
		//READ Pin in port A
		case 'A':
		case 'a':
		val = READ_BIT(PINA,pin);
		break;
		
		//READ Pin in port B
		case 'B':
		case 'b':
		val = READ_BIT(PINB,pin);
		break;
		
		//READ Pin in port C
		case 'C':
		case 'c':
		val = READ_BIT(PINC,pin);
		break;
		
		//READ Pin in port D
		case 'D':
		case 'd':
		val = READ_BIT(PIND,pin);
		break;
		
		default:
		break;
	}
	return val;
}

void DIO_SET_PORT_DIR(unsigned char port, unsigned char dir)
{
	switch(port)
	{
		//Direction of  port A
		case 'A':
		case 'a':
		DDRA = dir;
		break;
		
		//Direction of  port B
		case 'B':
		case 'b':
		DDRB = dir;
		break;
		
		//Direction of  port C
		case 'C':
		case 'c':
		DDRC = dir;
		break;
		
		//Direction of  port D
		case 'D':
		case 'd':
		DDRD = dir;
		break;
		
		default:
		break;
	}
}

void DIO_SET_PORT_VAL(unsigned char port, unsigned char val)
{
	switch(port)
	{
		//Value of  port A
		case 'A':
		case 'a':
		PORTA = val;
		break;
		
		//Value of  port B
		case 'B':
		case 'b':
		PORTB = val;
		break;
		
		//Value of  port C
		case 'C':
		case 'c':
		PORTC = val;
		break;
		
		//Value of  port D
		case 'D':
		case 'd':
		PORTD = val;
		break;
		
		default:
		break;
	}
}

unsigned char DIO_u8READ_PORT_VAL(unsigned char port) //u8 means unsigned char (To know return value)
{
	unsigned char val = 0;
	switch(port)
	{
		//READ  port A
		case 'A':
		case 'a':
		val = PINA;
		break;
		
		//READ  port B
		case 'B':
		case 'b':
		val = PINB;
		break;
		
		//READ  port C
		case 'C':
		case 'c':
		val = PINC;
		break;
		
		//READ port D
		case 'D':
		case 'd':
		val = PIND;
		break;
		
		default:
		break;
	}
	return val;
}

void DIO_TOG_PORT_VAL(unsigned char port)
{
	switch(port) 
	{
		//Toggle port A
		case 'A':
		case 'a':
		PORTA = ~ PORTA;
		break;
		
		//Toggle port B
		case 'B':
		case 'b':
		PORTB = ~ PORTB;
		break;
		
		//Toggle port C
		case 'C':
		case 'c':
		PORTC = ~ PORTC ;
		break;
		
		//Toggle port D
		case 'D':
		case 'd':
		PORTD = ~ PORTD;
		break;
		
		default:
		break;
	}
}

void DIO_EN_PULLUP(char port, char pin, char enable)
{
	switch(port)
	{
		//Pull Up Enable of Pin in port A
		case 'A':
		case 'a':
		if(enable == 1)
		{
			SET_BIT(PORTA,pin);
		}
		else
		{
			CLR_BIT(PORTA,pin);
		}
		break;
		
		//Pull Up Enable of Pin in port B
		case 'B':
		case 'b':
		if(enable == 1)
		{
			SET_BIT(PORTA,pin);
		}
		else
		{
			CLR_BIT(PORTA,pin);
		}
		break;
		
		//Pull Up Enable of Pin in port C
		case 'C':
		case 'c':
		if(enable == 1)
		{
			SET_BIT(PORTA,pin);
		}
		else
		{
			CLR_BIT(PORTA,pin);
		}
		break;
		
		//Pull Up Enable of Pin in port D
		case 'D':
		case 'd':
		if(enable == 1)
		{
			SET_BIT(PORTA,pin);
		}
		else
		{
			CLR_BIT(PORTA,pin);
		}
		break;
		
		default:
		break;
	}
}

void DIO_WR_LOW_NIBBLE(unsigned char port , unsigned char val)
{
	val&=0x0f;
	switch(port)
	{
		case 'A':
		case 'a':
			PORTA&=0xf0;
			PORTA|=val;
			break;
			
		case 'B':
		case 'b':
			PORTB&=0xf0;
			PORTB|=val;
			break;
			
		case 'C':
		case 'c':
			PORTC&=0xf0;
			PORTC|=val;
			break;
			
		case 'D':
		case 'd':
			PORTD&=0xf0;
			PORTD|=val;
			break;
	}
}


void DIO_WR_HIGH_NIBBLE(unsigned char port , unsigned char val)
{
	val<<=4;
	switch(port)
	{
		case 'A':
		case 'a':
		PORTA&=0x0f;
		PORTA|=val;
		break;
		
		case 'B':
		case 'b':
		PORTB&=0x0f;
		PORTB|=val;
		break;
		
		case 'C':
		case 'c':
		PORTC&=0x0f;
		PORTC|=val;
		break;
		
		case 'D':
		case 'd':
		PORTD&=0x0f;
		PORTD|=val;
		break;
	}
}