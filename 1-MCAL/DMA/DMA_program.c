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

void DMA_voidInit(void) {

	u32 Local_u32CCR_Buffer = 0x00000000;
	u32 Local_u32RegisterMask = 0xFFFFFFFF;

	CLR_BIT(Local_u32RegisterMask, CCR_MEM2MEM);
	Local_u32CCR_Buffer &= Local_u32RegisterMask;
	Local_u32CCR_Buffer |= DMA_CHANNEL0_MEMORY_TO_MEMORY_MODE << CCR_MEM2MEM;

	Local_u32RegisterMask = 0xFFFFFFFF;

	CLR_BIT(Local_u32RegisterMask, CCR_PL1);
	CLR_BIT(Local_u32RegisterMask, CCR_PL2);
	Local_u32CCR_Buffer &= Local_u32RegisterMask;
	Local_u32CCR_Buffer |= DMA_CHANNEL0_PRIORITY_LEVEL << CCR_PL1;

	Local_u32RegisterMask = 0xFFFFFFFF;

	CLR_BIT(Local_u32RegisterMask, CCR_MSIZE1);
	CLR_BIT(Local_u32RegisterMask, CCR_MSIZE2);
	Local_u32CCR_Buffer &= Local_u32RegisterMask;
	Local_u32CCR_Buffer |= DMA_CHANNEL0_MEMORY_SIZE << CCR_MSIZE1;

	Local_u32RegisterMask = 0xFFFFFFFF;

	CLR_BIT(Local_u32RegisterMask, CCR_PSIZE1);
	CLR_BIT(Local_u32RegisterMask, CCR_PSIZE2);
	Local_u32CCR_Buffer &= Local_u32RegisterMask;
	Local_u32CCR_Buffer |= DMA_CHANNEL0_PERIPHERAL_SIZE << CCR_PSIZE1;

	Local_u32RegisterMask = 0xFFFFFFFF;

	CLR_BIT(Local_u32RegisterMask, CCR_MINC);
	Local_u32CCR_Buffer &= Local_u32RegisterMask;
	Local_u32CCR_Buffer |= DMA_CHANNEL0_MEMORY_INCREMENT_MODE << CCR_MINC;

	Local_u32RegisterMask = 0xFFFFFFFF;

	CLR_BIT(Local_u32RegisterMask, CCR_PINC);
	Local_u32CCR_Buffer &= Local_u32RegisterMask;
	Local_u32CCR_Buffer |= DMA_CHANNEL0_PERIPHERAL_INCREMENT_MODE << CCR_PINC;

	Local_u32RegisterMask = 0xFFFFFFFF;

	CLR_BIT(Local_u32RegisterMask, CCR_CIRC);
	Local_u32CCR_Buffer &= Local_u32RegisterMask;
	Local_u32CCR_Buffer |= DMA_CHANNEL0_CIRCULAR_MODE << CCR_CIRC;

	Local_u32RegisterMask = 0xFFFFFFFF;

	CLR_BIT(Local_u32RegisterMask, CCR_DIR);
	Local_u32CCR_Buffer &= Local_u32RegisterMask;
	Local_u32CCR_Buffer |= DMA_CHANNEL0_DATA_TRANSFER_DIRECTION << CCR_DIR;

	DMA1_BASE->channel[0].CCR = Local_u32CCR_Buffer;


	SET_BIT(DMA1_BASE->channel[0].CCR, CCR_TCIE);


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

void DMA_voidClearInterruptFlag() {


	SET_BIT(DMA1_BASE->IFCR, IFCR_CGIF);


}
