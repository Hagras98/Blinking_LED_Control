/******************************************************************************
    FILE DESCRIPTION
*------------------------------------------------------------------------------
*     /file  Gpt_program.c  
*     /brief
*
*     /details
*
*****************************************************************************/

/****************************************************************************
*  INCLUDES
*****************************************************************************/
#include "Inc/Gpt_Interface.h"
#include "../Config/Gpt_Cfg.h"

/****************************************************************************
*  GLOBAL DATA
*****************************************************************************/
 static const uint32_t Gptm_baseAddress[] = {
											GPT_TIMER_0_BASE_ADDRESS,
                                            GPT_TIMER_1_BASE_ADDRESS,
											GPT_TIMER_2_BASE_ADDRESS,
											GPT_TIMER_3_BASE_ADDRESS,
											GPT_TIMER_4_BASE_ADDRESS,
											GPT_TIMER_5_BASE_ADDRESS,
											GPT_WIDE_TIMER_0_BASE_ADDRESS,
											GPT_WIDE_TIMER_1_BASE_ADDRESS,
											GPT_WIDE_TIMER_2_BASE_ADDRESS,
											GPT_WIDE_TIMER_3_BASE_ADDRESS,
											GPT_WIDE_TIMER_4_BASE_ADDRESS,
											GPT_WIDE_TIMER_5_BASE_ADDRESS
											};

/****************************************************************************
*  FUNCTIONS
*****************************************************************************/
void Gptm_Init(Gpt_OneShotOrPerodicCfgType* configurations[]){
	//Enable clock to 16/32 bit timers
	uint32_t rcgctimerValue = (
								TIMER_0_CLOCK << GPTM_TIMER_0_ID |
								TIMER_1_CLOCK << GPTM_TIMER_1_ID | 
								TIMER_2_CLOCK << GPTM_TIMER_2_ID |
								TIMER_3_CLOCK << GPTM_TIMER_3_ID |
								TIMER_4_CLOCK << GPTM_TIMER_4_ID | 
								TIMER_5_CLOCK << GPTM_TIMER_5_ID
								);
	
	WRITE_HW_REG(TIMER_RUN_MODE_CLOCK_GATING, rcgctimerValue);
	
	//Enable clock to 32/64 bit timers
	uint32_t rcgcwtimerValue = (
								WIDE_TIMER_0_CLOCK << GPTM_WIDE_TIMER_0_ID |
								WIDE_TIMER_1_CLOCK << GPTM_WIDE_TIMER_1_ID | 
								WIDE_TIMER_2_CLOCK << GPTM_WIDE_TIMER_2_ID |
								WIDE_TIMER_3_CLOCK << GPTM_WIDE_TIMER_3_ID |
								WIDE_TIMER_4_CLOCK << GPTM_WIDE_TIMER_4_ID | 
								WIDE_TIMER_5_CLOCK << GPTM_WIDE_TIMER_5_ID
								);
															
	WRITE_HW_REG(WIDE_TIMER_RUN_MODE_CLOCK_GATING, rcgctimerValue);
	
	uint32_t baseAddress;	
	uint8_t i;
	
	//Intializng and configuring timers
	for (i = 0; i < ENABLED_TIMERS; i++ )
	{
		baseAddress = Gptm_baseAddress[configurations[i] -> timerBlockId];
		GPTMCFG(baseAddress)->GPTMCFG = configurations[i]->configuration;
	
		if(configurations[i]->configuration == GPTM_INDIVIDUAL)
		{
			baseAddress = Gptm_baseAddress[configurations[i] -> timerBlockId] + (4 * configurations[i] -> timerBlockId);
		}
		
		GPTMTAMR(baseAddress)->TnMR = configurations[i]->mode;
		GPTMTAMR(baseAddress)->TnCDIR = configurations[i]->countDirection;
		GPTMTAMR(baseAddress)->TnSNAPS = configurations[i]->snapShot;
		GPTMTAMR(baseAddress)->TnWOT = configurations[i]->trigger;
		GPTMTAMR(baseAddress)->TnMIE = configurations[i]->matchInterrupt;
		
		uint32_t maxPossibleTick = configurations[i] -> timerBlockId > GPTM_TIMER_5_ID? 0xFFFFFFFF: 0xFFFF;
		uint8_t registerSize = configurations[i] -> timerBlockId > GPTM_TIMER_5_ID? 32: 16;
		uint32_t maxPossiblePrescalar = configurations[i] -> timerBlockId > GPTM_TIMER_5_ID? 0xFFFF: 0xFF;
		uint8_t prescalarSizeBits = 0;		
			
		if(configurations[i]->configuration == GPTM_INDIVIDUAL)
		{
			//calculating prescalar
			uint32_t approxPrescalar = 1;
			uint32_t prescalarValue = SYSTEM_CLOCK_FREQUENCY / (configurations[i]->frequencyHz);
			
			while(prescalarValue / approxPrescalar > 1)
			{
				approxPrescalar *= 2;
				prescalarSizeBits++;
			}
			
			if(prescalarValue % approxPrescalar <= (approxPrescalar / 2))
			{
					prescalarValue = approxPrescalar;
			}
			
			else
			{
				prescalarValue = approxPrescalar*2;
				prescalarSizeBits++;
			}		
			
			//Writing prescalar bits
			GPTMTAPR(baseAddress) = (configurations[i]->maxTick >> (registerSize - prescalarSizeBits)) & maxPossiblePrescalar;
		}
		
		//Setting interval load value
		GPTMTAILR(baseAddress) = (configurations[i]->maxTick << prescalarSizeBits);
	}
}

void Enable_Notification(Gptm_TimerBlockIdType timerBlockId, Gptm_TimerIdType timerId){
	uint32_t baseAddress = Gptm_baseAddress[timerBlockId];
	if(timerId == GPTM_TIMER_A)
	{
		GPTMIMR(baseAddress)->TATO = ENABLE;
	}	
	
	else if (timerId == GPTM_TIMER_A)
	{
		GPTMIMR(baseAddress)->TBTO = ENABLE;
	}
}

void Disable_Notification(Gptm_TimerBlockIdType timerBlockId, Gptm_TimerIdType timerId)
{
	uint32_t baseAddress = Gptm_baseAddress[timerBlockId];

	if(timerId == GPTM_TIMER_A)
	{
		GPTMIMR(baseAddress)->TATO = DISABLE;
	}	
	
	else if (timerId == GPTM_TIMER_A)
	{
		GPTMIMR(baseAddress)->TBTO = DISABLE;
	}
}

void Timer_Start(Gptm_TimerBlockIdType timerBlockId, Gptm_TimerIdType timerId)
{
	uint32_t baseAddress = Gptm_baseAddress[timerBlockId];

	if(timerId == GPTM_TIMER_A)
	{
		GPTMCTL(baseAddress)->TAEN = ENABLE;
	}	
	
	else if (timerId == GPTM_TIMER_A)
	{
		GPTMCTL(baseAddress)->TBEN = ENABLE;
	}
}

void Timer_Stop(Gptm_TimerBlockIdType timerBlockId, Gptm_TimerIdType timerId)
{
	uint32_t baseAddress = Gptm_baseAddress[timerBlockId];

	if(timerId == GPTM_TIMER_A)
	{
		GPTMCTL(baseAddress)->TAEN = DISABLE;
	}	

	else if (timerId == GPTM_TIMER_A)
	{
		GPTMCTL(baseAddress)->TBEN = DISABLE;
	}
}

void Gptm_Modify(Gpt_OneShotOrPerodicCfgType* configurations)
{
	uint32_t baseAddress = Gptm_baseAddress[configurations -> timerBlockId];

	if(configurations->configuration == GPTM_INDIVIDUAL)
	{
		baseAddress = Gptm_baseAddress[configurations -> timerBlockId] + (4 * configurations -> timerBlockId);
	}
	
	uint32_t maxPossibleTick = configurations -> timerBlockId > GPTM_TIMER_5_ID? 0xFFFFFFFF: 0xFFFF;
	uint8_t registerSize = configurations -> timerBlockId > GPTM_TIMER_5_ID? 32: 16;
	uint32_t maxPossiblePrescalar = configurations -> timerBlockId > GPTM_TIMER_5_ID? 0xFFFF: 0xFF;
	uint8_t prescalarSizeBits = 0;		
		
	if(configurations->configuration == GPTM_INDIVIDUAL)
	{
		//calculating prescalar
		uint32_t approxPrescalar = 1;
		uint32_t prescalarValue = SYSTEM_CLOCK_FREQUENCY / (configurations->frequencyHz);	
		
		while(prescalarValue / approxPrescalar > 1)
		{
			approxPrescalar *= 2;
			prescalarSizeBits++;
		}
		
		if(prescalarValue % approxPrescalar <= (approxPrescalar / 2))
		{
				prescalarValue = approxPrescalar;
		}
		
		else
		{
			prescalarValue = approxPrescalar*2;
			prescalarSizeBits++;
		}		
		
		//Writing prescalar bits
		GPTMTAPR(baseAddress) = (configurations->maxTick >> (registerSize - prescalarSizeBits)) & maxPossiblePrescalar;
	}
	
	//Setting interval load value
	GPTMTAILR(baseAddress) = (configurations->maxTick << prescalarSizeBits);
}

void TIMER0A_Handler ()
{
	GPTMICR(GPT_TIMER_0_BASE_ADDRESS)->TATO = ENABLE;
	(*TIMER_0_A_CB)();
}

/****************************************************************************
*  END OF FILE : Gpt_Program.c
*****************************************************************************/
