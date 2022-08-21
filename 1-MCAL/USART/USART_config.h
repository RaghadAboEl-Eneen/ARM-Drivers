/*
 * USART_config.h
 *
 *  Created on: 21 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_


#define USART_BAUD_RATE			9600

#define USART1_ENABLE			USART_ENABLE
#define USART2_ENABLE			USART_DISABLE
#define USART3_ENABLE			USART_DISABLE


#define USART1_NUMBER_OF_DATA_BITS		USART_8_DATA_BITS
#define USART2_NUMBER_OF_DATA_BITS		USART_8_DATA_BITS
#define USART3_NUMBER_OF_DATA_BITS		USART_8_DATA_BITS

#define USART1_PARITY_BIT_ENABLED		USART_PARITY_DISABLED
#define USART2_PARITY_BIT_ENABLED       USART_PARITY_DISABLED
#define USART3_PARITY_BIT_ENABLED       USART_PARITY_DISABLED

#define USART1_ENABLE_TRANSMITTER		USART_ENABLE_TRANSMITTER
#define USART2_ENABLE_TRANSMITTER		USART_ENABLE_TRANSMITTER
#define USART3_ENABLE_TRANSMITTER		USART_ENABLE_TRANSMITTER

#define USART1_ENABLE_RECEIVER			USART_ENABLE_RECEIVER
#define USART2_ENABLE_RECEIVER			USART_ENABLE_RECEIVER
#define USART3_ENABLE_RECEIVER			USART_ENABLE_RECEIVER


#define USART1_NUMBER_OF_STOP_BITS		USART_1_STOP_BIT
#define USART2_NUMBER_OF_STOP_BITS		USART_1_STOP_BIT
#define USART3_NUMBER_OF_STOP_BITS		USART_1_STOP_BIT


#endif /* USART_CONFIG_H_ */
