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
  volatile unsigned long ul;
  /* The string to print out is passed in via the parameter. Cast this to a
  character pointer. */
  pcTaskName = ( char * ) pvParameters;
  /* As per most tasks, this task is implemented in an infinite loop. */
  for( ;; )
   {
    /* Print out the name of this task. */
    uart_write_string( pcTaskName );
    /* Delay for a period. */
      for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
                ;
  }
}
