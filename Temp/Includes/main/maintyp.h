/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1372317399_3_
#define _BUR_1372317399_3_

#include <bur/plctypes.h>

/* Datatypes and datatypes of function blocks */
typedef struct MeasurementProcess_typ
{	plcbit diS0;
	plctime actualTime;
	plctime period;
	float factor;
	float sumPower;
	float actPower;
	plcbit trigS0;
	unsigned long impCount;
	float impPerHour;
	float peak;
} MeasurementProcess_typ;

typedef struct HistoryItem_typ
{	plcdt DateTime;
	float sumRealPower;
	float sumReactivePower;
	float realMax;
	float reactiveMax;
} HistoryItem_typ;






__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Main/Main.typ\\\" scope \\\"local\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1372317399_3_ */

