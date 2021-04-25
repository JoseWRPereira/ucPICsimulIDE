/*
 * File:   disp7seg.c
 * Author: josewrpereira
 *
 * Created on 24 April 2021, 20:52
 */


#include <xc.h>
#include "delay.h"

const char disp7seg_digitos[16] = 
{   0xFC, 0x60, 0xDA, 0xF2, 
    0x66, 0xB6, 0xBE, 0xE0, 
    0xFE, 0xF6, 0xEE, 0x3E, 
    0x9C, 0x7A, 0x9E, 0x8E
};

void disp7seg_init( void )
{
    ANSELH = 0;
    TRISB = 0;
    PORTB = 0;
}

void disp7seg( unsigned char num )
{
    PORTB = (num < 16) ? disp7seg_digitos[num] : 0;
}


