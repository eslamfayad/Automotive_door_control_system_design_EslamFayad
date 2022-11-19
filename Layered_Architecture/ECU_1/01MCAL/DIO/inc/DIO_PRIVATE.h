#ifndef		DIO_PRIVATE_h
#define		DIO_PRIVATE_h

/*			PORT A REGISTERS		*/
#define		PORTA_REG	*((volatile uint_8*)0x3B)
#define		DDRA_REG	*((volatile uint_8*)0x3A)
#define		PINA_REG	*((volatile uint_8*)0x39)

/* 			PORT B REGISTERS		*/
#define		PORTB_REG	*((volatile uint_8*)0x38)
#define		DDRB_REG	*((volatile uint_8*)0x37)
#define		PINB_REG	*((volatile uint_8*)0x36)

/* 			PORT c REGISTERS		*/
#define		PORTC_REG	*((volatile uint_8*)0x35)
#define		DDRC_REG	*((volatile uint_8*)0x34)
#define		PINC_REG	*((volatile uint_8*)0x33)

/* 			PORT D REGISTERS		*/
#define		PORTD_REG	*((volatile uint_8*)0x32)
#define		DDRD_REG	*((volatile uint_8*)0x31)
#define		PIND_REG	*((volatile uint_8*)0x30)




#endif
