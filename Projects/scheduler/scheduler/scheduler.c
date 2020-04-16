/*
 * scheduler.c
 *
 *  Created on: Apr 16, 2020
 *      Author: Mohamed
 */

#include "STD_Types.h"
#include "scheduler.h"
volatile uint16_t count=0;

//create task list
tcp_t task_list[TASKS_MAX];

/*
 * TIMER0 Interrupt Service Routine(ISR)
 */
//16000000/64=250000hz=>4us*255=1020=1ms=>100
ISR(TIMER0_OVF_vect){
	count++;
	if(count==100){
		count=0;
		for(uint8_t i=0;i<TASKS_MAX;i++){
			if(task_list[i].status==READY)
			{
				task_list[i].delay--;
			}//if
		}//for
	}//if
}//ISR

/*
 * Initialize Scheduler all task parameters are zeros for all tasks
 *
 */
void SchedulerInit(){

	for(uint8_t i=0;i<TASKS_MAX;i++){
		task_list[i].id=0;
		task_list[i].task=(task_t)0x00;
		task_list[i].delay=0;
		task_list[i].period=0;
		task_list[i].status=STOPPED;
	}
}
/*
 * add task to the task list
 * find the next empty id and then place the task parameters
 */
void addTask(uint8_t id,task_t task,uint16_t period){
		uint8_t done=0;
		for(uint8_t idx=0;idx<TASKS_MAX;idx++)
		{
			if(task_list[idx].status==STOPPED)
			{
				task_list[idx].id=id;
				task_list[idx].task=task;
				task_list[idx].delay=period;
				task_list[idx].period=period;
				task_list[idx].status=READY;
				done=1;
			}
			if(done!=0)break;
		}
}

/*
 * deleteTask
 * find the id of the task
 * change status to be STOPPED
 */
 void delteTask(uint8_t id){
	 for(uint8_t idx=0;idx<TASKS_MAX;idx++)
	 		{
	 			if(task_list[idx].id==id)
	 			{
	 				task_list[idx].status=STOPPED;
	 				break;
	 			}
	 		}

 }
 /*
  * Get Status of a Task
  * find the ID of a Task return the status
  */
 status_t getStatus(uint8_t id){
	 for(uint8_t idx=0;idx<TASKS_MAX;idx++)
	 {
		 if(task_list[idx].id==id)
		 return task_list[idx].status;
	 }
	 return ERROR;
 }
/*
 * Dispatch
 *
 */
void dispatchTasks(){
	 for(uint8_t idx=0;idx<TASKS_MAX;idx++)
	 	{
		 if(!task_list[idx].delay && task_list[idx].status==READY){
			 //make the status is running
		 		task_list[idx].status=RUNNING;
			 //call the task function
		 		(*task_list[idx].task)();
		 		//Reset period
		 		task_list[idx].delay=task_list[idx].period;
			 //change the status again to be READY after function finishes
		 		task_list[idx].status=READY;
		 }
	 	}
}
