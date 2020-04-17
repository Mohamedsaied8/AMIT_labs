/*
 * ADC_TEST_Q6.c
 *
 * Created: 17/04/2020 06:31:46 م
 * Author : Abdel-Rahman
 
 *Requirements :
 -Select ADC1 as input channel - ADCSRA prescaler /128 - ADCSRA auto trigger mode
 -polling -ADMUX right adjust( no left adjust)
 -internal reference 2.56v
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <string.h>

void ADC_Init(){
	   //select A1 as input
	   DDRA &=~(1<<1);
	   //ADC1 as input | Internal reference
	   ADMUX=(1<<REFS1)|(1<<REFS0); //00001=ADC1 |reference 1100 =C
	   ADCSRA=(1<<ADATE)|(1<<ADPS0)|(ADPS1)|(ADPS2)|(1<<ADEN);
		
}
unsigned int ADC_Read(unsigned channel){
	 ADMUX=0xC0 |(channel&0x07);
	 //start conversion
	 ADCSRA|=(1<<ADSC);
	 
	 //check flag -
	 while(!(ADCSRA&(1<<ADIF))); //infinite loop --POLLING 100%
	 //clear flag
	 ADCSRA|=(1<<ADIF);
	 //ADCL
	 unsigned int data = ADCL;
	 //ADCH
	 data|=ADCH<<8;
	 return data;
 }
int main(void)
{
	ADC_Init();
    while (1) 
    {
	char buffer[10]="";
	unsigned int pot_value=	ADC_Read(1); //POT
	//equation from to celius
		sprintf(buffer,"%d",pot_value);
		//	LCD_String(buffer);
    }
}

