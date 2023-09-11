/*
 * @file ocpZynqCpu1.c
 *
 */

#ifdef SOC_CPU1
//=============================================================================
/*-------------------------------- Includes ---------------------------------*/
//=============================================================================
#include "ocpZynqCpu1.h"


/* Open controller project */
#include "ocpConfig.h"
#include "ocpTrace.h"
#include "ocpCS.h"
#include "ocpIf.h"
#include "ocpOpil.h"

/* Inter-processor communication */
#include "../ipc/ipcServer.h"

/* Controller lib */
#include "../controller/controller.h"

/* Zynq-specific stuff */
#include "ipcServerZynq.h"

/* Application */
#include "afe.h"
#include "afeIf.h"
#include "afeHwZynq.h"

#include "buckOpil.h"
#include "buckController.h"
#include "buckHw.h"

#include "zynqConfig.h"
//=============================================================================

//=============================================================================
/*-------------------------------- Prototypes -------------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
static int32_t ocpZynqCpu1InitializeHw(void *intcInst);
//-----------------------------------------------------------------------------
static int32_t ocpZynqCpu1InitializeIpc(void *intcInst);
//-----------------------------------------------------------------------------
static int32_t ocpZynqCpu1InitializeTraces(void);
//-----------------------------------------------------------------------------
static int32_t ocpZynqCpu1InitializeControlSystem(void);
//-----------------------------------------------------------------------------
static int32_t ocpZynqCpu1InitializeInterface(void);
//-----------------------------------------------------------------------------
//=============================================================================

//=============================================================================
/*------------------------------- Definitions -------------------------------*/
//=============================================================================
#define OCP_ZYNQ_C1_CONFIG_CPU0_TO_CPU1_ADDR		ZYNQ_CONFIG_MEM_CPU0_TO_CPU1_ADR
#define OCP_ZYNQ_C1_CONFIG_CPU0_TO_CPU1_SIZE		ZYNQ_CONFIG_MEM_CPU0_TO_CPU1_SIZE

#define OCP_ZYNQ_C1_CONFIG_CPU1_TO_CPU0_ADDR		ZYNQ_CONFIG_MEM_CPU1_TO_CPU0_ADR
#define OCP_ZYNQ_C1_CONFIG_CPU1_TO_CPU0_SIZE		ZYNQ_CONFIG_MEM_CPU1_TO_CPU0_SIZE

#define OCP_ZYNQ_C1_CONFIG_TRACE_0_ADDR				ZYNQ_CONFIG_MEM_TRACE_ADR
#define OCP_ZYNQ_C1_CONFIG_TRACE_0_SIZE				ZYNQ_CONFIG_MEM_TRACE_SIZE_MAX

#define OCP_ZYNQ_C1_CONFIG_TRACE_0_NAME_LEN			250
#define OCP_ZYNQ_C1_CONFIG_TRACE_0_MAX_SIGNALS		20
//=============================================================================

//=============================================================================
/*--------------------------------- Globals ---------------------------------*/
//=============================================================================
static char trace0Names[OCP_ZYNQ_C1_CONFIG_TRACE_0_NAME_LEN];
static size_t trace0Data[OCP_ZYNQ_C1_CONFIG_TRACE_0_MAX_SIGNALS];

static float bInputs[10];
static float bProcInputs[10];
static float bProcOutputs[10];
static float bOutputs[10];
//=============================================================================

//=============================================================================
/*-------------------------------- Functions --------------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
void ocpZynqCpu1Initialize(void *intcInst){

	ocpZynqCpu1InitializeTraces();
	ocpZynqCpu1InitializeIpc(intcInst);
	ocpZynqCpu1InitializeHw(intcInst);
	ocpZynqCpu1InitializeControlSystem();
	ocpZynqCpu1InitializeInterface();
}
//-----------------------------------------------------------------------------
//=============================================================================


//=============================================================================
/*---------------------------- Static functions -----------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
static int32_t ocpZynqCpu1InitializeHw(void *intcInst){

	afeHwZynqInitialize(intcInst);

	return 0;
}
//-----------------------------------------------------------------------------
static int32_t ocpZynqCpu1InitializeIpc(void *intcInst){

    /* Initializes inter-processor communication */
    ipcServerZynqInitialize(intcInst);

    ipcServerInitialize(ocpIf, ipcServerZynqIrqSend,
            ZYNQ_CONFIG_MEM_CPU0_TO_CPU1_ADR, ZYNQ_CONFIG_MEM_CPU0_TO_CPU1_SIZE,
            ZYNQ_CONFIG_MEM_CPU1_TO_CPU0_ADR, ZYNQ_CONFIG_MEM_CPU1_TO_CPU0_SIZE);

    return 0;
}
//-----------------------------------------------------------------------------
static int32_t ocpZynqCpu1InitializeTraces(void){

	ocpTraceConfig_t config;

	config.mem = (void *)OCP_ZYNQ_C1_CONFIG_TRACE_0_ADDR;
	config.size = OCP_ZYNQ_C1_CONFIG_TRACE_0_SIZE;
	config.data = (void **)trace0Data;
	config.names = trace0Names;

	ocpTraceInitialize(OCP_TRACE_1, &config, "Main Trace");

	return 0;
}
//-----------------------------------------------------------------------------
static int32_t ocpZynqCpu1InitializeControlSystem(void){

	ocpCSConfig_t config;

	/* Initializes controller lib */
	buckControllerInitialize();

	/* Initializes control sys lib */
	config.binputs = (void *)bInputs;
	config.bprocInputs = (void *)bProcInputs;
	config.bprocOutputs = (void *)bProcOutputs;
	config.boutputs = (void *)bOutputs;

    config.fhwInterface = 0;
    config.fhwStatus = buckHwStatus;

    config.fgetInputs = buckOpilGetMeasurements;
    config.fprocInputs = buckOpilProcInputs;

    config.fprocOutputs = buckOpilProcOutputs;
    config.fapplyOutputs = buckOpilUpdateControl;

    config.frun = buckControllerRun;
    config.fcontrollerInterface = buckControllerInterface;
    config.fcontrollerStatus = buckControllerStatus;

    config.fenable = 0;
    config.fdisable = buckOpilDisable;

    config.fonEntry = 0;
    config.fonExit = 0;


//	controllerInitialize();
//	config.fhwInterface = afeIf;
//
//	config.fgetInputs = afeHwZynqGetInputs;
//	config.fprocInputs = afeHwZynqProcInputs;
//
//	config.fprocOutputs = afeHwZynqProcOutputs;
//	config.fapplyOutputs = afeHwZynqApplyOutputs;
//
//	config.frun = controllerRun;
//	config.fcontrollerInterface = controllerInterface;
//
//	config.fenable = 0;
//	config.fdisable = 0;
//
//	config.fonEntry = 0;
//	config.fonExit = 0;


	ocpCSInitialize(OCP_CS_1, &config, "Converter control");

	return 0;
}
//-----------------------------------------------------------------------------
static int32_t ocpZynqCpu1InitializeInterface(void){

    /* Initializes OPiL interface */
    ocpOpilConfig_t config;

    config.updateMeas = buckOpilUpdateMeasurements;
    config.updateSimData = buckOpilUpdateSimData;

    config.initControl = 0;

    config.getControl = buckOpilGetControl;
    config.getControllerData = buckOpilGetControllerData;

    ocpOpilInitialize(&config);

    /* Initializes OCP interface */
    ocpIfInitialize();

	return 0;
}
//-----------------------------------------------------------------------------
//=============================================================================
#endif /* SOC_CPU0 */
