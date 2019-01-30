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

int button1_test = 0;
int button2_test = 0;


void task_game(void *pvParameters){
	
	printf("task_game \n");
		/* Create Semaphores */
		
		vSemaphoreCreateBinary(button1);
		vSemaphoreCreateBinary(button2);
		
		
		int timer_time = 0;
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
				printf("Game start \n");
					
					//Randomized time
					//uint32_t randomTime = trng_read_output_data(&myTrng)%5000000 + 2000000;		// microseconds
// 					uint32_t randomTime = 2000000;		// microseconds
// 					printf("%lu\n", randomTime);
					
				uint32_t count = (trng_read_output_data(TRNG) % 5000000) + 2000000;
				printf("Time in loop: %lu \n",count);
					
					//Start timer
					//delayMicroseconds(randomTime);
					
				delayMicroseconds(timer_time);
					
				ioport_set_pin_level(LED_OUTPUT, HIGH);
					
				
				
			}
			
		}
		
		
		
		
		if(ioport_get_pin_level(BUTTON_INPUT_01) && game_started && !button1_started)				//
		{
			//button1_started = 1;
			if (xSemaphoreGive(button1) == pdTRUE)
			{
				button1_test = 1;
				printf("Sem1 given \n");
			}
			vTaskDelay(100);

		}
		
		if(ioport_get_pin_level(BUTTON_INPUT_02) && game_started && !button2_started)				//
		{
			//button2_started = 1;
			if (xSemaphoreGive(button2) == pdTRUE)
			{
				button2_test = 1;
				printf("Sem2 given \n");
			}
			vTaskDelay(100);

			
		}
		
// 		uint32_t button_register = PIOC->PIO_PDSR;
// 		if ((button_register & (1<<8)) && (button_register & (1<<17)))
// 		{
// 			printf("Both buttons!\n");
// 			continue;
// 		}
// 		if (button_register & (1<<8))
// 		{
// 			
// 			xSemaphoreGive(button1);
// 			continue;
// 		}
// 		if (button_register & (1<<17))
// 		{
// 			
// 			xSemaphoreGive(button2);
// 			continue;
// 		}
	
	}
	
}