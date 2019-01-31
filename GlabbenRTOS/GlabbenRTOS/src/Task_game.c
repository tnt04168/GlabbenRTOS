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
#include "lcdApplication.h"
#include "buttons.h"



xSemaphoreHandle button1 = NULL;
xSemaphoreHandle button2 = NULL;

// int button1_test = 0;
// int button2_test = 0;


void task_game(void *pvParameters){
	
	printf("task_game \n");
		/* Create Semaphores */
		
		vSemaphoreCreateBinary(button1);
		vSemaphoreCreateBinary(button2);
		if (xSemaphoreTake(button1,portMAX_DELAY))
		{
			printf("Semaphore 1 init OK\n");
		}
		if (xSemaphoreTake(button2,portMAX_DELAY))
		{
			printf("Semaphore 2 init OK\n");
		}
		
		int game_started = 0;
		int button1_started = 0;
		int button2_started = 0;
		volatile int start_time = 0;
		volatile int player1_time = 0;
		volatile int player2_time = 0;
		int final_time = 0;
		int temp = 0;
		int temp2 = 0;
		int win_state = 0;
	
	while (1)
	{
		
		//printf("inside while in game");
		while (!game_started && !ioport_get_pin_level(BUTTON_INPUT_01) && !ioport_get_pin_level(BUTTON_INPUT_02))
		{
// 			lcdClearDisplay();
// 			lcdWriteAsciiString("Press start");
			if (!temp)
			{
				printf("Press start \n");
				temp = 1;
			}
			
			if (readLCDbutton() == btnSELECT && !game_started)
			{
				game_started = 1;
				
				lcdClearDisplay();
				
				
				ioport_set_pin_level(LED_OUTPUT, LOW);
				printf("Game start! \n");
				
				uint32_t count = (trng_read_output_data(TRNG) % 5000000) + 2000000;
				printf("Time in loop: %lu \n",count);
				
				delayMicroseconds(count);
				
				ioport_set_pin_level(LED_OUTPUT, HIGH);
				start_time = xTaskGetTickCount();
				xSemaphoreTake(button1,0);
				xSemaphoreTake(button2,0);
			}
		}
		
		
		
		
		while (game_started)
		{
			
			
			
			if((xSemaphoreTake(button1,0) || ((xTaskGetTickCount() - start_time) > 20000)) && !button1_started)				
			{
				if ((xTaskGetTickCount() - start_time) < 20000)
				{
					player1_time = (xTaskGetTickCount() - start_time);
					button1_started = 1;
					printf("Time player 1: %d \n", player1_time);
				}else{
					player1_time = 20000;
					button1_started = 1;
					printf("Player 1 timeout \n");
				}
				
			}
			
			if((xSemaphoreTake(button2,0) || ((xTaskGetTickCount() - start_time) > 20000)) && !button2_started)				
			{
				if ((xTaskGetTickCount() - start_time) < 20000)
				{
					player2_time = (xTaskGetTickCount() - start_time);
					button2_started = 1;
					printf("Time player 2: %d \n", player2_time);
				}else{
					player2_time = 20000;
					button2_started = 1;
					printf("Player 2 timeout \n");
				}
				
			}
			
			
			while(button1_started && button2_started)
			{
				final_time = player1_time - player2_time;
				
				if (final_time < 0)
				{
					win_state = 1;
				}else if (final_time > 0 )
				{
					win_state = 2;
				}else{
					win_state = 3;
				}
				if (!temp2)
				{
					switch (win_state)
					{
						case 1:
						printf("Player 1 wins! \n");
						temp2 = 1;
						break;
						case 2:
						printf("Player 2 wins! \n");
						temp2 = 1;
						break;
						case 3:
						printf("It's a draw!!! \n");
						temp2 = 1;
						break;
					}
				}
				
				
				
			}
			
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