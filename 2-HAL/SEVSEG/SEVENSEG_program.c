/*
 * SEVENSEG_program.c
 *
 *  Created on: 5 Aug 2022
 *      Author: es-RaghadAly2023
 */


#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "SEVENSEG_interface.h"
#include "SEVENSEG_config.h"
#include "SEVENSEG_private.h"

u8 sev_seg[10] = {SEVENSEG_ZERO,
				  SEVENSEG_ONE,
				  SEVENSEG_TWO,
				  SEVENSEG_THREE,
				  SEVENSEG_FOUR,
				  SEVENSEG_FIVE,
				  SEVENSEG_SIX,
				  SEVENSEG_SEVEN,
				  SEVENSEG_EIGHT,
				  SEVENSEG_NINE};



void SEVENSEG_voidInit() {

	RCC_voidInit();
	RCC_u8EnablePeripheralClock(GPIOA);
	GPIO_u8SetPortMode(GPIO_PORTA, GPIO_PIN_MODE_GP_PP_10MHZ);

}

u8 SEVENSEG_u8DisplayNumber(u8 Copy_u8Number){

	u8 Local_u8ErrorState = OK;

	GPIO_u8SetPortValue(SEVENSEG_PORT, sev_seg[Copy_u8Number]);

	return Local_u8ErrorState;

}


void SEVENSEG_voidTurnOffDisplay(void) {

	GPIO_u8SetPortValue(SEVENSEG_PORT, GPIO_PORT_LOW);

}


