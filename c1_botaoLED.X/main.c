/*
 * File:   main.c
 * Author: josewrpereira
 *
 * Created on 13 April 2021, 21:45
 * 
 * IDE:                 MPLAB X IDE v5.45
 * Compiler:            XC8 v2.31
 * Operating System:    Debian GNU/Linux bullseye/sid
 * Kernel:              Linux 5.10.0-5-amd64
 * Architecture:        x86-64
 * 
 * Objetivo: 
 *      Acionar o LED em fun��o do bot�o
 * 
 * Pinos    |n�     |Conex�o
 *  VDD     |11,32  | Alimenta��o (Vcc/+5V)
 *  VSS     |12,31  | Alimenta��o (GND/0V)
 *  RD0     |19     | LED   (source)
 *  RD3     |22     | BOTAO (pullDown)
 */


#include "config.h"             // Inclui diretivas de configura��o do uC
#include <xc.h>                 // Inclui biblioteca padr�o do compilador XC8 
                                // para microcontroladores Microchip.

void main(void)                 // Fun��o principal = main.
{                               // In�cio do escopo da fun��o main.
    PORTDbits.RD0 = 0;          // Inicia RD0 com o valor 0.
    TRISDbits.TRISD0 = 0;       // Configura RD0 como Sa�da.
    TRISDbits.TRISD3 = 1;       // Configura RD3 como Entrada;
                                // N�o precisa inicializa��o do valor do pino.

    while( 1 )                  // La�o de repeti��o infinito.
    {                           // Inicio do escopo do la�o de repeti��o.
        if( PORTDbits.RD3 == 1 )// Condi��o: Se o bot�o estiver pressionado.
            PORTDbits.RD0 = 1;  // Liga RD0.
        else                    // Sen�o.
            PORTDbits.RD0 = 0;  // Desliga RD0.
    }                           // Fim do escopo do la�o de repeti��o.
    return;                     // Caracteriza main como uma fun��o sem retorno.
}                               // Fim do escopo da fun��o main.
