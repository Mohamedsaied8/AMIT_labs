/*
 * main.c
 *
 *  Created on: Apr 16, 2020
 *      Author: Mohamed
 *
 *      This is a Round-Robin Scheduler with Quantum of 100ms
 */

#include <avr/io.h>
#include "scheduler.h"
#include "STD_Types.h"



// prototypes of tasks
void Task1(void);
void Task2(void);

#define LED1	7
#define LED0	2

void Task1(void)
{
    static uint8_t status = 0x01;
    if(status)
        PORTC |= (1<<LED0);
    else
        PORTC &= ~(1<<LED0);
    status = !status;
}


void Task2(void)
{
    static uint8_t status = 0x01;
    if( status )
        PORTC|= (1<<LED1);
    else
        PORTC &= ~(1<<LED1);
    status = !status;
}

void timer_Init(){
	 // use 1/8 of system clock frequency
	    TCCR0 = 0x03;//CS02 =0 CS01=1 CS00=1
	    // inital timer value = 0
	    TCNT0 = 0;
	    // enable Timer0 Overflow interrupt
	    TIMSK = (1<<0); //TOIE0=bit0
}
int main(void)
{

    // set LED0 bit0 and LED1 on AMIT kit as outputs
    DDRC = (1<<2)|(1<<7);
   // PORTC|=(1<<LED0);
    timer_Init();
    SchedulerInit();
    // add tasks, id is arbitrary
    // task1 runs every 1 second
    addTask(1, Task1, 10);

    // task2 runs every 4 seconds
    addTask(2, Task2, 40);

    // enable all interrupts
    sei();
    for(;;){
    	//Task1();
    	dispatchTasks();
    }
    return 0; // will never reach here
}

