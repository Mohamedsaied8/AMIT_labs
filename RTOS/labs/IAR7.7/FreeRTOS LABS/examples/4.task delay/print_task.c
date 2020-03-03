/* config includes. */
#include "FreeRTOSConfig.h"

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Drivers includes. */
#include "uart.h"

/* APP includes. */
#include "print_task.h"



void vTaskFunction( void *pvParameters )
{
  char *pcTaskName;
  pcTaskName = ( char * ) pvParameters;

/* As per most tasks, this task is implemented in an infinite loop. */
  for( ;; )
   {
    /* Print out the name of this task. */
    uart_write_string( pcTaskName );
    /* Delay for a period. */
    vTaskDelay(1000/portTICK_RATE_MS);
  }
}

void vContinuousProcessingTask( void *pvParameters )
{

  /* As per most tasks, this task is implemented in an infinite loop. */
    for( ;; )
    {
    /* Print out the name of this task. This task just does this repeatedly
    without ever blocking or delaying. */
    uart_write_string( "\x1B[32m continous task is running\r\n" );
    }
}

void vPeriodicTask( void *pvParameters )
{
  portTickType xLastWakeTime;
  /* The xLastWakeTime variable needs to be initialized with the current tick
  count. Note that this is the only time the variable is explicitly written to.
  After this xLastWakeTime is managed automatically by the vTaskDelayUntil()
  API function. */
  xLastWakeTime = xTaskGetTickCount();
    /* As per most tasks, this task is implemented in an infinite loop. */
    for( ;; )
    {
    /* Print out the name of this task. */
    uart_write_string( "\x1B[31m Periodic task is running\r\n" );
    /* The task should execute every 10 milliseconds exactly. */
    vTaskDelayUntil( &xLastWakeTime, ( 1000 / portTICK_RATE_MS ) );
    }
}
