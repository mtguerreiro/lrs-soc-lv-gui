/*
 * cukHwOpil.h
 *
 *  Created on: 06.10.2023
 *      Author: mguerreiro
 */

#ifndef CUK_HW_OPIL_H_
#define CUK_HW_OPIL_H_

//=============================================================================
/*-------------------------------- Includes ---------------------------------*/
//=============================================================================
#include "stdint.h"
//=============================================================================

//=============================================================================
/*-------------------------------- Functions --------------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
int32_t cukHwOpilInitialize(void);
//-----------------------------------------------------------------------------
int32_t cukHwOpilStatus(void);
//-----------------------------------------------------------------------------
void cukHwOpilSetPwmReset(uint32_t reset);
//-----------------------------------------------------------------------------
uint32_t cukHwOpilGetPwmReset(void);
//-----------------------------------------------------------------------------
void cukHwOpilSetPwmOutputEnable(uint32_t enable);
//-----------------------------------------------------------------------------
uint32_t cukHwOpilGetPwmOutputEnable(void);
//-----------------------------------------------------------------------------
void cukHwOpilSetPwmOvfTriggerEnable(uint32_t enable);
//-----------------------------------------------------------------------------
uint32_t cukHwOpilGetPwmOvfTriggerEnable(void);
//-----------------------------------------------------------------------------
void cukHwOpilSetPwmFrequency(uint32_t freq);
//-----------------------------------------------------------------------------
uint32_t cukHwOpilGetPwmFrequency(void);
//-----------------------------------------------------------------------------
void cukHwOpilSetPwmDuty(float duty);
//-----------------------------------------------------------------------------
float cukHwOpilGetPwmDuty(void);
//-----------------------------------------------------------------------------
void cukHwOpilSetPwmDeadTime(float deadtime);
//-----------------------------------------------------------------------------
float cukHwOpilGetPwmDeadTime(void);
//-----------------------------------------------------------------------------
void cukHwOpilSetAdcEnable(uint32_t enable);
//-----------------------------------------------------------------------------
uint32_t cukHwOpilGetAdcEnable(void);
//-----------------------------------------------------------------------------
void cukHwOpilSetAdcManualTrigger(uint32_t trigger);
//-----------------------------------------------------------------------------
uint32_t cukHwOpilGetAdcManualTrigger(void);
//-----------------------------------------------------------------------------
void cukHwOpilSetAdcInterruptEnable(uint32_t enable);
//-----------------------------------------------------------------------------
uint32_t cukHwOpilGetAdcInterruptEnable(void);
//-----------------------------------------------------------------------------
void cukHwOpilSetAdcSpiFreq(uint32_t freq);
//-----------------------------------------------------------------------------
uint32_t cukHwOpilGetAdcSpiFreq(void);
//-----------------------------------------------------------------------------
int32_t cukHwOpilGetMeasurements(void *meas);
//-----------------------------------------------------------------------------
int32_t cukHwOpilApplyOutputs(void *outputs, int32_t size);
//-----------------------------------------------------------------------------
void cukHwOpilDisable(void);
//-----------------------------------------------------------------------------
void cukHwOpilEnable(void);
//-----------------------------------------------------------------------------
void cukHwOpilControllerDisable(void);
//-----------------------------------------------------------------------------
void cukHwOpilControllerEnable(void);
//-----------------------------------------------------------------------------
void cukHwOpilSetLoadSwitch(uint32_t state);
//-----------------------------------------------------------------------------
uint32_t cukHwOpilGetLoadSwitch(void);
//-----------------------------------------------------------------------------
void cukHwOpilSetOutputSwitch(uint32_t state);
//-----------------------------------------------------------------------------
uint32_t cukHwOpilGetOutputSwitch(void);
//-----------------------------------------------------------------------------
//=============================================================================

#endif /* CUK_HW_OPIL_H_ */
