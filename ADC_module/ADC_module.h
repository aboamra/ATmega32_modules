/***************************************************************************
 * ADC_module.h
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


#ifndef ADC_MODULE_H_
#define ADC_MODULE_H_

#include <stdint.h>

// ADC Channels Selection
#define CH_0	0
#define CH_1	1
#define CH_2	2
#define CH_3	3
#define CH_4	4
#define CH_5	5
#define CH_6	6
#define CH_7	7


// ADC Registers for ATMEGA_AVR
#define ADC_MUX_SELECTION_REG				ADMUX
#define ADC_REFERENCE_SELECTION_0			REFS0
#define ADC_REFERENCE_SELECTION_1			REFS1
#define ADC_LEFT_ADJUST_RESULT				ADLAR
#define ADC_ANALOG_CH_SELECTION_BIT_0		MUX0
#define ADC_ANALOG_CH_SELECTION_BIT_1		MUX1
#define ADC_ANALOG_CH_SELECTION_BIT_2		MUX2
#define ADC_ANALOG_CH_SELECTION_BIT_3		MUX3
#define ADC_ANALOG_CH_SELECTION_BIT_4		MUX4

#define ADC_CTRL_STATUS_REG					ADCSRA
#define ADC_ENABLE							ADEN
#define ADC_START_CONVERSION				ADSC
#define ADC_INTERRUPT_FLAG					ADIF
#define ADC_INTERRUPT_ENABLE				ADIE
#define ADC_PRESCALER_SELECT_BIT_0			ADPS0
#define ADC_PRESCALER_SELECT_BIT_1			ADPS1
#define ADC_PRESCALER_SELECT_BIT_2			ADPS2




// Voltage Reference Selection
#define EXTERNAL_AREF	0
#define EXTERNAL_AVCC	1
#define RESERVED		2
#define INTERNAL_VREF	3




// Module Functions
void ADC_INIT(uint8_t ,uint8_t, uint8_t );
void ADC_START(void);
uint16_t READ_ADC(void);




#endif /* ADC_MODULE_H_ */
