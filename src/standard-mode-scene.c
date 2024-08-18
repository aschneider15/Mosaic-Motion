#include "standard-mode-scene.h"

void GetPuzzle(uint8_t rand)
{
    HIDE_SPRITES;
    // set_bkg_data(tiles_gonefishing_TILE_ORIGIN, tiles_gonefishing_TILE_COUNT, tiles_gonefishing_tiles);
    set_bkg_data(tiles_gonefishing_TILE_ORIGIN, tiles_gonefishing_TILE_COUNT, tiles_gonefishing_tiles);
    set_bkg_tiles(0, 0, bkg_md_std_WIDTH >> 3, bkg_md_std_HEIGHT >> 3, bkg_md_std_map);

    for (uint8_t i = 0; i < 144; i++)
    {
        puzzle_map[i] = tiles_gonefishing_map[i];
    }
    set_bkg_tiles(4, 1, 12, 12, puzzle_map);

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

    return;
}

void MoveMetaTile(uint8_t input)
{
    uint8_t temp = 0x00;

    if (input & J_UP)
    {
        if (blank_pos_y != 0)
        {
            temp = cur_arrange[(blank_pos_x + (blank_pos_y - 1) * board_size)];
            cur_arrange[(blank_pos_x + (blank_pos_y - 1) * board_size)] = cur_arrange[(blank_pos_x + (blank_pos_y)*board_size)];
            cur_arrange[(blank_pos_x + (blank_pos_y)*board_size)] = temp;
            blank_pos_y--;
            
            CheckWinCondition();
            vsync();
        }
    }
    else if (input & J_DOWN)
    {
        if (blank_pos_y < board_size - 1)
        {
            temp = cur_arrange[(blank_pos_x + (blank_pos_y + 1) * board_size)];
            cur_arrange[(blank_pos_x + (blank_pos_y + 1) * board_size)] = cur_arrange[(blank_pos_x + (blank_pos_y)*board_size)];
            cur_arrange[(blank_pos_x + (blank_pos_y)*board_size)] = temp;
            blank_pos_y++;

            CheckWinCondition();
            vsync();
        }
    }
    else if (input & J_LEFT)
    {
        if (blank_pos_x != 0)
        {
            temp = cur_arrange[((blank_pos_x - 1) + blank_pos_y * board_size)];
            cur_arrange[((blank_pos_x - 1) + blank_pos_y * board_size)] = cur_arrange[(blank_pos_x + (blank_pos_y)*board_size)];
            cur_arrange[(blank_pos_x + (blank_pos_y)*board_size)] = temp;
            blank_pos_x--;

            CheckWinCondition();
            vsync();
        }
    }
    else if (input & J_RIGHT)
    {
        if (blank_pos_x < board_size - 1)
        {
            temp = cur_arrange[((blank_pos_x + 1) + blank_pos_y * board_size)];
            cur_arrange[((blank_pos_x + 1) + blank_pos_y * board_size)] = cur_arrange[(blank_pos_x + (blank_pos_y)*board_size)];
            cur_arrange[(blank_pos_x + (blank_pos_y)*board_size)] = temp;
            blank_pos_x++;

            CheckWinCondition();
            vsync();
        }
    }

    return;
}

void CheckWinCondition(void)
{
    for(int i = board_size * board_size - 1; i > 0; i--)
    {
        if(cur_arrange[i] < cur_arrange[i - 1])
        {
            game_won = 0;
            return;
        }
    }

    game_won = 1;
    return;
}

void StandardModeMainLoop(void)
{
    game_won = 0;
    mibisecs = 0;
    secs = 0;
    mins = 0;

    GetPuzzle(0);
    PartitionTiles(0);

    SHOW_BKG;
    SHOW_SPRITES;
    WhtFadeIn(4);

    uint8_t input = 0x00;

    uint8_t i = 0, j = 0;

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
    cur_arrange[board_size * board_size - 1] = 0x2F;

    while (!(input == J_START) && game_won == 0)
    {
        input = joypad();

        MoveMetaTile(input);

        if (mibisecs > 59)
        {
            secs++;
            mibisecs = 0;
        }
        if (secs > 59)
        {
            mins++;
            secs = 0;
        }
        if (mins > 99)
        {
            mins == 99;
            secs == 59;
            mibisecs == 59;
        }
        mibisecs++;

        set_tile_xy(13, 16, (0x20 + mibisecs % 10));
        set_tile_xy(12, 16, (0x20 + mibisecs / 10));
        set_tile_xy(10, 16, (0x20 + secs % 10));
        set_tile_xy(9, 16, (0x20 + secs / 10));
        set_tile_xy(7, 16, (0x20 + mins % 10));
        set_tile_xy(6, 16, (0x20 + mins / 10));

        for (i = 0; i < board_size; i++)
        {
            for (j = 0; j < board_size; j++)
            {
                set_tile_xy(0 + j, i, (0x20 + cur_arrange[(i * board_size) + j]));
            }
        }

        IncrementFrame();
    }

    WhtFadeOut(4);
    HIDE_BKG;
    HIDE_WIN;
    HIDE_SPRITES;
}