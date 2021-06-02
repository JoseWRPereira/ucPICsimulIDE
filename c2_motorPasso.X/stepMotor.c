/*
 * File:   stepMotor.c
 * Author: josewrpereira
 *
 * Created on 28 de Maio de 2021, 12:42
 */


#include <xc.h>
#include "delay.h"
#include "stepMotor.h"

char            passo;
unsigned char   motor[8] = {0x04, 0x06, 0x02, 0x03, 0x01, 0x09, 0x08, 0x0C};
unsigned int    ppr;
unsigned long   contador_passos;

struct motorpasso_t
{
    unsigned char bobinas:4;
};
volatile struct motorpasso_t motorPasso __at(0x006);

void StepMotor_init( unsigned int pulsosPorRevolucao )
{
    ANSELHbits.ANS12 = 0;   TRISBbits.TRISB0 = 0;   PORTBbits.RB0 = 0;
    ANSELHbits.ANS10 = 0;   TRISBbits.TRISB1 = 0;   PORTBbits.RB1 = 0;
    ANSELHbits.ANS8  = 0;   TRISBbits.TRISB2 = 0;   PORTBbits.RB2 = 0;
    ANSELHbits.ANS9  = 0;   TRISBbits.TRISB3 = 0;   PORTBbits.RB3 = 0;

    ppr = pulsosPorRevolucao;
    contador_passos = 0;
    passo = 0;
    motorPasso.bobinas = motor[passo];
}

//void step_cw( void )
//{
//    passo = (passo + 2) % 8;
//    motorPasso.bobinas = motor[passo];
//}
//
//void step_ccw( void )
//{
//    passo = (passo - 2) % 8;
//    motorPasso.bobinas = motor[passo];
//}
//
//void halfstep_cw( void )
//{
//    passo = (passo + 1) % 8;
//    motorPasso.bobinas = motor[passo];
//}
//
//void halfstep_ccw( void )
//{
//    passo = (passo - 1) % 8;
//    motorPasso.bobinas = motor[passo];
//}

void StepMotor(unsigned long qtd_graus_passos,
               unsigned char unidade, 
               unsigned char sentido,
               unsigned char meio_passo,
               unsigned int t )
{
    char passo_sentido = 2; // Full Step, horário
    
    if( unidade == DEGREES )
        contador_passos = (qtd_graus_passos * ppr) / 360;
    else
        contador_passos = qtd_graus_passos;
    
    if( meio_passo == HALF_STEP )
    {
        contador_passos *= 2;
        passo_sentido = 1;
    }
    
    if( sentido == CCW )
        passo_sentido *= -1;
    
    while( contador_passos )
    {
        passo = (passo + passo_sentido) % 8;
        motorPasso.bobinas = motor[passo];
        --contador_passos;
        delay( t );
    }
}

