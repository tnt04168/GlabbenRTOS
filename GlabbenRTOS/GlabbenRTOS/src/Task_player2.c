﻿/*
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
	
	uint32_t time_passed2 = 0;
	
	while(1) {
		if (xSemaphoreTake(button2,portMAX_DELAY) && button1_test)
		{
			//lcdClearDisplay();
			//printf("player2 semaphore ok \n");
			//vTaskDelay(100);
// 			time_passed2 = tc_read_cv(TC0,0);
// 			
// 			vTaskDelay(2000);
// 			
// 			printf("Time 2: %lu \n", time_passed2);
			
			printf("Only button 2\n");
			/*fflush(stdout);*/
			
			vTaskDelay(1000);
			
			button2_test = 1;
			
			
		}
		
		
	}
	
}
