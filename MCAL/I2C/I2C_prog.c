/*
 * I2C_prog.c
 *
 *  Created on: Aug 7, 2023
 *      Author: hp
 */


#include "Std_types.h"
#include "Macros.h"

#include "DIO_int.h"

#include "I2C_int.h"
#include "I2C_priv.h"
#include "I2C_confg.h"


void I2C_voidInitializtion(void)
{
	SET_BIT(TWCR,TWCR_TWEN);
	CLR_BIT(TWSR,TWSR_TWPS1);
	CLR_BIT(TWSR,TWSR_TWPS0);

	SET_BIT(TWCR,TWCR_TWEA);

	TWBR = TWBR_Prescaler;

	TWAR = (MCU_Address<<1);

}

u8 I2C_Master_SendStartCondition(void)
{
	SET_BIT(TWCR,TWCR_TWSTA);
	SET_BIT(TWCR,TWCR_TWINT);

	while(!DIO_u8GetPinValue(TWCR,TWCR_TWINT));

	return (TWSR)&(0xF8);
}

u8 I2C_Master_SendRepeatedStartCondition(void)
{
	SET_BIT(TWCR,TWCR_TWSTA);
	SET_BIT(TWCR,TWCR_TWINT);

	while(!DIO_u8GetPinValue(TWCR,TWCR_TWINT));

	return (TWSR)&(0xF8);
}

void I2C_Master_SendStopCondition(void)
{
	SET_BIT(TWCR,TWCR_TWSTO);

	SET_BIT(TWCR,TWCR_TWINT);
}

u8 	 I2C_Master_SendSlaveAddress_Write(u8 Address)
{
	TWDR=(Address<<1);

	CLR_BIT(TWDR,0);

	CLR_BIT(TWCR,TWCR_TWSTA);
	SET_BIT(TWCR,TWCR_TWINT);

	while(!DIO_u8GetPinValue(TWCR,TWCR_TWINT));

	return (TWSR)&(0xF8);
}

u8 	 I2C_Master_SendSlaveAddress_Read(u8 Address)
{
	TWDR=(Address<<1);

	SET_BIT(TWDR,0);

	CLR_BIT(TWCR,TWCR_TWSTA);
	SET_BIT(TWCR,TWCR_TWINT);

	while(!DIO_u8GetPinValue(TWCR,TWCR_TWINT));

	return (TWSR)&(0xF8);
}

u8 	 I2C_Master_SendData(u8 Data)
{
	TWDR = Data;

	SET_BIT(TWCR,TWCR_TWINT);

	while(!DIO_u8GetPinValue(TWCR,TWCR_TWINT));

	return (TWSR)&(0xF8);
}

u8 	 I2C_Master_ReadData(u8 * Data)
{
	SET_BIT(TWCR,TWCR_TWINT);

	while(!DIO_u8GetPinValue(TWCR,TWCR_TWINT));

	if(((TWSR)&(0xF8))==Data_Rcieved_ACK_Returned)
	{
		*Data = TWDR;
	}

	return (TWSR)&(0xF8);
}

void I2C_voidInterruptEnable(void)
{
	SET_BIT(TWCR,TWCR_TWIE);
}
void I2C_voidInterruptDisable(void)
{
	CLR_BIT(TWCR,TWCR_TWIE);

}

u8   I2C_Slave_ReadData(u8 * Data)
{
	SET_BIT(TWCR,TWCR_TWINT);

	while(!DIO_u8GetPinValue(TWCR,TWCR_TWINT));

	if((((TWSR)&(0xF8))==Slave_Data_Rcieved_ACK_Returned_OWN_Adsress)||((TWSR)&(0xF8))==Slave_Data_Rcieved_ACK_Returned_GeneralCall)
	{
		SET_BIT(TWCR,TWCR_TWEA);
		*Data = TWDR;
	}

	return (TWSR)&(0xF8);
}
