/******************************************************************************
    FILE DESCRIPTION
*------------------------------------------------------------------------------
*     /file  Gpt_Lcfg.c  
*     /brief
*
*     /details
*
*****************************************************************************/

/****************************************************************************
*  INCLUDES
*****************************************************************************/
#include "../Mcal/Inc/Gpt_Interface.h"
#include "Gpt_Cfg.h"

/****************************************************************************
*  GLOBAL DATA
*****************************************************************************/
/*Intialize struct of type Gpio_PinConfigurationsType for every initialized pin.
Struct elements are:
	1- timerBlockId 
			Can be intialized to:
				GPTM_TIMER_0_ID
				GPTM_TIMER_1_ID
				GPTM_TIMER_2_ID
				GPTM_TIMER_3_ID
				GPTM_TIMER_4_ID
				GPTM_TIMER_5_ID
				GPTM_WIDE_TIMER_0_ID
				GPTM_WIDE_TIMER_1_ID
				GPTM_WIDE_TIMER_2_ID
				GPTM_WIDE_TIMER_3_ID
				GPTM_WIDE_TIMER_4_ID
				GPTM_WIDE_TIMER_5_ID

	2- timerId	
			Can be intialized to:
				GPTM_TIMER_A
				GPTM_TIMER_B
				
	3- mode
			Can be intialized to:
				ONE_SHOT
				PERIODIC
			
	4- configuration
			Can be intialized to:
				GPTM_CONCATENATED
				GPTM_REAL_TIME_CLOCK
				GPTM_INDIVIDUAL
				
	5- countDirection
			Can be intialized to:
				COUNT_DOWN
				COUNT_UP

	6- frequencyHz
			Sytem clock frequency
	
	7- maxTick
			max number of ticks before an overflow event
*/
Gpt_OneShotOrPerodicCfgType appTimer = {.timerBlockId = APP_TIMER_BLOCK,
										.timerId = APP_TIMER_ID,
										.mode = APP_TIMER_MODE,
										.configuration = APP_TIMER_CONFIGURATION,
										.countDirection = APP_TIMER_DIRECTION,
										.frequencyHz = SYSTEM_CLOCK_FREQUENCY,
										.maxTick = APP_TIMER_START_VALUE,
};

/****************************************************************************
*  END OF FILE : Gpt_Lcfg.c
*****************************************************************************/
