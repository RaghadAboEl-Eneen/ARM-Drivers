/*
 * Servo_interface.h
 *
 *  Created on: 21 Dec 2022
 *      Author: es-RaghadAly2023
 */

#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_


typedef struct {
	u8 ServoPort;
	u8 ServoPin;
	u8 ServoTimer;
	u8 ServoChannel;
	u8 Enable;
}Servo_t;


void Servo_init(void);
void Servo_setAngle(Servo_t Servo, u16 Copy_u16Angle);
Servo_t  Servo_attach(u8 Copy_u8Port,u8 Copy_u8Pin);


#endif /* SERVO_INTERFACE_H_ */
