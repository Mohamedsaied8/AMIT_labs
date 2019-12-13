/*
 * GccApplication1.c
 *
 * Created: 5/19/2019 11:12:00 AM
 * Author : Mohamed
 */ 

#include <avr/io.h>
#include "lcd.h"

#define degree_sysmbol 0xdf

void ADC_Init(){
	DDRA = 0x00;							        /* Make ADC port as input */
	ADCSRA = 0x87;									/* Enable ADC, with freq/128  */
	ADMUX = 0x40;									/* Vref: Avcc, ADC channel: 0 */
}

int ADC_Read(char channel)
{
	ADMUX = 0x40 | (channel & 0x07);				/* set input channel to read */
	ADCSRA |= (1<<ADSC);							/* Start ADC conversion */
	while (!(ADCSRA & (1<<ADIF)));					/* Wait until end of conversion by polling ADC interrupt flag */
	ADCSRA |= (1<<ADIF);							/* Clear interrupt flag */
	_delay_ms(1);									/* Wait a little bit */
	return ADCW;									/* Return ADC word */
}



int main(void)
{
   LCD_Init();			/* Initialization of LCD*/
	ADC_Init();                 /* initialize ADC*/

   LCD_String("El hamdulelah");	/* Write string on 1st line of LCD*/
   LCD_Command(0xC0);		/* Go to 2nd line*/
   LCD_String("Mohamed Saied");	/* Write string on 2nd line*/
   while(1);
}

