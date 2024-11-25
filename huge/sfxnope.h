/*

	nope

	Sound Effect File.
	
	Info:
		Length			:	10
		Priority		:	15
		Channels used	:	Duty channel 2 & Noise channel
		SGB Support		:	No
*/

#ifndef __nope_h_INCLUDE
#define __nope_h_INCLUDE
#define CBTFX_PLAY_nope CBTFX_init(&nope[0])
extern const unsigned char nope[];
#endif