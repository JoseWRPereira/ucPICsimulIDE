/*
 * File:   fmm.c (Filtro de Media Móvel)
 * Author: josewrpereira
 *
 * Created on 1 de Julho de 2021, 14:26
 */


#include <xc.h>
#include "fmm.h"

char fmm_vetor[FMM_VETOR_SIZE];
char fmm_i = 0;
long fmm_somatoria = 0;

void FMM_inserir( char d )
{
    fmm_somatoria -= fmm_vetor[fmm_i];
    fmm_vetor[fmm_i] = d;
    ++fmm_i;
    fmm_i %= FMM_VETOR_SIZE;
    fmm_somatoria += d;
}


int FMM_media( void )
{
    return( (int)(fmm_somatoria / FMM_VETOR_SIZE) );
}
