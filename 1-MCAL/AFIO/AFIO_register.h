/*
 * AFIO_register.h
 *
 *  Created on: 11 Aug 2022
 *      Author: es-RaghadAly2023
 */

#ifndef AFIO_REGISTER_H_
#define AFIO_REGISTER_H_


#define AFIO_BASE_ADDRESS	0x40010000






#define AFIO_EVCR		    *( (volatile u32*) (AFIO_BASE_ADDRESS + 0x00) )	/* Event Control Register                          */
#define AFIO_MAPR		    *( (volatile u32*) (AFIO_BASE_ADDRESS + 0x04) ) /* AF Remap and Debug I/O Configuration Register 1 */

#define AFIO_EXTICR1	    *( (volatile u32*) (AFIO_BASE_ADDRESS + 0x08) ) /* External Interrupt Configuration Register 1     */
#define AFIO_EXTICR2	    *( (volatile u32*) (AFIO_BASE_ADDRESS + 0x0C) ) /* External Interrupt Configuration Register 2     */
#define AFIO_EXTICR3	    *( (volatile u32*) (AFIO_BASE_ADDRESS + 0x10) ) /* External Interrupt Configuration Register 3     */
#define AFIO_EXTICR4	    *( (volatile u32*) (AFIO_BASE_ADDRESS + 0x14) ) /* External Interrupt Configuration Register 4     */

#define AFIO_MAPR2		    *( (volatile u32*) (AFIO_BASE_ADDRESS + 0x1C) ) /* AF Remap and Debug I/O Configuration Register 2 */


#endif /* AFIO_REGISTER_H_ */
