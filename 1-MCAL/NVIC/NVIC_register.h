/*
 * NVIC_register.h
 *
 *  Created on: 9 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef NVIC_REGISTER_H_
#define NVIC_REGISTER_H_

#define NVIC_BASE_ADDRESS	0xE000E100

#define NVIC_ISER0			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x000))	/* NVIC Set Enable Register*/
#define NVIC_ISER1			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x004))

#define NVIC_ICER0			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x080))	/* NVIC Clear Enable Register*/
#define NVIC_ICER1			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x084))

#define NVIC_ISPR0			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x100))	/* NVIC Set Pending Register*/
#define NVIC_ISPR1			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x104))

#define NVIC_ICPR0			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x180))	/* NVIC Clear Pending Register*/
#define NVIC_ICPR1			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x184))

#define NVIC_IABR0			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x200))   /* NVIC Active Bit register*/
#define NVIC_IABR1			*((volatile u32 *) (NVIC_BASE_ADDRESS+0x204))

#define NVIC_IPR			((volatile u8 *) (NVIC_BASE_ADDRESS+0x300))

#define NVIC_STIR			*((volatile u32 *) (NVIC_BASE_ADDRESS+0xE00))


#endif /* NVIC_REGISTER_H_ */
