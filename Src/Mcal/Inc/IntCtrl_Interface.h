/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Intctrl_Interface.h
 *       Module:  Interrupt Control
 *
 *  Description:  Header file for IntCtrl_Program.c file
 *  
 *********************************************************************************************************************/

#ifndef INTCTRL_INTERFACE_H
#define INTCTRL_INTERFACE_H
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl_Private.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*interrupt priority grouping binary point*/
#define XXX 0
#define XXY 1
#define XYY 2
#define YYY 3

#define APIT_VECTOR_KEY	0x05FA

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*INTERRUPTS ID*/
typedef enum{
	NVIC_GPIOA = 0,	
	NVIC_GPIOB,	
	NVIC_GPIOC,	
	NVIC_GPIOD,	
	NVIC_GPIOE,	
	NVIC_UART0,	
	NVIC_UART1,	
	NVIC_SSI0,	
	NVIC_I2C0,	
	NVIC_PMW0_FAULT,
	NVIC_PWM0_0,
	NVIC_PWM0_1,	
	NVIC_PWM0_2,	
	NVIC_QEI0,	
	NVIC_ADC0SS0,
	NVIC_ADC0SS1,
	NVIC_ADC0SS2,
	NVIC_ADC0SS3,
	NVIC_WDT0,	
	NVIC_TIMER0A,
	NVIC_TIMER0B,	
	NVIC_TIMER1A, 	
	NVIC_TIMER1B,	
	NVIC_TIMER2A,	
	NVIC_TIMER2B,	
	NVIC_COMP0,	
	NVIC_COMP1,						
	NVIC_SYSCTL = 28,		
	NVIC_FLASH,		
	NVIC_GPIOF,						
	NVIC_UART2 = 33,
	NVIC_SSI1,	
	NVIC_TIMER3A,
	NVIC_TIMER3B,
	NVIC_I2C1,	
	NVIC_QEI1,		
	NVIC_CAN0,		
	NVIC_CAN1,				
	NVIC_HIB	= 43,	
	NVIC_USB0,		
	NVIC_PWM0_3,
	NVIC_UDMA,	
	NVIC_UDMAERR,
	NVIC_ADC1SS0,
	NVIC_ADC1SS1,
	NVIC_ADC1SS2,	
	NVIC_ADC1SS3,					
	NVIC_SSI2 = 57,	
	NVIC_SSI3,
	NVIC_UART3,		
	NVIC_UART4,		
	NVIC_UART5,		
	NVIC_UART6,		
	NVIC_UART7,					
	NVIC_I2C2 = 68,
	NVIC_I2C3,
	NVIC_TIMER4A,	
	NVIC_TIMER4B,			
	NVIC_TIMER5A	= 92,
	NVIC_TIMER5B,
	NVIC_WTIMER0A,	
	NVIC_WTIMER0B,	
	NVIC_WTIMER1A,	
	NVIC_WTIMER1B,	
	NVIC_WTIMER2A,	
	NVIC_WTIMER2B,	
	NVIC_WTIMER3A,	
	NVIC_WTIMER3B,	
	NVIC_WTIMER4A,	
	NVIC_WTIMER4B,	
	NVIC_WTIMER5A,	
	NVIC_WTIMER5B,	
	NVIC_FPU,				
	NVIC_PMW1_0 = 134,
	NVIC_PWM1_1,		
	NVIC_PWM1_2,		
	NVIC_PWM1_3,		
	NVIC_PWM1_FAULT
}Nvic_InterruptsType;

typedef struct{
	Nvic_InterruptsType interruptId;
	uint8_t	groupPriority;
	uint8_t	subgroupPriority;
	uint8_t	interruptEnable;
}Nvic_Interrupt_IntializationType;

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Nvic_init(Nvic_Interrupt_IntializationType** interruptConfigurations);
void Nvic_Enable_Interrupt(Nvic_InterruptsType interrupt);
 
#endif  /* INTCTRL_INTERFACE_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/