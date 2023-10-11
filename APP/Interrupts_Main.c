#include "STD_Types.h"
#include "Macros.h"

#include "DIO_int.h"
#include "DIO_reg.h"

#include "GIE_int.h"

#include "EXT_INT_int.h"
#include "EXT_INT_priv.h"

#include <util/delay.h>

void Toggle(void)
{
	DIO_voidTogglePin(PortB,Pin7);

	_delay_ms(200);
}

int main(void)
{
	DIO_voidInitialization();

	EXT_INT_voidInitialization();

	EXTI1_CallBack(Toggle);
	//EXTI1_CallBack(DIO_voidTogglePin(PortB,Pin7));

	GIE_Enable();
	EXTI1_Enable();

	while(1)
	{

	}


	return 0;
}
