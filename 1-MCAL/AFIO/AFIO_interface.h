/*
 * AFIO_interface.h
 *
 *  Created on: 11 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef AFIO_INTERFACE_H_
#define AFIO_INTERFACE_H_


#define AFIO_PORTA				0
#define AFIO_PORTB				1
#define AFIO_PORTC				2
#define AFIO_PORTD				3
#define AFIO_PORTE				4
#define AFIO_PORTF				5
#define AFIO_PORTG				6

#define AFIO_EXTI0				0
#define AFIO_EXTI1				1
#define AFIO_EXTI2				2
#define AFIO_EXTI3				3
#define AFIO_EXTI4				4
#define AFIO_EXTI5				5
#define AFIO_EXTI6				6
#define AFIO_EXTI7				7
#define AFIO_EXTI8				8
#define AFIO_EXTI9				9
#define AFIO_EXTI10				10
#define AFIO_EXTI11				11
#define AFIO_EXTI12				12
#define AFIO_EXTI13				13
#define AFIO_EXTI14				14
#define AFIO_EXTI15				15



u8 AFIO_u8SetExternalInterruptSource(u8 Copy_u8Port, u8 Copy_u8Pin);




#endif /* AFIO_INTERFACE_H_ */
