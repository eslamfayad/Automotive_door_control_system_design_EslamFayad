/*
 * EXTINT.c
 *
 * Created: 5/30/2021 11:57:33 PM
 *  Author: EslamFayad
 */ 
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "EXTINT_Private.h"
#include "EXTINT_Interface.h"

 void Enable_Ext_INT(uint_8 INT_NUM)
 {
		 switch (INT_NUM)
		 {
		 case 0 : 
		 SET_BIT(EXTINT_GICR_REG , INT0_EN_BIT);
		 	break;
		 case 1 : 
		 SET_BIT(EXTINT_GICR_REG , INT1_EN_BIT);
			break;
		case 2 : 
		SET_BIT(EXTINT_GICR_REG , INT2_EN_BIT);
			break;					 
		 }
		 
 }


//////////////////////////////////////////////////////////////////////////////////////////////////
void Disable_Ext_INT(uint_8 INT_NUM)
{
		switch (INT_NUM)
		{
			case 0 : 
			CLR_BIT (EXTINT_GICR_REG , INT0_EN_BIT);
			break;
			case 1 : 
			CLR_BIT(EXTINT_GICR_REG , INT1_EN_BIT);
			break;
			case 2 : 
			CLR_BIT(EXTINT_GICR_REG , INT2_EN_BIT);
			break;
		}
	
 }
 
 
 void INT0_SensCfg(uint_8 Sense_CFG)
 {
	 EXTINT_MCUCR_REG|=Sense_CFG;
 }
 
 void INT1_SensCfg(uint_8 Sense_CFG)
 {
	 EXTINT_MCUCR_REG|=Sense_CFG;
 }