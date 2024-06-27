#include <gb/gb.h>
#include <stdint.h>
#include "timing-ops.h"

#define WHT3 0x00 // pure white
#define WHT2 0x40 // mostly white
#define WHT1 0x90 // white tint
#define NTRL 0xE4 // natural colors
#define BLK1 0xF9 // black tint
#define BLK2 0xFE // mostly black
#define BLK3 0xFF // pure black



/* Transition the screen from black to normal colors
    \param speed speed of color transition with 0 being fastest (1/60 of a second), and 255 being slowest (255/60 of a second).
*/
void BlkFadeIn(uint8_t speed);

/* Transition the screen from normal colors to black
    \param speed speed of color transition with 0 being fastest (1/60 of a second), and 255 being slowest (255/60 of a second).
*/
void BlkFadeOut(uint8_t speed);

/* Shake the screen by offsetting background tiles rapidly.
    \param speed Speed of oscillations with 0 being fastest (1/60 of a second), and 255 being slowest (255/60 of a second).
    \param intensity How many pixels are offset with each oscillation with 0 being smallest (0 px) and 255 being the greatest (255 px).
    \param times How many times the screen should shake.
    \param direction Pass in 0 for left-to-right movement, and 1 for up-and-down movement.
 */
void ShakeScreen(uint8_t speed, uint8_t intensity, BOOLEAN direction, uint8_t times);

/* Transition the screen from white to normal colors
    \param speed speed of color transition with 0 being fastest (1/60 of a second), and 255 being slowest (255/60 of a second).
*/
void WhtFadeIn(uint8_t speed);

/* Transition the screen from normal colors to white
    \param speed speed of color transition with 0 being fastest (1/60 of a second), and 255 being slowest (255/60 of a second).
*/
void WhtFadeOut(uint8_t speed);
