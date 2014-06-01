/***************************************************************************
 * DIO_Module.c
 *
 * Created :: 01/03/2012
 *  Author :: Islam Abo-Amra
 *	Tester :: Islam Abo-Amra
 *	File description ::
 *			DIO Module Implementation 
 *	Fuctions ::
 *		void DIO_Init_Port(uint8_t PORT_NAME, uint8_t PORT_VALUE)
 *		void DIO_Init_Port_bit(uint8_t PORT_NAME, uint8_t PIN_NAME, uint8_t PIN_VALUE)
 *		void DIO_Set_Port(uint8_t PORT_NAME, uint8_t PORT_VALUE)
 *      void DIO_Set_Port_bit(uint8_t PORT_NAME, uint8_t PIN_NAME)
 *		void DIO_Clear_Port_bit(uint8_t PORT_NAME, uint8_t PIN_NAME)
 *		uint8_t DIO_Read_Port(uint8_t PORT_NAME)
 *      void DIO_Toggle_Port(uint8_t PORT_NAME)
 *      void DIO_Toggle_Port_bit(uint8_t PORT_NAME, uint8_t PIN_NAME)
 *
 *****************************************************************************/ 

#include <avr/io.h>
#include "DIO_Module.h"


/*==========================================================================*/

/*****************************************************************************
* function name:
* 		DIO_Init_Port
* function description:
* 		This function determines which port will be input or output
* function input:
* 		PORT_NAME ,PORT_VALUE
* function output:
*		void
* created in:
* 		01/03/2012
* created by:
* 		Islam Abo-Amra 
*
*****************************************************************************/

void DIO_Init_Port(uint8_t PORT_NAME, uint8_t PORT_VALUE)
				// PORT_NAME( A|a|B|b|C|c|D|d ) ,PORT_VALUE ( INPUT | OUTPUT )
{
	switch(PORT_NAME) 
		{
			case 'A': case 'a':
				PORTA_DIRECTION = PORT_VALUE;
										break;
			case 'B': case 'b':
				PORTB_DIRECTION = PORT_VALUE;
										break;
			case 'C': case 'c':
				PORTC_DIRECTION = PORT_VALUE;
										break;
			case 'D': case 'd':
				PORTD_DIRECTION = PORT_VALUE;
										break;	
		}
}

/*===============================================================================*/

/*****************************************************************************
* function name:
* 		DIO_Init_Port_bit
* function description:
* 		This function determines which port bit will be input or output
* function input:
* 		PORT_NAME ,PIN_NAME ,PIN_VALUE
* function output:
*		void
* created in:
* 		01/03/2012
* created by:
* 		Islam Abo-Amra 
*
*****************************************************************************/

void DIO_Init_Port_bit(uint8_t PORT_NAME,uint8_t PIN_NAME,uint8_t PIN_VALUE)
	// PORT_NAME ( A|a|B|b|C|c|D|d ), PIN_NAME ( 0|1|2|3|4|5|6|7 ), PIN_VALUE ( I=INPUT , O=OUTPUT )
{
	
	MASK_BIT = ( 0x01 << PIN_NAME );		//choose the required pin & store it to MASK_BIT

	switch(PORT_NAME)
		{
			case 'A': case 'a':		// port name

				switch(PIN_VALUE)
					{
						case 'I': case 'i':		// pin is input
							PORTA_DIRECTION &= ~MASK_BIT;
								break;
						case 'O': case 'o':		// pin is output
							PORTA_DIRECTION |=  MASK_BIT;
								break;
					}break;


			case 'B': case 'b':		// port name

				switch(PIN_VALUE)
					{
						case 'I': case 'i':		// pin is input
							PORTB_DIRECTION &= ~MASK_BIT;
								break;
						case 'O': case 'o':		// pin is output
							PORTB_DIRECTION |=  MASK_BIT;
								break;
					}break;


			case 'C': case 'c':		// port name

				switch(PIN_VALUE)
					{
						case 'I': case 'i':		// pin is input
							PORTC_DIRECTION &= ~MASK_BIT;
								break;
						case 'O': case 'o':		// pin is output
							PORTC_DIRECTION |=  MASK_BIT;
								break;
					}break;


			case 'D': case 'd':		// port name

				switch(PIN_VALUE)
					{
						case 'I': case 'i':		// pin is input
							PORTD_DIRECTION &= ~MASK_BIT;
								break;
						case 'O': case 'o':		// pin is output
							PORTD_DIRECTION |=  MASK_BIT;
								break;
					}break;

		}
}

/*==========================================================================*/

/*****************************************************************************
* function name:
* 		DIO_Set_Port
* function description:
* 		This function sets value to the desired port
* function input:
* 		PORT_NAME ,PORT_VALUE
* function output:
*		void
* created in:
* 		01/03/2012
* created by:
* 		Islam Abo-Amra 
*
*****************************************************************************/

void DIO_Set_Port(uint8_t PORT_NAME, uint8_t PORT_VALUE)
		// PORT_NAME( A|a|B|b|C|c|D|d ) ,PORT_VALUE ( As You Like :D )
{
	switch(PORT_NAME) 
		{
			case 'A': case 'a':
				PORTA_WRITE_VALUE = PORT_VALUE;
										break;
			case 'B': case 'b':
				PORTB_WRITE_VALUE = PORT_VALUE;
										break;
			case 'C': case 'c':
				PORTC_WRITE_VALUE = PORT_VALUE;
										break;
			case 'D': case 'd':
				PORTD_WRITE_VALUE = PORT_VALUE;
										break;	
		}
}

/*=========================================================================*/

/*****************************************************************************
* function name:
* 		DIO_Set_Port_bit
* function description:
* 		This function sets value to the desired port bit
* function input:
* 		PORT_NAME ,PIN_NAME
* function output:
*		void
* created in:
* 		01/03/2012
* created by:
* 		Islam Abo-Amra 
*
*****************************************************************************/

void DIO_Set_Port_bit( uint8_t PORT_NAME, uint8_t PIN_NAME )
		// PORT_NAME ( A|a|B|b|C|c|D|d ), PIN_NAME ( 0|1|2|3|4|5|6|7 )
{

	MASK_BIT = ( 0x01 << PIN_NAME );		//choose the required pin & store it to MASK_BIT

	switch(PORT_NAME)
		{
			case 'A': case 'a':		// port name
				SET( PORTA_WRITE_VALUE,MASK_BIT );
					break;
								
			case 'B': case 'b':		// port name
				SET( PORTB_WRITE_VALUE,MASK_BIT );
					break;
								
			case 'C': case 'c':		// port name
				SET( PORTC_WRITE_VALUE,MASK_BIT );
					break;

								
			case 'D': case 'd':		// port name
				SET( PORTD_WRITE_VALUE,MASK_BIT );
					break;
		}
}

/*=========================================================================*/

/*****************************************************************************
* function name:
* 		DIO_Clear_Port_bit
* function description:
* 		This function sets value to the desired port bit
* function input:
* 		PORT_NAME ,PIN_NAME
* function output:
*		void
* created in:
* 		01/03/2012
* created by:
* 		Islam Abo-Amra 
*
*****************************************************************************/

void DIO_Clear_Port_bit(uint8_t PORT_NAME,uint8_t PIN_NAME)
		// PORT_NAME ( A|a|B|b|C|c|D|d ), PIN_NAME ( 0|1|2|3|4|5|6|7 )
{

	MASK_BIT = ( 0x01 << PIN_NAME );		//choose the required pin & store it to MASK_BIT

	switch(PORT_NAME)
		{
			case 'A': case 'a':		// port name
				CLEAR( PORTA_WRITE_VALUE, MASK_BIT );
					break;
								
			case 'B': case 'b':		// port name
				CLEAR( PORTB_WRITE_VALUE, MASK_BIT );
					break;

			case 'C': case 'c':		// port name
				CLEAR( PORTC_WRITE_VALUE, MASK_BIT );
					break;
								
			case 'D': case 'd':		// port name
				CLEAR( PORTD_WRITE_VALUE, MASK_BIT );
					break;

		}
}

/*=========================================================================*/

/*****************************************************************************
* function name:
* 		DIO_Read_Port
* function description:
* 		This function reads the port value
* function input:
* 		PORT_NAME 
* function output:
*		uint8_t
* created in:
* 		01/03/2012
* created by:
* 		Islam Abo-Amra 
*
*****************************************************************************/

uint8_t DIO_Read_Port(uint8_t PORT_NAME)
	// PORT_NAME ( A|a|B|b|C|c|D|d )  , Port value is returned 
{
	switch(PORT_NAME)
		{
			case 'A': case 'a':
							return PORTA_READ_VALUE;
									break;
			case 'B': case 'b':
							return PORTB_READ_VALUE;
									break;
			case 'C': case 'c':
							return PORTC_READ_VALUE;
									break;
			case 'D': case 'd':
							return PORTD_READ_VALUE;
									break;
		}
		return 0;
}

/*=========================================================================*/

/*****************************************************************************
* function name:
* 		DIO_Toggle_Port
* function description:
* 		This function Toggles the port value
* function input:
* 		PORT_NAME
* function output:
*		void
* created in:
* 		01/03/2012
* created by:
* 		Islam Abo-Amra 
*
*****************************************************************************/

void DIO_Toggle_Port(uint8_t PORT_NAME)
	// PORT_NAME ( A|a|B|b|C|c|D|d ) 
{
	switch(PORT_NAME)
		{
			case 'A': case 'a':
				PORTA_WRITE_VALUE = ~PORTA_WRITE_VALUE;
									break;
			case 'B': case 'b':
				PORTB_WRITE_VALUE = ~PORTB_WRITE_VALUE;
									break;
			case 'C': case 'c':
				PORTC_WRITE_VALUE = ~PORTC_WRITE_VALUE;
									break;
			case 'D': case 'd':
				PORTD_WRITE_VALUE = ~PORTD_WRITE_VALUE;
									break;
		}
}

/*=========================================================================*/

/*****************************************************************************
* function name:
* 		DIO_Toggle_Port_bit
* function description:
* 		This function Toggles bit value
* function input:
* 		PORT_NAME ,PIN_NAME
* function output:
*		void
* created in:
* 		01/03/2012
* created by:
* 		Islam Abo-Amra 
*
*****************************************************************************/

void DIO_Toggle_Port_bit(uint8_t PORT_NAME, uint8_t PIN_NAME)
	// PORT_NAME ( A|a|B|b|C|c|D|d ), PIN_NAME ( 0|1|2|3|4|5|6|7 )
{

	MASK_BIT = ( 0x01 << PIN_NAME );		//choose the required pin & store it to MASK_BIT

	switch(PORT_NAME)
		{
			case 'A': case 'a':
				TOGGLE( PORTA_WRITE_VALUE , MASK_BIT);
					break;

			case 'B': case 'b':
				TOGGLE( PORTB_WRITE_VALUE , MASK_BIT);
					break;

			case 'C': case 'c':
				TOGGLE( PORTC_WRITE_VALUE , MASK_BIT);
					break;

			case 'D': case 'd':
				TOGGLE( PORTD_WRITE_VALUE , MASK_BIT);
					break;
		}
}
