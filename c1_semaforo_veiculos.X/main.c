/*
 * File:   main.c
 * Author: josewrpereira
 *
 * Created on 15 April 2021, 21:11
 * 
 * IDE:                 MPLAB X IDE v5.45
 * Compiler:            XC8 v2.31
 * Operating System:    Debian GNU/Linux bullseye/sid
 * Kernel:              Linux 5.10.0-5-amd64
 * Architecture:        x86-64
 * 
 * Objetivo: 
 *      Acionar 3 saídas simulando um semáforo com os respectivos tempos:
 *          Vermelha: 5s
 *          Verde: 4s
 *          Amarela: 1s
 * 
 * 
 * Pinos    |nº     |Conexão
 *  VDD     |11,32  | Alimentação (Vcc/+5V)
 *  VSS     |12,31  | Alimentação (GND/0V)
 *  RD7     |30     | LED Vermelho (source)
 *  RD6     |29     | LED Amarelo (source)
 *  RD5     |28     | LED Verde (source)
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
        // Configuração dos pinos
    TRISDbits.TRISD7 = 0;
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD5 = 0;
        // Inicialização do estado dos LEDs
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
