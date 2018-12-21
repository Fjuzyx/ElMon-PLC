/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1539796079_1_
#define _BUR_1539796079_1_

#include <bur/plctypes.h>

/* Constants */
#ifdef _REPLACE_CONST
#else
#endif


/* Variables */
_GLOBAL plcdt gTarifTime;
_GLOBAL float gPowerLimitInterval;
_GLOBAL float gPowerConsumed;
_GLOBAL float gPeakPower;
_GLOBAL float gActPower;
_GLOBAL plcbit gTrigger2Alarm;
_GLOBAL plcbit gTrigger1Alarm;
_GLOBAL plcbit gTrigger2MuteActive;
_GLOBAL plcbit gTrigger1MuteActive;
_GLOBAL signed long gTrigger2DeadTime;
_GLOBAL signed long gTrigger1DeadTime;
_GLOBAL signed short gTrigger2Value;
_GLOBAL signed short gTrigger1Value;
_GLOBAL signed short gTarifInterval;
_GLOBAL float gPowerLimit;
_GLOBAL float gPowerFactor;
_GLOBAL plcbit gInitDone;





__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Global.var\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1539796079_1_ */

