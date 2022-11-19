#ifndef		DIO_INTERFACE_h
#define		DIO_INTERFACE_h
#include 	"STD_TYPES.h"
#include "DIO_PRIVATE.h"

void DIO_SetPortDirection(uint_8 PortID ,uint_8 Direction);

void DIO_SetPinDirection(uint_8 PortID , uint_8 PinID,uint_8 Direction);

void DIO_SetPortValue(uint_8 PortID ,uint_8 Value);

void DIO_SetPinValue(uint_8 PortID , uint_8 PinID,uint_8 Value);

uint_8 DIO_GETPinValue(uint_8 PortID , uint_8 PinID);
void Dio_FlipChannel(uint_8 PortID,uint_8 PinID);
void Dio_WriteChannelGroup(uint_8  portID, uint_8 mask, uint_8 position, uint_8 data);
uint_8 Dio_ReadChannelGroup(uint_8 portID, uint_8 mask, uint_8 position);
//Dio_Level Dio_ReadChannel(Dio_Port port,Dio_Channel channel);

#define			DIO_PORTA			0
#define			DIO_PORTB			1
#define			DIO_PORTC			2
#define			DIO_PORTD			3

#define			PIN0			0
#define			PIN1			1
#define			PIN2			2
#define			PIN3			3
#define			PIN4			4
#define			PIN5			5
#define			PIN6			6
#define			PIN7			7

#define			INPUT			0
#define			OUTPUT			1

#define			HIGH			1
#define			LOW				0







#endif
