/*
 * Task_game.h
 *
 * Created: 2019-01-19 23:27:31
 *  Author: André Ahlbertz
 */ 


#ifndef TASK_GAME_H_
#define TASK_GAME_H_

#include "asf.h"

extern xSemaphoreHandle button1;
extern xSemaphoreHandle button2;

extern int button1_test;
extern int button2_test;


void task_game(void *pvParameters);



#endif /* TASK_GAME_H_ */