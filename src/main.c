#include <gb/gb.h>
#include <stdint.h>
#include <rand.h>
#include "./title-scene.h"

void main(void)
{
    // initialize random number generator with the Division register
    initrand(DIV_REG);

    // Loop forever
    while (1)
    {
        TitleMainLoop();
    }
}