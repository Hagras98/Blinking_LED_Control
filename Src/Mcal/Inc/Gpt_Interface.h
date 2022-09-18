/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt_Interface.h
 *       Module:  General purpose timer
 *
 *  Description:  Header file for GPT_Program.c file
 *  
 *********************************************************************************************************************/
#ifndef GPT_INTERFACE_H
#define GPT_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Gpt_Private.h"
 
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum{
	GPTM_TIMER_0_ID,
	GPTM_TIMER_1_ID,
	GPTM_TIMER_2_ID,
	GPTM_TIMER_3_ID,
	GPTM_TIMER_4_ID,
	GPTM_TIMER_5_ID,
	GPTM_WIDE_TIMER_0_ID,
	GPTM_WIDE_TIMER_1_ID,
	GPTM_WIDE_TIMER_2_ID,
	GPTM_WIDE_TIMER_3_ID,
	GPTM_WIDE_TIMER_4_ID,
	GPTM_WIDE_TIMER_5_ID
}Gptm_TimerBlockIdType;

typedef enum{
	GPTM_TIMER_A,
	GPTM_TIMER_B
}Gptm_TimerIdType;

typedef enum{
	GPTM_CONCATENATED = 0,
	GPTM_REAL_TIME_CLOCK,
	GPTM_INDIVIDUAL = 4
}Gptm_TimerConfigurationType;

typedef enum{
	ONE_SHOT = 1,
	PERIODIC
}Gptm_TimerModeType;

typedef enum{
	SNAP_SHOT_DISABLED = 0,
	SNAP_SHOT_ENABLED
}Gptm_SnapShotModeType;

typedef enum{
	BEGIN_COUNTING_ON_ENABLE = 0,
	WAIT_FOR_TRIGGER
}Gptm_WaitOnTriggerModeType;

typedef enum{
	MATCH_INTERRUPT_DISABLED = 0,
	MATCH_INTERRUPT_ENABLED
}Gptm_MatchInterruptStateType;

typedef enum{
	COUNT_DOWN = 0,
	COUNT_UP
}Gptm_CountDirectionType;

typedef struct{
	Gptm_TimerBlockIdType timerBlockId;
	Gptm_TimerIdType timerId;
	Gptm_TimerConfigurationType configuration;
	Gptm_TimerModeType mode;
	Gptm_SnapShotModeType snapShot;
	Gptm_WaitOnTriggerModeType trigger;
	Gptm_MatchInterruptStateType matchInterrupt;
	Gptm_CountDirectionType countDirection;
	uint32_t frequencyHz;
	uint32_t maxTick;
}Gpt_OneShotOrPerodicCfgType;

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Gptm_Init(Gpt_OneShotOrPerodicCfgType* configurations[]);
void Enable_Notification(Gptm_TimerBlockIdType timerBlockId, Gptm_TimerIdType timerId);
void Disable_Notification(Gptm_TimerBlockIdType timerBlockId, Gptm_TimerIdType timerId);
void Gptm_Modify(Gpt_OneShotOrPerodicCfgType* configurations);
void Timer_Stop(Gptm_TimerBlockIdType timerBlockId, Gptm_TimerIdType timerId);
void Timer_Start(Gptm_TimerBlockIdType timerBlockId, Gptm_TimerIdType timerId);	
 
#endif  /* GPT_INTERFACE_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpt_Interface.h
 *********************************************************************************************************************/