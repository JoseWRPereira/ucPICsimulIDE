#ifndef IHM_H
#define IHM_H

#include "lcd.h"

struct
{
    void (* init)(void);
    void (* print)( const char * str );
    void (* printpos)( unsigned char lin, unsigned char col, const char * str );
    void (* printv)(  unsigned char lin, unsigned char col, int num, unsigned char tam );
    void (* clr)( void );
    unsigned char (* B0)( void );
    unsigned char (* B1)( void );
} IHM = { dispLCD_init, dispLCDstr, dispLCD, dispLCD_num, dispLCD_clr, dispLCD_B0, dispLCD_B1 };


#endif
