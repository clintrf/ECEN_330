/*
 * main.c
 *
 *  Created on: May 11, 2017
 *      Author: clintrf
 */

#include "supportFiles/leds.h"
#include "switches.h"
#include "buttons.h"

int main() {
    switches_runTest();
    buttons_runTest();




}

void isr_function() {
    // Empty for now.
}




