 /**********************************************************************************************************************
 *  File		: SSD.c
 *	Module		: SSD
 *	Target		: General
 *	Author		: Eslam fayad
 *  Description	:      
 * 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SSD.h"
#include "DIO_PRIVATE.h"
#include "DIO_INTERFACE.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : void SSD_Init(void)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : None
*******************************************************************************/
void SSD_Init(void)
{
		/*	configure SSD1 Enable Channel as Output	*/
	DIO_SetPinDirection(SSD_DIG1_EN_PORT,SSD_DIG1_EN_CHANNEL,OUTPUT);
		/*	configure SSD1 Enable Channel as Output	*/
	DIO_SetPinDirection(SSD_DIG2_EN_PORT,SSD_DIG2_EN_CHANNEL,OUTPUT);
		/*	configure SSD Data Channels as Output	*/
	DIO_SetPortDirection(SSD_DATA_PORT,OUTPUT);
}
/******************************************************************************
* \Syntax          : void SSD_Display(u8 number)
* \Description     : This Service shall be called periodically every 10 ms
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : number - Two digit number (0 : 99)
* \Return value:   : None
*******************************************************************************/
void SSD_Display(uint_8 number)
{
		/*	Turn ON SSD 1	*/
	DIO_SetPinValue(SSD_DIG1_EN_PORT,SSD_DIG1_EN_CHANNEL,HIGH);
		/*	Turn OFF SSD 2	*/
	DIO_SetPinValue(SSD_DIG2_EN_PORT,SSD_DIG2_EN_CHANNEL,LOW);
		/*	Set First Digit of Displayed Number	*/
	Dio_WriteChannelGroup(SSD_DATA_PORT,SSD_MASK,SSD_DATA_GRP_POS,number%10);
	_delay_ms(1);

		/*	Turn OFF SSD 1	*/
	DIO_SetPinValue(SSD_DIG1_EN_PORT,SSD_DIG1_EN_CHANNEL,LOW);
		/*	Turn ON SSD 2	*/
	DIO_SetPinValue(SSD_DIG2_EN_PORT,SSD_DIG2_EN_CHANNEL,HIGH);
		/*	Set Second Digit of Displayed Number	*/
	Dio_WriteChannelGroup(SSD_DATA_PORT,SSD_MASK,SSD_DATA_GRP_POS,number/10);
	_delay_ms(1);
		/*	Turn OFF SSD 1	*/
	DIO_SetPinValue(SSD_DIG1_EN_PORT,SSD_DIG1_EN_CHANNEL,LOW);
		/*	Turn OFF SSD 2	*/
	DIO_SetPinValue(SSD_DIG2_EN_PORT,SSD_DIG2_EN_CHANNEL,LOW);
}



void SSD_DelayWithDisplayMS(uint_8 num,uint_16 delay)
{
	uint_16 count=0;
	for (count=0;count<delay;count+=3)
	{
		SSD_Display(num);
		_delay_ms(1);
	}
}
/**********************************************************************************************************************
 *  END OF FILE: SSD.c
 *********************************************************************************************************************/
