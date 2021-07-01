#ifndef SENSOR_H
#define SENSOR_H

struct SensorTemperatura_t
{
    int temp_C;
    int temp_K;
    int temp_F;
};

void sensor_init( int tmin, int tmax );
void temperatura( struct SensorTemperatura_t * ptr );

#endif
