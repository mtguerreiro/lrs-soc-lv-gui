/*
 * pid.h
 *
 *  Created on: 11 de set de 2022
 *      Author: marco
 */

#ifndef PID_H_
#define PID_H_

//=============================================================================
/*-------------------------------- Includes ---------------------------------*/
//=============================================================================
#include "stdint.h"
//=============================================================================

//=============================================================================
/*------------------------------- Definitions -------------------------------*/
//=============================================================================
typedef struct pidConfig_t{
    float a1;
    float a2;
    float b0;
    float b1;
    float b2;

    uint32_t saturate;
    float umax;
    float umin;
}pidConfig_t;

typedef struct pid_t{
    float a1;
    float a2;
    float b0;
    float b1;
    float b2;

    float umax;
    float umin;
    uint32_t saturate;

    float u_1;
    float u_2;
    float e_1;
    float e_2;
}pid_t;
//=============================================================================

//=============================================================================
/*-------------------------------- Functions --------------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
void pidInitialize(pid_t *pid, pidConfig_t *params);
//-----------------------------------------------------------------------------
void pidSetParams(pid_t *pid, pidConfig_t *params);
//-----------------------------------------------------------------------------
void pidGetParams(pid_t *pid, pidConfig_t *params);
//-----------------------------------------------------------------------------
float pidRun(pid_t *pid, float e);
//-----------------------------------------------------------------------------
//=============================================================================

#endif /* PID_H_ */