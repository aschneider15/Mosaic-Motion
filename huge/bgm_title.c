#pragma bank 255

#include "hUGEDriver.h"
#include <stddef.h>

static const unsigned char order_cnt = 22;

static const unsigned char P0[] = {
    DN(___,0,0xB0B),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P1[] = {
    DN(G_5,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(E_5,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_5,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(C_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(___,0,0xC02),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(D_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(___,0,0xC02),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_5,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0xC04),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0xC02),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
};
static const unsigned char P2[] = {
    DN(E_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(E_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(G_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(___,0,0xC01),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(___,0,0xC01),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(D_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0xC03),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0xC01),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
};
static const unsigned char P3[] = {
    DN(C_5,7,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(C_4,7,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(C_5,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(C_6,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(C_4,4,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(C_5,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(C_6,5,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(C_5,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(G_4,7,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(G_3,7,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(G_4,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(G_5,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(G_4,4,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(G_4,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(G_5,5,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(G_4,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
};
static const unsigned char P4[] = {
    DN(G_6,1,0xF03),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_7,2,0x000),
    DN(___,0,0x000),
    DN(G_7,2,0x000),
    DN(___,0,0x000),
    DN(G_7,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_7,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_7,3,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_7,3,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_7,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_7,3,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_7,3,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_7,3,0x000),
    DN(___,0,0x000),
    DN(G_7,3,0x000),
    DN(___,0,0x000),
    DN(G_7,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_7,3,0x000),
    DN(G_7,3,0x000),
    DN(G_7,3,0x000),
    DN(G_7,3,0x000),
    DN(G_7,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_7,3,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_7,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_6,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P5[] = {
    DN(A_5,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_5,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(A_5,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(D_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(___,0,0xC02),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(___,0,0xC02),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(B_5,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0xC04),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0xC02),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
};
static const unsigned char P6[] = {
    DN(F_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(D_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(A_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(___,0,0xC01),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(C_6,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(___,0,0xC01),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0xC03),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0xC01),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
};
static const unsigned char P7[] = {
    DN(F_4,7,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(F_3,7,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(F_4,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(F_5,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(F_3,4,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(F_4,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(F_5,5,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(F_4,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(G_4,7,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(G_3,7,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(G_4,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(G_5,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(G_4,4,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(G_4,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(G_5,5,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(G_4,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
};
static const unsigned char P8[] = {
    DN(D_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(B_5,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(D_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(G_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(___,0,0xC02),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(F_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(D_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(F_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(F_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(E_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(___,0,0xC02),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(A_5,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(B_5,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(C_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
};
static const unsigned char P9[] = {
    DN(B_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(B_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(D_6,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(D_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(A_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(G_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(A_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(Gs5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(Gs5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(___,0,0xC01),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(E_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(D_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(E_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
};
static const unsigned char P10[] = {
    DN(E_4,7,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(E_3,7,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(E_4,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(E_5,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(E_3,4,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(D_4,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(D_5,5,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(F_5,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(Gs5,7,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(Gs4,7,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(Gs4,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(A_4,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(A_3,4,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(A_4,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(A_5,5,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(G_5,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
};
static const unsigned char P11[] = {
    DN(C_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0xC04),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(A_5,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(B_5,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(C_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(D_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0xC04),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
};
static const unsigned char P12[] = {
    DN(G_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(C_5,3,0xC08),
    DN(___,0,0x000),
    DN(G_5,3,0xC03),
    DN(___,0,0x000),
    DN(D_5,3,0xC08),
    DN(___,0,0x000),
    DN(C_5,3,0xC03),
    DN(___,0,0x000),
    DN(G_5,3,0xC08),
    DN(___,0,0x000),
    DN(D_5,3,0xC03),
    DN(___,0,0x000),
    DN(C_5,3,0xC08),
    DN(___,0,0x000),
    DN(G_5,3,0xC03),
    DN(___,0,0x000),
    DN(D_5,3,0xC08),
    DN(___,0,0x000),
    DN(C_5,3,0xC03),
    DN(___,0,0x000),
    DN(G_5,3,0xC08),
    DN(___,0,0x000),
    DN(D_5,3,0xC03),
    DN(___,0,0x000),
    DN(D_5,3,0xC08),
    DN(___,0,0x000),
    DN(G_5,3,0xC03),
    DN(___,0,0x000),
    DN(C_6,3,0xC08),
    DN(___,0,0x000),
    DN(D_5,3,0xC03),
    DN(___,0,0x000),
    DN(B_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(A_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(B_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
};
static const unsigned char P13[] = {
    DN(F_4,7,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(F_3,7,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(F_4,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(F_5,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(F_3,4,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(F_4,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(F_5,5,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(F_4,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(G_4,7,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(G_3,7,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(G_4,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(G_5,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(G_4,4,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(G_4,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(A_4,5,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(B_4,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
};
static const unsigned char P14[] = {
    DN(C_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0xC04),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(A_5,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(B_5,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(C_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(D_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0xC04),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(B_5,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(C_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(D_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
};
static const unsigned char P15[] = {
    DN(G_5,3,0xC08),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(C_5,3,0xC08),
    DN(___,0,0x000),
    DN(G_5,3,0xC03),
    DN(___,0,0x000),
    DN(D_5,3,0xC08),
    DN(___,0,0x000),
    DN(C_5,3,0xC03),
    DN(___,0,0x000),
    DN(G_5,3,0xC08),
    DN(___,0,0x000),
    DN(D_5,3,0xC03),
    DN(___,0,0x000),
    DN(C_5,3,0xC08),
    DN(___,0,0x000),
    DN(G_5,3,0xC03),
    DN(___,0,0x000),
    DN(D_5,3,0xC08),
    DN(___,0,0x000),
    DN(C_5,3,0xC03),
    DN(___,0,0x000),
    DN(G_5,3,0xC08),
    DN(___,0,0x000),
    DN(D_5,3,0xC03),
    DN(___,0,0x000),
    DN(C_5,3,0xC08),
    DN(___,0,0x000),
    DN(G_5,3,0xC03),
    DN(___,0,0x000),
    DN(G_5,3,0xC08),
    DN(___,0,0x000),
    DN(C_5,3,0xC03),
    DN(___,0,0x000),
    DN(D_5,3,0xC08),
    DN(___,0,0x000),
    DN(G_5,3,0xC03),
    DN(___,0,0x000),
    DN(F_5,3,0xC08),
    DN(___,0,0x000),
    DN(D_5,3,0xC03),
    DN(___,0,0x000),
    DN(G_5,3,0xC08),
    DN(___,0,0x000),
    DN(F_5,3,0xC03),
    DN(___,0,0x000),
    DN(D_5,3,0xC08),
    DN(___,0,0x000),
    DN(G_5,3,0xC03),
    DN(___,0,0x000),
    DN(F_5,3,0xC08),
    DN(___,0,0x000),
    DN(D_5,3,0xC03),
    DN(___,0,0x000),
    DN(G_5,3,0xC08),
    DN(___,0,0x000),
    DN(F_5,3,0xC03),
    DN(___,0,0x000),
    DN(D_5,3,0xC08),
    DN(___,0,0x000),
    DN(G_5,3,0xC03),
    DN(___,0,0x000),
};
static const unsigned char P17[] = {
    DN(Ds6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0xC04),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(C_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(D_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(Ds6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(F_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0xC04),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(D_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(Ds6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
    DN(F_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0xC04),
    DN(___,0,0x000),
};
static const unsigned char P18[] = {
    DN(Gs5,3,0xC08),
    DN(___,0,0x000),
    DN(D_5,3,0xC03),
    DN(___,0,0x000),
    DN(C_5,3,0xC08),
    DN(___,0,0x000),
    DN(Gs5,3,0xC03),
    DN(___,0,0x000),
    DN(Ds5,3,0xC08),
    DN(___,0,0x000),
    DN(C_5,3,0xC03),
    DN(___,0,0x000),
    DN(Gs5,3,0xC08),
    DN(___,0,0x000),
    DN(Ds5,3,0xC03),
    DN(___,0,0x000),
    DN(C_5,3,0xC08),
    DN(___,0,0x000),
    DN(Gs5,3,0xC03),
    DN(___,0,0x000),
    DN(Ds5,3,0xC08),
    DN(___,0,0x000),
    DN(C_5,3,0xC03),
    DN(___,0,0x000),
    DN(Gs5,3,0xC08),
    DN(___,0,0x000),
    DN(Ds5,3,0xC03),
    DN(___,0,0x000),
    DN(Ds5,3,0xC08),
    DN(___,0,0x000),
    DN(Gs5,3,0xC03),
    DN(___,0,0x000),
    DN(As5,3,0xC08),
    DN(___,0,0x000),
    DN(Ds5,3,0xC03),
    DN(___,0,0x000),
    DN(Ds5,3,0xC08),
    DN(___,0,0x000),
    DN(As5,3,0xC03),
    DN(___,0,0x000),
    DN(F_5,3,0xC08),
    DN(___,0,0x000),
    DN(Ds5,3,0xC03),
    DN(___,0,0x000),
    DN(As5,3,0xC08),
    DN(___,0,0x000),
    DN(F_5,3,0xC03),
    DN(___,0,0x000),
    DN(Ds5,3,0xC08),
    DN(___,0,0x000),
    DN(As5,3,0xC03),
    DN(___,0,0x000),
    DN(F_5,3,0xC08),
    DN(___,0,0x000),
    DN(Ds5,3,0xC03),
    DN(___,0,0x000),
    DN(As5,3,0xC08),
    DN(___,0,0x000),
    DN(F_5,3,0xC03),
    DN(___,0,0x000),
    DN(F_5,3,0xC08),
    DN(___,0,0x000),
    DN(As5,3,0xC03),
    DN(___,0,0x000),
};
static const unsigned char P19[] = {
    DN(Gs4,7,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(Gs3,7,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(Gs4,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(Gs5,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(Gs3,4,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(Gs4,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(Gs5,5,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(Gs4,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(As4,7,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(As3,7,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(As4,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(As5,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(As4,4,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(As4,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(As5,5,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(As4,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
};
static const unsigned char P20[] = {
    DN(G_6,3,0xC0A),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0xC04),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0xC02),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0xC01),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0x441),
    DN(___,0,0xC00),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};
static const unsigned char P21[] = {
    DN(C_6,3,0xC08),
    DN(___,0,0x000),
    DN(As5,3,0xC03),
    DN(___,0,0x000),
    DN(E_5,3,0xC08),
    DN(___,0,0x000),
    DN(C_6,3,0xC03),
    DN(___,0,0x000),
    DN(G_5,3,0xC08),
    DN(___,0,0x000),
    DN(E_5,3,0xC03),
    DN(___,0,0x000),
    DN(C_6,3,0xC08),
    DN(___,0,0x000),
    DN(G_5,3,0xC03),
    DN(___,0,0x000),
    DN(E_5,3,0xC07),
    DN(___,0,0x000),
    DN(C_6,3,0xC03),
    DN(___,0,0x000),
    DN(G_5,3,0xC07),
    DN(___,0,0x000),
    DN(E_5,3,0xC03),
    DN(___,0,0x000),
    DN(C_6,3,0xC07),
    DN(___,0,0x000),
    DN(G_5,3,0xC03),
    DN(___,0,0x000),
    DN(E_5,3,0xC06),
    DN(___,0,0x000),
    DN(C_6,3,0xC02),
    DN(___,0,0x000),
    DN(G_5,3,0xC06),
    DN(___,0,0x000),
    DN(E_5,3,0xC02),
    DN(___,0,0x000),
    DN(C_6,3,0xC06),
    DN(___,0,0x000),
    DN(G_5,3,0xC02),
    DN(___,0,0x000),
    DN(E_5,3,0xC05),
    DN(___,0,0x000),
    DN(C_6,3,0xC02),
    DN(___,0,0x000),
    DN(G_5,3,0xC05),
    DN(___,0,0x000),
    DN(E_5,3,0xC02),
    DN(___,0,0x000),
    DN(C_6,3,0xC04),
    DN(___,0,0x000),
    DN(G_5,3,0xC01),
    DN(___,0,0x000),
    DN(E_5,3,0xC03),
    DN(___,0,0x000),
    DN(C_6,3,0xC00),
    DN(___,0,0x000),
    DN(G_5,3,0xC03),
    DN(___,0,0x000),
    DN(E_5,3,0xC00),
    DN(___,0,0x000),
    DN(C_6,3,0xC02),
    DN(___,0,0x000),
    DN(G_5,3,0xC00),
    DN(___,0,0x000),
};
static const unsigned char P22[] = {
    DN(C_5,7,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(C_4,7,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(C_5,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(C_6,4,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(C_4,4,0xC06),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(C_5,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(C_6,5,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(C_5,6,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(C_4,7,0xC0B),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xC06),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xC03),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0xC00),
};
static const unsigned char P23[] = {
    DN(G_6,1,0xF03),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_7,2,0x000),
    DN(___,0,0x000),
    DN(G_7,2,0x000),
    DN(___,0,0x000),
    DN(G_7,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_7,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_7,3,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_7,3,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_7,2,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_7,3,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(G_7,2,0xF03),
    DN(G_7,2,0x000),
    DN(G_7,2,0x000),
    DN(G_7,2,0x000),
    DN(G_7,2,0x000),
    DN(G_7,2,0x000),
    DN(G_7,2,0x000),
    DN(G_7,2,0x000),
    DN(G_7,2,0x000),
    DN(G_7,3,0x000),
    DN(G_7,3,0x000),
    DN(G_7,3,0x000),
    DN(G_7,3,0xF04),
    DN(G_7,3,0xF03),
    DN(G_7,3,0xF04),
    DN(G_7,3,0xF03),
    DN(G_7,3,0xF04),
    DN(G_7,3,0x000),
    DN(G_7,3,0x000),
    DN(G_7,3,0x000),
    DN(G_7,3,0xF05),
    DN(G_7,3,0xF04),
    DN(G_7,3,0xF05),
    DN(G_7,3,0xF04),
    DN(G_7,3,0xF05),
    DN(G_7,3,0xF04),
    DN(G_7,3,0xF05),
    DN(G_7,3,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
    DN(___,0,0x000),
};

static const unsigned char* const order1[] = {P1,P5,P8,P11,P1,P5,P8,P14,P17,P20,P0};
static const unsigned char* const order2[] = {P2,P6,P9,P12,P2,P6,P9,P15,P18,P21,P0};
static const unsigned char* const order3[] = {P3,P7,P10,P13,P3,P7,P10,P7,P19,P22,P0};
static const unsigned char* const order4[] = {P4,P4,P4,P4,P4,P4,P4,P4,P4,P23,P0};

static const hUGEDutyInstr_t duty_instruments[] = {
    {8,0,240,0,128},
    {8,64,240,0,128},
    {8,128,240,0,128},
};
static const hUGEWaveInstr_t wave_instruments[] = {
    {0,32,0,0,128},
    {0,32,1,0,128},
    {0,32,2,0,128},
    {0,32,3,0,128},
    {0,32,4,0,128},
    {0,32,5,0,128},
    {0,32,6,0,128},
};
static const hUGENoiseInstr_t noise_instruments[] = {
    {177,0,0,0,0},
    {113,0,0,0,0},
    {65,0,0,0,0},
};

static const unsigned char waves[] = {
    0,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,
    0,0,0,0,255,255,255,255,255,255,255,255,255,255,255,255,
    0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,255,
    255,238,221,204,187,170,153,136,119,102,85,68,51,34,17,0,
    0,0,0,0,170,170,187,204,221,221,255,255,255,255,0,255,
    0,0,0,0,170,170,187,204,221,221,255,255,255,255,170,255,
    0,0,102,170,187,221,255,255,255,255,255,255,255,255,255,255,
};

const void __at(255) __bank_bgm_title;
const hUGESong_t bgm_title = {3, &order_cnt, order1, order2, order3,order4, duty_instruments, wave_instruments, noise_instruments, NULL, waves};
