/*
 * EXTI_interface.h
 *
 *  Created on: 11 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


#define EXTI_ENABLE		1
#define EXTI_DISABLE	0

#define EXTI_RISING_TRIGGER		0
#define EXTI_FALLING_TRIGGER	1
#define EXTI_BOTH_TRIGGER		2

/*
 * Configures the trigger signal EXTI for a certain line
 */
void EXTI_voidSelectTrig(u8 Copy_u8EXTI_line, u8 Copy_u8Selection);

/*
 * Configures the trigger signal EXTI for a certain line
 */
void EXTI_voidControlLine(u8 Copy_u8EXTI_line, u8 Copy_u8State);

/*
 * EXTI_voidSW_interrupt
 */
void EXTI_voidSW_interrupt(u8 Copy_u8EXTI_line);

/*
 * Clearing the xPIF for EXTI for a certain line
 */
void EXTI_voidClearFlag(u8 Copy_u8EXTI_line);



#endif /* EXTI_INTERFACE_H_ */
