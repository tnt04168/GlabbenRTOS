/*
 * adcFunctions.c
 *
 * Created: 2015-06-16 09:00:18
 *  Author: To Be Decided
 */ 

#include <inttypes.h>
#include <asf.h>
#include "adcFunctions.h"

int analogInit(int pinNumber)
{
	/* 
	 * The pin number is the analog input pin on the DUe board, see http://www.arduino.cc/en/Hacking/PinMappingSAM3X
	 * Obviously it starts at analog 0 which is equivalent to the analog input on PA16
	 * so you need to figure out which AD channel this corresponds to
	 *
	 * See code example http://asf.atmel.com/docs/latest/sam.drivers.adc.adc_example.arduino_due_x/html/sam_adc_quickstart.html
	 * It is assumed that the AD-converter is using 12 bits
	 */
	
	pinNumber = 7 - pinNumber;		// assumed
	
	pmc_enable_periph_clk(ID_ADC);	/* power the clock for the ADC with pmc_enable_periph_clk(ID_ADC) */
	
	adc_init(ADC, sysclk_get_main_hz(), 20000000, 0);
	adc_configure_timing(ADC, 0, 0, 0);
	adc_set_resolution(ADC, ADC_MR_LOWRES_BITS_12);
	adc_enable_channel(ADC, pinNumber);
	adc_configure_trigger(ADC, ADC_TRIG_SW, 1);
	
	return 0;	/* if everything is ok */
}

uint32_t analogRead(int pinNumber)
{
	adc_start(ADC);
	while ((adc_get_status(ADC) & 0x1<<24) == 0);
	uint32_t value = adc_get_channel_value(ADC, 7 - pinNumber);

	return value;	/* Replace with actual value read from A/D input*/
}