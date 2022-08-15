/*
 * SEVENSEG_interface.h
 *
 *  Created on: 5 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef SEVENSEG_INTERFACE_H_
#define SEVENSEG_INTERFACE_H_

#define FIRST_SEVENSEG		0
#define SECOND_SEVENSEG		1

void SEVENSEG_voidInit();

u8 SEVENSEG_u8DisplayNumber(u8 Copy_u8Number, u8 Copy_u8SevenSegmentNumber);


u8 SEVENSEG_u8CountDown(u8 Copy_u8Number);

void SEVENSEG_voidTurnOffDisplay(u8 Copy_u8SevenSegmentNumber);

void SEVENSEG_voidTurnOnDisplay(u8 Copy_u8SevenSegmentNumber);

#endif /* SEVENSEG_INTERFACE_H_ */
