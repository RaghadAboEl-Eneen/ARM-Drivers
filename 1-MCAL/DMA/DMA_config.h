/*
 * DMA_config.h
 *
 *  Created on: 23 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef DMA_CONFIG_H_
#define DMA_CONFIG_H_


/* Enable or Disable the memory to memory mode
 * Options: 1-DMA_DISABLE
 * 			2-DMA_ENABLE
 **/
#define DMA_CHANNEL0_MEMORY_TO_MEMORY_MODE		DMA_ENABLE


/* Select the Channel Priority Level
 * Options: 1-DMA_CHANNEL_PRIORITY_LOW
 * 			2-DMA_CHANNEL_PRIORITY_MEDIUM
 * 			3-DMA_CHANNEL_PRIORITY_HIGH
 * 			4-DMA_CHANNEL_PRIORITY_VERY_HIGH
 **/
#define DMA_CHANNEL0_PRIORITY_LEVEL		DMA_CHANNEL_PRIORITY_VERY_HIGH


/* Select the Memory Size
 * Options: 1-DMA_MEMORY_SIZE_8_BITS
 * 			2-DMA_MEMORY_SIZE_16_BITS
 * 			3-DMA_MEMORY_SIZE_32_BITS
 **/
#define DMA_CHANNEL0_MEMORY_SIZE		DMA_MEMORY_SIZE_8_BITS


/* Select the Peripheral Size
 * Options: 1-DMA_PERIPHERAL_SIZE_8_BITS
 * 			2-DMA_PERIPHERAL_SIZE_16_BITS
 * 			3-DMA_PERIPHERAL_SIZE_32_BITS
 **/
#define DMA_CHANNEL0_PERIPHERAL_SIZE		DMA_MEMORY_SIZE_8_BITS


/* Enable or Disable the memory increment mode
 * Options: 1-DMA_DISABLE
 * 			2-DMA_ENABLE
 **/
#define DMA_CHANNEL0_MEMORY_INCREMENT_MODE	DMA_ENABLE


/* Enable or Disable the peripheral increment mode
 * Options: 1-DMA_DISABLE
 * 			2-DMA_ENABLE
 **/
#define DMA_CHANNEL0_PERIPHERAL_INCREMENT_MODE	DMA_ENABLE


/* Enable or Disable the circular mode
 * Options: 1-DMA_DISABLE
 * 			2-DMA_ENABLE
 **/
#define DMA_CHANNEL0_CIRCULAR_MODE	DMA_DISABLE


/* Choose the data transfer direction
 * Options: 1-DMA_READ_FROM_PERIPHERAL
 * 			2-DMA_READ_FROM_MEMORY
 **/
#define DMA_CHANNEL0_DATA_TRANSFER_DIRECTION 	DMA_READ_FROM_PERIPHERAL









#endif /* DMA_CONFIG_H_ */
