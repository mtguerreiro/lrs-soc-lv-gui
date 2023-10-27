/*
 * cukControlOL.c
 *
 *  Created on: 11.09.2023
 *      Author: marco
 */

#ifdef SOC_CPU1
//=============================================================================
/*-------------------------------- Includes ---------------------------------*/
//=============================================================================
#include "cukControlOL.h"

#include "ocpConfig.h"
#include "ocpTrace.h"

#include "cukConfig.h"
//#include "config/stypesCuk.h"
//=============================================================================

//=============================================================================
/*------------------------------- Definitions -------------------------------*/
//=============================================================================

//=============================================================================

//=============================================================================
/*--------------------------------- Globals ---------------------------------*/
//=============================================================================
static float u = 0.0f;
//=============================================================================

//=============================================================================
/*-------------------------------- Functions --------------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
void cukControlOLInitialize(void){

}
//-----------------------------------------------------------------------------
int32_t cukControlOLSetParams(void *params, uint32_t n){

    float *p = (float *)params;

    u = *p;

	return 0;
}
//-----------------------------------------------------------------------------
int32_t cukControlOLGetParams(void *in, uint32_t insize, void *out, uint32_t maxoutsize){

    float *p = (float *)out;

    *p = u;

    return 4;
}
//-----------------------------------------------------------------------------
int32_t cukControlOLRun(void *meas, int32_t nmeas, void *refs, int32_t nrefs, void *outputs, int32_t nmaxoutputs){

    cukConfigMeasurements_t *m = (cukConfigMeasurements_t *)meas;
    cukConfigReferences_t *r = (cukConfigReferences_t *)refs;
    cukConfigControl_t *o = (cukConfigControl_t *)outputs;

    o->u = u;

    return sizeof(cukConfigControl_t);
}
//-----------------------------------------------------------------------------
void cukControlOLReset(void){

    u = 0.0f;
}
//-----------------------------------------------------------------------------
//=============================================================================
#endif /* SOC_CPU1 */
