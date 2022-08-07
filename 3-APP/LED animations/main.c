/*
 * main.c
 *
 *  Created on: 7 Aug 2022
 *      Author: es-RaghadAly2023
 */

#include "STD_TYPES.h"
#include "DELAY_interface.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"


void flashing(void);
void shifting_left(void);
void shifting_right(void);
void converging(void);
void diverging(void);
void ping_ping(void);
void snake(void);
void converging_diverging(void);


void main(void) {

	RCC_voidInit();
	RCC_u8EnablePeripheralClock(GPIOA);
	GPIO_u8SetPortMode(GPIO_PORTA, GPIO_PIN_MODE_GP_PP_10MHZ);
	u8 Local_u8Counter = 0;


	while(1) {

		for(Local_u8Counter = 0; Local_u8Counter < 10; Local_u8Counter++) {
			flashing();
		}
		for(Local_u8Counter = 0; Local_u8Counter < 10; Local_u8Counter++) {
			shifting_left();
		}
		for(Local_u8Counter = 0; Local_u8Counter < 10; Local_u8Counter++) {
			shifting_right();
		}
		for(Local_u8Counter = 0; Local_u8Counter < 10; Local_u8Counter++) {
			converging();
		}
		for(Local_u8Counter = 0; Local_u8Counter < 10; Local_u8Counter++) {
			diverging();
		}
		for(Local_u8Counter = 0; Local_u8Counter < 10; Local_u8Counter++) {
			ping_ping();
		}
		for(Local_u8Counter = 0; Local_u8Counter < 10; Local_u8Counter++) {
			snake();
		}
		for(Local_u8Counter = 0; Local_u8Counter < 10; Local_u8Counter++) {
			converging_diverging();
		}





	}


}


void flashing(void) {

	GPIO_u8SetPortSegmentValue(GPIO_PORTA, GPIO_PORT_HIGH, 0, 8);
	delay_ms(500);
	GPIO_u8SetPortSegmentValue(GPIO_PORTA, GPIO_PORT_LOW, 0, 8);
	delay_ms(500);

}



void shifting_left(void) {


	u8 Local_u8Shift = 1;

	while(Local_u8Shift != 0) {
		GPIO_u8SetPortSegmentValue(GPIO_PORTA, Local_u8Shift, 0, 8);
		Local_u8Shift = Local_u8Shift << 1 ;
		delay_ms(250);
	}


}
void shifting_right(void) {

	u8 Local_u8Shift = 128;

	while(Local_u8Shift != 0) {
		GPIO_u8SetPortSegmentValue(GPIO_PORTA, Local_u8Shift, 0, 8);
		Local_u8Shift = Local_u8Shift >> 1 ;
		delay_ms(250);
	}

}
void converging(void) {

	u8 Local_u8Number = 129;
	u8 Local_u8Offset = 1;
	u8 Local_u8Counter = 3;

	GPIO_u8SetPortSegmentValue(GPIO_PORTA, Local_u8Number, 0, 8);
	delay_ms(300);

	Local_u8Number = Local_u8Number + 1;

	while(Local_u8Number != 24) {

			Local_u8Number = (Local_u8Number / 2) + Local_u8Offset;
			GPIO_u8SetPortSegmentValue(GPIO_PORTA, Local_u8Number, 0, 8);
			Local_u8Offset = Local_u8Offset * Local_u8Counter;
			Local_u8Counter--;
			delay_ms(300);


	}

}

void diverging(void) {

	u8 Local_u8Number = 24;
	u8 Local_u8Offset = 12;
	u8 Local_u8Counter = 2;

	GPIO_u8SetPortSegmentValue(GPIO_PORTA, Local_u8Number, 0, 8);
	delay_ms(250);

	while(Local_u8Number != 129) {

		Local_u8Number = (Local_u8Number * 2) - Local_u8Offset;
		GPIO_u8SetPortSegmentValue(GPIO_PORTA, Local_u8Number, 0, 8);
		Local_u8Offset = Local_u8Offset - (3*Local_u8Counter);
		Local_u8Counter--;
		delay_ms(250);


	}




}

void ping_ping(void) {

	shifting_left();
	delay_ms(250);
	shifting_right();
	delay_ms(250);


}

void snake(void) {

	u8 Local_u8Number = 0;
	u8 Local_u8Counter = 1;

	GPIO_u8SetPortSegmentValue(GPIO_PORTA, Local_u8Number, 0, 8);
	delay_ms(300);

	while(Local_u8Number != 255) {

		Local_u8Number = Local_u8Number + Local_u8Counter;
		GPIO_u8SetPortSegmentValue(GPIO_PORTA, Local_u8Number, 0, 8);
		Local_u8Counter = Local_u8Counter << 1;
		delay_ms(300);

	}



}
void converging_diverging(void) {

	converging();
	delay_ms(300);
	diverging();
	delay_ms(300);


}







