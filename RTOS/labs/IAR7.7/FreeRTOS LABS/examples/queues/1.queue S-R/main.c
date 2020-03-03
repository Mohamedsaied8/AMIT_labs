
/* config includes. */
#include "FreeRTOSConfig.h"

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/* Drivers includes. */
#include "uart.h"

/* APP includes. */
#include "S_RTasks.h"

#define F_CPU   16000000U

//static const char *pcTextForTask1 = "\x1B[32m Task 1 is running\r\n";
//static const char *pcTextForTask2 = "\x1B[33m Task 2 is running\r\n";

/* Declare a variable of type xQueueHandle. This is used to store the reference
to the queue that is accessed by all three tasks. */
xQueueHandle xQueue;

int main( void )
{
  uart_init(9600,F_CPU);
  /* The queue is created to hold a maximum of 5 values, each of which is
  large enough to hold a variable of type long. */
  xQueue = xQueueCreate( 1, sizeof( long ) );
  if( xQueue != NULL )
  {
    /* Create two instances of the task that will send to the queue. The task
    parameter is used to pass the value that the task will write to the queue,
    so one task will continuously write 100 to the queue while the other task
    will continuously write 200 to the queue. Both tasks are created at
    priority 1. */
    xTaskCreate( vSenderTask, "Sender1", 100, ( void * ) 100, 1, NULL );
    xTaskCreate( vSenderTask, "Sender2", 100, ( void * ) 200, 1, NULL );
    /* Create the task that will read from the queue. The task is created with
    priority 2, so above the priority of the sender tasks. */
    xTaskCreate( vReceiverTask, "Receiver", 100, NULL, 2, NULL );
    /* Start the scheduler so the created tasks start executing. */
    vTaskStartScheduler();
  }
  else
  {
    /* The queue could not be created. */
  }
  /* If all is well then main() will never reach here as the scheduler will
  now be running the tasks. If main() does reach here then it is likely that
  there was insufficient heap memory available for the idle task to be created.
  CHAPTER 5 provides more information on memory management. */
  for( ;; );
}