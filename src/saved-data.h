#ifndef SAVED_DATA_H
#define SAVED_DATA_H

#include <gb/gb.h> 

// Check to see if a save exists
extern uint8_t save_checksum;

// The puzzle images the player has unlocked. There are eight total unlockable puzzles.
extern uint8_t saved_unlocked_puzzles;

/* Each score is saved as a 16-bit value:
    - Values 0 - 14 are top 5 Standard Mode scores for normal, hard, and expert difficulty
    - Values 15 - 29 are top 5 Twist Mode scores for normal, hard, and expert difficulty
    - Values 30 - 44 are top 5 Shift Mode scores for normal, hard, and expert difficulty
 */
extern uint16_t saved_strategist_scores[45];


#endif