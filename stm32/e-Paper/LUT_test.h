/**
 ******************************************************************************
 * @file      LUT_test.h
 * @author    ts-manuel
 * @brief     Test LUTs
 *
 ******************************************************************************
 */

#ifndef LUT_TEST_H_
#define LUT_TEST_H_

#include <stdint.h>

//VCOM Levels
#define VCM_DC	0	//TFT adjustable negative bias (-1V)
#define VCM_HI	1	//15V + VCM_DC
#define VCM_LO	2	//-15V + VCM_DC
#define VCM_FL	3	//Floating
#define VCM_LV(_l1, _l2, _l3, _l4, _l5, _l6, _l7, _l8) ((_l1)<<6)|((_l2)<<4)|((_l3)<<2)|(_l4), ((_l5)<<6)|((_l6)<<4)|((_l7)<<2)|(_l8)
//PIXEL Levels
#define PIX_GND	0	//0V
#define PIX_VSH	1	//15V
#define PIX_VSL 2	//-15V
#define PIX_LVH 3	//VSH_LV adjustable (10V)
#define PIX_LVL 4	//VSL_LV adjustable (-10V)
#define PIX_LV2 5	//NON used
#define PIX_FLT	7	//Floating
#define PIX_LV(_l1, _l2, _l3, _l4, _l5, _l6, _l7, _l8) ((_l1)<<4)|(_l2), ((_l3)<<4)|(_l4), ((_l5)<<4)|(_l6), ((_l7)<<4)|(_l8)
//XON Levels
#define XON_VGH	0	//All gate ON (VGH)
#define XON_SCN	1	//Normal gate scan function
#define XON_LV(_l1, _l2, _l3, _l4, _l5, _l6, _l7, _l8) ((_l1)<<7)|((_l1)<<6)|((_l1)<<5)|((_l1)<<4)|((_l1)<<3)|((_l1)<<2)|((_l1)<<1)|(_l1)

//----------------------------
// Stock LUTs
//----------------------------
const uint8_t LUT_VCOM[] = {
	1, VCM_LV(VCM_DC, VCM_HI, VCM_LO, VCM_HI, VCM_DC, VCM_LO, VCM_DC, VCM_HI),  1,100,100, 25,  1, 25,  1, 25,
	1, VCM_LV(VCM_DC, VCM_LO, VCM_DC, VCM_HI, VCM_DC, VCM_LO, VCM_DC, VCM_HI),  1, 25,  1, 25,  1, 25,  1, 25,
	1, VCM_LV(VCM_DC, VCM_LO, VCM_DC, VCM_HI, VCM_DC, VCM_LO, VCM_DC, VCM_HI),  1, 25,  1, 25,  1, 25,  1, 25,
	1, VCM_LV(VCM_DC, VCM_LO, VCM_DC, VCM_DC, VCM_DC, VCM_DC, VCM_DC, VCM_DC),  1, 25, 52,  0,  0,  0,  0,  0,
};

const uint8_t LUT_COLOR_0[] = {
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND),  1, 50, 77, 73, 25,  1, 25,  1,
	1, PIX_LV(PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND), 25,  1, 25,  1, 25,  1, 25,  1,
	1, PIX_LV(PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND), 25,  1, 14, 12, 25,  1, 14, 12,
	1, PIX_LV(PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL, PIX_GND, PIX_GND, PIX_GND, PIX_GND), 22,  3,  1, 14, 63,  0,  0,  0,
};

const uint8_t LUT_COLOR_1[] = {
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL, PIX_VSH),  1, 57, 43,103, 22,  1, 17,  8,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH),  1,  3, 22,  1, 17,  8,  1,  3,
	1, PIX_LV(PIX_VSL, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_VSL, PIX_GND), 22,  1, 17,  8,  1,  3, 22,  1,
	1, PIX_LV(PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND), 17,  8,  1, 25,  1, 17,  8,  1,
	1, PIX_LV(PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_LVH, PIX_GND),  3, 22,  1, 17,  8, 12, 14, 26,
};

const uint8_t LUT_COLOR_2[] = {
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH),  1, 32, 68,113, 13, 21,  5, 13,
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH), 13, 21,  5, 13, 13, 25,  1, 13,
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH), 13, 25,  1, 13, 13, 25,  1, 13,
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND), 13, 25, 52,  0,  0,  0,  0,  0,
};

const uint8_t LUT_COLOR_3[] = {
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH),  1, 67, 33,125,  1, 25,  1,  5,
	1, PIX_LV(PIX_VSL, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL), 20,  1, 12, 14,  5, 20,  1, 12,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_VSL), 14,  5, 20,  1, 12, 14,  5, 20,
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL, PIX_GND),  1, 12, 14,  5, 20,  1, 12, 65,
};

const uint8_t LUT_COLOR_4[] = {
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_VSL),  1,139, 86,  1, 25,  1, 16,  9,
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH),  1, 12, 13,  1, 25,  1, 12, 13,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND),  1, 25,  1, 12, 13,  1, 25,  1,
	1, PIX_LV(PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL, PIX_GND), 12, 13,  1, 16,  9,  1, 25, 11,
	1, PIX_LV(PIX_LVH, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND), 15, 26,  0,  0,  0,  0,  0,  0,
};

const uint8_t LUT_COLOR_5[] = {
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH),  1, 78, 22,125,  1, 25,  1,  5,
	1, PIX_LV(PIX_VSL, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL), 20,  1, 24,  2,  5, 20,  1, 24,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND),  2,  5, 20,  1, 24,  2, 25,  1,
	1, PIX_LV(PIX_VSL, PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL, PIX_GND, PIX_LVL), 25,  1,  5, 20,  1, 24, 51,  1,
	1, PIX_LV(PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND),  1,  0,  0,  0,  0,  0,  0,  0,
};

const uint8_t LUT_COLOR_6[] = {
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_VSL),  1,130, 95,  1,  1, 25, 15, 10,
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH),  1,  1, 25, 25,  1,  1, 25, 15,
	1, PIX_LV(PIX_VSL, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND), 10,  1,  1, 25, 25,  1,  1, 25,
	1, PIX_LV(PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL, PIX_GND, PIX_GND, PIX_GND, PIX_GND), 15, 10,  1, 25, 52,  0,  0,  0,
};

const uint8_t LUT_COLOR_7[] = {
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH),  1, 58, 42,100, 19,  7, 23,  2,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND),  1, 19,  7, 23,  2,  1, 19,  7,
	1, PIX_LV(PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND), 23,  2,  1, 19,  7, 23,  2,  1,
	1, PIX_LV(PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL), 19,  7, 23,  2,  1, 19,  7, 25,
	1, PIX_LV(PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND), 52,  0,  0,  0,  0,  0,  0,  0,
};

const uint8_t LUT_XON[] = {
	1, XON_LV(XON_SCN, XON_SCN, XON_SCN, XON_SCN, XON_SCN, XON_SCN, XON_SCN, XON_VGH), 255,255, 54,  0,  0,  0,  0,  0,
};


//----------------------------
// Self clear with transparent color LUTs
//----------------------------
const uint8_t LUT_VCOM_SC[] = {
	1, VCM_LV(VCM_DC, VCM_HI, VCM_LO, VCM_HI, VCM_DC, VCM_LO, VCM_DC, VCM_HI),  1,100,100, 25,  1, 25,  1, 25,
	1, VCM_LV(VCM_DC, VCM_LO, VCM_DC, VCM_HI, VCM_DC, VCM_LO, VCM_DC, VCM_HI),  1, 25,  1, 25,  1, 25,  1, 25,
	1, VCM_LV(VCM_DC, VCM_LO, VCM_DC, VCM_HI, VCM_DC, VCM_LO, VCM_DC, VCM_HI),  1, 25,  1, 25,  1, 25,  1, 25,
	1, VCM_LV(VCM_DC, VCM_LO, VCM_DC, VCM_DC, VCM_DC, VCM_DC, VCM_DC, VCM_DC),  1, 25, 52,  0,  0,  0,  0,  0,
	1, VCM_LV(VCM_DC, VCM_HI, VCM_LO, VCM_HI, VCM_DC, VCM_LO, VCM_DC, VCM_HI),  1,100,100, 25,  1, 25,  1, 25,
	1, VCM_LV(VCM_DC, VCM_LO, VCM_DC, VCM_HI, VCM_DC, VCM_LO, VCM_DC, VCM_HI),  1, 25,  1, 25,  1, 25,  1, 25,
	1, VCM_LV(VCM_DC, VCM_LO, VCM_DC, VCM_HI, VCM_DC, VCM_LO, VCM_DC, VCM_HI),  1, 25,  1, 25,  1, 25,  1, 25,
	1, VCM_LV(VCM_DC, VCM_LO, VCM_DC, VCM_DC, VCM_DC, VCM_DC, VCM_DC, VCM_DC),  1, 25, 52,  0,  0,  0,  0,  0,
};

const uint8_t LUT_COLOR_0_SC[] = {
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH),  1, 58, 42,100, 19,  7, 23,  2,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND),  1, 19,  7, 23,  2,  1, 19,  7,
	1, PIX_LV(PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND), 23,  2,  1, 19,  7, 23,  2,  1,
	1, PIX_LV(PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL), 19,  7, 23,  2,  1, 19,  7, 25,
	1, PIX_LV(PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND), 52,  0,  0,  0,  0,  0,  0,  0,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND),  1, 50, 77, 73, 25,  1, 25,  1,
	1, PIX_LV(PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND), 25,  1, 25,  1, 25,  1, 25,  1,
	1, PIX_LV(PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND), 25,  1, 14, 12, 25,  1, 14, 12,
	1, PIX_LV(PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL, PIX_GND, PIX_GND, PIX_GND, PIX_GND), 22,  3,  1, 14, 63,  0,  0,  0,
};

const uint8_t LUT_COLOR_1_SC[] = {
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH),  1, 58, 42,100, 19,  7, 23,  2,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND),  1, 19,  7, 23,  2,  1, 19,  7,
	1, PIX_LV(PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND), 23,  2,  1, 19,  7, 23,  2,  1,
	1, PIX_LV(PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL), 19,  7, 23,  2,  1, 19,  7, 25,
	1, PIX_LV(PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND), 52,  0,  0,  0,  0,  0,  0,  0,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL, PIX_VSH),  1, 57, 43,103, 22,  1, 17,  8,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH),  1,  3, 22,  1, 17,  8,  1,  3,
	1, PIX_LV(PIX_VSL, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_VSL, PIX_GND), 22,  1, 17,  8,  1,  3, 22,  1,
	1, PIX_LV(PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND), 17,  8,  1, 25,  1, 17,  8,  1,
	1, PIX_LV(PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_LVH, PIX_GND),  3, 22,  1, 17,  8, 12, 14, 26,
};

const uint8_t LUT_COLOR_2_SC[] = {
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH),  1, 58, 42,100, 19,  7, 23,  2,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND),  1, 19,  7, 23,  2,  1, 19,  7,
	1, PIX_LV(PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND), 23,  2,  1, 19,  7, 23,  2,  1,
	1, PIX_LV(PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL), 19,  7, 23,  2,  1, 19,  7, 25,
	1, PIX_LV(PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND), 52,  0,  0,  0,  0,  0,  0,  0,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH),  1, 32, 68,113, 13, 21,  5, 13,
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH), 13, 21,  5, 13, 13, 25,  1, 13,
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH), 13, 25,  1, 13, 13, 25,  1, 13,
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND), 13, 25, 52,  0,  0,  0,  0,  0,
};

const uint8_t LUT_COLOR_3_SC[] = {
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH),  1, 58, 42,100, 19,  7, 23,  2,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND),  1, 19,  7, 23,  2,  1, 19,  7,
	1, PIX_LV(PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND), 23,  2,  1, 19,  7, 23,  2,  1,
	1, PIX_LV(PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL), 19,  7, 23,  2,  1, 19,  7, 25,
	1, PIX_LV(PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND), 52,  0,  0,  0,  0,  0,  0,  0,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH),  1, 67, 33,125,  1, 25,  1,  5,
	1, PIX_LV(PIX_VSL, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL), 20,  1, 12, 14,  5, 20,  1, 12,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_VSL), 14,  5, 20,  1, 12, 14,  5, 20,
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL, PIX_GND),  1, 12, 14,  5, 20,  1, 12, 65,
};

const uint8_t LUT_COLOR_4_SC[] = {
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH),  1, 58, 42,100, 19,  7, 23,  2,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND),  1, 19,  7, 23,  2,  1, 19,  7,
	1, PIX_LV(PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND), 23,  2,  1, 19,  7, 23,  2,  1,
	1, PIX_LV(PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL), 19,  7, 23,  2,  1, 19,  7, 25,
	1, PIX_LV(PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND), 52,  0,  0,  0,  0,  0,  0,  0,
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_VSL),  1,139, 86,  1, 25,  1, 16,  9,
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH),  1, 12, 13,  1, 25,  1, 12, 13,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND),  1, 25,  1, 12, 13,  1, 25,  1,
	1, PIX_LV(PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL, PIX_GND), 12, 13,  1, 16,  9,  1, 25, 11,
	1, PIX_LV(PIX_LVH, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND), 15, 26,  0,  0,  0,  0,  0,  0,
};

const uint8_t LUT_COLOR_5_SC[] = {
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH),  1, 58, 42,100, 19,  7, 23,  2,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND),  1, 19,  7, 23,  2,  1, 19,  7,
	1, PIX_LV(PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND), 23,  2,  1, 19,  7, 23,  2,  1,
	1, PIX_LV(PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL), 19,  7, 23,  2,  1, 19,  7, 25,
	1, PIX_LV(PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND), 52,  0,  0,  0,  0,  0,  0,  0,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH),  1, 78, 22,125,  1, 25,  1,  5,
	1, PIX_LV(PIX_VSL, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL), 20,  1, 24,  2,  5, 20,  1, 24,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND),  2,  5, 20,  1, 24,  2, 25,  1,
	1, PIX_LV(PIX_VSL, PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL, PIX_GND, PIX_LVL), 25,  1,  5, 20,  1, 24, 51,  1,
	1, PIX_LV(PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND),  1,  0,  0,  0,  0,  0,  0,  0,
};

const uint8_t LUT_COLOR_6_SC[] = {
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH),  1, 58, 42,100, 19,  7, 23,  2,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND),  1, 19,  7, 23,  2,  1, 19,  7,
	1, PIX_LV(PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND), 23,  2,  1, 19,  7, 23,  2,  1,
	1, PIX_LV(PIX_VSH, PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL), 19,  7, 23,  2,  1, 19,  7, 25,
	1, PIX_LV(PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND), 52,  0,  0,  0,  0,  0,  0,  0,
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_VSL),  1,130, 95,  1,  1, 25, 15, 10,
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH),  1,  1, 25, 25,  1,  1, 25, 15,
	1, PIX_LV(PIX_VSL, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND), 10,  1,  1, 25, 25,  1,  1, 25,
	1, PIX_LV(PIX_VSH, PIX_VSL, PIX_GND, PIX_VSL, PIX_GND, PIX_GND, PIX_GND, PIX_GND), 15, 10,  1, 25, 52,  0,  0,  0,
};

const uint8_t LUT_COLOR_7_SC[] = {
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH),  1,100,100, 25,  1, 25,  1, 25,
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH),  1, 25,  1, 25,  1, 25,  1, 25,
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH),  1, 25,  1, 25,  1, 25,  1, 25,
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND),  1, 25, 52,  0,  0,  0,  0,  0,
	1, PIX_LV(PIX_GND, PIX_VSH, PIX_VSL, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH),  1,100,100, 25,  1, 25,  1, 25,
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH),  1, 25,  1, 25,  1, 25,  1, 25,
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_GND, PIX_VSH, PIX_GND, PIX_VSL, PIX_GND, PIX_VSH),  1, 25,  1, 25,  1, 25,  1, 25,
	1, PIX_LV(PIX_GND, PIX_VSL, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND, PIX_GND),  1, 25, 52,  0,  0,  0,  0,  0,
};

const uint8_t LUT_XON_SC[] = {
	1, XON_LV(XON_SCN, XON_SCN, XON_SCN, XON_SCN, XON_SCN, XON_SCN, XON_SCN, XON_VGH), 255,255, 54,  0,  0,  0,  0,  0,
	1, XON_LV(XON_SCN, XON_SCN, XON_SCN, XON_SCN, XON_SCN, XON_SCN, XON_SCN, XON_VGH), 255,255, 54,  0,  0,  0,  0,  0,
};

#endif /* LUT_TEST_H_ */
