
/* config includes. */
#include "FreeRTOSConfig.h"

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Drivers includes. */
#include "uart.h"

/* APP includes. */
#include "print_task.h"


int main()
{
  uart_init(9600,16000000);
  /* Create one of the two tasks. */
  /* Create the first task at priority 1. The priority is the second to last parameter. */
  xTaskCreate( vPeriodicTask, "periodic", 1000, NULL, 2, NULL );
  /* Create the second task at priority 2. */
  xTaskCreate( vContinuousProcessingTask, "continous", 1000,NULL, 1, NULL );
  /* Start the scheduler so the tasks start executing. */
  vTaskStartScheduler();
   for( ;; );

}

