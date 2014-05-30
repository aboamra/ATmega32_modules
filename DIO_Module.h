/**********************************************************************
 *	DIO_Module.h
 *	Created: 01/03/2012
 *	DIO_module.h
 *	
 *	This module is compatible with ATmega32 
 *
 *      Author: Islam Abo-Amra
 *		Tester: Islam Abo-Amra
 *  File description:
 *		The header file of DIO module
 *
 *  Functions:
 *  	void DIO_Init_Port(uint8_t PORT_NAME, uint8_t PORT_VALUE)
 *		void DIO_Init_Port_bit(uint8_t PORT_NAME, uint8_t PIN_NAME, uint8_t PIN_VALUE)
 *		void DIO_Set_Port(uint8_t PORT_NAME, uint8_t PORT_VALUE)
 *      void DIO_Set_Port_bit(uint8_t PORT_NAME, uint8_t PIN_NAME)
 *		void DIO_Clear_Port_bit(uint8_t PORT_NAME, uint8_t PIN_NAME)
 *		uint8_t DIO_Read_Port(uint8_t PORT_NAME)
 *      void DIO_Toggle_Port(uint8_t PORT_NAME)
 *      void DIO_Toggle_Port_bit(uint8_t PORT_NAME, uint8_t PIN_NAME)
 *
 ************************************************************************************************/


#ifndef DIO_MODULE_H_
#define DIO_MODULE_H_

#include <stdint.h>

volatile unsigned char MASK_BIT;

#define PORTA_DIRECTION 	DDRA
#define PORTB_DIRECTION 	DDRB
#define PORTC_DIRECTION 	DDRC
#define PORTD_DIRECTION 	DDRD

#define PORTA_WRITE_VALUE 	PORTA
#define PORTB_WRITE_VALUE 	PORTB
#define PORTC_WRITE_VALUE 	PORTC
#define PORTD_WRITE_VALUE 	PORTD

#define PORTA_READ_VALUE 	PINA
#define PORTB_READ_VALUE 	PINB
#define PORTC_READ_VALUE 	PINC
#define PORTD_READ_VALUE 	PIND

#define INPUT				0x00
#define OUTPUT				0xff

#define SET( PORT , MASK )		( PORT |=  MASK )
#define CLEAR( PORT , MASK )	( PORT &= ~MASK )
#define TOGGLE( PORT , MASK )	( PORT ^=  MASK )


void	DIO_Init_Port(uint8_t, uint8_t);
void	DIO_Init_Port_bit(uint8_t, uint8_t, uint8_t);
void	DIO_Set_Port_bit(uint8_t,uint8_t);
void	DIO_Set_Port(uint8_t, uint8_t);
uint8_t	DIO_Read_Port(uint8_t);
void	DIO_Clear_Port_bit(uint8_t,uint8_t);
void	DIO_Toggle_Port(uint8_t);
void	DIO_Toggle_Port_bit(uint8_t, uint8_t);



#endif /* DIO_MODULE_H_ */
