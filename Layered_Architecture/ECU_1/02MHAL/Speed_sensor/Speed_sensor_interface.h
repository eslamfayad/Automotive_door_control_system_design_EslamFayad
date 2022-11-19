/*
 * IncFile1.h
 *
 * Created: 5/21/2021 10:15:14 AM
 *  Author: EslamFayad
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#define		LCD_DATA_PORT				PORTA_REG
#define		LCD_CONTROL_PORT			DIO_PORTB
#define		LCD_RS					PIN1
#define		LCD_RW					PIN2
#define		LCD_EN					PIN3
void LCD_voidInit(void);
void LCD_WriteChar(uint_8 Data)	;
void LCD_Command(uint_8 Data)	;
void LCD_WRITE_STRING( char  STRING[] );

void LCD_Init_4bit (void);
void LCD_Command_4bit( uint_8 CMD );
void LCD_WriteChar_4bit( uint_8 DATA );
void LCD_WRITE_STRING_4bit(char  STRING[] );

#endif /* INCFILE1_H_ */