/*
 * LCD_KIT_int.h
 *
 *  Created on: Jul 23, 2023
 *      Author: hp
 */

#ifndef HAL_LCD_KIT_LCD_KIT_INT_H_
#define HAL_LCD_KIT_LCD_KIT_INT_H_

#define Kit_not_Proteous

#define Clear_LCD 0x01

#ifdef Kit_not_Proteous
	#define Go_To_Left		Pin7	// from Port D
	#define Go_To_Right		Pin3	// from Port D
	#define Go_To_Up		Pin5	// from Port D
	#define Go_To_Down		Pin6	// from Port D
	#define Switch_Port		PortD
#else
	#define Go_To_Left		Pin4	// from Port C
	#define Go_To_Right		Pin5	// from Port C
	#define Go_To_Up		Pin7	// from Port D
	#define Go_To_Down		Pin6	// from Port D
	#define Switch_Port		PortC
#endif


#define Left  0x10
#define Right 0x14

#define Line1 0x80
#define Line2 0xC0
#define Line3 0x94
#define Line4 0xD4

#define Col0 0
#define Col1 1
#define Col2 2
#define Col3 3
#define Col4 4
#define Col5 5
#define Col6 6
#define Col7 7
#define Col8 8
#define Col9 9
#define Col10 10
#define Col11 11
#define Col12 12
#define Col13 13
#define Col14 14
#define Col15 15
#define Col16 16
#define Col17 17
#define Col18 18
#define Col19 19

#define meem {0x00,0x00,0x06,0x09,0x09,0x16,0x00,0x00}
#define haaa {0x00,0x00,0x0E,0x01,0x01,0x1E,0x00,0x00}
#define daal {0x00,0x00,0x01,0x01,0x01,0x0F,0x00,0x00}

#define eeen {0x00,0x00,0x07,0x08,0x08,0x1F,0x00,0x00}
#define alef {0x08,0x08,0x08,0x08,0x08,0x0F,0x00,0x00}
#define laam {0x01,0x01,0x01,0x09,0x09,0x0F,0x00,0x00}

#define MEEM 0
#define HAAA 1
#define DAAL 2
#define EEEN 3
#define ALEF 4
#define LAAM 5

void LCD_KIT_voidInitialization(void);
void LCD_KIT_voidDisplayCharacter(u8 character);
void LCD_KIT_voidRunCommand(u8 command);
void LCD_KIT_voidSetCurser(u8 Line , u8 Col);

void LCD_KIT_voidDisplayString(u8 *Str);
//void LCD_KIT_voidDisplayCustomCharacter(u8 *Str);
void LCD_KIT_voidDisplayBigNumber(u32 Number);

void LCD_KIT_voidStoreCustomCharacter(u8 *Character,u8 Address);

#endif /* HAL_LCD_KIT_LCD_KIT_INT_H_ */




