/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Program: Test
 * File: Test.c
 * Author: Petr Fišer
 * Created: June 23, 2013
 ********************************************************************
 * Implementation of program Test
 ********************************************************************/

#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif

void _INIT TestINIT( void )
{
	pulsePeriod = 10 * 1000; // 10 sek.
    tarifPeriod = 15 * 60 * 1000; // 15 min.
}

void _CYCLIC TestCYCLIC( void )
{
    doPulse = 0;
    doTarif = 0;
    
	timer += 10;
    if (timer >= pulsePeriod)
    {
        timer = 0;
        pulseDelay = 500;
    }
        
    if (pulseDelay > 0)
    {
        pulseDelay -= 10;
        doPulse = 1;
    }
    
    tarifTimer += 10;
    if (tarifTimer >= tarifPeriod)
    {
        tarifTimer = 0;
        tarifDelay = 500;
    }
    
    if (tarifDelay > 0)
    {
        tarifDelay -= 10;
        doTarif = 1;
    }
}
