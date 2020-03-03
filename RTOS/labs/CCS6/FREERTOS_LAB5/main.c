#include <stdint.h>
#include "Reg.h"
#include "DIO.h"
#include "Types.h"
#include "PLL.h"
#include "UART.h"
/* FreeRTOS*/
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#define TASKSTACKSIZE        128


SemaphoreHandle_t Client_Sem;
volatile uint8_t data1 = 0 ;
void vButtonTask(void * para)
{
	uint8_t flag_low = Pin0 ; //to work on falling edge
	while(1)
	{
		DIO_PortRead(PortF,Pin0,&data1);
		if((data1 == DIO_LOW) && (flag_low == Pin0)) //active low , if button is pressed , and last time was high
		{
            if( xSemaphoreGive(Client_Sem) != pdTRUE )
            {
            }
		}
		flag_low = data1;
	}

}


void vServerTask(void * para)
{
	Client_Sem = xSemaphoreCreateBinary();
	xSemaphoreTake( Client_Sem, (TickType_t)0 ); //intilaize it
	uint32_t i = 0;
	TaskHandle_t client_task =  xTaskGetHandle("Button");
	while(1)
	{
		xSemaphoreTake( Client_Sem, (TickType_t)portMAX_DELAY );
		UART0_SendString("Client number ");
		UART0_SendInt(++i);
		UART0_SendString(" Served!");
		UART0_Println();

	}
}

int main(void) {
	PLL_Set80();
	UART0_Init(115200,80000000);
	DIO_PortInit(PortF, Pin0|Pin1|Pin2|Pin3|Pin4 , Pin0|Pin4);
	DIO_PortDirection(PortF , Pin1|Pin2|Pin3, DIO_OUTPUT);
	DIO_PortDirection(PortF , Pin0|Pin4, DIO_INPUT);

	TaskHandle_t  First_handle,Second_handle;
	xTaskCreate(vButtonTask, "Button",TASKSTACKSIZE, NULL,1, &First_handle);
	xTaskCreate(vServerTask, "Server",TASKSTACKSIZE, NULL,2, &Second_handle);

	vTaskStartScheduler();
	return 0;
}
