#include "ops-vital.h"

inline void SoftReset(uint8_t input)
{
    if((input & J_A) && (input & J_B) && (input & J_SELECT) && (input & J_START))
    {
        reset();
    }
}

inline void set_banked_bkg_data(uint8_t first_tile, uint8_t nb_tiles, const uint8_t *data, uint8_t bank) 
{
    uint8_t save = CURRENT_BANK;
    SWITCH_ROM(bank);
    set_bkg_data(first_tile, nb_tiles, data);
    SWITCH_ROM(save);
}

inline void WaitNewInput(uint8_t previous_input)
{
    // poll current input
    uint8_t current_input = joypad();
    // if current input is the same as the previous, do recursive call
    if(current_input == previous_input)
    {
        // increment frame 
        IncrementFrame();
        WaitNewInput(current_input);
    }

    return;
}