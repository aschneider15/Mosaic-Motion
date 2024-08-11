#include <gb/gb.h>
#include <stdint.h>
#include <rand.h>
#include "./title-scene.h"
#include "./standard-mode-scene.h"

void main(void)
{

    // initialize random number generator with the Division register
    initrand(DIV_REG);

    // extern Stack SceneStack;
    // initialize(&SceneStack);

    DISPLAY_ON;
    // Loop forever
    while (1)
    {
        TitleMainLoop();
        StandardModeMainLoop();
    }
}