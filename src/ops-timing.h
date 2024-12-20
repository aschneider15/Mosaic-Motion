#ifndef OPS_TIMING_H
#define OPS_TIMING_H

#include <gb/gb.h>
#include <stdint.h>
#include <rand.h>

/* Global variable used to control most animations and non-halting delays. */
extern uint8_t g_framecounter;

/* Delays an action by waiting for vblank to occur for the given number of frames (originally written by GamingMonsters).
    \param frames The number of frames meant to be delayed; 0 is the shortest delay, and 255 is the longest.
*/
void PerformantDelay(uint8_t frames);

/* Call to increment the frame counter. Calling this function also calls vsync() in order to ensure smooth animation timing.*/
inline void IncrementFrame(void);

#endif