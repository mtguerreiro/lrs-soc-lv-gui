/*
 * @file afeZynqHw.c
 *
 */

#ifdef SOC_CPU1
//=============================================================================
/*-------------------------------- Includes ---------------------------------*/
//=============================================================================
#include "afeZynqHw.h"

#include "soc_defs.h"

#include "xparameters.h"
#include <stdio.h>
#include "xil_io.h"
#include "xil_mmu.h"
#include "xil_cache.h"
#include "xil_exception.h"
#include "xscugic.h"
#include "sleep.h"

#include "xgpio.h"
#include "xil_types.h"

#include "axi_test.h"

#include "afeZynqHwIf.h"

#include "ocpTrace.h"
//=============================================================================

//=============================================================================
/*------------------------------- Definitions -------------------------------*/
//=============================================================================

#define AFE_ZYNQ_HW_CONFIG_IRQ_PL_TO_CPU1	SOC_IRQ_PL_TO_CPU1

#define AXI_TEST_BASE_ADR			XPAR_ADC_PSCTL_0_S00_AXI_BASEADDR
#define AXI_PWM_BASE_ADR			XPAR_AXI_PWM_0_S00_AXI_BASEADDR
#define AXI_GPIO_DEBUG_BASE_ADR		XPAR_AXI_GPIO_DEBUG_BASEADDR
//=============================================================================

//=============================================================================
/*--------------------------------- Globals ---------------------------------*/
//=============================================================================
static float gridVoltage = 0.0f;
//=============================================================================

//=============================================================================
/*-------------------------------- Prototypes -------------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
static int32_t afeZynqHwInitIf(void);
//-----------------------------------------------------------------------------
static int32_t afeZynqHwInitHw(void * intcInst);
//-----------------------------------------------------------------------------
void afeZynqHwPlToCpuIrq(void *callbackRef);
//-----------------------------------------------------------------------------
//=============================================================================

//=============================================================================
/*-------------------------------- Functions --------------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
void afeZynqHwInitialize(void * intcInst){


	afeZynqHwInitHw(intcInst);
	afeZynqHwInitIf();
}
//-----------------------------------------------------------------------------
int32_t afeZynqHwAdcEn(uint32_t en){

	if( en == 0 ) AXI_TEST_mWriteReg(AXI_PWM_BASE_ADR, 0, 0U);
	else AXI_TEST_mWriteReg(AXI_PWM_BASE_ADR, 0, 1U);

	return 0;
}
//-----------------------------------------------------------------------------
int32_t afeZynqHwSetAdcSpiFreq(uint32_t freq){

	uint32_t en;

	en = AXI_TEST_mReadReg(AXI_PWM_BASE_ADR, 0);

	if( (en & 1) == 1 ) AXI_TEST_mWriteReg(AXI_PWM_BASE_ADR, 0, 0U);

	AXI_TEST_mWriteReg(AXI_TEST_BASE_ADR, 4, freq);

	if( (en & 1) == 1 ) AXI_TEST_mWriteReg(AXI_PWM_BASE_ADR, 0, en);

	return 0;
}
//-----------------------------------------------------------------------------
int32_t afeZynqHwSetAdcSamplingFreq(uint32_t freq){

	uint32_t en;

	en = AXI_TEST_mReadReg(AXI_PWM_BASE_ADR, 0);

	if( (en & 1) == 1 ) AXI_TEST_mWriteReg(AXI_PWM_BASE_ADR, 0, 0U);

	//AXI_TEST_mWriteReg(AXI_PWM_BASE_ADR, 0, 1U);
	AXI_TEST_mWriteReg(AXI_PWM_BASE_ADR, 4, freq);
	AXI_TEST_mWriteReg(AXI_PWM_BASE_ADR, 8, 0);

	//AXI_TEST_mWriteReg(AXI_TEST_BASE_ADR, 8, freq);

	if( (en & 1) == 1 ) AXI_TEST_mWriteReg(AXI_PWM_BASE_ADR, 0, en);

	return 0;
}
//-----------------------------------------------------------------------------
//=============================================================================

//=============================================================================
/*---------------------------- Static functions -----------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
static int32_t afeZynqHwInitIf(void){

	afeZynqHwIfInitialize();

	return 0;
}
//-----------------------------------------------------------------------------
static int32_t afeZynqHwInitHw(void * intcInst){

	XScuGic_SetPriorityTriggerType(intcInst, AFE_ZYNQ_HW_CONFIG_IRQ_PL_TO_CPU1, 0xA0, 0x3);
	XScuGic_Connect(intcInst, AFE_ZYNQ_HW_CONFIG_IRQ_PL_TO_CPU1, (Xil_ExceptionHandler)afeZynqHwPlToCpuIrq, intcInst) ;
	XScuGic_Enable(intcInst, AFE_ZYNQ_HW_CONFIG_IRQ_PL_TO_CPU1);

	ocpTraceAddSignal(OCP_TRACE_1, (void *)&gridVoltage, "Grid voltage");

	return 0;
}
//-----------------------------------------------------------------------------
//=============================================================================

//=============================================================================
/*----------------------------------- IRQ -----------------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
void afeZynqHwPlToCpuIrq(void *callbackRef){

	gridVoltage = SOC_ADC_TO_SIGNAL(*((uint16_t *)(SOC_AFE_GRID_VOLTAGE)), SOC_AFE_GRID_VOLTAGE_SENS_GAIN, SOC_AFE_GRID_VOLTAGE_SENS_OFFS);

	ocpTraceSave(OCP_TRACE_1);

}
//-----------------------------------------------------------------------------
//=============================================================================

#endif /* SOC_CPU1 */
