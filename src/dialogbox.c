#include "./dialogbox.h"

void SetDialogTiles(void)
{
    set_bkg_data(tiles_general_TILE_ORIGIN, tiles_general_TILE_COUNT, tiles_general_tiles);
    set_win_tiles(0, 0, uimap_dialogbox_WIDTH >> 3, uimap_dialogbox_HEIGHT >> 3, uimap_dialogbox_map);
}

void SetText(uint8_t phrase[36])
{
    uint8_t i;
    for (i = 0; i < 36; i++)
    {
        if (i < 18)
        {
            // terminator character detected - move to the next line
            if (phrase[i] == '/')
            {
                i = 17;
            }
            else
            {
                set_win_tile_xy(i + 1, 1, ConvertLetterToTile(phrase[i]));
            }
        }
        else
        {
            // terminator character detected - shortcut to end of dialogbox
            if (phrase[i] == '/')
            {
                i = 35;
            }
            else
            {
                set_win_tile_xy(i - 17, 3, ConvertLetterToTile(phrase[i]));
            }
        }
        IncrementFrame();
    }
    return;
}

void SetLabel(uint8_t label[17])
{
    uint8_t i;
    if (label[0] == '/')
    {
        for (i = 0; i < 18; i++)
        {
            set_win_tile_xy(i + 1, 0, 0x41);
        }
        return;
    }
    for (i = 0; i < 18; i++)
    {
        // if a NULL char is encountered, draw the label-end tile, then follow with terminating tiles
        if (label[i] == NULL)
        {
            set_win_tile_xy(i + 1, 0, 0x42);
            i++;
            while (i < 18)
            {
                set_win_tile_xy(i + 1, 0, 0x41);
                i++;
            }
        }
        else
        {
            set_win_tile_xy(i + 1, 0, ConvertLetterToTile(label[i]));
        }
    }
    return;
}

uint8_t ConvertLetterToTile(char let)
{
    uint8_t out = 0x2F;

    if (let >= 'A' && let <= 'Z')
    {
        out = let - 'A';
    }
    else if (let >= 'a' && let <= 'z')
    {
        out = let - 'a';
    }
    else if (let >= '0' && let <= '9')
    {
        out = let - '0' + 0x20;
    }

    else
    {
        if (let == ' ')
        {
            out = 0x1A;
        }
        else if (let == '.')
        {
            out = 0x1B;
        }
        else if (let == '!')
        {
            out = 0x1C;
        }
        else if (let == '?')
        {
            out = 0x1D;
        }
        else if (let == '-')
        {
            out = 0x1E;
        }
        else if (let == ':')
        {
            out = 0x1F;
        }
        else if (let == '"')
        {
            out = 0x2A;
        }
        else if (let == '$')
        {
            out = 0x2B;
        }
        else if (let == '+')
        {
            out = 0x2C;
        }
    }

    return out;
}

void DisplayDialogBox(uint8_t phrase[36], uint8_t label[17])
{
    move_win(7, 104);
    uint8_t input = 0x00;
    SetDialogTiles();
    SetLabel(label);
    SHOW_WIN;
    SetText(phrase);
    while (!(input & J_A || input & J_B))
    {
        input = joypad();
        if (g_framecounter % 10 == 0)
        {
            set_win_tile_xy(0x12, 0x04, 0x2D);
        }
        if (g_framecounter % 10 == 5)
        {
            set_win_tile_xy(0x12, 0x04, 0x46);
        }
        IncrementFrame();
    }
}