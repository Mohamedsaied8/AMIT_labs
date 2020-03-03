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

/* Declare a variable that will be incremented by the hook function. */
unsigned long ulIdleCycleCount = 0UL;
/* Idle hook functions MUST be called vApplicationIdleHook(), take no parameters,
and return void. */
void vApplicationIdleHook( void )
{
  /* This hook function does nothing but increment a counter. */
  ulIdleCycleCount++;
}
