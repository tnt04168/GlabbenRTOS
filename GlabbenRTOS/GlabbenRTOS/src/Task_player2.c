/*
 * Task_player2.c
 *
 * Created: 2019-01-19 23:25:47
 *  Author: André Ahlbertz
 */ 
#include <asf.h>

#include "Task_player2.h"
#include "Setup_tasks.h"
#include "Task_game.h"
#include "lcdApplication.h"
#include "LCDFunctions.h"



void task_player2(void *pvParameters) {

	
	while(1) {
		if (xSemaphoreTake(button2,100))
		{
			lcdClearDisplay();
			printf("player2 semaphore ok \n");
			vTaskDelay(100);
		}
		
		
	}
	
}
