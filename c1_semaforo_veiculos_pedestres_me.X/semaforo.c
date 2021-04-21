/*
 * File:   semaforo.c
 * Author: josewrpereira
 *
 * Created on 19 April 2021, 22:05
 */

#include <xc.h>
#include "semaforo.h"

void semaforo_init( void )
{
        // Configura��o dos pinos
    TRISDbits.TRISD7 = 0;   // Sa�da: Vermelho ve�culos
    TRISDbits.TRISD6 = 0;   // Sa�da: Amarelo ve�culos
    TRISDbits.TRISD5 = 0;   // Sa�da: Verde ve�culos
    TRISDbits.TRISD3 = 0;   // Sa�da: Vermelho pedestre
    TRISDbits.TRISD2 = 0;   // Sa�da: Verde pedestre
    TRISDbits.TRISD0 = 1;   // Entrada: Bot�o pedestre
    
        // Inicializa��o do estado dos LEDs
    PORTDbits.RD7 = 0;
    PORTDbits.RD6 = 0;
    PORTDbits.RD5 = 0;
    PORTDbits.RD3 = 0;
    PORTDbits.RD2 = 0;
}

char botao_pedestre( void )
{
    return( PORTDbits.RD0 );
}

void semaforo( unsigned char cor )
{
    PORTDbits.RD2 = 0;
    PORTDbits.RD3 = 0;
    PORTDbits.RD5 = 0;
    PORTDbits.RD6 = 0;
    PORTDbits.RD7 = 0;

    switch( cor )
    {
        case VERMELHO:
                    PORTDbits.RD7 = 1;
                    PORTDbits.RD2 = 1;
                    break;
        case AMARELO:
                    PORTDbits.RD6 = 1;
                    PORTDbits.RD3 = 1;
                    break;
        case VERDE:
                    PORTDbits.RD5 = 1;
                    PORTDbits.RD3 = 1;
                    break;
    }
}
