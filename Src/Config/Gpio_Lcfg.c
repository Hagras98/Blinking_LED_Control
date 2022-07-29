/******************************************************************************
    FILE DESCRIPTION
*------------------------------------------------------------------------------
*     /file  Gpio_Lcfg.c  
*     /brief
*
*     /details
*
*****************************************************************************/

/****************************************************************************
*  INCLUDES
*****************************************************************************/
#include "../Mcal/Inc/Gpio_interface.h"
#include "Gpio_Cfg.h"
/***************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*****************************************************************************/

/****************************************************************************
*  LOCAL DATA
*****************************************************************************/


/****************************************************************************
*  GLOBAL DATA
*****************************************************************************/


/*Intialize struct of type Gpio_PinConfigurationsType for every initialized pin.
Struct elements are:
	1- port 
			Can be intialized to:
				GPIO_PORT_A
				GPIO_PORT_B
				GPIO_PORT_C
				GPIO_PORT_D
				GPIO_PORT_E
				GPIO_PORT_F
	
	2-pin	
			Can be intialized to:
				GPIO_PIN_0
				GPIO_PIN_1
				GPIO_PIN_2
				GPIO_PIN_3
				GPIO_PIN_4
				GPIO_PIN_5
				GPIO_PIN_6
				GPIO_PIN_7
			
	3- direction
			Can be intialized to:
				GPIO_INPUT
				GPIO_OUTPUT	
			
	4- alternateFunction
			Can be intialized to:
				GPIO_NONE_AF
				GPIO_AF_1
				GPIO_AF_2
				GPIO_AF_3
				GPIO_AF_4
				GPIO_AF_5
				GPIO_AF_6
				GPIO_AF_7
				GPIO_AF_8
				GPIO_AF_9
				GPIO_AF_14
				GPIO_AF_15
				GPIO_ADC_TRIGGER
				GPIO_UDMA_TRIGGER
	
	5- current
			Can be intialized to:
				GPIO_2_MA
				GPIO_4_MA
				GPIO_8_MA
	
	6- internalConnection
			Can be intialized to:
				GPIO_TRI_STATE
				GPIO_OPEN_DRAIN
				GPIO_PULL_UP
				GPIO_PULL_DOWN
		
	7- functionality
			Can be intialized to:
				GPIO_DIGITAL
				GPIO_ANALOG

*/
Gpio_PinConfigurationsType pinA1 = {.port = APP_LED_PORT, .pin = APP_LED_PIN, 
																		.direction = GPIO_OUTPUT,
																		.alternateFunction = GPIO_NONE_AF,
																		.current = GPIO_2_MA, 
																		.internalConnection = GPIO_TRI_STATE, 
																		.functionality = GPIO_DIGITAL};
																		
	/*Array elemetns are pointers to previously initialized Gpio_PinConfigurationsType
	structs*/
const Gpio_PinConfigurationsType* Gpio_pinsConfigurations[ENABLED_PINS] = {&pinA1};

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


/****************************************************************************
*  END OF FILE : Gpio_Lcfg.c
*****************************************************************************/
