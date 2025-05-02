# include "save-handler.h"
# include "saved-data.h"

#pragma bank 255

uint8_t LoadSaveData(void) NONBANKED
{
    uint8_t i = 0;
    uint16_t checksum = 0;
    uint8_t origin_bank = CURRENT_BANK;

    ENABLE_RAM;

    // Check to see if a saved file exists
    if (save_checksum == 0)
    {
        DISABLE_RAM;
        return -1;
    }

    // Check for an uncorrupted savefile via XOR checksum

    // Go through all of the saved scores for all game modes
    for (i = 1; i < 45; i++)
    {
        checksum = checksum ^ saved_scores[i];
    }

    // Then check the unlocked puzzles
    checksum = checksum ^ saved_unlocked_puzzles;

    // If everything checks out, copy the values from SRAM into WRAM.
    if (checksum != save_checksum)
    {
        DISABLE_RAM;
        return 0;
    }

    // Copy values from Nonvolatile memory into WRAM

    for (i = 0; i < 30; i++)
    {
        standard_mode_scores[i] = saved_standard_mode_scores[i];
        twist_mode_scores[i] = saved_twist_mode_scores[i];
        shift_mode_scores[i] = saved_shift_mode_scores[i];
    }

    unlocked_puzzles = saved_unlocked_puzzles;

    DISABLE_RAM;

    // Return 1 if there was a checksum error
    return 1;
}

uint8_t UpdateSavedData(void) NONBANKED
{
    uint8_t i = 0;
    uint16_t checksum = 0;

    ENABLE_RAM;

    // Copy values from WRAM into nonvolatile RAM

    for (i = 0; i < 30; i++)
    {
        saved_standard_mode_scores[i] = standard_mode_scores[i];
        saved_twist_mode_scores[i] = twist_mode_scores[i];
        saved_shift_mode_scores[i] = shift_mode_scores[i];
    }

    saved_unlocked_puzzles = unlocked_puzzles;

    // Generate a new checksum based on the modified data
    for (i = 1; i < 30; i++)
    {
        checksum = checksum ^ saved_standard_mode_scores[i];
        checksum = checksum ^ saved_twist_mode_scores[i];
        checksum = checksum ^ saved_shift_mode_scores[i];
    }

    checksum = checksum ^ saved_unlocked_puzzles;

    save_checksum = checksum;

    DISABLE_RAM;

    return 1;
}