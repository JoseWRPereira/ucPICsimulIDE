/*
 * File:   main.c
 * Author: josewrpereira
 *
 * Created on 15 April 2021, 22:19
 * 
 * IDE:                 MPLAB X IDE v5.45
 * Compiler:            XC8 v2.31
 * Operating System:    Debian GNU/Linux bullseye/sid
 * Kernel:              Linux 5.10.0-5-amd64
 * Architecture:        x86-64
 * 
 * Objetivo: 
 *      Simular um sem�foro de ve�culos e de pedestre, 
 *      incluindo o bot�o para bloqueio da via e libera��o da atravessia aos pedestres.
 * 
 * 
 * Pinos    |n�     |Conex�o
 *  VDD     |11,32  | Alimenta��o (Vcc/+5V)
 *  VSS     |12,31  | Alimenta��o (GND/0V)
 *  RD7     |30     | LED Vermelho Ve�culos (source)
 *  RD6     |29     | LED Amarelo Ve�culos (source)
 *  RD5     |28     | LED Verde Ve�culos (source)
 *  RD3     |22     | LED Vermelho Pedestres(source)
 *  RD2     |21     | LED Verde Pedestres(source)
 *  RD0     |19     | Bot�o punsador (pullDown)
 * 
 */

#include "config.h"
#include <xc.h>

#define _XTAL_FREQ  4000000

#define SEMAFORO_VERMELHO   PORTDbits.RD7
#define SEMAFORO_AMARELO    PORTDbits.RD6
#define SEMAFORO_VERDE      PORTDbits.RD5

#define TEMPO_SEMAFORO_VERMELHO 5000
#define TEMPO_SEMAFORO_AMARELO  1000
#define TEMPO_SEMAFORO_VERDE    4000

void semaforo_init( void )
{
        // Configura��o dos pinos
    TRISDbits.TRISD7 = 0;
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD5 = 0;
        // Inicializa��o do estado dos LEDs
    SEMAFORO_VERMELHO = 0;
    SEMAFORO_AMARELO = 0;
    SEMAFORO_VERDE = 0;
}

void semaforo_vermelho( void )
{
    SEMAFORO_VERMELHO = 1;
    __delay_ms( TEMPO_SEMAFORO_VERMELHO );
    SEMAFORO_VERMELHO = 0;
}

void semaforo_verde( void )
{
    SEMAFORO_VERDE = 1;
    __delay_ms( TEMPO_SEMAFORO_VERDE );
    SEMAFORO_VERDE = 0;
}

void semaforo_amarelo( void )
{
    SEMAFORO_AMARELO = 1;
    __delay_ms( TEMPO_SEMAFORO_AMARELO );
    SEMAFORO_AMARELO = 0;
}

void main(void)
{
    semaforo_init();
    while( 1 )
    {
        semaforo_vermelho();
        semaforo_verde();
        semaforo_amarelo();
    }
}
