#include "STD_Types.h"
#include "Macros.h"

#include "DIO_int.h"
#include "DIO_reg.h"

#include "7SEG_int.h"

#include <util/delay.h>


int main(void)
{
	SEG_voidInitialization();

	while(1)
	{
		for(u8 i=0;i<10;i++)
		{
			SEG_voidDisplayNumber(i);
			_delay_ms(500);
		}
	}

	return 0;
}
