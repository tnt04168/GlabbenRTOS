/*
 * Task_player1.c
 *
 * Created: 2019-01-19 23:24:51
 *  Author: André Ahlbertz
 */ 
#include <asf.h>

#include "Task_player1.h"
#include "Setup_tasks.h"
#include "Task_game.h"
#include "lcdApplication.h"
#include "LCDFunctions.h"


void task_player1(void *pvParameters) {

	
	while(1) {
		if (xSemaphoreTake(button1,100))
		{
			lcdClearDisplay();
			lcdWrite(1,1);
			printf("player1 semaphore ok \n");
		}
		
		
	}
	
}
