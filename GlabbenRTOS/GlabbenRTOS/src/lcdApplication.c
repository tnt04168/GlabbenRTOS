/*
 * lcdApplication.c
 *
 * Created: 2015-09-10 08:44:50
 *  Author: To Be Decided
 */ 

#include "lcdApplication.h"
#include "buttons.h"	/* to get the buttontype definiton */
#include "LCDFunctions.h"

int lcdWrite4DigitNumber(int number)
{
	char digits[4];
	number %= 10000;
	digits[0] = 48 + number/1000;
	number %= 1000;
	digits[1] = 48 + number/100;
	number %= 100;
	digits[2] = 48 + number/10;
	number %= 10;
	digits[3] = 48 + number;
	for (int index = 0; index < 4; index++)
	{
		lcdWrite(digits[index], 1);
	}
	
	return 0;	/* Assuming everything went ok */
}

int lcdWriteAsciiString(const char *string)
/* writes an ascii string up to 40 characters on the LCD display */
{
	for (int index = 0; index < 16; index++)
	{
		if (*(string + index) == NULL)
		{
			return 0;
		}
		lcdWrite(*(string + index), 1);
	}
	
	return 0;	/* Assuming everything went ok */
}

int lcdWriteButtonValue(buttonType inputButton)
/* Writes the text corresponding to one of the buttosn on the LCD dispaly using lcdWriteAsciiString() 
 * Output should be one of SELECT, LEFT, UP, DOWN, RIGHT on the LCD display
 * if no buttons is pushed you can chose on displaying nothing or NONE  */
{
	switch (inputButton)
	{
		case btnRIGHT:
			lcdWriteAsciiString("RIGHT");
			break;
		case btnUP:
			lcdWriteAsciiString("UP");
			break;
		case btnDOWN:
			lcdWriteAsciiString("DOWN");
			break;
		case btnLEFT:
			lcdWriteAsciiString("LEFT");
			break;
		case btnSELECT:
			lcdWriteAsciiString("SELECT");
			break;
		default:
			//lcdWriteAsciiString("NONE");
			break;
	}
	
	return 0;	/* Assuming everything went ok */
}