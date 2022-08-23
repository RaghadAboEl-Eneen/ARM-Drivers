/*
 * DMA_interface.h
 *
 *  Created on: 23 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

#define DMA_CHANNEL0		0
#define DMA_CHANNEL1        1
#define DMA_CHANNEL2        2
#define DMA_CHANNEL3        3
#define DMA_CHANNEL4        4
#define DMA_CHANNEL5        5
#define DMA_CHANNEL6        6

#define DMA_DISABLE			0
#define DMA_ENABLE			1

#define DMA_CHANNEL_PRIORITY_LOW		0
#define DMA_CHANNEL_PRIORITY_MEDIUM		1
#define DMA_CHANNEL_PRIORITY_HIGH		2
#define DMA_CHANNEL_PRIORITY_VERY_HIGH	3

#define DMA_MEMORY_SIZE_8_BITS			0
#define DMA_MEMORY_SIZE_16_BITS			1
#define DMA_MEMORY_SIZE_32_BITS			2

#define DMA_PERIPHERAL_SIZE_8_BITS			0
#define DMA_PERIPHERAL_SIZE_16_BITS			1
#define DMA_PERIPHERAL_SIZE_32_BITS			2

#define DMA_READ_FROM_PERIPHERAL		0
#define DMA_READ_FROM_MEMORY			1


void DMA_voidInit(void);

void DMA_voidClearInterruptFlag(void);

u8 DMA_u8EnableChannel(u8 Copy_u8ChannelNumber);
u8 DMA_u8DisableChannel(u8 Copy_u8ChannelNumber);
u8 DMA_u8SetNumberOfDataToTransfer(u16 Copy_u16DataAmount, u8 Copy_u8ChannelNumber);
u8 DMA_u8SetPeripheralAddress(u32  Copy_u32PeripheralAddress, u8 Copy_u8ChannelNumber);
u8 DMA_u8SetMemoryAddress(u32  Copy_u32MemoryAddress, u8 Copy_u8ChannelNumber);


#endif /* DMA_INTERFACE_H_ */
