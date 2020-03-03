
/* config includes. */
#include "FreeRTOSConfig.h"

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Drivers includes. */
#include "uart.h"

/* APP includes. */
#include "print_task.h"


static const char *pcTextForTask1 = "\x1B[32m Task 1 is running\r\n";
static const char *pcTextForTask2 = "\x1B[33m Task 2 is running\r\n";

/* Declare a variable that is used to hold the handle of Task2. */
xTaskHandle xTask2Handle;

int main( void )
{
  /* Create the first task at priority 2. The task parameter is not used
  and set to NULL. The task handle is also not used so is also set to NULL. */
  xTaskCreate( vTask1, "Task 1", 1000, (void *)pcTextForTask1, 2, NULL );
  /* The task is created at priority 2 ______^. */
  /* Create the second task at priority 1 - which is lower than the priority
  given to Task1. Again the task parameter is not used so is set to NULL -
  BUT this time the task handle is required so the address of xTask2Handle
  is passed in the last parameter. */
  xTaskCreate( vTask2, "Task 2", 1000, (void *)pcTextForTask2, 1, &xTask2Handle );
  /* The task handle is the last parameter _____^^^^^^^^^^^^^ */
  /* Start the scheduler so the tasks start executing. */
  vTaskStartScheduler();
  
  for( ;; );
}