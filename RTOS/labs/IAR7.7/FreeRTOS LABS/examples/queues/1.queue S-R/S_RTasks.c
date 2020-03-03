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

extern xQueueHandle xQueue;

void vSenderTask( void *pvParameters )
{
  long lValueToSend;
  portBASE_TYPE xStatus;
  /* Two instances of this task are created so the value that is sent to the
  queue is passed in via the task parameter - this way each instance can use
  a different value. The queue was created to hold values of type long,
  so cast the parameter to the required type. */
  lValueToSend = ( long ) pvParameters;
  /* As per most tasks, this task is implemented within an infinite loop. */
  for( ;; )
  {
    /* Send the value to the queue.
    The first parameter is the queue to which data is being sent. The
    queue was created before the scheduler was started, so before this task
    started to execute.
    The second parameter is the address of the data to be sent, in this case
    the address of lValueToSend.
    The third parameter is the Block time – the time the task should be kept
    in the Blocked state to wait for space to become available on the queue
    should the queue already be full. In this case a block time is not
    specified because the queue should never contain more than one item and
    therefore never be full. */
    xStatus = xQueueSendToBack( xQueue, &lValueToSend, 0 );
    if( xStatus != pdPASS )
    {
      /* The send operation could not complete because the queue was full -
      this must be an error as the queue should never contain more than
      one item! */
      uart_write_string( "Could not send to the queue.\r\n" );
    }
    /* Allow the other sender task to execute. taskYIELD() informs the
    scheduler that a switch to another task should occur now rather than
    keeping this task in the Running state until the end of the current time
    slice. */
    taskYIELD();
  }
}

void vReceiverTask( void *pvParameters )
{
  /* Declare the variable that will hold the values received from the queue. */
  long lReceivedValue;
  portBASE_TYPE xStatus;
  const portTickType xTicksToWait = 100 / portTICK_RATE_MS;
  /* This task is also defined within an infinite loop. */
  for( ;; )
  {
    /* This call should always find the queue empty because this task will
    immediately remove any data that is written to the queue. */
    if( uxQueueMessagesWaiting( xQueue ) != 0 )
    {
      uart_write_string( "Queue should have been empty!\r\n" );
    }
    /* Receive data from the queue.
    The first parameter is the queue from which data is to be received. The
    queue is created before the scheduler is started, and therefore before this
    task runs for the first time.
    The second parameter is the buffer into which the received data will be
    placed. In this case the buffer is simply the address of a variable that
    has the required size to hold the received data.
    The last parameter is the block time – the maximum amount of time that the
    task should remain in the Blocked state to wait for data to be available
    should the queue already be empty. In this case the constant
    portTICK_RATE_MS is used to convert 100 milliseconds to a time specified in
    ticks. */
    xStatus = xQueueReceive( xQueue, &lReceivedValue, xTicksToWait );
    if( xStatus == pdPASS )
    {
      /* Data was successfully received from the queue, print out the received
      value. */
      if(lReceivedValue==100)
      {
        uart_write_string("\x1B[31mReceived = ");
      }
      else 
      {
        uart_write_string("\x1B[32mReceived = ");
      }
      uart_write_int( lReceivedValue );
      uart_write_string("\r\n");
    }
    else
    {
      /* Data was not received from the queue even after waiting for 100ms.
      This must be an error as the sending tasks are free running and will be
      continuously writing to the queue. */
      uart_write_string( "Could not receive from the queue.\r\n" );
    }
  }
}