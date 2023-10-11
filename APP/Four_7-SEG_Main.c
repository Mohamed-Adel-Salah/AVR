
#include "STD_Types.h"
#include "Macros.h"


#include "SEG_KIT_int.h"


#include <util/delay.h>


int main(void)
{
	SEG_KIT_voidInitialization();

	while(1)
	{
		for(u8 i=0;i<10;i++)
		{
			for(u8 j=1;j<5;j++)
			{
				SEG_KIT_voidDisplayNumber(i,j);
				_delay_ms(5);
			}
			//_delay_ms(200);
		}
	}

	return 0;
}

