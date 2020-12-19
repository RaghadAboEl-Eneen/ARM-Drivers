/*********************************************************************/
/*********************************************************************/
/******** Author:Raghad Mohamed    ***********************************/
/******** Component:GPIO           ***********************************/
/******** Layer:    MCAL           ***********************************/
/******** Date: 20/11/2020		   ***********************************/
/******** Version:  1.0            ***********************************/
/*********************************************************************/
/*********************************************************************/


#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_

/*Selecting the maximum output speed.
 * Options:1-TWO_MHZ
 * 		   2-TEN_MHZ
 * 		   3-FIFTY_MHZ
 **/
#define OUTPUT_SPEED_MAX TWO_MHZ

/*Selecting the output mode.
 * Options:1-G_PUSH_PULL
 * 		   2-G_OPEN_DRAIN
 * 		   3-AF_PUSH_PULL
 * 		   4-AF_OPEN_DRAIN
 **/
//#define OUTPUT_MODE   G_PUSH_PULL

/*Selecting the input mode.
 * Options:1-ANALOG_MODE
 * 		   2-FLOATING_INPUT
 * 		   3-INPUT_PA_OR_PD
 **/
//#define INPUT_MODE   INPUT_PA_OR_PD



#endif
