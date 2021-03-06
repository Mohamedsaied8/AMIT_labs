#include "Reg.h"
#include "DIO.h"
#include "Types.h"
#include "PLL.h"
/* FreeRTOS*/
#include "FreeRTOS.h"
#include "task.h"
#define STACKSIZE        128

void vLED1(void *pvParameters)
{
	while(1)
	{
		DIO_PortWrite(PortF,Pin1,DIO_HIGH);
		vTaskDelay( 100 );
		DIO_PortWrite(PortF,Pin1,DIO_LOW);
		vTaskDelay( 100 );

	}

}
void vLED2(void *pvParameters)
{
	uint8_t state = DIO_LOW;
	TickType_t xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();
	while(1)
	{
		DIO_PortWrite(PortF,Pin2,state);
		state ^= 0xFF;
		vTaskDelayUntil( &xLastWakeTime, 1000);

	}
}
int main(void) {
	PLL_Set80();
	DIO_PortInit(PortF,Pin1|Pin2|Pin3, 0);
	DIO_PortDirection(PortF , Pin1|Pin2|Pin3, DIO_OUTPUT);

	TaskHandle_t  First_handle,Second_handle;
	xTaskCreate(vLED1, "LED1",STACKSIZE, NULL,1, &First_handle);
	xTaskCreate(vLED2, "LED2",STACKSIZE, NULL,2, &Second_handle);
    vTaskStartScheduler();
    while(1);
	return 0;
}
