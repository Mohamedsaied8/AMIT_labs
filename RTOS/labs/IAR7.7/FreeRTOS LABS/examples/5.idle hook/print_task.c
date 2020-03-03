/* config includes. */
#include "FreeRTOSConfig.h"

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Drivers includes. */
#include "uart.h"

/* APP includes. */
#include "print_task.h"
#include "idlehook.h"

extern unsigned long ulIdleCycleCount;

void vTaskFunction( void *pvParameters )
{
  char *pcTaskName;
  portTickType xLastWakeTime;
  pcTaskName = ( char * ) pvParameters;

  xLastWakeTime = xTaskGetTickCount();
/* As per most tasks, this task is implemented in an infinite loop. */
  for( ;; )
   {
    /* Print out the name of this task. */
    uart_write_string( pcTaskName );
    uart_write_int(  ulIdleCycleCount );
    /* Delay for a period. */
    vTaskDelayUntil(&xLastWakeTime,(250/portTICK_RATE_MS));
  }
}


  