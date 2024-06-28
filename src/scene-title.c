#include "scene-title.h"

void InitGraphics_Title(void)
{
    DISPLAY_ON;

    // Load Background tiles and then map
    set_bkg_data(bkg_title_TILE_ORIGIN, bkg_title_TILE_COUNT, bkg_title_tiles);
    // right shift 3 for both width and height because tiles are 8x8... faster than integer division
    set_bkg_tiles(0, 0, bkg_title_WIDTH >> 3, bkg_title_HEIGHT >> 3, bkg_title_map);

    // configure the window layer to obscure the 12x2 area underneath the logo
    move_win(7, 112);

    set_sprite_data(spr_star_TILE_ORIGIN, spr_star_TILE_COUNT, spr_star_tiles);
    // set random y-value location for sprite starting at 16 (first index in screen)
    for (uint8_t i = 0; i < 8; i++)
    {
        set_sprite_tile(i, 0);
        move_sprite(i, 0, 64 + (8 * i) + 16);
    }

    // Turn the background map, window, sprite layer on to make it visible
    SHOW_BKG;
    SHOW_WIN;
    SHOW_SPRITES;
}

void SpriteActivity_Title(void)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        scroll_sprite(i, 4, 0);
    }
}