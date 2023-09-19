/*
 * @file zynqAxiPwm.h
 *
 */

#ifndef ZYNQ_AXI_PWM_H_
#define ZYNQ_AXI_PWM_H_

//=============================================================================
/*-------------------------------- Includes ---------------------------------*/
//=============================================================================
#include "stdint.h"
#include "stddef.h"

//=============================================================================

//=============================================================================
/*------------------------------- Definitions -------------------------------*/
//=============================================================================
#define ZYNQ_AXI_PWM_RESET_OFS                  0
#define ZYNQ_AXI_PWM_RESET_MASK                 (1 << ZYNQ_AXI_PWM_RESET_OFS)

#define ZYNQ_AXI_PWM_OUTPUT_ENABLE_OFS          1
#define ZYNQ_AXI_PWM_OUTPUT_ENABLE_MASK         (1 << ZYNQ_AXI_PWM_OUTPUT_ENABLE_OFS)

#define ZYNQ_AXI_PWM_OVF_TRIGGER_ENABLE_OFS     2
#define ZYNQ_AXI_PWM_OVF_TRIGGER_ENABLE_MASK    (1 << ZYNQ_AXI_PWM_OVF_TRIGGER_ENABLE_OFS)


//=============================================================================

//=============================================================================
/*-------------------------------- Functions --------------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
void zynqAxiPwmResetWrite(uint32_t pwmBase, uint32_t reset);
//-----------------------------------------------------------------------------
void zynqAxiPwmOutputEnableWrite(uint32_t pwmBase, uint32_t enable);
//-----------------------------------------------------------------------------
void zynqAxiPwmOvfTriggerEnableWrite(uint32_t pwmBase, uint32_t enable);
//-----------------------------------------------------------------------------
void zynqAxiPwmControlWrite(uint32_t pwmBase, uint32_t data);
//-----------------------------------------------------------------------------
uint32_t zynqAxiPwmControlRead(uint32_t pwmBase);
//-----------------------------------------------------------------------------
void zynqAxiPwmPeriodWrite(uint32_t pwmBase, uint32_t period);
//-----------------------------------------------------------------------------
uint32_t zynqAxiPwmPeriodRead(uint32_t pwmBase);
//-----------------------------------------------------------------------------
void zynqAxiPwmDutyWrite(uint32_t pwmBase, uint32_t duty);
//-----------------------------------------------------------------------------
uint32_t zynqAxiPwmDutyRead(uint32_t pwmBase);
//-----------------------------------------------------------------------------
void zynqAxiPwmDeadTimeWrite(uint32_t pwmBase, uint32_t deadtime);
//-----------------------------------------------------------------------------
uint32_t zynqAxiPwmDeadTimeRead(uint32_t pwmBase);
//-----------------------------------------------------------------------------
//=============================================================================

#endif /* ZYNQ_AXI_PWM_H_ */
