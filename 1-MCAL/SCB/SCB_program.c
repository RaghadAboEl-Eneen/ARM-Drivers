/*
 * SCB_program.c
 *
 *  Created on: 11 Aug 2022
 *      Author: es-RaghadAly2023
 */


#include "BIT_MATH.h"
#include "STD_TYPES.h"


#include "SCB_interface.h"
#include "SCB_private.h"
#include "SCB_register.h"
#include "SCB_config.h"




void SCB_voidInit() {

	SCB_AIRCR = SCB_PRIORITY_DISTRIBUTION;


}

