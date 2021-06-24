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


void main(void)
{
    struct SensorTemperatura_t sensor;
    IHM.init();
    sensor_init(-50,50);
    IHM.print("  C    K    F  ");
    while( 1 )
    {
        temperatura( &sensor );

        IHM.printv(1,  1, sensor.temp_C, 3 );
        IHM.printv(1,  5, sensor.temp_K, 3 );
        IHM.printv(1, 10, sensor.temp_F, 3 );
    }
}
