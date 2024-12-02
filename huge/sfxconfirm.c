#pragma bank 255
/*

	confirm

	Sound Effect File.
	
	Info:
		Length			:	8
		Priority		:	15
		Channels used	:	Noise channel
		SGB Support		:	No
*/

const void __at(255) __bank_sfx_confirm;
const unsigned char confirm[] = {
0x8F,0x09,0x81,0xAA,0x00,0xC0,0xD6,0x87,0x00,
0x00,0x60,0xD6,0x87,0x01,0x00,0x80,0xDF,0x87,
0x00,0x00,0x50,0xDF,0x87,0x01,0x00,0x40,0xD6,
0x87,0x00,0x00,0x20,0xD6,0x87,0x01,0x00,0x60,
0xDF,0x87,0x00,0x00,0x10,0xDF,0x87
};