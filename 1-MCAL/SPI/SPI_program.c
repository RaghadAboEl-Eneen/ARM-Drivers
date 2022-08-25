/*
 * SPI_program.c
 *
 *  Created on: 24 Aug 2022
 *      Author: es-RaghadAly2023
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_register.h"
#include "SPI_config.h"

volatile SPI_REG_t * SPI_base_array[2] = { SPI1_BASE, SPI2_BASE };

const SPI_Config_t SPI_configurations[2] = {

{ 		SPI1_DATA_DIRECTION_MODE,
		SPI1_BIDIRECTIONAL_MODE_CONFIG,
		SPI1_HARDWARE_CRC_EN,
		SPI1_CRC_TRANSFER_NEXT,
		SPI1_DATA_FRAME_FORMAT,
		SPI1_FULL_DUPLEX_EN,
		SPI1_SOFTWARE_SLAVE_MANAGEMENT_EN,
		SPI1_FRAME_FORMAT,
		SPI1_EN, SPI1_BAUD_RATE_PRE,
		SPI1_MASTER_SLAVE_MODE,
		SPI1_CLOCK_POLARITY,
		SPI1_CLOCK_PHASE,
		SPI1_TX_BUFFER_EMPTY_EN,
		SPI1_RX_BUFFER_NOT_EMPTY_EN,
		SPI1_ERROR_INTERRUPT_EN,
		SPI1_SS_OUTPUT_EN,
		SPI1_TX_DMA_MODE_EN,
		SPI1_RX_DMA_MODE_EN },

{		SPI2_DATA_DIRECTION_MODE,
		SPI2_BIDIRECTIONAL_MODE_CONFIG,
		SPI2_HARDWARE_CRC_EN,
		SPI2_CRC_TRANSFER_NEXT,
		SPI2_DATA_FRAME_FORMAT,
		SPI2_FULL_DUPLEX_EN,
		SPI2_SOFTWARE_SLAVE_MANAGEMENT_EN,
		SPI2_FRAME_FORMAT,
		SPI2_EN,
		SPI2_BAUD_RATE_PRE,
		SPI2_MASTER_SLAVE_MODE,
		SPI2_CLOCK_POLARITY,
		SPI2_CLOCK_PHASE,
		SPI2_TX_BUFFER_EMPTY_EN,
		SPI2_RX_BUFFER_NOT_EMPTY_EN,
		SPI2_ERROR_INTERRUPT_EN,
		SPI2_SS_OUTPUT_EN,
		SPI2_TX_DMA_MODE_EN,
		SPI2_RX_DMA_MODE_EN }

};

void SPI_voidInit(void) {

	u32 Local_u32CR1_Buffer = 0x00000000;
	u32 Local_u32CR2_Buffer = 0x00000000;
	u8 Local_u8Counter = 0;

	//SPI1_BASE->CR1 = 68;
	//SPI1_BASE->CR2 = 8;

	for (Local_u8Counter = 0; Local_u8Counter < 2; Local_u8Counter++) {

		Local_u32CR1_Buffer = 0x00000000;
		Local_u32CR2_Buffer = 0x00000000;

		SPI_base_array[Local_u8Counter]->CR1 = 0x00000000;
		SPI_base_array[Local_u8Counter]->CR2 = 0x00000000;

		Local_u32CR1_Buffer |= SPI_configurations[Local_u8Counter].bidimode		<< CR1_BIDIMODE;
		Local_u32CR1_Buffer |= SPI_configurations[Local_u8Counter].bidioe		<< CR1_BIDIOE;
		Local_u32CR1_Buffer |= SPI_configurations[Local_u8Counter].crcen		<< CR1_CRCEN;
		Local_u32CR1_Buffer |= SPI_configurations[Local_u8Counter].crcnext		<< CR1_CRCNEXT;
		Local_u32CR1_Buffer |= SPI_configurations[Local_u8Counter].dff			<< CR1_DFF;
		Local_u32CR1_Buffer |= SPI_configurations[Local_u8Counter].rxonly		<< CR1_RXONLY;
		Local_u32CR1_Buffer |= SPI_configurations[Local_u8Counter].ssm			<< CR1_SSM;
		Local_u32CR1_Buffer |= SPI_configurations[Local_u8Counter].lsbfirst		<< CR1_LSBFIRST;
		Local_u32CR1_Buffer |= SPI_configurations[Local_u8Counter].br 			<< CR1_BR0;
		Local_u32CR1_Buffer |= SPI_configurations[Local_u8Counter].mstr			<< CR1_MSTR;
		Local_u32CR1_Buffer |= SPI_configurations[Local_u8Counter].cpol			<< CR1_CPOL;
		Local_u32CR1_Buffer |= SPI_configurations[Local_u8Counter].cpha			<< CR1_CPHA;

		Local_u32CR2_Buffer |= SPI_configurations[Local_u8Counter].txeie		<< CR2_TXEIE;
		Local_u32CR2_Buffer |= SPI_configurations[Local_u8Counter].rxneie		<< CR2_RXNEIE;
		Local_u32CR2_Buffer |= SPI_configurations[Local_u8Counter].errie		<< CR2_ERRIE;
		Local_u32CR2_Buffer |= SPI_configurations[Local_u8Counter].ssoe			<< CR2_SSOE;
		Local_u32CR2_Buffer |= SPI_configurations[Local_u8Counter].txdmaen		<< CR2_TXDMAEN;
		Local_u32CR2_Buffer |= SPI_configurations[Local_u8Counter].txdmaen		<< CR2_RXDMAEN;

		SPI_base_array[Local_u8Counter]->CR1 = Local_u32CR1_Buffer;
		SPI_base_array[Local_u8Counter]->CR2 = Local_u32CR2_Buffer;

		/* Enabling the SPI after setting up all the configurations */
		SPI_base_array[Local_u8Counter]->CR1 |= SPI_configurations[Local_u8Counter].spe << CR1_SPE;

	}

}

u8 SPI_u8SendDataSynchronous(u8 Copy_u8SPI_Number, u8 Copy_u8Data) {

	u8 Local_u8ErrorState = OK;
	u8 Local_u8Temp = 0;

	/* Check that transmit buffer is already empty */
	while ((GET_BIT(SPI_base_array[Copy_u8SPI_Number]->SR, SR_TXE)) == 0);

	/* Load the data into the DR register */
	SPI_base_array[Copy_u8SPI_Number]->DR = Copy_u8Data;

	/* Wait for the TXE flag to be set*/
	while ((GET_BIT(SPI_base_array[Copy_u8SPI_Number]->SR, SR_TXE)) == 0);

	/* Wait for the RXNE flag to be set */
	while ((GET_BIT(SPI_base_array[Copy_u8SPI_Number]->SR, SR_RXNE)) == 0);

	/* Read DR so RXNE flag gets cleared again */
	Local_u8Temp = SPI_base_array[Copy_u8SPI_Number]->DR;

	/* Wait for busy flag to be cleared */
	while ((GET_BIT(SPI_base_array[Copy_u8SPI_Number]->SR, SR_BSY)) == 1);

	delay_ms(20);




	return Local_u8ErrorState;
}

u8 SPI_u8ReceiveDataSynchronous(u8 Copy_u8SPI_Number, u8 * Pointer_u8Data) {

	u8 Local_u8ErrorState = OK;
	u8 Local_u8TempData = 0xFF;


	/* Load the data into the DR register */
	SPI_base_array[Copy_u8SPI_Number]->DR = Local_u8TempData;

	/* Wait for the TXE flag to be set */
	while ((GET_BIT(SPI_base_array[Copy_u8SPI_Number]->SR, SR_TXE)) != 1);

	/* Wait for the RXNE flag to be set */
	while ((GET_BIT(SPI_base_array[Copy_u8SPI_Number]->SR, SR_RXNE)) != 1);

	*Pointer_u8Data = SPI_base_array[Copy_u8SPI_Number]->DR;

	delay_ms(20);


	return Local_u8ErrorState;
}

u8 SPI_u8SendArrayOfDataSynchronous(u8 Copy_u8SPI_Number,const u8 * Pointer_u8Data, u16 Copy_u16DataLen) {

	u8 Local_u8ErrorState = OK;
	u16 Local_u16Counter = 0;


	if( Copy_u8SPI_Number == SPI_1 || Copy_u8SPI_Number == SPI_2) {
		for(Local_u16Counter = 0; Local_u16Counter < Copy_u16DataLen; Local_u16Counter++) {
			SPI_u8SendDataSynchronous(Copy_u8SPI_Number, Pointer_u8Data[Local_u16Counter]);
		}
	} else {
		Local_u8ErrorState = NOOK;
	}


	return Local_u8ErrorState;

}


u8 SPI_u8ReceiveArrayOfDataSynchronous(u8 Copy_u8SPI_Number, u8 * Pointer_u8Data, u16 Copy_u16DataLen) {

	u8 Local_u8ErrorState = OK;
	u16 Local_u16Counter = 0;


	if( Copy_u8SPI_Number == SPI_1 || Copy_u8SPI_Number == SPI_2) {
		for(Local_u16Counter = 0; Local_u16Counter < Copy_u16DataLen; Local_u16Counter++) {
			SPI_u8ReceiveDataSynchronous(Copy_u8SPI_Number, &Pointer_u8Data[Local_u16Counter]);
		}
	} else {
		Local_u8ErrorState = NOOK;
	}


	return Local_u8ErrorState;

}




u8 SPI_u8EnableSPI(u8 Copy_u8SPI_Number) {

	u8 Local_u8ErrorState = OK;

	switch (Copy_u8SPI_Number) {

	case (SPI_1):
		SET_BIT(SPI1_BASE->CR1, CR1_SPE);
		break;

	case (SPI_2):
		SET_BIT(SPI2_BASE->CR1, CR1_SPE);
		break;

	default:
		Local_u8ErrorState = NOOK;
		break;

	}

	return Local_u8ErrorState;

}

u8 SPI_u8DisableSPI(u8 Copy_u8SPI_Number) {

	u8 Local_u8ErrorState = OK;

	switch (Copy_u8SPI_Number) {

	case (SPI_1):
		CLR_BIT(SPI1_BASE->CR1, CR1_SPE);
		break;

	case (SPI_2):
		CLR_BIT(SPI2_BASE->CR1, CR1_SPE);
		break;

	default:
		Local_u8ErrorState = NOOK;
		break;

	}

	return Local_u8ErrorState;

}

