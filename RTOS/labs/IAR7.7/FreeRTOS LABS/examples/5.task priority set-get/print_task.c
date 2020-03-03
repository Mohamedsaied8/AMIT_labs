/* config includes. */
#include "FreeRTOSConfig.h"

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Drivers includes. */
#include "uart.h"

/* APP includes. */
#include "print_task.h"

extern xTaskHandle xTask2Handle;

void vTask1( void *pvParameters )
{
  const char* pcTask;
  unsigned portBASE_TYPE uxPriority;
  /* This task will always run before Task2 as it is created with the higher
  priority. Neither Task1 nor Task2 ever block so both will always be in either
  the Running or the Ready state.
  Query the priority at which this task is running - passing in NULL means
  "return my priority". */
  pcTask = (char *)pvParameters;
  uxPriority = uxTaskPriorityGet( NULL );
    for( ;; )
    {
      /* Print out the name of this task. */
      uart_write_string( pcTask );
      /* Setting the Task2 priority above the Task1 priority will cause
      Task2 to immediately start running (as then Task2 will have the higher
      priority of the two created tasks). Note the use of the handle to task
      2 (xTask2Handle) in the call to vTaskPrioritySet(). Listing 24 shows how
      the handle was obtained. */
      uart_write_string( "About to raise the Task2 priority\r\n" );
      vTaskPrioritySet( xTask2Handle, ( uxPriority + 1 ) );
      /* Task1 will only run when it has a priority higher than Task2.
      Therefore, for this task to reach this point Task2 must already have
      executed and set its priority back down to below the priority of this
      task. */
    }
}


void vTask2( void *pvParameters )
{
  const char* pcTask;
  unsigned portBASE_TYPE uxPriority;
  /* Task1 will always run before this task as Task1 is created with the
  higher priority. Neither Task1 nor Task2 ever block so will always be
  in either the Running or the Ready state.
  Query the priority at which this task is running - passing in NULL means
  "return my priority". */
  pcTask = (char *)pvParameters;
  uxPriority = uxTaskPriorityGet( NULL );
    for( ;; )
    {
      /* For this task to reach this point Task1 must have already run and
      set the priority of this task higher than its own.
      Print out the name of this task. */
      uart_write_string(pcTask  );
      /* Set our priority back down to its original value. Passing in NULL
      as the task handle means "change my priority". Setting the
      priority below that of Task1 will cause Task1 to immediately start
      running again – pre-empting this task. */
      uart_write_string( "About to lower the Task2 priority\r\n" );
      vTaskPrioritySet( NULL, ( uxPriority - 2 ) );
    }
}