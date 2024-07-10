#include <string.h>
#include <stdio.h>
#include <gb/gb.h>
#include <stdint.h>
#include "./timing-ops.h"
#include "../res/uimap_dialogbox.h"
#include "../res/tiles_general.h"

/* Fills the window with the tiles required to render a blank dialog box 
    Note: the default size of the dialoge box supports two lines of eighteen chars.
*/
void SetDialogTiles(void);

/* Sets the tiles in the window layer to the eighteen characters which are passed. Bear in mind that the first eighteen characters will occupy the first line, and the second set will follow below.
    \param phrase Eighteen characters for the first line, followed immediately by the eighteen characters of the second line. Any greater number of characters will result in truncated text.
    \param text_speed The speed at which text is scrolled onto the screen. 0 is instantaneous, and 255 is extremely slow.
    TEXT SPEED ISN'T WORKING AS INTENDED. PLEASE PASS 0 FOR NOW FOR PERFORMANCE.
*/
void SetText(uint8_t phrase[36], uint8_t text_speed);

/* Sets the label or "speaker" tiles in the window layer to the (maximum) seventeen characters which are passed. It terminates upon encountering NULL, upon which the 'label end' tile will be drawn. If no label is desired, pass a single forward slash ("/").
    \param label Up to seventeen characters to be placed starting on the second tile of the first row of the window layer.
*/
void SetLabel(uint8_t label[17]);

/* Converts the letter into a writable tile corresponding to the general tileset.
    \param let The letter which is to be translated.
 */
uint8_t ConvertLetterToTile(char let);

/* Uses previously defined functions to create a dialogue box to display to the screen. 
    \param phrase Eighteen characters for the first line, followed immediately by the eighteen characters of the second line. Any greater number of characters will result in truncated text.
    \param text_speed The speed at which text is scrolled onto the screen. 0 is instantaneous, and 255 is extremely slow.
    \param label Up to seventeen characters to be placed starting on the second tile of the first row of the window layer.
 */
void DisplayDialogBox(uint8_t phrase[36], uint8_t text_speed, uint8_t label[17]);