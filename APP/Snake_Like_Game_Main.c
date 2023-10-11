#include "STD_Types.h"
#include "Macros.h"

#include "DIO_int.h"
#include "DIO_reg.h"

#include "LCD_KIT_int.h"

#include <util/delay.h>


int main(void)
{
    LCD_KIT_voidInitialization();

	u8 Way_Flag, Previous_Way_flag, Col_Index=2, Line_Index=1;

		u8 Ball[8]={0x00,0x00,0x0E,0x1F,0x1F,0x1F,0x0E,0x00};
		LCD_KIT_voidStoreCustomCharacter(Ball,0x40);

		LCD_KIT_voidSetCurser(Line1,Col0);
		LCD_KIT_voidDisplayCharacter(0x00);

		while(1)
		{
			if(!DIO_u8GetPinValue(Switch_Port,Go_To_Right))
			{
				LCD_KIT_voidRunCommand(0x06);
				LCD_KIT_voidRunCommand(0x10);
				LCD_KIT_voidDisplayCharacter(' ');
				LCD_KIT_voidDisplayCharacter(0x00);
				Way_Flag=Right;
				Previous_Way_flag=Right;
				break;
			}
		}

		while(1)
		{
			if((Col_Index == 0)||(Col_Index == 21))
			{
				LCD_KIT_voidRunCommand(0x06);
				LCD_KIT_voidSetCurser(Line1,Col5);
				LCD_KIT_voidDisplayString("Game Over");
				break;
			}

			_delay_ms(200);

			if(!DIO_u8GetPinValue(Switch_Port,Go_To_Right))
			{
				LCD_KIT_voidRunCommand(0x06);
				Way_Flag=Right;
				_delay_ms(200);
			}
			else if(!DIO_u8GetPinValue(Switch_Port,Go_To_Left))
			{
				LCD_KIT_voidRunCommand(0x04);
				Way_Flag=Left;
				_delay_ms(200);
			}
			else if(!DIO_u8GetPinValue(PortD,Go_To_Up))
			{
				if(Way_Flag==Right)
				{
					LCD_KIT_voidRunCommand(Left);
					LCD_KIT_voidDisplayCharacter(' ');
				}
				else if(Way_Flag==Left)
				{
					LCD_KIT_voidRunCommand(Right);
					LCD_KIT_voidDisplayCharacter(' ');
				}

				if(Line_Index==1)
				{
					LCD_KIT_voidRunCommand(0x06);
					LCD_KIT_voidSetCurser(Line1,Col5);
					LCD_KIT_voidDisplayString("Game Over");
					break;
				}

				switch(Line_Index)
				{
				case 2:
					if(Way_Flag==Left)
					{
						LCD_KIT_voidSetCurser(Line1,Col_Index-2); break;
					}
					else
					{
						LCD_KIT_voidSetCurser(Line1,Col_Index); break;
					}

				case 3:
					if(Way_Flag==Left)
					{
						LCD_KIT_voidSetCurser(Line2,Col_Index-2); break;
					}
					else
					{
						LCD_KIT_voidSetCurser(Line2,Col_Index); break;
					}

				case 4:
					if(Way_Flag==Left)
					{
						LCD_KIT_voidSetCurser(Line3,Col_Index-2); break;
					}
					else
					{
						LCD_KIT_voidSetCurser(Line3,Col_Index); break;
					}
				}
				Line_Index--;
				_delay_ms(200);
			}
			else if (!DIO_u8GetPinValue(PortD,Go_To_Down))
			{
				if(Way_Flag==Right)
				{
					LCD_KIT_voidRunCommand(Left);
					LCD_KIT_voidDisplayCharacter(' ');
				}
				else if(Way_Flag==Left)
				{
					LCD_KIT_voidRunCommand(Right);
					LCD_KIT_voidDisplayCharacter(' ');
				}

				if(Line_Index==4)
				{
					LCD_KIT_voidRunCommand(0x06);
					LCD_KIT_voidSetCurser(Line1,Col5);
					LCD_KIT_voidDisplayString("Game Over");
					break;
				}

				switch(Line_Index)
				{
				case 1:
					if(Way_Flag==Left)
					{
						LCD_KIT_voidSetCurser(Line2,Col_Index-2); break;
					}
					else
					{
						LCD_KIT_voidSetCurser(Line2,Col_Index); break;
					}

				case 2:
					if(Way_Flag==Left)
					{
						LCD_KIT_voidSetCurser(Line3,Col_Index-2); break;
					}
					else
					{
						LCD_KIT_voidSetCurser(Line3,Col_Index); break;
					}

				case 3:
					if(Way_Flag==Left)
					{
						LCD_KIT_voidSetCurser(Line4,Col_Index-2); break;
					}
					else
					{
						LCD_KIT_voidSetCurser(Line4,Col_Index); break;
					}
				}
				Line_Index++;
				_delay_ms(200);
			}

			if((Way_Flag==Left)&&(Previous_Way_flag==Left))
			{
				Col_Index--;
				LCD_KIT_voidRunCommand(Right);
				LCD_KIT_voidDisplayCharacter(' ');

				if(Col_Index > 0)
				{
					LCD_KIT_voidDisplayCharacter(0x00);
				}
			}
			else if((Way_Flag==Left)&&(Previous_Way_flag==Right))
			{
				LCD_KIT_voidRunCommand(Left);
				LCD_KIT_voidDisplayCharacter(' ');
				LCD_KIT_voidDisplayCharacter(0x00);
				Previous_Way_flag=Left;
				Col_Index--;
			}
			else if((Way_Flag==Right)&&(Previous_Way_flag==Right))
			{
				Col_Index++;
				LCD_KIT_voidRunCommand(Left);
				LCD_KIT_voidDisplayCharacter(' ');

				if(Col_Index<21)
				{
					LCD_KIT_voidDisplayCharacter(0x00);
				}
			}
			else if((Way_Flag==Right)&&(Previous_Way_flag==Left))
			{
				LCD_KIT_voidRunCommand(Right);
				LCD_KIT_voidDisplayCharacter(' ');
				LCD_KIT_voidDisplayCharacter(0x00);
				Previous_Way_flag=Right;
				Col_Index++;
			}

	}

	return 0;
}




