#ifndef DIO_H_
#define DIO_H_

/*
	Function Name        : DIO_SET_PIN_DIR
	Function Return      : void
	function Arguments   : unsigned char port, unsigned char pin, unsigned char dir
	function Description : Set direction of a pin in the given port (0 = input, 1 = output)
*/
void DIO_SET_PIN_DIR(unsigned char port, unsigned char pin, unsigned char dir);


/*
	Function Name        : DIO_SET_PIN_VAL
	Function Return      : void
	function Arguments   : unsigned char port, unsigned char pin, unsigned char val
	function Description : Set value of a pin in the given port (0 = low, 1 = high)
*/
void DIO_SET_PIN_VAL(unsigned char port, unsigned char pin, unsigned char val);


/*
	Function Name        : DIO_TOG_PIN_VAL
	Function Return      : void
	function Arguments   : unsigned char port, unsigned char pin
	function Description : Reverse value of a pin in the given port
*/
void DIO_TOG_PIN_VAL(unsigned char port, unsigned char pin);



/*
	Function Name        : DIO_u8READ_PIN_VAL
	Function Return      : unsigned char
	function Arguments   : unsigned char port, unsigned char pin
	function Description : Read value of a pin in the given port (0 = low, 1 = high)
*/
unsigned char DIO_u8READ_PIN_VAL(unsigned char port, unsigned char pin); //u8 means unsigned char (To know return value)


/*
	Function Name        : DIO_SET_PORT_DIR
	Function Return      : void
	function Arguments   : unsigned char port, unsigned char dir
	function Description : Set Direction of the given port (0 = input, 1 = output)
*/
void DIO_SET_PORT_DIR(unsigned char port, unsigned char dir);


/*
	Function Name        : DIO_SET_PORT_VAL
	Function Return      : void
	function Arguments   : unsigned char port, unsigned char val
	function Description : Set value of the given port (0 = low, 1 = high)
*/
void DIO_SET_PORT_VAL(unsigned char port, unsigned char val);


/*
	Function Name        : DIO_u8READ_PORT_VAL
	Function Return      : unsigned char
	function Arguments   : unsigned char port
	function Description : Read value of the given port (0 = low, 1 = high)
*/
unsigned char DIO_u8READ_PORT_VAL(unsigned char port); //u8 means unsigned char (To know return value)


/*
	Function Name        : DIO_TOG_PORT_VAL
	Function Return      : void
	function Arguments   : unsigned char port
	function Description : Reverse value of the given port
*/
void DIO_TOG_PORT_VAL(unsigned char port);

/*
	Function Name        : DIO_EN_PULLUP
	Function Return      : void
	function Arguments   : char port, char pin, char enable
	function Description : Enable the Internal PullUp of the given pin in the given Port
*/
void DIO_EN_PULLUP(char port, char pin, char enable);


/*
	Function Name        : DIO_WR_LOW_NIBBLE
	Function Return      : void
	function Arguments   : unsigned char port , unsigned char val
	function Description : Writes the 4 Least Bits of the given Value on the first 4 pins of the given Port
*/
void DIO_WR_LOW_NIBBLE(unsigned char port , unsigned char val);




/*
	Function Name        : DIO_WR_HIGH_NIBBLE
	Function Return      : void
	function Arguments   : unsigned char port , unsigned char val
	function Description : Writes the 4 Least Bits of th given Value on the second 4 pins of the given Port
*/
void DIO_WR_HIGH_NIBBLE(unsigned char port , unsigned char val);

#endif /* DIO_H_ */