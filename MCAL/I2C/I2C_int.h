/*
 * I2C_int.h
 *
 *  Created on: Aug 7, 2023
 *      Author: hp
 */

#ifndef MCAL_I2C_I2C_INT_H_
#define MCAL_I2C_I2C_INT_H_

#define Start_Cond_Transmitted					0x08
#define RepeatedStart_Cond_Transmitted 			0x10
#define Arbitration_Lost						0x38
#define SLA+W_Transmitted_ACK_Recieved			0x18
#define SLA+W_Transmitted_ACK_NOT_Recieved		0x20
#define Data_Transmitted_ACK_Recieved			0x28
#define Data_Transmitted_ACK_NOT_Recieved		0x30
#define SLA+R_Transmitted_ACK_Recieved			0x40
#define SLA+R_Transmitted_ACK_NOT_Recieved		0x48
#define Data_Rcieved_ACK_Returned				0x50
#define Data_Rcieved_ACK_NOT_Returned			0x58

#define Slave_Data_Rcieved_ACK_Returned_OWN_Adsress		0x80
#define Slave_Data_Rcieved_ACK_Returned_GeneralCall		0x90


void I2C_voidInitializtion(void);

void I2C_voidInterruptEnable(void);
void I2C_voidInterruptDisable(void);

void I2C_voidSendAck(void);
void I2C_voidRemoveAck(void);

u8 	 I2C_Master_SendStartCondition(void);
u8 	 I2C_Master_SendRepeatedStartCondition(void);
void I2C_Master_SendStopCondition(void);

u8 	 I2C_Master_SendSlaveAddress_Write(u8 Address);
u8 	 I2C_Master_SendSlaveAddress_Read(u8 Address);

u8 	 I2C_Master_SendData(u8 Data);
u8 	 I2C_Master_ReadData(u8 * Data);

u8   I2C_Slave_ReadData(u8 * Data);

#endif /* MCAL_I2C_I2C_INT_H_ */
