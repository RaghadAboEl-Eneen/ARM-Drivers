/*
 * SEVENSEG_config.h
 *
 *  Created on: 5 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef SEVENSEG_CONFIG_H_
#define SEVENSEG_CONFIG_H_



/*
 * Choose Port connected to seven segment
 * Options: 1- GPIO_PORTA
 * 			2- GPIO_PORTB
 */
#define SEVENSEGMENT1	GPIO_PORTA
#define SEVENSEGMENT2 	GPIO_PORTB


#define SEVENSEGMENT1_CONTORL_PORT	GPIO_PORTA
#define SEVENSEGMENT2_CONTORL_PORT	GPIO_PORTA


#define SEVENSEGMENT1_CONTROL_PIN	10
#define SEVENSEGMENT2_CONTROL_PIN	11




#endif /* SEVENSEG_CONFIG_H_ */
