#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
void Servo_Write(char);
void Wait()
{
	uint16_t i;
	for(i=0;i<50;i++)
	{
		_delay_loop_2(0);
		_delay_loop_2(0);
		_delay_loop_2(0);
	}
}
void main()
{
	//FOR TIMER1
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        //NON Inverted PWM
	TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=64 MODE 14(FAST PWM)
	ICR1=4999;  //frequency PWM=50Hz
	DDRD|=(1<<PD4)|(1<<PD5);   //PWM Pins as Output
	while(1)
	{
		Servo_Write(90);  //90 degree
		_delay_ms(3000);
		Servo_Write(0);   //0 degree
		_delay_ms(3000);
		Servo_Write(180);  //180 degree
		_delay_ms(3000);
		
	}
}

void Servo_Write(char angle){
	if (angle ==0){
		OCR1A = 97;
	}else{
		OCR1A = (angle*2.43)+97;		
	}
}