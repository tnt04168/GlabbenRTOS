/*
 * Task_player1.c
 *
 * Created: 2019-01-19 23:24:51
 *  Author: André Ahlbertz & Sebastian Hoggard
 */ 
#include <asf.h>

#include "Task_player1.h"
#include "Setup_tasks.h"
#include "Task_game.h"
#include "lcdApplication.h"
#include "LCDFunctions.h"


void task_player1(void *pvParameters) {
	
	
	
	while(1) {
		if (ioport_get_pin_level(BUTTON_INPUT_01))
		{
			xSemaphoreGive(button1);
			//printf("Button 1 pressed\n");
			/*fflush(stdout);*/
			
			vTaskDelay(2000);
			
		}
		
		vTaskDelay(1);
	}
	
}
