/*
 * EXTI_program.c
 *
 *  Created on: 11 Aug 2022
 *      Author: es-RaghadAly2023
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_register.h"
#include "EXTI_config.h"


/*
 * Configures the trigger signal EXTI for a certain line
 */
void EXTI_voidSelectTrig(u8 Copy_u8EXTI_line, u8 Copy_u8Selection){
	switch(Copy_u8Selection){
	case EXTI_RISING_TRIGGER:
		SET_BIT(EXTI->RTSR, Copy_u8EXTI_line);
		CLR_BIT(EXTI->FTSR, Copy_u8EXTI_line);
	break;
	case EXTI_FALLING_TRIGGER:
		CLR_BIT(EXTI->RTSR, Copy_u8EXTI_line);
		SET_BIT(EXTI->FTSR, Copy_u8EXTI_line);
	break;
	case EXTI_BOTH_TRIGGER:
		SET_BIT(EXTI->RTSR, Copy_u8EXTI_line);
		SET_BIT(EXTI->FTSR, Copy_u8EXTI_line);
	break;
	}
}

/*
 * EXTI_voidSW_interrupt
 */
void EXTI_voidSW_interrupt(u8 Copy_u8EXTI_line){

	SET_BIT(EXTI->SWIER, Copy_u8EXTI_line);

}

/*
 * Configures the trigger signal EXTI for a certain line
 */
void EXTI_voidControlLine(u8 Copy_u8EXTI_line, u8 Copy_u8State){

	switch(Copy_u8State){

	case EXTI_ENABLE:
		SET_BIT(EXTI->IMR, Copy_u8EXTI_line);
		break;
	case EXTI_DISABLE:
		CLR_BIT(EXTI->IMR, Copy_u8EXTI_line);
		break;
	}
}

/*
 * Clearing the xPIF for EXTI for a certain line
 */
void EXTI_voidClearFlag(u8 Copy_u8EXTI_line){
		SET_BIT(EXTI->PR, Copy_u8EXTI_line);
}


