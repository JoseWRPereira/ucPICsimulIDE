/*
 * File:   stepMotor.c
 * Author: josewrpereira
 *
 * Created on 28 de Maio de 2021, 12:42
 */


#include <xc.h>


void StepMotor_init( void )
{
    ANSELH = 0; // ??
    TRISBbits.TRISB0 = 0;
    TRISBbits.TRISB1 = 0;
    TRISBbits.TRISB2 = 0;
    TRISBbits.TRISB3 = 0;
    PORTBbits.RB0 = 0;
    PORTBbits.RB1 = 0;
    PORTBbits.RB2 = 0;
    PORTBbits.RB3 = 0;
}
