/*
 * SEVENSEG_program.c
 *
 *  Created on: 5 Aug 2022
 *      Author: es-RaghadAly2023
 */


#include "STD_TYPES.h"
#include "DELAY_interface.h"

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
	RCC_u8EnablePeripheralClock(GPIOB);
	GPIO_u8SetPortMode(GPIO_PORTA, GPIO_PIN_MODE_GP_PP_10MHZ);
	GPIO_u8SetPortMode(GPIO_PORTB, GPIO_PIN_MODE_GP_PP_10MHZ);

}

u8 SEVENSEG_u8DisplayNumber(u8 Copy_u8Number, u8 Copy_u8SevenSegmentNumber){

	u8 Local_u8ErrorState = OK;

	if(Copy_u8SevenSegmentNumber == FIRST_SEVENSEG)
		GPIO_u8SetPortSegmentValue(GPIO_PORTA, sev_seg[Copy_u8Number], 0, 7);
	else if(Copy_u8SevenSegmentNumber == SECOND_SEVENSEG)
		GPIO_u8SetPortSegmentValue(GPIO_PORTB, sev_seg[Copy_u8Number], 5, 7);


	return Local_u8ErrorState;

}


u8 SEVENSEG_u8CountDown(u8 Copy_u8Number) {

	u8 Local_u8ErrorState = OK;

	u8 Local_u8Counter = Copy_u8Number;

	u8 Local_u8Temp = 0;

	for(Local_u8Counter = Copy_u8Number; Local_u8Counter > 0; Local_u8Counter --) {

		Local_u8Temp = Local_u8Counter % 10;
		SEVENSEG_u8DisplayNumber(Local_u8Temp, SEVENSEGMENT2);
		Local_u8Temp = Local_u8Counter / 10;
		SEVENSEG_u8DisplayNumber(Local_u8Temp, SEVENSEGMENT1);
		delay_ms(1500);
	}


	return Local_u8ErrorState;



}




void SEVENSEG_voidTurnOffDisplay(u8 Copy_u8SevenSegmentNumber) {

	if(Copy_u8SevenSegmentNumber == FIRST_SEVENSEG) {
		GPIO_u8SetPinValue(SEVENSEGMENT1_CONTORL_PORT, SEVENSEGMENT1_CONTROL_PIN, GPIO_PIN_HIGH);
	} else if(Copy_u8SevenSegmentNumber == SECOND_SEVENSEG) {
		GPIO_u8SetPinValue(SEVENSEGMENT2_CONTORL_PORT, SEVENSEGMENT2_CONTROL_PIN, GPIO_PIN_HIGH);
	}

}


void SEVENSEG_voidTurnOnDisplay(u8 Copy_u8SevenSegmentNumber) {

	if(Copy_u8SevenSegmentNumber == FIRST_SEVENSEG) {
		GPIO_u8SetPinValue(SEVENSEGMENT1_CONTORL_PORT, SEVENSEGMENT1_CONTROL_PIN, GPIO_PIN_LOW);
	} else if(Copy_u8SevenSegmentNumber == SECOND_SEVENSEG) {
		GPIO_u8SetPinValue(SEVENSEGMENT2_CONTORL_PORT, SEVENSEGMENT2_CONTROL_PIN, GPIO_PIN_LOW);
	}

}



