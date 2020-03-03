/* config includes. */
#include "FreeRTOSConfig.h"

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"

/* Drivers includes. */
#include "uart.h"

/* APP includes. */
#include "print_task.h"


void vTask1( void *pvParameters )
{
  const char *pcTaskName = "\x1B[31m Task 1 is running\r\n";
  volatile unsigned long ul;
  /* As per most tasks, this task is implemented in an infinite loop. */
  for( ;; )
  {
  /* Print out the name of this task. */
  uart_write_string( pcTaskName );
  /* Delay for a period. */
      for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
      {
      /* This loop is just a very crude delay implementation. There is
      nothing to do in here. Later examples will replace this crude
      loop with a proper delay/sleep function. */
      }
  }
}

void vTask2( void *pvParameters )
{
  const char *pcTaskName = "\x1B[32m Task 2 is running\r\n";
  volatile unsigned long ul;
  /* As per most tasks, this task is implemented in an infinite loop. */
  for( ;; )
  {
  /* Print out the name of this task. */
  uart_write_string( pcTaskName );
  /* Delay for a period. */
    for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
    {
    /* This loop is just a very crude delay implementation. There is
    nothing to do in here. Later examples will replace this crude
    loop with a proper delay/sleep function. */
    }
  }
}