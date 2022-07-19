/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Intctrl_Interface.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
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

#define APIT_VECTOR_KEY	0x05FA

/*interrupt priority grouping binary point*/
#define XXX 0
#define XXY 1
#define XYY 2
#define YYY 3

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*INTERRUPTS ID*/
typedef enum{
	GPIOA = 0,	
	GPIOB,	
	GPIOC,	
	GPIOD,	
	GPIOE,	
	UART0,	
	UART1,	
	SSI0,	
	I2C0,	
	PMW0_FAULT,
	PWM0_0,
	PWM0_1,	
	PWM0_2,	
	QEI0,	
	ADC0SS0,
	ADC0SS1,
	ADC0SS2,
	ADC0SS3,
	WDT0,	
	TIMER0A,
	TIMER0B,	
	TIMER1A, 	
	TIMER1B,	
	TIMER2A,	
	TIMER2B,	
	COMP0,	
	COMP1,						
	SYSCTL = 28,		
	FLASH,		
	GPIOF,						
	UART2 = 33,
	SSI1,	
	TIMER3A,
	TIMER3B,
	I2C1,	
	QEI1,		
	CAN0,		
	CAN1,				
	HIB	= 43,	
	USB0,		
	PWM0_3,
	UDMA,	
	UDMAERR,
	ADC1SS0,
	ADC1SS1,
	ADC1SS2,	
	ADC1SS3,					
	SSI2 = 57,	
	SSI3,
	UART3,		
	UART4,		
	UART5,		
	UART6,		
	UART7,					
	I2C2 = 68,
	I2C3,
	TIMER4A,	
	TIMER4B,			
	TIMER5A	= 92,
	TIMER5B,
	WTIMER0A,	
	WTIMER0B,	
	WTIMER1A,	
	WTIMER1B,	
	WTIMER2A,	
	WTIMER2B,	
	WTIMER3A,	
	WTIMER3B,	
	WTIMER4A,	
	WTIMER4B,	
	WTIMER5A,	
	WTIMER5B,	
	FPU,				
	PMW1_0 = 134,
	PWM1_1,		
	PWM1_2,		
	PWM1_3,		
	PWM1_FAULT
}Nvic_Interrupts_Tag;


typedef struct{
	Nvic_Interrupts_Tag interrupt_name;
	uint8_t	group_Priority;
	uint8_t	subgroup_Priority;
}Nvic_Interrupt_Intialization_Tag;



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void Nvic_Set_Interrupt_Priority_Binary_Point(void);
void Nvic_Enable_Interrupt(Nvic_Interrupts_Tag interrupt);
void Nvic_Priority_Grouping(Nvic_Interrupt_Intialization_Tag* interrupt);
void Nvic_Trigger_Software_Interrupt(Nvic_Interrupts_Tag interrupt);


 
#endif  /* INTCTRL_INTERFACE_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/