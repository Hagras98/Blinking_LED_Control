/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt_Private.h
 *       Module:  MCU Core Peripherals
 *
 *  Description:  Defining MCU registers utilized in Gpt_Program.c  
 *  
 *********************************************************************************************************************/



#ifndef GPT_PRIVATE_H
#define GPT_PRIVATE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "../../Common/Bit_Math.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define GPT_TIMER_0_BASE_ADDRESS			0X40030000
#define GPT_TIMER_1_BASE_ADDRESS 			0X40031000
#define GPT_TIMER_2_BASE_ADDRESS 			0X40032000
#define GPT_TIMER_3_BASE_ADDRESS 			0X40033000
#define GPT_TIMER_4_BASE_ADDRESS 			0X40034000
#define GPT_TIMER_5_BASE_ADDRESS 			0X40035000
#define GPT_WIDE_TIMER_0_BASE_ADDRESS		0X40036000
#define GPT_WIDE_TIMER_1_BASE_ADDRESS		0X40037000
#define GPT_WIDE_TIMER_2_BASE_ADDRESS		0X4004C000
#define GPT_WIDE_TIMER_3_BASE_ADDRESS		0X4004D000
#define GPT_WIDE_TIMER_4_BASE_ADDRESS		0X4004E000
#define GPT_WIDE_TIMER_5_BASE_ADDRESS		0X4004F000

#define SYSCTL_BASE_ADDRESS					0x400FE000

#define GPTMCFG_OFFSET				0x000
#define GPTMTAMR_OFFSET             0x004
#define GPTMTBMR_OFFSET				0x008
#define GPTMCTL_OFFSET				0x00C
#define GPTMSYNC_OFFSET             0x010
#define GPTMIMR_OFFSET              0x018
#define GPTMRIS_OFFSET              0x01C
#define GPTMMIS_OFFSET              0x020
#define GPTMICR_OFFSET              0x024
#define GPTMTAILR_OFFSET            0x028
#define GPTMTBILR_OFFSET            0x02C
#define GPTMTAMATCHR_OFFSET         0x030
#define GPTMTBMATCHR_OFFSET         0x034
#define GPTMTAPR_OFFSET             0x038
#define GPTMTBPR_OFFSET             0x03C
#define GPTMTAPMR_OFFSET            0x040
#define GPTMTBPMR_OFFSET            0x044
#define GPTMTAR_OFFSET              0x048
#define GPTMTBR_OFFSET              0x04C
#define GPTMTAV_OFFSET              0x050
#define GPTMTBV_OFFSET              0x054
#define GPTMRTCPD_OFFSET            0x058
#define GPTMTAPS_OFFSET				0x05C
#define GPTMTBPS_OFFSET				0x060
#define GPTMTAPV_OFFSET				0x064
#define GPTMTBPV_OFFSET				0x068
#define GPTMPP_OFFSET				0xFC0

#define SYSCTL_RCGCTIMER_OFFSET		0x604
#define SYSCTL_RCGCWTIMER_OFFSET	0x65C


#define TIMER_RUN_MODE_CLOCK_GATING			*( (volatile uint32_t *) (SYSCTL_BASE_ADDRESS + SYSCTL_RCGCTIMER_OFFSET) )
#define WIDE_TIMER_RUN_MODE_CLOCK_GATING	*( (volatile uint32_t *) (SYSCTL_BASE_ADDRESS + SYSCTL_RCGCWTIMER_OFFSET) )


#define GPTMCFG(base) 				( (volatile GPTM_ConfigurationType*) (base + GPTMCFG_OFFSET) )
#define GPTMTAMR(base) 				( (volatile GPTM_TimernModeType*) (base + GPTMTAMR_OFFSET) )
#define GPTMTBMR(base) 				( (volatile GPTM_TimernModeType*) (base + GPTMTBMR_OFFSET) )
#define GPTMCTL(base) 				( (volatile GPTM_TimernControlType*) (base + GPTMCTL_OFFSET) )
#define GPTMIMR(base)	 			( (volatile GPTM_TimerInterruptType*) (base + GPTMIMR_OFFSET) )
#define GPTMRIS(base)  				( (volatile GPTM_TimerInterruptType*) (base + GPTMRIS_OFFSET) )
#define GPTMMIS(base)  				( (volatile GPTM_TimerInterruptType*) (base + GPTMMIS_OFFSET) )
#define GPTMICR(base)  				( (volatile GPTM_TimerInterruptType*) (base + GPTMICR_OFFSET) )
#define GPTMTAILR(base) 			*( (volatile uint32_t*) (base + GPTMTAILR_OFFSET) )
#define GPTMTBILR(base) 			*( (volatile uint32_t*) (base + GPTMTBILR_OFFSET) )
#define GPTMTAR(base) 				*( (volatile uint32_t*) (base + GPTMTAR_OFFSET) )
#define GPTMTBR(base) 				*( (volatile uint32_t*) (base + GPTMTBR_OFFSET) )
#define GPTMTAV(base) 				*( (volatile uint32_t*) (base + GPTMTAV_OFFSET) )
#define GPTMTBV(base) 				*( (volatile uint32_t*) (base + GPTMTBV_OFFSET) )
#define GPTMTAPR(base)				*( (volatile uint32_t*) (base + GPTMTAPR_OFFSET) )
#define GPTMTBPR(base)				*( (volatile uint32_t*) (base + GPTMTBPR_OFFSET) )
#define GPTMTAPMR(base)  			*( (volatile uint32_t*) (base + GPTMTAPMR_OFFSET) )
#define GPTMTBPMR(base)				*( (volatile uint32_t*) (base + GPTMTBPMR_OFFSET) )
#define GPTMTAPS(base)				*( (volatile uint32_t*) (base + GPTMTAPS_OFFSET) )
#define GPTMTBPS(base)	            *( (volatile uint32_t*) (base + GPTMTBPS_OFFSET) )
#define GPTMTAPV(base)				*( (volatile uint32_t*) (base + GPTMTAPV_OFFSET) )
#define GPTMTBPV(base)				*( (volatile uint32_t*) (base + GPTMTBPV_OFFSET) )

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct{
	uint32_t GPTMCFG:	3;
	uint32_t reserved:	29;
}GPTM_ConfigurationType;

typedef struct{
	uint32_t TnMR:		2;
	uint32_t TnCMR:		1;
	uint32_t TnAMS:		1;
	uint32_t TnCDIR:	1;
	uint32_t TnMIE:		1;
	uint32_t TnWOT:		1;
	uint32_t TnSNAPS:	1;
	uint32_t TnILD:		1;
	uint32_t TnPWMIE:	1;
	uint32_t TnMRSU:	1;
	uint32_t TnPLO:		1;
	uint32_t reserved:	20;
}GPTM_TimernModeType;

typedef struct{
	uint32_t TAEN:		1;
	uint32_t TASTALL:	1;
	uint32_t TAEVENT:	2;
	uint32_t RTCEN:		1;
	uint32_t TAOTE:		1;
	uint32_t TAPWML:	1;
	uint32_t reserved:	1;
	uint32_t TBEN:		1;
	uint32_t TBSTALL:	1;
	uint32_t TBEVENT:	2;
	uint32_t reserved1:	1;
	uint32_t TBOTE:		1;
	uint32_t TBPWML:	1;
	uint32_t reserved2:	17;
}GPTM_TimernControlType;

typedef struct{
	uint32_t TATO:		1;
	uint32_t CAM:		1;
	uint32_t CAE:		1;
	uint32_t RTC:		1;
	uint32_t TAM:		1;
	uint32_t reserved:	3;
	uint32_t TBTO:		1;
	uint32_t CBM:		1;
	uint32_t CBE:		1;
	uint32_t TBM:		1;
	uint32_t reserved1:	4;
	uint32_t WUE:		1;
	uint32_t reserved2:	15;
}GPTM_TimerInterruptType;

#endif  /* GPT_PRIVATE_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpt_Private.h
 *********************************************************************************************************************/