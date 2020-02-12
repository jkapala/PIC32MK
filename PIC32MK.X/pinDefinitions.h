/* 
 * File:   pinDefinitions.h
 * Author: jakka
 *
 * Created on February 10, 2020, 12:33 AM
 */

#ifndef PINDEFINITIONS_H
#define	PINDEFINITIONS_H

// Tris Names
#define PWM10_Pin      TRISAbits.TRISA7
#define PWM4_Pin       TRISAbits.TRISA10
#define C9_Pin         TRISCbits.TRISC9
#define D8_Pin         TRISDbits.TRISD8
#define E12_Pin        TRISEbits.TRISE12
#define E13_Pin        TRISEbits.TRISE13
#define E14_Pin        TRISEbits.TRISE14

// Lat Names (output)
#define PWM10          LATAbits.LATA7
#define PWM4           LATAbits.LATA10
#define E12            LATEbits.LATE12
#define E13            LATEbits.LATE13
#define E14            LATEbits.LATE14

// Port Names (Input)
#define C9             PORTCbits.RC9
#define D8             PORTDbits.RD8

// Variable Names
#define ON 1
#define OFF 0

// Pin States
#define OUT 0
#define IN 1

#endif	/* PINDEFINITIONS_H */

