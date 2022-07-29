/******************************************************************************
    FILE DESCRIPTION
*------------------------------------------------------------------------------
*     /file  main.c  
*     /brief	
*
*     /details
*
*****************************************************************************/

/****************************************************************************
*  INCLUDES
*****************************************************************************/
#include "Inc/App_BlinkLed.h"
#include "../Config/Gpio_Cfg.h"
#include "../Config/Gpt_Cfg.h"
#include "../Config/IntCtrl_Cfg.h"

/****************************************************************************
*  GLOBAL DATA
*****************************************************************************/
extern Nvic_Interrupt_IntializationType* enabledInterrupts[];
extern Gpio_PinConfigurationsType* Gpio_pinsConfigurations [];
extern Gpt_OneShotOrPerodicCfgType* Gptm_timersConfigurations [];
extern Led_CfgType ledCfg;

/****************************************************************************
*  FUNCTIONS
*****************************************************************************/
int main(){
	Gptm_Init(Gptm_timersConfigurations);
	Enable_Notification(APP_TIMER_BLOCK, APP_TIMER_ID);
	Nvic_init(enabledInterrupts);
	Gpio_Init(Gpio_pinsConfigurations);
	if(ledCfg.initState == LED_OFF){
		Led_Off(&ledCfg);
	}
	else if(ledCfg.initState == LED_ON){
		Led_On(&ledCfg);
	}
	
	//Timer starts counting
	Timer_Start(GPTM_TIMER_0_ID, GPTM_TIMER_A);
	
	while(1){
		//Super loop
	}
	return 0;
}

/****************************************************************************
*  END OF FILE : main.c
*****************************************************************************/
