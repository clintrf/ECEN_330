/*
 * flashSequence.c
 *
 *  Created on: Jun 1, 2017
 *      Author: clintrf
 */

#include "flashSequence.h"
#include "simonDisplay.h"
#include "supportFiles/display.h"
#include "supportFiles/utils.h"
#include "globals.h"
#include <stdio.h>


//**********CODE_FROM_THE_PROFFESOR**********//
// This will set the sequence to a simple sequential pattern.
// It starts by flashing the first color, and then increments the index and flashes the first
// two colors and so forth. Along the way it prints info messages to the LCD screen.
#define TEST_SEQUENCE_LENGTH 8  // Just use a short test sequence.
uint8_t flashSequence_testSequence[TEST_SEQUENCE_LENGTH] = {
    SIMON_DISPLAY_REGION_0,                                     // sets region 0 to 0
    SIMON_DISPLAY_REGION_1,                                     // sets region 1 to 1
    SIMON_DISPLAY_REGION_2,                                     // sets region 2 to 2
    SIMON_DISPLAY_REGION_3,                                     // sets region 3 to 3
    SIMON_DISPLAY_REGION_3,                                     // sets region 3 to 3
    SIMON_DISPLAY_REGION_2,                                     // sets region 2 to 2
    SIMON_DISPLAY_REGION_1,                                     // sets region 1 to 1
    SIMON_DISPLAY_REGION_0};                                    // sets region 0 to 0
#define INCREMENTING_SEQUENCE_MESSAGE1 "Incrementing Sequence"  // Info message.
#define RUN_TEST_COMPLETE_MESSAGE "Runtest() Complete"          // Info message.
#define MESSAGE_TEXT_SIZE 2                                     // Make the text easy to see.
#define TWO_SECONDS_IN_MS 2000                                  // Two second delay.
#define TICK_PERIOD 75                                          // 200 millisecond delay.
#define TEXT_ORIGIN_X 0                                         // Text starts from far left and
#define TEXT_ORIGIN_Y (DISPLAY_HEIGHT/2)                        // middle of screen.

//**********MY_CODE***********//
#define FLASH_ENABLE_FLAG_ON 1                                  // Var for when the FLAG is o
#define FLASH_ENABLE_FLAG_OFF 0                                 // Var for when the enable flag is off
#define TRUE 1                                                  // sets true to 1
#define FALSE 0                                                 // sets false to 0
#define timeDelay 10                                            // time to delay between each box shown
uint8_t flashEnableFlag = 0;                                    // declares the enable flag
uint8_t isCompleteFlag = 0;                                     // declare the complete flag
uint8_t waitCounter = 0;                                        // declare the flash counter
uint8_t series = 0;                                             // Var for what number in the array

enum flashSequence_st_m{                                        // number the state
    init_st,                                                    // start state
    print_st,                                                   // print the button state
    wait_st,                                                    // wait for the button to be printed state
    delete_st,                                                  // delete the button state
    end_st                                                      // end state
}flashCurrentState = init_st;                                   // set the starting state to iniyt_st

void flashSequence_enable(){                                    // Turns on the state machine. Part of the interlock.
    flashEnableFlag = FLASH_ENABLE_FLAG_ON;                     //sets the flag to on
}

void flashSequence_disable(){                                   // Turns off the state machine. Part of the interlock.
    flashEnableFlag = FLASH_ENABLE_FLAG_OFF;                    //sets the flag to off
}

bool flashSequence_isComplete(){                                // Other state machines can call this to determine if this state machine is finished.
    return isCompleteFlag;
}

void flashSequence_tick(){                                      // Standard tick function.
    switch(flashCurrentState){
    case init_st:                                               // Moore state action for state #1
        break;                                                  // exit state
    case print_st:                                              // Moore state action for state #2
        simonDisplay_drawSquare(globals_getSequenceValue(series),FALSE);// print out the squares
        break;                                                  // exit state
    case wait_st:                                               // Moore state action for state #3
        waitCounter++;                                          // increment the waitCounter
        break;                                                  // exit state
    case delete_st:                                             // Moore state action for state #4
        simonDisplay_drawSquare(globals_getSequenceValue(series),TRUE); //delete the square that was printed
        break;                                                  // exit state
    case end_st:                                                // Moore state action for state #5
        isCompleteFlag = TRUE;                                  // raise the flag saying that the square has been printed and erased
        break;                                                  // exit state
    }
    switch(flashCurrentState){
    case init_st:                                               // Mealy transition state action for state #1
        if(flashEnableFlag){
            flashCurrentState = print_st;                       // transition to next state
        }
        break;                                                  // exit state
    case print_st:                                              // Mealy transition state action for state #2
        flashCurrentState = wait_st;                            // transition to next state
        break;                                                  // exit state
    case wait_st:                                               // Mealy transition state action for state #3
        if(waitCounter >= timeDelay){                           // wait till counter reaches the timerDelay
            waitCounter = FALSE;                                // after the state has sat for 10 ticks then reset the counter
            flashCurrentState = delete_st;                      // transition to next state
        }
        break;                                                  // exit state
    case delete_st:                                             // Mealy transition state action for state #4
        if(series >= globals_getSequenceIterationLength()){     // when the series reaches the max iteration length of the array
            flashCurrentState = end_st;                         // transition to next state
        }
        else{
            series++;                                           // increment the spot in the series
            flashCurrentState = print_st;                       // transition to next state
        }
        break;                                                  // exit state
    case end_st:                                                // Mealy transition state action for state #5
        if(!flashEnableFlag){                                   // when the enable flag is lowered reset back to begining
            series = FALSE;                                     // reset the flag
            isCompleteFlag = FALSE;                             // reset the flag
            flashCurrentState = init_st;                        // go back the the initial state
        }
        break;                                                  // exit state
    }
}

    // Print the incrementing sequence message.
void flashSequence_printIncrementingMessage() {
  display_fillScreen(DISPLAY_BLACK);  // Otherwise, tell the user that you are incrementing the sequence.
  display_setCursor(TEXT_ORIGIN_X, TEXT_ORIGIN_Y);// Roughly centered.
  display_println(INCREMENTING_SEQUENCE_MESSAGE1);// Print the message.
  utils_msDelay(TWO_SECONDS_IN_MS);   // Hold on for 2 seconds.
  display_fillScreen(DISPLAY_BLACK);  // Clear the screen.
}

// Run the test: flash the sequence, one square at a time
// with helpful information messages.
void flashSequence_runTest() {
  display_init();                   // We are using the display.
  display_fillScreen(DISPLAY_BLACK);    // Clear the display.
  globals_setSequence(flashSequence_testSequence, TEST_SEQUENCE_LENGTH);    // Set the sequence.
  flashSequence_enable();             // Enable the flashSequence state machine.
  int16_t sequenceLength = 1;         // Start out with a sequence of length 1.
  globals_setSequenceIterationLength(sequenceLength);   // Set the iteration length.
  display_setTextSize(MESSAGE_TEXT_SIZE); // Use a standard text size.
  while (1) {                             // Run forever unless you break.
    flashSequence_tick();             // tick the state machine.
    utils_msDelay(TICK_PERIOD);   // Provide a 1 ms delay.
    if (flashSequence_isComplete()) {   // When you are done flashing the sequence.
      flashSequence_disable();          // Interlock by first disabling the state machine.
      flashSequence_tick();             // tick is necessary to advance the state.
      utils_msDelay(TICK_PERIOD);       // don't really need this here, just for completeness.
      flashSequence_enable();           // Finish the interlock by enabling the state machine.
      utils_msDelay(TICK_PERIOD);       // Wait 1 ms for no good reason.
      sequenceLength++;                 // Increment the length of the sequence.
      if (sequenceLength > TEST_SEQUENCE_LENGTH)  // Stop if you have done the full sequence.
        break;
      // Tell the user that you are going to the next step in the pattern.
      flashSequence_printIncrementingMessage();
      globals_setSequenceIterationLength(sequenceLength);  // Set the length of the pattern.
    }
  }
  // Let the user know that you are finished.
  display_fillScreen(DISPLAY_BLACK);              // Blank the screen.
  display_setCursor(TEXT_ORIGIN_X, TEXT_ORIGIN_Y);// Set the cursor position.
  display_println(RUN_TEST_COMPLETE_MESSAGE);     // Print the message.
}

