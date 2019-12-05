/*
 * buttons.c
 *
 *  Created on: May 11, 2017
 *      Author: clintrf
 */
#include "buttons.h"
#include "supportFiles/display.h"
#include "xil_io.h" // Helper function to read GPIO registers.

#define GPIO_DATA_OFFSET 0x00 //offset for the GPIO_DATA register
#define GPIO_TRI_OFFSET 0x04 //offset for the GPIO_TRI register
#define GPIO_TRI_SET_INPUT 1 //start input

#define BUTTONS_ALL_BUTTONS_PRESSED 0x0F // if all the buttons are pressed
#define BUTTONS_TEXT_SIZE 2 // The size of the text to display on screen

// How big the rectangle is
// They are all the same size, so use the same values
#define BUTTONS_ALL_BUTTONS_X_LENGTH DISPLAY_WIDTH/4 //how big to make the box in the x direction (aka one forth)
#define BUTTONS_ALL_BUTTONS_Y_LENGTH DISPLAY_HEIGHT/2 //how big to make the box in the y direction (aka half)
#define BUTTONS_ALL_BUTTONS_X_LENGTH_BASE 0 //where the screen starts x
#define BUTTONS_ALL_BUTTONS_Y_LENGTH_BASE 0 //where the screen starts y
#define BUTTONS_CURS_SHIFT 18 // how far to shift over


#define BUTTONS_TEXT_Y_POSITION 55 // All button's text is on the same line, so share the value

// Button 1's on screen rectangle values
#define BUTTONS_BUTTON0_X_CORD DISPLAY_WIDTH-(DISPLAY_WIDTH/4) //x cord for 1st box

#define BUTTONS_BUTTON1_X_CORD DISPLAY_WIDTH/2 //x cord for 2nd box

#define BUTTONS_BUTTON2_X_CORD DISPLAY_WIDTH/4 //x cord for 3rd box

#define BUTTONS_BUTTON3_X_CORD 0 //x cord for 3rd box


#define BUTTONS_GPIO_DEVICE_BASE_ADDRESS XPAR_PUSH_BUTTONS_BASEADDR //define base address


#define BUTTONS_TRUE 1 //when things are true return 1
#define BUTTONS_FALSE 0 //when things are false return 0
#define BUTTONS_BNT0 0 //matching number to text for box 1
#define BUTTONS_BNT1 1 //matching number to text for box 2
#define BUTTONS_BNT2 2 //matching number to text for box 3
#define BUTTONS_BNT3 3 //matching number to text for box 4

//**********Prototype_Functions**********
int32_t buttons_readGpioRegister(int32_t offset);//Reading from the register function prototype
void buttons_writeGpioRegister(int32_t offset, int32_t value);//Writing to the register function prototype
void display_buttons(int16_t x_cor, uint16_t box_color, int16_t text_color, int16_t btn_number);

//**********Main_Functions**********
// Initializes the button driver software and hardware. Returns one of the defined status values (above).
int32_t buttons_init(){
    buttons_writeGpioRegister(GPIO_TRI_OFFSET, GPIO_TRI_SET_INPUT);
    if(GPIO_TRI_SET_INPUT == buttons_readGpioRegister(GPIO_DATA_OFFSET)){
        return BUTTONS_INIT_STATUS_OK; //register was updated
    }
    else{
        return BUTTONS_INIT_STATUS_FAIL;//register was not updated
    }
}

// Returns the current value of all 4 buttons as the lower 4 bits of the returned value.
// bit3 = BTN3, bit2 = BTN2, bit1 = BTN1, bit0 = BTN0.
int32_t buttons_read(){
    return buttons_readGpioRegister(GPIO_DATA_OFFSET);
}

// Runs a test of the buttons. As you push the buttons, graphics and messages will be written to the LCD
// panel. The test will until all 4 pushbuttons are simultaneously pressed.
void buttons_runTest(){
    buttons_init(); //Initializes the buttons
    display_init(); //Initializes the screen
    display_fillScreen(DISPLAY_BLACK); //fills the screen black
    char B0_pressed = BUTTONS_FALSE; //initializing B0
    char B1_pressed = BUTTONS_FALSE; //initializing B1
    char B2_pressed = BUTTONS_FALSE; //initializing B2
    char B3_pressed = BUTTONS_FALSE; //initializing B3
    int32_t ButtonsPressed = buttons_read();
    while(ButtonsPressed != BUTTONS_ALL_BUTTONS_PRESSED){
        ButtonsPressed = buttons_read();
        if((ButtonsPressed & BUTTONS_BTN0_MASK) && !B0_pressed){ //checks against the Mask to see if button 0 is pressed
            display_buttons(BUTTONS_BUTTON0_X_CORD, DISPLAY_YELLOW, DISPLAY_BLACK, BUTTONS_BNT0);
            B0_pressed = BUTTONS_TRUE;
        }
        else if(!(ButtonsPressed & BUTTONS_BTN0_MASK) && B0_pressed){ //checks against the Mask to see if button 0 is not pressed
            display_buttons(BUTTONS_BUTTON0_X_CORD, DISPLAY_BLACK, DISPLAY_BLACK, BUTTONS_BNT0);
            B0_pressed = BUTTONS_FALSE;
        }
        if((ButtonsPressed & BUTTONS_BTN1_MASK) && !B1_pressed){ //checks against the Mask to see if button 1 is pressed
            display_buttons(BUTTONS_BUTTON1_X_CORD, DISPLAY_CYAN, DISPLAY_BLACK, BUTTONS_BNT1);
            B1_pressed = BUTTONS_TRUE;
        }
        else if(!(ButtonsPressed & BUTTONS_BTN1_MASK) && B1_pressed){ //checks against the Mask to see if button 1 is not pressed
            display_buttons(BUTTONS_BUTTON1_X_CORD, DISPLAY_BLACK, DISPLAY_BLACK, BUTTONS_BNT1);
            B1_pressed = BUTTONS_FALSE;
        }
        if((ButtonsPressed & BUTTONS_BTN2_MASK) && !B2_pressed){ //checks against the Mask to see if button 2 is pressed
            display_buttons(BUTTONS_BUTTON2_X_CORD, DISPLAY_RED, DISPLAY_WHITE, BUTTONS_BNT2);
            B2_pressed = BUTTONS_TRUE;
        }
        else if(!(ButtonsPressed & BUTTONS_BTN2_MASK) && B2_pressed){ //checks against the Mask to see if button 2 is not pressed
            display_buttons(BUTTONS_BUTTON2_X_CORD, DISPLAY_BLACK, DISPLAY_BLACK, BUTTONS_BNT2);
            B2_pressed = BUTTONS_FALSE;
        }
        if((ButtonsPressed & BUTTONS_BTN3_MASK) && !B3_pressed){ //checks against the Mask to see if button 3 is pressed
            display_buttons(BUTTONS_BUTTON3_X_CORD, DISPLAY_BLUE, DISPLAY_WHITE, BUTTONS_BNT3);
            B3_pressed = BUTTONS_TRUE;
        }
        else if(!(ButtonsPressed & BUTTONS_BTN3_MASK) && B3_pressed){ //checks against the Mask to see if button 3 is not pressed
            display_buttons(BUTTONS_BUTTON3_X_CORD, DISPLAY_BLACK, DISPLAY_BLACK, BUTTONS_BNT3);
            B3_pressed = BUTTONS_FALSE;
        }
    }
    display_fillScreen(DISPLAY_BLACK); //fills the screen black
}
//**********Helper_Functions**********
int32_t buttons_readGpioRegister(int32_t offset){// Reads from the register
    //use the low-level Xilinx call.
    return Xil_In32(BUTTONS_GPIO_DEVICE_BASE_ADDRESS + offset);
}
void buttons_writeGpioRegister(int32_t offset, int32_t value){// Writes to the register
    Xil_Out32(BUTTONS_GPIO_DEVICE_BASE_ADDRESS + offset, value);//use the low-level Xilinx call.
}
void display_buttons(int16_t x_cor, uint16_t box_color, int16_t text_color, int16_t btn_number){ //function to display boxes and text on screen
    display_fillRect(x_cor, BUTTONS_ALL_BUTTONS_Y_LENGTH_BASE, BUTTONS_ALL_BUTTONS_X_LENGTH, BUTTONS_ALL_BUTTONS_Y_LENGTH, box_color); //fills the box
    display_setCursor(x_cor + BUTTONS_CURS_SHIFT, BUTTONS_TEXT_Y_POSITION); //sets the cursor
    display_setTextColor(text_color); //sets the color of the text
    display_setTextSize(BUTTONS_TEXT_SIZE); // sets the size of the text
    display_print("BTN"); // writes out the name of the box
    display_println(btn_number); //writes out the number of the box
}

