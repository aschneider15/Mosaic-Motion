#include "timing-ops.h"

void PerformantDelay(uint8_t frames)
{
    for (int i = 0; i < frames; i++)
    {
        vsync();
    }
}