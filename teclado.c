
#include "config.h"
#include "delay.h"
#include "dispLCD4vias.h"
#include <xc.h>


#define L1 PORTBbits.RB0
#define L2 PORTBbits.RB1
#define L3 PORTBbits.RB2
#define L4 PORTBbits.RB3

#define C1 PORTBbits.RB4
#define C2 PORTBbits.RB5
#define C3 PORTBbits.RB6
#define C4 PORTBbits.RB7

#define MASK 0x10



void teclado_init(void)
{
    ANSELH = 0;   
    TRISB = 0xF0;
    PORTB = 0;
  
}

char tabela[2][4] = {{'1','2','3','A'},
                    {'4','5','6','B'}};

char teclado_scan( void )
{

    char tecla = 0;    
    char i;
    PORTB = 0x01;
     for( i=0; i<4; i++ )
    { if( PORTB & MASK<<i ) tecla = tabela [0][i]; }
    
    PORTB = 0x02;
     for( i=0; i<4; i++ )
    { if( PORTB & MASK<<i ) tecla = tabela [1][i]; }
    
    return(tecla);
}