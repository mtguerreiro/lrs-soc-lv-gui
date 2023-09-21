/*
 * cukHwIf.h
 *
 *  Created on: 31 de ago de 2023
 *      Author: marco
 */

#ifndef CUK_HW_IF_H_
#define CUK_HW_IF_H_

//=============================================================================
/*-------------------------------- Includes ---------------------------------*/
//=============================================================================
#include "stdint.h"
//=============================================================================

//=============================================================================
/*------------------------------- Definitions -------------------------------*/
//=============================================================================
typedef enum{
    CUK_HW_IF_SET_PWM_RESET,
    CUK_HW_IF_GET_PWM_RESET,
    CUK_HW_IF_SET_PWM_OUTPUT_ENABLE,
    CUK_HW_IF_GET_PWM_OUTPUT_ENABLE,
    CUK_HW_IF_SET_PWM_OVF_TRIGGER_ENABLE,
    CUK_HW_IF_GET_PWM_OVF_TRIGGER_ENABLE,
    CUK_HW_IF_SET_PWM_FREQ,
    CUK_HW_IF_GET_PWM_FREQ,
    CUK_HW_IF_SET_PWM_DUTY,
    CUK_HW_IF_GET_PWM_DUTY,
    CUK_HW_IF_SET_PWM_DEAD_TIME,
    CUK_HW_IF_GET_PWM_DEAD_TIME,
    CUK_HW_IF_SET_ADC_ENABLE,
    CUK_HW_IF_GET_ADC_ENABLE,
    CUK_HW_IF_SET_ADC_MANUAL_TRIG,
    CUK_HW_IF_GET_ADC_MANUAL_TRIG,
    CUK_HW_IF_SET_ADC_INT_ENABLE,
    CUK_HW_IF_GET_ADC_INT_ENABLE,
    CUK_HW_IF_SET_ADC_SPI_FREQ,
    CUK_HW_IF_GET_ADC_SPI_FREQ,
    CUK_HW_IF_END
}cukHwIfCommands_t;

//=============================================================================

//=============================================================================
/*-------------------------------- Functions --------------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
int32_t cukHwIfInitialize(void);
//-----------------------------------------------------------------------------
int32_t cukHwIf(void *in, uint32_t insize, void **out, uint32_t maxoutsize);
//-----------------------------------------------------------------------------
//=============================================================================

#endif /* CUK_HW_IF_H_ */