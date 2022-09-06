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


u8 USART_SEND_FLAG	   = IDLE;
u8 USART_RECEIVE_FLAG  = IDLE;

u8 USART_ReceiveBuffer = 0;

void USART_voidInitUSART1(void) {

	/* Calculate USART_DIV for needed baudrate*/
	f32 Local_f32FractionTemp = (f32)(500000.0 / (f32)USART_BAUD_RATE);
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


#if USART1_ENABLE_TX_COMPLETE_INTERRUPT == USART_ENABLE_TX_COMPLETE_INTERRUPT
	SET_BIT(USART1_START_ADDRESS->CR1, CR1_TCIE);

#elif USART1_ENABLE_TX_COMPLETE_INTERRUPT == USART_DISABLE_TX_COMPLETE_INTERRUPT
	CLR_BIT(USART1_START_ADDRESS->CR1, CR1_TCIE);

#endif

#if USART1_ENABLE_RECEIVED_BYTE_INTERRUPT == USART_ENABLE_RECEIVED_BYTE_INTERRUPT
	SET_BIT(USART1_START_ADDRESS->CR1, CR1_RXNEIE);

#elif USART1_ENABLE_RECEIVED_BYTE_INTERRUPT == USART_DISABLE_RECEIVED_BYTE_INTERRUPT
	CLR_BIT(USART1_START_ADDRESS->CR1, CR1_RXNEIE);

#endif



	//SET_BIT(USART1_START_ADDRESS->CR1, CR1_TXEIE);

	/*Enable DMA for transmission*/
	//SET_BIT(USART1_START_ADDRESS->CR3, CR3_DMAT);






}

void USART_voidInitUSART2(void) {


}

void USART_voidInitUSART3(void) {

}

u8 USART_u8SendDataSynchronous(u8 Copy_u8Data) {

	u8 Local_u8ErrorState = OK;


	USART1_START_ADDRESS->DR = Copy_u8Data;

	while(GET_BIT(USART1_START_ADDRESS->SR, SR_TXE) != 1);

	CLR_BIT(USART1_START_ADDRESS->SR, SR_TXE);


	return Local_u8ErrorState;

}




u8 USART_u8SendArrayOfDataSynchronous(u8 * Pointer_u8Data) {

	u8 Local_u8ErrorState = OK;
	u8 Local_u8Counter = 0;

	while(Pointer_u8Data[Local_u8Counter] != '\0') {

		USART_u8SendDataSynchronous(Pointer_u8Data[Local_u8Counter]);
		Local_u8Counter++;

	}

	return Local_u8ErrorState;

}



void USART_voidSendDataAsynchronous(u8 Copy_u8Data){


	if(USART_SEND_FLAG == IDLE) {
		USART_SEND_FLAG = SENDING;
		USART1_START_ADDRESS->DR = Copy_u8Data;
		USART_voidEnableInterrupt(USART_TX_BUFFER_EMPTY_INT);

	}


}


u8 USART_u8ReceiveDataSynchronous(u8 * Pointer_u8Data) {

	u8 Local_u8ErrorState = OK;


	while(GET_BIT(USART1_START_ADDRESS->SR, SR_RXNE) != 1);


	*Pointer_u8Data = 	USART1_START_ADDRESS->DR;

	CLR_BIT(USART1_START_ADDRESS->SR, SR_RXNE);


	return Local_u8ErrorState;


}


u8 USART_u8ReceiveDataSynchronousWithTimeout(u8 * Pointer_u8Data, u32 Copy_u32TimeuotPeriod) {

	u8 Local_u8ErrorState = OK;
	u32 Local_u32Countdown = Copy_u32TimeuotPeriod;

	while( (GET_BIT(USART1_START_ADDRESS->SR, SR_RXNE) != 1) && Local_u32Countdown !=0 ) {
		Local_u32Countdown--;
	}

	if(Local_u32Countdown > 0) {

	*Pointer_u8Data = 	USART1_START_ADDRESS->DR;

	//CLR_BIT(USART1_START_ADDRESS->SR, SR_RXNE);

	} else if(Local_u32Countdown == 0) {
		Local_u8ErrorState = TIMEOUT_STATE;
	}

	return Local_u8ErrorState;


}

u8 USART_u8ReceiveArrayOfDataSynchronousWithTimeout(u8 * Pointer_u8ReceiveBuffer, u32 Copy_u32TimeoutPeriod) {

	u8 Local_u8ErrorState = OK;
	u8 Local_u8NestedErrorState = OK;
	u8 Local_u8Counter = 0;


	while(Local_u8NestedErrorState != TIMEOUT_STATE) {

		Local_u8NestedErrorState = USART_u8ReceiveDataSynchronousWithTimeout( &(Pointer_u8ReceiveBuffer[Local_u8Counter]), Copy_u32TimeoutPeriod );
		Local_u8Counter++;
	}



	Local_u8Counter++;
	Pointer_u8ReceiveBuffer[Local_u8Counter] = '\0';

	return Local_u8ErrorState;


}

u8 USART_u8ReceiveArrayOfDataSynchronous(u8 * Pointer_u8ReceiveBuffer, u8 Copy_u8NumberOfBytes) {

	u8 Local_u8ErrorState = OK;
	u8 Local_u8Counter = 0;

	for(Local_u8Counter = 0; Local_u8Counter < Copy_u8NumberOfBytes ; Local_u8Counter++) {

		USART_u8ReceiveDataSynchronous( &(Pointer_u8ReceiveBuffer[Local_u8Counter]) );

	}

	Pointer_u8ReceiveBuffer[Local_u8Counter] = '\0';

	return Local_u8ErrorState;


}

u8 USART_u8ReceiveStringUntil(u8 * Pointer_u8ReceiveBuffer, u8 Copy_u8StopCharacter) {

	u8 Local_u8ErrorState = OK;
	u8 Local_u8Counter = 0;

	USART_u8ReceiveDataSynchronous( &(Pointer_u8ReceiveBuffer[0]) );


	while( Pointer_u8ReceiveBuffer[Local_u8Counter] != Copy_u8StopCharacter) {

		Local_u8Counter++;
		USART_u8ReceiveDataSynchronous( &(Pointer_u8ReceiveBuffer[Local_u8Counter]) );

	}

	Local_u8Counter++;
	Pointer_u8ReceiveBuffer[Local_u8Counter] = '\0';


	/*
	if( Pointer_u8ReceiveBuffer[0] == Copy_u8StopCharacter) {
		//nothing
	} else {
		Local_u8Counter++;

		while( Pointer_u8ReceiveBuffer[Local_u8Counter] != Copy_u8StopCharacter) {

			USART_u8ReceiveDataSynchronous( &(Pointer_u8ReceiveBuffer[Local_u8Counter]) );
			Local_u8Counter++;

		}
	}

*/


	return Local_u8ErrorState;

}

void USART_voidReceiveDataAsynchronous(u8 * Pointer_u8Data) {

	if(USART_RECEIVE_FLAG == RECEIVED) {
		*Pointer_u8Data = USART_ReceiveBuffer;
		USART_RECEIVE_FLAG = IDLE;
	}
}


void USART_voidEnableInterrupt(u8 Copy_u8InterruptType) {


	switch(Copy_u8InterruptType) {
	case(USART_RX_BUFFER_NOT_EMPTY_INT): 	SET_BIT(USART1_START_ADDRESS->CR1, CR1_RXNEIE);  break;
	case(USART_TX_COMPLETE_INT): 	        SET_BIT(USART1_START_ADDRESS->CR1, CR1_TCIE);  break;
	case(USART_TX_BUFFER_EMPTY_INT): 		SET_BIT(USART1_START_ADDRESS->CR1, CR1_TXEIE);  break;
	}

}

void USART_voidDisableInterrupt(u8 Copy_u8InterruptType) {


	switch(Copy_u8InterruptType) {
	case(USART_RX_BUFFER_NOT_EMPTY_INT): 	CLR_BIT(USART1_START_ADDRESS->CR1, CR1_RXNEIE);  break;
	case(USART_TX_COMPLETE_INT): 	        CLR_BIT(USART1_START_ADDRESS->CR1, CR1_TCIE);  break;
	case(USART_TX_BUFFER_EMPTY_INT): 		CLR_BIT(USART1_START_ADDRESS->CR1, CR1_TXEIE);  break;
	}

}


void USART_voidClearInterruptFlag(void) {


	CLR_BIT(USART1_START_ADDRESS->SR, SR_TC);


}



void USART1_IRQHandler(void) {




	if(GET_BIT(USART1_START_ADDRESS->SR, SR_TXE) == 1) {

		USART_SEND_FLAG = IDLE;
		USART_voidDisableInterrupt(USART_TX_BUFFER_EMPTY_INT);

	}


	if(GET_BIT(USART1_START_ADDRESS->SR, SR_RXNE) == 1) {
		USART_ReceiveBuffer = USART1_START_ADDRESS->DR;
		USART_RECEIVE_FLAG = RECEIVED;
		//USART_voidDisableInterrupt(USART_RX_BUFFER_NOT_EMPTY_INT);
	}


}


