/*
 * File:   main.c
 * Author: josewrpereira
 *
 * Created on 15 de Agosto de 2020, 16:03:21
 *
 * -------------------------------------------------
 *  MAPA DE ENTRADAS E SAIDAS
 * -------------------------------------------------
 *  Pinos |PORT | Conexões
 * -------|-----|-----------------------------------
 *    1   | RE3 | 
 *    2   | RA0 | 
 *    3   | RA1 | 
 *    4   | RA2 | 
 *    5   | RA3 | 
 *    6   | RA4 | 
 *    7   | RA5 | 
 *    8   | RE0 | 
 *    9   | RE1 | 
 *    10  | RE2 | 
 *    11  | VDD | 
 *    12  | VSS | 
 *    13  | RA7 | 
 *    14  | RA6 | 
 *    15  | RC0 | 
 *    16  | RC1 | 
 *    17  | RC2 | 
 *    18  | RC3 | 
 *    19  | RD0 | LCD_D4
 *    20  | RD1 | LCD_D5
 *    21  | RD2 | LCD_D6
 *    22  | RD3 | LCD_D7
 *    23  | RC4 | 
 *    24  | RC5 | 
 *    25  | RC6 | 
 *    26  | RC7 | 
 *    27  | RD4 | LCD_RS
 *    28  | RD5 | LCD_EN
 *    29  | RD6 | LCD_B0
 *    30  | RD7 | LCD_B1
 *    31  | VSS | 
 *    32  | VDD | 
 *    33  | RB0 | 
 *    34  | RB1 | 
 *    35  | RB2 | 
 *    36  | RB3 | 
 *    37  | RB4 | 
 *    38  | RB5 | 
 *    39  | RB6 | 
 *    40  | RB7 | 
 * -------------------------------------------------
 * -------------------------------------------------
 */

#include "config.h"
#include <xc.h>
#include "delay.h"
#include "lcd.h"

void main(void)
{
    int tela = 0;
    int n = 1;
    int n_1 = 0;
    int n_2 = 0;
    dispLCD_init();

    while( 1 )
    {
        switch( tela )
        {
            case 0: dispLCD(0,0," Display LCD 4b "); 
                    tela = 1;
                    delay(1000);
                    break;
                    
            case 1: dispLCD(1,0,"  LCD HD44780   "); 
                    tela = 2;
                    delay(2000);
                    break;
                    
            case 2: dispLCD_clr();
                    tela = 3;
                    delay(500);
                    break;
                    
            case 3: dispLCD(0,0," Display LCD 4b ");
                    dispLCD(1,0," B1: Fibonacci  ");
                    if( dispLCD_B1() )
                        tela = 10;
                    break;

                    
            case 10:
                    dispLCD(0,0,"  Display LCD   "); 
                    dispLCD(1,0,"Fibonacci:      ");
                    n_2 = n_1 = 0;
                    n = 1;
                    tela = 11;
                    break;

            case 11:
                    n_2 = n_1;
                    n_1 = n;
                    n = n_1 + n_2;
                    if( n < 0 || dispLCD_B0())
                        tela = 0;
                    else
                        tela = 12;
                    break;

            case 12:
                    dispLCD_num(1,11, n, 5 ); 
                    tela = 11;
                    delay(1000);
                    break;
        }
   }
    return;
}
