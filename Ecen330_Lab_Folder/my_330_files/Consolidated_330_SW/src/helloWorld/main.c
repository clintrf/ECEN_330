
// Print out "hello world" on both the console and the LCD screen.

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int main() {
    int8_t a = 0b00000001;
    int8_t b = 0b10000000;
    int16_t c;
    c = a ^ b;
    printf("%b\n", c);
}


// This function must be defined but can be left empty for now.
// You will use this function in a later lab.
// It is called in the timer interrupt service routine (see interrupts.c in supportFiles).
void isr_function() {
    // Empty for now.
}
