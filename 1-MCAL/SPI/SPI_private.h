/*
 * SPI_private.h
 *
 *  Created on: 24 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

typedef struct{

	u8 bidimode;	/* Bidirectional data mode enable 		*/
	u8 bidioe;      /* Output enable in bidirectional mode  */
	u8 crcen;       /* Hardware CRC calculation enable 		*/
	u8 crcnext;		/* CRC transfer next 					*/
	u8 dff;			/* Data frame format 					*/
	u8 rxonly;		/* Receive only 						*/
	u8 ssm;			/* Software slave management 			*/
	u8 lsbfirst;	/* Frame format 						*/
	u8 spe;			/* SPI enable 							*/
	u8 br;			/* Baud rate control 					*/
	u8 mstr;		/* Master Selection 					*/
	u8 cpol;        /* Clock polarity 						*/
	u8 cpha;		/* Clock Phase 							*/
	u8 txeie;		/* Tx buffer empty interrupt enable		*/
	u8 rxneie;		/* Rx buffer not empty interrupt enable */
	u8 errie;		/* Error interrupy enable 				*/
	u8 ssoe;		/* SS output enable 					*/
	u8 txdmaen;		/* Tx buffer DMA enable 				*/
	u8 rxdmaen;		/* Rx buffer DMA enable 				*/

}SPI_Config_t;


#endif /* SPI_PRIVATE_H_ */
