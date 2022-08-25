/*
 * SPI_interface.h
 *
 *  Created on: 24 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


#define SPI_1		0
#define SPI_2		1


#define SPI_2_LINE_UNIDIRECTIONAL_DATA_MODE	0
#define SPI_1_LINE_BIDRECTIONAL_DATA_MODE 	1

#define SPI_RECEIVE_ONLY_MODE	0
#define SPI_TRANSMIT_ONLY_MODE	1

#define SPI_DISABLE		0
#define SPI_ENABLE		1

#define SPI_DATA_PHASE		0
#define SPI_CRC_PHASE		1

#define SPI_8_BIT_DATA		0
#define SPI_16_BIT_DATA		1

#define	SPI_FULL_DUPLEX			0
#define SPI_RECEIVE_ONLY		1

#define SPI_MSB_FORMAT	0
#define SPI_LSB_FORMAT	1

#define SPI_CLK_PRE_2			0
#define SPI_CLK_PRE_4			1
#define SPI_CLK_PRE_8			2
#define SPI_CLK_PRE_16			3
#define SPI_CLK_PRE_32			4
#define SPI_CLK_PRE_64			5
#define SPI_CLK_PRE_128			6
#define SPI_CLK_PRE_256			7

#define SPI_SLAVE_MODE		0
#define SPI_MASTER_MODE		1

#define	SPI_LOW_WHEN_IDLE	0
#define SPI_HIGH_WHEN_IDLE	1

#define	SPI_DATA_SAMPLED_ON_RISING_EDGE 	0
#define SPI_DATA_SAMPLED_ON_FALLING_EDGE	1




void SPI_voidInit(void);

u8 SPI_u8SendDataSynchronous(u8 Copy_u8SPI_Number, u8 Copy_u8Data);
u8 SPI_u8ReceiveDataSynchronous(u8 Copy_u8SPI_Number, u8 * Pointer_u8Data);
u8 SPI_u8SendArrayOfDataSynchronous(u8 Copy_u8SPI_Number, const u8 * Pointer_u8Data, u16 Copy_u16DataLen);
u8 SPI_u8ReceiveArrayOfDataSynchronous(u8 Copy_u8SPI_Number, u8 * Pointer_u8Data, u16 Copy_u16DataLen);

u8 SPI_u8EnableSPI(u8 Copy_u8SPI_Number);
u8 SPI_u8DisableSPI(u8 Copy_u8SPI_Number);

#endif /* SPI_INTERFACE_H_ */
