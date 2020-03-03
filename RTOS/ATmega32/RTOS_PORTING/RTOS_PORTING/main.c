/*
 * RTOS_PORTING.c
 *
 * Created: 12/28/2019 7:06:53 PM
 * Author : Mohamed
 * LED0 PC2 100ms
 * LED1 PC7 200ms
 * LED2 PD3 50 ms
 */ 

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
//prototypes
void LED0_Task(void *p);
void LED1_Task(void *p);
void LED2_Task(void *p);
int main(void)
{
	xTaskCreate(LED0_Task,"LED0_Periodic",300,NULL,3,NULL);
	xTaskCreate(LED1_Task,"LED0_Periodic",300,NULL,3,NULL);
	xTaskCreate(LED2_Task,"LED0_Periodic",300,NULL,3,NULL);

	vTaskStartScheduler();
    while (1) 
    {
    }
}

void LED0_Task(void *p){
	DDRC|=(1<<2);
	while(1){
	
	PORTC^=(1<<2);
	vTaskDelay(200/portTICK_PERIOD_MS);
	}
}
void LED1_Task(void *p){
	DDRC|=(1<<7);
	while(1){
		
		PORTC^=(1<<7);
		vTaskDelay(100/portTICK_PERIOD_MS);
	}
}
void LED2_Task(void *p){
	
	DDRD|=(1<<3);
	while(1){
		
		PORTD^=(1<<3);
		vTaskDelay(50/portTICK_PERIOD_MS);
	}
}