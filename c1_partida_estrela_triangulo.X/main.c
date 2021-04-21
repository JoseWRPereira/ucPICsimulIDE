/*
 * File:   main.c
 * Author: josewrpereira
 *
 * Created on 20 April 2021, 20:28
 * 
 * IDE:                 MPLAB X IDE v5.45
 * Compiler:            XC8 v2.31
 * Operating System:    Debian GNU/Linux bullseye/sid
 * Kernel:              Linux 5.10.0-5-amd64
 * Architecture:        x86-64
 * 
 * Objetivo: 
 *      Simular uma partida estrela/tri�ngulo de motor trif�sico.
 * 
 * n� Pinos| PORT |Conex�o
 *  11,32  | VDD  | Alimenta��o (Vcc/+5V)
 *  12,31  | VSS  | Alimenta��o (GND/0V)
 * 
 *  30     | RD7  | Contator K1: Comum (source)
 *  29     | RD6  | Contator K2: Tri�ngulo (source)
 *  28     | RD5  | Contator K3: Estrela (source)
 * 
 *  19     | RD0  | Bot�o Pulsador Desligar (pullUp)
 *  20     | RD1  | Bot�o Pulsador Ligar (pullUp)
 * 
 */

#include "config.h"
#include <xc.h>
#include "delay.h"
#include "partida_estrela_triangulo.h"

void main(void)
{
    char estado = 0;
    int tempo;
    
    pet_init();
    
    while( 1 )
    {
        switch( estado )
        {
            case 0:
                    pet_k3_reset();
                    pet_k2_reset();
                    pet_k1_reset();
                    estado = 1;
                    break;
            case 1:
                    if( pet_s1() )
                    {
                        estado = 2;
                    }
                    break;
            case 2:
                    pet_k1_set();
                    pet_k3_set();
                    tempo = 5000;
                    estado = 3;
                    break;
            case 3:
                    delay(1);
                    --tempo;
                    if( tempo == 0 )
                        estado = 4;
                    break;
            case 4:
                    pet_k3_reset();
                    pet_k2_set();
                    estado = 5;
                    break;
            case 5:
                    if( pet_s0() )
                        estado = 0;
                    break;
        }
    }
}
