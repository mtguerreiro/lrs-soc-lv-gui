/*
 * sysinit.h
 *
 *  Created on: 10.03.2023
 *      Author: Marco Guerreiro
 */

#ifndef TASKS_SYSINIT_H_
#define TASKS_SYSINIT_H_
//=============================================================================
/*-------------------------------- Includes ---------------------------------*/
//=============================================================================
#include <stdint.h>
//=============================================================================

//=============================================================================
/*--------------------------------- Defines ---------------------------------*/
//=============================================================================
/* Priority and stack size of this task */
#define SYSINIT_CONFIG_TASK_PRIO				2
#define SYSINIT_CONFIG_TASK_STACK_SIZE			1024

//=============================================================================

//=============================================================================
/*---------------------------------- Task -----------------------------------*/
//=============================================================================
void sysinit(void *param);
//=============================================================================

#endif /* TASKS_SYSINIT_H_ */
