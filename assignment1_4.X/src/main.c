/* 
 * File:   main.c
 * Author: Roy Meijer
 *
 * Created on 6 March 2022, 21:02
 */

/* Generic C libraries */
#include <stdio.h>
#include <stdlib.h>

/* XC32 libraries */
#include <xc.h>
#include <sys/attribs.h>

/* Your own libraries */
#include "led.h"
#include "lcd.h"
#include "btn.h"
#include "assignment1_4.h"

/* Device Config Bits in DEVCFG1:  */
#pragma config FNOSC =      FRC
#pragma config FSOSCEN =	OFF
#pragma config POSCMOD =	XT
#pragma config OSCIOFNC =	ON
#pragma config FPBDIV =     DIV_1

/* Device Config Bits in  DEVCFG2: */
#pragma config FPLLIDIV =	DIV_2
#pragma config FPLLMUL =	MUL_20
#pragma config FPLLODIV =	DIV_1

#pragma config JTAGEN =     OFF     
#pragma config FWDTEN =     OFF  

int main() {
    //all intialization functions
    LED_Init();
    LCD_Init();
    BTN_Init();
    Timer1_Init();
    
    state CurrentState = S0;    //Initial state
    
    while(1) {
        StateOutput(CurrentState);
        CurrentState = SequenceDetector(CurrentState);
    }
    return (0);
}