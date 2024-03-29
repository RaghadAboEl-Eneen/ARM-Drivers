/*
 * DMA_program.c
 *
 *  Created on: 23 Aug 2022
 *      Author: es-RaghadAly2023
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_register.h"
#include "DMA_config.h"

const DMA_Config_t DMA_Channel_Configurations[7] = {

	{DMA_CHANNEL0_MEMORY_TO_MEMORY_MODE, DMA_CHANNEL0_PRIORITY_LEVEL, DMA_CHANNEL0_MEMORY_SIZE, DMA_CHANNEL0_PERIPHERAL_SIZE, DMA_CHANNEL0_MEMORY_INCREMENT_MODE, DMA_CHANNEL0_PERIPHERAL_INCREMENT_MODE, DMA_CHANNEL0_CIRCULAR_MODE, DMA_CHANNEL0_DATA_TRANSFER_DIRECTION, DMA_CHANNEL0_TRANSFER_ERROR_INTERRUPT_EN, DMA_CHANNEL0_HALF_TRANSFER_INTERRUPT_EN, DMA_CHANNEL0_TRANSFER_COMPLETE_INTERRUPT_EN },
	{DMA_CHANNEL1_MEMORY_TO_MEMORY_MODE, DMA_CHANNEL1_PRIORITY_LEVEL, DMA_CHANNEL1_MEMORY_SIZE, DMA_CHANNEL1_PERIPHERAL_SIZE, DMA_CHANNEL1_MEMORY_INCREMENT_MODE, DMA_CHANNEL1_PERIPHERAL_INCREMENT_MODE, DMA_CHANNEL1_CIRCULAR_MODE, DMA_CHANNEL1_DATA_TRANSFER_DIRECTION, DMA_CHANNEL1_TRANSFER_ERROR_INTERRUPT_EN, DMA_CHANNEL1_HALF_TRANSFER_INTERRUPT_EN, DMA_CHANNEL1_TRANSFER_COMPLETE_INTERRUPT_EN },
	{DMA_CHANNEL2_MEMORY_TO_MEMORY_MODE, DMA_CHANNEL2_PRIORITY_LEVEL, DMA_CHANNEL2_MEMORY_SIZE, DMA_CHANNEL2_PERIPHERAL_SIZE, DMA_CHANNEL2_MEMORY_INCREMENT_MODE, DMA_CHANNEL2_PERIPHERAL_INCREMENT_MODE, DMA_CHANNEL2_CIRCULAR_MODE, DMA_CHANNEL2_DATA_TRANSFER_DIRECTION, DMA_CHANNEL2_TRANSFER_ERROR_INTERRUPT_EN, DMA_CHANNEL2_HALF_TRANSFER_INTERRUPT_EN, DMA_CHANNEL2_TRANSFER_COMPLETE_INTERRUPT_EN },
	{DMA_CHANNEL3_MEMORY_TO_MEMORY_MODE, DMA_CHANNEL3_PRIORITY_LEVEL, DMA_CHANNEL3_MEMORY_SIZE, DMA_CHANNEL3_PERIPHERAL_SIZE, DMA_CHANNEL3_MEMORY_INCREMENT_MODE, DMA_CHANNEL3_PERIPHERAL_INCREMENT_MODE, DMA_CHANNEL3_CIRCULAR_MODE, DMA_CHANNEL3_DATA_TRANSFER_DIRECTION, DMA_CHANNEL3_TRANSFER_ERROR_INTERRUPT_EN, DMA_CHANNEL3_HALF_TRANSFER_INTERRUPT_EN, DMA_CHANNEL3_TRANSFER_COMPLETE_INTERRUPT_EN },
	{DMA_CHANNEL4_MEMORY_TO_MEMORY_MODE, DMA_CHANNEL4_PRIORITY_LEVEL, DMA_CHANNEL4_MEMORY_SIZE, DMA_CHANNEL4_PERIPHERAL_SIZE, DMA_CHANNEL4_MEMORY_INCREMENT_MODE, DMA_CHANNEL4_PERIPHERAL_INCREMENT_MODE, DMA_CHANNEL4_CIRCULAR_MODE, DMA_CHANNEL4_DATA_TRANSFER_DIRECTION, DMA_CHANNEL4_TRANSFER_ERROR_INTERRUPT_EN, DMA_CHANNEL4_HALF_TRANSFER_INTERRUPT_EN, DMA_CHANNEL4_TRANSFER_COMPLETE_INTERRUPT_EN },
	{DMA_CHANNEL5_MEMORY_TO_MEMORY_MODE, DMA_CHANNEL5_PRIORITY_LEVEL, DMA_CHANNEL5_MEMORY_SIZE, DMA_CHANNEL5_PERIPHERAL_SIZE, DMA_CHANNEL5_MEMORY_INCREMENT_MODE, DMA_CHANNEL5_PERIPHERAL_INCREMENT_MODE, DMA_CHANNEL5_CIRCULAR_MODE, DMA_CHANNEL5_DATA_TRANSFER_DIRECTION, DMA_CHANNEL5_TRANSFER_ERROR_INTERRUPT_EN, DMA_CHANNEL5_HALF_TRANSFER_INTERRUPT_EN, DMA_CHANNEL5_TRANSFER_COMPLETE_INTERRUPT_EN },
	{DMA_CHANNEL6_MEMORY_TO_MEMORY_MODE, DMA_CHANNEL6_PRIORITY_LEVEL, DMA_CHANNEL6_MEMORY_SIZE, DMA_CHANNEL6_PERIPHERAL_SIZE, DMA_CHANNEL6_MEMORY_INCREMENT_MODE, DMA_CHANNEL6_PERIPHERAL_INCREMENT_MODE, DMA_CHANNEL6_CIRCULAR_MODE, DMA_CHANNEL6_DATA_TRANSFER_DIRECTION, DMA_CHANNEL6_TRANSFER_ERROR_INTERRUPT_EN, DMA_CHANNEL6_HALF_TRANSFER_INTERRUPT_EN, DMA_CHANNEL6_TRANSFER_COMPLETE_INTERRUPT_EN }

};

void DMA_voidInit(void) {


	u32 Local_u32CCR_Buffer= 0x00000000;
	u8  Local_u8Counter = 0;


	for(Local_u8Counter = 0; Local_u8Counter < 7; Local_u8Counter++) {

		Local_u32CCR_Buffer= 0x00000000;
		DMA1_BASE->channel[Local_u8Counter].CCR = 0;

		Local_u32CCR_Buffer |= DMA_Channel_Configurations[Local_u8Counter].mem2mem 	<< CCR_MEM2MEM;
		Local_u32CCR_Buffer |= DMA_Channel_Configurations[Local_u8Counter].pl 		<< CCR_PL1;
		Local_u32CCR_Buffer |= DMA_Channel_Configurations[Local_u8Counter].msize 	<< CCR_MSIZE1;
		Local_u32CCR_Buffer |= DMA_Channel_Configurations[Local_u8Counter].psize 	<< CCR_PSIZE1;
		Local_u32CCR_Buffer |= DMA_Channel_Configurations[Local_u8Counter].minc 	<< CCR_MINC;
		Local_u32CCR_Buffer |= DMA_Channel_Configurations[Local_u8Counter].pinc 	<< CCR_PINC;
		Local_u32CCR_Buffer |= DMA_Channel_Configurations[Local_u8Counter].circ 	<< CCR_CIRC;
		Local_u32CCR_Buffer |= DMA_Channel_Configurations[Local_u8Counter].dir  	<< CCR_DIR;
		Local_u32CCR_Buffer |= DMA_Channel_Configurations[Local_u8Counter].teie 	<< CCR_TEIE;
		Local_u32CCR_Buffer |= DMA_Channel_Configurations[Local_u8Counter].htie  	<< CCR_HTIE;
		Local_u32CCR_Buffer |= DMA_Channel_Configurations[Local_u8Counter].tcie  	<< CCR_TCIE;


		DMA1_BASE->channel[Local_u8Counter].CCR = Local_u32CCR_Buffer;
	}



}

u8 DMA_u8EnableChannel(u8 Copy_u8ChannelNumber) {

	u8 Local_u8ErrorState = OK;

	if (Copy_u8ChannelNumber < 7) {
		SET_BIT(DMA1_BASE->channel[Copy_u8ChannelNumber].CCR, CCR_EN);
	} else {
		Local_u8ErrorState = NOOK;
	}

	return Local_u8ErrorState;
}

u8 DMA_u8DisableChannel(u8 Copy_u8ChannelNumber) {

	u8 Local_u8ErrorState = OK;

	if (Copy_u8ChannelNumber < 7) {
		CLR_BIT(DMA1_BASE->channel[Copy_u8ChannelNumber].CCR, CCR_EN);
	} else {
		Local_u8ErrorState = NOOK;
	}

	return Local_u8ErrorState;
}

u8 DMA_u8SetPeripheralAddress(u32 Copy_u32PeripheralAddress, u8 Copy_u8ChannelNumber) {

	u8 Local_u8ErrorState = OK;

	DMA1_BASE->channel[Copy_u8ChannelNumber].CPAR = Copy_u32PeripheralAddress;

	return Local_u8ErrorState;

}

u8 DMA_u8SetMemoryAddress(u32 Copy_u32MemoryAddress, u8 Copy_u8ChannelNumber) {

	u8 Local_u8ErrorState = OK;

	DMA1_BASE->channel[Copy_u8ChannelNumber].CMAR = Copy_u32MemoryAddress;

	return Local_u8ErrorState;

}

u8 DMA_u8SetNumberOfDataToTransfer(u16 Copy_u16DataAmount, u8 Copy_u8ChannelNumber) {

	u8 Local_u8ErrorState = OK;

	DMA1_BASE->channel[Copy_u8ChannelNumber].CNDTR = Copy_u16DataAmount;

	return Local_u8ErrorState;

}

void DMA_voidClearInterruptFlag(u8 Copy_u8InterruptType, u8 Copy_u8ChannelNumber) {

	u8 Local_u8RegisterBit = (Copy_u8ChannelNumber * 4);


	switch(Copy_u8InterruptType) {

	case(DMA_CHANNEL_TRANSFER_ERROR_FLAG): 	  SET_BIT(DMA1_BASE->IFCR, (IFCR_CTEIF + Local_u8RegisterBit));  break;
	case(DMA_CHANNEL_HALF_TRANSFER_FLAG): 	  SET_BIT(DMA1_BASE->IFCR, (IFCR_CHTIF + Local_u8RegisterBit));  break;
	case(DMA_CHANNEL_TRANSFER_COMPLETE_FLAG): SET_BIT(DMA1_BASE->IFCR, (IFCR_CTCIF + Local_u8RegisterBit));  break;
	case(DMA_CHANNEL_GLOBAL_INTERRUPT_FLAG):  SET_BIT(DMA1_BASE->IFCR, (IFCR_CGIF  + Local_u8RegisterBit));  break;

	}
	SET_BIT(DMA1_BASE->IFCR, IFCR_CGIF);


}
