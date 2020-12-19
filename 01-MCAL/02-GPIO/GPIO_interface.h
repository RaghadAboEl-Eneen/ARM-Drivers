/*********************************************************************/
/*********************************************************************/
/******** Author:Raghad Mohamed    ***********************************/
/******** Component:GPIO           ***********************************/
/******** Layer:    MCAL           ***********************************/
/******** Date: 20/11/2020		   ***********************************/
/******** Version:  1.0            ***********************************/
/*********************************************************************/
/*********************************************************************/


#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


#define GPIO_PIN0				0
#define GPIO_PIN1				1
#define GPIO_PIN2				2
#define GPIO_PIN3				3
#define GPIO_PIN4				4
#define GPIO_PIN5				5
#define GPIO_PIN6				6
#define GPIO_PIN7				7
#define GPIO_PIN8				8
#define GPIO_PIN9				9
#define GPIO_PIN10				10
#define GPIO_PIN11				11
#define GPIO_PIN12				12
#define GPIO_PIN13				13
#define GPIO_PIN14				14
#define GPIO_PIN15				15

#define GPIO_PORTA				0
#define GPIO_PORTB				1
#define GPIO_PORTC				2

#define GPIO_PORT_OUTPUT		1
#define GPIO_PORT_INPUT			0

#define GPIO_PIN_OUTPUT			1
#define GPIO_PIN_INPUT			0


#define GPIO_OUTPUT_TEN_MHZ			1
#define GPIO_OUTPUT_TWO_MHZ			2
#define GPIO_OUTPUT_FIFTY_MHZ		3

#define GPIO_PORT_LOW			0x00000000
#define GPIO_PORT_HIGH			0xFFFF

#define GPIO_PIN_LOW			0
#define GPIO_PIN_HIGH			1

#define G_PUSH_PULL				0
#define	G_OPEN_DRAIN			4
#define AF_PUSH_PULL			8
#define AF_OPEN_DRAIN			12

#define ANALOG_MODE				0
#define FLOATING_INPUT			4
#define INPUT_PA_OR_PD  		8

#define GPIO_INPUT_PIN_PULL_UP 		1
#define GPIO_INPUT_PIN_PULL_DOWN	0
#define GPIO_INPUT_PORT_PULL_UP		0xFFFF
#define GPIO_INPUT_PORT_PULL_DOWN	0x00000000

u8 GPIO_u8SetPortDirectionAndMode(u8 Copy_u8Port, u8 Copy_u8Direction, u8 Copy_u8Mode,u8 Copy_u8Configs);
u8 GPIO_u8SetPinDirectionAndMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction, u8 Copy_u8Mode,u8 Copy_u8Configs);
u8 GPIO_u8SetPortValue(u8 Copy_u8Port,u16 Copy_u16Value);
u8 GPIO_u8SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin, u8 Copy_u8Value);
u8 GPIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 * Copy_pu8PinValue);

#endif
