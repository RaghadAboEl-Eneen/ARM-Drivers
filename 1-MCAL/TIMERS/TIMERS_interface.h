/*
 * TIMERS_interface.h
 *
 *  Created on: 2 Nov 2022
 *      Author: es-RaghadAly2023
 */

#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_


#define TIMER2		0
#define TIMER3		1
#define TIMER4		2
#define TIMER5		3

#define CHANNEL1	0
#define CHANNEL2	1
#define CHANNEL3	2
#define CHANNEL4	3

#define PWM_MODE_1	6


void TIMER2_init(void);
void TIMER3_init(void);
void TIMER4_init(void);
void TIMER5_init(void);

void TIMERS_setFrequency(u8 Copy_u8Timer, u16 Copy_u16NumberOfTicks);
void TIMERS_setCompareMatchValue(u8 Copy_u8Timer, u8 Copy_u8Channel, u16 Copy_u16NumberOfTicks);



#endif /* TIMERS_INTERFACE_H_ */
