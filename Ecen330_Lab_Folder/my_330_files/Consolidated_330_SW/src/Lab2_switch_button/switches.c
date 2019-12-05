/*
 * switches.c
 *
 *  Created on: May 11, 2017
 *      Author: clintrf
 */
#include <stdio.h>
#include "switches.h"
#include "supportFiles/leds.h"
#include "xil_io.h"
#include "xparameters.h"

#define GPIO_DATA_OFFSET 0x00 //offset for the GPIO_DATA register
#define GPIO_TRI_OFFSET 0x04 //offset for the GPIO_TRI register
#define GPIO_TRI_SET_INPUT 1 //start input
#define SWITCHES_ALL_SWITCHES_ON 0x0F
#define SWITCHES_ALL_SWITCHES_OFF 0x00
#define TRUE 1
#define FALSE 0

//**********Prototype_Functions**********
int32_t switches_readGpioRegister(int32_t offset);
void switches_writeGpioRegister(int32_t offset, int32_t value);

//**********Switches.h_Functions**********
int32_t switches_init(){// Initializes the SWITCHES driver software and hardware. Returns one of the STATUS values defined above.
    switches_writeGpioRegister(GPIO_TRI_OFFSET, GPIO_TRI_SET_INPUT);
    if(GPIO_TRI_SET_INPUT == switches_readGpioRegister(GPIO_DATA_OFFSET)){
        return SWITCHES_INIT_STATUS_OK; //register was updated
    }
    else{
        return SWITCHES_INIT_STATUS_FAIL;//register was not updated
    }
}

// Returns the current value of all 4 switches as the lower 4 bits of the returned value.
// bit3 = SW3, bit2 = SW2, bit1 = SW1, bit0 = SW0.
int32_t switches_read(){
    return switches_readGpioRegister(GPIO_DATA_OFFSET);
}

// Runs a test of the switches. As you slide the switches, LEDs directly above the switches will illuminate.
// The test will run until all switches are slid upwards. When all 4 slide switches are slid upward,
// this function will return.
void switches_runTest(){
    switches_init(); //initialize the switches
    int32_t SwitchesOn = switches_read(); //read in what switches are being slide
    while (TRUE){
        SwitchesOn = switches_read();//read in what switches are being slide
        leds_init(FALSE); //turn all switches off to start
        switch(SwitchesOn){ //checking for all switches to be on
        case (SWITCHES_ALL_SWITCHES_ON): //if all the switches are on enter case
                leds_write(SWITCHES_ALL_SWITCHES_OFF); // turn of all the leds and exit the program
        return;
        break;
        default: leds_write(SwitchesOn); //as long as not all the switches are on then continue writing to the board
        }
    }
}

//****************************Helper_Functions********************************

int32_t switches_readGpioRegister(int32_t offset){// Reads from the register
    //use the low-level Xilinx call.
    return Xil_In32(XPAR_SLIDE_SWITCHES_BASEADDR + offset);
}
void switches_writeGpioRegister(int32_t offset, int32_t value){// Writes to the register
    Xil_Out32(XPAR_SLIDE_SWITCHES_BASEADDR + offset, value);//use the low-level Xilinx call.
}

