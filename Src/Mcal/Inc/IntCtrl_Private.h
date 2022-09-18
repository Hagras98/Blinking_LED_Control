/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Private.h
 *       Module:  MCU Core Peripherals
 *
 *  Description:  Defining MCU registers utilized in IntCtrl_Program.c
 *  
 *********************************************************************************************************************/

#ifndef INTCTRL_PRIVATE_H
#define INTCTRL_PRIVATE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Common/Bit_Math.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define MCU_CORE_PERIPHERALS_BASE_ADDRESS		0xE000E000

/*
 * PERIPHERALS OFFSETS
 */
#define NVIC_EN_OFFSET					0x100
#define NVIC_DIS_OFFSET					0x180
#define NVIC_PEND_OFFSET				0x200
#define NVIC_UNPEND_OFFSET				0x280
#define NVIC_ACTIVE_OFFSET				0x300
#define NVIC_PRI_OFFSET					0x400
#define NVIC_SWTRIG_OFFSET				0xF00
#define SCB_INTCTRL_OFFSET				0xD04
#define SCB_APINT_OFFSET				0xD0C

/*
 * REGISTERS DEFINITIONS
 */
#define NVIC_SOFTWARE_TRIGGER_INTERRUPT_REGISTER		( (volatile Nvic_Software_Trigger_InterruptType *) (MCU_CORE_PERIPHERALS_BASE_ADDRESS + NVIC_SWTRIG_OFFSET) )
#define SCB_INTERRUPT_CONTROL_AND_STATE					( (volatile Scb_Interrupt_Control_And_StateType *) (MCU_CORE_PERIPHERALS_BASE_ADDRESS + SCB_INTCTRL_OFFSET) )
#define SCB_APPLICATION_INTERRUPT_AND_RESET_CONTROL		( (volatile Scb_Application_Interrupt_and_Reset_ControlType *) (MCU_CORE_PERIPHERALS_BASE_ADDRESS + SCB_APINT_OFFSET) )

//TODO: The rest of SCB registers definitions

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define NVIC_ENABLE_INTERRUPT_REGISTER(INTERRUPT_ID)	*( (volatile uint32_t *) ( MCU_CORE_PERIPHERALS_BASE_ADDRESS + NVIC_EN_OFFSET + ((INTERRUPT_ID / 32) * 4) ) )
#define NVIC_DISABLE_INTERRUPT_REGISTER(INTERRUPT_ID)	*( (volatile uint32_t *) ( MCU_CORE_PERIPHERALS_BASE_ADDRESS + NVIC_DIS_OFFSET + ((INTERRUPT_ID / 32) * 4) ) )
#define NVIC_PEND_INTERRUPT_REGISTER(INTERRUPT_ID)		*( (volatile uint32_t *) ( MCU_CORE_PERIPHERALS_BASE_ADDRESS + NVIC_PEND_OFFSET + ((INTERRUPT_ID / 32) * 4) ) )
#define NVIC_UNPEND_INTERRUPT_REGISTER(INTERRUPT_ID)	*( (volatile uint32_t *) ( MCU_CORE_PERIPHERALS_BASE_ADDRESS + NVIC_UNPEND_OFFSET 	+ 	((INTERRUPT_ID / 32) * 4) ) )
#define NVIC_ACTIVE_INTERRUPT_REGISTER(INTERRUPT_ID)	*( (volatile uint32_t *) ( MCU_CORE_PERIPHERALS_BASE_ADDRESS + NVIC_ACTIVE_OFFSET 	+ 	((INTERRUPT_ID / 32) * 4) ) )
#define INTERRUPT_PRIORITY_REGISTER(INTERRUPT_ID)			*( (volatile uint32_t *) ( MCU_CORE_PERIPHERALS_BASE_ADDRESS + NVIC_PRI_OFFSET 		+ 	((INTERRUPT_ID / 4) * 4) ) )
#define INTERRUPT_BIT(INTERRUPT_ID)										(INTERRUPT_ID % 32)
#define INTERRUPT_INDEX(INTERRUPT_ID)									(INTERRUPT_ID % 4)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*
 * NVIC
 */	
typedef struct{
	uint32_t reserved		:5;	
	uint32_t groupPriority	:3;
}Nvic_Single_Interrupt_priorityType;

typedef struct{
	uint32_t intd 			:8;
	uint32_t reserved		:24;
}Nvic_Software_Trigger_InterruptType;

/*
 * SCB
 */
typedef struct{
	uint32_t vecact 		:8;
	uint32_t reserved1		:3;
	uint32_t retbase		:1;
	uint32_t vecpend		:8;
	uint32_t reserved2		:2;
	uint32_t isrpend 		:1;
	uint32_t isrpre			:1;
	uint32_t reserved3		:1;
	uint32_t pendstclr		:1;
	uint32_t pendstset		:1;
	uint32_t unpendsv		:1;
	uint32_t pendsv			:1;
	uint32_t reserved4		:2;
	uint32_t nmiset			:1;
}Scb_Interrupt_Control_And_StateType;
	
typedef union{
	struct{
		uint32_t vectreset 	:1;		
		uint32_t vectclract	:1;
		uint32_t sysresreq	:1;
		uint32_t reserved1	:5;
		uint32_t prigroup	:3;
		uint32_t reserved2 	:4;
		uint32_t endianess	:1;
		uint32_t vectkey	:16;
	}b;
	uint32_t r;
}Scb_Application_Interrupt_and_Reset_ControlType;
	
#endif  /* INTCTRL_PRIVATE_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Private.h
 *********************************************************************************************************************/