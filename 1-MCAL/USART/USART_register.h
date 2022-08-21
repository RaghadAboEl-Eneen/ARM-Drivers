/*
 * USART_register.h
 *
 *  Created on: 21 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_



typedef struct{

	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;

}USART_t;

#define USART1_START_ADDRESS    ((volatile USART_t*) 0x40013800)
#define USART2_START_ADDRESS    ((volatile USART_t*) 0x40014400)
#define USART3_START_ADDRESS    ((volatile USART_t*) 0x40014800)

#define SR_TXE				    7			/* Transmit Data Register Empty*/
#define SR_TC				    6			/* Transmission Complete */
#define SR_RXNE				    5			/* Read Data Register Not Empty */

#define BRR_DIV_FRACTION		0
#define BRR_DIV_MANTISSA		4

#define CR1_UE					13
#define CR1_M					12
#define CR1_PCE					10
#define CR1_PS					9
#define CR1_TE					3
#define CR1_RE					2



#endif /* USART_REGISTER_H_ */
