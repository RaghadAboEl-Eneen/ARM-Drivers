/*
 * ESP_interface.h
 *
 *  Created on: 30 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef ESP_INTERFACE_H_
#define ESP_INTERFACE_H_


#define USER_SSID 			(u8*)"Raghad"
#define USER_PASSWORD		(u8*)"alex4all"
#define USER_IP				(u8*)"156.218.43.185"


void ESP_voidInit(void);
u8 	 ESP_u8ConnectToWIFI(u8* SSID, u8* password);
u8   ESP_u8ConnectToSite(u8* IP);
u8	 ESP_u8Send(u8* IP, u8* data);
u8 ESP_u8SendCommand(u8 * Pointer_u8Command, u8 * Pointer_u8ReceiveBuffer, u8 * Pointer_u8OkStateString);


#endif /* ESP_INTERFACE_H_ */
