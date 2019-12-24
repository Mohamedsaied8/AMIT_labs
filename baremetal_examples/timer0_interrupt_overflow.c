/*
 * Timer.c
 *
 * Created: 12/21/2019 12:33:56 PM
 * Author : Mohamed
 */ 
#define F_CPU	 16000000
#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned int counter=0;


int main(void)
{
	DDRC=(1<<7); //led1
	//Configure Timer control register
	//prescaler 64
	TCCR0 = (1<<CS01)|(1<<CS00);
	TIMSK=(1<<TOIE0);
	sei();
    while (1) 
    {

		if(counter>=100){
			PORTC^=(1<<7); //toggle led 1
			counter=0;
		}//if
	
    }//while
}//main


//Interrupt Service Routine
ISR(TIMER0_OVF_vect){
	counter++;
}
