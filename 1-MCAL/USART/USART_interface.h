/*
 * USART_interface.h
 *
 *  Created on: 21 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_


#define USART_DISABLE			0
#define USART_ENABLE			1


#define USART_8_DATA_BITS		0
#define USART_9_DATA_BITS		1


#define USART_PARITY_DISABLED	0
#define USART_PARITY_ENABLED	1

#define USART_DISABLE_TRANSMITTER		0
#define USART_ENABLE_TRANSMITTER		1

#define USART_DISABLE_RECEIVER			0
#define USART_ENABLE_RECEIVER			1


#define USART_1_STOP_BIT				0
#define USART_2_STOP_BIT				2


void USART_voidInitUSART1(void);
void USART_voidInitUSART2(void);
void USART_voidInitUSART3(void);

u8 USART_u8SendDataSynchronous(u8 Copy_u8Data);
u8 USART_u8ReceiveDataSynchronous(u8 * Pointer_u8Data);

#endif /* USART_INTERFACE_H_ */
