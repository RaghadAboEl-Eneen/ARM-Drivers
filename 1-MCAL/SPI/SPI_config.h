/*
 * SPI_config.h
 *
 *  Created on: 24 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_



/* Choose Uni or Bi directional data mode
 * Options: 1- SPI_2_LINE_UNIDIRECTIONAL_DATA_MODE
 * 			2- SPI_1_LINE_BIDRECTIONAL_DATA_MODE
 **/
#define SPI1_DATA_DIRECTION_MODE 		SPI_2_LINE_UNIDIRECTIONAL_DATA_MODE
#define SPI2_DATA_DIRECTION_MODE 		SPI_2_LINE_UNIDIRECTIONAL_DATA_MODE


/* Choose Receive only or Transmit only in Bidirectional Mode
 * Options: 1- SPI_RECEIVE_ONLY_MODE
 * 			2- SPI_TRANSMIT_ONLY_MODE
 **/
#define SPI1_BIDIRECTIONAL_MODE_CONFIG	SPI_RECEIVE_ONLY_MODE
#define SPI2_BIDIRECTIONAL_MODE_CONFIG	SPI_RECEIVE_ONLY_MODE


/* Enable or Disable Hardware CRC calculation
 * Options: 1- SPI_DISABLE
 * 			2- SPI_ENABLE
 **/
#define SPI1_HARDWARE_CRC_EN	SPI_DISABLE
#define SPI2_HARDWARE_CRC_EN	SPI_DISABLE


/* Select CRC transfer next mode
 * Options: 1- SPI_DATA_PHASE
 * 			2- SPI_CRC_PHASE
 **/
#define SPI1_CRC_TRANSFER_NEXT		SPI_DATA_PHASE
#define SPI2_CRC_TRANSFER_NEXT		SPI_CRC_PHASE


/* Select the data frame format
 * Options: 1- SPI_8_BIT_DATA
 * 			2- SPI_16_BIT_DATA
 **/
#define SPI1_DATA_FRAME_FORMAT		SPI_8_BIT_DATA
#define SPI2_DATA_FRAME_FORMAT		SPI_8_BIT_DATA


/* Select SPI mode to be full duplex or receive only
 * Options: 1- SPI_FULL_DUPLEX
 * 			2- SPI_RECEIVE_ONLY
 **/
#define SPI1_FULL_DUPLEX_EN		SPI_FULL_DUPLEX
#define SPI2_FULL_DUPLEX_EN		SPI_FULL_DUPLEX


/* Enable or disable software slave management
 * Options: 1- SPI_DISABLE
 * 			2- SPI_ENABLE
 **/
#define SPI1_SOFTWARE_SLAVE_MANAGEMENT_EN	SPI_DISABLE
#define SPI2_SOFTWARE_SLAVE_MANAGEMENT_EN	SPI_DISABLE


/* Select frame format MSB/LSB
 * Options: 1- SPI_MSB_FORMAT
 * 			2- SPI_LSB_FORMAT
 **/
#define SPI1_FRAME_FORMAT	SPI_MSB_FORMAT
#define SPI2_FRAME_FORMAT	SPI_LSB_FORMAT


/* Enable or Disable the SPI peripheral
 * Options: 1- SPI_DISABLE
 * 			2- SPI_ENABLE
 **/
#define SPI1_EN		SPI_ENABLE
#define SPI2_EN		SPI_DISABLE


/* Select Baud rate prescalar
 * Options: 1- SPI_CLK_PRE_2
 * 			2- SPI_CLK_PRE_4
 * 			2- SPI_CLK_PRE_8
 * 			2- SPI_CLK_PRE_16
 * 			2- SPI_CLK_PRE_32
 * 			2- SPI_CLK_PRE_64
 * 			2- SPI_CLK_PRE_128
 * 			2- SPI_CLK_PRE_256
 **/
#define SPI1_BAUD_RATE_PRE	SPI_CLK_PRE_2
#define SPI2_BAUD_RATE_PRE	SPI_CLK_PRE_2


/* Select SPI mode to be master or slave
 * Options: 1- SPI_MASTER_MODE
 * 			2- SPI_SLAVE_MODE
 **/
#define SPI1_MASTER_SLAVE_MODE		SPI_MASTER_MODE
#define SPI2_MASTER_SLAVE_MODE		SPI_SLAVE_MODE


/* Select the clock polarity
 * Options: 1- SPI_LOW_WHEN_IDLE
 * 			2- SPI_HIGH_WHEN_IDLE
 **/
#define SPI1_CLOCK_POLARITY		SPI_LOW_WHEN_IDLE
#define SPI2_CLOCK_POLARITY		SPI_LOW_WHEN_IDLE


/* Select the clock phase
 * Options: 1- SPI_DATA_SAMPLED_ON_RISING_EDGE
 * 			2- SPI_DATA_SAMPLED_ON_FALLING_EDGE
 **/
#define SPI1_CLOCK_PHASE	SPI_DATA_SAMPLED_ON_RISING_EDGE
#define SPI2_CLOCK_PHASE	SPI_DATA_SAMPLED_ON_RISING_EDGE


/* Enable or Disable transmit buffer empty interrupt
 * Options: 1- SPI_DISABLE
 * 			2- SPI_ENABLE
 **/
#define SPI1_TX_BUFFER_EMPTY_EN		SPI_DISABLE
#define SPI2_TX_BUFFER_EMPTY_EN		SPI_DISABLE


/* Enable or Disable receive buffer not empty interrupt
 * Options: 1- SPI_DISABLE
 * 			2- SPI_ENABLE
 **/
#define SPI1_RX_BUFFER_NOT_EMPTY_EN		SPI_DISABLE
#define SPI2_RX_BUFFER_NOT_EMPTY_EN		SPI_DISABLE


/* Enable or Disable error interrupt
 * Options: 1- SPI_DISABLE
 * 			2- SPI_ENABLE
 **/
#define SPI1_ERROR_INTERRUPT_EN		SPI_DISABLE
#define SPI2_ERROR_INTERRUPT_EN		SPI_DISABLE


/* Enable or Disable SS output
 * Options: 1- SPI_DISABLE
 * 			2- SPI_ENABLE
 **/
#define SPI1_SS_OUTPUT_EN	SPI_ENABLE
#define SPI2_SS_OUTPUT_EN	SPI_DISABLE


/* Enable or Disable transmit buffer dma mode
 * Options: 1- SPI_DISABLE
 * 			2- SPI_ENABLE
 **/
#define SPI1_TX_DMA_MODE_EN		SPI_DISABLE
#define SPI2_TX_DMA_MODE_EN		SPI_DISABLE


/* Enable or Disable receive buffer dma mode
 * Options: 1- SPI_DISABLE
 * 			2- SPI_ENABLE
 **/
#define SPI1_RX_DMA_MODE_EN		SPI_DISABLE
#define SPI2_RX_DMA_MODE_EN		SPI_DISABLE


#endif /* SPI_CONFIG_H_ */
