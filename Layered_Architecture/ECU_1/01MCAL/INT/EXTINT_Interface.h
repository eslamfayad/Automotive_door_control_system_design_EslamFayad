/*
 * EXTINT_Interface.h
 *
 * Created: 5/30/2021 11:58:28 PM
 *  Author: EslamFayad
 */ 

 
#ifndef EXTINT_INTERFACE_H_
#define EXTINT_INTERFACE_H_

#include "EXTINT_Private.h"
void Enable_Ext_INT(uint_8 INT_NUM);
void Disable_Ext_INT(uint_8 INT_NUM);
void INT0_SensCfg(uint_8 Sense);
void INT1_SensCfg(uint_8 Sense);
void INT2_SensCfg(uint_8 Sense);


#define INT0_EN_BIT						(6)
#define INT1_EN_BIT						(7)
#define INT2_EN_BIT						(5)

#define INT0_SENSE_LOW_LEVEL   		    (0)
#define INT0_SENSE_LOGIC_CHANGE     	(1)
#define INT0_SENSE_FAILING_EDGE       	(2)
#define INT0_SENSE_RISING_EDGE       	(3)

#define INT1_SENSE_LOW_LEVEL   		    (0)
#define INT1_SENSE_LOGIC_CHANGE     	(4)
#define INT1_SENSE_FAILING_EDGE       	(8)
#define INT1_SENSE_RISING_EDGE       	(12)

#define INT2_SENSE_FAILING_EDGE       	(0)
#define INT2_SENSE_RISING_EDGE       	(1<<6) // 64

#endif /* EXTINT_INTERFACE_H_ */