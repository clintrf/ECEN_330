/*
 * simonDisplay.c
 *
 *  Created on: Jun 1, 2017
 *      Author: clintrf
 */

#include <stdio.h>
#include "simonDisplay.h"
#include "supportFiles/display.h"
#include "supportFiles/utils.h"

//**********CODE FROM PROFESSOR**********//
#define TOUCH_PANEL_ANALOG_PROCESSING_DELAY_IN_MS 60 // in ms
#define MAX_STR 255
#define TEXT_SIZE 2
#define TEXT_VERTICAL_POSITION 0
#define TEXT_HORIZONTAL_POSITION (DISPLAY_HEIGHT/2)
#define INSTRUCTION_LINE_1 "Touch and release to start the Simon demo."
#define INSTRUCTION_LINE_2 "Demo will terminate after %d touches."
#define DEMO_OVER_MESSAGE_LINE_1 "Simon demo terminated"
#define DEMO_OVER_MESSAGE_LINE_2 "after %d touches."
#define TEXT_VERTICAL_POSITION 0 // Start at the far left.
#define ERASE_THE_SQUARE true  // drawSquare() erases if this is passed in.
#define DRAW_THE_SQUARE false  // drawSquare() draws the square if this is passed in.

//***********MY_VAR**********//
#define DIVIDE_HALF 2 // too cut the screen width and height in half
#define CENTER_BUTTEN_X 50 //offset from the side in the x direction
#define CENTER_BUTTEN_Y 30 //offset from the side in the y direction
#define BOX_HEIGHT 160  // the height of the box that flashes
#define BOX_WIDTH 120       //the width of the bow that flashed
#define HOME_POSITION 0     //the start postion 0,0




int8_t simonDisplay_computeRegionNumber(int16_t x, int16_t y){
    if(x < (DISPLAY_WIDTH/DIVIDE_HALF)){             //see if screen was touched on the left half
        if(y < (DISPLAY_HEIGHT/DIVIDE_HALF)){        //see if screen was touched on the top half
            return SIMON_DISPLAY_REGION_0;           //return button 0
        }
        else{                                       //screen was touched on the the bottom half
            return SIMON_DISPLAY_REGION_2;          //return button 2
        }
    }
    else{                                           //screen was touched on the right half
        if(y < (DISPLAY_HEIGHT/DIVIDE_HALF)){       //see if screen was touched on the top half
            return SIMON_DISPLAY_REGION_1;          //return button 1
        }
        else{                                       //screen was touched on the the bottom half
            return SIMON_DISPLAY_REGION_3;          //return button 3
        }
    }
}

// Draws a colored "button" that the user can touch.
// The colored button is centered in the region but does not fill the region.
void simonDisplay_drawButton(uint8_t regionNumber){
    switch (regionNumber){
    case SIMON_DISPLAY_REGION_0: // fills button #0 in with red
        display_fillRect(CENTER_BUTTEN_X, CENTER_BUTTEN_Y, SIMON_DISPLAY_BUTTON_WIDTH, SIMON_DISPLAY_BUTTON_HEIGHT, DISPLAY_RED);
        break;                      // exits the case
    case SIMON_DISPLAY_REGION_1: // fills button #1 in with yellow
        display_fillRect((DISPLAY_WIDTH/DIVIDE_HALF)+CENTER_BUTTEN_X, CENTER_BUTTEN_Y, SIMON_DISPLAY_BUTTON_WIDTH, SIMON_DISPLAY_BUTTON_HEIGHT, DISPLAY_YELLOW);
        break;                      // exits the case
    case SIMON_DISPLAY_REGION_2: // fills button #2 in with blue
        display_fillRect(CENTER_BUTTEN_X, (DISPLAY_HEIGHT/DIVIDE_HALF)+CENTER_BUTTEN_Y, SIMON_DISPLAY_BUTTON_WIDTH, SIMON_DISPLAY_BUTTON_HEIGHT, DISPLAY_BLUE);
        break;                      // exits the case
    case SIMON_DISPLAY_REGION_3: // fills button #3 in with green
        display_fillRect((DISPLAY_WIDTH/DIVIDE_HALF)+CENTER_BUTTEN_X, (DISPLAY_HEIGHT/DIVIDE_HALF)+CENTER_BUTTEN_Y, SIMON_DISPLAY_BUTTON_WIDTH, SIMON_DISPLAY_BUTTON_HEIGHT, DISPLAY_GREEN);
        break;                      // exits the case
    }
};
// Convenience function that draws all of the buttons.
void simonDisplay_drawAllButtons(){
    simonDisplay_drawButton(SIMON_DISPLAY_REGION_0); // draw the button in position #0
    simonDisplay_drawButton(SIMON_DISPLAY_REGION_1); // draw the button in position #1
    simonDisplay_drawButton(SIMON_DISPLAY_REGION_2); // draw the button in position #2
    simonDisplay_drawButton(SIMON_DISPLAY_REGION_3); // draw the button in position #3
};
// Convenience function that erases all of the buttons.
void simonDisplay_eraseAllButtons(){ //uses the same code from simonDisplay_drawButton but changes the color to black
    display_fillRect(CENTER_BUTTEN_X, CENTER_BUTTEN_Y, SIMON_DISPLAY_BUTTON_WIDTH, SIMON_DISPLAY_BUTTON_HEIGHT, DISPLAY_BLACK);
    display_fillRect((DISPLAY_WIDTH/DIVIDE_HALF)+CENTER_BUTTEN_X, CENTER_BUTTEN_Y, SIMON_DISPLAY_BUTTON_WIDTH, SIMON_DISPLAY_BUTTON_HEIGHT, DISPLAY_BLACK);
    display_fillRect(CENTER_BUTTEN_X, (DISPLAY_HEIGHT/DIVIDE_HALF)+CENTER_BUTTEN_Y, SIMON_DISPLAY_BUTTON_WIDTH, SIMON_DISPLAY_BUTTON_HEIGHT, DISPLAY_BLACK);
    display_fillRect((DISPLAY_WIDTH/DIVIDE_HALF)+CENTER_BUTTEN_X, (DISPLAY_HEIGHT/DIVIDE_HALF)+CENTER_BUTTEN_Y, SIMON_DISPLAY_BUTTON_WIDTH, SIMON_DISPLAY_BUTTON_HEIGHT, DISPLAY_BLACK);
};

// Draws a bigger square that completely fills the region.
// If the erase argument is true, it draws the square as black background to "erase" it.
void simonDisplay_drawSquare(uint8_t regionNo, bool erase){
    if (erase){
        switch (regionNo){
        case SIMON_DISPLAY_REGION_0:   // fills box #0 in with black
            display_fillRect(HOME_POSITION, HOME_POSITION, BOX_HEIGHT, BOX_WIDTH, DISPLAY_BLACK);
            break;                      // exits the case
        case SIMON_DISPLAY_REGION_1:   // fills box #1 in with black
            display_fillRect(BOX_HEIGHT, HOME_POSITION, BOX_HEIGHT, BOX_WIDTH, DISPLAY_BLACK);
            break;                      // exits the case
        case SIMON_DISPLAY_REGION_2:   // fills box #2 in with black
            display_fillRect(0, BOX_WIDTH, BOX_HEIGHT, BOX_WIDTH, DISPLAY_BLACK);
            break;                      // exits the case
        case SIMON_DISPLAY_REGION_3:   // fills box #3 in with black
            display_fillRect(BOX_HEIGHT, BOX_WIDTH,BOX_HEIGHT, BOX_WIDTH,  DISPLAY_BLACK);
            break;                      // exits the case
        }
    }
    else{ // if the erase is false then fill the box with the right color
        switch (regionNo){
        case SIMON_DISPLAY_REGION_0:   // fills box #0 in with red
            display_fillRect(HOME_POSITION, HOME_POSITION, BOX_HEIGHT, BOX_WIDTH, DISPLAY_RED);
            break;                      // exits the case
        case SIMON_DISPLAY_REGION_1:   // fills box #1 in with yellow
            display_fillRect(BOX_HEIGHT, HOME_POSITION, BOX_HEIGHT, BOX_WIDTH, DISPLAY_YELLOW);
            break;                      // exits the case
        case SIMON_DISPLAY_REGION_2:   // fills box #2 in with blue
            display_fillRect(HOME_POSITION, BOX_WIDTH, BOX_HEIGHT, BOX_WIDTH, DISPLAY_BLUE);
            break;                      // exits the case
        case SIMON_DISPLAY_REGION_3:   // fills box #3 in with green
            display_fillRect(BOX_HEIGHT, BOX_WIDTH,BOX_HEIGHT, BOX_WIDTH,  DISPLAY_GREEN);
            break;                      // exits the case
        }
    }
};

// Runs a brief demonstration of how buttons can be pressed and squares lit up to implement the user
// interface of the Simon game. The routine will continue to run until the touchCount has been reached, e.g.,
// the user has touched the pad touchCount times.

// I used a busy-wait delay (utils_msDelay) that uses a for-loop and just blocks until the time has passed.
// When you implement the game, you CANNOT use this function as we discussed in class. Implement the delay
// using the non-blocking state-machine approach discussed in class.
void simonDisplay_runTest(uint16_t touchCount){
    display_init();         // Always initialize the display.
    char str[MAX_STR];      // Enough for some simple printing.
    uint8_t regionNumber = 0;   // Convenience variable.
    uint16_t touches = 0;   // Terminate when you receive so many touches.
    // Write an informational message and wait for the user to touch the LCD.
    display_fillScreen(DISPLAY_BLACK);              // clear the screen.
    display_setCursor(TEXT_VERTICAL_POSITION, TEXT_HORIZONTAL_POSITION); // move to the middle of the screen.
    display_setTextSize(TEXT_SIZE);                 // Set the text size for the instructions.
    display_setTextColor(DISPLAY_RED, DISPLAY_BLACK);   // Reasonable text color.
    sprintf(str, INSTRUCTION_LINE_1);                   // Copy the line to a buffer.
    display_println(str);                               // Print to the LCD.
    display_println();                                  // new-line.
    sprintf(str, INSTRUCTION_LINE_2, touchCount);       // Copy the line to a buffer.
    display_println(str);                               // Print to the LCD.
    while (!display_isTouched());       // Wait here until the screen is touched.
    while (display_isTouched());        // Now wait until the touch is released.
    display_fillScreen(DISPLAY_BLACK);  // Clear the screen.
    simonDisplay_drawAllButtons();      // Draw all of the buttons.
    bool touched = false;         // Keep track of when the pad is touched.
    int16_t x, y;                     // Use these to keep track of coordinates.
    uint8_t z;                        // This is the relative touch pressure.
    while (touches < touchCount) {  // Run the loop according to the number of touches passed in.
        if (!display_isTouched() && touched) {          // user has stopped touching the pad.
             simonDisplay_drawSquare(regionNumber, ERASE_THE_SQUARE);  // Erase the square.
             simonDisplay_drawButton(regionNumber);        // DISPLAY_REDraw the button.
             touched = false;                  // Released the touch, set touched to false.
        }
        else if (display_isTouched() && !touched) {   // User started touching the pad.
             touched = true;                             // Just touched the pad, set touched = true.
             touches++;                                  // Keep track of the number of touches.
             display_clearOldTouchData();                // Get rid of data from previous touches.
             // Must wait this many milliseconds for the chip to do analog processing.
             utils_msDelay(TOUCH_PANEL_ANALOG_PROCESSING_DELAY_IN_MS);
             display_getTouchedPoint(&x, &y, &z);        // After the wait, get the touched point.
             regionNumber = simonDisplay_computeRegionNumber(x, y);// Compute the region number, see above.
             simonDisplay_drawSquare(regionNumber, DRAW_THE_SQUARE);  // Draw the square (erase = false).
        }
    }
    // Done with the demo, write an informational message to the user.
    display_fillScreen(DISPLAY_BLACK);        // clear the screen.
    // Place the cursor in the middle of the screen.
    display_setCursor(TEXT_VERTICAL_POSITION, TEXT_HORIZONTAL_POSITION);
    display_setTextSize(TEXT_SIZE); // Make it readable.
    display_setTextColor(DISPLAY_RED, DISPLAY_BLACK);  // red is foreground color, black is background color.
    sprintf(str, DEMO_OVER_MESSAGE_LINE_1);    // Format a string using sprintf.
    display_println(str);                     // Print it to the LCD.
    sprintf(str, DEMO_OVER_MESSAGE_LINE_2, touchCount);  // Format the rest of the string.
    display_println(str);  // Print it to the LCD.
    };


