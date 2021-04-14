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
 *      Acionar o LED em função do botão
 * 
 * Pinos    |nº     |Conexão
 *  VDD     |11,32  | Alimentação (Vcc/+5V)
 *  VSS     |12,31  | Alimentação (GND/0V)
 *  RD0     |19     | LED   (source)
 *  RD3     |22     | BOTAO (pullDown)
 */


#include "config.h"             // Inclui diretivas de configuração do uC
#include <xc.h>                 // Inclui biblioteca padrão do compilador XC8 
                                // para microcontroladores Microchip.

void main(void)                 // Função principal = main.
{                               // Início do escopo da função main.
    PORTDbits.RD0 = 0;          // Inicia RD0 com o valor 0.
    TRISDbits.TRISD0 = 0;       // Configura RD0 como Saída.
    TRISDbits.TRISD3 = 1;       // Configura RD3 como Entrada;
                                // Não precisa inicialização do valor do pino.

    while( 1 )                  // Laço de repetição infinito.
    {                           // Inicio do escopo do laço de repetição.
        if( PORTDbits.RD3 == 1 )// Condição: Se o botão estiver pressionado.
            PORTDbits.RD0 = 1;  // Liga RD0.
        else                    // Senão.
            PORTDbits.RD0 = 0;  // Desliga RD0.
    }                           // Fim do escopo do laço de repetição.
    return;                     // Caracteriza main como uma função sem retorno.
}                               // Fim do escopo da função main.
