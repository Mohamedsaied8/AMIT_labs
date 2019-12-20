/*
	LM35 Interfacing with ATmega16/32

 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include "lcd.h"

#define degree_sysmbol 0xdf
#define ADMUX0		0

void ADC_Init(){										
	DDRA = 0xF0;							        /* Make ADC port as input */
	ADCSRA =(1<<ADPS0) | (1<<ADPS1)	|(1<<ADPS2) | (1<<ADATE) | (1<<ADEN);							/* Enable ADC, with freq/128  */
	ADMUX =(1<<REFS0) | (1<<REFS1) |(1<<ADMUX0);		/* Vref: Internal , ADC channel: 1 */
}

int ADC_Read(char channel)							
{					 
	ADMUX = 0xC0 | (channel & 0x07);				/* set input channel to read */
	ADCSRA |= (1<<ADSC);							/* Start ADC conversion */
	while (!(ADCSRA & (1<<ADIF)));					/* Wait until end of conversion by polling ADC interrupt flag */
	ADCSRA |= (1<<ADIF);							/* Clear interrupt flag */
	_delay_ms(1);									/* Wait a little bit */
	
	int dataADC=ADCL;
	dataADC=ADCH<<8;
	return dataADC;
	//return ADCW;									/* Return ADC word */
	
}


int main()
{
	char Temperature[10];
	float celsius;

	LCD_Init();                 /* initialize 16x2 LCD*/
	ADC_Init();                 /* initialize ADC*/
	LCD_Command(0x80);		/* Go to 1st line*/
	LCD_String("AMIT");
	LCD_Command(0xC0);		/* Go to 2nd line*/
	LCD_String("Sensor Example");
	LCD_Clear();
	while(1)
	{
		LCD_Command(0x80);		/* Go to 1st line*/
		//LCD_String_xy(0,0,"Temperature");
		 LCD_String("Temperature");
		celsius = (ADC_Read(1)*4.88);
		celsius = (celsius/10.00); //equation of temperature sensor
		sprintf(Temperature,"%d%cC  ", (int)celsius, degree_sysmbol);               // convert integer value to ASCII string 
		LCD_Command(0xC0);	
		LCD_String(Temperature);                // send string data for printing  
		_delay_ms(1000);
		memset(Temperature,0,10);
		 
	}
	return 0;
}

