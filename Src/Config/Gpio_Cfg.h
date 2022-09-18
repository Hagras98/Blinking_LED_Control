/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  GPIO_Cfg.h
 *       Module:  GPIO
 *
 *  Description:  Configurations for the GPIO peripheral    
 *  
 *********************************************************************************************************************/
#ifndef GPIO_CFG_H
#define GPIO_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Led_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*
	- Port clock enable 
	0: DISABLE
	1: ENABLE	
	
	Each GPIO module clock must be enabled before the registers can be programmed.
*/
	#define PORT_A_CLOCK	ENABLE
	#define PORT_B_CLOCK	DISABLE
	#define PORT_C_CLOCK	DISABLE
	#define PORT_D_CLOCK	DISABLE
	#define PORT_E_CLOCK	DISABLE
	#define PORT_F_CLOCK	ENABLE

/*
	- Port accessing bus 	
	0: ENABLE_APB
	1: ENABLE_AHB
	
	Each GPIO port can be accessed through one of two bus apertures. The legacy aperture, the Advanced Peripheral Bus 
	(APB),and the Advanced High-Performance Bus (AHB).		
*/
	#define PORT_A_BUS		ENABLE_APB
	#define PORT_B_BUS		ENABLE_AHB
	#define PORT_C_BUS		ENABLE_APB
	#define PORT_D_BUS		ENABLE_APB
	#define PORT_E_BUS		ENABLE_APB
	#define PORT_F_BUS		ENABLE_APB

/*
	Number of used GPIO pins in project
*/
	#define ENABLED_PINS	1

/*
	Using bit masking to manipulate GPIO_DATA
	0: DISABLE
	1: ENABLE	
*/
	#define GPIO_DATA_BIT_MASKING	DISABLE
	
 
#endif  /* GPIO_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpio_Cfg.h
 *********************************************************************************************************************/