 /**********************************************************************************************************************
 *  File		: Timer0.c
 *	Module		: TIMER0
 *	Target		: ATMEGA32
 *	Author		: eslam fayad
 *  Description	:
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Timer0.h"
#include "Timer0_Cfg.h"
void TIMER0_Init(void)
{
	#if (TIMER_OPERATION_MODE == TIMER0_MODE_INTERVAL)
	TIMER0_TCCR0_REG|= TIMER0_INTERVAL_MODE;
	#elif (TIMER_OPERATION_MODE == TIMER0_MODE_CTC)
	TIMER0_TCCR0_REG|= TIMER0_CTC_MODE;
	#elif (TIMER_OPERATION_MODE == TIMER0_MODE_FAST_PWM)
	TIMER0_TCCR0_REG|= TIMER0_PWM_FAST;
	#elif (TIMER_OPERATION_MODE == TIMER0_MODE_PWM_PHASE_CORRECT)
	TIMER0_TCCR0_REG|= TIMER0_PWM_PHASE_CORRECT;
	#else
	#warning "You Shall Define Timer Operation Mode In Timer0_Private.h"
	#endif
}
void TIMER0_Start(uint_8 prescaler)
{
	TIMER0_TCCR0_REG |=prescaler;
}
void TIMER0_Stop(void)
{
	TIMER0_TCCR0_REG &=0xFC;
}
void TIMER0_Load(uint_8 loadvalue)
{
	TIMER0_TCNT0_REG =loadvalue;
}
uint_8 TIMER0_CAPTURE(void)
{
	 return TIMER0_TCNT0_REG; 
}
void TIMER0_EnableInterrupt(void)
{
	#if (TIMER_OPERATION_MODE == TIMER0_MODE_INTERVAL)
	SET_BIT(TIMER0_TIMSK_REG,TIMER0_INTERVAL_INT_ENABLE_BIT_NO);
	#elif (TIMER_OPERATION_MODE == TIMER0_MODE_CTC)
	SET_BIT(TIMER0_TIMSK_REG,TIMER0_CTC_INT_ENABLE_BIT_NO);
	#endif
}
void TIMER0_DisableInterrupt(void)
{
	#if (TIMER_OPERATION_MODE == TIMER0_MODE_INTERVAL)
	CLR_BIT(TIMER0_TIMSK_REG,TIMER0_INTERVAL_INT_ENABLE_BIT_NO);
	#elif (TIMER_OPERATION_MODE == TIMER0_MODE_CTC)
	CLR_BIT(TIMER0_TIMSK_REG,TIMER0_CTC_INT_ENABLE_BIT_NO);
	#endif
}
/**********************************************************************************************************************
 *  END OF FILE: Timer0.c
 *********************************************************************************************************************/
