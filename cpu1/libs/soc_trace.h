/*
 * soc_trace.h
 *
 *  Created on: 21 de ago de 2022
 *      Author: marco
 */

#ifndef LIBS_SOC_TRACE_H_
#define LIBS_SOC_TRACE_H_

//===========================================================================
/*------------------------------- Includes --------------------------------*/
//===========================================================================
#include "stdint.h"
//===========================================================================

//===========================================================================
/*------------------------------ Definitions ------------------------------*/
//===========================================================================
typedef enum soctraceIDs_t{
	SOC_TRACE_ID_1,
	SOC_TRACE_ID_END
}soctraceIDs_t;

typedef enum soctraceDTypes_t{
	SOC_TRACE_DTYPE_INT,
	SOC_TRACE_DTYPE_UINT,
	SOC_TRACE_DTYPE_FLOAT
}soctraceDTypes_t;
//===========================================================================

//===========================================================================
/*------------------------------- Functions -------------------------------*/
//===========================================================================
//---------------------------------------------------------------------------
void soctraceInitialize(soctraceIDs_t id, uint32_t *mem, uint32_t size, uint32_t **data, uint8_t *dtype,  char *tags);
//---------------------------------------------------------------------------
void soctraceAdd(soctraceIDs_t id, uint32_t *src, uint8_t dtype, char *tag);
//---------------------------------------------------------------------------
void soctraceReset(soctraceIDs_t id);
//---------------------------------------------------------------------------
void soctraceSetSize(soctraceIDs_t id, uint32_t size);
//---------------------------------------------------------------------------
uint32_t soctraceReadQtyTraces(soctraceIDs_t id);
//---------------------------------------------------------------------------
uint32_t soctraceReadTags(soctraceIDs_t id, char *buffer);
//---------------------------------------------------------------------------
uint32_t soctraceReadDTypes(soctraceIDs_t id, uint8_t *buffer);
//---------------------------------------------------------------------------
void soctraceSave(soctraceIDs_t id);
//---------------------------------------------------------------------------
//===========================================================================

#endif /* LIBS_SOC_TRACE_H_ */