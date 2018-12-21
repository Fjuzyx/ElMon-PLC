/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Program: Main
 * File: Main.c
 * Author: Petr Fišer
 * Created: June 01, 2013
 ********************************************************************
 * Implementation of program Main
 ********************************************************************/

#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT MainInit(void)
{
    fbRTInfo.enable = 1;
    RTInfo(&fbRTInfo);
    cycleTime = fbRTInfo.cycle_time / 1000;
    
	if (!gInitDone)
	{
		gInitDone = 1;
		gPowerFactor = 0.1;
		gTarifInterval = 15;
		gPowerLimit = 160; // kWh
		gTrigger1Value = 100; // kWh
		gTrigger1DeadTime = 60 * 1000; // 1min.
		gTrigger2Value = 100; // kWh
		gTrigger2DeadTime = 30 * 1000; // 1min.
	}
}

void _CYCLIC MainCyclic(void)
{
	tarifFactor = 60.0 / gTarifInterval;
	gPowerLimitInterval = gPowerLimit / tarifFactor;
	
    //
    // Vypocet realneho vykonu ------------------------------------------------
    //
    //
    //
    
	realPowerProcess.factor = gPowerFactor; // kWh/imp.
    realPowerProcess.impPerHour = 1 / realPowerProcess.factor;

    realPowerProcess.actualTime += cycleTime;
        
    if (realPowerProcess.diS0)
    {
        if (!realPowerProcess.trigS0)
        {
            realPowerProcess.trigS0 = 1;
    	    realPowerProcess.period = realPowerProcess.actualTime;
            realPowerProcess.sumPower += realPowerProcess.factor;
            realPowerProcess.impCount++;
            realPowerProcess.actualTime = 0;
        }
    }
    else
        realPowerProcess.trigS0 = 0;
        
    tmpPeriod = realPowerProcess.actualTime;
    if (tmpPeriod < realPowerProcess.period)
        tmpPeriod = realPowerProcess.period;
    if (tmpPeriod > 0.0 && realPowerProcess.factor > 0.0)
        realPowerProcess.actPower = 3600000 / (tmpPeriod * realPowerProcess.impPerHour);
    if (realPowerProcess.actPower > realPowerProcess.peak)
        realPowerProcess.peak = realPowerProcess.actPower;
        
        
    //
    // Vypocet jaloveho vykonu ------------------------------------------------
    //
    //
    //
    
	reactivePowerProcess.factor = gPowerFactor; // kWh/imp.
    reactivePowerProcess.impPerHour = 1 / reactivePowerProcess.factor;
    
    reactivePowerProcess.actualTime += cycleTime;
    
    if (reactivePowerProcess.diS0)
    {
        if (!reactivePowerProcess.trigS0)
        {
            reactivePowerProcess.trigS0 = 1;
            reactivePowerProcess.period = reactivePowerProcess.actualTime;
            reactivePowerProcess.sumPower += reactivePowerProcess.factor;
            reactivePowerProcess.impCount++;
            reactivePowerProcess.actualTime = 0;
        }
    }
    else
        reactivePowerProcess.trigS0 = 0;
        
    tmpPeriod = reactivePowerProcess.actualTime;
    if (tmpPeriod < reactivePowerProcess.period)
        tmpPeriod = reactivePowerProcess.period;
    if (tmpPeriod > 0.0 && reactivePowerProcess.factor > 0.0)
        reactivePowerProcess.actPower = 3600000 / (tmpPeriod * reactivePowerProcess.impPerHour);
    if (reactivePowerProcess.actPower > reactivePowerProcess.peak)
        reactivePowerProcess.peak = reactivePowerProcess.actPower;
    
        
    //
    // Tarifni impuls ---------------------------------------------------------
    //
    //
    //
    
    if (!diTarif)
    {
        if (!trigTarif)
        {
            trigTarif = 1;
            
            fbGetTime.enable = 1;
            DTGetTime(&fbGetTime);
            if (!fbGetTime.status)
            {
				gTarifTime = fbGetTime.DT1;
				
				// Uloz data do statistiky.
				if (historyListNextItemIndex > MAX_HISTORY_LIST)
					historyListNextItemIndex = 0;
				
                historyList[historyListNextItemIndex].DateTime = fbGetTime.DT1;
                historyList[historyListNextItemIndex].sumRealPower = realPowerProcess.sumPower * tarifFactor;
                historyList[historyListNextItemIndex].sumReactivePower = reactivePowerProcess.sumPower * tarifFactor;
                historyList[historyListNextItemIndex].realMax = realPowerProcess.peak;
                historyList[historyListNextItemIndex].reactiveMax = reactivePowerProcess.peak;
				
                historyListNextItemIndex++;
            }
			
            realPowerProcess.sumPower = 0;
            realPowerProcess.peak = 0;
            reactivePowerProcess.sumPower = 0;
            reactivePowerProcess.peak = 0;
        }
    }
    else
        trigTarif = 0;
        
        
    //
    // Reset mereni a historie ------------------------------------------------
    //
    //
    //
    
    if (reset)
    {
        reset = 0;
        realPowerProcess.impCount = 0;
        realPowerProcess.period = 0;
        realPowerProcess.sumPower = 0;
        
        reactivePowerProcess.impCount = 0;
        reactivePowerProcess.period = 0;
        reactivePowerProcess.sumPower = 0;
        
        memset(&historyList, 0, sizeof(historyList));
        historyListNextItemIndex = 0;
    }
    
    
    //
    // Hlidej hodnotu max. vykonu ---------------------------------------------
    //
    //
    //
    
    gActPower = realPowerProcess.actPower + reactivePowerProcess.actPower;
    gPeakPower = realPowerProcess.peak + reactivePowerProcess.peak;
	gPowerConsumed = realPowerProcess.sumPower + reactivePowerProcess.sumPower;
	
    
	// Hlidani 1 -----------------------------------------------------------------
    if (gActPower > gTrigger1Value)
    {
		if (trigger1Delay > 0)
			trigger1Delay -= cycleTime;
		else
			gTrigger1Alarm = 1;
    }
	else
	{
		trigger1Delay = (gTrigger1DeadTime * 1000);
		gTrigger1MuteActive = 0;
		gTrigger1Alarm = 0;
	}
        
	// Rucni potvrzeni alarmu tlacitkem.
	if (diAlarm1Reset)
		gTrigger1MuteActive = 1;
	
	doTrigger1Sound = !gTrigger1MuteActive && gTrigger1Alarm;
	doTrigger1Light = gTrigger1Alarm;
	
	
	// Hlidani 2 -----------------------------------------------------------------
	if (gActPower > gTrigger2Value)
	{
		if (trigger2Delay > 0)
			trigger2Delay -= cycleTime;
		else
			gTrigger2Alarm = 1;
	}
	else
	{
		trigger2Delay = (gTrigger2DeadTime * 1000);
		gTrigger2MuteActive = 0;
		gTrigger2Alarm = 0;
	}
        
	// Rucni potvrzeni alarmu tlacitkem.
	if (diAlarm2Reset)
		gTrigger2MuteActive = 1;
	
	doTrigger2Sound = !gTrigger2MuteActive && gTrigger2Alarm;
	doTrigger2Light = gTrigger2Alarm;
}
