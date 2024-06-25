#include <gb/gb.h>
#include <stdint.h>
#include <rand.h>
#include "../res/bkg_title.h"
#include "../res/spr_star.h"

void init_gfx(void);

void main(void)
{
    // initialize random number generator with the Division register
    initrand(DIV_REG);
    init_gfx();
    uint8_t framecount;

    // Loop forever
    while (1)
    {

        uint8_t input = joypad();

        // Game main loop processing goes here
        // if (input & J_UP)
        // {
        //     scroll_sprite(0, 0, -1);
        // }
        // else if (input & J_DOWN)
        // {
        //     scroll_sprite(0, 0, 1);
        // }

        // if (input & J_LEFT)
        // {
        //     scroll_sprite(0, -1, 0);
        // }
        // else if (input & J_RIGHT)
        // {
        //     scroll_sprite(0, 1, 0);
        // }

        for (uint8_t i = 0; i < 8; i++)
        {
            scroll_sprite(i, 4, 0);
        }

        // alternate window on/off every 20f (1/3 sec)
        framecount = framecount + 1;
        if (framecount % 20 == 0)
        {
            if (LCDC_REG & LCDCF_WINON)
            {
                HIDE_WIN;
            }
            else
            {
                SHOW_WIN;
            }
        }

        // set the frame count back to zero and wait until vsync
        if (framecount == 60)
        {
            framecount &= 0x00;
        }
        // Done processing, yield CPU and wait for start of next frame
        vsync();
    }
}

void init_gfx(void)
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
        move_sprite(i, 0, arand() % 72 + 16);
    }

    // Turn the background map, window, sprite layer on to make it visible
    SHOW_BKG;
    SHOW_WIN;
    SHOW_SPRITES;
}