/*
 * Timer.c
 *
 * Created: 12/21/2019 12:33:56 PM
 * Author : Mohamed
 * example Generate delay using timer0 polling
 */ 
#define F_CPU	 16000000

#include <avr/io.h>


int main(void)
{
	unsigned int counter=0;
	DDRC=(1<<7); //led1
	//Configure Timer control register
	//prescaler 64
	TCCR0 = (1<<CS01)|(1<<CS00); //generate delay every 1ms
    while (1) 
    {
	while(!(TIFR & (1<<TOV0))); 
	TIFR|=(1<<TOV0); // clear flag 
		counter++;
		if(counter>=100){
			PORTC^=(1<<7); //toggle led 1
			counter=0;
		}
	
    }
}


