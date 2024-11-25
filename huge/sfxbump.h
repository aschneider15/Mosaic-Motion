/*

	bump

	Sound Effect File.
	
	Info:
		Length			:	8
		Priority		:	15
		Channels used	:	Duty channel 2 & Noise channel
		SGB Support		:	No
*/

#ifndef __bump_h_INCLUDE
#define __bump_h_INCLUDE
#define CBTFX_PLAY_bump CBTFX_init(&bump[0])
extern const unsigned char bump[];
#endif