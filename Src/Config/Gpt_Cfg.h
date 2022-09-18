/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt_Cfg.h
 *       Module:  Gpt
 *
 *  Description:  Configurations for the general timer peripgheral    
 *  
 *********************************************************************************************************************/
#ifndef GPT_CFG_H
#define GPT_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../Config/App_BlinkLedCfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*
	Number of used timer modules in project
*/
	#define ENABLED_TIMERS	1

/*
	System clock frequency
*/
	#define SYSTEM_CLOCK_FREQUENCY 50000000UL

/*
	- Port clock enable 
	0: DISABLE
	1: ENABLE	
	
	Each GPT module clock must be enabled before the registers can be programmed.
*/
	#define TIMER_0_CLOCK						ENABLE
	#define TIMER_1_CLOCK						DISABLE
	#define TIMER_2_CLOCK						DISABLE
	#define TIMER_3_CLOCK						DISABLE
	#define TIMER_4_CLOCK						DISABLE
	#define TIMER_5_CLOCK						DISABLE
	#define WIDE_TIMER_0_CLOCK					DISABLE
	#define WIDE_TIMER_1_CLOCK					DISABLE
	#define WIDE_TIMER_2_CLOCK					DISABLE
	#define WIDE_TIMER_3_CLOCK					DISABLE
	#define WIDE_TIMER_4_CLOCK					DISABLE
	#define WIDE_TIMER_5_CLOCK					DISABLE
	
	/*
	 * Callback function for timer0 A interrupt
	 */
	#define	TIMER_0_A_CB 						APP_FN_PTR
 
#endif  /* GPT_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpt_Cfg.h
 *********************************************************************************************************************/