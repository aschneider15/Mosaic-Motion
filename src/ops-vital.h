#ifndef OPS_VITAL_H
#define OPS_VITAL_H

#include <gb/gb.h>
#include <stdint.h>
#include <rand.h>

#include "../huge/hUGEDriver.h"
#include "../huge/cbtfx.h"

#include "../huge/sfxbounce.h"
#include "../huge/sfxbump.h"
#include "../huge/sfxconfirm.h"
#include "../huge/sfxgo.h"
#include "../huge/sfxnope.h"
#include "../huge/sfxready.h"
#include "../huge/sfxready.h"
#include "../huge/sfxswipe1.h"
#include "../huge/sfxswipe2.h"
#include "../huge/sfxtick.h"

/* Enables a soft reset input (A + B + Start + Select).
    @param input The current player's input read from a call to joypad().
    @returns 1 if selection is entered by pressing A, or -1 if phase is cancelled by pressing B.
 */
inline void SoftReset(uint8_t input);

/* A function to be called during vblank interrupt. Advances the music and sfx drivers: hUGE and cbtfx
 */
void UpdateSoundDrivers(void);

/* Allows for background data from a banked file to be loaded into another banked file.
    @param first_tile Index of the first tile to write.
    @param nb_tiles Number of tiles to write.
    @param data Pointer to (2 bpp) source tile data.
    @param bank The bank in which the desired tile data is stored.

 */
inline void SetBKGBankedData(uint8_t first_tile, uint8_t nb_tiles, const uint8_t *data, uint8_t bank);

/* Allows for tilemap data from a banked file to be loaded into another banked file
    @param x X Start position in Background Map tile coordinates. Range 0-31
    @param y Y Start-position in Background Map tile coordinates. Range 0-31
    @param w Width of area to set in tiles. Range 1-32
    @param h Height of area to set in tiles. Range 1-32
    @param tiles Pointer to source tile map data
    @param bank The bank in which the desired tilemap data is stored
 */
inline void SetTilemapBankedData(uint8_t x, uint8_t y, uint8_t w, uint8_t h, const uint8_t *tiles, uint8_t bank);

/* Waits until the user has let go of a given input before processing a new one. This is done by calling itself recursively. 
   This function yields better battery life than waitpadup() because it doesn't eat up CPU cycles.
    @param previous_input The player's previous input.
 */
inline void WaitNewInput(uint8_t previous_input);

/* Global variable used to control most animations and non-halting delays. */
extern uint8_t g_framecounter;

/* Delays an action by waiting for vblank to occur for the given number of frames (originally written by GamingMonsters).
    \param frames The number of frames meant to be delayed; 0 is the shortest delay, and 255 is the longest.
*/
void PerformantDelay(uint8_t frames);

/* Call to increment the frame counter. Calling this function also calls vsync() in order to ensure smooth animation timing.*/
inline void IncrementFrame(void);


#endif