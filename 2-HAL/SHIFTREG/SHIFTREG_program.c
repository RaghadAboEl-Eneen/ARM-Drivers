/*
 * SHIFTREG_program.c
 *
 *  Created on: 18 Aug 2022
 *      Author: es-RaghadAly2023
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

#include "SHIFTREG_interface.h"
#include "SHIFTREG_private.h"
#include "SHIFTREG_config.h"


void SHIFTREG_voidInit(void) {
	STK_voidInit(SYSTICK_AHB_8);
}



Shiftreg_T SHIFTREG_Shiftreg_T_InitShiftRegister(u8 Copy_u8ControlPort,
												 u8 Copy_u8SerialDataSrc,
												 u8 Copy_u8ShiftClkSrc,
												 u8 Copy_u8LatchClkSrc,
												 u8 Copy_u8ResetSrc) {

	Shiftreg_T Local_shiftRegister = {Copy_u8ControlPort,
									  Copy_u8SerialDataSrc,
									  Copy_u8ShiftClkSrc,
									  Copy_u8LatchClkSrc,
									  Copy_u8ResetSrc};


	GPIO_u8SetPinValue(Local_shiftRegister.ControlPort, Local_shiftRegister.LatchClkSrc, GPIO_PIN_HIGH);
	GPIO_u8SetPinValue(Local_shiftRegister.ControlPort, Local_shiftRegister.ShiftClkSrc, GPIO_PIN_HIGH);


	return Local_shiftRegister;


}



u8 SHIFTREG_u8SendSerialData(Shiftreg_T Copy_Shiftreg_T_ShiftRegister, u8 Copy_u8Data) {

	u8 Local_u8ErrorState = OK;
	u8 Local_u8Temp = 0;
	u8 Local_u8Mask = 0x80;
	u8 Local_u8Counter = 0;

	GPIO_u8SetPinValue(Copy_Shiftreg_T_ShiftRegister.ControlPort, Copy_Shiftreg_T_ShiftRegister.ResetSrc, GPIO_PIN_LOW);
	STK_voidSetBusyWait(20);
	GPIO_u8SetPinValue(Copy_Shiftreg_T_ShiftRegister.ControlPort, Copy_Shiftreg_T_ShiftRegister.ResetSrc, GPIO_PIN_HIGH);

	for(Local_u8Counter = 0; Local_u8Counter < 8 ; Local_u8Counter++) {

		Local_u8Temp = Copy_u8Data & Local_u8Mask;
		Local_u8Temp = Local_u8Temp >> 7;

		GPIO_u8SetPinValue(Copy_Shiftreg_T_ShiftRegister.ControlPort, Copy_Shiftreg_T_ShiftRegister.SerialDataSrc, Local_u8Temp);
		STK_voidSetBusyWait(10);


		GPIO_u8SetPinValue(Copy_Shiftreg_T_ShiftRegister.ControlPort, Copy_Shiftreg_T_ShiftRegister.ShiftClkSrc, GPIO_PIN_LOW);
		STK_voidSetBusyWait(20);
		GPIO_u8SetPinValue(Copy_Shiftreg_T_ShiftRegister.ControlPort, Copy_Shiftreg_T_ShiftRegister.ShiftClkSrc, GPIO_PIN_HIGH);

		Copy_u8Data = Copy_u8Data << 1;
	}

	GPIO_u8SetPinValue(Copy_Shiftreg_T_ShiftRegister.ControlPort, Copy_Shiftreg_T_ShiftRegister.LatchClkSrc, GPIO_PIN_LOW);
	STK_voidSetBusyWait(20);
	GPIO_u8SetPinValue(Copy_Shiftreg_T_ShiftRegister.ControlPort, Copy_Shiftreg_T_ShiftRegister.LatchClkSrc, GPIO_PIN_HIGH);






	return Local_u8ErrorState;


}









