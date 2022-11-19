/*
 * GLBL_Interrupt.c
 *
 * Created: 5/28/2021 1:52:43 PM
 *  Author: EslamFayad
 */ 
#include "BIT_MATH.h"
#include "GLBL_Interupt_inteface.h"


void EnableAllInterrupts()
{
	SET_BIT(GLBLINT_SREG_REG,I_BIT_POS);
}
void DisableAllInterrupts()
{
	CLR_BIT(GLBLINT_SREG_REG,I_BIT_POS);
}