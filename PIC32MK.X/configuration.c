
#include "configuration.h"

// <editor-fold defaultstate="collapsed" desc="PIC32MK0512MCF064 configuration bits">

// DEVCFG3
#pragma config USERID = 0xFFFF          // Enter Hexadecimal value (Enter Hexadecimal value)
#pragma config PWMLOCK = OFF            // PWM IOxCON lock (PWM IOxCON register writes accesses are not locked or protected)
#pragma config FUSBIDIO2 = ON           // USB2 USBID Selection (USBID pin is controlled by the USB2 module)
#pragma config FVBUSIO2 = ON            // USB2 VBUSON Selection bit (VBUSON pin is controlled by the USB2 module)
#pragma config PGL1WAY = ON             // Permission Group Lock One Way Configuration bit (Allow only one reconfiguration)
#pragma config PMDL1WAY = ON            // Peripheral Module Disable Configuration (Allow only one reconfiguration)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow only one reconfiguration)
#pragma config FUSBIDIO1 = ON           // USB1 USBID Selection (USBID pin is controlled by the USB1 module)
#pragma config FVBUSIO1 = ON            // USB2 VBUSON Selection bit (VBUSON pin is controlled by the USB1 module)

// DEVCFG2
#pragma config FPLLIDIV = DIV_8         // System PLL Input Divider (8x Divider)
#pragma config FPLLRNG = RANGE_54_64_MHZ// System PLL Input Range (54-64 MHz Input)
#pragma config FPLLICLK = PLL_FRC       // System PLL Input Clock Selection (FRC is input to the System PLL)
#pragma config FPLLMULT = MUL_128       // System PLL Multiplier (PLL Multiply by 128)
#pragma config FPLLODIV = DIV_32        // System PLL Output Clock Divider (32x Divider)
#pragma config VBATBOREN = ON           // VBAT BOR Enable (Enable ZPBOR during VBAT Mode)
#pragma config DSBOREN = ON             // Deep Sleep BOR Enable (Enable ZPBOR during Deep Sleep Mode)
#pragma config DSWDTPS = DSPS32         // Deep Sleep Watchdog Timer Postscaler (1:2^36)
#pragma config DSWDTOSC = LPRC          // Deep Sleep WDT Reference Clock Selection (Select LPRC as DSWDT Reference clock)
#pragma config DSWDTEN = ON             // Deep Sleep Watchdog Timer Enable (Enable DSWDT during Deep Sleep Mode)
#pragma config FDSEN = ON               // Deep Sleep Enable (Enable DSEN bit in DSCON)
#pragma config BORSEL = HIGH            // Brown-out trip voltage (BOR trip voltage 2.1v (Non-OPAMP deviced operation))
#pragma config UPLLEN = OFF             // USB PLL Enable (USB PLL Disabled)

// DEVCFG1
#pragma config FNOSC = LPRC             // Oscillator Selection Bits (Low Power RC Osc (LPRC))
#pragma config DMTINTV = WIN_127_128    // DMT Count Window Interval (Window/Interval value is 127/128 counter value)
#pragma config FSOSCEN = ON             // Secondary Oscillator Enable (Enable Secondary Oscillator)
#pragma config IESO = ON                // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = OFF            // Primary Oscillator Configuration (Primary osc disabled)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FCKSM = CSECME           // Clock Switching and Monitor Selection (Clock Switch Enabled, FSCM Enabled)
#pragma config WDTPS = PS1048576        // Watchdog Timer Postscaler (1:1048576)
#pragma config WDTSPGM = STOP           // Watchdog Timer Stop During Flash Programming (WDT stops during Flash programming)
#pragma config WINDIS = NORMAL          // Watchdog Timer Window Mode (Watchdog Timer is in non-Window mode)
#pragma config FWDTEN = ON              // Watchdog Timer Enable (WDT Enabled)
#pragma config FWDTWINSZ = WINSZ_25     // Watchdog Timer Window Size (Window size is 25%)
#pragma config DMTCNT = DMT31           // Deadman Timer Count Selection (2^31 (2147483648))
#pragma config FDMTEN = ON              // Deadman Timer Enable (Deadman Timer is enabled)

// DEVCFG0
#pragma config DEBUG = OFF              // Background Debugger Enable (Debugger is disabled)
#pragma config JTAGEN = ON              // JTAG Enable (JTAG Port Enabled)
#pragma config ICESEL = ICS_PGx1        // ICE/ICD Comm Channel Select (Communicate on PGEC1/PGED1)
#pragma config TRCEN = ON               // Trace Enable (Trace features in the CPU are enabled)
#pragma config BOOTISA = MIPS32         // Boot ISA Selection (Boot code and Exception code is MIPS32)
#pragma config FSLEEP = OFF             // Flash Sleep Mode (Flash is powered down when the device is in Sleep mode)
#pragma config DBGPER = PG_ALL          // Debug Mode CPU Access Permission (Allow CPU access to all permission regions)
#pragma config SMCLR = MCLR_NORM        // Soft Master Clear Enable (MCLR pin generates a normal system Reset)
#pragma config SOSCGAIN = GAIN_2X       // Secondary Oscillator Gain Control bits (2x gain setting)
#pragma config SOSCBOOST = ON           // Secondary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config POSCGAIN = GAIN_LEVEL_3  // Primary Oscillator Gain Control bits (Gain Level 3 (highest))
#pragma config POSCBOOST = ON           // Primary Oscillator Boost Kick Start Enable bit (Boost the kick start of the oscillator)
#pragma config EJTAGBEN = NORMAL        // EJTAG Boot Enable (Normal EJTAG functionality)

// DEVCP
//#pragma config CP = OFF                 // Code Protect (Protection Disabled)

// SEQ
#pragma config TSEQ = 0xFFFF            // Boot Flash True Sequence Number (Enter Hexadecimal value)
#pragma config CSEQ = 0xFFFF            // Boot Flash Complement Sequence Number (Enter Hexadecimal value)

// </editor-fold>

void initPins() {
    // PWM mapping to right ports
    CFGCONbits.PWMAPIN2 = 1; // changes PWM2L to PWM8H at pin 63
    CFGCONbits.PWMAPIN3 = 1; // changes PWM3L to PWM9H at pin 61
    CFGCONbits.PWMAPIN4 = 1; // changes PWM4L to PWM10H at pin 1
    
    ANSELA = 0x0; // turn off analog function nof all analog A pins
    ANSELB = 0x0; // turn off analog function nof all analog B pins
    ANSELC = 0x0; // turn off analog function nof all analog C pins
 // ANSELD = 0x0; // turn off analog function nof all analog D pins, invalid for 64 pin devices 
    ANSELE = 0x0; // turn off analog function nof all analog E pins
 // ANSELF = 0x0; // turn off analog function nof all analog F pins, invalid for 64 pin devices
    
    // Tris
    PWM10_Pin = OUT;    // setting pin to output
    PWM4_Pin = OUT;     // setting pin to output
    C9_Pin = IN;        // gpio
    D8_Pin = IN;        // gpio
    E12_Pin = OUT;      // gpio
    E13_Pin = OUT;      // gpio
    E14_Pin = OUT;      // gpio

}

void initPWM() {
    PTCONbits.PTEN = 0;     // disable PWM module so that changes can be made
    PWMKEY = 1;             // unlocking IOCONx modules so changes can be made
    PTCONbits.PCLKDIV = 0b110;  // 000 -> divide by 1, 110 -> divide by 64, 111 -> divide by 128 and resolution is 128/FSYSCLK, setting clock divisor bits
    STCON = 0x0;            // setting secondary timer bits 
    
    //PTPER = (FSYSCLK / (FPWM * PCLKDIV<2:0> bits (PTCON<6:4)))
    PTPER = 37500 ; // Primary Master Time Base Period, minimum value is 0x008 and LSB of timer is 1 / FSYSCLK.
        
    STPER = 2000;   // setting secondary timer period
    SEVTCMP = 10;   
    SSEVTCMP = 10;
    
    
    // PWM 10 setup
    PWMCON10 = 0x0;
    IOCON10 = 0x0;
    IOCON10bits.PENH = 1;    // PWM4H output ownership pin, choosing PWM module control
    PDC10 = 1000;
    SDC10 = 500;
    // dead time
    DTR10 = 75;
    ALTDTR10 = 75;
    // trigger generator
    TRGCON10 = 0x0;
    TRIG10 = 0;
    STRIG10 = 0;
    // leading edge blanking
    LEBCON10 = 0x0;
    LEBDLY10 = 10;
    
    // IOCON 4 setup
    PWMCON4 = 0x0;
    IOCON4 = 0x0;
    IOCON4bits.PENH = 1;    // PWM4H output ownership pin, choosing PWM module control
    PDC4 = 1000;
    SDC4 = 500;
    // dead time
    DTR4 = 75;
    ALTDTR4 = 75;
    // trigger generator
    TRGCON4 = 0x0;
    TRIG4 = 0;
    STRIG4 = 0;
    // leading edge blanking
    LEBCON4 = 0x0;
    LEBDLY4 = 10;

    PWMKEY = 0;             // locking IOCON
    PTCONbits.PTEN = 1;     // PWM Module Enable, enable last
    E12 = 1;                // light up LED to indicate code has executed
}
