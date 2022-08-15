/*
 * OS_program.c
 *
 *  Created on: 14 Aug 2022
 *      Author: es-RaghadAly2023
 */

#include "STD_TYPES.h"

#include "SYSTICK_interface.h"
#include "SCB_interface.h"


#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

Task OS_Tasks[OS_NUMBER_OF_TASKS];
u32 TickCount = 0;

/**
 *
 */
void Scheduler(void){

	for(u8 i = 0; i < OS_NUMBER_OF_TASKS; i++){
		if((OS_Tasks[i].State == OS_TASK_READY)){
			if(OS_Tasks[i].InitialDelay == 0){
				OS_Tasks[i].InitialDelay = OS_Tasks[i].Periodicity-1;
				OS_Tasks[i].Fptr();
			}else{
				OS_Tasks[i].InitialDelay--;
			}
		}
	}
	TickCount++;
}



/**
 *
 * @param Copy_u8ID
 * @param Copy_u8Periodicity
 * @param Copy_u8InitialDelay
 * @param ptr
 */
void OS_voidCreateTask(u8 Copy_u8ID, u8 Copy_u8Periodicity, u8 Copy_u8InitialDelay, void (*ptr)(void)){

	OS_Tasks[Copy_u8ID].Fptr = ptr;
	OS_Tasks[Copy_u8ID].InitialDelay = Copy_u8InitialDelay;
	OS_Tasks[Copy_u8ID].Periodicity = Copy_u8Periodicity;
	OS_Tasks[Copy_u8ID].State = OS_TASK_READY;
	OS_Tasks[Copy_u8ID].TaskID= Copy_u8ID;

}


/**
 *
 * @param Copy_u8ID
 */
void OS_voidDeleteTask(u8 Copy_u8ID){

	OS_Tasks[Copy_u8ID].State = OS_TASK_DELETED;

}

/**
 *
 * @param Copy_u8ID
 * @param Copy_u8SuspensionTime
 */
void OS_voidSuspendTask(u8 Copy_u8ID, u8 Copy_u8SuspendTime){

	OS_Tasks[Copy_u8ID].State = OS_TASK_SUSPENDED;
	OS_Tasks[Copy_u8ID].SuspendTime = Copy_u8SuspendTime + TickCount;

}

/**
 *
 */
void OS_voidStartScheduler(void){

	STK_voidInit(SYSTICK_AHB_8);
	Scheduler();
	STK_voidSetPeriodicInterval(OS_TICK_TIME, Scheduler);

}

/**
 *
 * @param Copy_u8ID
 */
void OS_voidResumeTask(u8 Copy_u8ID){

	OS_Tasks[Copy_u8ID].State = OS_TASK_READY;

}

/**
 *
 * @param Copy_u8ID
 * @return
 */
u8 OS_u8GetTaskState(u8 Copy_u8ID){

	return OS_Tasks[Copy_u8ID].State;

}
