/*
 * SYSTICK_program.c
 *
 *  Created on: 11 Aug 2022
 *      Author: es-RaghadAly2023
 */




#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_register.h"
#include "SYSTICK_config.h"


void (*CallBack)(void) = (void *) 0;
u8 IntervalState = SYSTICK_PERIODIC_INTERVAL;

/*
 * STK_voidInit
 * description: Selects the clock source of the SysTick (AHB, AHB/8)
 */
void STK_voidInit(u8 Copy_u8ClkSRC){

	switch(Copy_u8ClkSRC)
	{
	case SYSTICK_AHB_8:
		CLR_BIT(SYSTICK->CTRL, SYSTICK_CTRL_CLKSOURCE);
		break;
	case SYSTICK_AHB:
		SET_BIT(SYSTICK->CTRL, SYSTICK_CTRL_CLKSOURCE);
		break;
	}

}


/*
 * STK_voidStopTimer
 * description: Stops the Timer
 */
void STK_voidStopTimer(void){



	/* stop the timer */
	CLR_BIT(SYSTICK->CTRL, SYSTICK_CTRL_ENABLE);

	/* reset the flag */
	SYSTICK->VAL = 0;

}



/*
 * STK_voidSetBusyWait
 * description: Starts a synchronous wait (delay)
 */
void STK_voidSetBusyWait(u32 Copy_u32TickCount){


	/* Disable the systick interrupt*/
	CLR_BIT(SYSTICK->CTRL, SYSTICK_CTRL_TICKINT);

	/* Set LOAD value */
	SYSTICK->LOAD = (Copy_u32TickCount - 1) & 0x00FFFFFF;

	SYSTICK->VAL = 0;

	/* start the timer */
	SET_BIT(SYSTICK->CTRL, SYSTICK_CTRL_ENABLE);

	/* empty loop until the flag is raised */
	while(!(GET_BIT(SYSTICK->CTRL, SYSTICK_CTRL_COUNTFLAG))){
		__asm("NOP");
	}

	/* stop the timer */
	CLR_BIT(SYSTICK->CTRL, SYSTICK_CTRL_ENABLE);

	/* reset the flag */
	SYSTICK->VAL = 0;


	/* Reset the LOAD register */
	SYSTICK->LOAD = 0;




}


/*
 * STK_voidSetPeriodicInterval
 * description: Starts a periodic interval asynchronous wait
 */

void STK_voidSetPeriodicInterval(u32 Copy_u32TickCount, void (*ptr)(void)){


	/* Set LOAD value	*/
	IntervalState = SYSTICK_PERIODIC_INTERVAL;
	SYSTICK->LOAD = (Copy_u32TickCount - 1) & 0x00FFFFFF;

	/* assign the callback function to the handler	*/
	CallBack = ptr;

	/* Enable the interrupt	*/
	SET_BIT(SYSTICK->CTRL, SYSTICK_CTRL_TICKINT);

	/* start the timer	*/
	SET_BIT(SYSTICK->CTRL, SYSTICK_CTRL_ENABLE);
}


/*
 * STK_voidSetSingleInterval
 * description: Starts a single interval asynchronous wait
 */
void STK_voidSetSingleInterval(u32 Copy_u32TickCount, void (*ptr)(void)){



	/* Set LOAD value */
	IntervalState = SYSTICK_SINGLE_INTERVAL;
	SYSTICK->LOAD = (Copy_u32TickCount - 1) & 0x00FFFFFF;

	/* assign the callback function to the handler */
	CallBack = ptr;

	/* Enable the interrupt */
	SET_BIT(SYSTICK->CTRL, SYSTICK_CTRL_TICKINT);

	/* start the timer */
	SET_BIT(SYSTICK->CTRL, SYSTICK_CTRL_ENABLE);
}


/*
 * STK_u32GetRemainingTicks
 * description: Gets the number of ticks remaining until we reach zero
 */
u32 STK_u32GetRemainingTicks(void){

	u32 Local_u32RemainingTicks = SYSTICK->CTRL;

	return Local_u32RemainingTicks;
}

/*
 * STK_u32GetElapsedTicks
 * description: Gets the number of ticks elapsed since we started counting
 */
u32 STK_u32GetElapsedTicks(void){


	u32 Local_u32ElapsedTicks = SYSTICK->LOAD = SYSTICK->VAL;

	return Local_u32ElapsedTicks;
}

void SysTick_Handler(void){
	CallBack();
	if(IntervalState == SYSTICK_PERIODIC_INTERVAL){

		//continue

	}else{
		CLR_BIT(SYSTICK->CTRL, SYSTICK_CTRL_ENABLE);
	}
	SYSTICK->VAL = 0; // Clearing the flag
}
