/*
 * scheduler.h
 *
 *  Created on: Apr 16, 2020
 *      Author: Mohamed
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_
#include "STD_Types.h"
#include <avr/interrupt.h>
//16000000/64=250,000 means timer tick every 4us overflow in 4us*255=1ms =>100 cycle =102ms
#define TIME_SLICE	(392)

#define TASKS_MAX	(5)

typedef enum{
	READY,
	RUNNING,
	STOPPED,
	ERROR
}status_t;

typedef void (*task_t)(void);

typedef struct{
uint8_t id;
task_t task;
uint16_t delay,period;
status_t status;
}tcp_t;

//prototypes
void SchedulerInit();
void addTask(uint8_t id,task_t task,uint16_t period);
void deleteTask(uint8_t id);
status_t getStatus(uint8_t id);
void dispatchTasks();

#endif /* SCHEDULER_H_ */
