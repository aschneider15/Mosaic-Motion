#include "ops-screen.h"

void BlkFadeIn(uint8_t speed)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        switch (i)
        {
        case 0:
            BGP_REG = BLK3;
            break;
        case 1:
            BGP_REG = BLK2;
            break;
        case 2:
            BGP_REG = BLK1;
            break;
        case 3:
            BGP_REG = NTRL;
            break;
        }
        PerformantDelay(speed);
    }
}

void BlkFadeOut(uint8_t speed)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        switch (i)
        {
        case 0:
            BGP_REG = NTRL;
            break;
        case 1:
            BGP_REG = BLK1;
            break;
        case 2:
            BGP_REG = BLK2;
            break;
        case 3:
            BGP_REG = BLK3;
            break;
        }
        PerformantDelay(speed);
    }
}

void ShakeScreen(uint8_t speed, uint8_t intensity, BOOLEAN direction, uint8_t times)
{
    if (direction == 0)
    {
        for (uint8_t i = 0; i < times; i++)
        {
            move_bkg(intensity, 0);
            PerformantDelay(speed);
            move_bkg(0xff - intensity, 0);
            PerformantDelay(speed);
        }
    }
    else
    {
        for (uint8_t i = 0; i < times; i++)
        {
            move_bkg(0, intensity);
            PerformantDelay(speed);
            move_bkg(0, 0xff - intensity);
            PerformantDelay(speed);
        }
    }
    // reset position just in case
    move_bkg(0,0);
}

void WhtFadeIn(uint8_t speed)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        switch (i)
        {
        case 0:
            BGP_REG = WHT3;
            break;
        case 1:
            BGP_REG = WHT2;
            break;
        case 2:
            BGP_REG = WHT1;
            break;
        case 3:
            BGP_REG = NTRL;
            break;
        }
        PerformantDelay(speed);
    }
}

void WhtFadeOut(uint8_t speed)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        switch (i)
        {
        case 0:
            BGP_REG = NTRL;
            break;
        case 1:
            BGP_REG = WHT1;
            break;
        case 2:
            BGP_REG = WHT2;
            break;
        case 3:
            BGP_REG = WHT3;
            break;
        }
        PerformantDelay(speed);
    }
}

/* Dialogbox related functions */

void SetDialogTiles(void)
{
    set_bkg_data(tiles_general_TILE_ORIGIN, tiles_general_TILE_COUNT, tiles_general_tiles);
    set_win_tiles(0, 0, uimap_dialogbox_WIDTH >> 3, uimap_dialogbox_HEIGHT >> 3, uimap_dialogbox_map);
}

void SetText(uint8_t phrase[36])
{
    uint8_t x = 1; // X position in the window
    uint8_t y = 1; // Y position in the window

    for (uint8_t i = 0; i < 36; i++)
    {
        if(phrase[i] == '\0')
        {
            break; // Stop if null terminator is encountered
        }

        // Handle newline character by moving to the next line
        if (phrase[i] == '\n')
        {
            if (y == 1)
            {
                y = 3; // Move to the second line in the window
                x = 1; // Reset X position
            }
            else
            {
                break; // If already on the second line, stop rendering
            }
        }
        else
        {
            set_win_tile_xy(x, y, ConvertLetterToTile(phrase[i]));
            CBTFX_PLAY_tick;
            x++;
        }

        // Move to the next line if the end of the current line is reached
        if (x > 18)
        {
            if (y == 1)
            {
                y = 3; // Move to the second line in the window
                x = 1; // Reset X position
            }
            else
            {
                break; // If already on the second line, stop rendering
            }
        }

        PerformantDelay(2);
    }
    return;
}


// Function to convert an integer to a string
void itoa(uint16_t num, uint8_t* str, uint8_t base) {
    int i = 0;

    // Handle 0 explicitly
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    // Process individual digits
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    str[i] = '\0'; // Null-terminate the string

    // Reverse the string
    for (int j = 0; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}

// Modified SetText function to handle formatted strings
void SetTextFormatted(const uint8_t* format, uint16_t value) {
    char buffer[36];
    char numStr[12]; // Buffer for the integer converted to string

    itoa(value, numStr, 10); // Convert the integer to string

    // Replace %d with the number string
    int bufIdx = 0, fmtIdx = 0;
    while (format[fmtIdx] != '\0' && bufIdx < sizeof(buffer) - 1) {
        if (format[fmtIdx] == '%' && format[fmtIdx + 1] == 'd') {
            for (int i = 0; numStr[i] != '\0' && bufIdx < sizeof(buffer) - 1; i++) {
                buffer[bufIdx++] = numStr[i];
            }
            fmtIdx += 2; // Skip over %d
        } else {
            buffer[bufIdx++] = format[fmtIdx++];
        }
    }
    buffer[bufIdx] = '\0'; // Null-terminate the string

    SetText((uint8_t*)buffer);
}
/* 
// Usage example
void DisplayNumberExample() {
    int number = 12345;
    SetTextFormatted("Number: %d", number); // Display "Number: 12345"
} 
*/


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

uint8_t ConvertLetterToTile(uint8_t let)
{
    // uint8_t out = 0x2F;

    uint8_t out = let;


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

void DisplayDialogBox(uint8_t phrase[36])
{
    move_win(7, 104);
    uint8_t input = 0x00;
    SetDialogTiles();
    SHOW_WIN;
    SetText(phrase);
    while (!(input & J_A || input & J_B))
    {
        input = joypad();
        if (g_framecounter % 10 == 0)
        {
            set_win_tile_xy(0x13, 0x04, 0x2D);
        }
        if (g_framecounter % 10 == 5)
        {
            set_win_tile_xy(0x13, 0x04, 0x47);
        }
        SoftReset(input);
        IncrementFrame();
    }
    CBTFX_PLAY_confirm;
    PerformantDelay(6);
}

void DisplayDialogBoxNumber(uint8_t phrase[36], uint16_t number)
{
    move_win(7, 104);
    uint8_t input = 0x00;
    SetDialogTiles();
    SHOW_WIN;
    SetTextFormatted(phrase, number);
    while (!(input & J_A || input & J_B))
    {
        input = joypad();
        if (g_framecounter % 10 == 0)
        {
            set_win_tile_xy(0x13, 0x04, 0x2D);
        }
        if (g_framecounter % 10 == 5)
        {
            set_win_tile_xy(0x13, 0x04, 0x47);
        }
        SoftReset(input);
        IncrementFrame();
    }
    CBTFX_PLAY_confirm;
    PerformantDelay(6);
}