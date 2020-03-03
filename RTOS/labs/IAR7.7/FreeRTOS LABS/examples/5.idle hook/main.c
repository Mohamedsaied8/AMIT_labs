
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
/* Define the strings that will be passed in as the task parameters. These are
defined const and not on the stack to ensure they remain valid when the tasks are
executing. */
static const char *pcTextForTask1 = "\r\n\x1B[32m Task 1 is running, ulIdleCycleCount= ";
static const char *pcTextForTask2 = "\r\n\x1B[33m Task 2 is running, ulIdleCycleCount= ";

int main()
{
  uart_init(9600,16000000);
  /* Create one of the two tasks. */
  /* Create the first task at priority 1. The priority is the second to last parameter. */
  xTaskCreate( vTaskFunction, "task 1", 1000, (void *)pcTextForTask1, 2, NULL );
  /* Create the second task at priority 2. */
  xTaskCreate( vTaskFunction, "task 2", 1000,(void *)pcTextForTask2, 1, NULL );
  /* Start the scheduler so the tasks start executing. */
  vTaskStartScheduler();
   for( ;; );

}

