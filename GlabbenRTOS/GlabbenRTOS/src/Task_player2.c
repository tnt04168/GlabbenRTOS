/*
 * Task_player2.c
 *
 * Created: 2019-01-19 23:25:47
 *  Author: André Ahlbertz & Sebastian Hoggard
 */ 
#include <asf.h>

#include "Task_player2.h"
#include "Setup_tasks.h"
#include "Task_game.h"
#include "lcdApplication.h"
#include "LCDFunctions.h"



void task_player2(void *pvParameters) {

	
	while(1) {
		if (ioport_get_pin_level(BUTTON_INPUT_02))
		{
			xSemaphoreGive(button2);
			//printf("Button 2 pressed\n");
			/*fflush(stdout);*/
			
			vTaskDelay(2000);
			
			
			
			
		}
		vTaskDelay(1);
		
	}
	
}
