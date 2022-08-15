/*
 * DELAY_program.c
 *
 *  Created on: 5 Aug 2022
 *      Author: es-RaghadAly2023
 */

#include "STD_TYPES.h"
#include "DELAY_interface.h"

void delay_ms(u32 Copy_u32DelayTime) {

	Copy_u32DelayTime = Copy_u32DelayTime * 10000;
	Copy_u32DelayTime = Copy_u32DelayTime * 2; //0.5us: 8MHz/4 = 2MHz. 1/2MHz = 0.5us;
	u32 Local_u32Cycles = (u32)(Copy_u32DelayTime / 5);
	u32 Local_u32Counter = 0;

	for(Local_u32Counter = 0; Local_u32Counter< Local_u32Cycles; Local_u32Counter++) {
		__asm__("nop");
	}

}


