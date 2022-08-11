/*
 * AFIO_program.c
 *
 *  Created on: 11 Aug 2022
 *      Author: es-RaghadAly2023
 */



#include "BIT_MATH.h"
#include "STD_TYPES.h"


#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_register.h"
#include "AFIO_config.h"

/*
0 	4	8	12  %4 = 0
1	5	9	13  %4 = 1
2	6	10	14  %4 = 2
3	7	11	15  %4 = 3
*/


u8 AFIO_u8SetExternalInterruptSource(u8 Copy_u8Port, u8 Copy_u8ExternalInterruptNumber) {


	u8 Local_u8ErrorState = OK;

	u8 Local_u8RegisterShift = ( Copy_u8ExternalInterruptNumber % 4 ) * 4 ;


	if(Copy_u8ExternalInterruptNumber < 4) {
		AFIO_EXTICR1 |= Copy_u8Port << Local_u8RegisterShift;

	}else if (Copy_u8ExternalInterruptNumber < 8) {
		AFIO_EXTICR2 |= Copy_u8Port << Local_u8RegisterShift;

	}else if (Copy_u8ExternalInterruptNumber < 11) {
		AFIO_EXTICR3 |= Copy_u8Port << Local_u8RegisterShift;

	}else if (Copy_u8ExternalInterruptNumber < 15) {
		AFIO_EXTICR4 |= Copy_u8Port << Local_u8RegisterShift;

	} else {
		Local_u8ErrorState = NOOK;
	}


	return Local_u8ErrorState;



}
