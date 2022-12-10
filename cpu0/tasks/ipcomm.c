/*
 * ipcomm.c
 *
 *  Created on: 23.05.2022
 *      Author: Marco Guerreiro
 *
 * CPU
 */

//=============================================================================
/*-------------------------------- Includes ---------------------------------*/
//=============================================================================
#include "ipcomm.h"

/* Kernel */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

/* Device and drivers */
#include "xparameters.h"
#include "xil_types.h"

#include "xil_exception.h"
#include "xscugic_hw.h"
#include "xil_printf.h"
#include "xstatus.h"
#include "xscugic.h"

/* Tasks */
#include "uiface.h"

/* LRS SoC defs */
#include "soc_defs.h"
//=============================================================================

//=============================================================================
/*--------------------------------- Defines ---------------------------------*/
//=============================================================================
/*
 * Software generated interrupt (SIG) from CPU0 to CPU1. This interrupt is
 * generated by CPU0 to notify CPU1 that a new command is to be executed.
 */
#define IPCOMM_INT_CPU0_TO_CPU1		SOC_SIG_CPU0_TO_CPU1

/*
 * Software generated interrupt (SIG) from CPU1 to CPU0. This interrupt is
 * generated by CPU1 to notify CPU0 that a requested command was executed.
 */
#define IPCOMM_INT_CPU1_TO_CPU0		SOC_SIG_CPU1_TO_CPU0

/* CPU1->CPU0 reply timeout, in system ticks */
#define IPCOMM_CONFIG_CPU1_REPLY_TO		(IPCOMM_CONFIG_CPU1_REPLY_TO_MS / portTICK_PERIOD_MS)

/* Functions binding to CPU1 commands should have this signature */
typedef uifaceHandle_t ipcommCMDHandle_t;

typedef struct{
	/*
	 * CPU1 flag.
	 *
	 * This flag is set by CPU0 before a command is issued to CPU1. After
	 * CPU1 executes its commands, it generates an interrupt in CPU1. The
	 * handler of this interrupt clears this flag. Thus, this flag is used
	 * to indicate that CPU1 executed a command issued by CPU0.
	 */
	volatile uint32_t cpu1flag; /* Should this be volatile? */

	/*
	 * CPU1 commands.
	 *
	 * The index corresponds to CPU1 commands, while the entries correspond
	 * to CPU0 commands.
	 */
	uint32_t cmd[SOC_CMD_CPU1_END];

	/* Interrupt controller instance */
	XScuGic *intcInstance;

	/*
	 * Semaphore used to signal a response from CPU1.
	 *
	 * This semaphore is taken before a command is issued to CPU1. When CPU1
	 * replies back, an interrupt is generated in CPU0, which releases the
	 * semaphore. Thus, the semaphore is used to indicate that CPU1 replied
	 * to a command issued by CPU0.
	 */
	SemaphoreHandle_t cpu1Semaphore;

}ipcommControl_t;

//=============================================================================

//=============================================================================
/*--------------------------------- Globals ---------------------------------*/
//=============================================================================
ipcommControl_t xipcommControl;
//=============================================================================


//=============================================================================
/*-------------------------------- Prototypes -------------------------------*/
//=============================================================================
static int ipcommInitialize(void);

static void ipCommInitializeCMDs(void);

static void ipcommCMDRegister(uint32_t cpu0cmd, uint32_t cpu1cmd, ipcommCMDHandle_t handle);
static uint32_t ipcommCMDFind(uint32_t cpu0cmd);
static int32_t ipcommCMDExecute(uint32_t cmd, uint8_t **pbuf, uint32_t size);

void ipcommIRQCPU1(void *CallbackRef);
//=============================================================================

//=============================================================================
/*---------------------------------- Task -----------------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
void ipcomm(void *intcInstance){

	xipcommControl.intcInstance = (XScuGic *)intcInstance;

	ipcommInitialize();

	vTaskDelete(NULL);

	while(1);
}
//-----------------------------------------------------------------------------
//=============================================================================

//=============================================================================
/*---------------------------- Static functions -----------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
static int ipcommInitialize(void){

	XScuGic_Connect(xipcommControl.intcInstance, IPCOMM_INT_CPU1_TO_CPU0,
					(Xil_ExceptionHandler)ipcommIRQCPU1,
					(void  *)xipcommControl.intcInstance);
	XScuGic_Enable(xipcommControl.intcInstance, IPCOMM_INT_CPU1_TO_CPU0);

	ipCommInitializeCMDs();

	xipcommControl.cpu1Semaphore = xSemaphoreCreateBinary();

	return XST_SUCCESS;
}
//-----------------------------------------------------------------------------
static void ipCommInitializeCMDs(void){

	ipcommCMDRegister(SOC_CMD_CPU0_BLINK_CPU1, SOC_CMD_CPU1_BLINK, ipcommCMDExecute);

	ipcommCMDRegister(SOC_CMD_CPU0_ADC_EN, SOC_CMD_CPU1_ADC_EN, ipcommCMDExecute);

	ipcommCMDRegister(SOC_CMD_CPU0_ADC_SPI_FREQ_SET, SOC_CMD_CPU1_ADC_SPI_FREQ_SET, ipcommCMDExecute);

	ipcommCMDRegister(SOC_CMD_CPU0_ADC_SAMPLING_FREQ_SET, SOC_CMD_CPU1_ADC_SAMPLING_FREQ_SET, ipcommCMDExecute);

	ipcommCMDRegister(SOC_CMD_CPU0_ADC_ERROR_READ, SOC_CMD_CPU1_ADC_ERROR_READ, ipcommCMDExecute);

	ipcommCMDRegister(SOC_CMD_CPU0_ADC_ERROR_CLEAR, SOC_CMD_CPU1_ADC_ERROR_CLEAR, ipcommCMDExecute);

	ipcommCMDRegister(SOC_CMD_CPU0_TRACE_START, SOC_CMD_CPU1_TRACE_START, ipcommCMDExecute);

	ipcommCMDRegister(SOC_CMD_CPU0_TRACE_READ_TAGS, SOC_CMD_CPU1_TRACE_READ_TAGS, ipcommCMDExecute);

	ipcommCMDRegister(SOC_CMD_CPU0_TRACE_READ, SOC_CMD_CPU1_TRACE_READ, ipcommCMDExecute);

	ipcommCMDRegister(SOC_CMD_CPU0_TRACE_SIZE_SET, SOC_CMD_CPU1_TRACE_SIZE_SET, ipcommCMDExecute);

	ipcommCMDRegister(SOC_CMD_CPU0_TRACE_SIZE_READ, SOC_CMD_CPU1_TRACE_SIZE_READ, ipcommCMDExecute);

	ipcommCMDRegister(SOC_CMD_CPU0_CONTROL_EN, SOC_CMD_CPU1_CONTROL_EN, ipcommCMDExecute);

}
//-----------------------------------------------------------------------------
static void ipcommCMDRegister(uint32_t cpu0cmd, uint32_t cpu1cmd, ipcommCMDHandle_t handle){

	xipcommControl.cmd[cpu1cmd] = cpu0cmd;
	uifaceRegisterHandle(cpu0cmd, handle);
}
//-----------------------------------------------------------------------------
static uint32_t ipcommCMDFind(uint32_t cpu0cmd){

	uint32_t i;

	for(i = 0; i < SOC_CMD_CPU1_END; i++){
		if( xipcommControl.cmd[i] == cpu0cmd ) break;
	}

	return i;
}
//-----------------------------------------------------------------------------
static int32_t ipcommCMDExecute(uint32_t cmd, uint8_t **pbuf, uint32_t size){

	uint32_t cpu0cmd, cpu1cmd;
	uint8_t *src, *dst;
	uint32_t i;
	uint32_t status;

	/*
	 * If amount of data to be passed to CPU1 exceeds the available memory,
	 * an error is generated.
	 */
	if( size > SOC_MEM_CPU0_TO_CPU1_SIZE ) return IPCOMM_ERR_CPU0_CPU1_BUFFER_OVERFLOW;

	cpu0cmd = cmd;
	cpu1cmd = ipcommCMDFind(cpu0cmd);

	/* If the command received does not exist, returns an error */
	if( cpu1cmd >= SOC_CMD_CPU1_END) return IPCOMM_ERR_CPU1_INVALID_CMD;

	xSemaphoreTake(xipcommControl.cpu1Semaphore, 0);

	/*
	 * Transferring data to CPU1 follows the procedure described in the
	 * soc_defs.h file.
	 */
	/* Writes command to be executed */
	*( (uint32_t *)SOC_MEM_CPU0_TO_CPU1_CMD ) = cpu1cmd;

	/* Writes size of data (in number of bytes) */
	*( (uint32_t *)SOC_MEM_CPU0_TO_CPU1_CMD_SIZE ) = size;

	/*
	 * Writes where data will be located at. Here, we will always copy data
	 * from the uiface buffer to the CPU0->CPU1 buffer.
	 */
	if( size > 0 ){
		//*( (uint32_t *)SOC_MEM_CPU0_TO_CPU1_CMD_DATA_ADDR ) = SOC_MEM_CPU0_TO_CPU1_DATA;
		dst = (uint8_t *)(SOC_MEM_CPU0_TO_CPU1_DATA);
		src = *pbuf;
		for(i = 0; i < size; i++) *dst++ = *src++;
	}

	/* Generates a software interrupt on CPU1 */
	XScuGic_SoftwareIntr ( xipcommControl.intcInstance, IPCOMM_INT_CPU0_TO_CPU1, SOC_SIG_CPU1_ID );

	/* Waits until CPU1 replies back */
	if( xSemaphoreTake(xipcommControl.cpu1Semaphore, IPCOMM_CONFIG_CPU1_REPLY_TO) != pdTRUE ){
		return IPCOMM_ERR_CPU1_REPLY_TO;
	}

	/*
	 * Gets the command status and writes to pbuf the address of where the
	 * data (if any) is located at.
	 */
	status = *( (uint32_t *)SOC_MEM_CPU1_TO_CPU0_CMD_STATUS );
	*pbuf = (uint8_t *) ( *( (uint32_t *)SOC_MEM_CPU1_TO_CPU0_CMD_DATA_ADDR ) );

	return status;
}
//-----------------------------------------------------------------------------
//=============================================================================

//=============================================================================
/*----------------------------------- IRQ -----------------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
void ipcommIRQCPU1(void *CallbackRef){

	BaseType_t xHigherPriorityTaskWoken;

	xipcommControl.cpu1flag = 0;

	xSemaphoreGiveFromISR( xipcommControl.cpu1Semaphore, &xHigherPriorityTaskWoken );

	portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
}
//-----------------------------------------------------------------------------
//=============================================================================
