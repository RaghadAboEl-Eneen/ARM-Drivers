/*
 * main.c
 *
 *  Created on: 5 Aug 2022
 *      Author: es-RaghadAly2023
 */

#include "STD_TYPES.h"
#include "DELAY_interface.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

#include "SEVENSEG_interface.h"



#define GREEN_LED		8
#define YELLOW_LED		9
#define RED_LED			10


void main(void) {

	SEVENSEG_voidInit();
	GPIO_u8SetPinMode(GPIO_PORTA, GREEN_LED, GPIO_PIN_MODE_GP_PP_10MHZ);
	GPIO_u8SetPinMode(GPIO_PORTA, YELLOW_LED, GPIO_PIN_MODE_GP_PP_10MHZ);
	GPIO_u8SetPinMode(GPIO_PORTA, RED_LED, GPIO_PIN_MODE_GP_PP_10MHZ);


	while(1) {

		GPIO_u8SetPinValue(GPIO_PORTA, RED_LED, GPIO_PIN_LOW);
		GPIO_u8SetPinValue(GPIO_PORTA, GREEN_LED, GPIO_PIN_HIGH);
		SEVENSEG_u8CountDown(10);
		GPIO_u8SetPinValue(GPIO_PORTA, GREEN_LED, GPIO_PIN_LOW);
		GPIO_u8SetPinValue(GPIO_PORTA, YELLOW_LED, GPIO_PIN_HIGH);
		SEVENSEG_u8CountDown(3);
		GPIO_u8SetPinValue(GPIO_PORTA, YELLOW_LED, GPIO_PIN_LOW);
		GPIO_u8SetPinValue(GPIO_PORTA, RED_LED, GPIO_PIN_HIGH);
		SEVENSEG_u8CountDown(10);


	}



}
