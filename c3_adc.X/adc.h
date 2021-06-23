#ifndef ADC_H
#define ADC_H


/////////////////////////////////////// Configurações do ADC
#define FOSC_DIV_2      0x0
#define FOSC_DIV_8      0x1
#define FOSC_DIV_32     0x2
#define FRC             0x3

#define ADC_CH0         0x0
#define ADC_CH1         0x1
#define ADC_CH2         0x2
#define ADC_CH3         0x3
#define ADC_CH4         0x4
#define ADC_CH5         0x5
#define ADC_CH6         0x6
#define ADC_CH7         0x7
#define ADC_CH8         0x8
#define ADC_CH9         0x9
#define ADC_CH10        0xA
#define ADC_CH11        0xB
#define ADC_CH12        0xC
#define ADC_CH13        0xD
#define ADC_CVREF       0xE
#define ADC_FIXED_REF   0xF

#define ADC_FORMAT_RIGHT    1
#define ADC_FORMAT_LEFT     0

#define ADC_VREF_NEG_PIN    1
#define ADC_VREF_VSS        0
#define ADC_VREF_POS_PIN    1
#define ADC_VREF_VDD        0

/////////////////////////////////////// Funções do ADC
void ADC_init( void );
void ADC_int( void );
unsigned int ADC_read( void );


#endif
