/*
 * ocpTrace.h
 *
 *  Created on: 17.02.2023
 *      Author: mguerreiro
 */

#ifndef OCP_TRACE_H_
#define OCP_TRACE_H_

//===========================================================================
/*------------------------------- Includes --------------------------------*/
//===========================================================================
#include "stdint.h"

#include "ctrace.h"
//===========================================================================

//===========================================================================
/*------------------------------ Definitions ------------------------------*/
//===========================================================================

typedef ctraceConfig_t ocpTraceConfig_t;

#define OCP_TRACE_CONFIG_TRACE_NAME_MAX_LEN		20

typedef enum{
	OCP_TRACE_1 = 0,
	OCP_TRACE_2,
	OCP_TRACE_END
}ocpTraceIDs_t;

//===========================================================================

//===========================================================================
/*------------------------------- Functions -------------------------------*/
//===========================================================================
//---------------------------------------------------------------------------
int32_t ocpTraceInitialize(uint32_t id, ocpTraceConfig_t *config, char *name);
//---------------------------------------------------------------------------
int32_t ocpTraceAddSignal(uint32_t id, void *src, char *name);
//---------------------------------------------------------------------------
int32_t ocpTraceGetAddress(uint32_t id, void *address);
//---------------------------------------------------------------------------
int32_t ocpTraceReset(uint32_t id);
//---------------------------------------------------------------------------
int32_t ocpTraceGetSize(uint32_t id);
//---------------------------------------------------------------------------
int32_t ocpTraceSetSize(uint32_t id, int32_t size);
//---------------------------------------------------------------------------
int32_t ocpTraceGetNumberSignals(uint32_t id);
//---------------------------------------------------------------------------
int32_t ocpTraceGetSignalsNames(uint32_t id, char *buffer, int32_t maxsize);
//---------------------------------------------------------------------------
int32_t ocpTraceGetNumberTraces(void);
//---------------------------------------------------------------------------
int32_t ocpTraceGetTracesNames(char *buffer, int32_t maxsize);
//---------------------------------------------------------------------------
int32_t ocpTraceSave(uint32_t id);
//---------------------------------------------------------------------------
//===========================================================================

#endif /* OCP_TRACE_H_ */
