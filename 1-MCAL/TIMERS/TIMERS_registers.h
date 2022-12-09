/*
 * TIMERS_registers.h
 *
 *  Created on: 2 Nov 2022
 *      Author: es-RaghadAly2023
 */

#ifndef TIMERS_REGISTERS_H_
#define TIMERS_REGISTERS_H_


typedef struct{

	u32 CR1;
	u32 CR2;
	u32 SMCR;
	u32 DIER;
	u32 SR;
	u32 EGR;
	u32 CCMR1;
	u32 CCMR2;
	u32 CCER;
	u32 CNT;
	u32 PSC;
	u32 ARR;
	u32 res1;
	u32 CCR1;
	u32 CCR2;
	u32 CCR3;
	u32 CCR4;
	u32 res;
	u32 DCR;
	u32 DMAR;

}TIMERS_REG_t;

#define TIMER2_BASE		((volatile TIMERS_REG_t*) 0x40000000)
#define TIMER3_BASE		((volatile TIMERS_REG_t*) 0x40000400)
#define TIMER4_BASE		((volatile TIMERS_REG_t*) 0x40000800)
#define TIMER5_BASE		((volatile TIMERS_REG_t*) 0x40000C00)

#define CR1_CEN			0
#define CR1_ARPE		7

#define CCMR1_OC2M		12
#define CCMR1_OC2PE		11
#define CCMR1_OC1M		4
#define CCMR1_OC1PE		3

#define CCMR2_OC4M		12
#define CCMR2_OC4PE		11
#define CCMR2_OC3M		4
#define CCMR2_OC3PE		3


#define EGR_UG			0

#define CCER_CC4E		12
#define CCER_CC3E		8
#define CCER_CC2E		4
#define CCER_CC1E		0






#endif /* TIMERS_REGISTERS_H_ */
