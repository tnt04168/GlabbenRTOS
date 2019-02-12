/**
 * \file
 *
 * Created: 2019-01-19
 * Author: André Ahlbertz & Sebastian Hoggard
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
#include "lcdApplication.h"
#include "DelayFunctions.h"


int main (void)
{
	

	
	/* Init board */
	
	
	board_init();
	sysclk_init();
	ioport_init();
	analogInit(0);
	configureConsole();
	delayInit();
	lcdInit();
	
	pmc_enable_periph_clk(ID_TRNG);
	trng_enable(TRNG);
	
	lcdClearDisplay();
	
	/*Init IO-pins*/
	
	ioport_set_pin_dir(BUTTON_INPUT_01, IOPORT_DIR_INPUT);
	ioport_set_pin_dir(BUTTON_INPUT_02, IOPORT_DIR_INPUT);
	ioport_set_pin_dir(LED_OUTPUT, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(LED_OUTPUT, LOW);
	
	ioport_set_pin_dir(PIO_PD0_IDX, IOPORT_DIR_OUTPUT);
	ioport_set_pin_level(PIO_PD0_IDX, HIGH);

	/* Create tasks */
	
	xTaskCreate(task_player1, (const signed char * const) "player1", TASK_PLAYER1_STACK_SIZE, NULL, TASK_PLAYER1_PRIORITY, NULL);
	
	xTaskCreate(task_player2, (const signed char * const) "player2", TASK_PLAYER2_STACK_SIZE, NULL, TASK_PLAYER2_PRIORITY, NULL);
	
	xTaskCreate(task_game, (const signed char * const) "game", TASK_GAME_STACK_SIZE, NULL, TASK_GAME_PRIORITY, NULL);
	
	/*Starting scheduler*/
	
	vTaskStartScheduler();
}
