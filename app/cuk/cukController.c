/*
 * cukController.c
 *
 *  Created on: 11.09.2023
 *      Author: LRS
 */

#ifdef SOC_CPU1
//=============================================================================
/*-------------------------------- Includes ---------------------------------*/
//=============================================================================
#include "cukController.h"

#include "../utils/rp.h"

/* Controllers */
#include "cukControlOL.h"
#include "cukControlDisabled.h"

//=============================================================================

//=============================================================================
/*------------------------------- Definitions -------------------------------*/
//=============================================================================
typedef void(*controllerInit)(void);
typedef void(*controllerReset)(void);
typedef int32_t(*controllerSP)(void *in, uint32_t insize);
typedef int32_t(*controllerGP)(void *in, uint32_t insize, void *out, uint32_t maxoutsize);
typedef int32_t(*controllerR)(void *inputs, int32_t ninputs, void *outputs, int32_t nmaxoutputs);

typedef struct{
	rphandle_t handles[CUK_CONTROLLER_IF_END];
	rpctx_t rp;
}controllerIF_t;

typedef struct{

	controllerInit initialize[CUK_CONTROLLER_END];
	controllerSP setParams[CUK_CONTROLLER_END];
	controllerGP getParams[CUK_CONTROLLER_END];
	controllerR run[CUK_CONTROLLER_END];
	controllerReset reset[CUK_CONTROLLER_END];

	uint32_t active;

	controllerIF_t interface;

	cukControllerEnable_t enable;
	cukControllerDisable_t disable;

}controller_t;

static controller_t controllers = {.active = CUK_CONTROLLER_DISABLED};

//=============================================================================

//=============================================================================
/*-------------------------------- Prototypes -------------------------------*/
//=============================================================================
static int32_t cukControllerInterfaceGetController(void *in, uint32_t insize, void **out, uint32_t maxoutsize);
static int32_t cukControllerInterfaceSetController(void *in, uint32_t insize, void **out, uint32_t maxoutsize);
static int32_t cukControllerInterfaceGetControllerParams(void *in, uint32_t insize, void **out, uint32_t maxoutsize);
static int32_t cukControllerInterfaceSetControllerParams(void *in, uint32_t insize, void **out, uint32_t maxoutsize);
static int32_t cukControllerInterfaceReset(void *in, uint32_t insize, void **out, uint32_t maxoutsize);
//=============================================================================

//=============================================================================
/*-------------------------------- Functions --------------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
void cukControllerInitialize(cukControllerConfig_t *config){

	uint32_t k;

	controllers.enable = config->enable;
    controllers.disable = config->disable;

    if( controllers.disable != 0 ) controllers.disable();

	/* Initializes the request processor */
	rpInitialize(&controllers.interface.rp, CUK_CONTROLLER_IF_END, controllers.interface.handles);
	rpRegisterHandle(&controllers.interface.rp, CUK_CONTROLLER_IF_GET, cukControllerInterfaceGetController);
	rpRegisterHandle(&controllers.interface.rp, CUK_CONTROLLER_IF_SET, cukControllerInterfaceSetController);
	rpRegisterHandle(&controllers.interface.rp, CUK_CONTROLLER_IF_GET_PARAMS, cukControllerInterfaceGetControllerParams);
	rpRegisterHandle(&controllers.interface.rp, CUK_CONTROLLER_IF_SET_PARAMS, cukControllerInterfaceSetControllerParams);
    rpRegisterHandle(&controllers.interface.rp, CUK_CONTROLLER_IF_RESET, cukControllerInterfaceReset);

	/* Register the available controllers */
    controllers.initialize[CUK_CONTROLLER_DISABLED] = cukControlDisabledInitialize;
    controllers.setParams[CUK_CONTROLLER_DISABLED] = cukControlDisabledSetParams;
    controllers.getParams[CUK_CONTROLLER_DISABLED] = cukControlDisabledGetParams;
    controllers.run[CUK_CONTROLLER_DISABLED] = cukControlDisabledRun;
    controllers.reset[CUK_CONTROLLER_DISABLED] = cukControlDisabledReset;

    controllers.initialize[CUK_CONTROLLER_OL] = cukControlOLInitialize;
    controllers.setParams[CUK_CONTROLLER_OL] = cukControlOLSetParams;
    controllers.getParams[CUK_CONTROLLER_OL] = cukControlOLGetParams;
    controllers.run[CUK_CONTROLLER_OL] = cukControlOLRun;
    controllers.reset[CUK_CONTROLLER_OL] = cukControlOLReset;

	/* Initializes all registered controllers */
	for(k = 0; k < CUK_CONTROLLER_END; k++){
		controllers.initialize[k]();
	}
}
//-----------------------------------------------------------------------------
int32_t cukControllerInterface(void *in, uint32_t insize, void **out, uint32_t maxoutsize){

	int32_t status;

	status = rpRequest(&controllers.interface.rp, in, insize, out, maxoutsize);

	return status;
}
//-----------------------------------------------------------------------------
int32_t cukControllerRun(void *inputs, int32_t ninputs, void *outputs, int32_t nmaxoutputs){

	int32_t status = CUK_CONTROLLER_ERR_INACTIVE_CTL;
	uint32_t ctl = controllers.active;

	if( ctl < CUK_CONTROLLER_END ){
		status = controllers.run[ctl](inputs, ninputs, outputs, nmaxoutputs);
	}

	return status;
}
//-----------------------------------------------------------------------------
int32_t cukControllerStatus(void){

    return 0;
}
//-----------------------------------------------------------------------------
//=============================================================================

//=============================================================================
/*----------------------------- Static functions ----------------------------*/
//=============================================================================
//-----------------------------------------------------------------------------
static int32_t cukControllerInterfaceGetController(void *in, uint32_t insize, void **out, uint32_t maxoutsize){

	uint32_t *p;

	p = (uint32_t *)( *out );
	*p = controllers.active;

	return sizeof( controllers.active );
}
//-----------------------------------------------------------------------------
static int32_t cukControllerInterfaceSetController(void *in, uint32_t insize, void **out, uint32_t maxoutsize){

	uint32_t ctl;

	ctl = *( (uint32_t *) in );

	if( ctl >= CUK_CONTROLLER_END ) return CUK_CONTROLLER_ERR_INVALID_CTL;

	controllers.active = ctl;

	if( ctl == CUK_CONTROLLER_DISABLED ){
	    if( controllers.disable != 0 ) controllers.disable();
	}
	else{
	    if( controllers.enable != 0 ) controllers.enable();
	}


	return 0;
}
//-----------------------------------------------------------------------------
static int32_t cukControllerInterfaceGetControllerParams(void *in, uint32_t insize, void **out, uint32_t maxoutsize){

	uint32_t status;
	uint32_t *p;
	uint32_t ctl;

	p = (uint32_t *)in;
	ctl = *p++;

	if( ctl >= CUK_CONTROLLER_END ) return CUK_CONTROLLER_ERR_INVALID_CTL;

	status = controllers.getParams[ctl]((void *)p, insize, *out, maxoutsize);

	return status;
}
//-----------------------------------------------------------------------------
static int32_t cukControllerInterfaceSetControllerParams(void *in, uint32_t insize, void **out, uint32_t maxoutsize){

	uint32_t status;
	uint32_t *p;
	uint32_t ctl;

	p = (uint32_t *)in;
	ctl = *p++;

	if( ctl >= CUK_CONTROLLER_END ) return CUK_CONTROLLER_ERR_INVALID_CTL;

	status = controllers.setParams[ctl]((void *)p, insize - sizeof( ctl ) );

	return status;
}
//-----------------------------------------------------------------------------
static int32_t cukControllerInterfaceReset(void *in, uint32_t insize, void **out, uint32_t maxoutsize){

    uint32_t *p;
    uint32_t ctl;

    p = (uint32_t *)in;
    ctl = *p++;

    if( ctl >= CUK_CONTROLLER_END ) return CUK_CONTROLLER_ERR_INVALID_CTL;

    controllers.reset[ctl]();

    return 0;
}
//-----------------------------------------------------------------------------
//=============================================================================
#endif /* SOC_CPU1 */