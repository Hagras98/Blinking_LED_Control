/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  App_BlinkLedCfg.h
 *       Module:  Application
 *
 *  Description:  Configurations for the blink led project
 *  
 *********************************************************************************************************************/
#ifndef APP_BLINK_LED_CFG_H
#define APP_BLINK_LED_CFG_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*
 *	LED ON and OFF time in seconds
 */
	#define APP_TIMER_ON_DURATION		1UL
	#define APP_TIMER_OFF_DURATION		1UL

/*
 *	System clock frequency
 */
	#define SYSTEM_CLOCK_FREQUENCY 50000000UL

/*
 *	Configurations for timer module. 
 *	Refer to Gpt_Lcfg.c for valid values
 */
	#define APP_TIMER_BLOCK				GPTM_TIMER_0_ID
	#define APP_TIMER_ID				GPTM_TIMER_A
	#define	APP_INTERRUPT_HANDLER		NVIC_TIMER0A
	#define	APP_TIMER_CONFIGURATION		GPTM_CONCATENATED
	#define APP_TIMER_MODE				PERIODIC
	#define APP_TIMER_START_VALUE		(uint32_t)APP_TIMER_OFF_DURATION * SYSTEM_CLOCK_FREQUENCY
	#define APP_TIMER_DIRECTION			COUNT_DOWN

/*
 *	Configurations for LED.
 *	Refer to Led_Lcfg.c and Gpio_Lcfg.c for valid values
 */
	#define	APP_LED_INIT_STATE			LED_OFF
	#define APP_LED_PORT				GPIO_PORT_F
	#define APP_LED_PIN					GPIO_PIN_1

/*
 *	Prototype of callback function passed to MCAL layer
 */
	#define	APP_FN_PTR					blinkLED

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void blinkLED(void);
	
 #endif /*APP_BLINK_LED_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: App_BlinkLedCfg.h
 *********************************************************************************************************************/
 