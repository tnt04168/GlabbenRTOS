/*
 * Task_game.c
 *
 * Created: 2019-01-19 23:26:18
 *  Author: André Ahlbertz
 */ 
#include <asf.h>

#include "Task_game.h"
#include "Setup_tasks.h"
#include "DelayFunctions.h"
#include "LCDFunctions.h"
#include "buttons.h"



xSemaphoreHandle button1 = NULL;
xSemaphoreHandle button2 = NULL;


void task_game(void *pvParameters){
	
	printf("task_game \n");
		/* Create Semaphores */
		
		vSemaphoreCreateBinary(button1);
		vSemaphoreCreateBinary(button2);
		
		int game_started = 0;
		int button1_started = 0;
		int button2_started = 0;
	
	while (1)
	{
		
		//printf("inside while in game");
		
		if (readLCDbutton() == btnSELECT && !ioport_get_pin_level(BUTTON_INPUT_01) && !ioport_get_pin_level(BUTTON_INPUT_02))	
		{	
			if (!game_started)
			{
				
				game_started = 1;
				
				lcdClearDisplay();
			
				ioport_set_pin_level(LED_OUTPUT, LOW);
			
				//Show game start on display
			
				//Randomized time
				uint32_t randomTime = trng_read_output_data(&myTrng)%5000000 + 2000000;		// microseconds
				printf("%lu\n", randomTime);
			
			
				//Start timer
				delayMicroseconds(randomTime);
			
				ioport_set_pin_level(LED_OUTPUT, HIGH);
				
				tc_start(TC0,0);
			}
			
		}
		
		
		if(ioport_get_pin_level(BUTTON_INPUT_01) && game_started && !button1_started)				//
		{
			//button1_started = 1;
			xSemaphoreGive(button1);
			vTaskDelay(100);

		}
		
		if(ioport_get_pin_level(BUTTON_INPUT_02) && game_started && !button2_started)				//
		{
			//button2_started = 1;
			xSemaphoreGive(button2);
			vTaskDelay(100);

			
		}
	
	}
	
}