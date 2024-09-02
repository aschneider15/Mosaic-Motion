#include "title-scene.h"

void InitGraphics_Title(void)
{
    // Load Background tiles and then map
    set_bkg_data(tiles_general_TILE_ORIGIN, tiles_general_TILE_COUNT, tiles_general_tiles);
    set_bkg_data(bkg_title_TILE_ORIGIN, bkg_title_TILE_COUNT, bkg_title_tiles);

    // right shift 3 for both width and height because tiles are 8x8... faster than integer division
    set_bkg_tiles(0, 0, bkg_title_WIDTH >> 3, bkg_title_HEIGHT >> 3, bkg_title_map);

    set_sprite_data(0, tiles_general_TILE_COUNT, tiles_general_tiles);
    set_sprite_tile(0, 0x4A);

    // Turn the background map, window, sprite layer on to make it visible
    SHOW_BKG;
    SHOW_SPRITES;

    HIDE_WIN;
}

uint8_t TitleMainLoop(void)
{
    uint8_t difficulty = 0x00;
    uint8_t input = 0x00;

    InitGraphics_Title();

    uint8_t cursor_x = 48;
    uint8_t cursor_y = 80;

    move_sprite(0, cursor_x, cursor_y);

    SHOW_BKG;
    SHOW_SPRITES;
    WhtFadeIn(4);

    while (!(input == J_START))
    {
        input = joypad();

        if ((input & J_A) && (input & J_B) && (input & J_START) && (input & J_SELECT))
        {
            reset();
        }

        if ((input & J_UP) && difficulty > 0)
        {
            cursor_y -= 8;
            move_sprite(0, cursor_x, cursor_y);
            difficulty--;
            waitpadup();
        }
        else if ((input & J_DOWN) && difficulty < 2)
        {
            cursor_y += 8;
            move_sprite(0, cursor_x, cursor_y);
            difficulty++;
            waitpadup();
        }

        // Done processing, yield CPU and wait for start of next frame
        IncrementFrame();
    }

    WhtFadeOut(4);
    HIDE_BKG;
    HIDE_WIN;
    HIDE_SPRITES;

    return difficulty;
}
