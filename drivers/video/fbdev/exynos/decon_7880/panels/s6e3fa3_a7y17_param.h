#ifndef __S6E3FA3_A7Y17_PARAM_H__
#define __S6E3FA3_A7Y17_PARAM_H__

#include <linux/types.h>
#include <linux/kernel.h>
#include "dynamic_aid_s6e3fa3_a7y17.h"

#define EXTEND_BRIGHTNESS	365
#define UI_MAX_BRIGHTNESS	255
#define UI_DEFAULT_BRIGHTNESS	128
#define NORMAL_TEMPERATURE	25	/* 25 degrees Celsius */

#define GAMMA_CMD_CNT				((u16)ARRAY_SIZE(SEQ_GAMMA_CONDITION_SET))
#define ACL_CMD_CNT					((u16)ARRAY_SIZE(SEQ_ACL_OFF))
#define OPR_CMD_CNT					((u16)ARRAY_SIZE(SEQ_ACL_OPR_OFF))
#define ELVSS_CMD_CNT				((u16)ARRAY_SIZE(SEQ_ELVSS_SET))
#define AID_CMD_CNT					((u16)ARRAY_SIZE(SEQ_AID_SETTING))
#define TSET_CMD_CNT				((u16)ARRAY_SIZE(SEQ_TSET_SETTING))

#define LDI_REG_ELVSS				0xB6
#define LDI_REG_COORDINATE			0xA1
#define LDI_REG_DATE				LDI_REG_MTP
#define LDI_REG_ID					0x04
#define LDI_REG_CHIP_ID				0xD6
#define LDI_REG_MTP					0xC8
#define LDI_REG_HBM					0xB4
#define LDI_REG_RDDPM				0x0A
#define LDI_REG_RDDSM				0x0E
#define LDI_REG_ESDERR				0xEE
#define LDI_REG_MANUFACTURE_INFO	0xC9

/* len is read length */
#define LDI_LEN_ELVSS				(ELVSS_CMD_CNT - 1)
#define LDI_LEN_COORDINATE			4
#define LDI_LEN_DATE				7
#define LDI_LEN_ID					3
#define LDI_LEN_CHIP_ID				5
#define LDI_LEN_MTP					35
#define LDI_LEN_HBM					28
#define LDI_LEN_RDDPM				1
#define LDI_LEN_RDDSM				1
#define LDI_LEN_ESDERR				1
#define LDI_LEN_MANUFACTURE_INFO	21

/* offset is position including addr, not only para */
#define LDI_OFFSET_AOR_1	1
#define LDI_OFFSET_AOR_2	2

#define LDI_OFFSET_ELVSS_1	1	/* B6h 1st Para: MPS_CON */
#define LDI_OFFSET_ELVSS_2	2	/* B6h 2nd Para: ELVSS_Dim_offset */
#define LDI_OFFSET_ELVSS_3	22	/* B6h 22nd Para: ELVSS Temp Compensation */

#define LDI_OFFSET_OPR_1	1	/* B5h 1st Para: Frame Avg. */
#define LDI_OFFSET_OPR_2	2	/* B5h 2nd Para: Start Point */
#define LDI_OFFSET_OPR_3	4	/* B5h 22nd Para: ACL Percent */

#define LDI_OFFSET_ACL		1
#define LDI_OFFSET_TSET		1

#define LDI_GPARA_DATE		40	/* 0xC8 41st Para */
#define LDI_GPARA_HBM_ELVSS	22	/* 0xB6 23th para */

struct lcd_seq_info {
	unsigned char	*cmd;
	unsigned int	len;
	unsigned int	sleep;
};

static unsigned char SEQ_SLEEP_OUT[] = {
	0x11
};

static unsigned char SEQ_SLEEP_IN[] = {
	0x10
};

static unsigned char SEQ_DISPLAY_ON[] = {
	0x29
};

static unsigned char SEQ_DISPLAY_OFF[] = {
	0x28
};

static unsigned char SEQ_TEST_KEY_ON_F0[] = {
	0xF0,
	0x5A, 0x5A
};

static unsigned char SEQ_TEST_KEY_OFF_F0[] = {
	0xF0,
	0xA5, 0xA5
};

static unsigned char SEQ_TEST_KEY_ON_FC[] = {
	0xFC,
	0x5A, 0x5A
};

static unsigned char SEQ_TEST_KEY_OFF_FC[] = {
	0xFC,
	0xA5, 0xA5
};

static unsigned char SEQ_TE_ON[] = {
	0x35,
	0x00
};

static unsigned char SEQ_PCD_SET_DET_LOW[] = {
	0xCC,
	0x5C
};

static unsigned char SEQ_ERR_FG_SETTING[] = {
	0xED,
	0x44
};

static unsigned char SEQ_AVC_SETTING[] = {
	0xFD,
	0xA1, 0x20, 0x08, 0x04, 0x44, 0x00, 0x0C, 0x07,
	0x00, 0x00, 0xFF, 0x00, 0x0A, 0xAA, 0x0A, 0xAA,
	0x0A, 0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x5A, 0x80, 0x57, 0x65,
	0xA8			/* AVC -6.4V Setting */
};

static unsigned char SEQ_PARTIAL_MODE_ON[] = {
	0x12
};

static unsigned char SEQ_NORMAL_MODE_ON[] = {
	0x13
};

static unsigned char SEQ_PARTIAL_AREA_SETTING[] = {
	0x30,
	0x07, 0x7E, 0x07, 0x7F
};

static unsigned char SEQ_GAMMA_CONDITION_SET[] = {
	0xCA,
	0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x00, 0x00, 0x00, 0x00, 0x00
};

static unsigned char SEQ_AID_SETTING[] = {
	0xB2,
	0x00, 0x14
};

static unsigned char SEQ_ELVSS_SET[] = {
	0xB6,
	0xBC,	/* B6h 1st Para: MPS_CON */
	0x0A,	/* B6h 2nd Para: ELVSS_Dim_offset */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00,
	0x00,	/* B6h 22nd Para: ELVSS Temp Compensation */
	0x00	/* B6h 23rd Para: OTP for B6h 22nd Para of HBM Interpolation */
};

static unsigned char SEQ_GAMMA_UPDATE[] = {
	0xF7,
	0x03
};

static unsigned char SEQ_ACL_OPR_OFF[] = {
	0xB5,
	0x40,	/* 16 Frame Avg. at ACL Off */
	0x7F,	/* Start Point 50% */
	0x14,
	0x14	/* ACL 15% */
};

static unsigned char SEQ_ACL_OPR_08P[] = {
	0xB5,
	0x50,	/* 32 Frame Avg. at ACL On */
	0x99,	/* Start Point 60% */
	0x14,
	0x0A	/* ACL 8% */
};

static unsigned char SEQ_ACL_OPR_15P[] = {
	0xB5,
	0x50,	/* 32 Frame Avg. at ACL On */
	0x7F,	/* Start Point 50% */
	0x14,
	0x14	/* ACL 15% */
};

static unsigned char SEQ_ACL_OFF[] = {
	0x55,
	0x00
};

static unsigned char SEQ_ACL_ON[] = {
	0x55,
	0x02	/* 0x02 : ACL 8% (Default) */
};

static unsigned char SEQ_TSET_SETTING[] = {
	0xB8,
	0x19	/* (ex) 25 degree : 0x19 */
};

static unsigned char SEQ_OSC_FREQ_ADJ[] = {
	0xCE,
	0x29, 0xD0, 0x4B, 0x4C,	/* 0x4B, 0x4C : 60.0Hz */
	0x4B, 0x38, 0x06, 0x03,
	0x00, 0xFF, 0x0A, 0x3F,
	0x3F, 0x3F, 0x3F
};

#ifdef CONFIG_LCD_DOZE_MODE
enum {
	ALPM_OFF,
	ALPM_ON_LOW,	/* ALPM 2 NIT */
	HLPM_ON_LOW,	/* HLPM 2 NIT */
	ALPM_ON_HIGH,	/* ALPM 60 NIT */
	HLPM_ON_HIGH,	/* HLPM 60 NIT */
	ALPM_MODE_MAX
};

static const unsigned char SEQ_SELECT_HLPM_60[] = {
	0xBB,
	0x14, 0x00, 0x07, 0x14	/* 0x14 : HLPM 60nit Mode */
};

static const unsigned char SEQ_SELECT_HLPM_02[] = {
	0xBB,
	0x54, 0x00, 0x07, 0x14	/* 0x54 : HLPM 2nit Mode */
};

static const unsigned char SEQ_SELECT_ALPM_60[] = {
	0xBB,
	0x84, 0x00, 0x07, 0x14	/* 0x84 : ALPM 60nit Mode */
};

static const unsigned char SEQ_SELECT_ALPM_02[] = {
	0xBB,
	0xC4, 0x00, 0x07, 0x14	/* 0xC4 : ALPM 2nit Mode */
};

static const unsigned char SEQ_SELECT_60NIT_ON[] = {
	0x53,
	0x02			/* 0x02 : HLPM/ALPM 60nit On */
};

static const unsigned char SEQ_SELECT_02NIT_ON[] = {
	0x53,
	0x03			/* 0x03 : HLPM/ALPM 2nit On */
};

static const unsigned char SEQ_SRC_LOAD_EN_HLPM[] = {
	0xFD,
	0xA1, 0x20, 0x08, 0x04, 0x44, 0x00,
	0x8C,			/* 0x8C : HLPM */
	0x07, 0x00, 0x00, 0xFF, 0x00, 0x0A, 0xAA, 0x0A,
	0xAA, 0x0A, 0xAA, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x5A, 0x80, 0x57, 0x65, 0xA8,
	0x95, 0xA5, 0x04, 0x55, 0x05, 0x01, 0x01, 0x01
};

static const unsigned char SEQ_SRC_LOAD_EN_ALPM[] = {
	0xFD,
	0xA1, 0x20, 0x08, 0x04, 0x44, 0x00,
	0x0C,			/* 0x0C : ALPM */
	0x07, 0x00, 0x00, 0xFF, 0x00, 0x0A, 0xAA, 0x0A,
	0xAA, 0x0A, 0xAA, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x5A, 0x80, 0x57, 0x65, 0xA8,
	0x95, 0xA5, 0x04, 0x55, 0x05, 0x01, 0x01, 0x01
};

static const unsigned char SEQ_ALPM_OFF[] = {
	0x53,
	0x00
};

static const unsigned char SEQ_SRC_LOAD_EN_NORMAL[] = {
	0xFD,
	0xA1, 0x20, 0x08, 0x04, 0x44, 0x00,
	0x0C
};
#endif

enum {
	ACL_STATUS_OFF,
	ACL_STATUS_ON,
	ACL_STATUS_MAX
};

enum {
	OPR_STATUS_OFF,
	OPR_STATUS_08P,
	OPR_STATUS_15P,
	OPR_STATUS_MAX
};

enum {
	CAPS_OFF,
	CAPS_ON,
	CAPS_MAX
};

enum {
	TEMP_ABOVE_MINUS_00_DEGREE,	/* T > 0 */
	TEMP_ABOVE_MINUS_15_DEGREE,	/* -15 < T <= 0 */
	TEMP_BELOW_MINUS_15_DEGREE,	/* T <= -15 */
	TEMP_MAX
};

static unsigned char *ACL_TABLE[ACL_STATUS_MAX] = {SEQ_ACL_OFF, SEQ_ACL_ON};
static unsigned char *OPR_TABLE[OPR_STATUS_MAX] = {SEQ_ACL_OPR_OFF, SEQ_ACL_OPR_08P, SEQ_ACL_OPR_15P};

static unsigned char elvss_mpscon_offset_data[IBRIGHTNESS_HBM_MAX][3] = {
	[IBRIGHTNESS_002NIT] = {0xB6, 0xAC, 0x0A},
	[IBRIGHTNESS_003NIT] = {0xB6, 0xAC, 0x0A},
	[IBRIGHTNESS_004NIT] = {0xB6, 0xAC, 0x0A},
	[IBRIGHTNESS_005NIT] = {0xB6, 0xAC, 0x0A},
	[IBRIGHTNESS_006NIT] = {0xB6, 0xAC, 0x0B},
	[IBRIGHTNESS_007NIT] = {0xB6, 0xAC, 0x0C},
	[IBRIGHTNESS_008NIT] = {0xB6, 0xAC, 0x0D},
	[IBRIGHTNESS_009NIT] = {0xB6, 0xAC, 0x0E},
	[IBRIGHTNESS_010NIT] = {0xB6, 0xAC, 0x0F},
	[IBRIGHTNESS_011NIT] = {0xB6, 0xAC, 0x10},
	[IBRIGHTNESS_012NIT] = {0xB6, 0xAC, 0x11},
	[IBRIGHTNESS_013NIT] = {0xB6, 0xAC, 0x12},
	[IBRIGHTNESS_014NIT] = {0xB6, 0xAC, 0x13},
	[IBRIGHTNESS_015NIT] = {0xB6, 0xAC, 0x14},
	[IBRIGHTNESS_016NIT] = {0xB6, 0xAC, 0x15},
	[IBRIGHTNESS_017NIT] = {0xB6, 0xAC, 0x16},
	[IBRIGHTNESS_019NIT] = {0xB6, 0xAC, 0x17},
	[IBRIGHTNESS_020NIT] = {0xB6, 0xAC, 0x18},
	[IBRIGHTNESS_021NIT] = {0xB6, 0xAC, 0x18},
	[IBRIGHTNESS_022NIT] = {0xB6, 0xAC, 0x18},
	[IBRIGHTNESS_024NIT] = {0xB6, 0xAC, 0x18},
	[IBRIGHTNESS_025NIT] = {0xB6, 0xAC, 0x18},
	[IBRIGHTNESS_027NIT] = {0xB6, 0xAC, 0x18},
	[IBRIGHTNESS_029NIT] = {0xB6, 0xAC, 0x18},
	[IBRIGHTNESS_030NIT] = {0xB6, 0xAC, 0x18},
	[IBRIGHTNESS_032NIT] = {0xB6, 0xAC, 0x18},
	[IBRIGHTNESS_034NIT] = {0xB6, 0xAC, 0x18},
	[IBRIGHTNESS_037NIT] = {0xB6, 0xAC, 0x17},
	[IBRIGHTNESS_039NIT] = {0xB6, 0xAC, 0x17},
	[IBRIGHTNESS_041NIT] = {0xB6, 0xBC, 0x17},
	[IBRIGHTNESS_044NIT] = {0xB6, 0xBC, 0x17},
	[IBRIGHTNESS_047NIT] = {0xB6, 0xBC, 0x17},
	[IBRIGHTNESS_050NIT] = {0xB6, 0xBC, 0x17},
	[IBRIGHTNESS_053NIT] = {0xB6, 0xBC, 0x17},
	[IBRIGHTNESS_056NIT] = {0xB6, 0xBC, 0x17},
	[IBRIGHTNESS_060NIT] = {0xB6, 0xBC, 0x17},
	[IBRIGHTNESS_064NIT] = {0xB6, 0xBC, 0x17},
	[IBRIGHTNESS_068NIT] = {0xB6, 0xBC, 0x17},
	[IBRIGHTNESS_072NIT] = {0xB6, 0xBC, 0x17},
	[IBRIGHTNESS_077NIT] = {0xB6, 0xBC, 0x16},
	[IBRIGHTNESS_082NIT] = {0xB6, 0xBC, 0x16},
	[IBRIGHTNESS_087NIT] = {0xB6, 0xBC, 0x15},
	[IBRIGHTNESS_093NIT] = {0xB6, 0xBC, 0x15},
	[IBRIGHTNESS_098NIT] = {0xB6, 0xBC, 0x15},
	[IBRIGHTNESS_105NIT] = {0xB6, 0xBC, 0x15},
	[IBRIGHTNESS_111NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_119NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_126NIT] = {0xB6, 0xBC, 0x14},
	[IBRIGHTNESS_134NIT] = {0xB6, 0xBC, 0x13},
	[IBRIGHTNESS_143NIT] = {0xB6, 0xBC, 0x13},
	[IBRIGHTNESS_152NIT] = {0xB6, 0xBC, 0x13},
	[IBRIGHTNESS_162NIT] = {0xB6, 0xBC, 0x12},
	[IBRIGHTNESS_172NIT] = {0xB6, 0xBC, 0x12},
	[IBRIGHTNESS_183NIT] = {0xB6, 0xBC, 0x12},
	[IBRIGHTNESS_195NIT] = {0xB6, 0xBC, 0x12},
	[IBRIGHTNESS_207NIT] = {0xB6, 0xBC, 0x12},
	[IBRIGHTNESS_220NIT] = {0xB6, 0xBC, 0x12},
	[IBRIGHTNESS_234NIT] = {0xB6, 0xBC, 0x12},
	[IBRIGHTNESS_249NIT] = {0xB6, 0xBC, 0x12},
	[IBRIGHTNESS_265NIT] = {0xB6, 0xBC, 0x11},
	[IBRIGHTNESS_282NIT] = {0xB6, 0xBC, 0x10},
	[IBRIGHTNESS_300NIT] = {0xB6, 0xBC, 0x0F},
	[IBRIGHTNESS_316NIT] = {0xB6, 0xBC, 0x0E},
	[IBRIGHTNESS_333NIT] = {0xB6, 0xBC, 0x0E},
	[IBRIGHTNESS_350NIT] = {0xB6, 0xBC, 0x0D},
	[IBRIGHTNESS_357NIT] = {0xB6, 0xBC, 0x0C},
	[IBRIGHTNESS_365NIT] = {0xB6, 0xBC, 0x0C},
	[IBRIGHTNESS_372NIT] = {0xB6, 0xBC, 0x0C},
	[IBRIGHTNESS_380NIT] = {0xB6, 0xBC, 0x0C},
	[IBRIGHTNESS_387NIT] = {0xB6, 0xBC, 0x0B},
	[IBRIGHTNESS_395NIT] = {0xB6, 0xBC, 0x0B},
	[IBRIGHTNESS_403NIT] = {0xB6, 0xBC, 0x0B},
	[IBRIGHTNESS_412NIT] = {0xB6, 0xBC, 0x0A},
	[IBRIGHTNESS_420NIT] = {0xB6, 0xBC, 0x0A},
	[IBRIGHTNESS_465NIT] = {0xB6, 0xBC, 0x11},
	[IBRIGHTNESS_488NIT] = {0xB6, 0xBC, 0x0F},
	[IBRIGHTNESS_510NIT] = {0xB6, 0xBC, 0x0E},
	[IBRIGHTNESS_533NIT] = {0xB6, 0xBC, 0x0C},
	[IBRIGHTNESS_555NIT] = {0xB6, 0xBC, 0x0B},
	[IBRIGHTNESS_578NIT] = {0xB6, 0xBC, 0x0B},
	[IBRIGHTNESS_600NIT] = {0xB6, 0xBC, 0x0A}
};

static unsigned char AOR_TABLE[EXTEND_BRIGHTNESS + 1][AID_CMD_CNT] = {
	{0xB2, 0x70, 0x81},
	{0xB2, 0x70, 0x80},
	{0xB2, 0x70, 0x7F},
	{0xB2, 0x70, 0x7D},
	{0xB2, 0x70, 0x73},
	{0xB2, 0x70, 0x71},
	{0xB2, 0x70, 0x6F},
	{0xB2, 0x70, 0x6D},
	{0xB2, 0x70, 0x63},
	{0xB2, 0x70, 0x61},
	{0xB2, 0x70, 0x5F},
	{0xB2, 0x70, 0x5D},
	{0xB2, 0x70, 0x54},
	{0xB2, 0x70, 0x51},
	{0xB2, 0x70, 0x4F},
	{0xB2, 0x70, 0x4D},
	{0xB2, 0x70, 0x49},
	{0xB2, 0x70, 0x43},
	{0xB2, 0x70, 0x41},
	{0xB2, 0x70, 0x3D},
	{0xB2, 0x70, 0x39},
	{0xB2, 0x70, 0x33},
	{0xB2, 0x70, 0x31},
	{0xB2, 0x70, 0x2D},
	{0xB2, 0x70, 0x2A},
	{0xB2, 0x70, 0x23},
	{0xB2, 0x70, 0x21},
	{0xB2, 0x70, 0x1D},
	{0xB2, 0x70, 0x16},
	{0xB2, 0x70, 0x13},
	{0xB2, 0x70, 0x11},
	{0xB2, 0x70, 0x0D},
	{0xB2, 0x70, 0x04},
	{0xB2, 0x70, 0x03},
	{0xB2, 0x70, 0x01},
	{0xB2, 0x60, 0xFD},
	{0xB2, 0x60, 0xF4},
	{0xB2, 0x60, 0xF1},
	{0xB2, 0x60, 0xEF},
	{0xB2, 0x60, 0xED},
	{0xB2, 0x60, 0xE3},
	{0xB2, 0x60, 0xDF},
	{0xB2, 0x60, 0xDD},
	{0xB2, 0x60, 0xD2},
	{0xB2, 0x60, 0xCF},
	{0xB2, 0x60, 0xCD},
	{0xB2, 0x60, 0xC2},
	{0xB2, 0x60, 0xB9},
	{0xB2, 0x60, 0xB0},
	{0xB2, 0x60, 0xA7},
	{0xB2, 0x60, 0x9E},
	{0xB2, 0x60, 0x93},
	{0xB2, 0x60, 0x88},
	{0xB2, 0x60, 0x76},
	{0xB2, 0x60, 0x64},
	{0xB2, 0x60, 0x5A},
	{0xB2, 0x60, 0x50},
	{0xB2, 0x60, 0x48},
	{0xB2, 0x60, 0x40},
	{0xB2, 0x60, 0x38},
	{0xB2, 0x60, 0x2F},
	{0xB2, 0x60, 0x1E},
	{0xB2, 0x60, 0x0E},
	{0xB2, 0x60, 0x06},
	{0xB2, 0x50, 0xFD},
	{0xB2, 0x50, 0xE8},
	{0xB2, 0x50, 0xD4},
	{0xB2, 0x50, 0xC3},
	{0xB2, 0x50, 0xB3},
	{0xB2, 0x50, 0xAA},
	{0xB2, 0x50, 0xA2},
	{0xB2, 0x50, 0x91},
	{0xB2, 0x50, 0x80},
	{0xB2, 0x50, 0x70},
	{0xB2, 0x50, 0x5F},
	{0xB2, 0x50, 0x46},
	{0xB2, 0x50, 0x2E},
	{0xB2, 0x50, 0x1A},
	{0xB2, 0x50, 0x05},
	{0xB2, 0x40, 0xF4},
	{0xB2, 0x40, 0xE3},
	{0xB2, 0x40, 0xC9},
	{0xB2, 0x40, 0xB0},
	{0xB2, 0x40, 0x97},
	{0xB2, 0x40, 0x7E},
	{0xB2, 0x40, 0x61},
	{0xB2, 0x40, 0x43},
	{0xB2, 0x40, 0x29},
	{0xB2, 0x40, 0x0F},
	{0xB2, 0x30, 0xF2},
	{0xB2, 0x30, 0xD4},
	{0xB2, 0x30, 0xB2},
	{0xB2, 0x30, 0x8F},
	{0xB2, 0x30, 0x68},
	{0xB2, 0x30, 0x42},
	{0xB2, 0x30, 0x1B},
	{0xB2, 0x20, 0xF5},
	{0xB2, 0x20, 0xD1},
	{0xB2, 0x20, 0xAE},
	{0xB2, 0x20, 0xCB},
	{0xB2, 0x20, 0xA2},
	{0xB2, 0x20, 0xC9},
	{0xB2, 0x20, 0xA2},
	{0xB2, 0x20, 0xC6},
	{0xB2, 0x20, 0xA2},
	{0xB2, 0x20, 0xCB},
	{0xB2, 0x20, 0xA2},
	{0xB2, 0x20, 0xC2},
	{0xB2, 0x20, 0xA2},
	{0xB2, 0x20, 0xCC},
	{0xB2, 0x20, 0xA2},
	{0xB2, 0x20, 0xC4},
	{0xB2, 0x20, 0xA2},
	{0xB2, 0x20, 0xCD},
	{0xB2, 0x20, 0xA2},
	{0xB2, 0x20, 0xC5},
	{0xB2, 0x20, 0xA2},
	{0xB2, 0x20, 0xC8},
	{0xB2, 0x20, 0xA2},
	{0xB2, 0x20, 0xCA},
	{0xB2, 0x20, 0xA2},
	{0xB2, 0x20, 0xC8},
	{0xB2, 0x20, 0xA2},
	{0xB2, 0x20, 0xC9},
	{0xB2, 0x20, 0xA2},
	{0xB2, 0x20, 0xC7},
	{0xB2, 0x20, 0xA2},
	{0xB2, 0x20, 0xC4},
	{0xB2, 0x20, 0x9E},
	{0xB2, 0x20, 0x62},
	{0xB2, 0x20, 0x59},
	{0xB2, 0x20, 0x50},
	{0xB2, 0x20, 0x47},
	{0xB2, 0x20, 0x3E},
	{0xB2, 0x20, 0x35},
	{0xB2, 0x20, 0x2C},
	{0xB2, 0x20, 0x1D},
	{0xB2, 0x20, 0x0E},
	{0xB2, 0x10, 0xFF},
	{0xB2, 0x10, 0xF0},
	{0xB2, 0x10, 0xE1},
	{0xB2, 0x10, 0xD2},
	{0xB2, 0x10, 0xC3},
	{0xB2, 0x10, 0xB7},
	{0xB2, 0x10, 0xAB},
	{0xB2, 0x10, 0x9F},
	{0xB2, 0x10, 0x94},
	{0xB2, 0x10, 0x88},
	{0xB2, 0x10, 0x7C},
	{0xB2, 0x10, 0x70},
	{0xB2, 0x10, 0x50},
	{0xB2, 0x10, 0x42},
	{0xB2, 0x10, 0x35},
	{0xB2, 0x10, 0x27},
	{0xB2, 0x10, 0x19},
	{0xB2, 0x10, 0x0B},
	{0xB2, 0x00, 0xFE},
	{0xB2, 0x00, 0xF0},
	{0xB2, 0x10, 0x2B},
	{0xB2, 0x10, 0x1D},
	{0xB2, 0x10, 0x10},
	{0xB2, 0x10, 0x03},
	{0xB2, 0x00, 0xF6},
	{0xB2, 0x00, 0xE9},
	{0xB2, 0x00, 0xDC},
	{0xB2, 0x00, 0xCF},
	{0xB2, 0x10, 0x2C},
	{0xB2, 0x10, 0x21},
	{0xB2, 0x10, 0x15},
	{0xB2, 0x10, 0x09},
	{0xB2, 0x00, 0xFE},
	{0xB2, 0x00, 0xF2},
	{0xB2, 0x00, 0xE6},
	{0xB2, 0x00, 0xDB},
	{0xB2, 0x00, 0xCF},
	{0xB2, 0x10, 0x2C},
	{0xB2, 0x10, 0x20},
	{0xB2, 0x10, 0x15},
	{0xB2, 0x10, 0x09},
	{0xB2, 0x00, 0xFE},
	{0xB2, 0x00, 0xF2},
	{0xB2, 0x00, 0xE6},
	{0xB2, 0x00, 0xDB},
	{0xB2, 0x00, 0xCF},
	{0xB2, 0x10, 0x2D},
	{0xB2, 0x10, 0x22},
	{0xB2, 0x10, 0x18},
	{0xB2, 0x10, 0x0E},
	{0xB2, 0x10, 0x03},
	{0xB2, 0x00, 0xF9},
	{0xB2, 0x00, 0xEE},
	{0xB2, 0x00, 0xE4},
	{0xB2, 0x00, 0xD9},
	{0xB2, 0x00, 0xCF},
	{0xB2, 0x10, 0x1C},
	{0xB2, 0x10, 0x11},
	{0xB2, 0x10, 0x06},
	{0xB2, 0x00, 0xFB},
	{0xB2, 0x00, 0xF0},
	{0xB2, 0x00, 0xE5},
	{0xB2, 0x00, 0xDA},
	{0xB2, 0x00, 0xCF},
	{0xB2, 0x10, 0x1E},
	{0xB2, 0x10, 0x14},
	{0xB2, 0x10, 0x0A},
	{0xB2, 0x10, 0x00},
	{0xB2, 0x00, 0xF6},
	{0xB2, 0x00, 0xED},
	{0xB2, 0x00, 0xE3},
	{0xB2, 0x00, 0xD9},
	{0xB2, 0x00, 0xCF},
	{0xB2, 0x10, 0x1A},
	{0xB2, 0x10, 0x11},
	{0xB2, 0x10, 0x07},
	{0xB2, 0x00, 0xFE},
	{0xB2, 0x00, 0xF4},
	{0xB2, 0x00, 0xEB},
	{0xB2, 0x00, 0xE2},
	{0xB2, 0x00, 0xD8},
	{0xB2, 0x00, 0xCF},
	{0xB2, 0x00, 0xE9},
	{0xB2, 0x00, 0xE0},
	{0xB2, 0x00, 0xD8},
	{0xB2, 0x00, 0xCF},
	{0xB2, 0x00, 0xEC},
	{0xB2, 0x00, 0xE2},
	{0xB2, 0x00, 0xD9},
	{0xB2, 0x00, 0xCF},
	{0xB2, 0x00, 0xB3},
	{0xB2, 0x00, 0xAE},
	{0xB2, 0x00, 0xA8},
	{0xB2, 0x00, 0x9E},
	{0xB2, 0x00, 0x94},
	{0xB2, 0x00, 0x8A},
	{0xB2, 0x00, 0x80},
	{0xB2, 0x00, 0x78},
	{0xB2, 0x00, 0x6F},
	{0xB2, 0x00, 0x66},
	{0xB2, 0x00, 0x5E},
	{0xB2, 0x00, 0x51},
	{0xB2, 0x00, 0x44},
	{0xB2, 0x00, 0x37},
	{0xB2, 0x00, 0x2A},
	{0xB2, 0x00, 0x31},
	{0xB2, 0x00, 0x27},
	{0xB2, 0x00, 0x1E},
	{0xB2, 0x00, 0x14},
	{0xB2, 0x00, 0x34},
	{0xB2, 0x00, 0x29},
	{0xB2, 0x00, 0x1F},
	{0xB2, 0x00, 0x14},
	{0xB2, 0x00, 0x2F},
	{0xB2, 0x00, 0x26},
	{0xB2, 0x00, 0x1D},
	{0xB2, 0x00, 0x14},
	[UI_MAX_BRIGHTNESS ... EXTEND_BRIGHTNESS] = {0xB2, 0x00, 0x14}
};

/* platform brightness <-> acl opr and percent */
static unsigned int brightness_opr_table[ACL_STATUS_MAX][EXTEND_BRIGHTNESS + 1] = {
	{
		[0 ... UI_MAX_BRIGHTNESS - 1]	= OPR_STATUS_15P,
		[UI_MAX_BRIGHTNESS ... 281]		= OPR_STATUS_OFF,	/* 420 */
		[282 ... EXTEND_BRIGHTNESS]		= OPR_STATUS_08P
	}, {
		[0 ... 281]						= OPR_STATUS_15P,
		[282 ... EXTEND_BRIGHTNESS]		= OPR_STATUS_08P
	}
};

/* platform brightness <-> gamma level */
static unsigned int brightness_table[EXTEND_BRIGHTNESS + 1] = {
	[0 ... 0] =		IBRIGHTNESS_002NIT,
	[1 ... 4] =		IBRIGHTNESS_003NIT,
	[5 ... 8] =		IBRIGHTNESS_004NIT,
	[9 ... 12] =		IBRIGHTNESS_005NIT,
	[13 ... 16] =		IBRIGHTNESS_006NIT,
	[17 ... 20] =		IBRIGHTNESS_007NIT,
	[21 ... 24] =		IBRIGHTNESS_008NIT,
	[25 ... 28] =		IBRIGHTNESS_009NIT,
	[29 ... 32] =		IBRIGHTNESS_010NIT,
	[33 ... 36] =		IBRIGHTNESS_011NIT,
	[37 ... 40] =		IBRIGHTNESS_012NIT,
	[41 ... 43] =		IBRIGHTNESS_013NIT,
	[44 ... 46] =		IBRIGHTNESS_014NIT,
	[47 ... 48] =		IBRIGHTNESS_015NIT,
	[49 ... 50] =		IBRIGHTNESS_016NIT,
	[51 ... 52] =		IBRIGHTNESS_017NIT,
	[53 ... 54] =		IBRIGHTNESS_019NIT,
	[55 ... 56] =		IBRIGHTNESS_020NIT,
	[57 ... 58] =		IBRIGHTNESS_021NIT,
	[59 ... 60] =		IBRIGHTNESS_022NIT,
	[61 ... 62] =		IBRIGHTNESS_024NIT,
	[63 ... 64] =		IBRIGHTNESS_025NIT,
	[65 ... 66] =		IBRIGHTNESS_027NIT,
	[67 ... 68] =		IBRIGHTNESS_029NIT,
	[69 ... 70] =		IBRIGHTNESS_030NIT,
	[71 ... 72] =		IBRIGHTNESS_032NIT,
	[73 ... 74] =		IBRIGHTNESS_034NIT,
	[75 ... 76] =		IBRIGHTNESS_037NIT,
	[77 ... 78] =		IBRIGHTNESS_039NIT,
	[79 ... 80] =		IBRIGHTNESS_041NIT,
	[81 ... 82] =		IBRIGHTNESS_044NIT,
	[83 ... 84] =		IBRIGHTNESS_047NIT,
	[85 ... 86] =		IBRIGHTNESS_050NIT,
	[87 ... 88] =		IBRIGHTNESS_053NIT,
	[89 ... 90] =		IBRIGHTNESS_056NIT,
	[91 ... 92] =		IBRIGHTNESS_060NIT,
	[93 ... 94] =		IBRIGHTNESS_064NIT,
	[95 ... 96] =		IBRIGHTNESS_068NIT,
	[97 ... 98] =		IBRIGHTNESS_072NIT,
	[99 ... 100] =		IBRIGHTNESS_077NIT,
	[101 ... 102] =		IBRIGHTNESS_082NIT,
	[103 ... 104] =		IBRIGHTNESS_087NIT,
	[105 ... 106] =		IBRIGHTNESS_093NIT,
	[107 ... 108] =		IBRIGHTNESS_098NIT,
	[109 ... 110] =		IBRIGHTNESS_105NIT,
	[111 ... 112] =		IBRIGHTNESS_111NIT,
	[113 ... 114] =		IBRIGHTNESS_119NIT,
	[115 ... 116] =		IBRIGHTNESS_126NIT,
	[117 ... 118] =		IBRIGHTNESS_134NIT,
	[119 ... 120] =		IBRIGHTNESS_143NIT,
	[121 ... 122] =		IBRIGHTNESS_152NIT,
	[123 ... 124] =		IBRIGHTNESS_162NIT,
	[125 ... 126] =		IBRIGHTNESS_172NIT,
	[127 ... 128] =		IBRIGHTNESS_183NIT,
	[129 ... 135] =		IBRIGHTNESS_195NIT,
	[136 ... 142] =		IBRIGHTNESS_207NIT,
	[143 ... 149] =		IBRIGHTNESS_220NIT,
	[150 ... 157] =		IBRIGHTNESS_234NIT,
	[158 ... 165] =		IBRIGHTNESS_249NIT,
	[166 ... 174] =		IBRIGHTNESS_265NIT,
	[175 ... 183] =		IBRIGHTNESS_282NIT,
	[184 ... 193] =		IBRIGHTNESS_300NIT,
	[194 ... 201] =		IBRIGHTNESS_316NIT,
	[202 ... 210] =		IBRIGHTNESS_333NIT,
	[211 ... 219] =		IBRIGHTNESS_350NIT,
	[220 ... 223] =		IBRIGHTNESS_357NIT,
	[224 ... 227] =		IBRIGHTNESS_365NIT,
	[228 ... 230] =		IBRIGHTNESS_372NIT,
	[231 ... 234] =		IBRIGHTNESS_380NIT,
	[235 ... 238] =		IBRIGHTNESS_387NIT,
	[239 ... 242] =		IBRIGHTNESS_395NIT,
	[243 ... 246] =		IBRIGHTNESS_403NIT,
	[247 ... 250] =		IBRIGHTNESS_412NIT,
	[251 ... 281] =		IBRIGHTNESS_420NIT,
	[282 ... 295] =		IBRIGHTNESS_465NIT,
	[296 ... 309] =		IBRIGHTNESS_488NIT,
	[310 ... 323] =		IBRIGHTNESS_510NIT,
	[324 ... 336] =		IBRIGHTNESS_533NIT,
	[337 ... 350] =		IBRIGHTNESS_555NIT,
	[351 ... 364] =		IBRIGHTNESS_578NIT,
	[EXTEND_BRIGHTNESS ... EXTEND_BRIGHTNESS] =		IBRIGHTNESS_600NIT
};

#endif /* __S6E3FA3_A7Y17_PARAM_H__ */
