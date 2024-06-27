#include "screen-ops.h"

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