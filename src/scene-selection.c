#include "scene-selection.h"

BANKREF_EXTERN(bkg_selection)

void SelectionInit(void)
{
    uint8_t previous_bank = _current_bank;
    SWITCH_ROM( BANK(bkg_selection) );

    set_bkg_data(96, bkg_selection_TILE_COUNT, bkg_selection_tiles);

    // right shift 3 for both width and height because tiles are 8x8... faster than integer division
    set_bkg_tiles(0, 0, bkg_selection_WIDTH >> 3, bkg_selection_HEIGHT >> 3, bkg_selection_map);

    SWITCH_ROM(previous_bank);

    // Create the window layer to obscure scene transitions
    fill_win_rect(0, 0, 31, 31, 0xAF);
    set_win_based_tiles(0, 0, 20, 4, uimap_select_curtain_map, 0x3A);

    move_win(7, 112);

    move_sprite(0, cursor_x, cursor_y);

    SHOW_BKG;
    SHOW_SPRITES;
    SHOW_WIN;
    WhtFadeIn(4);

    // External song declaration
    extern const hUGESong_t bgm_selection;

    // Initialize the music
    hUGE_init(&bgm_selection);

    NR52_REG = 0b10000000; // enable all sound
    NR50_REG = 0x77;       // turn on stereo speakers

    return;
}

void DifficultySelection(void)
{
    // prevent two subsequent A- or B-presses
    waitpadup();

    cursor_x = 24;
    cursor_y = 24;

    uint8_t cur_selection = 0;
    uint8_t input = 0;

    NR51_REG = 0b00010001; // enable duty 1 channel sound

    /* Loop forever... at least until the break statments. */
    while (1)
    {
        input = joypad();

        SoftReset(input);

        /* Restrict users to select between 0 and 2 */
        if (input & J_UP && cur_selection > 0)
        {
            cur_selection--;
            cursor_y -= 8;
        }

        if (input & J_DOWN && cur_selection < 2)
        {
            cur_selection++;
            cursor_y += 8;
        }

        if (input & J_A)
        {
            // update settings to account for current selection
            settings = settings | cur_selection;
            phase = 2;
            return;
        }

        if (input & J_B)
        {
            phase = 0;
            return;
        }

        move_sprite(0, cursor_x, cursor_y);
        IncrementFrame();
    }
}

void StyleSelection(void)
{
    // prevent two subsequent A- or B-presses
    waitpadup();

    cursor_x = 24;
    cursor_y = 64;

    uint8_t cur_selection = 0;
    uint8_t input = 0;

    NR51_REG = 0b10011001; // enable duty 1 and noise channel sound

    /* Loop forever... at least until the break statments. */
    while (1)
    {
        input = joypad();

        SoftReset(input);

        /* Restrict users to select between 0 and 1 */
        if (input & J_UP && cur_selection > 0)
        {
            cur_selection--;
            cursor_y -= 8;
        }

        if (input & J_DOWN && cur_selection < 1)
        {
            cur_selection++;
            cursor_y += 8;
        }

        if (input & J_A)
        {
            // left-shift by 1, then update settings to account for current selection
            settings << 1;
            settings = settings | cur_selection;
            phase = 3;
            return;
        }

        if (input & J_B)
        {
            phase = 1;
            return;
        }

        move_sprite(0, cursor_x, cursor_y);
        IncrementFrame();
    }
}

void ModeSelection(void)
{
    // prevent two subsequent A- or B-presses
    waitpadup();

    cursor_x = 24;
    cursor_y = 96;

    uint8_t cur_selection = 0;
    uint8_t input = 0;

    move_sprite(0, cursor_x, cursor_y);
    SHOW_SPRITES;

    NR51_REG = 0b10111011; // enable duty 1, duty 2 and noise channel sound

    /* Loop forever... at least until the break statments. */
    while (1)
    {
        input = joypad();

        SoftReset(input);

        /* Restrict users to select between 0 and 2 */
        if (input & J_UP && cur_selection > 0)
        {
            cur_selection--;
            cursor_y -= 8;
        }

        if (input & J_DOWN && cur_selection < 2)
        {
            cur_selection++;
            cursor_y += 8;
        }

        if (input & J_A)
        {
            // left-shift by two, then update settings to account for current selection
            settings << 2;
            settings = settings | cur_selection;
            phase = 4;

            // Scroll the background over to the music pane
            HIDE_SPRITES;
            for (uint8_t i = 0; i < 24; i++)
            {
                scroll_bkg(4, 0);
                IncrementFrame();
            }
            return;
        }

        if (input & J_B)
        {
            phase = 2;
            return;
        }

        move_sprite(0, cursor_x, cursor_y);
        IncrementFrame();
    }
}

void MusicSelection(void)
{
    // prevent two subsequent A- or B-presses
    waitpadup();

    cursor_x = 88;
    cursor_y = 32;


    uint8_t cur_selection = 0;
    uint8_t input = 0;
    
    move_sprite(0, cursor_x, cursor_y);

    SHOW_SPRITES;

    NR51_REG = 0b11111111; // enable all sound channels

    /* Loop forever... at least until the break statments. */
    while (1)
    {
        input = joypad();

        SoftReset(input);

        /* Restrict users to select between 0 and 3 */
        if (input & J_UP && cur_selection > 0)
        {
            cur_selection--;
            cursor_y -= 8;
        }

        if (input & J_DOWN && cur_selection < 3)
        {
            cur_selection++;
            cursor_y += 8;
        }

        if (input & J_A)
        {
            // left-shift by two, then update settings to account for current selection
            settings << 2;
            settings = settings | cur_selection;
            phase = 5;

            WindowClose();
            move_bkg(0, 144);
            move_sprite(0, 0, 0);
            WindowOpen();

            return;
        }

        if (input & J_B)
        {
            phase = 3;
            // Scroll the background over to the first pane
            HIDE_SPRITES;
            for (uint8_t i = 0; i < 24; i++)
            {
                scroll_bkg(-4, 0);
                IncrementFrame();
            }

            return;
        }

        move_sprite(0, cursor_x, cursor_y);
        IncrementFrame();
    }
}

void PuzzleSelection(void) 
{
    // prevent two subsequent A- or B-presses
    waitpadup();

    cursor_x = 15;
    cursor_y = 27;


    uint8_t cur_selection = 0;
    uint8_t input = 0;

    NR51_REG = 0b11111111; // enable all sound channels

    /* Loop forever... at least until the break statments. */
    while (1)
    {
        input = joypad();

        SoftReset(input);

        if (input & J_UP && cursor_y > 27)
        {
            cur_selection -= 4;
            cursor_y--;
        }

        if (input & J_DOWN && cursor_y < 28)
        {
            cur_selection += 4;
            cursor_y++;
        }

        if(input & J_RIGHT && cursor_x < 18)
        {
            cur_selection++;
            cursor_x++;
        }

        if(input & J_RIGHT && cursor_x > 15)
        {
            cur_selection--;
            cursor_x--;
        }


        if (input & J_A)
        {
            // left-shift by two, then update settings to account for current selection
            settings << 2;
            settings = settings | cur_selection;
            phase = 5;

            return;
        }

        if (input & J_B)
        {
            phase = 4;

            WindowClose();
            move_bkg(96, 0);
            move_sprite(0, 88, 32);
            WindowOpen();

            return;
        }

        move_sprite(0, cursor_x, cursor_y);
        IncrementFrame();
    }
}

void WindowOpen(void)
{
    for (uint8_t i = 15; i > 0; i--)
    {
        move_win(7, scroll_positions[i]);
        IncrementFrame();
    }
    move_win(7, 112);

    SHOW_SPRITES;

    return;
}

void WindowClose(void)
{
    HIDE_SPRITES;

    for (uint8_t i = 0; i < 15; i++)
    {
        move_win(7, scroll_positions[i]);
        IncrementFrame();
    }
    move_win(7, 0);
    return;
}

uint8_t SelectionMainLoop(void)
{
    uint8_t input = 0;

    uint8_t sprite_frame = 0x49;

    phase = 1;
    /*
        phase of selection scene:
            difficulty > style > game mode > music > puzzle
     */

    SelectionInit();
    // while (phase > 0 && phase < 5)
    while (1)
    {

        /*
        if ((g_framecounter % 4) == 0)
                {
                    set_sprite_tile(0, sprite_frame);
                    sprite_frame++;
                }

                if (sprite_frame > 0x4B)
                {
                    sprite_frame = 0x49;
                }
         */
        // Operate the settings selection based on the current selection phase
        switch (phase)
        {
        case 1:
            DifficultySelection();
            break;

        case 2:
            StyleSelection();
            break;

        case 3:
            ModeSelection();
            break;

        case 4:
            MusicSelection();
            break;

        case 5:
            break;

        default:
            break;
        }

        if (phase == 0 || phase == 6)
        {
            break;
        }
    }

    NR52_REG = 0x00; // Disable all sound
    NR51_REG = 0x00; // Disable all channels
    NR50_REG = 0x00; // Mute both left and right speakers

    WhtFadeOut(4);
    HIDE_BKG;
    HIDE_WIN;
    HIDE_SPRITES;

    return settings;
}
