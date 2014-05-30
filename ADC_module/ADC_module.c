/***************************************************************************
 * ADC_module.c
 *
 *  Created :: Created: 17/07/2012 10:03:37 ص
 *  Author :: Islam Abo-Amra
 *	Tester :: 
 *	File description ::
 *			Analog to Digital Converter Module Implementation 
 *	Fuctions ::
 *		void ADC_INIT(uint8_t ADC_CHANNEL, uint8_t ADC_PORT, unit8_t ADC_VREF)
 *		void ADC_START(void)
 *		uint16_t READ_ADC(void)
 *****************************************************************************/ 

#include <avr/io.h>
#include "ADC_module.h"
#include "DIO_Module.h"


/*==========================================================================*/

/*****************************************************************************
* function name:
* 		ADC_INIT
* function description:
* 		This function initializes analog to digital converter ::
*			Set ADC channel used to be Input,
*			Set ADMUX register : (REFS0,REFS1,MUX4,MUX3,MUX2,MUX1,MUX0),
*			Set ADCSRA register: (ADPS2,ADPS1,ADPS0)
*			ADPS2:0 is set to 111 ( Prescaler is 128 ) to ensure that ADC clock is less than 200 KHZ,
*			The ADC result is right justified.
* function input:
* 		ADC_CHANNEL , ADC_PORT , ADC_VREF
* function output:
*		void
* created in:
* 		17/07/2012
* created by:
* 		Islam Abo-Amra 
*
*****************************************************************************/

void ADC_INIT(uint8_t ADC_CHANNEL, uint8_t ADC_PORT, uint8_t ADC_VREF)
	// ADC_CHANNEL ( CH_0 | CH_1 | CH_3 | CH_4 | CH_5 | CH_6 | CH_7 )
	// ADC_PORT    ( 'A'|'a'|'B'|'b'|'C'|'c'|'D'|'d' )
	// ADC_VREF    ( EXTERNAL_AREF | EXTERNAL_AVCC | INTERNAL_VREF | RESERVED )
{
	ADC_CTRL_STATUS_REG |=  (1<<ADC_PRESCALER_SELECT_BIT_2) | (1<<ADC_PRESCALER_SELECT_BIT_1) | (1<<ADC_PRESCALER_SELECT_BIT_0);
	
	switch (ADC_CHANNEL)
					{		
						case CH_0:
							ADC_MUX_SELECTION_REG |= (0<<ADC_ANALOG_CH_SELECTION_BIT_2) | (0<<ADC_ANALOG_CH_SELECTION_BIT_1) | (0<<ADC_ANALOG_CH_SELECTION_BIT_0);
								switch (ADC_PORT)
									{
										case 'A': case 'a':
											DIO_Init_Port_bit('A',0,'I');
												break;
										case 'B': case 'b':
											DIO_Init_Port_bit('B',0,'I');
												break;
										case 'C': case 'c':
											DIO_Init_Port_bit('C',0,'I');
												break;
										case 'D': case 'd':
											DIO_Init_Port_bit('D',0,'I');
												break;
									}break;
						
					case CH_1:
						ADC_MUX_SELECTION_REG |= (0<<ADC_ANALOG_CH_SELECTION_BIT_2) | (0<<ADC_ANALOG_CH_SELECTION_BIT_1) | (1<<ADC_ANALOG_CH_SELECTION_BIT_0);
							switch (ADC_PORT)
								{
									case 'A': case 'a':
										DIO_Init_Port_bit('A',1,'I');
											break;
									case 'B': case 'b':
										DIO_Init_Port_bit('B',1,'I');
											break;
									case 'C': case 'c':
										DIO_Init_Port_bit('C',1,'I');
											break;
									case 'D': case 'd':
										DIO_Init_Port_bit('D',1,'I');
											break;
								}break;
						
					case CH_2:
						ADC_MUX_SELECTION_REG |= (0<<ADC_ANALOG_CH_SELECTION_BIT_2) | (1<<ADC_ANALOG_CH_SELECTION_BIT_1) | (0<<ADC_ANALOG_CH_SELECTION_BIT_0);
							switch (ADC_PORT)
								{
									case 'A': case 'a':
										DIO_Init_Port_bit('A',2,'I');
											break;
									case 'B': case 'b':
										DIO_Init_Port_bit('B',2,'I');
											break;
									case 'C': case 'c':
										DIO_Init_Port_bit('C',2,'I');
											break;
									case 'D': case 'd':
											DIO_Init_Port_bit('D',2,'I');
											break;
								}break;
			
					case CH_3:
						ADC_MUX_SELECTION_REG |= (0<<ADC_ANALOG_CH_SELECTION_BIT_2) | (1<<ADC_ANALOG_CH_SELECTION_BIT_1) | (1<<ADC_ANALOG_CH_SELECTION_BIT_0);
							switch (ADC_PORT)
								{
									case 'A': case 'a':
										DIO_Init_Port_bit('A',3,'I');
											break;
									case 'B': case 'b':
										DIO_Init_Port_bit('B',3,'I');
											break;
									case 'C': case 'c':
										DIO_Init_Port_bit('C',3,'I');
											break;
									case 'D': case 'd':
										DIO_Init_Port_bit('D',3,'I');
											break;
								}break;
					
					case CH_4:
						ADC_MUX_SELECTION_REG |= (1<<ADC_ANALOG_CH_SELECTION_BIT_2) | (0<<ADC_ANALOG_CH_SELECTION_BIT_1) | (0<<ADC_ANALOG_CH_SELECTION_BIT_0);
							switch (ADC_PORT)
								{
									case 'A': case 'a':
										DIO_Init_Port_bit('A',4,'I');
											break;
									case 'B': case 'b':
										DIO_Init_Port_bit('B',4,'I');
											break;
									case 'C': case 'c':
										DIO_Init_Port_bit('C',4,'I');
											break;
									case 'D': case 'd':
										DIO_Init_Port_bit('D',4,'I');
											break;
								}break;

					case CH_5:
						ADC_MUX_SELECTION_REG |= (1<<ADC_ANALOG_CH_SELECTION_BIT_2) | (0<<ADC_ANALOG_CH_SELECTION_BIT_1) | (1<<ADC_ANALOG_CH_SELECTION_BIT_0);
							switch (ADC_PORT)
								{
									case 'A': case 'a':
										DIO_Init_Port_bit('A',5,'I');
											break;
									case 'B': case 'b':
										DIO_Init_Port_bit('B',5,'I');
											break;
									case 'C': case 'c':
										DIO_Init_Port_bit('C',5,'I');
											break;
									case 'D': case 'd':
										DIO_Init_Port_bit('D',5,'I');
											break;
								}break;

					case CH_6:
						ADC_MUX_SELECTION_REG |= (1<<ADC_ANALOG_CH_SELECTION_BIT_2) | (1<<ADC_ANALOG_CH_SELECTION_BIT_1) | (0<<ADC_ANALOG_CH_SELECTION_BIT_0);
							switch (ADC_PORT)
								{
									case 'A': case 'a':
										DIO_Init_Port_bit('A',6,'I');
											break;
									case 'B': case 'b':
										DIO_Init_Port_bit('B',6,'I');
											break;
									case 'C': case 'c':
										DIO_Init_Port_bit('C',6,'I');
											break;
									case 'D': case 'd':
										DIO_Init_Port_bit('D',6,'I');
											break;
								}break;

					case CH_7:
						ADC_MUX_SELECTION_REG |= (1<<ADC_ANALOG_CH_SELECTION_BIT_2) | (1<<ADC_ANALOG_CH_SELECTION_BIT_1) | (1<<ADC_ANALOG_CH_SELECTION_BIT_0);
							switch (ADC_PORT)
								{
									case 'A': case 'a':
										DIO_Init_Port_bit('A',7,'I');
											break;
									case 'B': case 'b':
										DIO_Init_Port_bit('B',7,'I');
											break;
									case 'C': case 'c':
										DIO_Init_Port_bit('C',7,'I');
											break;
									case 'D': case 'd':
										DIO_Init_Port_bit('D',7,'I');
											break;
								}break;	
					}
						
						
	switch (ADC_VREF)
					{
						case EXTERNAL_AREF:
							ADC_MUX_SELECTION_REG |= (0<<ADC_REFERENCE_SELECTION_1) | (0<<ADC_REFERENCE_SELECTION_0);
								break;	
		
						case EXTERNAL_AVCC:
							ADC_MUX_SELECTION_REG |= (0<<ADC_REFERENCE_SELECTION_1) | (1<<ADC_REFERENCE_SELECTION_0);
								break;
								
						case INTERNAL_VREF:
							ADC_MUX_SELECTION_REG |= (1<<ADC_REFERENCE_SELECTION_1) | (1<<ADC_REFERENCE_SELECTION_0);
								break;
				
						case RESERVED:
							ADC_MUX_SELECTION_REG |= (1<<ADC_REFERENCE_SELECTION_1) | (1<<ADC_REFERENCE_SELECTION_0);
								break;
					}


}	


/*==========================================================================*/

/*****************************************************************************
* function name:
* 		ADC_START
* function description:
* 		This function starts the conversion by writing 1 to ADEN (ADC Enable bit) of ADCSRA register
*		and write 1 to ADSC (ADC Start Conversion bit) of ADCSRA register.
* function input:
* 		void
* function output:
*		void
* created in:
* 		19/07/2012
* created by:
* 		Islam Abo-Amra 
*
*****************************************************************************/		

void ADC_START(void)
{
	ADC_CTRL_STATUS_REG |= ( 1 << ADC_ENABLE ) | ( 1 << ADC_START_CONVERSION );
}


/*==========================================================================*/

/*****************************************************************************
* function name:
* 		READ_ADC
* function description:
* 		This function waits until the conversion completes then reads 
*		both ADCL and ADCH which have the ADC conversion result 
*		inside and returns the result as a 16 bit integer.
* function input:
* 		void
* function output:
*		void
* created in:
* 		19/07/2012
* created by:
* 		Islam Abo-Amra 
*
*****************************************************************************/	

uint16_t READ_ADC(void)
{
	while ( 0 == (ADC_CTRL_STATUS_REG & (1<<ADC_INTERRUPT_FLAG)) );
	return ADC;
}
