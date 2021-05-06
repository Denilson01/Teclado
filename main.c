/*
 * File:   main.c
 * Author: 20185087
 *
 * Created on 5 de Maio de 2021, 14:03
 */

#include "config.h"
#include "delay.h"
#include "dispLCD4vias.h"
#include "teclado.h"
#include <xc.h>


void main(void)
{
    char str[] = "Tecla:        ";
        dispLCD_init();
        teclado_init();
        
         while( 1 )
    {
        str[7] = teclado_scan();
        if(str[7] == 0)
           str[7] = ' ';
           dispLCD(1,0,str);
        dispLCD(0,1, "Tertos project");
       
    }
    return;
}
