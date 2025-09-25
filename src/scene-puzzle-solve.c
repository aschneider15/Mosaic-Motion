#include "scene-puzzle-solve.h"

void GetPuzzle(uint8_t rand)
{
    HIDE_SPRITES;

    uint8_t previous_bank = _current_bank;

    SWITCH_ROM_MBC5(BANK(tiles_gonefishing));

    set_bkg_data(tiles_gonefishing_TILE_ORIGIN, tiles_gonefishing_TILE_COUNT, tiles_gonefishing_tiles);
    set_bkg_tiles(0, 0, bkg_md_std_WIDTH >> 3, bkg_md_std_HEIGHT >> 3, bkg_md_std_map);

    base_puzzle = tiles_gonefishing_map;

    SWITCH_ROM(previous_bank);

    return;
}

void PartitionTiles(uint8_t difficulty)
{
    switch (difficulty)
    {
    default:
        piece_size = 4;
        break;
    case 1:
        piece_size = 3;
        break;
    case 2:
        piece_size = 2;
        break;
    }

    board_size = BOARD_DIMENSION / piece_size;
    total_board_size = board_size * board_size;
    total_piece_size = piece_size * piece_size;

    uint8_t i = 0, j = 0;

    // Initialize cur_arrange
    for (i = 0; i < board_size; i++)
    {
        for (j = 0; j < board_size; j++)
        {
            cur_arrange[(i * board_size) + j] = (i * board_size) + j;
        }
    }
    // reserve the last tile to render as a black square
    blank_pos_x = board_size - 1;
    blank_pos_y = board_size - 1;
    cur_arrange[total_board_size - 1] = 0x2F;

    return;
}

inline uint8_t GetPuzzleIndexFromBaseTile(uint8_t base_tile)
{
    uint8_t x_offset, y_offset;
    x_offset = base_tile % board_size; // If base tile is 5, and board size is 4 mosaic tiles, then there will be a remainder of 1, i.e. an x-offset of 1.
    y_offset = base_tile / board_size; // If base tile is 5 and board size is 4 mosaic tiles, 5 / 4 = 1, i.e. a y-offset of 1.

    return (y_offset * piece_size * BOARD_DIMENSION) + (piece_size * x_offset);
}

void SetCurrentPuzzleData(void)
{
    uint8_t i, j, puzzle_index;
    for (i = 0; i < total_board_size; i++)
    {
        puzzle_index = GetPuzzleIndexFromBaseTile(i);
        // If not drawing the last mosaic piece
        if (i != total_board_size - 1)
        {
            PopulateSpriteData(cur_arrange[i]);

            for (j = 0; j < total_piece_size; j++)
            {
                puzzle_map[puzzle_index] = cur_sprite_data[j];
                puzzle_index++;
                if (puzzle_index % piece_size == 0)
                {
                    puzzle_index += (12 - piece_size);
                }
            }
        }
        // handle last mosaic piece... should be all black (tile 0x4F)
        else
        {
            for (j = 0; j < total_piece_size; j++)
            {
                puzzle_map[puzzle_index] = 0x4F;
                puzzle_index++;
                if (puzzle_index % piece_size == 0)
                {
                    puzzle_index += (12 - piece_size);
                }
            }
        }
    }

    set_bkg_tiles(4, 1, BOARD_DIMENSION, BOARD_DIMENSION, puzzle_map);

    return;
}

void PopulateSpriteData(uint8_t mosaic_tile_index)
{
    uint8_t i = 0;
    uint8_t puzzle_index = GetPuzzleIndexFromBaseTile(mosaic_tile_index);
    // if the current tile passes the last tile in a row, kick up to the next row.
    for (i; i < total_piece_size; i++)
    {
        cur_sprite_data[i] = base_puzzle[puzzle_index];
        puzzle_index++;
        if (puzzle_index % piece_size == 0)
        {
            puzzle_index += (12 - piece_size);
        }
    }
    return;
}

void StandardModeMovement(uint8_t input)
{
    uint8_t temp = 0x00;
    uint8_t adjacent_tile = 0x00;
    uint8_t old_blank = (blank_pos_x + (blank_pos_y * board_size));

    if (input & J_UP)
    {
        if (blank_pos_y != 0)
        {
            // set the sprite data to the adjacent tile
            adjacent_tile = (blank_pos_x + (blank_pos_y - 1) * board_size);
            PopulateSpriteData(cur_arrange[adjacent_tile]);

            temp = cur_arrange[old_blank];
            cur_arrange[old_blank] = cur_arrange[adjacent_tile];
            cur_arrange[adjacent_tile] = temp;

            // set the background tiles so that blank becomes adjacent tile and adjacent tile becomes blank
            set_bkg_tiles(4 + (blank_pos_x * piece_size), 1 + (blank_pos_y * piece_size), piece_size, piece_size, cur_sprite_data);
            for (uint8_t i = 0; i < total_piece_size; i++)
            {
                cur_sprite_data[i] = 0x4F;
            }
            set_bkg_tiles(4 + (blank_pos_x * piece_size), 1 + ((blank_pos_y - 1) * piece_size), piece_size, piece_size, cur_sprite_data);

            if (g_framecounter % 2 == 1)
                CBTFX_PLAY_swipe1;
            else
                CBTFX_PLAY_swipe2;

            blank_pos_y--;
            operations++;
            WaitNewInput(input);
            CheckWinCondition();
            return;
        }
        CBTFX_PLAY_bump;
        ShakeScreen(1, 1, 1, 6);
        return;
    }
    else if (input & J_DOWN)
    {
        if (blank_pos_y < board_size - 1)
        {
            adjacent_tile = (blank_pos_x + (blank_pos_y + 1) * board_size);
            PopulateSpriteData(cur_arrange[adjacent_tile]);

            temp = cur_arrange[old_blank];
            cur_arrange[old_blank] = cur_arrange[adjacent_tile];
            cur_arrange[adjacent_tile] = temp;

            // set the background tiles so that blank becomes adjacent tile and adjacent tile becomes blank
            set_bkg_tiles(4 + (blank_pos_x * piece_size), 1 + (blank_pos_y * piece_size), piece_size, piece_size, cur_sprite_data);
            for (uint8_t i = 0; i < total_piece_size; i++)
            {
                cur_sprite_data[i] = 0x4F;
            }
            set_bkg_tiles(4 + (blank_pos_x * piece_size), 1 + ((blank_pos_y + 1) * piece_size), piece_size, piece_size, cur_sprite_data);

            if (g_framecounter % 2 == 1)
                CBTFX_PLAY_swipe1;
            else
                CBTFX_PLAY_swipe2;

            blank_pos_y++;
            operations++;
            WaitNewInput(input);
            CheckWinCondition();
            return;
        }
        CBTFX_PLAY_bump;
        ShakeScreen(1, 1, 1, 6);
        return;
    }
    else if (input & J_LEFT)
    {
        if (blank_pos_x != 0)
        {
            adjacent_tile = ((blank_pos_x - 1) + blank_pos_y * board_size);
            PopulateSpriteData(cur_arrange[adjacent_tile]);

            temp = cur_arrange[old_blank];
            cur_arrange[old_blank] = cur_arrange[adjacent_tile];
            cur_arrange[adjacent_tile] = temp;

            // set the background tiles so that blank becomes adjacent tile and adjacent tile becomes blank
            set_bkg_tiles(4 + (blank_pos_x * piece_size), 1 + (blank_pos_y * piece_size), piece_size, piece_size, cur_sprite_data);
            for (uint8_t i = 0; i < total_piece_size; i++)
            {
                cur_sprite_data[i] = 0x4F;
            }
            set_bkg_tiles(4 + ((blank_pos_x - 1) * piece_size), 1 + (blank_pos_y * piece_size), piece_size, piece_size, cur_sprite_data);

            if (g_framecounter % 2 == 1)
                CBTFX_PLAY_swipe1;
            else
                CBTFX_PLAY_swipe2;

            blank_pos_x--;
            operations++;
            WaitNewInput(input);
            CheckWinCondition();
            return;
        }
        CBTFX_PLAY_bump;
        ShakeScreen(1, 1, 0, 6);
        return;
    }
    else if (input & J_RIGHT)
    {
        if (blank_pos_x < board_size - 1)
        {
            adjacent_tile = ((blank_pos_x + 1) + blank_pos_y * board_size);
            PopulateSpriteData(cur_arrange[adjacent_tile]);

            temp = cur_arrange[old_blank];
            cur_arrange[old_blank] = cur_arrange[adjacent_tile];
            cur_arrange[adjacent_tile] = temp;

            // set the background tiles so that blank becomes adjacent tile and adjacent tile becomes blank
            set_bkg_tiles(4 + (blank_pos_x * piece_size), 1 + (blank_pos_y * piece_size), piece_size, piece_size, cur_sprite_data);
            for (uint8_t i = 0; i < total_piece_size; i++)
            {
                cur_sprite_data[i] = 0x4F;
            }
            set_bkg_tiles(4 + ((blank_pos_x + 1) * piece_size), 1 + (blank_pos_y * piece_size), piece_size, piece_size, cur_sprite_data);

            if (g_framecounter % 2 == 1)
                CBTFX_PLAY_swipe1;
            else
                CBTFX_PLAY_swipe2;

            blank_pos_x++;
            operations++;
            WaitNewInput(input);
            CheckWinCondition();
            return;
        }
        CBTFX_PLAY_bump;
        ShakeScreen(1, 1, 0, 6);
        return;
    }

    return;
}

uint16_t CalculateInversions(void)
{
    uint16_t inversions = 0;
    for (uint8_t i = 0; i < total_board_size; i++)
    {
        for (uint8_t j = i + 1; j < total_board_size; j++)
        {
            if (cur_arrange[i] != 0x2F && cur_arrange[j] != 0x2F && cur_arrange[i] > cur_arrange[j])
            {
                inversions++;
            }
        }
    }
    return inversions;
}

// Fisher-Yates Shuffle
void FisherYatesShuffle(void)
{
    for (int i = total_board_size - 2; i > 0; i--)
    {
        int j = rand() % (i + 1);
        uint8_t temp = cur_arrange[i];
        cur_arrange[i] = cur_arrange[j];
        cur_arrange[j] = temp;
    }
}

// Function to randomize tiles and ensure the puzzle is solvable
void RandomizeTiles(void)
{
    initrand(DIV_REG);
    uint16_t inversions;
    uint8_t blank_row_from_bottom = 0;
    do
    {
        FisherYatesShuffle();

        inversions = CalculateInversions();

        // Calculate blank tile row from the bottom
        for (uint8_t i = 0; i < total_board_size; i++)
        {
            if (cur_arrange[i] == 0x2F)
            {
                blank_row_from_bottom = board_size - (i / board_size);
                break;
            }
        }
    } while (!(
        (board_size % 2 != 0 && inversions % 2 == 0) ||                                      // Odd-sized board: even inversions
        (board_size % 2 == 0 && ((inversions % 2 == 0) == (blank_row_from_bottom % 2 != 0))) // Even-sized board: inversions + blank row parity
        ));
}

inline void CheckWinCondition(void)
{
    for (int i = total_board_size - 1; i > 0; i--)
    {
        if (cur_arrange[i] < cur_arrange[i - 1])
        {
            game_won = 0;
            return;
        }
    }

    game_won = 1;
    return;
}

void UpdateTimer(void)
{
    if (g_framecounter == 0)
    {
        secs++;
    }
    if (secs > 59)
    {
        mins++;
        secs = 0;
    }
    if (mins > 99)
    {
        mins = 99;
        secs = 59;
    }
    set_tile_xy(13, 16, (0x20 + g_framecounter % 10));
    set_tile_xy(12, 16, (0x20 + g_framecounter / 10));
    set_tile_xy(10, 16, (0x20 + secs % 10));
    set_tile_xy(9, 16, (0x20 + secs / 10));
    set_tile_xy(7, 16, (0x20 + mins % 10));
    set_tile_xy(6, 16, (0x20 + mins / 10));
}

uint16_t CalculateScore(void)
{
    // Constants (scaled down to fit within 16-bit)
    const uint16_t max_time_bonus = 50000; // Scaled max time bonus
    const uint16_t base_score = 10000;     // Base score for completing puzzle
    // The bigger the board size, the smaller the penalty. Was a const, but not sure if this causes problems for read-only since board_size is not also a const.
    uint8_t move_penalty = 120 / board_size; // Penalty per operation
    const uint16_t max_time = 14400;               // Max time (4 minutes in frames)

    // Calculate elapsed frames
    uint16_t elapsed_frames = (mins * 3600) + (secs * 60) + g_framecounter;

    // Calculate time bonus using intermediate 32-bit arithmetic to avoid overflow
    uint32_t time_bonus = 0;
    if (elapsed_frames < max_time)
    {
        time_bonus = (uint32_t)max_time_bonus * (max_time - elapsed_frames) / max_time;
    }
    else
    {
        time_bonus = 0;
    }

    // Calculate the final score with base score and penalties
    int32_t final_score = (int32_t)base_score + (int32_t)time_bonus;

    // Subtract operation penalties
    if (base_score > (move_penalty * operations))
    {
        final_score -= (int32_t)(operations * move_penalty);
    }

    // Clamp the score to fit within uint16_t range
    // This was generated by GPT-4... this part is ridiculous.
    // An unsigned int CAN'T be less than zero. It'll underflow.
    /*
    if (final_score > 65535) {
        final_score = 65535; // Cap at maximum 16-bit value
    } else if (final_score < 0) {
        final_score = 0; // Ensure no negative scores
    }
    */

    return (uint16_t)final_score;
}

void StandardModeMainLoop(uint16_t settings)
{

    set_bkg_data(0, tiles_general_TILE_ORIGIN, tiles_general_tiles);
    move_bkg(0, 0);

    game_won = 0;
    operations = 0;
    secs = 0;
    mins = 0;

    GetPuzzle(0);
    PartitionTiles((settings >> 8) & 0b0000000000000011);
    RandomizeTiles();
    SetCurrentPuzzleData();

    SHOW_BKG;
    // SHOW_SPRITES;

    WhtFadeIn(4);

    if ((settings & 0b0000000000011000) == 0b00000)
    {
        // Account for music settings, if user picked any.
        extern const hUGESong_t bgm_howtoplay;
        hUGE_init(&bgm_howtoplay);
        hUGEResumeMusic();
    }
    else if ((settings & 0b0000000000011000) == 0b01000)
    {
        // BGM 2 here
    }
    else if ((settings & 0b0000000000011000) == 0b10000)
    {
        // BGM 3 here
    }
    else
    {
        // No BGM selected
    }

    uint8_t input = 0x00;
    uint8_t i = 0, j = 0;
    g_framecounter = 1;

    // Create vblank interrupt to update the timer every frame.
    add_VBL(UpdateTimer);

    while (game_won == 0)
    {
        input = joypad();

        SoftReset(input);

        if (!(input & 0x00))
        {
            StandardModeMovement(input);
        }

        // For debugging purposes, this is how you can display the numeric current arrangement to the screen.
        // for (i = 0; i < board_size; i++)
        // {
        //     for (j = 0; j < board_size; j++)
        //     {
        //         set_tile_xy(0 + j, i, (0x20 + cur_arrange[(i * board_size) + j]));
        //     }
        // }

        IncrementFrame();
    }

    // Remove timer update interrupt
    remove_VBL(UpdateTimer);

    uint16_t final_score = CalculateScore();

    DisplayDialogBox("Congratulations!  You solved it!\0");
    DisplayDialogBoxNumber("Final Score:\n%d pts.\0", final_score);
    DisplayDialogBox("Thanks for playingMy alpha release\0");
    DisplayDialogBox("And please look\nforward to some\0");
    DisplayDialogBox("more currently in the works! Bye!\0");

    NR52_REG = 0x00; // Disable all sound
    NR51_REG = 0x00; // Disable all channels
    NR50_REG = 0x00; // Mute both left and right speakers

    WhtFadeOut(4);
    HIDE_BKG;
    HIDE_WIN;
    HIDE_SPRITES;
}
