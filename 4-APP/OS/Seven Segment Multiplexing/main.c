/*
 * main.c
 *
 *  Created on: 14 Aug 2022
 *      Author: es-RaghadAly2023
 */

#include "STD_TYPES.h"

#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "OS_interface.h"

#include "SEVENSEG_interface.h"

u8 Number = 99;
u8 UpdateFlag = 0;

void WriteNumberOnSevenSegment1(void);

void WriteNumberOnSevenSegment2(void);

void UpdateNumber(void);

void main(void) {

	SEVENSEG_voidInit();


/* void OS_voidCreateTask(u8 Copy_u8ID, u8 Copy_u8Periodicity, u8 Copy_u8InitialDelay, void (*ptr)(void)); */
	OS_voidCreateTask(0, 50, 1, UpdateNumber);
	OS_voidCreateTask(1, 1, 1, WriteNumberOnSevenSegment1);
	OS_voidCreateTask(2, 2, 1, WriteNumberOnSevenSegment2);

	OS_voidStartScheduler();



	while(1) {



	}



}

/*
Local_u8Temp = Local_u8Counter % 10;
		SEVENSEG_u8DisplayNumber(Local_u8Temp, SEVENSEGMENT2);
		Local_u8Temp = Local_u8Counter / 10;
		SEVENSEG_u8DisplayNumber(Local_u8Temp, SEVENSEGMENT1);
		delay_ms(1500);
*/


void WriteNumberOnSevenSegment1(void){

	u8 Local_u8Temp = Number;
	Local_u8Temp = Local_u8Temp / 10;

	SEVENSEG_voidTurnOffDisplay(SECOND_SEVENSEG);
	SEVENSEG_voidTurnOnDisplay(FIRST_SEVENSEG);
	SEVENSEG_u8DisplayNumber(Local_u8Temp, FIRST_SEVENSEG);
}

void WriteNumberOnSevenSegment2(void){

	u8 Local_u8Temp = Number;
	Local_u8Temp = Local_u8Temp % 10;


	SEVENSEG_voidTurnOffDisplay(FIRST_SEVENSEG);
	SEVENSEG_voidTurnOnDisplay(SECOND_SEVENSEG);
	SEVENSEG_u8DisplayNumber(Local_u8Temp, FIRST_SEVENSEG);


	if(UpdateFlag == 1){
		Number--;
		if(Number == 0) {
			Number = 30;
		}
		UpdateFlag = 0;
	}

}

void UpdateNumber(void) {

	UpdateFlag = 1;
}




