/*
 * SCB_register.h
 *
 *  Created on: 11 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef SCB_REGISTER_H_
#define SCB_REGISTER_H_

#define SCB_BASE_ADDRESS	0xE000ED00											/* System Control Block Base Address */


#define SCB_AIRCR			*((volatile u32 *) (SCB_BASE_ADDRESS+0x0C))			/*  Application Interrupt and Reset Control Register */


#endif /* SCB_REGISTER_H_ */
