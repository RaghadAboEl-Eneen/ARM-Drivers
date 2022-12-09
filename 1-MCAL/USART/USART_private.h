/*
 * USART_private.h
 *
 *  Created on: 21 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_


typedef struct{

	u16 baudrate;
	u8 ue;
	u8 m;
	u8 pce;
	u8 te;
	u8 re;
	u8 stop;
	u8 tcie;
	u8 rxneie;
	u8 dmat;
	u8 dmar;





}USART_Config_t;






/* USART1 is in APB2*/
/* USART2 and USART3 is in APB1 */

#define IDLE			0
#define RECEIVED		1
#define SENDING			2

#endif /* USART_PRIVATE_H_ */
