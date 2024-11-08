#ifndef OPS_SCREEN_H
#define OPS_SCREEN_H

#include <gb/gb.h>
#include <stdint.h>
#include "ops-timing.h"
#include <string.h>
#include <stdio.h>
#include "../res/uimap_dialogbox.h"
#include "../res/tiles_general.h"

#define WHT3 0x00 // pure white
#define WHT2 0x40 // mostly white
#define WHT1 0x90 // white tint
#define NTRL 0xE4 // natural colors
#define BLK1 0xF9 // black tint
#define BLK2 0xFE // mostly black
#define BLK3 0xFF // pure black

/* ************************************* */
/* Screen Manipulation related functions */
/* ************************************* */

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

/* *************************** */
/* Dialogbox related functions */
/* *************************** */

/* Fills the window with the tiles required to render a blank dialog box 
    Note: the default size of the dialoge box supports two lines of eighteen chars.
*/
void SetDialogTiles(void);

/* Sets the tiles in the window layer to the eighteen characters which are passed. Bear in mind that the first eighteen characters will occupy the first line, and the second set will follow below.
    \param phrase Eighteen characters for the first line, followed immediately by the eighteen characters of the second line. Any greater number of characters will result in truncated text.
*/
void SetText(uint8_t phrase[36]);

/* Sets the label or "speaker" tiles in the window layer to the (maximum) seventeen characters which are passed. It terminates upon encountering NULL, upon which the 'label end' tile will be drawn. If no label is desired, pass a single forward slash ("/").
    \param label Up to seventeen characters to be placed starting on the second tile of the first row of the window layer.
*/
void SetLabel(uint8_t label[17]);

/* Converts the letter into a writable tile corresponding to the general tileset.
    \param let The letter which is to be translated.
 */
uint8_t ConvertLetterToTile(char let);

/* Uses previously defined functions to create a dialogue box to display to the screen. 
    \param phrase Eighteen characters for the first line, followed immediately by the eighteen characters of the second line. Any greater number of characters will result in truncated text.
    \param label Up to seventeen characters to be placed starting on the second tile of the first row of the window layer.
 */
void DisplayDialogBox(uint8_t phrase[36], uint8_t label[17]);

#endif
