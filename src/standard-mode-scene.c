#include "standard-mode-scene.h"

uint8_t TileOffset(uint8_t index)
{
    return (12 * (12 / board_size) * index) + ((12 / board_size) * index);
}

uint8_t CopyEnd(uint8_t offset)
{
    return offset + (12 * ((12 / board_size) - 1) + (12 / board_size));
}

void GetPuzzle(uint8_t rand)
{
    // set_bkg_data(tiles_gonefishing_TILE_ORIGIN, tiles_gonefishing_TILE_COUNT, tiles_gonefishing_tiles);
    set_bkg_data(tiles_gonefishing_TILE_ORIGIN, tiles_gonefishing_TILE_COUNT, tiles_gonefishing_tiles);
    set_bkg_tiles(0, 0, bkg_md_std_WIDTH >> 3, bkg_md_std_HEIGHT >> 3, bkg_md_std_map);

    for (uint8_t i = 0; i < 144; i++)
    {
        defualt_puzzle_map[i] = tiles_gonefishing_map[i];
        current_puzzle_map[i] = tiles_gonefishing_map[i];
    }

    HIDE_SPRITES;
}

void DrawPuzzle(void)
{
    /*
        uint8_t i;
        uint8_t j;

        for (i = 0; i < board_size * board_size; i++)
        {
            if (cur_arrange[i] != prev_arrange[i])
            {
                for (j = 0; j < board_size * board_size; j++)
                {
                    prev_arrange[i] = cur_arrange[i];
                }
                set_bkg_tiles(4, 1, 12, 12, current_puzzle_map);
                break;
            }
        }
         */
    uint8_t index;
    uint8_t offset = TileOffset(index);
    uint8_t limit = CopyEnd(offset);

    for (uint8_t i = 0; i < board_size * board_size; i++)
    {
        index = cur_arrange[i];
        for (uint8_t j = offset; j < limit; j++)
        {
            if (j % 12 < (12 / board_size))
            {
                current_puzzle_map[j] = defualt_puzzle_map[TileOffset(i)];
            }
        }
    }
}

void PartitionTiles(uint8_t difficulty)
{
    switch (difficulty)
    {
    default:
        board_size = 3;
        break;
    case 1:
        board_size = 4;
        break;
    case 2:
        board_size = 6;
        break;
    }
}

void MoveMetaTile(uint8_t input)
{
    uint8_t i = 0;
    if (input & J_UP)
    {
        if (blank_pos_y > 0)
        {
            cur_arrange[(board_size * blank_pos_y) + blank_pos_x] = cur_arrange[(board_size * (blank_pos_y - 1)) + blank_pos_x];
            cur_arrange[(board_size * (blank_pos_y - 1)) + blank_pos_x] = 0xFF;

            uint8_t initial_offset = (12 * board_size * (blank_pos_y - 1) + (board_size * blank_pos_x));

            for (uint8_t y = initial_offset; y < initial_offset + (12 * (board_size - 1) + board_size); y += 12)
            {
                for (uint8_t x = 0; x < board_size; x++)
                {
                    cur_sprite_data[i] = current_puzzle_map[y + x];
                    current_puzzle_map[y + x] = 0x4F;
                    i++;
                }
            }

            i = 0;

            initial_offset = (12 * board_size * (blank_pos_y) + (board_size * blank_pos_x));

            for (uint8_t y = initial_offset; y < initial_offset + (12 * (board_size - 1) + board_size); y += 12)
            {
                for (uint8_t x = 0; x < board_size; x++)
                {
                    current_puzzle_map[y + x] = cur_sprite_data[i];
                    i++;
                }
            }
        }
        else
        {
            // play some little bonk sound effect
        }
    }
    if (input & J_LEFT)
    {
    }
    if (input & J_DOWN)
    {
    }
    if (input & J_RIGHT)
    {
    }
}

void StandardModeMainLoop(void)
{
    GetPuzzle(0);
    PartitionTiles(0);

    SHOW_BKG;
    SHOW_SPRITES;
    WhtFadeIn(4);

    uint8_t input = 0x00;

    uint8_t i = 0;
    uint8_t total_board_size = board_size * board_size;

    for (i = 0; i < total_board_size; i++)
    {
        prev_arrange[i] = 0;
        cur_arrange[i] = i;
    }
    // reserve the last tile to render as a black square
    cur_arrange[total_board_size - 1] = 0xFF;
    blank_pos_x = board_size - 1;
    blank_pos_y = board_size - 1;

    set_bkg_tiles(4, 1, 12, 12, current_puzzle_map);

    while (!(input == J_START))
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

        DrawPuzzle();

        IncrementFrame();
    }

    WhtFadeOut(4);
    HIDE_BKG;
    HIDE_WIN;
    HIDE_SPRITES;
}