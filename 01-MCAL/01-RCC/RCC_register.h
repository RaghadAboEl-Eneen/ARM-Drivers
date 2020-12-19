/*********************************************************************/
/*********************************************************************/
/******** Author:Raghad Mohamed    ***********************************/
/******** Component:RCC            ***********************************/
/******** Layer:    MCAL           ***********************************/
/******** Version:  1.0            ***********************************/
/*********************************************************************/
/*********************************************************************/



#ifndef RCC_REGISTER_H_
#define RCC_REGISTER_H_


#define CR 			*((volatile u32 * ) 0x40021000)			//Clock Control Register
#define CR_PLLRDY	25
#define CR_PPLON	24
#define CR_CSSON	19
#define CR_HSEBYP	18
#define CR_HSERDY	17
#define CR_HSEON	16
#define CR_HSIRDY	1
#define CR_HSION	0

#define CFGR 		*((volatile u32 * ) 0x40021004)			//Clock Configuartion Register
#define CFGR_MCO2	26
#define CFGR_MCO1	25
#define CFGR_MCO0	24
#define CFGR_USBPRE	22
#define CFGR_PLLXTPRE	17
#define CFGR_PLLSRC		16
#define CFGR_SWS1		3
#define CFGR_SWS0		2
#define CFGR_SW1		1
#define CFGR_SW0		0




#define CIR 		*((volatile u32 * ) 0x40021008)			//Clock Interrupt Register
#define APB2RSTR 	*((volatile u32 * ) 0x4002100C)			//APB2 Peripheral Reset Register
#define APB1RSTR 	*((volatile u32 * ) 0x40021010)			//APB1 Peripheral Reset Register
#define AHBENR 		*((volatile u32 * ) 0x40021014)			//AHB Peripheral Clock Enable Register
#define APB2ENR 	*((volatile u32 * ) 0x40021018)			//APB2 Peripheral Clock Enable Register
#define APB1ENR 	*((volatile u32 * ) 0x4002101C)			//APB1 Peripheral Clock Enable Register
#define BDCR 		*((volatile u32 * ) 0x40021020)			//Backup Domain Control Register
#define CSR 		*((volatile u32 * ) 0x40021024)			//Control/Status Register



#endif
