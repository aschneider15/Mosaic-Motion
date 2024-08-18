#ifndef STANDARD_MODE_SCENE_H
#define STANDARD_MODE_SCENE_H

#include <gb/gb.h>
#include <stdint.h>

#include "dialogbox.h"
#include "screen-ops.h"
#include "timing-ops.h"
#include "../res/bkg_md_std.h"
#include "../res/tiles_general.h"
#include "../res/tiles_gonefishing.h"


#define BOARD_DIMENSION 12
#define BOARD_DIMENSION_PX 96

// The non-constant data in which the puzzle's current arrangement is represented.
static uint8_t puzzle_map[144] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static uint8_t cur_arrange[36]; // Current arrangment of tiles in the puzzle

static uint8_t game_won; // Check that confirms that the game is won. Is set using the function CheckWinCondition.

static uint8_t piece_size; // The size of a single mosaic metatile in hardware tiles. Will be either 3 (easy), 4 (medium) or 6 (hard).
static uint8_t board_size; // The size of the entire board in mosaic metatiles.
static uint8_t cur_sprite_data[16]; // The sprite tiles of the mosaic piece being moved.

static uint8_t blank_pos_x; // The x-position of the blank space. 
static uint8_t blank_pos_y; // The y-position of the blank space. 

static uint16_t operations; // The number of inputs the player has performed. Used to calculate score
static uint8_t mibisecs; // The number of second-fractions since the start of the puzzle. Measured in 60ths of a second.
static uint8_t secs; // The number of seconds since the start of the puzzle.
static uint8_t mins; // The number of minutes since the start of the puzzle. Along with seconds and mibiseconds, this is used in score calculation.

/* Fills the designated portion of VRAM for mosaic puzzle tiles. The number passed into it will determine which bank will be pulled from for puzzle data.
 */
void GetPuzzle(uint8_t rand);

/* Call to initialize the puzzle's arrangement. This is to be called only once per round.
 */
void PartitionTiles(uint8_t difficulty);

/* Moves a tile adjacent to the "blank space" into the blank space. Movement is opposite of player movement (i.e. J_UP will result in the tile moving down) to give the illusion of the "blank space" moving. If a tile cannot be moved in a given direction, then the operation will fail.
    @param input Player input as measured through joypad().
 */
void MoveMetaTile(uint8_t input);

/* Checks whether the player has met the win condition or not. Checks to see if the tiles in cur_arrange are in ascending order (i.e. 0 < 1; 1 < 2; 2 < 3, etc.)
 */
void CheckWinCondition(void);

/* The player's performance is graded based on the number of moves in relation to the time taken to complete the puzzle. 
 */
uint16_t CalculateScore(void);

/* Operates the main loop for the Standard Mode scene.
 */
void StandardModeMainLoop(void);

#endif