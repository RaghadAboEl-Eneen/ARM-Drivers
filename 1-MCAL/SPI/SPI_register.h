/*
 * SPI_register.h
 *
 *  Created on: 24 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_



typedef struct{

	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;

}SPI_REG_t;

#define SPI1_BASE		((volatile SPI_REG_t*) 0x40013000)
#define SPI2_BASE		((volatile SPI_REG_t*) 0x40003800)



#define CR1_BIDIMODE	15
#define CR1_BIDIOE 		14
#define CR1_CRCEN		13
#define CR1_CRCNEXT		12
#define CR1_DFF			11
#define CR1_RXONLY		10
#define CR1_SSM			9
#define CR1_SSI			8
#define CR1_LSBFIRST	7
#define CR1_SPE			6
#define CR1_BR2			5
#define CR1_BR1			4
#define CR1_BR0			3
#define CR1_MSTR		2
#define CR1_CPOL		1
#define CR1_CPHA		0


#define CR2_TXEIE		7
#define CR2_RXNEIE		6
#define CR2_ERRIE		5
#define CR2_SSOE		2
#define CR2_TXDMAEN		1
#define CR2_RXDMAEN		0


#define SR_BSY			7
#define SR_OVR			6
#define SR_MODF			5
#define SR_CRCERR		4
#define SR_UDR			3
#define SR_CHSIDE		2
#define SR_TXE			1
#define SR_RXNE			0


#endif /* SPI_REGISTER_H_ */
