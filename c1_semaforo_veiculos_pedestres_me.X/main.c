/*
 * File:   main.c
 * Author: josewrpereira
 *
 * Created on 20 April 2021, 20:42
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
 *      liberação da atravessia aos pedestres 
 *      utilizando Máquina de Estados.
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
#include "delay.h"

void main(void)
{
    char estado = 0;
    int tempo;
    semaforo_init();

    while( 1 )
    {
        switch( estado )
        {
            case 0:
                    semaforo( VERDE );
                    estado = 1;
                    break;
            case 1:
                    if( botao_pedestre() )
                        estado = 2;
                    break;
            case 2:
                    tempo = 2000;
                    estado = 3;
                    break;
            case 3:
                    delay(1);
                    --tempo;
                    if( tempo == 0 )
                        estado = 4;
                    break;
            case 4:
                    semaforo( AMARELO );
                    estado = 5;
                    break;
            case 5:
                    tempo = 3000;
                    estado = 6;
                    break;
            case 6:
                    delay(1);
                    --tempo;
                    if( tempo == 0 )
                        estado = 7;
                    break;
            case 7:
                    semaforo( VERMELHO );
                    estado = 8;
                    break;
            case 8:
                    tempo = 5000;
                    estado = 9;
                    break;
            case 9:
                    delay(1);
                    --tempo;
                    if( tempo == 0 )
                        estado = 0;
                    break;
        }
    }
}
