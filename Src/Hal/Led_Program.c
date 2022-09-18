/******************************************************************************
    FILE DESCRIPTION
*------------------------------------------------------------------------------
*     /file  Led_program.c  
*     /brief
*
*     /details
*
*****************************************************************************/

/****************************************************************************
*  INCLUDES
*****************************************************************************/
#include "../Inc/Led_Interface.h"

/****************************************************************************
*  FUNCTIONS
*****************************************************************************/
void Led_Init(Led_CfgType *ledCfg)
{
	if(ledCfg.initState == LED_OFF)
	{
		Led_Off(&ledCfg);
	}
	
	else if(ledCfg.initState == LED_ON)
	{
		Led_On(&ledCfg);
	}
}

void Led_On(Led_CfgType *ledCfg)
{
	Gpio_WritePinLevel(ledCfg->ledPort, ledCfg->ledPin, GPIO_PIN_HIGH);
}

void Led_Off(Led_CfgType *ledCfg)
{
	Gpio_WritePinLevel(ledCfg->ledPort, ledCfg->ledPin, GPIO_PIN_LOW);
}
void Led_Toggle(Led_CfgType *ledCfg)
{
	Gpio_TogglePinLevel(ledCfg->ledPort, ledCfg->ledPin);
}

/****************************************************************************
*  END OF FILE : Led_Program.c
*****************************************************************************/
