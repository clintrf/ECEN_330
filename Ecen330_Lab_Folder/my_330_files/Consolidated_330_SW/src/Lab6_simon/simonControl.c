/*
 * simonControl.c
 *
 *  Created on: Jun 8, 2017
 *      Author: clintrf
 */


#include "verifySequence_runTest.h"
#include "flashSequence.h"
#include "buttonHandler.h"
#include "simonDisplay.h"
#include "simonControl.h"
#include "supportFiles/display.h"
#include "supportFiles/utils.h"
#include "globals.h"
#include <stdio.h>
#include <stdint.h>
#include "../Lab2_switch_button/buttons.h"



#define START_MSG "TOUCH TO START"                                  // text for the start message
#define SIMON_MSG "SIMON"                                           // text for the start message
#define YAY_MSG "Yay!"                                              // text for the sequence completed message
#define NEW_L_MSG "Touch for new level"                             // text for the new level message
#define LONG_MSG "Longest Sequence: "                               // text for the longest sequence

#define START_MSG_X 70                                              // coordinates for the start message x position
#define START_MSG_Y 140                                             // coordinates for the start message y position

#define SIMON_MSG_X 80                                              // coordinates for the simon message x position
#define SIMON_MSG_Y 90                                              // coordinates for the simon message y position

#define YAY_MSG_X 100                                               // coordinates for the yay message x position
#define YAY_MSG_Y 100                                               // coordinates for the yay message y position

#define NEW_L_MSG_X 50                                              // coordinates for the new level message x position
#define NEW_L_MSG_Y YAY_MSG_Y                                       // coordinates for the new level message y position

#define LONG_MSG_X 50                                               // coordinates for the longest sequence message x position
#define LONG_MSG_Y YAY_MSG_Y                                        // coordinates for the longest sequence message y position

#define NUM_MSG_X 280                                               // coordinates for the number on the longest sequence message x position
#define NUM_MSG_Y YAY_MSG_Y                                         // coordinates for the number on the longest sequence message y position

#define FALSE 0                                                     // define False as 0 or reset
#define TRUE 1                                                      // define true as 1 for raising flags

#define TEXT_SIZE_L 5                                               // larger text size
#define TEXT_SIZE_S 2                                               // small text size
#define WAIT_TIME 40                                                // time to for messages to appear
#define WAIT_TIME_S 1                                               // time to give an extra tick in a state
#define INIT_LEVEL 4                                                // the starting level


uint8_t myArray[GLOBALS_MAX_FLASH_SEQUENCE];                        // the array that holds the sequence
uint8_t currLevel = INIT_LEVEL;                                     // the current level = the difficulty of the sequence
uint8_t currIter = 1;                                               // always start the level with the first box appearing of the sequence
uint8_t randNum = 0;                                                // number used to generate the random numbers

//**********COUNTERS**********/
uint8_t yayCounter = 0;                                             // counter for yay message wait
uint8_t newLevelCounter = 0;                                        // counter for new level message wait
uint8_t longestSeqCounter = 0;                                      // counter for longest sequence message wait
uint8_t fdCounter = 0;                                              // counter for flash enable wait
uint8_t vdCounter = 0;                                              // counter for verify enable wait

//**********FLAGS**********/
uint8_t initFlag = 0;                                               // flag for when the start screen needs to be printed
uint8_t nextFlag = 0;                                               // flag to send the SM on to the next level with out reseting




enum control_st_m{
    control_init_st,                                                // the initializing state
    control_touch_st,                                               // the first touch state off of the start screen state
    control_setIterLength_st,                                       // the state that sets the iteration length for that level state
    control_flash_enable_st,                                        // the enable flash sequence state
    control_flash_disable_st,                                       // the disable flash sequence state
    control_verify_enable,                                          // the enable verify sequence state
    control_verify_disable,                                         // the disable verify sequence state
    control_yay_st,                                                 // the print yay message state
    control_new_level_st,                                           // the print new level message state
    control_longest_sq_st                                           // the print longest sequence message state
}controlCurrent = control_init_st;                                  // initializes the first state to the control_init_st

void randNumGen(){                                                  // function that generates a random sequence
    srand(randNum);                                                 // seeds the number generator
    for(uint8_t i = 0; i < currLevel; i++){                         // for loop to fill the array with random nmbers
        myArray[i] = rand() % (INIT_LEVEL);                         // filling the array
    }
}

void simonControl_tick(){                                           // Simon control state machine
    switch(controlCurrent){
    case control_init_st:                                           // Moore state action for state #1
        if(!initFlag){
            display_setCursor(START_MSG_X, START_MSG_Y);            // set the cursor for the text
            display_setTextColor(DISPLAY_WHITE);                  // set the color for the text
            display_setTextSize(TEXT_SIZE_S);                       // set the text size to small
            display_println(START_MSG);                             // print the start message
            display_setCursor(SIMON_MSG_X, SIMON_MSG_Y);            // set the cursor for the text
            display_setTextColor(DISPLAY_WHITE);                  // set the color for the text
            display_setTextSize(TEXT_SIZE_L);                       // set the text size to large
            display_println(SIMON_MSG);                             // print simon on the screen
            if(!initFlag){
                initFlag = TRUE;                                    // raise the flag saying that it has been initialized
            }
        }
        randNum++;                                                  // get a new random number for the sequence generator
        break;
    case control_touch_st:                                            // Moore state action for state #2
        break;
    case control_setIterLength_st:
        globals_setSequenceIterationLength(currIter);               // set the iteration length to the current number number in the the array sequence
        break;
    case control_flash_enable_st:                                     // Moore state action for state #3
        fdCounter++;                                                  // increment the counter so the state is active for at least one tick
        flashSequence_enable();                                         // enable the flash sequence SM
        break;
    case control_flash_disable_st:                                    // Moore state action for state #4
        fdCounter = FALSE;                                              // reset the counter
        flashSequence_disable();                                        // disable the flash sequence SM
        break;
    case control_verify_enable:                                       // Moore state action for state #5
        vdCounter++;                                                  // increment the counter so the state is active for at least one tick
        verifySequence_enable();                                       // enable the verify seq SM
        break;
    case control_verify_disable:                                      // Moore state action for state #6
        vdCounter = FALSE;                                              // reset the counter
        verifySequence_disable();                                       // disable the verify seq SM
        break;
    case control_yay_st:                                              // Moore state action for state #7
        yayCounter++;                                                   // increment the counter
        break;
    case control_new_level_st:                                        // Moore state action for state #8
        newLevelCounter++;                                                   // increment the counter
        break;
    case control_longest_sq_st:                                       // Moore state action for state #9
        longestSeqCounter++;                                                   // increment the counter
        break;
    }
    switch(controlCurrent){
    case control_init_st:                                             // Mealy transition state action for state #1
        if(nextFlag){
            randNumGen();                                               // fill the array with random numbers
            globals_setSequence(myArray,currLevel);                     // set the sequence
            controlCurrent = control_setIterLength_st;
        }
        else if(display_isTouched()){
            randNumGen();
            globals_setSequence(myArray,currLevel);
            controlCurrent = control_touch_st;
        }
        break;
    case control_touch_st:                                            // Mealy transition state action for state #2
        if(!display_isTouched()){
            // print out the start messages
            display_setCursor(START_MSG_X, START_MSG_Y);            // set the cursor for the text
            display_setTextColor(DISPLAY_BLACK);                                     // erase the text
            display_setTextSize(TEXT_SIZE_S);                       // set the text size to small
            display_println(START_MSG);
            display_setCursor(SIMON_MSG_X, SIMON_MSG_Y);            // set the cursor for the text
            display_setTextColor(DISPLAY_BLACK);                                     // erase the text
            display_setTextSize(TEXT_SIZE_L);                       // set the text size to large
            display_println(SIMON_MSG);
            controlCurrent = control_setIterLength_st;
        }
        break;
    case control_setIterLength_st:                                    // Mealy transition state action for state #3
        controlCurrent = control_flash_enable_st;
        break;
    case control_flash_enable_st:                                     // Mealy transition state action for state #4
        if(flashSequence_isComplete()&& (fdCounter > WAIT_TIME_S)){   //if the flash SM is done then move to next state
            controlCurrent = control_flash_disable_st;
        }
        break;
    case control_flash_disable_st:                                    // Mealy transition state action for state #5
        controlCurrent = control_verify_enable;
        break;
    case control_verify_enable:                                       // Mealy transition state action for state #6
        if(verifySequence_isComplete() && (vdCounter > WAIT_TIME_S)){ //if the verify sequence is done move to next state
            controlCurrent = control_verify_disable;
        }
        break;
    case control_verify_disable:                                      // Mealy transition state action for state #7
        if(currIter == currLevel){                                      // if the level and the iteration match then they won
            // print yay msg
            display_setCursor(YAY_MSG_X, YAY_MSG_Y);            // set the cursor for the text
            display_setTextColor(DISPLAY_WHITE);                  // set the color for the text
            display_setTextSize(TEXT_SIZE_L);                       // set the text size to large
            display_println(YAY_MSG);
            controlCurrent = control_yay_st;
        }
        else if(verifySequence_isTimeOutError()|| verifySequence_isUserInputError()){   //if there was an user error of a time out error go to end
            //print longest sequence msg
            display_setCursor(LONG_MSG_X, LONG_MSG_Y);            // set the cursor for the text
            display_setTextColor(DISPLAY_WHITE);                  // set the color for the text
            display_setTextSize(TEXT_SIZE_S);                       // set the text size to small
            display_println(LONG_MSG);
            display_setCursor(NUM_MSG_X, NUM_MSG_Y);            // set the cursor for the text
            display_println(currLevel);
            controlCurrent = control_longest_sq_st;
        }
        else{
            currIter++;                                         // increment the iteration and go throught the flash and verify again
            controlCurrent = control_setIterLength_st;
        }
        break;
    case control_yay_st:                                              // Mealy transition state action for state #8
        if(yayCounter >= WAIT_TIME){                            // time to wait for the print yay
            // black yay
            display_setCursor(YAY_MSG_X, YAY_MSG_Y);            // set the cursor for the text
            display_setTextColor(DISPLAY_BLACK);                                     // erase the text
            display_setTextSize(TEXT_SIZE_L);                       // set the text size to large
            display_println(YAY_MSG);
            // print new level
            display_setCursor(NEW_L_MSG_X, NEW_L_MSG_Y);            // set the cursor for the text
            display_setTextColor(DISPLAY_WHITE);                  // set the color for the text
            display_setTextSize(TEXT_SIZE_S);                       // set the text size to small
            display_println(NEW_L_MSG);
            controlCurrent = control_new_level_st;
        }
        break;
    case control_new_level_st:                                        // Mealy transition state action for state #9
        if(newLevelCounter >= WAIT_TIME){                           // time to wait for the new level msg
            // black new level
            display_setCursor(NEW_L_MSG_X, NEW_L_MSG_Y);            // set the cursor for the text
            display_setTextColor(DISPLAY_BLACK);                                     // erase the text
            display_setTextSize(TEXT_SIZE_S);                       // set the text size to small
            display_println(NEW_L_MSG);
            // print longSQ
            display_setCursor(LONG_MSG_X, LONG_MSG_Y);            // set the cursor for the text
            display_setTextColor(DISPLAY_WHITE);                  // set the color for the text
            display_setTextSize(TEXT_SIZE_S);                       // set the text size to small
            display_println(LONG_MSG);
            display_setCursor(NUM_MSG_X, NUM_MSG_Y);            // set the cursor for the text
            display_println(currLevel);
            controlCurrent = control_longest_sq_st;
        }
        if(display_isTouched()){                                    // if screen is touch go to harder level
            // black new level
            display_setCursor(NEW_L_MSG_X, NEW_L_MSG_Y);            // set the cursor for the text
            display_setTextColor(DISPLAY_BLACK);                                     // erase the text
            display_setTextSize(TEXT_SIZE_S);                       // set the text size to small
            display_println(NEW_L_MSG);
            // Initialize var
            currLevel++;                                                // increment level
            currIter = TRUE;                                            //reset VAR
            nextFlag = TRUE;                                           //raise the next flag
            yayCounter = FALSE;                                           //reset VAR
            newLevelCounter = FALSE;                                           //reset VAR
            longestSeqCounter = FALSE;                                           //reset VAR
            controlCurrent = control_init_st;
        }
        break;
    case control_longest_sq_st:                                       // Mealy transition state action for state #10
        if(longestSeqCounter >= WAIT_TIME){
            // black longSQ
            display_setCursor(LONG_MSG_X, LONG_MSG_Y);            // set the cursor for the text
            display_setTextColor(DISPLAY_BLACK);                                     // erase the text
            display_setTextSize(TEXT_SIZE_S);                       // set the text size to small
            display_println(LONG_MSG);
            display_setCursor(NUM_MSG_X, NUM_MSG_Y);            // set the cursor for the text
            display_println(currLevel);
            // Initialize var
            currLevel = INIT_LEVEL;                             //reset VAR
            currIter = TRUE;                             //reset VAR
            initFlag = FALSE;                             //reset VAR
            nextFlag = FALSE;                             //reset VAR
            yayCounter = FALSE;                             //reset VAR
            newLevelCounter = FALSE;                             //reset VAR
            longestSeqCounter = FALSE;                             //reset VAR
            controlCurrent = control_init_st;
        }
        break;
    }
}

