#ifndef INPUT_OPS
#define INPUT_OPS

#include <gb/gb.h>
#include <stdint.h>

/* Enables a soft reset input (A + B + Start + Select)
    @param input The current player's input read from a call to joypad().
    @returns 1 if selection is entered by pressing A, or -1 if phase is cancelled by pressing B.
 */
inline void SoftReset(uint8_t input);

#endif