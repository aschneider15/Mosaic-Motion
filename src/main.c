#include <gb/gb.h>
#include <stdint.h>
#include <rand.h>
#include "./screen-ops.h"
#include "./scene-title.h"

void main(void)
{
    // initialize random number generator with the Division register
    initrand(DIV_REG);
    uint8_t framecount;
    InitGraphics_Title();

    // Loop forever
    while (1)
    {
        SpriteActivity_Title();

        uint8_t input = joypad();

        if (input & J_A)
        {
            ShakeScreen(1, 2, 0, 20);
        }
        else if (input & J_B)
        {
            ShakeScreen(1, 2, 1, 20);
        }

        if (input & J_START)
        {
            if (BGP_REG == NTRL)
            {
                BlkFadeOut(10);
            }
            else if (BGP_REG == BLK3)
            {
                BlkFadeIn(10);
            }
        }

        else if (input & J_SELECT)
        {
            if (BGP_REG == NTRL)
            {
                WhtFadeOut(1);
            }
            else if (BGP_REG == WHT3)
            {
                WhtFadeIn(1);
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