/*
 * SHIFTREG_interface.h
 *
 *  Created on: 18 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef SHIFTREG_INTERFACE_H_
#define SHIFTREG_INTERFACE_H_

typedef struct {
	u8 ControlPort;
	u8 SerialDataSrc;
	u8 ShiftClkSrc;
	u8 LatchClkSrc;
	u8 ResetSrc;
}Shiftreg_T;





Shiftreg_T SHIFTREG_Shiftreg_T_InitShiftRegister(u8 Copy_u8ControlPort,
												 u8 Copy_u8SerialDataSrc,
												 u8 Copy_u8ShiftClkSrc,
												 u8 Copy_u8LatchClkSrc,
												 u8 Copy_u8ResetSrc);

u8 SHIFTREG_u8SendSerialData(Shiftreg_T Copy_Shiftreg_T_ShiftRegister, u8 Copy_u8Data);

void SHIFTREG_voidInit(void);

#endif /* SHIFTREG_INTERFACE_H_ */
