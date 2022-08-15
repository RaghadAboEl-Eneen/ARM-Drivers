/*
 * OS_interface.h
 *
 *  Created on: 14 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_


#define OS_TASK_DELETED			2
#define OS_TASK_READY			1
#define OS_TASK_SUSPENDED		0





void OS_voidCreateTask(u8 Copy_u8ID, u8 Copy_u8Periodicity, u8 Copy_u8InitialDelay, void (*ptr)(void));

void OS_voidDeleteTask(u8 Copy_u8ID);

void OS_voidSuspendTask(u8 Copy_u8ID, u8 Copy_u8SuspensionTime);

void OS_voidStartScheduler(void);

void OS_voidResumeTask(u8 Copy_u8ID);

u8 OS_u8GetTaskState(u8 Copy_u8ID);



#endif /* OS_INTERFACE_H_ */
