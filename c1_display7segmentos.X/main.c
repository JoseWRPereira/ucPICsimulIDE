/*
 * File:   main.c
 * Author: josewrpereira
 *
 * Created on 24 April 2021, 20:45
 * 
 * IDE:                 MPLAB X IDE v5.45
 * Compiler:            XC8 v2.31
 * Operating System:    Debian GNU/Linux bullseye/sid
 * Kernel:              Linux 5.10.0-5-amd64
 * Architecture:        x86-64
 * 
 * Objetivo: 
 *      Exibir um contador de 0..F através de um display de 7 segmentos.
 * 
 * nº Pinos| PORT |Conexão
 *  11,32  | VDD  | Alimentação (Vcc/+5V)
 *  12,31  | VSS  | Alimentação (GND/0V)
 * 
 *  40     | RB7  | Segmento a (Catodo Comum)
 *  39     | RB6  | Segmento b
 *  38     | RB6  | Segmento c
 *  37     | RB6  | Segmento d
 *  36     | RB6  | Segmento e
 *  35     | RB6  | Segmento f
 *  34     | RB6  | Segmento g
 *  33     | RB6  | Ponto 
 * 
 */

#include "config.h"
#include <xc.h>
#include "delay.h"
#include "display7segmentos.h"

void main(void)
{
    char cont = 0;
    disp7seg_init();

    while( 1 )
    {
        disp7seg( cont );
        delay(500);
        cont = ++cont % 16;
    }
}
