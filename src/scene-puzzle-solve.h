#ifndef SCENE_PUZZLE_SOLVE_H
#define SCENE_PUZZLE_SOLVE_H

#include <gb/gb.h>
#include <stdint.h>
#include "../huge/hUGEDriver.h"

#include "ops-vital.h"
#include "ops-screen.h"
#include "ops-timing.h"
#include "../res/bkg_md_std.h"
#include "../res/tiles_general.h"
#include "../res/tiles_gonefishing.h"

// *
#define BOARD_DIMENSION 12
#define BOARD_DIMENSION_PX 96

// The non-constant data in which the puzzle's current arrangement is represented.
// *
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

// The memory address of the base tiles of the puzzle to be drawn.
// *
static uint8_t * base_puzzle;
// *
static uint8_t cur_arrange[36]; // Current arrangment of tiles in the puzzle
// *
static uint8_t game_won; // Check that confirms that the game is won. Is set using the function CheckWinCondition.
// *
static uint8_t piece_size; // The size of a single mosaic metatile in hardware tiles. Will be either 4 (easy), 3 (medium) or 2 (hard).
static uint8_t board_size; // The size of one dimension of the entire board in mosaic metatiles. Will be either 3 (easy), 4 (medium) or 6 (hard).
static uint8_t total_board_size; // The size of the board in both x and y dimensions. Assigned to be board_size * board_size.
static uint8_t total_piece_size; // The size of a single piece in both x and y dimensions. Assigned to be piece_size * piece_size.
static uint8_t cur_sprite_data[16]; // The sprite tiles of the mosaic piece being moved.

static uint8_t blank_pos_x; // The x-position of the blank space. 
static uint8_t blank_pos_y; // The y-position of the blank space. 

static uint16_t operations; // The number of inputs the player has performed. Used to calculate score
static uint8_t secs; // The number of seconds since the start of the puzzle.
static uint8_t mins; // The number of minutes since the start of the puzzle. Along with seconds, this is used in score calculation.

/* Fills the designated portion of VRAM for mosaic puzzle tiles. The number passed into it will determine which bank will be pulled from for puzzle data.
 */
void GetPuzzle(uint8_t rand);

/* Call to initialize the puzzle's arrangement. This is to be called only once per round.
 */
void PartitionTiles(uint8_t difficulty);

/* Returns the beginning index for a mosaic metatile which correspond to the index provided from the current arrangement.
    @param base_tile The mosaic metatile in the current arrangment for which this function finds the corresponding starting hardware tile in the base puzzle. 
 */
inline uint8_t GetPuzzleIndexFromBaseTile(uint8_t base_tile);

/* 
 */
void SetCurrentPuzzleData(void);

/* 
 */
void PopulateSpriteData(uint8_t mosaic_tile_index);

/* Moves a tile adjacent to the "blank space" into the blank space. Movement is opposite of player movement (i.e. J_UP will result in the tile moving down) to give the illusion of the "blank space" moving. If a tile cannot be moved in a given direction, then the operation will fail.
    @param input Player input as measured through joypad().
 */
void StandardModeMovement(uint8_t input);

/* Calculatest the number of inversions that occurr in the current puzzle arrangment. An inversion occurs whenever a higher number preceeds a lower number in the arrangment (eg. '8 2 4' would yield two inversions, since 8 > 2 and 8 > 4 ). */
uint16_t CalculateInversions(void);

/* Implementation of the Fisher-Yates Shuffling algorithm. This function iterates through the current arrangment in reverse order, swapping each tile with a random tile that occurs at a prior point in the arrangment. */
void FisherYatesShuffle(void);

/* Randomizes the order of the tiles using the helper functions: FisherYatesShuffle and CalculateInversions. In the event that a puzzle is randomly generated with an unsolvable inversion count, a new Fisher-Yates shuffle is performed. */
void RandomizeTiles(void);

/* Checks whether the player has met the win condition or not. Checks to see if the tiles in cur_arrange are in ascending order (i.e. 0 < 1; 1 < 2; 2 < 3, etc.)
 */
inline void CheckWinCondition(void);

/* Calculates the player's score for the "Strategist" game style. The player's performance is graded based on the number of moves in relation to the time taken to complete the puzzle. 
    - Time Bonus = Max Bonus - ((Elapsed Time / Max Time) * Max Bonus) --- This means it will be impossible to get a time bonus after a certain amount of time.
    - Move Penalty = Excess Moves * Penalty Per Move
    - Final Score Calculation = Base Score + Time Bonus - Move Penalty
    - Note: I do have to make sure it doesn't underflow and give the player a really high score! Maybe limit move penalty to a certain threshold?
 */
uint16_t CalculateScore(void);

/* Operates the main loop for the Standard Mode scene.
 */
void StandardModeMainLoop(uint16_t settings);

#endif