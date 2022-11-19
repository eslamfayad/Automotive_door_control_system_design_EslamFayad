 /**********************************************************************************************************************
 *  File		: Button.c
 *	Module		: BUTTON
 *	Target		: General
 *	Author		: mFawzi
 *  Description	:      
 * 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Button.h"
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
* \Syntax          : void Button_Init(void)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : None
* \Return value:   : None
*******************************************************************************/
void Button_Init(void)
{
 Dio_ConfigChannel(BUTTON0_PORT,BUTTON0_CHANNEL,INPUT);
 Dio_ConfigChannel(BUTTON1_PORT,BUTTON1_CHANNEL,INPUT);
 Dio_ConfigChannel(BUTTON2_PORT,BUTTON2_CHANNEL,INPUT);
}
/******************************************************************************
* \Syntax          : boolean Button_Pressed(BUTTON_ID ButtonID)      
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ButtonID   button ID                                                                          
* \Return value:   : boolean                               
*******************************************************************************/
boolean Button_Pressed(Button_Id ButtonID)
{
	boolean loc_ButtonPressed = FALSE;
	switch (ButtonID)
	{
	case BUTTON0:
		if (Dio_ReadChannel(BUTTON0_PORT,BUTTON0_CHANNEL))
		{
			loc_ButtonPressed = TRUE;
		}
		else
		{
			loc_ButtonPressed = FALSE;
		}
		break;

	case BUTTON1:
		if (Dio_ReadChannel(BUTTON1_PORT,BUTTON1_CHANNEL))
		{
			loc_ButtonPressed = TRUE;
		}
		else
		{
			loc_ButtonPressed = FALSE;
		}
		break;	
	case BUTTON2:
		if (Dio_ReadChannel(BUTTON2_PORT,BUTTON2_CHANNEL))
		{
			loc_ButtonPressed = TRUE;
		}
		else
		{
			loc_ButtonPressed = FALSE;
		}
		break;
	}
	return loc_ButtonPressed;
}
/**********************************************************************************************************************
 *  END OF FILE: Button.c
 *********************************************************************************************************************/