/*
 * ESP_program.c
 *
 *  Created on: 30 Aug 2022
 *      Author: es-RaghadAly2023
 */

#include <string.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "USART_interface.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"


void ESP_voidInit(void) {

	u8 Local_u8ReceiveBuffer[100];
	u8 Local_u8Counter = 0;


	for(Local_u8Counter = 0; Local_u8Counter < 100; Local_u8Counter++) {
		Local_u8ReceiveBuffer[Local_u8Counter] = 0xFF;
	}


	ESP_u8SendCommand( (u8 *)"AT+RST\r\n", Local_u8ReceiveBuffer, (u8*)"OK");
	//USART_u8SendArrayOfDataSynchronous( (u8 *)"AT+RST\r\n");
	//USART_u8ReceiveArrayOfDataSynchronousWithTimeout(Local_u8ReceiveBuffer, 100000);

	USART_u8SendArrayOfDataSynchronous( (u8 *)"ATE0\r\n");
	USART_u8ReceiveArrayOfDataSynchronousWithTimeout(Local_u8ReceiveBuffer, 100000);

	USART_u8SendArrayOfDataSynchronous( (u8 *)"AT\r\n");
	USART_u8ReceiveArrayOfDataSynchronousWithTimeout(Local_u8ReceiveBuffer, 100000);


	Local_u8Counter = 5;

}


u8  ESP_u8ConnectToWIFI(u8* SSID, u8* password) {

	u8 Local_u8ErrorState = OK;
	u8 Local_u8ReceiveBuffer[4000];
	u8 Local_u8Counter = 0;

	for(Local_u8Counter = 0; Local_u8Counter < 100; Local_u8Counter++) {
		Local_u8ReceiveBuffer[Local_u8Counter] = 0xFF;
	}

	//USART_u8SendArrayOfDataSynchronous( (u8 *)"AT+CWMODE=1");
	//USART_u8ReceiveStringUntil(Local_u8ReceiveBuffer, 'K');

	USART_u8SendArrayOfDataSynchronous( (u8 *)"AT+CWJAP_CUR=\"");
	USART_u8SendArrayOfDataSynchronous( (u8 *)SSID);
	USART_u8SendArrayOfDataSynchronous( (u8 *)"\",\"");
	USART_u8SendArrayOfDataSynchronous( (u8 *)password);
	USART_u8SendArrayOfDataSynchronous( (u8 *)"\"\r\n");
	USART_u8ReceiveStringUntil(Local_u8ReceiveBuffer, 'D');


	return Local_u8ErrorState;

}

//u8   ESP_u8ConnectToSite(u8* IP);
//u8	 ESP_u8Send(u8* IP, u8* data);

u8 ESP_u8SendCommand(u8 * Pointer_u8Command, u8 * Pointer_u8ReceiveBuffer, u8 * Pointer_u8OkStateString) {

	u8 Local_u8ErrorState = OK;
	u8 * Local_u8Indicator = NULL;

	USART_u8SendArrayOfDataSynchronous(Pointer_u8Command);
	USART_u8ReceiveArrayOfDataSynchronousWithTimeout(Pointer_u8ReceiveBuffer, 100000);


	Local_u8Indicator = strstr(Pointer_u8ReceiveBuffer, Pointer_u8OkStateString);

	while(Local_u8Indicator == NULL) {

		USART_u8SendArrayOfDataSynchronous(Pointer_u8Command);
		USART_u8ReceiveArrayOfDataSynchronousWithTimeout(Pointer_u8ReceiveBuffer, 100000);
		Local_u8Indicator = strstr(Pointer_u8ReceiveBuffer, Pointer_u8OkStateString);

	}


	return Local_u8ErrorState;




}


