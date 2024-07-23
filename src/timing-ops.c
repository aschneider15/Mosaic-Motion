#include "timing-ops.h"

uint8_t g_framecounter = 0;

void PerformantDelay(uint8_t frames)
{
    for (int i = 0; i < frames; i++)
    {
        vsync();
    }
}

void IncrementFrame(void)
{
    g_framecounter++;
    if(g_framecounter >= 60)
    {
        g_framecounter = 0;
    }
    vsync();
}

uint8_t GetFrameCount(void)
{
    return g_framecounter;
}