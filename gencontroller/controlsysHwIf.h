/*
 * controlsysHwIf.h
 *
 *  Created on: 4 de set de 2022
 *      Author: marco
 */

#ifndef CONTROLSYSHWIF_H_
#define CONTROLSYSHWIF_H_

//=============================================================================
/*-------------------------------- Includes ---------------------------------*/
//=============================================================================
#include "stdint.h"
//=============================================================================

//=============================================================================
/*-------------------------------- Functions --------------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
int32_t controlsysHwIfInitialize(void);
//-----------------------------------------------------------------------------
int32_t controlsysHwIfGetMeas(void *meas);
//-----------------------------------------------------------------------------
void controlsysHwIfProcMeas(void *meas, void *procmeas, int32_t n);
//-----------------------------------------------------------------------------
void controlsysHwIfProcOutputs(void *outputs, void *procoutputs, int32_t n);
//-----------------------------------------------------------------------------
void controlsysHwIfApplyOutputs(void *outputs, int32_t n);
//-----------------------------------------------------------------------------
int32_t controlsysHwIfSetParams(void *params, int32_t n);
//-----------------------------------------------------------------------------
int32_t controlsysHwIfGetParams(void *in, void *out);
//-----------------------------------------------------------------------------
//=============================================================================

#endif /* CONTROLSYSHWIF_H_ */
