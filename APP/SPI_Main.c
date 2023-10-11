
#include "STD_Types.h"
#include "Macros.h"

#include <math.h>

#include "LCD_KIT_int.h"

#include "SPI_int.h"
#include "SPI_priv.h"

#include <util/delay.h>



void SPI_RecieveValueByInterrupt(void)
{
	LCD_KIT_voidDisplayCharacter(SPI_SPDR);
}

int main(void)
{
	//SPI_CallBack(SPI_RecieveValueByInterrupt);
	SPI_voidInitialization();
	LCD_KIT_voidInitialization();

	//LCD_KIT_voidDisplayCharacter('B');

//	SPI_voidInterruptEnable();
//	GIE_Enable();

	SPI_MasterTransmit(0x82);
	//LCD_KIT_voidDisplayCharacter('A');
	_delay_ms(500);

	SPI_MasterTransmit(0x84);
	//LCD_KIT_voidDisplayCharacter('B');
	_delay_ms(500);

//	SPI_MasterTransmit(0x86);
//	//LCD_KIT_voidDisplayCharacter('C');
//	_delay_ms(1000);

	while(1)
	{

	}

	return 0;
}
