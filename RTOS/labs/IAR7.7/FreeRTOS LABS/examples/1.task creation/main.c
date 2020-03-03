
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
  /* Create one of the two tasks. Note that a real application should check
  the return value of the xTaskCreate() call to ensure the task was created
  successfully. */
  xTaskCreate( vTask1, /* Pointer to the function that implements the task. */
              "Task 1",/* Text name for the task. This is to facilitate debugging
              only. */
              1000, /* Stack depth - most small microcontrollers will use much
              less stack than this. */
              NULL, /* We are not using the task parameter. */
              1, /* This task will run at priority 1. */
              NULL ); /* We are not going to use the task handle. */
   /* Create the other task in exactly the same way and at the same priority. */
  xTaskCreate( vTask2, "Task 2", 1000, NULL, 1, NULL );
  /* Start the scheduler so the tasks start executing. */
  vTaskStartScheduler();

  for( ;; );
}

