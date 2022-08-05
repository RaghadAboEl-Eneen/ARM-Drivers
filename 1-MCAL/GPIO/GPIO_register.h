/*
 * GPIO_register.h
 *
 *  Created on: 4 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef GPIO_REGISTER_H_
#define GPIO_REGISTER_H_


typedef struct{

	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR;
	volatile u32 LCKR;

}GPIO_Port_t;

#define GPIO_PORTA_BASE	 ((volatile GPIO_Port_t*) 0x40010800)
#define GPIO_PORTB_BASE   ((volatile GPIO_Port_t*) 0x40010C00)
#define GPIO_PORTC_BASE   ((volatile GPIO_Port_t*) 0x40011000)



#endif /* GPIO_REGISTER_H_ */
