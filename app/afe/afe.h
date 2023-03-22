/*
 * @file afe.h
 *
 */

#ifndef AFE_H_
#define AFE_H_

#ifdef SOC_CPU1
//=============================================================================
/*-------------------------------- Includes ---------------------------------*/
//=============================================================================
#include "stdint.h"
#include "stddef.h"

//=============================================================================

//=============================================================================
/*------------------------------- Definitions -------------------------------*/
//=============================================================================


//=============================================================================

//=============================================================================
/*-------------------------------- Functions --------------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
int32_t afeInitialize(void *initparams);
//-----------------------------------------------------------------------------
int32_t afeAdcEnable(uint32_t enable);
//-----------------------------------------------------------------------------
int32_t afeAdcConfig(void *adcparams);
//-----------------------------------------------------------------------------
int32_t afePwmEnable(uint32_t enable);
//-----------------------------------------------------------------------------
int32_t afePwmSetDuty(uint32_t duty);
//-----------------------------------------------------------------------------
int32_t afePwmConfig(void *pwmparams);
//-----------------------------------------------------------------------------
void afeInputRelaySet(uint32_t state);
//-----------------------------------------------------------------------------
void afeOutputRelaySet(uint32_t state);
//-----------------------------------------------------------------------------
//=============================================================================
#endif /* SOC_CPU1 */

#endif /* AFE_H_ */
