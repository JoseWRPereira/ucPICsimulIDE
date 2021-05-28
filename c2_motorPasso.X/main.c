/*
 * File:   main.c
 * Author: josewrpereira
 *
 * Created on 28 de Maio de 2021, 12:40:21
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
 *    33  | RB0 | MotorPasso_A+
 *    34  | RB1 | MotorPasso_B+
 *    35  | RB2 | MotorPasso_A-
 *    36  | RB3 | MotorPasso_B-
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
#include "stepMotor.h"

void main(void)
{
    int estado = 0;

    dispLCD_init();
    StepMotor_init();
    
    while( 1 )
    {
        switch( estado )
        {
            case 0: dispLCD(0,0," Step Motor "); 
                    estado = 1;
                    break;
            case 1:
                    break;
        }
   }
    return;
}
