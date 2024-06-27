#include <gb/gb.h>
#include <stdint.h>
#include <rand.h>

/* Delays an action by waiting for vblank to occur for the given number of frames (originally written by GamingMonsters)
    \param frames The number of frames meant to be delayed; 0 is the shortest delay, and 255 is the longest.
*/
void PerformantDelay(uint8_t frames);