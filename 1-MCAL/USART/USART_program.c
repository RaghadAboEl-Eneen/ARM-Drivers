/*
 * USART_program.c
 *
 *  Created on: 21 Aug 2022
 *      Author: es-RaghadAly2023
 */



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_register.h"
#include "USART_config.h"




void USART_voidInitUSART1(void) {

	/* Calculate USART_DIV for needed baudrate*/
	f32 Local_f32FractionTemp = (f32)(500000 / USART_BAUD_RATE);
	u16 Local_u16MantissaTemp = (u16) Local_f32FractionTemp;
	u16 Local_u16Mask = 0x000F;

	USART1_START_ADDRESS->BRR &= Local_u16Mask;
	USART1_START_ADDRESS->BRR |= Local_u16MantissaTemp << BRR_DIV_MANTISSA;

	Local_f32FractionTemp = (f32)(Local_f32FractionTemp - Local_u16MantissaTemp);
	Local_f32FractionTemp = Local_f32FractionTemp * 16.0 ;

	Local_u16Mask = 0xFFF0;

	USART1_START_ADDRESS->BRR &= Local_u16Mask;
	USART1_START_ADDRESS->BRR |= ((u16)Local_f32FractionTemp) << BRR_DIV_FRACTION;


#if USART1_ENABLE == USART_ENABLE

	SET_BIT(USART1_START_ADDRESS->CR1, CR1_UE);

#elif USART1_ENABLE == USART_DISABLE

	CLR_BIT(USART1_START_ADDRESS->CR1, CR1_UE);

#endif


#if USART1_NUMBER_OF_DATA_BITS == USART_8_DATA_BITS

	CLR_BIT(USART1_START_ADDRESS->CR1, CR1_M);


#elif USART1_NUMBER_OF_DATA_BITS == USART_9_DATA_BITS

	SET_BIT(USART1_START_ADDRESS->CR1, CR1_M);

#endif


#if USART1_PARITY_BIT_ENABLED == USART_PARITY_ENABLED

	SET_BIT(USART1_START_ADDRESS->CR1, CR1_PCE);


#elif USART1_PARITY_BIT_ENABLED == USART_PARITY_DISABLED

	CLR_BIT(USART1_START_ADDRESS->CR1, CR1_PCE);

#endif


#if USART1_ENABLE_TRANSMITTER == USART_ENABLE_TRANSMITTER
	SET_BIT(USART1_START_ADDRESS->CR1, CR1_TE);

#elif USART1_ENABLE_TRANSMITTER == USART_DISABLE_TRANSMITTER
	CLR_BIT(USART1_START_ADDRESS->CR2, CR1_TE);

#endif


#if   USART1_ENABLE_RECEIVER == USART_ENABLE_RECEIVER
	SET_BIT(USART1_START_ADDRESS->CR1, CR1_RE);

#elif USART1_ENABLE_RECEIVER == USART_DISABLE_RECEIVER
	CLR_BIT(USART1_START_ADDRESS->CR1, CR1_RE);

#endif

}

void USART_voidInitUSART2(void) {


}

void USART_voidInitUSART3(void) {

}

u8 USART_u8SendDataSynchronous(u8 Copy_u8Data) {

	u8 Local_u8ErrorState = OK;


	USART1_START_ADDRESS->DR = Copy_u8Data;

	while(GET_BIT(USART1_START_ADDRESS->SR, SR_TC) != 1);

	CLR_BIT(USART1_START_ADDRESS->SR, SR_TC);

	return Local_u8ErrorState;

}

u8 USART_u8ReceiveDataSynchronous(u8 * Pointer_u8Data) {

	u8 Local_u8ErrorState = OK;


	while(GET_BIT(USART1_START_ADDRESS->SR, SR_RXNE) != 1);


	*Pointer_u8Data = 	USART1_START_ADDRESS->DR;

	CLR_BIT(USART1_START_ADDRESS->SR, SR_RXNE);


	return Local_u8ErrorState;


}

