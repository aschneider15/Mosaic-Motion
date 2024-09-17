#include "title-scene.h"

void InitGraphics_Title(void)
{
    // Load Background tiles and then map
    set_bkg_data(tiles_general_TILE_ORIGIN, tiles_general_TILE_COUNT, tiles_general_tiles);
    set_bkg_data(bkg_title_TILE_ORIGIN, bkg_title_TILE_COUNT, bkg_title_tiles);

    // right shift 3 for both width and height because tiles are 8x8... faster than integer division
    set_bkg_tiles(0, 0, bkg_title_WIDTH >> 3, bkg_title_HEIGHT >> 3, bkg_title_map);

    set_sprite_data(0, tiles_general_TILE_COUNT, tiles_general_tiles);
    set_sprite_tile(0, 0x49);

    // Turn the background map, window, sprite layer on to make it visible
    SHOW_BKG;
    SHOW_SPRITES;

    HIDE_WIN;
}

uint8_t TitleMainLoop(void)
{
    uint8_t difficulty = 0x00;
    uint8_t input = 0x00;

    uint8_t sprite_frame = 0x49;

    // #define SFX_CH_RETRIGGER  0b11000000
    // #define SFX_CH_ENABLE     0b10000000
    // enable sound
    NR52_REG = 0b10000000; // enable all sound
    NR51_REG = 0xFF; // enable all channels
    NR50_REG = 0x77; // turn on stereo speakers

    // External song declaration
    extern const hUGESong_t bgm_title;


    InitGraphics_Title();

    uint8_t cursor_x = 48;
    uint8_t cursor_y = 80;

    move_sprite(0, cursor_x, cursor_y);


    SHOW_BKG;
    SHOW_SPRITES;
    WhtFadeIn(4);

    // Initialize the music
    hUGE_init(&bgm_title);

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

        if((g_framecounter % 4) == 0)
        {
            set_sprite_tile(0, sprite_frame);
            sprite_frame++;
        }
        if(sprite_frame > 0x4B) 
        {
            sprite_frame = 0x49;
        }

        // Done processing, yield CPU and wait for start of next frame
        IncrementFrame();
    }

    NR52_REG = 0x00;  // Disable all sound
    NR51_REG = 0x00;  // Disable all channels
    NR50_REG = 0x00;  // Mute both left and right speakers


    WhtFadeOut(4);
    HIDE_BKG;
    HIDE_WIN;
    HIDE_SPRITES;

    return difficulty;
}
