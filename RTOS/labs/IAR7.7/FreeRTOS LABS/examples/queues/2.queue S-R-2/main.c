
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


/* Declare two variables of type xData that will be passed on the queue. */
static const xData xStructsToSend[ 2 ] =
{
  { 100, SENDER_1 }, /* Used by Sender1. */
  { 200, SENDER_2 } /* Used by Sender2. */
};
/* Declare a variable of type xQueueHandle. This is used to store the reference
to the queue that is accessed by all three tasks. */
xQueueHandle xQueue;

int main( void )
{
  uart_init(9600,F_CPU);
  /* The queue is created to hold a maximum of 3 structures of type xData. */
  xQueue = xQueueCreate( 3, sizeof( xData ) );
  if( xQueue != NULL )
  {
    /* Create two instances of the task that will write to the queue. The
    parameter is used to pass the structure that the task will write to the
    queue, so one task will continuously send xStructsToSend[ 0 ] to the queue
    while the other task will continuously send xStructsToSend[ 1 ]. Both
    tasks are created at priority 2 which is above the priority of the receiver. */
    xTaskCreate( task, "reciever2", 100, NULL, 3, NULL );
    xTaskCreate( vSenderTask, "Sender1", 100, (void *)&( xStructsToSend[ 0 ] ), 2, NULL );
    xTaskCreate( vSenderTask, "Sender2", 100, (void *)&( xStructsToSend[ 1 ] ), 2, NULL );
    /* Create the task that will read from the queue. The task is created with
    priority 1, so below the priority of the sender tasks. */
    xTaskCreate( vReceiverTask, "Receiver", 1000, NULL, 1, NULL );
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