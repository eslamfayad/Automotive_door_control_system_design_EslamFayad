#include 	"STD_TYPES.h"
#include 	"BIT_MATH.h"
#include 	"DIO_PRIVATE.h"
#include 	"DIO_INTERFACE.h"


/*  ############################# SET Port Direction ##################################
	DIO_SetPortDirection(PORTA ,OUTPUT);
	PORTA ===> output 				===> 	DDR = 0xFF
	
	
	DIO_SetportDirection(PORTA ,INPUT);
	PORTA ===> input 				===> 	DDR = 0x00
*/

void DIO_SetPortDirection(uint_8 PortID ,uint_8 Direction)
{
	//Range check
	if (PortID <4 )
	{
		if(Direction==OUTPUT)
			{
				switch(PortID)
				{
					case DIO_PORTA : DDRA_REG = 0xFF; break;
					case DIO_PORTB : DDRB_REG = 0xFF; break;
					case DIO_PORTC : DDRC_REG = 0xFF; break;
					case DIO_PORTD : DDRD_REG = 0xFF; break;
				}
			}
		else if (Direction==INPUT)
		   {
			   switch(PortID)
				{
					case DIO_PORTA : DDRA_REG = 0x00; break;
					case DIO_PORTB : DDRB_REG = 0x00; break;
					case DIO_PORTC : DDRC_REG = 0x00; break;
					case DIO_PORTD : DDRD_REG = 0x00; break;
				}
			
		   }
		else 
		{
			/*  set Direction value to the custom direction inserted  
            DIO_SetDIO_PORTDirection(DDRA_REG ,0x0F);			*/
			switch (PortID)
			{
				case DIO_PORTA : DDRA_REG = Direction; break;
				case DIO_PORTB : DDRB_REG = Direction; break;
				case DIO_PORTC : DDRC_REG = Direction; break;
				case DIO_PORTD : DDRD_REG = Direction; break;
			}	
		}
	}
	else 
	{
		/* ERROR*/
	}
	
}
/*  ############################# SET BIT Direction ##################################
	DIO_voidSetPinDireation(PORTA , PIN0 ,OUTPUT);
	A0 ===> output 				===> 	DDR = 1
	
	
	DIO_voidSetPinDireation(PORTA , PIN1 ,OUTPUT);
	A1 ===> input 				===> 	DDR = 0
*/

void DIO_SetPinDirection(uint_8 PortID , uint_8 PinID,uint_8 Direction)
{
	//Range check
	if (PortID <4 && PinID <8)
	{
		if(Direction==OUTPUT)
			{
				switch(PortID)
				{
					case DIO_PORTA : SET_BIT(DDRA_REG,PinID); break;
					case DIO_PORTB : SET_BIT(DDRB_REG,PinID); break;
					case DIO_PORTC : SET_BIT(DDRC_REG,PinID); break;
					case DIO_PORTD : SET_BIT(DDRD_REG,PinID); break;
				}
			}
		else if (Direction==INPUT)
		   {
			   switch(PortID)
				{
					case DIO_PORTA : CLR_BIT(DDRA_REG,PinID); break;
					case DIO_PORTB : CLR_BIT(DDRB_REG,PinID); break;
					case DIO_PORTC : CLR_BIT(DDRC_REG,PinID); break;
					case DIO_PORTD : CLR_BIT(DDRD_REG,PinID); break;
				}
			
		   }
		else 
		{
			/* ERROR */
		}
	}
	else 
	{
		/* ERROR*/
	}
	
}

/* ############################# SET Port VALUE ################################## 
*/
void DIO_SetPortValue(uint_8 PortID ,uint_8 Value)
{
	/* Range check*/
	if (PortID <4)
	{
		if (Value == HIGH)
		{
			switch (PortID)
			{
				case DIO_PORTA : PORTA_REG = 0xFF; break;
				case DIO_PORTB : PORTB_REG = 0xFF; break;
				case DIO_PORTC : PORTC_REG = 0xFF; break;
				case DIO_PORTD : PORTD_REG = 0xFF; break;
			}	
		}
		else if (Value == LOW)
		{
			switch (PortID)
			{
				case DIO_PORTA : PORTA_REG = 0x00; break;
				case DIO_PORTB : PORTB_REG = 0x00; break;
				case DIO_PORTC : PORTC_REG = 0x00; break;
				case DIO_PORTD : PORTD_REG = 0x00; break;
			}	
		}
		else 
		{
			/*  set port value to the value inserted  
		       DIO_SetPortValue(PORTA_REG ,0b 1010101010)	 set any value as you like */
			switch (PortID)
			{
				case DIO_PORTA : PORTA_REG = Value; break;
				case DIO_PORTB : PORTB_REG = Value; break;
				case DIO_PORTC : PORTC_REG = Value; break;
				case DIO_PORTD : PORTD_REG = Value; break;
			}	
		}	
	}
	else 
	{
		/*           */
	
	}
}

/* ############################# SET BIT VALUE ################################## 
*/
void DIO_SetPinValue(uint_8 PortID , uint_8 PinID,uint_8 Value)
{
	/* Range check*/
	if (PortID <4 && PinID <8)
	{
		if (Value == HIGH)
		{
			switch (PortID)
			{
				case DIO_PORTA : SET_BIT(PORTA_REG,PinID); break;
				case DIO_PORTB : SET_BIT(PORTB_REG,PinID); break;
				case DIO_PORTC : SET_BIT(PORTC_REG,PinID); break;
				case DIO_PORTD : SET_BIT(PORTD_REG,PinID); break;
			}	
		}
		else if (Value == LOW)
		{
			switch (PortID)
			{
				case DIO_PORTA : CLR_BIT(PORTA_REG,PinID); break;
				case DIO_PORTB : CLR_BIT(PORTB_REG,PinID); break;
				case DIO_PORTC : CLR_BIT(PORTC_REG,PinID); break;
				case DIO_PORTD : CLR_BIT(PORTD_REG,PinID); break;
			}	
		}
		else 
		{
			/*      */
		}	
	}
	else 
	{
		/*           */
	
	}
}

/* ############################# GET BIT VALUE ##################################
x = DIO_uint_8GetPinValue(PORTA , PIN0); store the bit value to uint_8 X
*/

 uint_8 DIO_GETPinValue(uint_8 PortID , uint_8 PinID)
 {
	 uint_8 Local_Value = 0xFF;  // setting initial value
	 /* Range check*/
	if (PortID <4 && PinID <8)
	{
		switch (PortID)
			{
				case DIO_PORTA : Local_Value = GET_BIT(PINA_REG,PinID); break;
				case DIO_PORTB : Local_Value = GET_BIT(PINB_REG,PinID); break;
				case DIO_PORTC : Local_Value = GET_BIT(PINC_REG,PinID); break;
				case DIO_PORTD : Local_Value = GET_BIT(PIND_REG,PinID); break;
			}
	}			
    else
	{
		/* ERROR*/
	}
return Local_Value;	 
 }
 
 
 void Dio_FlipChannel(uint_8 PortID,uint_8 PinID)
 {
	 switch (PortID)
	 {
		 case DIO_PORTA:
		 TOG_BIT(PORTA_REG,PinID);
		 break;
		 case DIO_PORTB:
		 TOG_BIT(PORTB_REG,PinID);
		 break;
		 case DIO_PORTC:
		 TOG_BIT(PORTC_REG,PinID);
		 break;
		 case DIO_PORTD:
		 TOG_BIT(PORTD_REG,PinID);
		 break;
	 }
 }
 /************************************************************************************************************************
* \Syntax          : void Dio_ConfigChannelGroup(Dio_PortID portID,u8 mask, u8 data)     
* \Description     : This service configure DIO channels directions                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PortID			- ID of DIO Port
*				   : mask			- DIO channel group position 
				   : data			- DIO channel group Level                                                                     
* \Return value:   : None                        
**************************************************************************************************************************/
void Dio_WriteChannelGroup(uint_8  portID, uint_8 mask, uint_8 position, uint_8 data)
{
	switch (portID)
	{
	case DIO_PORTA:
		PORTA_REG = (PORTA_REG & ~mask)|(data<<position) ;
		break;

	case DIO_PORTB:
		PORTB_REG = (PORTB_REG & ~mask)|(data<<position) ;
		break;
	case DIO_PORTC:
		PORTC_REG = (PORTC_REG & ~mask)|(data<<position) ;
		break;
	case DIO_PORTD:
		PORTD_REG = (PORTD_REG & ~mask)|(data<<position) ;
		break;
	}	
}
/************************************************************************************************************************
* \Syntax          : u8 Dio_ReadChannelDroup(Dio_PortID portID, u8 mask, u8 position)
* \Description     : This service configure DIO channels directions
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : PortID			- ID of DIO Port
*				   : mask			- DIO channel group mask
				   : position		- DIO channel group position
* \Return value:   : None
**************************************************************************************************************************/
uint_8 Dio_ReadChannelGroup(uint_8 portID, uint_8 mask, uint_8 position)
{
	uint_8 ret_Value=0;

	switch (portID)
	{
	case DIO_PORTA:
		ret_Value=PORTA_REG & mask;
		ret_Value=ret_Value<<position;
		break;
	case DIO_PORTB:
		ret_Value=PORTB_REG & mask;
		ret_Value=ret_Value<<position;
		break;
	case DIO_PORTC:
		ret_Value=PORTC_REG & mask;
		ret_Value=ret_Value<<position;
		break;
	case DIO_PORTD:
		ret_Value=PORTD_REG & mask;
		ret_Value=ret_Value<<position;
		break;
	}
	return ret_Value;
}