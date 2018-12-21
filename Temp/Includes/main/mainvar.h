/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1509356201_1_
#define _BUR_1509356201_1_

#include <bur/plctypes.h>

/* Constants */
#ifdef _REPLACE_CONST
 #define MAX_HISTORY_LIST 95U
#else
 _IEC_CONST unsigned short MAX_HISTORY_LIST = 95U;
#endif


/* Variables */
_LOCAL signed long trigger2Delay;
_LOCAL signed long trigger1Delay;
_LOCAL plcbit doTrigger2Light;
_LOCAL plcbit doTrigger1Light;
_LOCAL plcbit doTrigger2Sound;
_LOCAL plcbit doTrigger1Sound;
_LOCAL float tarifFactor;
_LOCAL plcbit trigTarif;
_LOCAL plcbit diAlarm2Reset;
_LOCAL plcbit diAlarm1Reset;
_LOCAL plcbit diTarif;
_LOCAL plcbit reset;
_LOCAL struct DTGetTime fbGetTime;
_LOCAL unsigned short historyListNextItemIndex;
_LOCAL struct HistoryItem_typ historyList[96];
_LOCAL float cycleTime;
_LOCAL struct RTInfo fbRTInfo;
_LOCAL plctime tmpPeriod;
_LOCAL struct MeasurementProcess_typ reactivePowerProcess;
_LOCAL struct MeasurementProcess_typ realPowerProcess;





__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Main/Main.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/astime/astime.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/brsystem/brsystem.fun\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1509356201_1_ */

