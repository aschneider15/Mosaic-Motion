#include "input-ops.h"

inline void SoftReset(uint8_t input)
{
    if((input & J_A) && (input & J_B) && (input & J_SELECT) && (input & J_START))
    {
        reset();
    }
}