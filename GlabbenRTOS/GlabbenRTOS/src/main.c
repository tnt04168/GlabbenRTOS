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
#include "lcdApplication.h"
#include "DelayFunctions.h"


int main (void)
{
	
	PIOC->PIO_PUDR  |= PIO_PC18 | PIO_PC16; /* Set pull-up for both buttons */
	PIOC->PIO_IFER  |= PIO_PC18 | PIO_PC16; /* Enable switch debounce filter for both buttons */
	PIOC->PIO_DIFSR |= PIO_PC18 | PIO_PC16;
	
	/* Init board */
	
	
	board_init();
	sysclk_init();
	
	configureConsole();
	delayInit();
	analogInit(0);
	lcdInit();
	pmc_enable_periph_clk(ID_TRNG);
	/*tc_init(TC0, 0, 0);*/
	
	trng_enable(TRNG);
	
	lcdClearDisplay();
	//lcdWrite(0x31,1);
	delayMicroseconds(5000);
	
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
