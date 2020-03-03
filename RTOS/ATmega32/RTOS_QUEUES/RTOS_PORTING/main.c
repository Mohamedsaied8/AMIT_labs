/*
 * main.c
 *
 *  Created on: Feb 11, 2020
 *      Author: ThinkPad
 */
#include "FreeRtos.h"
#include "task.h"
#include "queue.h"
#include <avr/io.h>


xQueueHandle xQueue;

//*****************************
void count(void *p)
{
	unsigned char xStatus;
	static int count=0;
	DDRD &=~(1<<2);

while(1)
{
	if(PIND &(1<<2))



	{
		if(count==10)
		{
			count =0;
		}
		else
		{
			count ++;

		}
		//xStatus = xQueueSendToBack(xQueue,&count,200);

	}

  xStatus = xQueueSendToBack(xQueue,&count,20);
  vTaskDelay(100);
}


	//if (xStatus !=PdPASS)
	//{
		//vPrintString("could not send to queue");
	//}
	//queue send



}
void led(void *p)
{
	unsigned char xStatus;
	int receivedvalue;
	 DDRC|=(1<<2);
	 DDRC|=(1<<7);
	 PORTC&=~(1<<2);
	 PORTC&=~(1<<7);

	 while(1)
	 {
		 //queue receive
		 xStatus = xQueueReceive(xQueue,&receivedvalue,portMAX_DELAY);
		 if(receivedvalue <= 5)
		 {
			PORTC |=(1<<2);
			 PORTC &=~(1<<7);

		 }
		 else if(receivedvalue >5)
		 {
			 PORTC |=(1<<7);
			 PORTC &=~(1<<2);
		 }
		

		 
		 vTaskDelay(50);

}//end while

}//end led
//******************************
 int main()

 {

	xQueue = xQueueCreate(3,sizeof(int));
	if(xQueue != NULL)
	{
		xTaskCreate(count,"count1",240,(void*)100,1,NULL);
		xTaskCreate(led,"led1",240,(void*)100,1,NULL);

		vTaskStartScheduler();

	}
	else
	{

	}
	while(1);


return 0;

 }
