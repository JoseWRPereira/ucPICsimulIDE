/*
 * File:   main.c
 * Author: josewrpereira
 *
 * Created on 19 April 2021, 20:42
 * 
 * IDE:                 MPLAB X IDE v5.45
 * Compiler:            XC8 v2.31
 * Operating System:    Debian GNU/Linux bullseye/sid
 * Kernel:              Linux 5.10.0-5-amd64
 * Architecture:        x86-64
 * 
 * Objetivo: 
 *      Simular um sem�foro de ve�culos e de pedestre, 
 *      incluindo o bot�o para bloqueio da via e 
 *      libera��o da atravessia aos pedestres.
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
 *  RD0     |19     | Bot�o Pulsador Pedestres (pullDown)
 * 
 */

#include "config.h"
#include <xc.h>
#include "semaforo.h"

void main(void)
{
    semaforo_init();

    while( 1 )
    {
        semaforo( VERDE, 1 );

        if( botao_pedestre() == 1 )
        {
            semaforo( VERDE,    2000 );
            semaforo( AMARELO,  3000 );
            semaforo( VERMELHO, 5000 );
        }
    }
}
