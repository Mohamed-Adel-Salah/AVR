

#include "STD_Types.h"
#include "Macros.h"

#include "DIO_int.h"
#include "DIO_reg.h"

#include "LCD_KIT_int.h"

#include "GIE_int.h"

#include "I2C_int.h"
#include "I2C_priv.h"


#include <util/delay.h>









u8 Return;
int main(void)
{
	I2C_voidInitializtion();
	LCD_KIT_voidInitialization();

	Return=I2C_Master_SendStartCondition();
	//LCD_KIT_voidSetCurser(Line1,Col0);
	//LCD_KIT_voidDisplayBigNumber(Return);
	Return=I2C_Master_SendSlaveAddress_Write(0x15);
	LCD_KIT_voidSetCurser(Line2,Col0);
	LCD_KIT_voidDisplayBigNumber(Return);
	Return=I2C_Master_SendData(1);
	_delay_ms(30);
//	LCD_KIT_voidSetCurser(Line3,Col0);
//	LCD_KIT_voidDisplayBigNumber(Return);
	Return=I2C_Master_SendData(2);
	_delay_ms(30);
//	LCD_KIT_voidSetCurser(Line4,Col0);
//	LCD_KIT_voidDisplayBigNumber(Return);
	Return = I2C_Master_SendData(3);
	_delay_ms(5);
//	LCD_KIT_voidSetCurser(Line1,Col0);
//	LCD_KIT_voidDisplayBigNumber(Return);
	I2C_Master_SendStopCondition();

//	I2C_Master_SendStartCondition();
//	I2C_Master_SendSlaveAddress_Write(0x00);
//	I2C_Master_SendData(0x54);
//	I2C_Master_SendData(0x45);
//	I2C_Master_SendStopCondition();

	while(1)
	{

	}

	return 0;
}
