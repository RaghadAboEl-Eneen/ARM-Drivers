/*
 * NVIC_interface.h
 *
 *  Created on: Aug 8, 2022
 *      Author:  es-RaghadAly2023
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


#define		NVIC_GROUP_4_BITS		0x05FA0300
#define		NVIC_GROUP_3_BITS		0x05FA0400
#define		NVIC_GROUP_2_BITS		0x05FA0500
#define		NVIC_GROUP_1_BITS		0x05FA0600
#define		NVIC_GROUP_0_BITS		0x05FA0700


/*
 * NVIC_voidInit
 * Parameters: void
 * description: Sets the Priority Model for group & sub-priorities
 */
void NVIC_voidInit(void);

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



void NVIC_voidSetPriority(u8 Copy_u8InterruptPosition, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);

#endif /* NVIC_INTERFACE_H_ */
