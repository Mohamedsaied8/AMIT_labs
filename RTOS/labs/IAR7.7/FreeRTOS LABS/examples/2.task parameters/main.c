
/* config includes. */
#include "FreeRTOSConfig.h"

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Drivers includes. */
#include "uart.h"

/* APP includes. */
#include "print_task.h"

/* Define the strings that will be passed in as the task parameters. These are
defined const and not on the stack to ensure they remain valid when the tasks are
executing. */
static const char *pcTextForTask1 = "\x1B[32m Task 1 is running\r\n";
static const char *pcTextForTask2 = "\x1B[33m Task 2 is running\r\n";

int main()
{
  uart_init(9600,16000000);
  /* Create one of the two tasks. */
  xTaskCreate( vTaskFunction, /* Pointer to the function that implements the task. */
                "Task 1", /* Text name for the task. This is to
                facilitate debugging only. */
                1000, /* Stack depth - most small microcontrollers
                will use much less stack than this. */
                (void*)pcTextForTask1, /* Pass the text to be printed into the task
                using the task parameter. */
                1, /* This task will run at priority 1. */
                NULL ); /* We are not using the task handle. */
  
    /* Create the other task in exactly the same way. Note this time that multiple
    tasks are being created from the SAME task implementation (vTaskFunction). Only
    the value passed in the parameter is different. Two instances of the same
    task are being created. */
    xTaskCreate( vTaskFunction, "Task 2", 1000, (void*)pcTextForTask2, 2, NULL );
    /* Start the scheduler so our tasks start executing. */
    vTaskStartScheduler();
    /* If all is well then main() will never reach here as the scheduler will
    now be running the tasks. If main() does reach here then it is likely that
    there was insufficient heap memory available for the idle task to be created.
    CHAPTER 5 provides more information on memory management. */
    for( ;; );

}

