#include "scene-title.h"

#pragma bank 255

void TitleInit(void) BANKED
{
    // Load Background tiles and then map
    set_bkg_data(tiles_general_TILE_ORIGIN, tiles_general_TILE_COUNT, tiles_general_tiles);

    // Call nonbanked functions to load tile data and map data
    SetBKGBankedData(96, bkg_title_TILE_COUNT, bkg_title_tiles, BANK(bkg_title));
    SetTilemapBankedData(0, 0, bkg_title_WIDTH >> 3, bkg_title_HEIGHT >> 3, bkg_title_map, BANK(bkg_title));

    set_sprite_data(0, tiles_general_TILE_COUNT, tiles_general_tiles);
    set_sprite_tile(0, 0x49);

    // Turn the background map, window, sprite layer on to make it visible
    SHOW_BKG;
    SHOW_SPRITES;

    HIDE_WIN;
}

BANKREF(TitleMainLoop)
uint8_t TitleMainLoop(void) BANKED
{
    uint8_t difficulty = 0x00;
    uint8_t input = 0x00;

    switch (LoadSaveData())
    {
        default:
            DisplayDialogBox("Save file loaded\nSuccessfully!");
            break;
        case -1:
            DisplayDialogBox("There is no saved file.");
            break;
        case 1: 
            DisplayDialogBox("Checksum conflict!\nThe save file is corrupt.");
            break;
    }
        
    NR52_REG = 0b10000000; // enable all sound
    NR51_REG = 0xFF; // enable all channels
    NR50_REG = 0x77; // turn on stereo speakers

    // External song declaration
    extern const hUGESong_t bgm_title;
    
    TitleInit();


    SHOW_BKG;
    WhtFadeIn(4);

    // Initialize the music
    hUGE_init(&bgm_title);

    while (!(input == J_START))
    {
        input = joypad();
        // Done processing, yield CPU and wait for start of next frame
        IncrementFrame();
    }

    CBTFX_PLAY_confirm;

    PerformantDelay(15);

    NR52_REG = 0x00;  // Disable all sound
    NR51_REG = 0x00;  // Disable all channels
    NR50_REG = 0x00;  // Mute both left and right speakers


    WhtFadeOut(4);
    HIDE_BKG;
    HIDE_WIN;
    HIDE_SPRITES;

    return difficulty;
}