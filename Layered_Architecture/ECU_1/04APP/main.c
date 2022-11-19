#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"


int main(void)
{
	/*		LED ON A0 	*/
	DIO_voidSetPinDireation(PORTA , PIN0 , OUTPUT);
	while(1)
	{
		DIO_voidSetPinValue(PORTA , PIN0 , HIGH);
	}
	return 0;
}