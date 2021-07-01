/*
 * File:   sensor.c
 * Author: josewrpereira
 *
 * Created on 24 de Junho de 2021, 13:51
 */


#include <xc.h>
#include "adc.h"
#include "sensor.h"


int tMin_C;
int tMax_C;

void sensor_init( int tmin, int tmax )
{
    ADC_init();
    tMin_C = tmin;
    tMax_C = tmax;
}

void temperatura( struct SensorTemperatura_t * ptr )
{
    long t = ADC_read();

    t *= (tMax_C - tMin_C);
    t >>= ADC_BIT_RESOLUTION;
    
    ptr->temp_C = (int)(t + tMin_C);
    ptr->temp_F = ((ptr->temp_C*9)/5)+32;
    ptr->temp_K = ptr->temp_C + 273;
}
