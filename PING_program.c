/****************************************************************/
/****************************************************************/
/***********************   YEHIA SHAHIN   ***********************/
/***********************   Layer :APP    ***********************/
/***********************   SWC (DRIVER):PING *********************/
/***********************   DATA : 24-8-2020 *********************/
/***********************   VERSION : 1.00   *********************/
/****************************************************************/
/****************************************************************/

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "EXTI_interface.h"
#include "PING_interface.h"
#include "PING_private.h"
#include "CLCD_interface.h"
#include <util/delay.h>

char PING_00[8] = {
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00110,
	0b00101,
	0b00100,
	0b00100
};

char PING_10[8] = {
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b01100,
	0b10100,
	0b00100,
	0b00100
};

char PING_01[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b10000,
	0b01110,
	0b00100,
	0b00010,
	0b00001
};
char PING_11[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b00001,
	0b10010,
	0b01100,
	0b01000,
	0b10000
};
char  NETWORK [8] = {
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100,
	0b00100
};
char BALL[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b01100,
	0b01100,
	0b00000,
	0b00000,
	0b00000
};
char Zero[8] = {
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};
void PING_voidPlay (void)
{
	u8 Local_Pu8ValueE ;
	u8 Local_Pu8ValueD ;
	u8 Local_Pu8Value1;
	u8 Local_Pu8Value2;
CLCD_voidSendCommand(1);
	CLCD_voidFullLcd("STRAT:1  END:2",0,0);

	DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN6,&Local_Pu8ValueE);
	DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN7,&Local_Pu8ValueD);
	while ((Local_Pu8ValueE==DIO_u8PIN_HIGH)&&(Local_Pu8ValueD==DIO_u8PIN_HIGH))
	{
		DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN6,&Local_Pu8ValueE);
		DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN7,&Local_Pu8ValueD);
	}

	if (Local_Pu8ValueE==DIO_u8PIN_LOW)
	{
		CLCD_voidSendCommand(1);
	CLCD_voidWriteSpecialCharacter(PING_10,0,0,0);
	CLCD_voidWriteSpecialCharacter(PING_00,1,14,0);
	CLCD_voidWriteSpecialCharacter(NETWORK,2,0x47,1);
	DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN7,&Local_Pu8ValueD);


	while (Local_Pu8ValueD != DIO_u8PIN_LOW)
	{	DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN2,&Local_Pu8Value1);
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN3,&Local_Pu8Value2);
	while ((Local_Pu8Value1!=DIO_u8PIN_LOW)&&(Local_Pu8Value2!=DIO_u8PIN_LOW))
	{
		DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN7,&Local_Pu8ValueD);
		if(Local_Pu8ValueD==DIO_u8PIN_LOW)
			{
				CLCD_voidSendCommand(1);
				CLCD_voidFullLcd("THANK YOU",3,0);
				return;


			}


		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN2,&Local_Pu8Value1);
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN3,&Local_Pu8Value2);

	}

	if (Local_Pu8Value1==DIO_u8PIN_LOW)
	{
	EXTI_u8EnableInterrrupt(EXTI_INT0);
	}
	else if (Local_Pu8Value2 == DIO_u8PIN_LOW)
	{
		EXTI_u8EnableInterrrupt(EXTI_INT1);
	}
	DIO_u8GetPinValue(DIO_u8PORTC,DIO_u8PIN7,&Local_Pu8ValueD);
	}



	if(Local_Pu8ValueD==DIO_u8PIN_LOW)
	{
		CLCD_voidSendCommand(1);
		CLCD_voidFullLcd("THANK YOU",3,0);


	}

	}

}
