/*
 * File:   main.c
 * Author: josewrpereira
 *
 * Created on 3 de Junho de 2021, 12:38
 */

#include "config.h"
#include <xc.h>
#include "ihm.h"
#include "timers.h"

void main(void)
{
    IHM.init();

    T0_init();
    T1_init();
    T2_init(); 

    IHM.print(" T0    T1    T2 ");
    T0_start(30000);
    T1_start(20000);
    T2_start(15000);

    while( 1 )
    {
        if( IHM.B0() ) 
        {
            T0_pause();
            T1_pause();
            T2_pause();
        }
        if( IHM.B1() )
        {
            T0_play();
            T1_play();
            T2_play();
        }   
        IHM.printv(1,0, (signed)T0_status(), 5);
        IHM.printv(1,6, (signed)T1_status(), 5);
        IHM.printv(1,12,(signed)T2_status(), 5);
    }
}
