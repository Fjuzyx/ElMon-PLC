
TYPE
	MeasurementProcess_typ : 	STRUCT 
		diS0 : BOOL;
		actualTime : TIME;
		period : TIME;
		factor : REAL;
		sumPower : REAL;
		actPower : REAL;
		trigS0 : BOOL;
		impCount : UDINT;
		impPerHour : REAL;
		peak : REAL;
	END_STRUCT;
	HistoryItem_typ : 	STRUCT 
		DateTime : DATE_AND_TIME;
		sumRealPower : REAL;
		sumReactivePower : REAL;
		realMax : REAL;
		reactiveMax : REAL;
	END_STRUCT;
END_TYPE
