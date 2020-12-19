/*********************************************************************/
/*********************************************************************/
/******** Author:Raghad Mohamed    ***********************************/
/******** Component:GPIO           ***********************************/
/******** Layer:    MCAL           ***********************************/
/******** Date: 20/11/2020		   ***********************************/
/******** Version:  1.0            ***********************************/
/*********************************************************************/
/*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_register.h"
#include "GPIO_config.h"



/*For Copy_u8Configs: choose speed if output , pull up or pull down if input */
u8 GPIO_u8SetPortDirectionAndMode(u8 Copy_u8Port, u8 Copy_u8Direction, u8 Copy_u8Mode, u8 Copy_u8Configs) {

	u8 Local_u8ErrorState = OK;

	u32 Local_u32Config = 0;
	u32 Local_u32PortValue = 0;

	if (Copy_u8Direction == GPIO_PORT_OUTPUT) {
		Local_u32Config += Copy_u8Configs;
	} else if (Copy_u8Direction == GPIO_PORT_INPUT) {
		Local_u32Config += GPIO_PORT_INPUT;
		GPIO_u8SetPortValue(Copy_u8Port, Copy_u8Configs);
	}

	Local_u32Config += Copy_u8Mode;

	Local_u32PortValue = Local_u32Config + (Local_u32Config << 4) + (Local_u32Config << 8) + (Local_u32Config << 12) + (Local_u32Config << 16) +(Local_u32Config << 20) +(Local_u32Config << 24) +(Local_u32Config << 28);

	switch (Copy_u8Port) {

	case GPIO_PORTA:
		GPIOA_CRL = Local_u32PortValue;
		GPIOA_CRH = Local_u32PortValue;
		break;
	case GPIO_PORTB:
		GPIOB_CRH = Local_u32PortValue;
		GPIOB_CRL = Local_u32PortValue;
		break;
	case GPIO_PORTC:
		GPIOC_CRL = Local_u32PortValue;
		GPIOC_CRH = Local_u32PortValue;
		break;
	default:
		Local_u8ErrorState = NOOK;
		break;

	}
	return Local_u8ErrorState;

}
/*For Copy_u8Configuartions: choose speed if output , choose pull up pull down if input*/
u8 GPIO_u8SetPinDirectionAndMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction, u8 Copy_u8Mode, u8 Copy_u8Configs) {
	u8 Local_u8ErrorState = OK;

	u32 Local_u32Config = 0;

	if (Copy_u8Direction == GPIO_PIN_OUTPUT) {
		Local_u32Config += Copy_u8Configs;
	} else if (Copy_u8Direction == GPIO_PIN_INPUT) {
		Local_u32Config += GPIO_PORT_INPUT;
		GPIO_u8SetPinValue(Copy_u8Port, Copy_u8Pin, Copy_u8Configs);
	}

	Local_u32Config += Copy_u8Mode;

	switch (Copy_u8Port) {
	case GPIO_PORTA:
		if ((Copy_u8Pin >= GPIO_PIN0) && (Copy_u8Pin <= GPIO_PIN7)) {
			GPIOA_CRL &= ~(0x0000000F << (4 * Copy_u8Pin));
			GPIOA_CRL += Local_u32Config << (4 * Copy_u8Pin);

		} else if ((Copy_u8Pin >= GPIO_PIN8) && (Copy_u8Pin <= GPIO_PIN15)) {
			GPIOA_CRH &= ~(0x0000000F << (4 * (Copy_u8Pin - 8)));
			GPIOA_CRH += Local_u32Config << (4 * (Copy_u8Pin - 8));

		} else {
			Local_u8ErrorState = NOOK;
		}
		break;
	case GPIO_PORTB:
		if ((Copy_u8Pin >= GPIO_PIN0) && (Copy_u8Pin <= GPIO_PIN7)) {
			GPIOB_CRL &= ~(0x0000000F << (4 * Copy_u8Pin));
			GPIOB_CRL += Local_u32Config << (4 * Copy_u8Pin);

		} else if ((Copy_u8Pin >= GPIO_PIN8) && (Copy_u8Pin <= GPIO_PIN15)) {
			GPIOB_CRH &= ~(0x0000000F << (4 * (Copy_u8Pin - 8)));
			GPIOB_CRH += Local_u32Config << (4 * (Copy_u8Pin - 8));

		} else {
			Local_u8ErrorState = NOOK;
		}

		break;
	case GPIO_PORTC:
		if ((Copy_u8Pin >= GPIO_PIN0) && (Copy_u8Pin <= GPIO_PIN7)) {
			GPIOC_CRL &= ~(0x0000000F << (4 * Copy_u8Pin));
			GPIOC_CRL += Local_u32Config << (4 * Copy_u8Pin);

		} else if ((Copy_u8Pin >= GPIO_PIN8) && (Copy_u8Pin <= GPIO_PIN15)) {
			GPIOC_CRH &= ~(0x0000000F << (4 * (Copy_u8Pin - 8)));
			GPIOC_CRH += Local_u32Config << (4 * (Copy_u8Pin - 8));

		} else {
			Local_u8ErrorState = NOOK;
		}

		break;
	default:
		Local_u8ErrorState = NOOK;
		break;
	}

	return Local_u8ErrorState;

}

u8 GPIO_u8SetPortValue(u8 Copy_u8Port, u16 Copy_u16Value) {
	u8 Local_u8ErrorState = OK;

	switch (Copy_u8Port) {

	case GPIO_PORTA:
		GPIOA_ODR = Copy_u16Value;
		break;
	case GPIO_PORTB:
		GPIOB_ODR = Copy_u16Value;
		break;
	case GPIO_PORTC:
		GPIOC_ODR = Copy_u16Value;
		break;
	default:
		Local_u8ErrorState = NOOK;
		break;
	}

	return Local_u8ErrorState;

}
u8 GPIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value) {
	u8 Local_u8ErrorState = OK;

	switch (Copy_u8Port) {

	case GPIO_PORTA:
		if (Copy_u8Value == GPIO_PIN_HIGH) {
			SET_BIT(GPIOA_ODR, Copy_u8Pin);
		} else if (Copy_u8Value == GPIO_PIN_LOW) {
			CLR_BIT(GPIOA_ODR, Copy_u8Pin);
		} else {
			Local_u8ErrorState = NOOK;
		}
		break;
	case GPIO_PORTB:
		if (Copy_u8Value == GPIO_PIN_HIGH) {
			SET_BIT(GPIOB_ODR, Copy_u8Pin);
		} else if (Copy_u8Value == GPIO_PIN_LOW) {
			CLR_BIT(GPIOB_ODR, Copy_u8Pin);
		} else {
			Local_u8ErrorState = NOOK;
		}
		break;
	case GPIO_PORTC:
		if (Copy_u8Value == GPIO_PIN_HIGH) {
			SET_BIT(GPIOC_ODR, Copy_u8Pin);
		} else if (Copy_u8Value == GPIO_PIN_LOW) {
			CLR_BIT(GPIOC_ODR, Copy_u8Pin);
		} else {
			Local_u8ErrorState = NOOK;
		}
		break;
	default:
		Local_u8ErrorState = NOOK;
		break;
	}

	return Local_u8ErrorState;

}

u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 * Copy_pu8PinValue) {

	u8 Local_u8ErrorState = OK;

	switch (Copy_u8Port) {
	case GPIO_PORTA:
		*Copy_pu8PinValue = GET_BIT(GPIOA_IDR, Copy_u8Pin);
		break;
	case GPIO_PORTB:
		*Copy_pu8PinValue = GET_BIT(GPIOB_IDR, Copy_u8Pin);
		break;
	case GPIO_PORTC:
		*Copy_pu8PinValue = GET_BIT(GPIOC_IDR, Copy_u8Pin);
		break;
	default:
		Local_u8ErrorState = NOOK;
		break;
	}

	return Local_u8ErrorState;

}
