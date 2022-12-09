/*
 * TIMERS_program.c
 *
 *  Created on: 2 Nov 2022
 *      Author: es-RaghadAly2023
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_registers.h"
#include "TIMERS_config.h"


volatile TIMERS_REG_t  * TIMERS_base_array[4] = { TIMER2_BASE, TIMER3_BASE, TIMER4_BASE, TIMER5_BASE };

void TIMER2_init(void) {


u32 Local_u32OC1M_mask = CCMR1_OC1M << THREE_BIT_MASK;
u32 Local_u32OC2M_mask = CCMR1_OC2M << THREE_BIT_MASK;

Local_u32OC1M_mask = ~Local_u32OC1M_mask;
Local_u32OC2M_mask = ~Local_u32OC2M_mask;


TIMERS_setFrequency(TIMER2, 53333);

/* setting PWM mode */
TIMER2_BASE->CCMR1 &= Local_u32OC1M_mask;
TIMER2_BASE->CCMR1 |= CCMR1_OC1M << PWM_MODE_1;

TIMER2_BASE->CCMR1 &= Local_u32OC2M_mask;
TIMER2_BASE->CCMR1 |= CCMR1_OC2M << PWM_MODE_1;

TIMER2_BASE->CCMR2 &= Local_u32OC1M_mask;
TIMER2_BASE->CCMR2 |= CCMR2_OC3M << PWM_MODE_1;

TIMER2_BASE->CCMR2 &= Local_u32OC2M_mask;
TIMER2_BASE->CCMR2 |= CCMR2_OC4M << PWM_MODE_1;


TIMERS_setCompareMatchValue(TIMER2, CHANNEL2, 30000);


/* enabling preload registers */
SET_BIT(TIMER2_BASE->CCMR1, CCMR1_OC1PE);
SET_BIT(TIMER2_BASE->CCMR1, CCMR1_OC2PE);

SET_BIT(TIMER2_BASE->CCMR2, CCMR2_OC3PE);
SET_BIT(TIMER2_BASE->CCMR2, CCMR2_OC4PE);


/* Output enable*/
SET_BIT(TIMER2_BASE->CCER, CCER_CC1E);
SET_BIT(TIMER2_BASE->CCER, CCER_CC2E);
SET_BIT(TIMER2_BASE->CCER, CCER_CC3E);
SET_BIT(TIMER2_BASE->CCER, CCER_CC4E);


/* Auto reload preload enable*/
//SET_BIT(TIMER2_BASE->CR1, CR1_ARPE);

/* start */
//SET_BIT(TIMER2_BASE->EGR, EGR_UG);

SET_BIT(TIMER2_BASE->CR1, CR1_CEN);


}

void TIMERS_setFrequency(u8 Copy_u8Timer, u16 Copy_u16NumberOfTicks) {

	TIMERS_base_array[Copy_u8Timer]->ARR = Copy_u16NumberOfTicks;

}


void TIMERS_setCompareMatchValue(u8 Copy_u8Timer, u8 Copy_u8Channel, u16 Copy_u16NumberOfTicks){

	switch(Copy_u8Channel) {

	case(CHANNEL1): TIMERS_base_array[Copy_u8Timer]->CCR1 = Copy_u16NumberOfTicks;  break;
	case(CHANNEL2): TIMERS_base_array[Copy_u8Timer]->CCR2 = Copy_u16NumberOfTicks;  break;
	case(CHANNEL3): TIMERS_base_array[Copy_u8Timer]->CCR3 = Copy_u16NumberOfTicks;  break;
	case(CHANNEL4): TIMERS_base_array[Copy_u8Timer]->CCR4 = Copy_u16NumberOfTicks;  break;
	default:	break;

	}


}

