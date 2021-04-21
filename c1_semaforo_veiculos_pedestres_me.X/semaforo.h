#ifndef SEMAFORO_H
#define SEMAFORO_H

#define VERMELHO    'R'
#define AMARELO     'Y'
#define VERDE       'G'

void semaforo_init( void );
char botao_pedestre( void );
void semaforo( unsigned char cor );

#endif
