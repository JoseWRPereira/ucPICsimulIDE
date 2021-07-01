/*
 * File:   main.c
 * Author: josewrpereira
 *
 * Created on 24 de Junho de 2021, 12:35
 */

#include "config.h"
#include <xc.h>
#include "delay.h"
#include "ihm.h"
#include "timers.h"
#include "sensor.h"
#include "fmm.h"


void main(void)
{
    struct SensorTemperatura_t sensor;
    IHM.init();

    sensor_init(-50,50);
    IHM.print(" Temp.    C     ");
    dispLCD_putChar(0, 9,0xDF);
//    dispLCD_putChar(0, 9,0x0);
    while( 1 )
    {
        temperatura( &sensor );
        FMM_inserir( (char)sensor.temp_C );
        IHM.printv(0, 7, FMM_media(), 3 );
    }
}
