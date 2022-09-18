/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpio_Private.h
 *       Module:  Private
 *
 *  Description:  Defining MCU registers utilized in Gpio_Program.c
 *  
 *********************************************************************************************************************/
 
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Common/Bit_Math.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*
 * Base addresses
 */
#define GPIO_PORT_A_APB_BASE_ADDRESS	0x40004000
#define GPIO_PORT_B_APB_BASE_ADDRESS	0x40005000
#define GPIO_PORT_C_APB_BASE_ADDRESS	0x40006000
#define GPIO_PORT_D_APB_BASE_ADDRESS	0x40007000
#define GPIO_PORT_E_APB_BASE_ADDRESS	0x40024000
#define GPIO_PORT_F_APB_BASE_ADDRESS	0x40025000
#define GPIO_PORT_A_AHB_BASE_ADDRESS	0x40058000
#define GPIO_PORT_B_AHB_BASE_ADDRESS	0x40059000
#define GPIO_PORT_C_AHB_BASE_ADDRESS	0x4005A000
#define GPIO_PORT_D_AHB_BASE_ADDRESS	0x4005B000
#define GPIO_PORT_E_AHB_BASE_ADDRESS	0x4005C000
#define GPIO_PORT_F_AHB_BASE_ADDRESS	0x4005D000
					
#define SYSCTL_BASE_ADDRESS				0x400FE000

/*
 * Offsets
 */
#define GPIO_DATA_OFFSET			0x3FC
#define GPIO_DIR_OFFSET				0x400
#define GPIO_IS_OFFSET				0x404
#define GPIO_IBE_OFFSET				0x408
#define GPIO_IEV_OFFSET				0x40C
#define GPIO_IM_OFFSET				0x410
#define GPIO_RIS_OFFSET				0x414
#define GPIO_MIS_OFFSET				0x418
#define GPIO_ICR_OFFSET				0x41C
#define GPIO_AFSEL_OFFSET			0x420
#define GPIO_DR2R_OFFSET			0x500
#define GPIO_DR4R_OFFSET			0x504
#define GPIO_DR8R_OFFSET			0x508
#define GPIO_ODR_OFFSET				0x50C
#define GPIO_PUR_OFFSET				0x510
#define GPIO_PDR_OFFSET				0x514
#define GPIO_SLR_OFFSET				0x518
#define GPIO_DEN_OFFSET				0x51C
#define GPIO_LOCK_OFFSET			0x520
#define GPIO_CR_OFFSET				0x524
#define GPIO_AMSEL_OFFSET			0x528
#define GPIO_PCTL_OFFSET			0x52C
#define GPIO_ADCCTL_OFFSET			0x530
#define GPIO_DMACTL_OFFSET			0x534
#define GPIO_PeriphID4_OFFSET		0xFD0
#define GPIO_PeriphID5_OFFSET		0xFD4
#define GPIO_PeriphID6_OFFSET		0xFD8
#define GPIO_PeriphID7_OFFSET		0xFDC
#define GPIO_PeriphID0_OFFSET		0xFE0
#define GPIO_PeriphID1_OFFSET		0xFE4
#define GPIO_PeriphID2_OFFSET		0xFE8
#define GPIO_PeriphID3_OFFSET		0xFEC
#define GPIO_PCellID0_OFFSET		0xFF0
#define GPIO_PCellID1_OFFSET		0xFF4
#define GPIO_PCellID2_OFFSET		0xFF8
#define GPIO_PCellID3_OFFSET		0xFFC
																			
#define SYSCTL_GPIOHBCTL_OFFSET		0x06C
#define SYSCTL_RCGCGPIO_OFFSET		0x608
			
#define GPIO_HIGH_PERFORMANCE_BUS_CONTROL		*( (volatile uint32_t *) (SYSCTL_BASE_ADDRESS + SYSCTL_GPIOHBCTL_OFFSET) )
#define GPIO_RUN_MODE_CLOCK_GATING				*( (volatile uint32_t *) (SYSCTL_BASE_ADDRESS + SYSCTL_RCGCGPIO_OFFSET) )	

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define GPIO_GET_REGISTER(base, offset)			*( (volatile uint32_t *) (base + offset) )

#define GPIO_GET_PORT_A_BASE_ADDRESS(bus)		bus == ENABLE_AHB ? GPIO_PORT_A_AHB_BASE_ADDRESS : GPIO_PORT_A_APB_BASE_ADDRESS
#define GPIO_GET_PORT_B_BASE_ADDRESS(bus)		bus == ENABLE_AHB ? GPIO_PORT_B_AHB_BASE_ADDRESS : GPIO_PORT_B_APB_BASE_ADDRESS
#define GPIO_GET_PORT_C_BASE_ADDRESS(bus)		bus == ENABLE_AHB ? GPIO_PORT_C_AHB_BASE_ADDRESS : GPIO_PORT_C_APB_BASE_ADDRESS
#define GPIO_GET_PORT_D_BASE_ADDRESS(bus)		bus == ENABLE_AHB ? GPIO_PORT_D_AHB_BASE_ADDRESS : GPIO_PORT_D_APB_BASE_ADDRESS
#define GPIO_GET_PORT_E_BASE_ADDRESS(bus)		bus == ENABLE_AHB ? GPIO_PORT_E_AHB_BASE_ADDRESS : GPIO_PORT_E_APB_BASE_ADDRESS
#define GPIO_GET_PORT_F_BASE_ADDRESS(bus)		bus == ENABLE_AHB ? GPIO_PORT_F_AHB_BASE_ADDRESS : GPIO_PORT_F_APB_BASE_ADDRESS

#endif  /* GPIO_PRIVATE_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpio_Private.h
 *********************************************************************************************************************/