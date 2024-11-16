#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include <gb/gb.h>
#include <stdint.h>
#include <gb/sgb.h>
#include "../huge/hUGEDriver.h"

#include "ops-vital.h"
#include "./ops-screen.h"
#include "../res/uimap_dialogbox.h"
#include "../res/tiles_general.h"
#include "../res/bkg_title.h"
#include "../res/spr_star.h"
#include "../res/border_default.h"

/* Initialize the background, sprites, music, etc. of the scene */
void TitleInit(void) BANKED;

/* Operates the main loop for the Title scene */
uint8_t TitleMainLoop(void) BANKED;
BANKREF_EXTERN(TitleMainLoop)

#endif