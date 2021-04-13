/*
 * File:   main.c
 * Author: josewrpereira
 *
 * Created on 12 April 2021, 19:39
 * 
 * IDE:         MPLAB X IDE v5.45
 * Compiler:    XC8 v2.31
 * Operating System: Debian GNU/Linux bullseye/sid
 * Kernel: Linux 5.10.0-5-amd64
 * Architecture: x86-64
 * 
 * Objetivo: 
 *      Piscar o LED com intervalo de 500 ms
 * 
 * Pinos    |n�     |Conex�o
 *  VDD     |11,32  | Alimenta��o (Vcc/+5V)
 *  VSS     |12,31  | Alimenta��o (GND/0V)
 *  RD0     |19     | LED (source/sink)
 */

                                // Inclui diretivas de configura��o do uC
// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#include <xc.h>                 // Inclui biblioteca padr�o do compilador XC8 
                                // para microcontroladores Microchip.

#define _XTAL_FREQ 4000000      // Define frequ�ncia do oscilador em uso.

void main(void)                 // Fun��o principal = main.
{                               // In�cio do escopo da fun��o main.
    PORTDbits.RD0 = 0;          // Inicia RD0 com o valor 0.
    TRISDbits.TRISD0 = 0;       // Configura RD0 como Sa�da.
    
    while( 1 )                  // La�o de repeti��o infinito.
    {                           // Inicio do escopo do la�o de repeti��o.
        PORTDbits.RD0 = 1;      // Liga RD0.
        __delay_ms(500);        // Espera 500 ms.
        PORTDbits.RD0 = 0;      // Desliga RD0.
        __delay_ms(500);        // Espera 500 ms.
    }                           // Fim do escopo la�o de repeti��o.
    return;                     // Caracteriza main como uma fun��o sem retorno.
}                               // Fim do escopo da fun��o main.
