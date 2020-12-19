/*********************************************************************/
/*********************************************************************/
/******** Author:Raghad Mohamed    ***********************************/
/******** Component:RCC            ***********************************/
/******** Layer:    MCAL           ***********************************/
/******** Version:  1.0            ***********************************/
/*********************************************************************/
/*********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
#include "RCC_register.h"


void RCC_voidInit(void) {

#if RCC_CLOCK_SELECT == HSI

	/*Enabling the HSI clock*/
	SET_BIT(CR,CR_HSION);
	/*Polling until it is ready*/
	while(GET_BIT(CR,CR_HSIRDY) == 0);

#elif RCC_CLOCK_SELECT == HSE

	/*Selecting the external clock*/
#if RCC_HSE_SOURCE == CRYSTAL
	CLR_BIT(CR, CR_HSEBYP);

	/*Enabling the HSE clock*/
	SET_BIT(CR,CR_HSEON);

	/*Polling until it is ready*/
	while(GET_BIT(CR,CR_HSERDY) == 0);


#elif RCC_HSE_SOURCE == RC
	SET_BIT(CR,CR_HSEBYP);

#else
#error ("wrong HSE_SOURCE configuration")

#endif

#elif RCC_CLOCK_SELECT == PLL

	/*Setting the PLL source*/
#if RCC_PLL_INPUT == PLL_HSE
	SET_BIT(CFGR,CFGR_PLLSRC);
#elif RCC_PLL_INPUT == PLL_HSI_DIVIDE_2
	CLR_BIT(CFGR,CFGR_PLLSRC);
#elif RCC_PLL_INPUT == PLL_HSE_DIVIDE_2
	  SET_BIT(CFGR,CFGR_PLLXTPRE);



#endif
	/*Polling until it is ready*/
	while(GET_BIT(CR,CR_PLLRDY) == 0);


#else
#error ("Invalid CLOCK_SELECT configuration")

#endif

}
	void RCC_voidEnableClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID) {

		if (Copy_u8PeripheralID < 32) {
			switch (Copy_u8BusID) {
			case RCC_AHB:
				SET_BIT(AHBENR, Copy_u8PeripheralID);
				break;
			case RCC_APB1:
				SET_BIT(APB1ENR, Copy_u8PeripheralID);
				break;
			case RCC_APB2:
				SET_BIT(APB2ENR, Copy_u8PeripheralID);
				break;
			}
		}

	}

	void RCC_voidDisableClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID) {

		if (Copy_u8PeripheralID < 32) {
			switch (Copy_u8BusID) {
			case RCC_AHB:
				CLR_BIT(AHBENR, Copy_u8PeripheralID);
				break;
			case RCC_APB1:
				CLR_BIT(APB1ENR, Copy_u8PeripheralID);
				break;
			case RCC_APB2:
				CLR_BIT(APB2ENR, Copy_u8PeripheralID);
				break;
			}
		}

	}

