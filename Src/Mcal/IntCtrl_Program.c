/******************************************************************************
    FILE DESCRIPTION
*------------------------------------------------------------------------------
*     /file  IntCtrl_Program.c  
*     /brief
*
*     /details
*
*****************************************************************************/

/****************************************************************************
*  INCLUDES
*****************************************************************************/
#include "../Mcal/Inc/Intctrl_Interface.h"
#include "../Config/IntCtrl_Cfg.h"

/****************************************************************************
*  FUNCTIONS
*****************************************************************************/
void Nvic_init(Nvic_Interrupt_IntializationType** interruptConfigurations){
	#if PRIORITY_BINARY_POINT > YYY
	#error invalid priority binary point 
	#endif
	uint32_t apitValue  = (APIT_VECTOR_KEY << 16) | ((PRIORITY_BINARY_POINT+4) << 8); 
	SCB_APPLICATION_INTERRUPT_AND_RESET_CONTROL->r = apitValue;
	uint16_t i;
	for(i = 0; i < NUMBER_OF_ENABLED_INTERRUPTS; i++){
		uint8_t interruptId = interruptConfigurations[i]->interruptId;
		uint32_t priGroup = ((interruptConfigurations[i]->groupPriority) << PRIORITY_BINARY_POINT) | interruptConfigurations[i]->subgroupPriority;
		INTERRUPT_PRIORITY_REGISTER(interruptId) = priGroup << ( ( (interruptId % 4) * 8) + 5);
		WRITE_BIT(NVIC_ENABLE_INTERRUPT_REGISTER(interruptId), INTERRUPT_BIT(interruptId), interruptConfigurations[i]->interruptEnable);
	}	
}

void Nvic_Enable_Interrupt(Nvic_InterruptsType interrupt){
	SET_BIT(NVIC_ENABLE_INTERRUPT_REGISTER(interrupt), INTERRUPT_BIT(interrupt));
}

/****************************************************************************
*  END OF FILE : IntCtrl_Program.c
*****************************************************************************/
