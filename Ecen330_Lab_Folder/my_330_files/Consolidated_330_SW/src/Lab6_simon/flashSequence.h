/*
 * flashSequence.h
 *
 *  Created on: Jun 1, 2017
 *      Author: clintrf
 */


#ifndef FLASHSEQUENCE_H_
#define FLASHSEQUENCE_H_

// Turns on the state machine. Part of the interlock.
void flashSequence_enable();

// Turns off the state machine. Part of the interlock.
void flashSequence_disable();

// Other state machines can call this to determine if this state machine is finished.
bool flashSequence_isComplete();

// Standard tick function.
void flashSequence_tick();

// Tests the flashSequence state machine.
void flashSequence_runTest();

#endif /* FLASHSEQUENCE_H_ */
