/*
 * LCD_program.c
 *
 * Created: 5/21/2021 10:14:46 AM
 *  Author: EslamFayad
 */ 
#define F_CPU 16000000UL

#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "DIO_PRIVATE.h" 
#include "LCD_interface.h"
#ifndef NULL
#define NULL ((void*) 0)
#endif

/*///////////////////                   8 BIT MODE  //////////  ////////////////////*/
void LCD_Init(void)
{
DIO_SetPortDirection(LCD_DATA_PORT ,OUTPUT);	          /* Make LCD command port direction as o/p */
DIO_SetPortDirection(LCD_CONTROL_PORT ,OUTPUT);	         /* Make LCD command port direction as o/p */
_delay_ms(15);		/* LCD Power ON delay always >15ms */
LCD_Command (0x38);	/* Initialization of 16X2 LCD in 8bit mode */
LCD_Command (0x0C);	/* Display ON Cursor OFF */
LCD_Command (0x06);	/* Auto Increment cursor */
LCD_Command (0x01);	/* clear display */
LCD_Command (0x80);	/* cursor at home position */
}


void LCD_WriteChar(uint_8 Data)	
{
	DIO_SetPinValue(LCD_CONTROL_PORT , LCD_RS , HIGH);
	DIO_SetPinValue(LCD_CONTROL_PORT , LCD_RW , LOW);
	DIO_SetPinValue(LCD_CONTROL_PORT , LCD_EN , HIGH);
	DIO_SetPortValue(LCD_DATA_PORT , Data);
	_delay_ms(5);
	DIO_SetPinValue(LCD_CONTROL_PORT , LCD_EN , LOW);
	_delay_ms(5);
	
}
void LCD_Command(uint_8 Data)	
{
	    DIO_SetPinValue(LCD_CONTROL_PORT , LCD_RS , LOW);
		DIO_SetPinValue(LCD_CONTROL_PORT , LCD_RW , LOW);
		DIO_SetPinValue(LCD_CONTROL_PORT , LCD_EN , HIGH);
		DIO_SetPortValue(LCD_DATA_PORT , Data);
	_delay_ms(5);
			DIO_SetPinValue(LCD_CONTROL_PORT , LCD_EN , LOW);
			_delay_ms(5);
}
void LCD_WRITE_STRING(char  STRING[] )
{
	uint_8 i = 0;
	while( STRING[i] != '\0' )
	{
	LCD_WriteChar( STRING[i]);
	i++;	
	
	}
	
}
/*///////////////////                   4BIT MODE  //////////  ////////////////////*/

void LCD_Init_4bit (void)  /* LCD Initialize function */
{
	DIO_SetPortDirection(LCD_DATA_PORT ,OUTPUT);/* Make LCD Data port direction as o/p */
	DIO_SetPortDirection(LCD_CONTROL_PORT ,OUTPUT);	  /* Make LCD command port direction as o/p */
	_delay_ms(15);		/* LCD Power ON delay always >15ms */
	
	LCD_Command_4bit(0x33);
	LCD_Command_4bit(0x32);	/* Send for 4 bit initialization of LCD  */
	LCD_Command_4bit(0x28);	/* 2 line, 5*7 matrix in 4-bit mode */
	LCD_Command_4bit(0x0c);	/* Display on cursor off */
	LCD_Command_4bit(0x06);	/* Increment cursor (shift cursor to right) */
	LCD_Command_4bit(0x01);	/* Clear display screen */
}


void LCD_Command_4bit( uint_8 CMD )
{
	 LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (CMD & 0xF0);   /* Sending upper nibble */
	 DIO_SetPinValue(LCD_CONTROL_PORT , LCD_RS , LOW);
	 DIO_SetPinValue(LCD_CONTROL_PORT , LCD_RW , LOW);
	 DIO_SetPinValue(LCD_CONTROL_PORT , LCD_EN , HIGH);
	_delay_ms(5);
	DIO_SetPinValue(LCD_CONTROL_PORT , LCD_EN , LOW);
	_delay_ms(5);
	
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (CMD << 4);            /* Sending lower nibble */
	DIO_SetPinValue(LCD_CONTROL_PORT , LCD_RS , LOW);
	DIO_SetPinValue(LCD_CONTROL_PORT , LCD_RW , LOW);
	DIO_SetPinValue(LCD_CONTROL_PORT , LCD_EN , HIGH);
	_delay_ms(5);
	DIO_SetPinValue(LCD_CONTROL_PORT , LCD_EN , LOW);
     _delay_ms(5);
	 }

void LCD_WriteChar_4bit( uint_8 DATA )
{
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (DATA & 0xF0);   /* Sending upper nibble */
	DIO_SetPinValue(LCD_CONTROL_PORT , LCD_RS , HIGH);
	DIO_SetPinValue(LCD_CONTROL_PORT , LCD_RW , LOW);
	DIO_SetPinValue(LCD_CONTROL_PORT , LCD_EN , HIGH);
	_delay_ms(5);
	DIO_SetPinValue(LCD_CONTROL_PORT , LCD_EN , LOW);
	_delay_ms(5);
	
	LCD_DATA_PORT = (LCD_DATA_PORT & 0x0F) | (DATA << 4);            /* Sending lower nibble */
	DIO_SetPinValue(LCD_CONTROL_PORT , LCD_RS , HIGH);
	DIO_SetPinValue(LCD_CONTROL_PORT , LCD_RW , LOW);
	DIO_SetPinValue(LCD_CONTROL_PORT , LCD_EN , HIGH);
	_delay_ms(5);
	DIO_SetPinValue(LCD_CONTROL_PORT , LCD_EN , LOW);
	_delay_ms(5);
}

void LCD_WRITE_STRING_4bit(char  STRING[] )
{
	uint_8 i = 0;
	while( STRING[i] != '\0' )
	{
		LCD_WriteChar_4bit( STRING[i]);
		i++;
		
	}
	
}