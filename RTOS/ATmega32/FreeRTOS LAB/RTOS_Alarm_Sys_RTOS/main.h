/*
 * main.h
 *
 *  Created on: Mar 28, 2015
 *      Author: akobyljanec
 */

#ifndef MAIN_H_
#define MAIN_H_

// System clock rate, 8 MHz
 #define F_CPU (8000000UL)

typedef enum
{
	Welcome,
	Recieving,
	Submit
}LCD_State_t;

#define NOTPRESSED  (0xFF)

void vButtonTask(void *p); 
void vLEDTask(void *p);

#endif /* MAIN_H_ */
