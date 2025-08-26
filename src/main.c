#include <gb/gb.h>
#include <stdint.h>
#include <rand.h>
#include "./ops-vital.h"
#include "./scene-title.h"
#include "./scene-selection.h"
#include "./scene-puzzle-solve.h"

void main(void)
{

    // initialize random number generator with the Division register
    initrand(DIV_REG);

    enable_interrupts();

    // Cause sound driver to advance at every vblank interrupt
    add_VBL(CBTFX_update);

    uint16_t settings;
    // extern Stack SceneStack;
    // initialize(&SceneStack);

    DISPLAY_ON;
    // Loop forever
    while (1)
    {
        SWITCH_ROM(BANK(TitleMainLoop));
        TitleMainLoop();
        settings = SelectionMainLoop();
        StandardModeMainLoop(settings);
    }
}