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
 *    19  | RD0 | 
 *    20  | RD1 | 
 *    21  | RD2 | LCD_RS
 *    22  | RD3 | LCD_EN
 *    23  | RC4 | 
 *    24  | RC5 | 
 *    25  | RC6 | 
 *    26  | RC7 | 
 *    27  | RD4 | LCD_D4
 *    28  | RD5 | LCD_D5
 *    29  | RD6 | LCD_D6
 *    30  | RD7 | LCD_D7
 *    31  | VSS | 
 *    32  | VDD | 
 *    33  | RB0 | Keyb_L0
 *    34  | RB1 | Keyb_L1
 *    35  | RB2 | Keyb_L2
 *    36  | RB3 | Keyb_L3
 *    37  | RB4 | Keyb_C0
 *    38  | RB5 | Keyb_C1
 *    39  | RB6 | Keyb_C2
 *    40  | RB7 | Keyb_C3
 * -------------------------------------------------
 * -------------------------------------------------
 */


#include "config.h"
#include <xc.h>
#include "delay.h"
#include "lcd.h"
#include "keyboard.h"

void main(void)
{
    int tela = 0;
    int n = 1;
    int n_1 = 0;
    int n_2 = 0;
    char tecla;
    char string[17] = " Tecla:         ";
    
    dispLCD_init();
    keyboard_init();

    while( 1 )
    {
        tecla = keyboard();
        if( tecla )
            string[8] = tecla;
        else
            string[8] = ' ';
        
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
                    
            case 3: dispLCD(0,0, string ); 
                    dispLCD(1,0," #: Fibonacci   "); 
                    if( tecla == '#' )
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
                    if( n < 0 )
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
