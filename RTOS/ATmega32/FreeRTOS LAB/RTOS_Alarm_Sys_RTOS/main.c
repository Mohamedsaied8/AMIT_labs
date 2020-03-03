/*
 * FreeRTOS_TaskCreation.c
 *
 * Created: 10/19/2016 12:12:58 AM
 * Author : Master
 */ 

#include "main.h"
#include <util/delay.h>
#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h" //
#include "semphr.h"
#include "queue.h"
#include "keypad.h"
#include "LCD_Lib.h"
#include <string.h>
#include "app_tasks.h"

xQueueHandle button_queue;

extern xQueueHandle LCD_Queue;
extern xSemaphoreHandle CheckPasswordSemaphore;

int main()
{
	/*LCD_Initialization();
	LCD_Write_String("Hello");
	LCD_Queue = xQueueCreate(10,sizeof(char)); //10 bytes size 
	CheckPasswordSemaphore = xSemaphoreCreateBinary();
	*/
		button_queue = xQueueCreate(5,sizeof(char));

	xTaskCreate(vButtonTask,"Button_Task",300,NULL,1,NULL);
	xTaskCreate(vLEDTask,"LED_Task",300,NULL,1,NULL);
	 
	/*
	xTaskCreate( vTask_LCD,"LCD",200,NULL, 1, NULL );
	xTaskCreate( vTask_KeyPad, "Keypad",200,NULL, 2, NULL );
	xTaskCreate( vTask_Password_Check, "check",200,NULL, 3, NULL );
	*/

		DDRC|=(1<<7);

	//PORTC|=(1<<7);
	vTaskStartScheduler();
	

	while(1);
}
#define GET_BIT(var,bit)	((var>>bit)&1)

void vButtonTask(void *p){
	
	DDRB&=~(1<<0); 
	DDRC|=(1<<7);
	char data=0;
	while(1){
	data=GET_BIT(PINB,0);
	if(data==1){
		_delay_ms(25);//debounce time
		//queue send
			xQueueSendToBack(button_queue,&data,100/portTICK_PERIOD_MS);
		
	}//
	else{
	xQueueSendToBack(button_queue,&data,100/portTICK_PERIOD_MS);

	}
	vTaskDelay(100/portTICK_PERIOD_MS);
 }//while
	
}//function

//continous , periodic and sparodic
void vLEDTask(void *p){
	
	DDRC|=(1<<7);
	char value;
	
	while(1){
		//queue send
 xQueueReceive(button_queue,&value,100/portTICK_PERIOD_MS);//blocking | non-blocking
		if(value==1){
			PORTC^=(1<<7);
			_delay_ms(10);
			vTaskDelay(500/portTICK_PERIOD_MS);

		}//if
		else{
			PORTC&=~(1<<7);
		}
	}//while
}//