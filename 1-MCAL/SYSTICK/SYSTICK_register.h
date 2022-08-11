/*
 * SYSTICK_register.h
 *
 *  Created on: 11 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef SYSTICK_REGISTER_H_
#define SYSTICK_REGISTER_H_


typedef struct{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}SYSTICK_t;

#define SYSTICK_BASE_ADDRESS		0xE000E010

#define SYSTICK			((volatile SYSTICK_t *)SYSTICK_BASE_ADDRESS)

#define SYSTICK_CTRL_COUNTFLAG	16
#define SYSTICK_CTRL_CLKSOURCE	2
#define SYSTICK_CTRL_TICKINT	1
#define SYSTICK_CTRL_ENABLE		0


#endif /* SYSTICK_REGISTER_H_ */
