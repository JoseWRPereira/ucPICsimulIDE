#ifndef LCD_H
#define LCD_H

void dispLCD_init( void );
void dispLCD( unsigned char lin, unsigned char col, const char * str );
void dispLCD_num(  unsigned char lin, unsigned char col,
                    int num, unsigned char tam );
void dispLCD_clr( void );
unsigned char dispLCD_B0( void );
unsigned char dispLCD_B1( void );

#endif
