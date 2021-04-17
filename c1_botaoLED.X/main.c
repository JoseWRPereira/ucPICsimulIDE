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

#define LED     PORTDbits.RD0   // Definição ou "apelido", para o pino RD0
#define BOTAO   PORTDbits.RD3   // Definição ou "apelido", para o pino RD3

void main(void)                 // Função principal = main.
{                               // Início do escopo da função main.
    LED = 0;                    // Inicia LED apagado.
    TRISDbits.TRISD0 = 0;       // Configura RD0 como Saída.
    TRISDbits.TRISD3 = 1;       // Configura RD3 como Entrada;
                                // Não precisa inicialização do valor do pino.

    while( 1 )                  // Laço de repetição infinito.
    {                           // Inicio do escopo do laço de repetição.
        LED = BOTAO;            // O LED recebe o valor do BOTAO.
    }                           // Fim do escopo do laço de repetição.
    return;                     // Caracteriza main como uma função sem retorno.
}                               // Fim do escopo da função main.
