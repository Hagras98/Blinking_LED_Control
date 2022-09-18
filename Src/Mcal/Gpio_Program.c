/******************************************************************************
    FILE DESCRIPTION
*------------------------------------------------------------------------------
*     /file  Gpio_Program.c  
*     /brief
*
*     /details
*
*****************************************************************************/

/****************************************************************************
*  INCLUDES
*****************************************************************************/
#include "Inc/Gpio_Interface.h"
#include "../Config/Gpio_Cfg.h"

/****************************************************************************
*  GLOBAL DATA
*****************************************************************************/
 static const uint32_t Gpio_baseAddress[] = {
											GPIO_PORT_A_BASE_ADDRESS, 
											GPIO_PORT_B_BASE_ADDRESS,
											GPIO_PORT_C_BASE_ADDRESS,
											GPIO_PORT_D_BASE_ADDRESS,
											GPIO_PORT_E_BASE_ADDRESS,
											GPIO_PORT_F_BASE_ADDRESS
											};
 
/****************************************************************************
*  FUNCTIONS
*****************************************************************************/

void Gpio_Init(Gpio_PinConfigurationsType** configurations){
	//Enable clock to peripheral
	uint32_t rcgcgpioValue = (
							PORT_A_CLOCK << GPIO_PORT_A |
							PORT_B_CLOCK << GPIO_PORT_B | 
							PORT_C_CLOCK << GPIO_PORT_C |
							PORT_D_CLOCK << GPIO_PORT_D |
							PORT_E_CLOCK << GPIO_PORT_E | 
							PORT_F_CLOCK << GPIO_PORT_F
							);
	
	WRITE_HW_REG(GPIO_RUN_MODE_CLOCK_GATING, rcgcgpioValue);
	
	//Control which internal bus is used to access each GPIO port
	uint32_t gpiohbctlValue = (
								PORT_A_BUS << GPIO_PORT_A |
								PORT_B_BUS << GPIO_PORT_B |
								PORT_C_BUS << GPIO_PORT_C |
								PORT_D_BUS << GPIO_PORT_D |
								PORT_E_BUS << GPIO_PORT_E |
								PORT_F_BUS << GPIO_PORT_F
								);
	
	WRITE_HW_REG(GPIO_HIGH_PERFORMANCE_BUS_CONTROL, gpiohbctlValue);
	
	Gpio_PortType port;
	Gpio_PinType pin;
	uint32_t base;	
	uint8_t i = 0;
	
	for (i = 0; i < ENABLED_PINS; i++ ){
		port = configurations[i]->port;
		pin = configurations[i]->pin;
		base = Gpio_baseAddress[port];
		
		//setting pin direction
		WRITE_BIT(GPIO_GET_REGISTER(base, GPIO_DIR_OFFSET), pin, configurations[i]->direction);
		
		WRITE_HW_REG(GPIO_GET_REGISTER(base, GPIO_LOCK_OFFSET), 0x4C4F434B);
		WRITE_HW_REG(GPIO_GET_REGISTER(base, GPIO_CR_OFFSET), 0X1F);
		
		//setting alternating function
		if (configurations[i]->alternateFunction == GPIO_NONE_AF){
			CLR_BIT(GPIO_GET_REGISTER(base, GPIO_AFSEL_OFFSET), pin);
		}
		else if (configurations[i]->alternateFunction == GPIO_ADC_TRIGGER){
			CLR_BIT(GPIO_GET_REGISTER(base, GPIO_AFSEL_OFFSET), pin);
			SET_BIT(GPIO_GET_REGISTER(base, GPIO_ADCCTL_OFFSET), pin);
		}
		else if (configurations[i]->alternateFunction ==  GPIO_UDMA_TRIGGER){
			CLR_BIT(GPIO_GET_REGISTER(base, GPIO_AFSEL_OFFSET), pin);
			SET_BIT(GPIO_GET_REGISTER(base, GPIO_DMACTL_OFFSET), pin);
		}
		else{
				SET_BIT(GPIO_GET_REGISTER(base, GPIO_AFSEL_OFFSET), pin);
				SET_GROUP(GPIO_GET_REGISTER(base, GPIO_PCTL_OFFSET), (configurations[i]->alternateFunction << (pin * 4)) );
		}
		
		//driving current
		SET_BIT(GPIO_GET_REGISTER(base, (GPIO_DR2R_OFFSET + (configurations[i]->current * 4))), pin);	
		
		
		//pin internal connection (tri-state, pull up, pull down, or open drain)
		if(configurations[i]->internalConnection != GPIO_TRI_STATE){
			SET_BIT(GPIO_GET_REGISTER(base, (GPIO_ODR_OFFSET + ((configurations[i]->internalConnection - 1) * 4) )), pin);		
		}
		
		//pin mode to either analog or digital
		SET_BIT(GPIO_GET_REGISTER(base, (GPIO_DEN_OFFSET + (configurations[i]->functionality * 12) )), pin);
	}
}	

void Gpio_WritePinLevel(Gpio_PortType port, uint32_t pin, Gpio_PinLevelType level){
	#if GPIO_DATA_BIT_MASKING == ENABLE
	uint32_t gpioMaskOffset = 4 * pin;
	WRITE_HW_REG(GPIO_GET_REGISTER(Gpio_baseAddress[port], gpioMaskOffset ), (level << pin));
	#elif GPIO_DATA_BIT_MASKING == DISABLE
	WRITE_BIT(GPIO_GET_REGISTER(Gpio_baseAddress[port], GPIO_DATA_OFFSET ), pin, level);
	#endif
}

void Gpio_TogglePinLevel(Gpio_PortType port, uint32_t pin){
	#if GPIO_DATA_BIT_MASKING == ENABLE
	uint32_t gpioMaskOffset = pin << 2;
	TOG_BIT(GPIO_GET_REGISTER(Gpio_baseAddress[port], gpioMaskOffset), pin);
	#elif GPIO_DATA_BIT_MASKING == DISABLE
	TOG_BIT(GPIO_GET_REGISTER(Gpio_baseAddress[port], GPIO_DATA_OFFSET), pin);
	#endif
}

void Gpio_WritePortLevel(Gpio_PortType port, Gpio_PortLevelType level){
	WRITE_HW_REG(GPIO_GET_REGISTER(Gpio_baseAddress[port], GPIO_DATA_OFFSET ), level);
}

Gpio_PinLevelType Gpio_ReadPinLevel(Gpio_PortType port, uint32_t pin){
	Gpio_PinLevelType level;
	level = GET_BIT(GPIO_GET_REGISTER(Gpio_baseAddress[port], GPIO_DATA_OFFSET), pin);
	return level;
}
	
uint8_t Gpio_ReadPortLevel(Gpio_PortType port){
	Gpio_PinLevelType level;
	level = GPIO_GET_REGISTER(Gpio_baseAddress[port], GPIO_DATA_OFFSET ) & 0xFF;
	return level;
}

/****************************************************************************
*  END OF FILE : Gpio_Program.c
*****************************************************************************/
