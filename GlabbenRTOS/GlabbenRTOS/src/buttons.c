/*
 * buttons.c
 *
 * Created: 2015-06-12 16:28:53
 * Author: To Be Decided
 */ 

#include "buttons.h"
#include "adcFunctions.h"	/* Must use the value from the ADC to figure out which button */
#include <stdio.h>

buttonType readLCDbutton(void)
{
	uint32_t value_button = analogRead(0);
	
	if (value_button < 333)
	{
		return btnRIGHT;
	}
	if (value_button > 333 && value_button < 1000)
	{
		return btnUP;
	}
	if (value_button > 1000 && value_button < 1667)
	{
		return btnDOWN;
	}
	if (value_button > 1667 && value_button < 2333)
	{
		return btnLEFT;
	}
	if (value_button > 2333 && value_button < 3000)
	{
		return btnSELECT;
	}
	if (value_button > 3000 && value_button < 3667)
	{
		return btnNONE;
	}
	if (value_button > 3667)		// no button assigned
	{
		return btnNONE;
	}
	
	return btnNONE;
	//printf("Value was: %ul", value_button);
}