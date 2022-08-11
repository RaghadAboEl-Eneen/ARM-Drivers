/*
 * NVIC_program.c
 *
 *  Created on: Aug 8, 2022
 *      Author:  es-RaghadAly2023
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_register.h"
#include "NVIC_config.h"




void NVIC_voidInit(void){

	//SCB_AIRCR = NVIC_PRIORITY_DISTRIBUTION;
}



/*
 * NVIC_voidEnableInterrupt
 * parameters:
 * description: Sets the NVIC enable pin for a specific interrupt
 */
void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptCode) {

	if (Copy_u8InterruptCode < 32) {
		NVIC_ISER0 = 1 << Copy_u8InterruptCode;
	} else if (Copy_u8InterruptCode < 60) {
		NVIC_ISER1 = 1 << (Copy_u8InterruptCode - 32);
	}
}

/*
 * NVIC_voidDisableInterrupt
 * parameters:
 * description: Sets the NVIC disable pin for a specific interrupt
 */
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptCode) {

	if (Copy_u8InterruptCode < 32) {
		NVIC_ICER0 = 1 << Copy_u8InterruptCode;
	} else if (Copy_u8InterruptCode < 60) {
		NVIC_ICER1 = 1 << (Copy_u8InterruptCode - 32);
	}

}

/*
 * NVIC_voidSetPendingFlag
 * parameters:
 * description: Sets the NVIC pending flag for a specific interrupt
 */
void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptCode) {

	if (Copy_u8InterruptCode < 32) {
		NVIC_ISPR0 = 1 << Copy_u8InterruptCode;
	} else if (Copy_u8InterruptCode < 60) {
		NVIC_ISPR1 = 1 << (Copy_u8InterruptCode - 32);
	}

}

/*
 * NVIC_voidClearPendingFlag
 * parameters:
 * description: Clears the NVIC penging flag for a specific interrupt
 */
void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptCode) {

	if (Copy_u8InterruptCode < 32) {
		NVIC_ICPR0 = 1 << Copy_u8InterruptCode;
	} else if (Copy_u8InterruptCode < 60) {
		NVIC_ICPR1 = 1 << (Copy_u8InterruptCode - 32);
	}

}

/*
 * NVIC_u8GetActiveFlag
 * parameters:
 * return value:
 * description: Sets the NVIC disable pin for a specific interrupt
 */
u8 NVIC_u8GetActiveFlag(u8 Copy_u8InterruptCode) {

	u8 Local_u8PendingFlag = 0;

	if (Copy_u8InterruptCode < 32) {
		Local_u8PendingFlag = GET_BIT(NVIC_IABR0, 1 << Copy_u8InterruptCode);
	} else if (Copy_u8InterruptCode < 60) {
		Local_u8PendingFlag = GET_BIT(NVIC_IABR1, 1 << (Copy_u8InterruptCode - 32));
	}

	return Local_u8PendingFlag;
}


/*
 * NVIC_voidSetPriority
 * parameters:
 * return value:
 * description: Sets the priority for a specific interrupt
 */
void NVIC_voidSetPriority(u8 Copy_u8InterruptPosition, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority){

	//NVIC_IPR[Copy_u8InterruptPosition] = (Copy_u8GroupPriority<<(4+NVIC_PRIORITY_DISTRIBUTION)) | (Copy_u8SubPriority<<4);
	NVIC_IPR[Copy_u8InterruptPosition] = (Copy_u8GroupPriority<<(4+((NVIC_PRIORITY_DISTRIBUTION-0x05FA0300)/0x100))) | (Copy_u8SubPriority<<4);

}
