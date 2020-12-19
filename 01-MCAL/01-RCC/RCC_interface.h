/*********************************************************************/
/*********************************************************************/
/******** Author:Raghad Mohamed    ***********************************/
/******** Component:RCC            ***********************************/
/******** Layer:    MCAL           ***********************************/
/******** Version:  1.0            ***********************************/
/*********************************************************************/
/*********************************************************************/


#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_


#define RCC_AHB			1
#define RCC_APB1		2
#define RCC_APB2		3



void RCC_voidInit(void);

void RCC_voidEnableClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID);
void RCC_voidDisableClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID);


#endif
