/*
 * EXTI_register.h
 *
 *  Created on: 11 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define EXTI_BASE_ADDRESS		0x40010400

typedef struct{

	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;

}EXTI_t;

#define EXTI		((volatile EXTI_t*)EXTI_BASE_ADDRESS)


#endif /* EXTI_REGISTER_H_ */
