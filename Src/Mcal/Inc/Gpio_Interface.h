/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpio_Interface.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Gpio_Private.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 
 #define ENABLE_APB									0
 #define ENABLE_AHB									1
 
 #define GPIO_PORT_A_BASE_ADDRESS		GPIO_GET_PORT_A_BASE_ADDRESS(PORT_A_BUS)
 #define GPIO_PORT_B_BASE_ADDRESS  	GPIO_GET_PORT_B_BASE_ADDRESS(PORT_B_BUS)
 #define GPIO_PORT_C_BASE_ADDRESS  	GPIO_GET_PORT_C_BASE_ADDRESS(PORT_C_BUS)
 #define GPIO_PORT_D_BASE_ADDRESS  	GPIO_GET_PORT_D_BASE_ADDRESS(PORT_D_BUS)
 #define GPIO_PORT_E_BASE_ADDRESS  	GPIO_GET_PORT_E_BASE_ADDRESS(PORT_E_BUS)
 #define GPIO_PORT_F_BASE_ADDRESS  	GPIO_GET_PORT_F_BASE_ADDRESS(PORT_F_BUS)
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
 
 
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

	typedef enum{
		GPIO_PIN_LOW = 0,
		GPIO_PIN_HIGH
	}Gpio_PinLevelType;
	
	typedef enum{
		GPIO_PORT_LOW = 0,
		GPIO_PORT_HIGH = 255
	}Gpio_PortLevelType;
	
	typedef enum{
		GPIO_INPUT = 0,
		GPIO_OUTPUT
	}Gpio_PinDirectionType;
	
	typedef enum{
		GPIO_PIN_0,
		GPIO_PIN_1,
		GPIO_PIN_2,
		GPIO_PIN_3,
		GPIO_PIN_4,
		GPIO_PIN_5,
		GPIO_PIN_6,
		GPIO_PIN_7
	}Gpio_PinType;
	
	
	typedef enum{
		GPIO_PORT_A,
		GPIO_PORT_B,
		GPIO_PORT_C,
		GPIO_PORT_D,
		GPIO_PORT_E,
		GPIO_PORT_F
	}Gpio_PortType;
	
	
	/*GPIO pin configurations typdefs*/
	
	typedef enum{
		GPIO_TRI_STATE = 0,
		GPIO_OPEN_DRAIN,
		GPIO_PULL_UP,
		GPIO_PULL_DOWN
	}Gpio_InternalConnectionType;
	
	typedef enum{
		GPIO_2_MA = 0,
		GPIO_4_MA,
		GPIO_8_MA
	}Gpio_DriveControlType;
	
	typedef enum{
		GPIO_DIGITAL = 0,
		GPIO_ANALOG
	}Gpio_FunctionType;
	
	typedef enum{
		GPIO_NONE_AF = 0,
		GPIO_AF_1,
		GPIO_AF_2,
		GPIO_AF_3,
		GPIO_AF_4,
		GPIO_AF_5,
		GPIO_AF_6,
		GPIO_AF_7,
		GPIO_AF_8,
		GPIO_AF_9,
		GPIO_AF_14 = 14,
		GPIO_AF_15,
		GPIO_ADC_TRIGGER,
		GPIO_UDMA_TRIGGER
	}Gpio_Alternate_functionsType;
	
	typedef struct{
		Gpio_PortType port;
		Gpio_PinType pin;
		Gpio_PinDirectionType direction;
		Gpio_Alternate_functionsType alternateFunction;
		Gpio_DriveControlType current;	
		Gpio_InternalConnectionType internalConnection;
		Gpio_FunctionType functionality;
	}Gpio_PinConfigurationsType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
	void Gpio_Init(Gpio_PinConfigurationsType** configurations);	
	void Gpio_WritePinLevel(Gpio_PortType port, uint32_t pin, Gpio_PinLevelType level);
	void Gpio_WritePortLevel(Gpio_PortType port, Gpio_PortLevelType level);
	Gpio_PinLevelType Gpio_ReadPinLevel(Gpio_PortType port, uint32_t pin);
	Gpio_PortLevelType Gpio_ReadPortLevel(Gpio_PortType port);
	void Gpio_TogglePinLevel(Gpio_PortType port, uint32_t pin);
	
 
#endif  /* GPIO_INTERFACE_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpio_Interface.h
 *********************************************************************************************************************/