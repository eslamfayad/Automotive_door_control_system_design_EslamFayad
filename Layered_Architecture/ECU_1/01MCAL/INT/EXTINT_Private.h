/*
 * EXTINT_Private.h
 *
 * Created: 5/30/2021 11:47:12 PM
 *  Author: EslamFayad
 */ 


#ifndef EXTINT_PRIVATE_H_
#define EXTINT_PRIVATE_H_
#include "STD_TYPES.h"
#define EXTINT_GICR_REG					(*(volatile uint_8*)0x5B)  /*	Bit	 7		 6	     5	
																		INT1    INT0    INT2 
															Read/Write  R/W     R/W     R/W    */

#define EXTINT_MCUCR_REG				(*(volatile uint_8*)0x55) /* Bit   3      2        1     0
																     ISC11 ISC10     ISC01 ISC00  */

#define EXTINT_MCUCSR_REG				(*(volatile uint_8*)0x54)  /* Bit    6 
																		ISC2  */


#endif     /* EXTINT_PRIVATE_H_ */