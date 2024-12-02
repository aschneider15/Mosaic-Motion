#ifndef SCENE_SELECTION_H
#define SCENE_SELECTION_H

#include <gb/gb.h>
#include <stdint.h>
#include <gb/sgb.h>
#include <string.h>
#include "../huge/hUGEDriver.h"

#include "./ops-vital.h"
#include "./ops-screen.h"
#include "../res/tiles_general.h"
#include "../res/bkg_selection.h"
#include "../res/uimap_dialogbox.h"
#include "../res/uimap_select-curtain.h"

/* Ten bits that hold the user's selected settings:
    - First set of two bits are the user's desired difficulty
    - Second set of one bit is the user's desired game style
    - Third set of two bits are the user's desired game mode
    - Fourth set of two bits are the user's desired music track
    - Fifth set of three bits are the user's desired map
    - initial padding of six bits go unused...: XXXXXX|00|0|00|00|000
 */
static uint16_t settings = 0b0000000000000000;

/*Selection phase to handle transitions between options
    - 0 -> return to previous scene
    - 1 -> select difficulty
    - 2 -> select style
    - 3 -> select mode
    - 4 -> select BGM
    - 5 -> select puzzle
    - 6 -> proceed to next scene
 */
static uint8_t phase;

static uint8_t incomplete[36] = "That feature isn'tDone yet, sorry!\0";

// bounding box for allowed cursor movements:
static uint8_t cursor_x_lower_bound = 0;
static uint8_t cursor_x_upper_bound = 0;
static uint8_t cursor_y_lower_bound = 0;
static uint8_t cursor_y_upper_bound = 0;

// current cursor positions
static uint8_t cursor_x = 0;
static uint8_t cursor_y = 0;

/* The y-positions which the scrolling window can be in at a given time, with the exception of 112 and 0. */
static const uint8_t scroll_positions[15] = {111, 110, 108, 105, 101, 96, 90, 84, 76, 68, 59, 49, 38, 26, 13};

/* Initialize the background, sprites, music, etc. of the scene */
void SelectionInit(void);

/* Controls the player's difficulty selection
 */
void DifficultySelection(void);

/* Controls the player's style selection
 */
void StyleSelection(void);

/* Controls the player's mode selection
 */
void ModeSelection(void);

/* Controls the player's music selection
 */
void MusicSelection(void);

/* Controls the player's puzzle image selection
 */
void PuzzleSelection(void);

/* Lowers the window to reveal screen */
void WindowOpen(void);

/* Raises the window to mask screen transition */
void WindowClose(void);

/* Operates the main loop for the Selection scene */
uint8_t SelectionMainLoop(void);


#endif