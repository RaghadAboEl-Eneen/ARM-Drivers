/*
 * OS_private.h
 *
 *  Created on: 14 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef OS_PRIVATE_H_
#define OS_PRIVATE_H_


typedef struct {

	u8 Periodicity;
	u8 InitialDelay;
	u8 TaskID;
	u8 State;
	u8 SuspendTime;
	void(*Fptr)(void);

}Task;


void Scheduler(void);



#endif /* OS_PRIVATE_H_ */
