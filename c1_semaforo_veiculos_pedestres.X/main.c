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
 *      Simular um semáforo de veículos e de pedestre, 
 *      incluindo o botão para bloqueio da via e 
 *      liberação da atravessia aos pedestres.
 * 
 * 
 * Pinos    |nº     |Conexão
 *  VDD     |11,32  | Alimentação (Vcc/+5V)
 *  VSS     |12,31  | Alimentação (GND/0V)
 *  RD7     |30     | LED Vermelho Veículos (source)
 *  RD6     |29     | LED Amarelo Veículos (source)
 *  RD5     |28     | LED Verde Veículos (source)
 *  RD3     |22     | LED Vermelho Pedestres(source)
 *  RD2     |21     | LED Verde Pedestres(source)
 *  RD0     |19     | Botão Pulsador Pedestres (pullDown)
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
