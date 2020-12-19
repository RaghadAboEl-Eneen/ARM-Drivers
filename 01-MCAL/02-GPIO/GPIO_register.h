/*********************************************************************/
/*********************************************************************/
/******** Author:Raghad Mohamed    ***********************************/
/******** Component:GPIO           ***********************************/
/******** Layer:    MCAL           ***********************************/
/******** Date: 20/11/2020		   ***********************************/
/******** Version:  1.0            ***********************************/
/*********************************************************************/
/*********************************************************************/

#ifndef GPIO_REGISTER_H_
#define GPIO_REGISTER_H_

#define GPIOA_BASE	0x040010800
#define GPIOB_BASE	0x040010C00
#define GPIOC_BASE	0x040011000

#define GPIOx_CRL_OFFSET		0x00
#define GPIOx_CRH_OFFSET		0x04
#define GPIOx_IDR_OFFSET		0x08
#define GPIOx_ODR_OFFSET		0x0C
#define GPIOx_BSRR_OFFSET		0x10
#define GPIOx_BRR_OFFSET		0x14
#define GPIOx_LCKR_OFFSET		0x18

#define GPIOA_CRL  *((volatile u32*) (GPIOA_BASE + GPIOx_CRL_OFFSET)  )
#define GPIOA_CRH  *((volatile u32*) (GPIOA_BASE + GPIOx_CRH_OFFSET)  )
#define GPIOA_IDR  *((volatile u32*) (GPIOA_BASE + GPIOx_IDR_OFFSET)  )
#define GPIOA_ODR  *((volatile u32*) (GPIOA_BASE + GPIOx_ODR_OFFSET)  )
#define GPIOA_BSRR *((volatile u32*) (GPIOA_BASE + GPIOx_BSRR_OFFSET) )
#define GPIOA_BRR  *((volatile u32*) (GPIOA_BASE + GPIOx_BRR_OFFSET)  )
#define GPIOA_LCKR *((volatile u32*) (GPIOA_BASE + GPIOx_LCKR_OFFSET) )

#define GPIOB_CRL  *((volatile u32*) (GPIOB_BASE + GPIOx_CRL_OFFSET)  )
#define GPIOB_CRH  *((volatile u32*) (GPIOB_BASE + GPIOx_CRH_OFFSET)  )
#define GPIOB_IDR  *((volatile u32*) (GPIOB_BASE + GPIOx_IDR_OFFSET)  )
#define GPIOB_ODR  *((volatile u32*) (GPIOB_BASE + GPIOx_ODR_OFFSET)  )
#define GPIOB_BSRR *((volatile u32*) (GPIOB_BASE + GPIOx_BSRR_OFFSET) )
#define GPIOB_BRR  *((volatile u32*) (GPIOB_BASE + GPIOx_BRR_OFFSET)  )
#define GPIOB_LCKR *((volatile u32*) (GPIOB_BASE + GPIOx_LCKR_OFFSET) )

#define GPIOC_CRL  *((volatile u32*) (GPIOC_BASE + GPIOx_CRL_OFFSET)  )
#define GPIOC_CRH  *((volatile u32*) (GPIOC_BASE + GPIOx_CRH_OFFSET)  )
#define GPIOC_IDR  *((volatile u32*) (GPIOC_BASE + GPIOx_IDR_OFFSET)  )
#define GPIOC_ODR  *((volatile u32*) (GPIOC_BASE + GPIOx_ODR_OFFSET)  )
#define GPIOC_BSRR *((volatile u32*) (GPIOC_BASE + GPIOx_BSSR_OFFSET) )
#define GPIOC_BRR  *((volatile u32*) (GPIOC_BASE + GPIOx_BRR_OFFSET)  )
#define GPIOC_LCKR *((volatile u32*) (GPIOC_BASE + GPIOx_LCKR_OFFSET) )

#endif
