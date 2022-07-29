/******************************************************************************
    FILE DESCRIPTION
*------------------------------------------------------------------------------
*     /file  App_BlinkLed.c  
*     /brief
*
*     /details
*
*****************************************************************************/

/****************************************************************************
*  INCLUDES
*****************************************************************************/
#include "Inc/App_BlinkLed.h"
#include "../Config/Gpt_Cfg.h"
#include "../Config/Gpio_Cfg.h"
#include "../Config/IntCtrl_Cfg.h"

/****************************************************************************
*  GLOBAL DATA
*****************************************************************************/
extern Gpt_OneShotOrPerodicCfgType appTimer;
extern Led_CfgType ledCfg;

/****************************************************************************
*  FUNCTIONS
*****************************************************************************/
void blinkLED(void){
	Timer_Stop(appTimer.timerBlockId, appTimer.timerId);
	//Using the system clock frequency to avoid using prescalar
	//Prescalars are not available in concatenated timer modes
	uint32_t frequency = SYSTEM_CLOCK_FREQUENCY;
	uint32_t onMaxTick = frequency * APP_TIMER_ON_DURATION;
	uint32_t offMaxTick = frequency * APP_TIMER_OFF_DURATION;
	static Led_StateType state = APP__LED_INIT_STATE;
	if (state == LED_OFF){
		appTimer.maxTick = onMaxTick;
		Gptm_Modify(&appTimer);
		state = LED_ON;
	}
	else if (state == LED_ON){
		appTimer.maxTick = offMaxTick;
		Gptm_Modify(&appTimer);
		state = LED_OFF;
	}
	Led_Toggle(&ledCfg);
	Timer_Start(appTimer.timerBlockId, appTimer.timerId);
}

/****************************************************************************
*  END OF FILE : App_BlinkLed.c
*****************************************************************************/
