/*
 * NVIC_interface.h
 *
 *  Created on: Aug 8, 2022
 *      Author: Omar Gamal
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_



/*
 * NVIC_voidEnableInterrupt
 * parameters:
 * description: Sets the NVIC enable pin for a specific interrupt
 */
void NVIC_voidEnableInterrupt(u8 Copy_u8InterruptCode);


/*
 * NVIC_voidDisableInterrupt
 * parameters:
 * description: Sets the NVIC disable pin for a specific interrupt
 */
void NVIC_voidDisableInterrupt(u8 Copy_u8InterruptCode);

/*
 * NVIC_voidSetPendingFlag
 * parameters:
 * description: Sets the NVIC pending flag for a specific interrupt
 */
void NVIC_voidSetPendingFlag(u8 Copy_u8InterruptCode);


/*
 * NVIC_voidClearPendingFlag
 * parameters:
 * description: Clears the NVIC pending flag for a specific interrupt
 */
void NVIC_voidClearPendingFlag(u8 Copy_u8InterruptCode);

/*
 * NVIC_u8GetActiveFlag
 * parameters:
 * return value:
 * description: Get the NVIC active status for a specific interrupt
 */
u8 NVIC_u8GetActiveFlag(u8 Copy_u8InterruptCode);


/**
 *
 * @param Local_u8PriorityGroup : which group the interrupt will be put in, there are 20 groups : IPR[0] ~ IPR[20
 * 								  each group can hold 4 interrupts
 * @param Local_u8PriorityLevel	: priority level within group , 0-15
 * @param Local_u8InterruptCode : interrupt ID
 */
void NVIC_voidSetPriorityGrouping(u8 Local_u8PriorityGroup, u8 Local_u8PriorityLevel, u8 Local_u8InterruptCode);

#endif /* NVIC_INTERFACE_H_ */
