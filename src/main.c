#include <gb/gb.h>
#include <stdint.h>
#include <rand.h>
#include "../huge/hUGEDriver.h"
#include "./title-scene.h"
#include "./standard-mode-scene.h"

void main(void)
{

    // initialize random number generator with the Division register
    initrand(DIV_REG);

    enable_interrupts();

    // Cause song to advance at every vblank interrupt
    add_VBL(hUGE_dosound);

    uint8_t difficulty;
    // extern Stack SceneStack;
    // initialize(&SceneStack);

    DISPLAY_ON;
    // Loop forever
    while (1)
    {

        difficulty = TitleMainLoop();
        StandardModeMainLoop(difficulty);
    }
}