/*
 * cukControlPch.c
 *
 *  Created on: 25.11.2023
 *      Author: marco
 */

#ifdef SOC_CPU1
//=============================================================================
/*-------------------------------- Includes ---------------------------------*/
//=============================================================================
#include "cukControlPch.h"

#include "ocpConfig.h"
#include "ocpTrace.h"

#include "cukConfig.h"
//#include "config/stypesCuk.h"
//=============================================================================

//=============================================================================
/*-------------------------------- Prototypes -------------------------------*/
//=============================================================================

//=============================================================================

//=============================================================================
/*------------------------------- Definitions -------------------------------*/
//=============================================================================
static float kj2 = 0.0f, kj3 = 0.0f, kr2 = 0.0f;
static float x2r = 0.0f, x3r = 0.0f;
//=============================================================================

//=============================================================================
/*--------------------------------- Globals ---------------------------------*/
//=============================================================================

//=============================================================================

//=============================================================================
/*-------------------------------- Functions --------------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
void cukControlPchInitialize(void){

}
//-----------------------------------------------------------------------------
int32_t cukControlPchSetParams(void *params, uint32_t n){

    float *p = (float *)params;

    kj2 = *p++;
    kj3 = *p++;
    kr2 = *p++;

	return 0;
}
//-----------------------------------------------------------------------------
int32_t cukControlPchGetParams(void *in, uint32_t insize, void *out, uint32_t maxoutsize){

    float *p = (float *)out;

    *p++ = kj2;
    *p++ = kj3;
    *p++ = kr2;

    return 12;
}
//-----------------------------------------------------------------------------
int32_t cukControlPchRun(void *meas, int32_t nmeas, void *refs, int32_t nrefs, void *outputs, int32_t nmaxoutputs){

    cukConfigMeasurements_t *m = (cukConfigMeasurements_t *)meas;
    cukConfigReferences_t *r = (cukConfigReferences_t *)refs;
    cukConfigControl_t *o = (cukConfigControl_t *)outputs;

    static float i2e, vcr, vce, voe;
    static float vc;
    static float u;

    vc = m->v_1 + (1.0f / CUK_CONFIG_TF_N2N1) * m->v_2;
    vcr = m->v_dc + (1.0f / CUK_CONFIG_TF_N2N1) * r->v_o;

    /* Errors */
    i2e = m->i_o - m->i_2;
    vce = vcr - vc;
    voe = r->v_o - m->v_dc_out;

    /* Control */
    u = (r->v_o + kj2 * voe + kr2 * i2e + kj3 * vce) / (vcr * CUK_CONFIG_TF_N2N1);

    if( u > 1.0f ) u = 1.0f;
    if( u < 0.0f ) u = 0.0f;

    o->u = u;

    return sizeof(cukConfigControl_t);
}
//-----------------------------------------------------------------------------
void cukControlPchReset(void){

}
//-----------------------------------------------------------------------------
//=============================================================================

#endif /* SOC_CPU1 */
