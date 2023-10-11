/*
 * I2C_priv.h
 *
 *  Created on: Aug 7, 2023
 *      Author: hp
 */

#ifndef MCAL_I2C_I2C_PRIV_H_
#define MCAL_I2C_I2C_PRIV_H_

// SCL Freq = (CPU Clock Freq)/(16+2*(TWBR)*4^TWPS)
#define TWBR	*((volatile u8 * )(0X20))

#define TWCR	*((volatile u8 * )(0X56))

#define TWCR_TWINT   Pin7
#define TWCR_TWEA    Pin6
#define TWCR_TWSTA   Pin5
#define TWCR_TWSTO   Pin4
#define TWCR_TWWC    Pin3
#define TWCR_TWEN    Pin2
#define TWCR_TWIE    Pin0

#define TWSR   	*((volatile u8 * )(0X21))

#define TWSR_TWS7    Pin7
#define TWSR_TWS6    Pin6
#define TWSR_TWS5    Pin5
#define TWSR_TWS4    Pin4
#define TWSR_TWS3    Pin3
#define TWSR_TWPS1   Pin1
#define TWSR_TWPS0   Pin0

#define TWDR	*((volatile u8 * )(0X23))

#define TWAR	*((volatile u8 * )(0X22))

#define TWAR_TWA7    Pin7
#define TWAR_TWA6    Pin6
#define TWAR_TWA5    Pin5
#define TWAR_TWA4    Pin4
#define TWAR_TWA3    Pin3
#define TWAR_TWA2    Pin2
#define TWAR_TWA 1   Pin1
#define TWAR_TWGCE   Pin0


#endif /* MCAL_I2C_I2C_PRIV_H_ */
