#ifndef PRINT_TASK_H_
#define PRINT_TASK_H_

#define SENDER_1        1
#define SENDER_2        2

/* Define the structure type that will be passed on the queue. */
typedef struct
{
unsigned char ucValue;
unsigned char ucSource;
} xData;

void vSenderTask( void *pvParameters );
void vReceiverTask( void *pvParameters );
void task( void *pvParameters );
#endif  //PRINT_TASK_H_