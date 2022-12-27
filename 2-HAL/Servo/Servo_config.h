/*
 * Servo_config.h
 *
 *  Created on: 21 Dec 2022
 *      Author: es-RaghadAly2023
 */

#ifndef SERVO_CONFIG_H_
#define SERVO_CONFIG_H_

// Timer 2 Channel 2 -> PA1 / PB5 / PB3
#define SERVO_1_PORT		GPIO_PORTA
#define SERVO_1_PIN			GPIO_PIN1
#define SERVO_1_TIMER		TIMER2
#define SERVO_1_CHANNEL		CHANNEL2
#define SERVO_1_ENABLE		YES

// Timer 2 Channel 3 -> PA2
#define SERVO_2_PORT		GPIO_PORTA
#define SERVO_2_PIN			GPIO_PIN2
#define SERVO_2_TIMER		TIMER2
#define SERVO_2_CHANNEL		CHANNEL3
#define SERVO_2_ENABLE		YES

// Timer 2 Channel  4 -> PA3
#define SERVO_3_PORT		GPIO_PORTA
#define SERVO_3_PIN			GPIO_PIN3
#define SERVO_3_TIMER		TIMER2
#define SERVO_3_CHANNEL		CHANNEL4
#define SERVO_3_ENABLE		YES

// Timer 3 Channel 1 -> PA6 / PB4
#define SERVO_4_PORT		GPIO_PORTA
#define SERVO_4_PIN			GPIO_PIN6
#define SERVO_4_TIMER		TIMER3
#define SERVO_4_CHANNEL		CHANNEL1
#define SERVO_4_ENABLE		YES

//Timer 3 Channel 2 -> PA7
#define SERVO_5_PORT		GPIO_PORTA
#define SERVO_5_PIN			GPIO_PIN7
#define SERVO_5_TIMER		TIMER3
#define SERVO_5_CHANNEL		CHANNEL2
#define SERVO_5_ENABLE		YES

//Timer 3 Channel 3 -> PB0
#define SERVO_6_PORT		GPIO_PORTB
#define SERVO_6_PIN			GPIO_PIN0
#define SERVO_6_TIMER		TIMER3
#define SERVO_6_CHANNEL		CHANNEL3
#define SERVO_6_ENABLE		YES

//Timer 3 Channel 4 -> PB1
#define SERVO_7_PORT		GPIO_PORTB
#define SERVO_7_PIN			GPIO_PIN1
#define SERVO_7_TIMER		TIMER3
#define SERVO_7_CHANNEL		CHANNEL4
#define SERVO_7_ENABLE		NO




#endif /* SERVO_CONFIG_H_ */
