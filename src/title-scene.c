#include "title-scene.h"

void InitGraphics_Title(void)
{
    // Load Background tiles and then map
    set_bkg_data(bkg_title_TILE_ORIGIN, bkg_title_TILE_COUNT, bkg_title_tiles);

    // right shift 3 for both width and height because tiles are 8x8... faster than integer division
    set_bkg_tiles(0, 0, bkg_title_WIDTH >> 3, bkg_title_HEIGHT >> 3, bkg_title_map);

    // Turn the background map, window, sprite layer on to make it visible
    SHOW_BKG;
    SHOW_SPRITES;

    // DisplayDialogBox("THANKS FOR PLAYINGMOSAIC MOTION!    ", "/");
    // DisplayDialogBox("YOUR SUPPORT MEANSSO MUCH.          ", "AIDAN");
    HIDE_WIN;
}

void TitleMainLoop(void)
{
    uint8_t input = 0x00;

    InitGraphics_Title();

    uint8_t cursor_x = 72;
    uint8_t cursor_y = 80;
    uint8_t temp_tile = 0x00;

    while (1)
    {
        input = joypad();


        if((input & J_A) && (input & J_B) && (input & J_START) && (input & J_SELECT))
        {
            reset();
        }

        if((input & J_UP) && (input & J_SELECT) && (input & J_B))
        {
            DisplayDialogBox("DO YOU WANT TO    DELETE SAVED DATA?", "WARNING");
        }


        if (input & J_UP)
        {

            temp_tile = get_bkg_tile_xy(cursor_x >> 3, (cursor_y - 8) >> 3);
            set_bkg_tile_xy((cursor_x) >> 3, (cursor_y - 8) >> 3, get_bkg_tile_xy(cursor_x >> 3, cursor_y >> 3));
            set_bkg_tile_xy(cursor_x >> 3, cursor_y >> 3, temp_tile);
            cursor_y -= 8;

            scroll_sprite(0, 0, -8);
        }
        else if (input & J_DOWN)
        {
            temp_tile = get_bkg_tile_xy(cursor_x >> 3, (cursor_y + 8) >> 3);
            set_bkg_tile_xy((cursor_x) >> 3, (cursor_y + 8) >> 3, get_bkg_tile_xy(cursor_x >> 3, cursor_y >> 3));
            set_bkg_tile_xy(cursor_x >> 3, cursor_y >> 3, temp_tile);
            cursor_y += 8;

            scroll_sprite(0, 0, 8);
        }
        else if (input & J_LEFT)
        {
            temp_tile = get_bkg_tile_xy((cursor_x - 8) >> 3, cursor_y >> 3);
            set_bkg_tile_xy((cursor_x - 8) >> 3, (cursor_y) >> 3, get_bkg_tile_xy(cursor_x >> 3, cursor_y >> 3));
            set_bkg_tile_xy(cursor_x >> 3, cursor_y >> 3, temp_tile);
            cursor_x -= 8;

            scroll_sprite(0, -8, 0);
        }
        else if (input & J_RIGHT)
        {
            temp_tile = get_bkg_tile_xy((cursor_x + 8) >> 3, cursor_y >> 3);
            set_bkg_tile_xy((cursor_x + 8) >> 3, (cursor_y) >> 3, get_bkg_tile_xy(cursor_x >> 3, cursor_y >> 3));
            set_bkg_tile_xy(cursor_x >> 3, cursor_y >> 3, temp_tile);
            cursor_x += 8;

            scroll_sprite(0, 8, 0);
        }

        // Done processing, yield CPU and wait for start of next frame
        IncrementFrame();
    }
}