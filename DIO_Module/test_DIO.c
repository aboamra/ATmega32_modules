/*
 * main.c
 *
 * Created: 02/03/2012 02:41:31 ص
 *  Author: Islam
 */ 

#include <stdio.h>
#include <util/delay.h>
#include "DIO_Module.h"

int main()
{

	//Initialization
	DIO_Init_Port_bit('A',3,'O');
	DIO_Init_Port_bit('A',4,'O');
	DIO_Init_Port_bit('A',5,'O');
	DIO_Init_Port_bit('A',6,'O');	
	DIO_Init_Port_bit('A',7,'O');
	DIO_Init_Port_bit('d',6,'O');


	while (1)
		{

			DIO_Set_Port_bit('A',3);
			DIO_Toggle_Port_bit('A',4);
			DIO_Set_Port_bit('A',5);
			DIO_Toggle_Port_bit('A',6);
			DIO_Set_Port_bit('A',7);
			DIO_Set_Port_bit('d',2);
				_delay_ms(1000);
		
			DIO_Toggle_Port_bit('A',3);
			DIO_Set_Port_bit('A',4);

			DIO_Toggle_Port_bit('A',5);
			DIO_Set_Port_bit('A',6);
			DIO_Toggle_Port_bit('A',7);

			DIO_Toggle_Port_bit('d',2);
				_delay_ms(1000);
	
		}
	
	return 0;
}
