/*
 * File:   adc.c
 * Author: josewrpereira
 *
 * Created on 18 de Junho de 2021, 14:03
 */


#include <xc.h>
#include "adc.h"

void ADC_init( void )
{
    INTCONbits.GIE = 0;

    ANSELbits.ANS0 = 1;
    ADCON0bits.ADCS = FOSC_DIV_32;
    ADCON1bits.VCFG0 = ADC_VREF_VDD;
    ADCON1bits.VCFG1 = ADC_VREF_VSS;
    ADCON0bits.CHS = ADC_CH0;
    ADCON1bits.ADFM = ADC_FORMAT_RIGHT;
    ADCON0bits.ADON = 1;
    
    INTCONbits.PEIE = 1;
    PIE1bits.ADIE = 1;
    INTCONbits.GIE = 1;
    ADCON0bits.GO = 1;
}

unsigned int ADC_value = 0;
void ADC_int( void )
{
    ADC_value = ADRESH;
    ADC_value <<= 8;
    ADC_value += ADRESL;
    ADCON0bits.GO = 1;
}

unsigned int ADC_read( void )
{
    return( ADC_value );
}
