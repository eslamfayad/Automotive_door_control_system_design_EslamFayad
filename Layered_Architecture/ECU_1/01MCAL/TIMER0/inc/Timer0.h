 /********************************************************************************************************************
 *  File		: Timer0.h
 *	Module		: TIMER0
 *	Target		: ATMEGA32
 *	Author		: eslamfayad
 *  Description	:
 *********************************************************************************************************************/
#ifndef TIMER0_H_
#define TIMER0_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD_TYPES.h"
#include "Timer0_Private.h"
#include "Timer0_Cfg.h"
#include "BIT_MATH.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*	TIMER0 Operation Modes	*/
#define TIMER0_INTERVAL_MODE				((uint_8)0<<3)
#define TIMER0_CTC_MODE						((uint_8)1<<3)
#define TIMER0_PWM_FAST						((uint_8)9<<3)
#define TIMER0_PWM_PHASE_CORRECT			((uint_8)1<<6)

/*	TIMER0 Clock Select Prescaler	*/
#define TIMER0_CS_DISABLED					((uint_8)0<<0)	/* Timer0 Stopped */
#define TIMER0_CS_NO_PRESCALER				((uint_8)1<<0)
#define TIMER0_CS_8_PRESCALER				((uint_8)2<<0)
#define TIMER0_CS_64_PRESCALER				((uint_8)3<<0)
#define TIMER0_CS_256_PRESCALER				((uint_8)4<<0)
#define TIMER0_CS_1024_PRESCALER			((uint_8)5<<0)
#define TIMER0_CS_External_FAILING_EDGE		((uint_8)6<<0)
#define TIMER0_CS_External_RISING_EDGE		((uint_8)7<<0)

/*	CTC Modes	*/
#define CTC_OC0_DISCONNECTED				((uint_8)0<<4)
#define CTC_OC0_TOGGLE						((uint_8)1<<4)
#define CTC_OC0_LOW							((uint_8)2<<4)
#define CTC_OC0_HIGH						((uint_8)3<<4)

/*	Fast PWM Modes	*/
#define PWM_FAST_OC0_DISCONNECTED			((uint_8)0<<4)
#define PWM_FAST_OC0_NON_INVERTED			((uint_8)2<<4)
#define PWM_FAST_OC0_INVERTED				((uint_8)3<<4)

/*	Phase Correct PWM Modes	*/
#define PWM_PHASE_CORRECT_OC0_DISCONNECTED	((uint_8)0<<4)
#define PWM_PHASE_CORRECT_OC0_NON_INVERTED	((uint_8)2<<4)
#define PWM_PHASE_CORRECT_OC0_INVERTED		((uint_8)3<<4)

/*	Timer0 Interrupt Enable	Bits */
#define TIMER0_INTERVAL_INT_ENABLE_BIT_NO		(0)
#define TIMER0_CTC_INT_ENABLE_BIT_NO			(1)
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void TIMER0_Init(void);
void TIMER0_Start(uint_8 prescaler);
void TIMER0_Stop(void);
void TIMER0_Load(uint_8 loadvalue);
uint_8 TIMER0_CAPTURE(void);
void TIMER0_EnableInterrupt(void);
void TIMER0_DisableInterrupt(void);

#endif  /* TIMER0_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Timer0.h
 *********************************************************************************************************************/
