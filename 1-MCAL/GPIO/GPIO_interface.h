/*
 * GPIO_interface.h
 *
 *  Created on: 4 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


#define GPIO_PORTA		0
#define GPIO_PORTB		1
#define GPIO_PORTC		2

#define GPIO_PIN_LOW	0
#define GPIO_PIN_HIGH	1

#define GPIO_PORT_LOW	0x0000
#define GPIO_PORT_HIGH	0xFFFF



#define GPIO_PIN_MODE_ANALOG_INPUT		0b0000
#define GPIO_PIN_MODE_FLOATING_INPUT	0b0100
#define GPIO_PIN_MODE_PULLING_INPUT		0b1000

#define GPIO_PIN_MODE_GP_PP_2MHZ		0b0010
#define GPIO_PIN_MODE_GP_PP_10MHZ		0b0001
#define GPIO_PIN_MODE_GP_PP_50MHZ		0b0011

#define GPIO_PIN_MODE_GP_OD_2MHZ		0b0110
#define GPIO_PIN_MODE_GP_OD_10MHZ		0b0101
#define GPIO_PIN_MODE_GP_OD_50MHZ		0b0111

#define GPIO_PIN_MODE_AF_PP_2MHZ		0b1010
#define GPIO_PIN_MODE_AF_PP_10MHZ       0b1001
#define GPIO_PIN_MODE_AF_PP_50MHZ       0b1011

#define GPIO_PIN_MODE_AF_OD_2MHZ        0b1110
#define GPIO_PIN_MODE_AF_OD_10MHZ       0b1101
#define GPIO_PIN_MODE_AF_OD_50MHZ       0b1111



void GPIO_init(void);



/**
 * @param Copy_u8Port
 * @param Copy_u8Pin
 * @param Copy_u8Mode
 * @return
 */
u8 GPIO_u8SetPinMode(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinMode);


/**
 * @param Copy_u8Port
 * @param Copy_u8PortMode
 * @return
 */
u8 GPIO_u8SetPortMode(u8 Copy_u8Port, u8 Copy_u8PortMode);



/**
 * @param Copy_u8Port
 * @param Copy_u8Pin
 * @param Copy_u8Value
 * @return
 */
u8 GPIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);


/**
 * @param Copy_u8Port
 * @param Copy_u8PortValue
 * @return
 */
u8 GPIO_u8SetPortValue(u8 Copy_u8Port, u16 Copy_u16PortValue);




/**
 * @param Copy_u8Port
 * @param Copy_u8Pin
 * @param Ptr_u8Value
 * @return
 */
u8 GPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Ptr_u8Value);


#endif /* GPIO_INTERFACE_H_ */
