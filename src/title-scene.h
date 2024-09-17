#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include <gb/gb.h>
#include <stdint.h>
#include <gb/sgb.h>

#include "../huge/hUGEDriver.h"
#include "./screen-ops.h"
#include "./dialogbox.h"
#include "../res/uimap_dialogbox.h"
#include "../res/tiles_general.h"
#include "../res/bkg_title.h"
#include "../res/spr_star.h"
#include "../res/border_default.h"

/* Initialize the background and sprites of the scene */
void TitleInitGraphics(void);

/* Operates the main loop for the Title scene */
uint8_t TitleMainLoop(void);

#endif