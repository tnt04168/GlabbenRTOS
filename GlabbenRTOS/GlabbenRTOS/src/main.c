/**
 * \file
 *
 * \brief Empty user application template
 *
 */

#include <asf.h>


#include "Task_game.h"
#include "Task_player1.h"
#include "Task_player2.h"
#include "Setup_tasks.h"
#include "consoleFunctions.h"
#include "adcFunctions.h"
#include "LCDFunctions.h"
#include "DelayFunctions.h"


int main (void)
{
	/* Init board */
	
	sysclk_init();
	board_init();
	
	configureConsole();
	delayInit();
	analogInit(0);
	lcdInit();
	pmc_enable_periph_clk(ID_TRNG);
	
	trng_enable(&myTrng);
	
	/*Init IO-pins*/
	
	ioport_set_pin_dir(BUTTON_INPUT_01, IOPORT_DIR_INPUT);
	ioport_set_pin_dir(BUTTON_INPUT_02, IOPORT_DIR_INPUT);
	ioport_set_pin_dir(LED_OUTPUT, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(LED_OUTPUT, LOW);

	/* Create tasks */
	
	xTaskCreate(task_player1, (const signed char * const) "player1", TASK_PLAYER1_STACK_SIZE, NULL, TASK_PLAYER1_PRIORITY, NULL);
	
	xTaskCreate(task_player2, (const signed char * const) "player2", TASK_PLAYER2_STACK_SIZE, NULL, TASK_PLAYER2_PRIORITY, NULL);
	
	xTaskCreate(task_game, (const signed char * const) "game", TASK_GAME_STACK_SIZE, NULL, TASK_GAME_PRIORITY, NULL);
	
	/*Starting scheduler*/
	
	vTaskStartScheduler();
}
