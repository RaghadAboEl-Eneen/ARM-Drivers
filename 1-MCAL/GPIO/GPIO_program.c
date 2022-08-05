/*
 * GPIO_program.c
 *
 *  Created on: 4 Aug 2022
 *      Author: es-RaghadAly2023
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "GPIO_interface.h"
#include "GPIO_register.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

u8 GPIO_u8SetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinMode) {

	u8 Local_u8ErrorState = OK;

	switch(Copy_u8Port){
		case GPIO_PORTA:
			if(Copy_u8Pin <= 7){
				GPIO_PORTA_BASE->CRL &= (~(0b1111<<(4*Copy_u8Pin)));
				GPIO_PORTA_BASE->CRL |= (Copy_u8PinMode << (4*Copy_u8Pin));
			}else if(Copy_u8Pin <= 16){
				GPIO_PORTA_BASE->CRH &= (~(0b1111<<(4*(Copy_u8Pin-8))));
				GPIO_PORTA_BASE->CRH |= (Copy_u8PinMode << (4*(Copy_u8Pin-8)));
			}
			break;
		case GPIO_PORTB:
			if(Copy_u8Pin <= 7){
				GPIO_PORTB_BASE->CRL &= (~(0b1111<<(4*Copy_u8Pin)));
				GPIO_PORTB_BASE->CRL |= (Copy_u8PinMode << (4*Copy_u8Pin));
			}else if(Copy_u8Pin <= 16){
				GPIO_PORTB_BASE->CRH &= (~(0b1111<<(4*(Copy_u8Pin-8))));
				GPIO_PORTB_BASE->CRH |= (Copy_u8PinMode << (4*(Copy_u8Pin-8)));
			}
			break;
		case GPIO_PORTC:
			if(Copy_u8Pin <= 7){
				GPIO_PORTC_BASE->CRL &= (~(0b1111<<(4*Copy_u8Pin)));
				GPIO_PORTC_BASE->CRL |= (Copy_u8PinMode << (4*Copy_u8Pin));
			}else if(Copy_u8Pin <= 16){
				GPIO_PORTC_BASE->CRH &= (~(0b1111<<(4*(Copy_u8Pin-8))));
				GPIO_PORTC_BASE->CRH |= (Copy_u8PinMode << (4*(Copy_u8Pin-8)));
			}
			break;
		default:
			Local_u8ErrorState = NOOK;
			break;

		}


	return Local_u8ErrorState;
}


u8 GPIO_u8SetPortMode(u8 Copy_u8Port, u8 Copy_u8PortMode) {

	u8 Local_u8ErrorState = OK;
	u32 Local_u32PortMode = (u32)Copy_u8PortMode;
	Local_u32PortMode = Local_u32PortMode         +
						(Local_u32PortMode << 4)  +
						(Local_u32PortMode << 8)  +
						(Local_u32PortMode << 12) +
						(Local_u32PortMode << 16) +
						(Local_u32PortMode << 20) +
						(Local_u32PortMode << 24) +
						(Local_u32PortMode << 28);

	switch(Copy_u8Port){
		case GPIO_PORTA:
			GPIO_PORTA_BASE->CRL = Local_u32PortMode;
			GPIO_PORTA_BASE->CRH = Local_u32PortMode;
			break;

		case GPIO_PORTB:
			GPIO_PORTB_BASE->CRL = Local_u32PortMode;
			GPIO_PORTB_BASE->CRH = Local_u32PortMode;
			break;

		case GPIO_PORTC:
			GPIO_PORTC_BASE->CRL = Local_u32PortMode;
			GPIO_PORTC_BASE->CRH = Local_u32PortMode;
			break;
		default:
			Local_u8ErrorState = NOOK;
			break;
		}


	return Local_u8ErrorState;

}






u8 GPIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value) {

	u8 Local_u8ErrorState = OK;

	if (Copy_u8Pin < 16) {

		switch (Copy_u8Port) {

		case (GPIO_PORTA):

			if (Copy_u8Value == GPIO_PIN_HIGH) {
				GPIO_PORTA_BASE->BSRR = 1<<Copy_u8Pin;
				//SET_BIT(GPIO_PORTA_BASE->ODR, Copy_u8Pin);
			} else if (Copy_u8Value == GPIO_PIN_LOW) {
				GPIO_PORTA_BASE->BRR =  1<<Copy_u8Pin;
				//CLR_BIT(GPIO_PORTA_BASE->ODR, Copy_u8Pin);
			}

			break;

		case (GPIO_PORTB):

			if (Copy_u8Value == GPIO_PIN_HIGH) {
				GPIO_PORTB_BASE->BSRR = 1<<Copy_u8Pin;
				//SET_BIT(GPIO_PORTB_BASE->ODR, Copy_u8Pin);
			} else if (Copy_u8Value == GPIO_PIN_LOW) {
				GPIO_PORTB_BASE->BRR =  1<<Copy_u8Pin;
				//CLR_BIT(GPIO_PORTB_BASE->ODR, Copy_u8Pin);
			}

			break;

		case (GPIO_PORTC):

			if (Copy_u8Value == GPIO_PIN_HIGH) {
				GPIO_PORTC_BASE->BSRR = 1<<Copy_u8Pin;
				//SET_BIT(GPIO_PORTC_BASE->ODR, Copy_u8Pin);
			} else {
				GPIO_PORTC_BASE->BRR =  1<<Copy_u8Pin;
				//CLR_BIT(GPIO_PORTC_BASE->ODR, Copy_u8Pin);

			}

			break;

		default:
			Local_u8ErrorState = NOOK;
			break;

		}
	} else {

		Local_u8ErrorState = NOOK;

	}

	return Local_u8ErrorState;

}


u8 GPIO_u8SetPortValue(u8 Copy_u8Port, u16 Copy_u16PortValue) {

	u8 Local_u8ErrorState = OK;

	switch (Copy_u8Port) {

			case (GPIO_PORTA):
			GPIO_PORTA_BASE->ODR = Copy_u16PortValue;
				break;

			case (GPIO_PORTB):
			GPIO_PORTB_BASE->ODR = Copy_u16PortValue;
				break;

			case (GPIO_PORTC):
			GPIO_PORTC_BASE->ODR = Copy_u16PortValue;
				break;

			default:
				Local_u8ErrorState = NOOK;
				break;
	}


	return Local_u8ErrorState;

}





u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Ptr_u8Value) {

	u8 Local_u8ErrorState = OK;

	switch (Copy_u8Port) {

	case (GPIO_PORTA):
		*Ptr_u8Value = GET_BIT(GPIO_PORTA_BASE->IDR, Copy_u8Pin);
		break;

	case (GPIO_PORTB):
		*Ptr_u8Value = GET_BIT(GPIO_PORTB_BASE->IDR, Copy_u8Pin);
		break;

	case (GPIO_PORTC):
		*Ptr_u8Value = GET_BIT(GPIO_PORTC_BASE->IDR, Copy_u8Pin);
		break;

	default:
		Local_u8ErrorState = NOOK;
		break;

	}

	return Local_u8ErrorState;

}
