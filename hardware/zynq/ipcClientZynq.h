/*
 * @file ipcClientZynq.h
 *
 * @brief Client for the inter-processor communication (IPC) library.
 *
 */

#ifndef IPC_CLIENT_ZYNQ_H_
#define IPC_CLIENT_ZYNQ_H_

#ifdef SOC_CPU0
//=============================================================================
/*-------------------------------- Includes ---------------------------------*/
//=============================================================================
#include "stdint.h"
#include "stddef.h"

//=============================================================================

//=============================================================================
/*------------------------------- Definitions -------------------------------*/
//=============================================================================
/* CPU1->CPU0 timeout error code */
#define IPC_CLIENT_ZYNQ_ERR_CPU1_REPLY_TO				-1

/* Invalid CPU1 command */
#define IPC_CLIENT_ZYNQ_ERR_CPU1_INVALID_CMD			-2

/* Data received exceeds CPU0->CPU1 buffer */
#define IPC_CLIENT_ZYNQ_ERR_CPU0_CPU1_BUFFER_OVERFLOW	-3

/* CPU1->CPU0 reply timeout */
#define IPC_CLIENT_ZYNQ_CONFIG_CPU1_REPLY_TO_MS			100
//=============================================================================

//=============================================================================
/*-------------------------------- Functions --------------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
void ipcClientZynqInitialize(void *irqInst);
//-----------------------------------------------------------------------------
int32_t ipcClientZynqIrqSend(void);
//-----------------------------------------------------------------------------
int32_t ipcClientZynqIrqReceive(uint32_t timeout);
//-----------------------------------------------------------------------------
//=============================================================================
#endif /* SOC_CPU0 */
#endif /* IPC_CLIENT_ZYNQ_H_ */
