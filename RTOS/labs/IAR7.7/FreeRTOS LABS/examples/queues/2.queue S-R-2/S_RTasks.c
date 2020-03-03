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
  portBASE_TYPE xStatus;
  const portTickType xTicksToWait = 100 / portTICK_RATE_MS;
  /* As per most tasks, this task is implemented within an infinite loop. */
  for( ;; )
  {
    /* Send to the queue.
    The second parameter is the address of the structure being sent. The
    address is passed in as the task parameter so pvParameters is used
    directly.
    The third parameter is the Block time - the time the task should be kept
    in the Blocked state to wait for space to become available on the queue
    if the queue is already full. A block time is specified because the
    sending tasks have a higher priority than the receiving task so the queue
    is expected to become full. The receiving task will on execute and remove
    items from the queue when both sending tasks are in the Blocked state. */
    xStatus = xQueueSendToBack( xQueue, pvParameters, xTicksToWait );
    if( xStatus != pdPASS )
    {
      /* The send operation could not complete, even after waiting for 100ms.
      This must be an error as the receiving task should make space in the
      queue as soon as both sending tasks are in the Blocked state. */
      uart_write_string( "Could not send to the queue.\r\n" );
    }

  /* Allow the other sender task to execute. */
  taskYIELD();
  }
}


void vReceiverTask( void *pvParameters )
{
  /* Declare the structure that will hold the values received from the queue. */
  xData xReceivedStructure;
  portBASE_TYPE xStatus;
  /* This task is also defined within an infinite loop. */
  for( ;; )
  {
    /* Because it has the lowest priority this task will only run when the
    sending tasks are in the Blocked state. The sending tasks will only enter
    the Blocked state when the queue is full so this task always expects the
    number of items in the queue to be equal to the queue length – 3 in this
    case. */
    if( uxQueueMessagesWaiting( xQueue ) != 3 )
    {
      uart_write_string( "Queue should have been full!\r\n" );
    }
    /* Receive from the queue.
    The second parameter is the buffer into which the received data will be
    placed. In this case the buffer is simply the address of a variable that
    has the required size to hold the received structure.
    The last parameter is the block time - the maximum amount of time that the
    task will remain in the Blocked state to wait for data to be available
    if the queue is already empty. In this case a block time is not necessary
    because this task will only run when the queue is full. */
    xStatus = xQueueReceive( xQueue, &xReceivedStructure, 0 );
    if( xStatus == pdPASS )
    {
      /* Data was successfully received from the queue, print out the received
      value and the source of the value. */
      if( xReceivedStructure.ucSource == SENDER_1 )
      {
        uart_write_string("\x1B[32mReceived From Sender 1 = ");
        uart_write_int( xReceivedStructure.ucValue );
        uart_write_string("\r\n");
      }
      else
      {
        uart_write_string("\x1B[31mReceived From Sender 2 = ");
        uart_write_int( xReceivedStructure.ucValue );
        uart_write_string("\r\n");
      }
    }
    else
    {
      /* Nothing was received from the queue. This must be an error
      as this task should only run when the queue is full. */
      uart_write_string( "Could not receive from the queue.\r\n" );
    }
  }
}

void task( void *pvParameters )
{
  xData xReceivedStructure;
  for(;;)
  {
  xQueueReceive( xQueue, &xReceivedStructure, 10);
  asm("NOP");
  }
}
