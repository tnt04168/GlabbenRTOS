/*
 * Setup_tasks.h
 *
 * Created: 2019-01-20 07:35:56
 *  Author: André Ahlbertz
 */ 
#include <ioport.h>

#ifndef SETUP_TASKS_H_
#define SETUP_TASKS_H_

/* Setup Task 01 */

#define TASK_PLAYER1_STACK_SIZE (2048/ sizeof(portSTACK_TYPE))
#define TASK_PLAYER1_PRIORITY (1)

#define BUTTON_INPUT_01 PIO_PC8_IDX		//Pin 40


/* Setup Task 02 */

#define TASK_PLAYER2_STACK_SIZE (2048/ sizeof(portSTACK_TYPE))
#define TASK_PLAYER2_PRIORITY (1)

#define BUTTON_INPUT_02 PIO_PC17_IDX		//Pin 46


/* Setup Game task */

#define TASK_GAME_STACK_SIZE (2048/ sizeof(portSTACK_TYPE))
#define TASK_GAME_PRIORITY (2)

#define LED_OUTPUT PIO_PC13_IDX			//Pin 50


#endif /* SETUP_TASKS_H_ */