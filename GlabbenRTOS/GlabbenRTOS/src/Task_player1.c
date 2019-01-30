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
	
	uint32_t time_passed1 = 0;
	
	while(1) {
		if (xSemaphoreTake(button1,portMAX_DELAY) && button2_test)
		{
			
			//lcdClearDisplay();
			//lcdWrite(1,1);
// 			time_passed1 = tc_read_cv(TC0,0);
// 			
// 			
// 			vTaskDelay(2000);
// 			
// 			printf("Time 1: %lu \n", time_passed1);
			
			printf("Only button 1\n");
			/*fflush(stdout);*/
			
			vTaskDelay(1000);
			
			button1_test = 1;
			
			
			
			
		}
		
		
	}
	
}
