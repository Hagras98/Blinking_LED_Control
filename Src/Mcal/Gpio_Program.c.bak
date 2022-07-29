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
#include "../Config/IntCtrl_Cfg.h"


/***************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*****************************************************************************/

/****************************************************************************
*  LOCAL DATA
*****************************************************************************/


/****************************************************************************
*  GLOBAL DATA
*****************************************************************************/

/****************************************************************************
*  FUNCTIONS
*****************************************************************************/


/****************************************************************************
* \Syntax : Std_ReturnType FunctionName(AnyType parameterName)
* \Description: Describe this service
*
* \Sync\Async:
* \Reentrancy:
* \Parameters (in):
* \Parameters (out):
* \Return Value:
*
******************************************************************************/
void Nvic_Set_Interrupt_Priority_Binary_Point(void){
	#if PRIORITY_BINARY_POINT > YYY
	#error invalid priority binary point 
	#endif
	uint32_t apit_Value  = (APIT_VECTOR_KEY << 16) | ((PRIORITY_BINARY_POINT+4) << 8); 
	SCB_APPLICATION_INTERRUPT_AND_RESET_CONTROL->r = apit_Value;
}

void Nvic_Enable_Interrupt(Nvic_Interrupts_Tag interrupt){
	SET_BIT(*NVIC_ENABLE_INTERRUPT_REGISTER(interrupt), INTERRUPT_BIT(interrupt));
}

void Nvic_Priority_Grouping(Nvic_Interrupt_Intialization_Tag* interrupt){
	uint8_t interrupt_Id = interrupt->interrupt_name;
	uint8_t prigroup = ((interrupt->group_Priority) << PRIORITY_BINARY_POINT) | interrupt->subgroup_Priority;
	INTERRUPT_PRIORITY_REGISTER(interrupt_Id)->single_Interrupt[INTERRUPT_INDEX(interrupt_Id)].group_Priority = prigroup;
}
/****************************************************************************
*  END OF FILE : FileName.c
*****************************************************************************/
