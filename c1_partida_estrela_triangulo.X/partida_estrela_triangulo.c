/*
 * File:   partida_estrela_triangulo.c
 * Author: josewrpereira
 *
 * Created on 20 April 2021, 20:45
 * 
 * pet : partida estrela triângulo
 */


#include <xc.h>

void pet_init( void )
{
    TRISDbits.TRISD7 = 0;
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD1 = 1;
    TRISDbits.TRISD0 = 1;
    
    PORTDbits.RD7 = 0;
    PORTDbits.RD6 = 0;
    PORTDbits.RD5 = 0;
}

void pet_k1_set( void )
{
    PORTDbits.RD5 = 1;
}

void pet_k1_reset( void )
{
    PORTDbits.RD5 = 0;
}

void pet_k2_set( void )
{
    PORTDbits.RD6 = 1;
}

void pet_k2_reset( void )
{
    PORTDbits.RD6 = 0;
}

void pet_k3_set( void )
{
    PORTDbits.RD7 = 1;
}

void pet_k3_reset( void )
{
    PORTDbits.RD7 = 0;
}


char pet_s1( void )
{
    return( !PORTDbits.RD1 );
}

char pet_s0( void )
{
    return( !PORTDbits.RD0 );
}
