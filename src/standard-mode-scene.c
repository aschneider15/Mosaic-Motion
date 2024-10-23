#include "standard-mode-scene.h"

void GetPuzzle(uint8_t rand)
{
    HIDE_SPRITES;

    set_bkg_data(tiles_gonefishing_TILE_ORIGIN, tiles_gonefishing_TILE_COUNT, tiles_gonefishing_tiles);
    set_bkg_tiles(0, 0, bkg_md_std_WIDTH >> 3, bkg_md_std_HEIGHT >> 3, bkg_md_std_map);

    base_puzzle = tiles_gonefishing_map;

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

void MoveMetaTile(uint8_t input)
{
    uint8_t temp = 0x00;
    uint8_t adjacent_tile = 0x00;
    uint8_t old_blank = (blank_pos_x + (blank_pos_y)*board_size);

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

            blank_pos_y--;
            operations++;
            waitpadup();
            CheckWinCondition();
        }
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

            blank_pos_y++;
            operations++;
            waitpadup();
            CheckWinCondition();
        }
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

            blank_pos_x--;
            operations++;
            waitpadup();
            CheckWinCondition();
        }
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

            blank_pos_x++;
            operations++;
            waitpadup();
            CheckWinCondition();
        }
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

void StandardModeMainLoop(uint8_t difficulty)
{
    game_won = 0;
    secs = 0;
    mins = 0;

    GetPuzzle(0);
    PartitionTiles(difficulty);
    RandomizeTiles();
    SetCurrentPuzzleData();

    SHOW_BKG;
    // SHOW_SPRITES;
    WhtFadeIn(4);

    NR52_REG = 0b10000000; // enable all sound
    NR51_REG = 0xFF; // enable all channels
    NR50_REG = 0x77; // turn on stereo speakers

    extern const hUGESong_t bgm_howtoplay;
    hUGE_init(&bgm_howtoplay);

    uint8_t input = 0x00;
    uint8_t i = 0, j = 0;
    g_framecounter = 1;

    while (game_won == 0)
    {
        input = joypad();

        if ((input & J_A) && (input & J_B) && (input & J_START) && (input & J_SELECT))
        {
            reset();
        }

        if (!(input & 0x00))
        {
            MoveMetaTile(input);
        }

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

        // For debugging purposes, this was how you can display the numeric current arrangement to the screen.
        // for (i = 0; i < board_size; i++)
        // {
        //     for (j = 0; j < board_size; j++)
        //     {
        //         set_tile_xy(0 + j, i, (0x20 + cur_arrange[(i * board_size) + j]));
        //     }
        // }

        IncrementFrame();
    }

    DisplayDialogBox("Congratulations!  You solved it!    ", "Aidan");
    DisplayDialogBox("Thanks for playingMy alpha release  ", "Aidan");
    DisplayDialogBox("And please look   forward to some   ", "Aidan");
    DisplayDialogBox("more currently in the works! Bye!   ", "Aidan");

    WhtFadeOut(4);
    HIDE_BKG;
    HIDE_WIN;
    HIDE_SPRITES;
}
