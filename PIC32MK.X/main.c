/* 
 * File:   main.c
 * Author: jakka
 *
 * Created on February 10, 2020, 12:30 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "configuration.h"
#include "pinDefinitions.h"

int main(int argc, char** argv) {
    
    E12 = 0;
    E13 = 0;
    initPins();
    initPWM();

    while (1) {
//        E12 = 1;
//        E13 = 0;
//        if (C9 == 1) {
//            E12 = 0;
//            E13 = 1;
//            E14 = 0;
//        } else {
//            E12 = 1;
//            E13 = 0;
//            E14 = 0;
//        }
        if (PTCONbits.PWMRDY== 1) {
            E13 = 1;
        }
    }
    return (EXIT_SUCCESS);
}

