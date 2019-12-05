/*
 * clockControl.c
 *
 *  Created on: May 18, 2017
 *      Author: clintrf
 */

#include "clockControl.h"
#include "clockDisplay.h"
#include "supportFiles/display.h"
#include <stdio.h>

#define ADC_COUNTER_MAX_VALUE 1  //the value of when the counter can flip when triggered by a touch
#define AUTO_COUNTER_MAX_VALUE 5 //the value of when the counter can flip automatically
#define RATE_COUNTER_MAX_VALUE 1 //the rate that the counter increments at
#define TOUCH_EXPIRED 10         //how many ticks it take for the touch to expire and exit the state
#define INITIALIZE_VAR 0         //value to initialize most var's
#define TRUE 1
#define FALSE 0

int8_t adcCounter = INITIALIZE_VAR;           //counter for the touch input
int16_t autoCounter = INITIALIZE_VAR;         //counter for the automatic increment
int16_t rateCounter = INITIALIZE_VAR;         //counter for how fast it increments
int8_t touched = INITIALIZE_VAR;              //var to store if the screen has been touched
int8_t soak = INITIALIZE_VAR;



// States for the controller state machine.
enum clockControl_st_t {
    init_st,                 // Start here, stay in this state for just one tick.
    never_touched_st,        // Wait here until the first touch - clock is disabled until set.
    waiting_for_touch_st,    // waiting for touch, clock is enabled and running.
    ad_timer_running_st,     // waiting for the touch-controller ADC to settle.
    auto_timer_running_st,   // waiting for the auto-update delay to expire
                                 // (user is holding down button for auto-inc/dec)
    rate_timer_running_st,   // waiting for the rate-timer to expire to know when to perform the auto inc/dec.
    rate_timer_expired_st,   // when the rate-timer expires, perform the inc/dec function.
    add_second_to_clock_st   // add a second to the clock time and reset the ms counter.
} currentState1 = init_st;


// This is a debug state print routine. It will print the names of the states each
// time tick() is called. It only prints states if they are different than the
// previous state.
void debugStatePrint() {
  static clockControl_st_t previousState;
  static bool firstPass = true;
  // Only print the message if:
  // 1. This the first pass and the value for previousState is unknown.
  // 2. previousState != currentState1 - this prevents reprinting the same state name over and over.
  if (previousState != currentState1 || firstPass) {
    firstPass = false;                // previousState will be defined, firstPass is false.
    previousState = currentState1;     // keep track of the last state that you were in.
    //printf("msCounter:%d\n\r", msCounter);
    switch(currentState1) {            // This prints messages based upon the state that you were in.
      case init_st:
        printf("init_st\n\r");
        break;                      //exit state
      case never_touched_st:
        printf("never_touched_st\n\r");
        break;                      //exit state
      case waiting_for_touch_st:
        printf("waiting_for_touch_st\n\r");
        break;                      //exit state
      case ad_timer_running_st:
        printf("ad_timer_running_st\n\r");
        break;                      //exit state
      case auto_timer_running_st:
        printf("auto_timer_running_st\n\r");
        break;                      //exit state
      case rate_timer_running_st:
        printf("rate_timer_running_st\n\r");
        break;                      //exit state
      case rate_timer_expired_st:
        printf("rate_timer_expired_st\n\r");
        break;                      //exit state
      case add_second_to_clock_st:
          break;                    //exit state
     }
  }
}

void clockControl_init() {
  currentState1 = init_st; //Initializes the state machine to the initial state
}

void clockControl_tick() {
    debugStatePrint(); //print out the debug function as a state is entered
  switch(currentState1) { //moore output switch
    case init_st: //empty (didn't use this state)
      break; //exit state
    case never_touched_st: //empty (didn't use this state)
      break; //exit state
    case waiting_for_touch_st: //name of state
        adcCounter = INITIALIZE_VAR;   //Initialize the counter var's
        autoCounter = INITIALIZE_VAR;  //Initialize the counter var's
        rateCounter = INITIALIZE_VAR;  //Initialize the counter var's
        if (touched){// if the display has been touched
            if (soak == TOUCH_EXPIRED){// if soak has incremented (waited long enough) the refresh screen:
                clockDisplay_advanceTimeOneSecond();// increment time by one second
                clockDisplay_updateTimeDisplay(0);  // update the display with the new time
                soak = INITIALIZE_VAR; // reset the counter
            }
            else {
                soak++;// else, add one to the counter
            }
        }
      break;//exit state
    case ad_timer_running_st:    //name of state
        if (!touched){
          touched = TRUE;       // set to 1
        }
        adcCounter++;           // Increment the counter
      break;//exit state
    case auto_timer_running_st: //name of state
        autoCounter++;          // Increment the counter
      break;//exit state
    case rate_timer_running_st: //name of state
        rateCounter++;          // Increment the timer.
      break;//exit state
    case rate_timer_expired_st: //name of state
        rateCounter = INITIALIZE_VAR;// reset rateTimer
      break;//exit state
     default:
      printf("clockControl_tick state action: hit default\n\r");
      break;//exit state
  }

  // Perform state update, transition
  switch(currentState1) {
    case init_st:    //name of state
        currentState1 = waiting_for_touch_st; // Initialize state machine
      break;//exit state
    case never_touched_st: //name of state
        //empty
      break;//exit state
    case waiting_for_touch_st: //name of state
        if(display_isTouched()){        //check if the screen is touched
            display_clearOldTouchData();// clear old touch data
            currentState1 = ad_timer_running_st;// go to the next state
        }
      break;//exit state
    case ad_timer_running_st: //name of state
        if (display_isTouched() && adcCounter == ADC_COUNTER_MAX_VALUE){ //check if the screen is touched
            currentState1 = auto_timer_running_st;// go to the next state
        }
        else if (!display_isTouched() && adcCounter == ADC_COUNTER_MAX_VALUE){
            clockDisplay_performIncDec();
            currentState1 = waiting_for_touch_st;// go to the next state
        }
      break;//exit state
    case auto_timer_running_st: //name of state
        if (display_isTouched() && autoCounter == AUTO_COUNTER_MAX_VALUE){//check if the screen is touched
            currentState1 = rate_timer_running_st;// go to the next state
        }
        else if (!display_isTouched()){
            clockDisplay_performIncDec();
            currentState1 = waiting_for_touch_st;// go to the next state
        }
      break;//exit state
    case rate_timer_running_st: //name of state
        if (display_isTouched() && rateCounter == RATE_COUNTER_MAX_VALUE){//check if the screen is touched
            currentState1 = rate_timer_expired_st;// go to the next state
        }
        else if (!display_isTouched()){
            currentState1 = waiting_for_touch_st;// go to the next state
        }
      break;//exit state
    case rate_timer_expired_st: //name of state
        if (display_isTouched()){   //check if the screen is touched
            clockDisplay_performIncDec();
            currentState1 = rate_timer_running_st;// go to the next state
        }
        else if (!display_isTouched()){
            currentState1 = waiting_for_touch_st;// go to the next state
        }
      break;//exit state
    case add_second_to_clock_st: //empty
      break;//exit state
    default:
      printf("clockControl_tick state update: hit default\n\r");
      break;//exit state
  }
}




