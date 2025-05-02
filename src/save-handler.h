#ifndef SAVE_HANDLER_H
#define SAVE_HANDLER_H

#include <gb/gb.h>

/* Volatile Saved Data */

extern uint8_t unlocked_puzzles;

/* Each score is saved as a 16-bit value:
    - Values 0 - 14 are top 5 Standard Mode scores for normal, hard, and expert difficulty
    - Values 15 - 29 are top 5 Twist Mode scores for normal, hard, and expert difficulty
    - Values 30 - 44 are top 5 Shift Mode scores for normal, hard, and expert difficulty
 */
extern uint16_t scores[45];

/* Call to load saved data from persistent RAM. Will perform checksum calculation to ensure data integrity.
    @return 0 if no errors |
    @return -1 if there is no save file present |
    @return 1 if there is a checksum conflict |
*/
uint8_t LoadSaveData(void) NONBANKED;

/* Call to update saved data in SRAM using the currrent values of volatile RAM */
uint8_t UpdateSavedData(void) NONBANKED;

#endif