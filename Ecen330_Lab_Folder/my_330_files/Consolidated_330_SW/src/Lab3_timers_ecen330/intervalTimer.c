/*
 * intervalTimer.c
 *
 *  Created on: May 15, 2017
 *      Author: clintrf
 */
#include "intervalTimer.h"
#include <xparameters.h>
#include "xil_io.h"

#define TCSR0_init_input 0x000          //set reg to 0
#define TCSR1_init_input 0b00000000000  //set reg2 to 0
#define TCSR_SET_CASC_BIT 0x800         //set the cascade bit to one
#define TCSR_START_ENT0_BIT 0x80        //set only the ent0 bit to 1
#define TCSR_STOP_ENT0_BIT 0x7f         //use as mask to set ent0 to 0

#define LOAD_CLEAR 0x000 // clear everything to 0
#define TCSR_LOAD 0b100000 // just enable the 5th bit where the load reg is

#define TCSR0_ADDER 0x00 //Read/Write 0x0 Control/Status Register 0
#define TLR0_ADDER 0x04 //Read/Write 0x0 Load Register 0
#define TCR0_ADDER 0x08 //Read 0x0 Timer/Counter Register 0
#define TCSR1_ADDER 0x10 //Read/Write 0x0 Control/Status Register 1
#define TLR1_ADDER 0x14 //Read/Write 0x0 Load Register 1
#define TCR1_ADDER 0x18 //Read 0x0 Timer/Counter Register 1

#define SHIFT_BITS 32





//**********Prototype_Functions**********
int32_t timer_0_read(int32_t offset); // define function read out from timer 0
int32_t timer_1_read(int32_t offset); // define function read out from timer 1
int32_t timer_2_read(int32_t offset); // define function read out from timer 2
void timer_0_write(int32_t offset, int32_t data); //  define function to write to timer 0
void timer_1_write(int32_t offset, int32_t data); // define function to write to timer 1
void timer_2_write(int32_t offset, int32_t data); // define function to write to timer 2

//**********Main_Functions**********
// You must initialize the timers before you use them.
// timerNumber indicates which timer should be initialized.
// returns INTERVAL_TIMER_STATUS_OK if successful, some other value otherwise.
intervalTimer_status_t intervalTimer_init(uint32_t timerNumber){
    switch (timerNumber){
    case INTERVAL_TIMER_TIMER_0:
        timer_0_write(TCSR0_ADDER, TCSR0_init_input); //write a 0 to the TCSR0 register.
        timer_0_write(TCSR1_ADDER, TCSR1_init_input); //write a 0 to the TCSR1 register.
        timer_0_write(TCSR0_ADDER, TCSR_SET_CASC_BIT); //set the CASC bit and clear the UDT0 bit in the TCSR0 register (cascade mode and up counting).
        return INTERVAL_TIMER_STATUS_OK;
    case INTERVAL_TIMER_TIMER_1:
        timer_1_write(TCSR0_ADDER, TCSR0_init_input); //write a 0 to the TCSR0 register.
        timer_1_write(TCSR1_ADDER, TCSR1_init_input); //write a 0 to the TCSR1 register.
        timer_1_write(TCSR0_ADDER, TCSR_SET_CASC_BIT); //set the CASC bit and clear the UDT0 bit in the TCSR0 register (cascade mode and up counting).
        return INTERVAL_TIMER_STATUS_OK;
    case INTERVAL_TIMER_TIMER_2:
        timer_2_write(TCSR0_ADDER, TCSR0_init_input); //write a 0 to the TCSR0 register.
        timer_2_write(TCSR1_ADDER, TCSR1_init_input); //write a 0 to the TCSR1 register.
        timer_2_write(TCSR0_ADDER, TCSR_SET_CASC_BIT); //set the CASC bit and clear the UDT0 bit in the TCSR0 register (cascade mode and up counting).
        return INTERVAL_TIMER_STATUS_OK;
    default:
        return INTERVAL_TIMER_STATUS_FAIL;
    }
};

// This is a convenience function that initializes all interval timers.
// Simply calls intervalTimer_init() on all timers.
// returns INTERVAL_TIMER_STATUS_OK if successful, some other value otherwise.
intervalTimer_status_t intervalTimer_initAll(){
    intervalTimer_init(INTERVAL_TIMER_TIMER_0); //init timer 0
    intervalTimer_init(INTERVAL_TIMER_TIMER_1); //init timer 1
    intervalTimer_init(INTERVAL_TIMER_TIMER_2); //init timer 2
    return INTERVAL_TIMER_STATUS_OK;
};

// This function starts the interval timer running.
// timerNumber indicates which timer should start running.
void intervalTimer_start(uint32_t timerNumber){
    switch(timerNumber){
    case INTERVAL_TIMER_TIMER_0:
        timer_0_write(TCSR0_ADDER, ( timer_0_read(TCSR0_ADDER) | TCSR_START_ENT0_BIT)); // write a 1 into the ENT0 bit in the TCSR0.
        break; // end start
    case INTERVAL_TIMER_TIMER_1:
        timer_1_write(TCSR0_ADDER, ( timer_1_read(TCSR0_ADDER) | TCSR_START_ENT0_BIT)); // write a 1 into the ENT0 bit in the TCSR0.
        break; // end start
    case INTERVAL_TIMER_TIMER_2:
        timer_2_write(TCSR0_ADDER, ( timer_2_read(TCSR0_ADDER) | TCSR_START_ENT0_BIT)); // write a 1 into the ENT0 bit in the TCSR0.
        break; // end start
    default:
        break; // end start
    }
};

// This function stops the interval timer running.
// timerNumber indicates which timer should stop running.
void intervalTimer_stop(uint32_t timerNumber){
    switch(timerNumber){
    case INTERVAL_TIMER_TIMER_0:
        timer_0_write(TCSR0_ADDER, ( timer_0_read(TCSR0_ADDER) & TCSR_STOP_ENT0_BIT)); // write a 0 into the ENT0 bit in the TCSR0.
        break; // end stop
    case INTERVAL_TIMER_TIMER_1:
        timer_1_write(TCSR0_ADDER, ( timer_1_read(TCSR0_ADDER) & TCSR_STOP_ENT0_BIT)); // write a 0 into the ENT0 bit in the TCSR0.
        break; // end stop
    case INTERVAL_TIMER_TIMER_2:
        timer_2_write(TCSR0_ADDER, ( timer_2_read(TCSR0_ADDER) & TCSR_STOP_ENT0_BIT)); // write a 0 into the ENT0 bit in the TCSR0.
        break; // end stop
    default:
        break; // end stop
    }
};

// This function resets the interval timer.
// timerNumber indicates which timer should reset.
void intervalTimer_reset(uint32_t timerNumber){
    switch(timerNumber){
    case INTERVAL_TIMER_TIMER_0:
        timer_0_write(TLR0_ADDER, LOAD_CLEAR); // write a 0 into the TLR0 register.
        timer_0_write(TCSR0_ADDER, ( timer_0_read(TCSR0_ADDER) | TCSR_LOAD)); // write a 1 into the LOAD0 bit in the TCSR0.
        timer_0_write(TLR1_ADDER, LOAD_CLEAR); // write a 0 into the TLR1 register.
        timer_0_write(TCSR1_ADDER, ( timer_0_read(TCSR1_ADDER) | TCSR_LOAD)); // write a 1 into the LOAD0 bit in the TCSR1.
        intervalTimer_init(INTERVAL_TIMER_TIMER_0);// Initialize the load timer reg again
        break;

    case INTERVAL_TIMER_TIMER_1:
        timer_1_write(TLR0_ADDER, LOAD_CLEAR); // write a 0 into the TLR0 register.
        timer_1_write(TCSR0_ADDER, ( timer_1_read(TCSR0_ADDER) | TCSR_LOAD)); // write a 1 into the LOAD0 bit in the TCSR0.
        timer_1_write(TLR1_ADDER, LOAD_CLEAR); // write a 0 into the TLR1 register.
        timer_1_write(TCSR1_ADDER, ( timer_1_read(TCSR1_ADDER) | TCSR_LOAD)); // write a 1 into the LOAD0 bit in the TCSR1.
        intervalTimer_init(INTERVAL_TIMER_TIMER_1);// Initialize the load timer reg again
        break;

    case INTERVAL_TIMER_TIMER_2:
        timer_2_write(TLR0_ADDER, LOAD_CLEAR); // write a 0 into the TLR0 register.
        timer_2_write(TCSR0_ADDER, ( timer_2_read(TCSR0_ADDER) | TCSR_LOAD)); // write a 1 into the LOAD0 bit in the TCSR0.
        timer_2_write(TLR1_ADDER, LOAD_CLEAR); // write a 0 into the TLR1 register.
        timer_2_write(TCSR1_ADDER, ( timer_2_read(TCSR1_ADDER) | TCSR_LOAD)); // write a 1 into the LOAD0 bit in the TCSR1.
        intervalTimer_init(INTERVAL_TIMER_TIMER_2); // Initialize the load timer reg again
        break;
    default:
        break;
    }
};

// Convenience function for intervalTimer_reset().
// Simply calls intervalTimer_reset() on all timers.
void intervalTimer_resetAll(){
    intervalTimer_reset(INTERVAL_TIMER_TIMER_0); //reset timer 0
    intervalTimer_reset(INTERVAL_TIMER_TIMER_1); //reset timer 1
    intervalTimer_reset(INTERVAL_TIMER_TIMER_2); //reset timer 2
};

// Runs a test on a single timer as indicated by the timerNumber argument.
// Returns INTERVAL_TIMER_STATUS_OK if successful, something else otherwise.
intervalTimer_status_t intervalTimer_test(uint32_t timerNumber){
    switch(timerNumber){
    case INTERVAL_TIMER_TIMER_0: //uses each function for timer 0
        intervalTimer_init(INTERVAL_TIMER_TIMER_0); //run to see if timer 0 will initialize
        intervalTimer_start(INTERVAL_TIMER_TIMER_0); //run to see if the timer will start
        intervalTimer_stop(INTERVAL_TIMER_TIMER_0);  //run to see if the timer will stop
        intervalTimer_reset(INTERVAL_TIMER_TIMER_0); //run to see if the timer will reset
        return INTERVAL_TIMER_STATUS_OK;
    case INTERVAL_TIMER_TIMER_1: //uses each function for timer 1
        intervalTimer_init(INTERVAL_TIMER_TIMER_1); //run to see if timer 2 will initialize
        intervalTimer_start(INTERVAL_TIMER_TIMER_1); //run to see if the timer will start
        intervalTimer_stop(INTERVAL_TIMER_TIMER_1); //run to see if the timer will stop
        intervalTimer_reset(INTERVAL_TIMER_TIMER_1); //run to see if the timer will reset
        return INTERVAL_TIMER_STATUS_OK;
    case INTERVAL_TIMER_TIMER_2: //uses each function for timer 2
        intervalTimer_init(INTERVAL_TIMER_TIMER_2); //run to see if timer 2 will initialize
        intervalTimer_start(INTERVAL_TIMER_TIMER_2); //run to see if the timer will start
        intervalTimer_stop(INTERVAL_TIMER_TIMER_2);  //run to see if the timer will stop
        intervalTimer_reset(INTERVAL_TIMER_TIMER_2); //run to see if the timer will reset
        return INTERVAL_TIMER_STATUS_OK;
    default:
        return INTERVAL_TIMER_STATUS_FAIL; // if false input return 0
    }
};

// Convenience function that invokes test on all interval timers.
// Returns INTERVAL_TIMER_STATUS_OK if successful, something else otherwise.
intervalTimer_status_t intervalTimer_testAll(){
    intervalTimer_test(INTERVAL_TIMER_TIMER_0); //test timer 0
    intervalTimer_test(INTERVAL_TIMER_TIMER_1); //test timer 1
    intervalTimer_test(INTERVAL_TIMER_TIMER_2); //test timer 2
    return INTERVAL_TIMER_STATUS_OK;
};

// Once the interval timer has stopped running, use this function to
// ascertain how long the timer was running.
// The timerNumber argument determines which timer is read.
double intervalTimer_getTotalDurationInSeconds(uint32_t timerNumber){
    switch(timerNumber){
    case INTERVAL_TIMER_TIMER_0:{
        int64_t upper_64;
        int32_t lower_32;
        double frec = XPAR_AXI_TIMER_0_CLOCK_FREQ_HZ; //set to a double so it doesn't concatenate it
        upper_64 = timer_0_read(TCR1_ADDER);
        lower_32 = timer_0_read(TCR0_ADDER);
        if(upper_64 == timer_0_read(TCR1_ADDER)){
            upper_64 = (upper_64 << SHIFT_BITS) + lower_32; // shift the upper reg over so the lower reg can be added
            return (double)((upper_64)/frec);
        }
        else{
            upper_64 = timer_0_read(TCR1_ADDER);
            lower_32 = timer_0_read(TCR0_ADDER);
            upper_64 = (upper_64 << SHIFT_BITS) + lower_32; // shift the upper reg over so the lower reg can be added
            return (double)((upper_64)/frec);
        }
    }
    case INTERVAL_TIMER_TIMER_1:{
        int64_t upper_64;
        int32_t lower_32;
        double frec = XPAR_AXI_TIMER_0_CLOCK_FREQ_HZ;//set to a double so it doesn't concatenate it
        upper_64 = timer_1_read(TCR1_ADDER);
        lower_32 = timer_1_read(TCR0_ADDER);
        if(upper_64 == timer_1_read(TCR1_ADDER)){
            upper_64 = (upper_64 << SHIFT_BITS) + lower_32; // shift the upper reg over so the lower reg can be added
            return (double)((upper_64)/frec);
        }
        else{
            upper_64 = timer_1_read(TCR1_ADDER);
            lower_32 = timer_1_read(TCR0_ADDER);
            upper_64 = (upper_64 << SHIFT_BITS) + lower_32; // shift the upper reg over so the lower reg can be added
            return (double)((upper_64)/frec);
        }
    }
    case INTERVAL_TIMER_TIMER_2:{
        int64_t upper_64;
        int32_t lower_32;
        double frec = XPAR_AXI_TIMER_0_CLOCK_FREQ_HZ;//set to a double so it doesn't concatenate it
        upper_64 = timer_2_read(TCR1_ADDER);
        lower_32 = timer_2_read(TCR0_ADDER);
        if(upper_64 == timer_2_read(TCR1_ADDER)){
            upper_64 = (upper_64 << SHIFT_BITS) + lower_32; // shift the upper reg over so the lower reg can be added
            return (double)((upper_64)/frec);
        }
        else{
            upper_64 = timer_2_read(TCR1_ADDER);
            lower_32 = timer_2_read(TCR0_ADDER);
            upper_64 = (upper_64 << SHIFT_BITS) + lower_32; // shift the upper reg over so the lower reg can be added
            return (double)((upper_64)/frec);
        }
    }
    default:
        return (double)(0);
    }
}

//**********HelperFunction**********
void timer_0_write(int32_t offset, int32_t data){ //helper function to
    Xil_Out32( XPAR_AXI_TIMER_0_BASEADDR + offset, data);//Xilinxs function to write to the register.
}
void timer_1_write(int32_t offset, int32_t data){ //helper function to
    Xil_Out32( XPAR_AXI_TIMER_1_BASEADDR + offset, data);//Xilinxs function to write to the register.
}
void timer_2_write(int32_t offset, int32_t data){ //helper function to
    Xil_Out32( XPAR_AXI_TIMER_2_BASEADDR + offset, data);//Xilinxs function to write to the register.
}
int32_t timer_0_read(int32_t offset){// helper function that Reads from the register
    return Xil_In32( XPAR_AXI_TIMER_0_BASEADDR + offset); // returns data from the register
}
int32_t timer_1_read(int32_t offset){// helper function that Reads from the register
    return Xil_In32( XPAR_AXI_TIMER_1_BASEADDR + offset); // returns data from the register
}
int32_t timer_2_read(int32_t offset){// helper function that Reads from the register
    return Xil_In32( XPAR_AXI_TIMER_2_BASEADDR + offset); // returns data from the register
}

