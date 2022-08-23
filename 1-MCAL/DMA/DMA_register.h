/*
 * DMA_register.h
 *
 *  Created on: 23 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef DMA_REGISTER_H_
#define DMA_REGISTER_H_



typedef struct{

	volatile u32 CCR; 					/* DMA Channel x Configuration Register */
	volatile u32 CNDTR; 				/* DMA Channel x Number of Data Register*/
	volatile u32 CPAR; 					/* DMA Channel x Peripheral Address Register */
	volatile u32 CMAR; 					/* DMA Channel x Memory Address Register*/
	volatile u32 RES;

}DMA_Channel_t;

typedef struct{

	volatile u32 ISR; 					/* DMA Interrupt Status Register */
	volatile u32 IFCR; 					/* DMA Interrupt Flag Clear Register*/

	volatile DMA_Channel_t channel[7];

}DMA_REG_t;


 /* DMA1->Channel[0].CRR = 0x00 */

#define DMA1_BASE	 ((volatile DMA_REG_t*) 0x40020000)


#define CCR_MEM2MEM	14
#define CCR_PL2		13
#define CCR_PL1		12
#define CCR_MSIZE2	11
#define CCR_MSIZE1	10
#define CCR_PSIZE2	9
#define CCR_PSIZE1	8
#define CCR_MINC	7
#define CCR_PINC	6
#define CCR_CIRC	5
#define CCR_DIR		4
#define CCR_TEIE	3
#define CCR_HTIE	2
#define CCR_TCIE	1
#define CCR_EN		0

#define IFCR_CTEIF	3
#define IFCR_CHTIF	2
#define IFCR_CTCIF	1
#define IFCR_CGIF	0

#endif /* DMA_REGISTER_H_ */
