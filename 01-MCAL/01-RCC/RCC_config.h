/*********************************************************************/
/*********************************************************************/
/******** Author:Raghad Mohamed    ***********************************/
/******** Component:RCC            ***********************************/
/******** Layer:    MCAL           ***********************************/
/******** Version:  1.0            ***********************************/
/*********************************************************************/
/*********************************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*Choosing the System Clock
 * Options: 1-HSI (High speed internal clock)
 * 			2-HSE (High speed external clock)
 * 			3-PLL	(Phase locked loop clock)
 **/
#define RCC_CLOCK_SELECT	HSI

/*If HSE is the chosen clock , choose the external source
 * Options:	1-CRYSTAL
 * 			2-RC*/
#if RCC_CLOCK_SELECT == HSE
#define RCC_HSE_SOURCE	CRYSTAL
#endif

/*If Pll is the chosen clock , choose the input clock
 * Options:1-PLL_HSE
 * 		   2-PLL_HSE_DIVIDE_2
 * 		   3-PLL_HSI_DIVIDE_2*/
#if RCC_CLOCK_SELECT == PLL
#define RCC_PLL_INPUT 		PLL_HSE
#endif

#endif
