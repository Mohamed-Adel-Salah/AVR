#include "STD_Types.h"
#include "Macros.h"

#include "DIO_int.h"
#include "DIO_reg.h"

#include "LCD_KIT_int.h"

#include <util/delay.h>

int main(void)
{
	LCD_KIT_voidInitialization();
	u8 Delay_Counter=0;

	u8 Leg_10=1,Leg_9=1,Leg_8=1;

//setting custom character array
	u8 Person_State[6][8]=
	{
		{0x04,0x0A,0x04,0x1F,0x04,0x04,0x0A,0x0A},
		{0x04,0x0A,0x05,0x0E,0x14,0x04,0x0A,0x11},
		{0x04,0x0A,0x14,0x0E,0x05,0x04,0x0A,0x11},
		{0x08,0x14,0x09,0x0A,0x04,0x0B,0x12,0x00},
		{0x02,0x05,0x12,0x0A,0x04,0x1A,0x09,0x00},
		{0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02}
	};

// Store characters
	LCD_KIT_voidStoreCustomCharacter(Person_State[0],0x40);
	LCD_KIT_voidStoreCustomCharacter(Person_State[1],0x48);
	LCD_KIT_voidStoreCustomCharacter(Person_State[2],0x50);
	LCD_KIT_voidStoreCustomCharacter(Person_State[3],0x58);
	LCD_KIT_voidStoreCustomCharacter(Person_State[4],0x60);
	LCD_KIT_voidStoreCustomCharacter(Person_State[5],0x68);

// Ready-Steady-Go stage
	LCD_KIT_voidSetCurser(Line1,Col7);
	LCD_KIT_voidDisplayString("Ready");
	_delay_ms(500);
	LCD_KIT_voidRunCommand(Clear_LCD);

	LCD_KIT_voidSetCurser(Line1,Col7);
	LCD_KIT_voidDisplayString("Steady");
	_delay_ms(500);
	LCD_KIT_voidRunCommand(Clear_LCD);

	LCD_KIT_voidSetCurser(Line1,Col9);
	LCD_KIT_voidDisplayString("GO");
	_delay_ms(500);
	LCD_KIT_voidRunCommand(Clear_LCD);

// Setting players positions
	LCD_KIT_voidSetCurser(Line3,Col0);
	LCD_KIT_voidDisplayCharacter(0x00);

	LCD_KIT_voidSetCurser(Line2,Col0);
	LCD_KIT_voidDisplayCharacter(0x00);

	LCD_KIT_voidSetCurser(Line4,Col0);
	LCD_KIT_voidDisplayCharacter(0x00);

// Setting Barriers Positions
	LCD_KIT_voidSetCurser(Line2,Col2);
	LCD_KIT_voidDisplayCharacter(0xFF);
	LCD_KIT_voidSetCurser(Line2,Col18);
	LCD_KIT_voidDisplayCharacter(0xFF);

	LCD_KIT_voidSetCurser(Line3,Col10);
	LCD_KIT_voidDisplayCharacter(0xFF);
	LCD_KIT_voidSetCurser(Line3,Col16);
	LCD_KIT_voidDisplayCharacter(0xFF);

	LCD_KIT_voidSetCurser(Line4,Col13);
	LCD_KIT_voidDisplayCharacter(0xFF);
	LCD_KIT_voidSetCurser(Line4,Col17);
	LCD_KIT_voidDisplayCharacter(0xFF);

// Setting End line Positions
	LCD_KIT_voidSetCurser(Line2,Col19);
	LCD_KIT_voidDisplayCharacter(0x05);
	LCD_KIT_voidSetCurser(Line3,Col19);
	LCD_KIT_voidDisplayCharacter(0x05);
	LCD_KIT_voidSetCurser(Line4,Col19);
	LCD_KIT_voidDisplayCharacter(0x05);

// Start Game
	LCD_KIT_voidSetCurser(Line1,Col4);
	LCD_KIT_voidDisplayString("Run Bary Run");

	while(1)
	{
		if(Delay_Counter<153)
		{
			_delay_ms(10);
			Delay_Counter++;

			if(Delay_Counter%10==0)
			{
				if((Delay_Counter/10==2)||(Delay_Counter/10==3)||(Delay_Counter/10==18)||(Delay_Counter/10==19))
				{
					if(Leg_10==1)
					{
						LCD_KIT_voidSetCurser(Line1,Delay_Counter/10);
						LCD_KIT_voidRunCommand(0x10);
						LCD_KIT_voidDisplayCharacter(' ');
						LCD_KIT_voidSetCurser(Line2,Delay_Counter/10);
						LCD_KIT_voidDisplayCharacter(0x03);
						Leg_10=2;
					}
					else if(Leg_10==2)
					{
						LCD_KIT_voidSetCurser(Line2,Delay_Counter/10);
						LCD_KIT_voidRunCommand(0x10);
						LCD_KIT_voidDisplayCharacter(' ');
						LCD_KIT_voidSetCurser(Line1,Delay_Counter/10);
						LCD_KIT_voidDisplayCharacter(0x04);
						Leg_10=1;
					}
				}
				else
				{
					LCD_KIT_voidSetCurser(Line2,Delay_Counter/10);
					LCD_KIT_voidRunCommand(0x10);
					LCD_KIT_voidDisplayCharacter(' ');
					LCD_KIT_voidSetCurser(Line2,Delay_Counter/10);

					if(Leg_10==1)
					{
						LCD_KIT_voidDisplayCharacter(0x01);
						Leg_10=2;
					}
					else if(Leg_10==2)
					{
						LCD_KIT_voidDisplayCharacter(0x02);
						Leg_10=1;
					}
				}
			}

			if(Delay_Counter%9==0)
			{
				if((Delay_Counter/9==13)||(Delay_Counter/9==14)||(Delay_Counter/9==17)||(Delay_Counter/9==18))
				{
					if(Leg_9==1)
					{
						LCD_KIT_voidSetCurser(Line4,Delay_Counter/9);
						LCD_KIT_voidRunCommand(0x10);
						LCD_KIT_voidDisplayCharacter(' ');
						LCD_KIT_voidSetCurser(Line3,Delay_Counter/9);
						LCD_KIT_voidDisplayCharacter(0x01);
						Leg_9=2;
					}
					else if(Leg_9==2)
					{
						LCD_KIT_voidSetCurser(Line3,Delay_Counter/9);
						LCD_KIT_voidRunCommand(0x10);
						LCD_KIT_voidDisplayCharacter(' ');
						LCD_KIT_voidSetCurser(Line4,Delay_Counter/9);
						LCD_KIT_voidDisplayCharacter(0x02);
						Leg_9=1;
					}
				}
				else
				{
					LCD_KIT_voidSetCurser(Line4,Delay_Counter/9);
					LCD_KIT_voidRunCommand(0x10);
					LCD_KIT_voidDisplayCharacter(' ');
					LCD_KIT_voidSetCurser(Line4,Delay_Counter/9);

					if(Leg_9==1)
					{
						LCD_KIT_voidDisplayCharacter(0x01);
						Leg_9=2;
					}
					else if(Leg_9==2)
					{
						LCD_KIT_voidDisplayCharacter(0x02);
						Leg_9=1;
					}
				}
			}

			if(Delay_Counter%8==0)
			{
				if((Delay_Counter/8==10)||(Delay_Counter/8==11)||(Delay_Counter/8==16)||(Delay_Counter/8==17))
				{
					if(Leg_8==1)
					{
						LCD_KIT_voidSetCurser(Line2,Delay_Counter/8);
						LCD_KIT_voidRunCommand(0x10);
						LCD_KIT_voidDisplayCharacter(' ');
						LCD_KIT_voidSetCurser(Line3,Delay_Counter/8);
						LCD_KIT_voidDisplayCharacter(0x01);
						Leg_8=2;
					}
					else if(Leg_8==2)
					{
						LCD_KIT_voidSetCurser(Line3,Delay_Counter/8);
						LCD_KIT_voidRunCommand(0x10);
						LCD_KIT_voidDisplayCharacter(' ');
						LCD_KIT_voidSetCurser(Line2,Delay_Counter/8);
						LCD_KIT_voidDisplayCharacter(0x02);
						Leg_8=1;
					}
				}
				else
				{
					LCD_KIT_voidSetCurser(Line3,Delay_Counter/8);
					LCD_KIT_voidRunCommand(0x10);
					LCD_KIT_voidDisplayCharacter(' ');
					LCD_KIT_voidSetCurser(Line3,Delay_Counter/8);

					if(Leg_8==1)
					{
						LCD_KIT_voidDisplayCharacter(0x01);
						Leg_8=2;
					}
					else if(Leg_8==2)
					{
						LCD_KIT_voidDisplayCharacter(0x02);
						Leg_8=1;
					}
				}
			}
		}
		else
		{
			LCD_KIT_voidSetCurser(Line2,Col19);
			LCD_KIT_voidDisplayCharacter(' ');
			LCD_KIT_voidSetCurser(Line4,Col19);
			LCD_KIT_voidDisplayCharacter(' ');
			_delay_ms(100);
			break;
		}
	}

	LCD_KIT_voidRunCommand(0x01);
	LCD_KIT_voidDisplayString(" The winner is Bary");
	LCD_KIT_voidSetCurser(Line2,Col0);
	LCD_KIT_voidDisplayString("Bary has just broken");
	LCD_KIT_voidSetCurser(Line3,Col0);
	LCD_KIT_voidDisplayString("  the WORLD RECORD");

//setting custom character array
	u8 Arabic_Word[6][8]=
	{
		{0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00},
		{0x01,0x01,0x01,0x01,0x01,0x01,0x1F,0x00},
		{0x00,0x00,0x0E,0x01,0x01,0x01,0x1E,0x00},
		{0x00,0x00,0x06,0x09,0x09,0x09,0x16,0x00},
		{0x00,0x00,0x01,0x01,0x01,0x01,0x0F,0x00},
		{0x00,0x06,0x09,0x09,0x07,0x01,0x01,0x00}
	};

// Store characters
	LCD_KIT_voidStoreCustomCharacter(Arabic_Word[0],0x40);
	LCD_KIT_voidStoreCustomCharacter(Arabic_Word[1],0x48);
	LCD_KIT_voidStoreCustomCharacter(Arabic_Word[2],0x50);
	LCD_KIT_voidStoreCustomCharacter(Arabic_Word[3],0x58);
	LCD_KIT_voidStoreCustomCharacter(Arabic_Word[4],0x60);
	LCD_KIT_voidStoreCustomCharacter(Arabic_Word[5],0x68);

// Setting Cursor to shift left to print Arabic word
	LCD_KIT_voidRunCommand(0x04);

// Return cursor to DDRAM
	LCD_KIT_voidSetCurser(Line4, Col13);

// Printing Arabic word
	LCD_KIT_voidDisplayCharacter(0);
	LCD_KIT_voidDisplayCharacter(1);
	LCD_KIT_voidDisplayCharacter(2);
	LCD_KIT_voidDisplayCharacter(3);
	LCD_KIT_voidDisplayCharacter(4);

	LCD_KIT_voidDisplayCharacter(1);
	LCD_KIT_voidDisplayCharacter(1);
	LCD_KIT_voidDisplayCharacter(5);

	return 0;
}
