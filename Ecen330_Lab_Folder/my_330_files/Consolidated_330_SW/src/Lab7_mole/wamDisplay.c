#include "supportFiles/display.h"
#include "wamDisplay.h"
#include "wamControl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//**********MY_VARS**********/

#define MOLE_HOLE_RADIUS 26 //size of the mole hole
#define MOLE_RADIUS 25      //size of the mole
#define TEXT_SIZE_L 3       //size of the big text
#define TEXT_SIZE_S 2       //size of the small text
#define STR_SIZE 20         //size of the strings that are being used in sprintf

#define BOARD_OFFSET_Y 18       //the size of the space where the score is printed out
#define BOARD_HOLE_OFFSET_X 120 //how big the moles should be from the x board center
#define BOARD_HOLE_OFFSET_Y 65  //how big the moles should be from the y board center

#define BOARD_SIZE_X DISPLAY_WIDTH                      //size of the board in the x direction
#define BOARD_SIZE_Y DISPLAY_HEIGHT - BOARD_OFFSET_Y    //size of the board in the y direction
#define BOARD_ORIGIN_X_Y 0                              //where the board starts from
#define TRUE 1                                          //define BOOL TRUE
#define FALSE 0                                         //define BOOL FALSE or reset
#define FAIL -1                                         //define fail as -1
#define BOARD_NUM_HOLES_4 4                             //num of holes for a 4 board
#define BOARD_NUM_HOLES_6 6                             //num of holes for a 6 board
#define BOARD_NUM_HOLES_9 9                             //num of holes for a 9 board

#define START_MSG_0 "Whack a Mole!"                     //Text for start screen
#define START_MSG_1 "Touch Screen to Start"             //Text for start screen

#define BOARD_STAT_0 "Hits:%d"                          //text for hits with space for numbers
#define BOARD_STAT_1 "Miss:%d"                          //text for misses with space for numbers
#define BOARD_STAT_2 "Level:%d"                         //text for level with space for numbers

#define GAME_OVER_MSG_0 "Game Over"                       //Text for end screen
#define GAME_OVER_MSG_1 "Hits:%d"                         //text for Hits with space for numbers
#define GAME_OVER_MSG_2 "Misses:%d"                       //text for misses with space for numbers
#define GAME_OVER_MSG_3 "Final Level:%d"                  //text for final level with space for numbers
#define GAME_OVER_MSG_4 "(Touch to Try Again)"            //Text for end screen

#define START_MSG_0_X 45                                //x coordinates for start screen message 0
#define START_MSG_1_X 30                                //x coordinates for start screen message 1

#define START_MSG_0_Y 100                                //y coordinates for start screen message 0
#define START_MSG_1_Y 130                                //y coordinates for start screen message 1

#define BOARD_STAT_0_X 0                                  //x coordinates for hits message 1
#define BOARD_STAT_1_X 100                                //x coordinates for misses message 1
#define BOARD_STAT_2_X 200                                //x coordinates for level message 1
#define BOARD_STAT_0_Y DISPLAY_HEIGHT-BOARD_OFFSET_Y      //y coordinates for the line of board stats

#define GAME_OVER_MSG_0_X 80                            //x coordinates for end screen message 0
#define GAME_OVER_MSG_1_X 125                            //x coordinates for end screen message 1
#define GAME_OVER_MSG_2_X 115                            //x coordinates for end screen message 2
#define GAME_OVER_MSG_3_X 85                            //x coordinates for end screen message 3
#define GAME_OVER_MSG_4_X 45                            //x coordinates for end screen message 4

#define GAME_OVER_MSG_0_Y 50                            //y coordinates for end screen message 0
#define GAME_OVER_MSG_1_Y 90                            //y coordinates for end screen message 1
#define GAME_OVER_MSG_2_Y 110                            //y coordinates for end screen message 2
#define GAME_OVER_MSG_3_Y 130                            //y coordinates for end screen message 3
#define GAME_OVER_MSG_4_Y 170                            //y coordinates for end screen message 4

#define MOLE_HOLE_0_X (MOLE_HOLE_1_X - BOARD_HOLE_OFFSET_X)     //x coordinate for the column 1 of holes
#define MOLE_HOLE_1_X DISPLAY_WIDTH/2                            //x coordinate for the column 2 of holes
#define MOLE_HOLE_2_X (MOLE_HOLE_1_X + BOARD_HOLE_OFFSET_X)     //x coordinate for the column 3 of holes

#define MOLE_HOLE_0_Y (MOLE_HOLE_1_Y - BOARD_HOLE_OFFSET_Y)     //y coordinate for the row 1 of holes
#define MOLE_HOLE_1_Y (DISPLAY_HEIGHT-BOARD_OFFSET_Y)/2         //y coordinate for the row 2 of holes
#define MOLE_HOLE_2_Y (MOLE_HOLE_1_Y + BOARD_HOLE_OFFSET_Y)     //y coordinate for the row 3 of holes

#define MOLE_HOLE_0_0 0                                         //mole hole 0
#define MOLE_HOLE_1_0 1                                         //mole hole 1
#define MOLE_HOLE_2_0 2                                         //mole hole 2
#define MOLE_HOLE_0_1 3                                         //mole hole 3
#define MOLE_HOLE_1_1 4                                         //mole hole 4
#define MOLE_HOLE_2_1 5                                         //mole hole 5
#define MOLE_HOLE_0_2 6                                         //mole hole 6
#define MOLE_HOLE_1_2 7                                         //mole hole 7
#define MOLE_HOLE_2_2 8                                         //mole hole 8
#define MOLE_HOLE_FAIL 10                                       //mole hole that does not exist

//**********MY_VAR**********/
uint8_t numMoleHoles = 0;                                       // VAR to update with the current number of mole holes
char statStr0[STR_SIZE];                                       // string to hold the hits
char statStr1[STR_SIZE];                                       // string to hold the misses
char statStr2[STR_SIZE];                                       // string to hold the level

char endStatMsgStr1[STR_SIZE];                                       // string to hold the hits
char endStatMsgStr2[STR_SIZE];                                       // string to hold the misses
char endStatMsgStr3[STR_SIZE];                                       // string to hold the level


uint16_t statCount0 = 0;                                        // VAR for hits
uint16_t statCount1 = 0;                                        // VAR for misses
uint16_t statCount2 = 0;                                        // VAR for level

wamDisplay_point_t moleCoord;                                   //VAR to hole the x and y coordinates of the touch


//**********PROTOTYPES*********/
void wamDisplay_drawAllMoleHoles();                                             //draw the all the mole holes
void wamDisplay_drawMoleHole(uint8_t moleHoleReion, uint8_t drwHole );          //draw one mole hole
void wamDisplay_drawMole(wamDisplay_point_t moleReion, uint8_t drwMole);        //draw one mole hole
void wamDisplay_getMoleCoor(uint16_t index);                                    //coordinates for the mole




/********************** typedefs **********************/
// This keeps track of all mole information.
typedef struct {
        wamDisplay_point_t origin;  // This is the origin of the hole for this mole.
        // A mole is active if either of the tick counts are non-zero. The mole is dormant otherwise.
        // During operation, non-zero tick counts are decremented at a regular rate by the control state machine.
        // The mole remains in his hole until ticksUntilAwake decrements to zero and then he pops out.
        // The mole remains popped out of his hole until ticksUntilDormant decrements to zero.
        // Once ticksUntilDomant goes to zero, the mole hides in his hole and remains dormant until activated again.
        wamDisplay_moleTickCount_t ticksUntilAwake;  // Mole will wake up (pop out of hole) when this goes from 1 -> 0.
        wamDisplay_moleTickCount_t ticksUntilDormant; // Mole will go dormant (back in hole) this goes 1 -> 0.
} wamDisplay_moleInfo_t;

// This will contain pointers to all of the mole info records.
// This will ultimately be treated as an array of pointers.
static wamDisplay_moleInfo_t** wamDisplay_moleInfo;

// Allocates the memory for wamDisplay_moleInfo_t records.
// Computes the origin for each mole assuming a simple row-column layout:
// 9 moles: 3 rows, 3 columns, 6 moles: 2 rows, 3 columns, 4 moles: 2 rows, 2 columns
// Also inits the tick counts for awake and dormant.
void wamDisplay_computeMoleInfo() {
    wamDisplay_moleInfo = (wamDisplay_moleInfo_t**) malloc(numMoleHoles * sizeof(wamDisplay_moleInfo_t*));  //Initialize moleInfo through MALLOC
    for(uint16_t i = FALSE; i< numMoleHoles; i++){
        wamDisplay_moleInfo[i] = (wamDisplay_moleInfo_t*) malloc(sizeof(wamDisplay_moleInfo_t));            //give memory to all of the mole holes
    }
    for (uint16_t j=FALSE; j<numMoleHoles; j++) {                                                               //initializes the values for origin, awake and dormant for all moles
        wamDisplay_getMoleCoor(j);                                                                        //get the mole coordinates
        wamDisplay_moleInfo[j]->origin = moleCoord;                                                      //initializes the values for origin
        wamDisplay_moleInfo[j]->ticksUntilAwake = FALSE;                                                      //initializes the values for awake
        wamDisplay_moleInfo[j]->ticksUntilDormant = FALSE;                                                      //initializes the values for dormant
    }
}

void wamDisplay_selectMoleCount(wamDisplay_moleCount_e moleCount){      //sets the mole count depending on the board
    switch(moleCount){
    case wamDisplay_moleCount_4:                                        //if the board has 4 holes
        numMoleHoles = BOARD_NUM_HOLES_4;                               //set the mole VAR
        break;
    case wamDisplay_moleCount_6:                                        //if the board has 6 holes
        numMoleHoles = BOARD_NUM_HOLES_6;                               //set the mole VAR
        break;
    case wamDisplay_moleCount_9:                                        //if the board has 9 holes
        numMoleHoles = BOARD_NUM_HOLES_9;                               //set the mole VAR
        break;
    }
    wamDisplay_computeMoleInfo();                                       //update the mole info
};

void wamDisplay_init(){// Call this before using any wamDisplay_ functions.
    display_setTextColor(DISPLAY_WHITE, DISPLAY_BLACK);                 //reset the text color behind the text
};

void wamDisplay_drawMoleBoard(){// Draw the game display with a background and mole holes.
    display_fillRect(BOARD_ORIGIN_X_Y, BOARD_ORIGIN_X_Y, BOARD_SIZE_X, BOARD_SIZE_Y, DISPLAY_GREEN); //draw green background
    wamDisplay_drawScoreScreen();                                                                    //draw the score bar
    wamDisplay_drawAllMoleHoles();                                                                   //cut out the holes in the board
};

void wamDisplay_drawSplashScreen(){ // Draw the initial splash (instruction) screen.
    display_fillScreen(DISPLAY_BLACK);                              //reset the screen
    display_setTextColor(DISPLAY_WHITE);                            //set the text color

    display_setTextSize(TEXT_SIZE_L);                               //set the text size
    display_setCursor(START_MSG_0_X , START_MSG_0_Y);               //set the cursor for the text
    display_println(START_MSG_0);                                   //print the msg

    display_setTextSize(TEXT_SIZE_S);                                //set the text size
    display_setCursor(START_MSG_1_X, START_MSG_1_Y);                //set the cursor for the text
    display_println(START_MSG_1);                                   //print the msg
};


void wamDisplay_drawGameOverScreen(){ // Draw the game-over screen.
    display_fillScreen(DISPLAY_BLACK);
    display_setTextColor(DISPLAY_WHITE);

    sprintf(endStatMsgStr1, GAME_OVER_MSG_1, statCount0);       //combine the message and the number of hits
    sprintf(endStatMsgStr2, GAME_OVER_MSG_2, statCount1);       //combine the message and the number of misses
    sprintf(endStatMsgStr3, GAME_OVER_MSG_3, statCount2);       //combine the message and the number of levels

    display_setTextSize(TEXT_SIZE_L);                               //set the text size
    display_setCursor(GAME_OVER_MSG_0_X , GAME_OVER_MSG_0_Y);               //set the cursor for the text
    display_println(GAME_OVER_MSG_0);                                   //print the game over message

    display_setTextSize(TEXT_SIZE_S);                               //set the text size
    display_setCursor(GAME_OVER_MSG_1_X , GAME_OVER_MSG_1_Y);               //set the cursor for the text
    display_println(endStatMsgStr1);                                        // String of the Hits

    display_setCursor(GAME_OVER_MSG_2_X , GAME_OVER_MSG_2_Y);               //set the cursor for the text
    display_println(endStatMsgStr2);                                        // String of the Misses

    display_setCursor(GAME_OVER_MSG_3_X , GAME_OVER_MSG_3_Y);               //set the cursor for the text
    display_println(endStatMsgStr3);                                        // String of the End Level

    display_setCursor(GAME_OVER_MSG_4_X , GAME_OVER_MSG_4_Y);               //set the cursor for the text
    display_println(GAME_OVER_MSG_4);                                       //prints the "touch to play" msg
}

// Selects a random mole and activates it.
// Activating a mole means that the ticksUntilAwake and ticksUntilDormant counts are initialized.
// See the comments for wamDisplay_moleInfo_t for details.
// Returns true if a mole was successfully activated. False otherwise. You can
// use the return value for error checking as this function should always be successful
// unless you have a bug somewhere.
bool wamDisplay_activateRandomMole(){
    uint8_t randMoleHole = rand()%(numMoleHoles); // get random Number for what region to activate
    //if active dont
    while(wamDisplay_moleInfo[randMoleHole]->ticksUntilAwake == FALSE &&
            wamDisplay_moleInfo[randMoleHole]->ticksUntilDormant == FALSE){                                  //if the mole is not awake and dormant then you can activate it
        if(wamDisplay_getActiveMoleCount() < wamDisplay_getLevel()+1 ){                                  //not let there be more moles than the current level + 1

            wamDisplay_moleInfo[randMoleHole]->ticksUntilAwake = wamControl_getRandomMoleAwakeInterval();// get how long the mole will be awake
            wamDisplay_moleInfo[randMoleHole]->ticksUntilDormant = wamControl_getRandomMoleAsleepInterval(); // get how long the mole is asleep
            return TRUE;
        }
        else{
            return FALSE;
        }
    }
    return FALSE;
};


// This takes the provided coordinates and attempts to whack a mole. If a
// mole is successfully whacked, all internal data structures are updated and
// the display and score is updated. You can only whack a mole if the mole is awake (visible).
// The return value can be used during testing (you could just print which mole is
// whacked without having to implement the entire game).
wamDisplay_moleIndex_t wamDisplay_whackMole(wamDisplay_point_t* whackOrigin){
    for(int i = FALSE;i <numMoleHoles; i++){
        if (wamDisplay_moleInfo[i]->ticksUntilAwake == FALSE &&
                    wamDisplay_moleInfo[i]->ticksUntilDormant != FALSE){
             if(abs(whackOrigin->x - wamDisplay_moleInfo[i]->origin.x ) < MOLE_RADIUS && abs(whackOrigin->y - wamDisplay_moleInfo[i]->origin.y ) < MOLE_RADIUS){// if mole is awake and non-dormant
                wamDisplay_moleInfo[i]->ticksUntilDormant = FALSE;                      // make the mole dormant
                wamDisplay_drawMole(wamDisplay_moleInfo[i]->origin, FALSE);             // erase the mole
                wamDisplay_setHitScore(statCount0+1);                                   // increment the number of hits
                wamDisplay_drawScoreScreen();                                           //update the board stats
                return i;                                                               //return the mole index
            }
        }
    }
    return FAIL; // the hit failed
};

// This updates the ticksUntilAwake/ticksUntilDormant clocks for all of the moles.
void wamDisplay_updateAllMoleTickCounts(){
    for(int i = FALSE; i<numMoleHoles; i++){
        if (wamDisplay_moleInfo[i]->ticksUntilAwake > FALSE){           // if it is not suppose to be awake then decrement it
            wamDisplay_moleInfo[i]->ticksUntilAwake--;                  // decrement the tick
            if (wamDisplay_moleInfo[i]->ticksUntilAwake == FALSE){ // when the timer hits 0 draw the mole
                wamDisplay_drawMole(wamDisplay_moleInfo[i]->origin, TRUE); // draw the mole
            }
        }
        else if (wamDisplay_moleInfo[i]->ticksUntilDormant > FALSE){            // now that the mole is awake, decrement down the dormant timer
            wamDisplay_moleInfo[i]->ticksUntilDormant--;                        // decrement the dormant counter
            if (wamDisplay_moleInfo[i]->ticksUntilDormant == FALSE){            // check for last second
                wamDisplay_drawMole(wamDisplay_moleInfo[i]->origin, FALSE);     //erase the mole
                statCount1++;                                                   //missed the mole, increment the counter
                wamDisplay_drawScoreScreen();                                   // update the score
            }
        }
    }
};

// Returns the count of currently active moles.
// A mole is active if it is not dormant, if:
// ticksUntilAwake or ticksUntilDormant are non-zero (in the moleInfo_t struct).
uint16_t wamDisplay_getActiveMoleCount(){
    uint16_t moleCounter = FALSE;                     //define a mole counter var
    for (int i = FALSE; i < numMoleHoles; i++){
        if(wamDisplay_moleInfo[i]->ticksUntilAwake > FALSE || wamDisplay_moleInfo[i]->ticksUntilDormant > FALSE){ //check if the mole[i] is either awake or dorment
            moleCounter++;                                                                                          // if so then increment the counter
        }
    }
    return moleCounter;                                                                                             //return the counter
};

// Sets the hit value in the score window.
void wamDisplay_setHitScore(uint16_t hits){
    statCount0 = hits;                                                                                          //set hits
};

// Gets the current hit value.
uint16_t wamDisplay_getHitScore(){
    return statCount0;                                                                                              //get number of hits
};

// Sets the miss value in the score window.
void wamDisplay_setMissScore(uint16_t misses){
    statCount1 = misses;                                                                                        //set misses
};

// Gets the miss value.
// Can be used for testing and other functions.
uint16_t wamDisplay_getMissScore(){
    return statCount1;                                                                                              //get miss
};

// Sets the level value on the score board.
void wamDisplay_incrementLevel(){
    statCount2++;                                                                                               //increment level
};

// Retrieves the current level value.
// Can be used for testing and other functions.
uint16_t wamDisplay_getLevel(){
    return statCount2;                                                                                              //get the level
};

// Completely draws the score screen.
// This function renders all fields, including the text fields for "Hits" and "Misses".
// Usually only called once when you are initializing the game.
void wamDisplay_drawScoreScreen(){
    display_setTextSize(TEXT_SIZE_S);                   // set the text size
    sprintf(statStr0, BOARD_STAT_0, statCount0);       //combine the message and the number of hits
    sprintf(statStr1, BOARD_STAT_1, statCount1);       //combine the message and the number of misses
    sprintf(statStr2, BOARD_STAT_2, statCount2);       //combine the message and the number of level
    display_setCursor(BOARD_STAT_0_X, BOARD_STAT_0_Y);  // set cursor for hit msg
    display_println(statStr0);                          // print hit msg
    display_setCursor(BOARD_STAT_1_X, BOARD_STAT_0_Y);  // set cursor for miss msg
    display_println(statStr1);                          // print miss msg
    display_setCursor(BOARD_STAT_2_X, BOARD_STAT_0_Y);  // set cursor for level msg
    display_println(statStr2);                          // print level msg
};

// Make this function available for testing purposes.
void wamDisplay_incrementMissScore(){
    statCount1++;                                                                                               //increment misses
};

// Reset the scores and level to restart the game.
void wamDisplay_resetAllScoresAndLevel(){
    statCount0 = FALSE;                     //reset hit var
    statCount1 = FALSE;                     //reset misses var
    statCount2 = FALSE;                     //reset level var
    for (uint16_t l=FALSE; l<numMoleHoles; l++) {
        free(wamDisplay_moleInfo[l]);   //deallocates the memory for the single mole
        wamDisplay_moleInfo[l] = NULL;
    }
    free(wamDisplay_moleInfo);   // Deallocates arrays memory
    wamDisplay_moleInfo = NULL;

};

// Test function that can be called from main() to demonstrate milestone 1.
// Invoking this function should provide the same behavior as shown in the Milestone 1 video.
void wamDisplay_runMilestone1_test(){
    uint8_t splashFlag = FALSE;         //flag to say the main screen was printed
    uint8_t boardFlag = FALSE;         //flag to say the board screen was printed
    uint8_t doneFlag = FALSE;         //flag to say the end screen was printed
    uint8_t endFlag = FALSE;         //flag to say the the whole thing was printed once
    wamDisplay_init();              //init the screen
    while (TRUE){
        if (!splashFlag){                       //if main screen has not been printed then
            wamDisplay_drawSplashScreen();      //print the main screen
            splashFlag = TRUE;                  //raise the flag
        }
        if (display_isTouched()){
            splashFlag = FALSE;                 //lower flag for the next time through
            while (TRUE){
                wamDisplay_drawScoreScreen();
                if (!boardFlag){
                    wamDisplay_drawMoleBoard();      //print the board screen
                    boardFlag = TRUE;                  //raise the flag
                }
                if (display_isTouched()){
                    boardFlag = FALSE;                 //lower flag for the next time through
                    while (TRUE){
                        if (!doneFlag){
                            wamDisplay_drawGameOverScreen();           //print the end screen
                            doneFlag = TRUE;                  //raise the flag
                        }
                        if (display_isTouched()){
                            doneFlag = FALSE;                 //lower flag for the next time through
                            endFlag = TRUE;                  //raise the flag saying that the sequence has been printed once
                            break;
                        }
                    }
                    break;
                }
            }
        }
        if(endFlag){                                         // if the 3 screens have been printed then exit the loop
            break;
        }
    }
};

// Helper Function to Draw a Mole
void wamDisplay_drawMole(wamDisplay_point_t moleReion, uint8_t drwMole){
    if(drwMole){
        display_fillCircle(moleReion.x, moleReion.y, MOLE_RADIUS, DISPLAY_RED);         //if you want to draw the mole then print the circle red
    }
    else{
        display_fillCircle(moleReion.x, moleReion.y, MOLE_RADIUS, DISPLAY_BLACK);         //if you want to erase the mole then print the circle black
    }
}

// Helper Function to Draw all the Mole Holes
void wamDisplay_drawAllMoleHoles(){
    if (numMoleHoles == 4){                                                 //draw all the holes for a 4 board
        wamDisplay_drawMoleHole(MOLE_HOLE_0_0, TRUE);                       //draw hole 1
        wamDisplay_drawMoleHole(MOLE_HOLE_2_0, TRUE);                       //draw hole 2
        wamDisplay_drawMoleHole(MOLE_HOLE_0_2, TRUE);                       //draw hole 3
        wamDisplay_drawMoleHole(MOLE_HOLE_2_2, TRUE);                       //draw hole 4
    }
    else if(numMoleHoles == 6){                                              //draw all the holes for a 6 board
        wamDisplay_drawMoleHole(MOLE_HOLE_0_0, TRUE);                       //draw hole 1
        wamDisplay_drawMoleHole(MOLE_HOLE_1_0, TRUE);                       //draw hole 2
        wamDisplay_drawMoleHole(MOLE_HOLE_2_0, TRUE);                       //draw hole 3
        wamDisplay_drawMoleHole(MOLE_HOLE_0_2, TRUE);                       //draw hole 4
        wamDisplay_drawMoleHole(MOLE_HOLE_1_2, TRUE);                       //draw hole 5
        wamDisplay_drawMoleHole(MOLE_HOLE_2_2, TRUE);                       //draw hole 6
    }
    else if(numMoleHoles == 9){                                              //draw all the holes for a 9 board
        wamDisplay_drawMoleHole(MOLE_HOLE_0_0, TRUE);
        wamDisplay_drawMoleHole(MOLE_HOLE_1_0, TRUE);                       //draw hole 1
        wamDisplay_drawMoleHole(MOLE_HOLE_2_0, TRUE);                       //draw hole 2
        wamDisplay_drawMoleHole(MOLE_HOLE_0_1, TRUE);                       //draw hole 3
        wamDisplay_drawMoleHole(MOLE_HOLE_1_1, TRUE);                       //draw hole 4
        wamDisplay_drawMoleHole(MOLE_HOLE_2_1, TRUE);                       //draw hole 5
        wamDisplay_drawMoleHole(MOLE_HOLE_0_2, TRUE);                       //draw hole 6
        wamDisplay_drawMoleHole(MOLE_HOLE_1_2, TRUE);                       //draw hole 7
        wamDisplay_drawMoleHole(MOLE_HOLE_2_2, TRUE);                       //draw hole 8
    }
};

// Helper Function to one Mole Hole
void wamDisplay_drawMoleHole(uint8_t moleHoleReion, uint8_t drwHole ){
    if(drwHole){
        switch (moleHoleReion){
        case MOLE_HOLE_0_0:                                                                                 //if the mole hole region is 0
            display_fillCircle(MOLE_HOLE_0_X, MOLE_HOLE_0_Y, MOLE_HOLE_RADIUS, DISPLAY_BLACK);              //erase the mole hole in this region
            break;
        case MOLE_HOLE_1_0:                                                                                 //if the mole hole region is 1
            display_fillCircle(MOLE_HOLE_1_X, MOLE_HOLE_0_Y, MOLE_HOLE_RADIUS, DISPLAY_BLACK);              //erase the mole hole in this region
            break;
        case MOLE_HOLE_2_0:                                                                                 //if the mole hole region is 2
            display_fillCircle(MOLE_HOLE_2_X, MOLE_HOLE_0_Y, MOLE_HOLE_RADIUS, DISPLAY_BLACK);              //erase the mole hole in this region
            break;
        case MOLE_HOLE_0_1:                                                                                 //if the mole hole region is 3
            display_fillCircle(MOLE_HOLE_0_X, MOLE_HOLE_1_Y, MOLE_HOLE_RADIUS, DISPLAY_BLACK);              //erase the mole hole in this region
            break;
        case MOLE_HOLE_1_1:                                                                                 //if the mole hole region is 4
            display_fillCircle(MOLE_HOLE_1_X, MOLE_HOLE_1_Y, MOLE_HOLE_RADIUS, DISPLAY_BLACK);              //erase the mole hole in this region
            break;
        case MOLE_HOLE_2_1:                                                                                 //if the mole hole region is 5
            display_fillCircle(MOLE_HOLE_2_X, MOLE_HOLE_1_Y, MOLE_HOLE_RADIUS, DISPLAY_BLACK);              //erase the mole hole in this region
            break;
        case MOLE_HOLE_0_2:                                                                                 //if the mole hole region is 6
            display_fillCircle(MOLE_HOLE_0_X, MOLE_HOLE_2_Y, MOLE_HOLE_RADIUS, DISPLAY_BLACK);              //erase the mole hole in this region
            break;
        case MOLE_HOLE_1_2:                                                                                 //if the mole hole region is 7
            display_fillCircle(MOLE_HOLE_1_X, MOLE_HOLE_2_Y, MOLE_HOLE_RADIUS, DISPLAY_BLACK);              //erase the mole hole in this region
            break;
        case MOLE_HOLE_2_2:                                                                                 //if the mole hole region is 8
            display_fillCircle(MOLE_HOLE_2_X, MOLE_HOLE_2_Y, MOLE_HOLE_RADIUS, DISPLAY_BLACK);              //erase the mole hole in this region
            break;
        }
    }
    else{                                                                                      //I dont think I ever use this function
        switch (moleHoleReion){
        case MOLE_HOLE_0_0:                                                                                 //if the mole region is 0
            display_fillCircle(MOLE_HOLE_0_X, MOLE_HOLE_0_Y, MOLE_RADIUS, DISPLAY_RED);                     //draw the mole in this region
            break;
        case MOLE_HOLE_1_0:                                                                                 //if the mole region is 1
            display_fillCircle(MOLE_HOLE_1_X, MOLE_HOLE_0_Y, MOLE_RADIUS, DISPLAY_RED);                     //draw the mole in this region
            break;
        case MOLE_HOLE_2_0:                                                                                 //if the mole region is 2
            display_fillCircle(MOLE_HOLE_2_X, MOLE_HOLE_0_Y, MOLE_RADIUS, DISPLAY_RED);                     //draw the mole in this region
            break;
        case MOLE_HOLE_0_1:                                                                                 //if the mole region is 3
            display_fillCircle(MOLE_HOLE_0_X, MOLE_HOLE_1_Y, MOLE_RADIUS, DISPLAY_RED);                     //draw the mole in this region
            break;
        case MOLE_HOLE_1_1:                                                                                 //if the mole region is 4
            display_fillCircle(MOLE_HOLE_1_X, MOLE_HOLE_1_Y, MOLE_RADIUS, DISPLAY_RED);                     //draw the mole in this region
            break;
        case MOLE_HOLE_2_1:                                                                                 //if the mole region is 5
            display_fillCircle(MOLE_HOLE_2_X, MOLE_HOLE_1_Y, MOLE_RADIUS, DISPLAY_RED);                     //draw the mole in this region
            break;
        case MOLE_HOLE_0_2:                                                                                 //if the mole region is 6
            display_fillCircle(MOLE_HOLE_0_X, MOLE_HOLE_2_Y, MOLE_RADIUS, DISPLAY_RED);                     //draw the mole in this region
            break;
        case MOLE_HOLE_1_2:                                                                                 //if the mole region is 7
            display_fillCircle(MOLE_HOLE_1_X, MOLE_HOLE_2_Y, MOLE_RADIUS, DISPLAY_RED);                     //draw the mole in this region
            break;
        case MOLE_HOLE_2_2:                                                                                 //if the mole region is 8
            display_fillCircle(MOLE_HOLE_2_X, MOLE_HOLE_2_Y, MOLE_RADIUS, DISPLAY_RED);                     //draw the mole in this region
            break;
        }
    }
};
void wamDisplay_getMoleCoor(uint16_t index){
    if( numMoleHoles == BOARD_NUM_HOLES_4){                         //gets the mole coordinates for the 4 board
        switch (index){
        case MOLE_HOLE_0_0:                                        //if the mole region is 0
            moleCoord.x = MOLE_HOLE_0_X;                           //get the X coordinate for this mole
            moleCoord.y = MOLE_HOLE_0_Y;                           //get the Y coordinate for this mole
            break;
        case MOLE_HOLE_1_0:                                        //if the mole region is 1
             moleCoord.x = MOLE_HOLE_2_X;                           //get the X coordinate for this mole
             moleCoord.y = MOLE_HOLE_0_Y;                           //get the Y coordinate for this mole
             break;
        case MOLE_HOLE_2_0:                                        //if the mole region is 2
             moleCoord.x = MOLE_HOLE_0_X;                           //get the X coordinate for this mole
             moleCoord.y = MOLE_HOLE_2_Y;                           //get the Y coordinate for this mole
             break;
        case MOLE_HOLE_0_1:                                        //if the mole region is 3
             moleCoord.x = MOLE_HOLE_2_X;                           //get the X coordinate for this mole
             moleCoord.y = MOLE_HOLE_2_Y;                           //get the Y coordinate for this mole
             break;
        }
    }
    else if( numMoleHoles == BOARD_NUM_HOLES_6){                         //gets the mole coordinates for the 6 board
        switch (index){
            case MOLE_HOLE_0_0:                                        //if the mole region is 0
                moleCoord.x = MOLE_HOLE_0_X;                           //get the X coordinate for this mole
                moleCoord.y = MOLE_HOLE_0_Y;                           //get the Y coordinate for this mole
                break;
            case MOLE_HOLE_1_0:                                        //if the mole region is 1
                moleCoord.x = MOLE_HOLE_1_X;                           //get the X coordinate for this mole
                moleCoord.y = MOLE_HOLE_0_Y;                           //get the Y coordinate for this mole
                break;
            case MOLE_HOLE_2_0:                                        //if the mole region is 2
                moleCoord.x = MOLE_HOLE_2_X;                           //get the X coordinate for this mole
                moleCoord.y = MOLE_HOLE_0_Y;                           //get the Y coordinate for this mole
                break;
            case MOLE_HOLE_0_1:                                        //if the mole region is 3
                moleCoord.x = MOLE_HOLE_0_X;                           //get the X coordinate for this mole
                moleCoord.y = MOLE_HOLE_2_Y;                           //get the Y coordinate for this mole
                break;
            case MOLE_HOLE_1_1:                                        //if the mole region is 4
                moleCoord.x = MOLE_HOLE_1_X;                           //get the X coordinate for this mole
                moleCoord.y = MOLE_HOLE_2_Y;                           //get the Y coordinate for this mole
                break;
            case MOLE_HOLE_2_1:                                        //if the mole region is 5
                moleCoord.x = MOLE_HOLE_2_X;                           //get the X coordinate for this mole
                moleCoord.y = MOLE_HOLE_2_Y;                           //get the Y coordinate for this mole
                break;
        }
    }
    else if( numMoleHoles == BOARD_NUM_HOLES_9){                         //gets the mole coordinates for the 9 board
        switch (index){
            case MOLE_HOLE_0_0:                                        //if the mole region is 0
                moleCoord.x = MOLE_HOLE_0_X;                           //get the X coordinate for this mole
                moleCoord.y = MOLE_HOLE_0_Y;                           //get the Y coordinate for this mole
                break;
            case MOLE_HOLE_1_0:                                        //if the mole region is 1
                moleCoord.x = MOLE_HOLE_1_X;                           //get the X coordinate for this mole
                moleCoord.y = MOLE_HOLE_0_Y;                           //get the Y coordinate for this mole
                break;
            case MOLE_HOLE_2_0:                                        //if the mole region is 2
                moleCoord.x = MOLE_HOLE_2_X;                           //get the X coordinate for this mole
                moleCoord.y = MOLE_HOLE_0_Y;                           //get the Y coordinate for this mole
                break;
            case MOLE_HOLE_0_1:                                        //if the mole region is 3
                moleCoord.x = MOLE_HOLE_0_X;                           //get the X coordinate for this mole
                moleCoord.y = MOLE_HOLE_1_Y;                           //get the Y coordinate for this mole
                break;
            case MOLE_HOLE_1_1:                                        //if the mole region is 4
                moleCoord.x = MOLE_HOLE_1_X;                           //get the X coordinate for this mole
                moleCoord.y = MOLE_HOLE_1_Y;                           //get the Y coordinate for this mole
                break;
            case MOLE_HOLE_2_1:                                        //if the mole region is 5
                moleCoord.x = MOLE_HOLE_2_X;                           //get the X coordinate for this mole
                moleCoord.y = MOLE_HOLE_1_Y;                           //get the Y coordinate for this mole
                break;
            case MOLE_HOLE_0_2:                                        //if the mole region is 6
                moleCoord.x = MOLE_HOLE_0_X;                           //get the X coordinate for this mole
                moleCoord.y = MOLE_HOLE_2_Y;                           //get the Y coordinate for this mole
                break;
            case MOLE_HOLE_1_2:                                        //if the mole region is 7
                moleCoord.x = MOLE_HOLE_1_X;                           //get the X coordinate for this mole
                moleCoord.y = MOLE_HOLE_2_Y;                           //get the Y coordinate for this mole
                break;
            case MOLE_HOLE_2_2:                                        //if the mole region is 8
                moleCoord.x = MOLE_HOLE_2_X;                           //get the X coordinate for this mole
                moleCoord.y = MOLE_HOLE_2_Y;                           //get the Y coordinate for this mole
                break;
        }
    }
}

