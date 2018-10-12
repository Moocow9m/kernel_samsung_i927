#ifndef CMC623_REG_HEADER
#define CMC623_REG_HEADER

#if defined(__cplusplus)
extern "C"
{
#endif

#define n1_ld9040 0
#define CMC623_SERVICE_EXTEND

/** CMC623 registers **/


/* SFR Bank selection */
#define CMC623_REG_SELBANK   0x00  // Bank0

/* A stage configuration */
#define CMC623_REG_DNRHDTROVE 0x01
#define CMC623_REG_DITHEROFF 0x06
#define CMC623_REG_CLKCONT 0x10
#define CMC623_REG_CLKGATINGOFF 0x0a
#define CMC623_REG_INPUTIFCON 0x24
#define CMC623_REG_CLKMONCONT   0x11  // Clock Monitor Ctrl Register
#define CMC623_REG_HDRTCEOFF 0x3a
#define CMC623_REG_I2C 0x0d
#define CMC623_REG_BSTAGE 0x0e
#define CMC623_REG_CABCCTRL 0x7c
#define CMC623_REG_PWMCTRL 0xb4
#define CMC623_REG_OVEMAX 0x54

/* A stage image size */
#define CMC623_REG_1280 0x22
#define CMC623_REG_800 0x23

/* B stage image size */
#define CMC623_REG_SCALERINPH 0x09
#define CMC623_REG_SCALERINPV 0x0a
#define CMC623_REG_SCALEROUTH 0x0b
#define CMC623_REG_SCALEROUTV 0x0c

/* EDRAM configuration */
#define CMC623_REG_EDRBFOUT40 0x01
#define CMC623_REG_EDRAUTOREF 0x06
#define CMC623_REG_EDRACPARAMTIM 0x07

/* Vsync Calibartion */
#define CMC623_REG_CALVAL10 0x65

/* tcon output polarity */
#define CMC623_REG_TCONOUTPOL 0x68

/* tcon RGB configuration */
#define CMC623_REG_TCONRGB1 0x6c
#define CMC623_REG_TCONRGB2 0x6d
#define CMC623_REG_TCONRGB3 0x6e

/* Reg update */
#define CMC623_REG_REGMASK 0x28
#define CMC623_REG_SWRESET 0x09
#define CMC623_REG_RGBIFEN 0x26

struct Cmc623RegisterSet{
    unsigned int RegAddr;
	unsigned int Data;
};

enum Lcd_CMC623_UI_mode{
	CMC623_UI_MODE,
	CMC623_VIDEO_MODE,
	CMC623_VIDEO_WARM_MODE,
	CMC623_VIDEO_COLD_MODE,
	CMC623_CAMERA_MODE,
	CMC623_NAVI,
	CMC623_GALLERY_MODE,
	CMC623_VT_MODE,
};

enum Lcd_CMC623_USERSELECT_mode{
	CMC623_USERSELECT_DYNAMIC_MODE,
	CMC623_USERSELECT_STANDARD_MODE,
	CMC623_USERSELECT_MOVIE_MODE,
};


/* If pclk < 48 then refer the following settings */

static const struct Cmc623RegisterSet cmc623_init1[] = {
    /* select SFR Bank0 */
    {CMC623_REG_SELBANK, 0x0000},

    /* A stage configuration */
    {CMC623_REG_DNRHDTROVE, 0x0030},
    {CMC623_REG_DITHEROFF, 0x0000},
    {CMC623_REG_CLKCONT, 0x0012},
    {0x0f, 0x0078},
    {CMC623_REG_CLKGATINGOFF, 0x0000},
    {CMC623_REG_INPUTIFCON, 0x0001},
    {CMC623_REG_HDRTCEOFF, 0x0000},  /*0x001d -> 0x0000*/
    {CMC623_REG_I2C, 0x180a},
    {CMC623_REG_BSTAGE, 0x0a0b},
    {CMC623_REG_CABCCTRL, 0x0002},
    {CMC623_REG_PWMCTRL, 0x5000},

    {CMC623_REG_1280, 0x0500},
    {CMC623_REG_800, 0x0320},

    /* select SFR Bank1 */
    {CMC623_REG_SELBANK, 0x0001},

    /* B stage image size */
    {CMC623_REG_SCALERINPH, 0x0500},
    {CMC623_REG_SCALERINPV, 0x0320},
    {CMC623_REG_SCALEROUTH, 0x0500},
    {CMC623_REG_SCALEROUTV, 0x0320},

    /* EDRAM configuration */
    {CMC623_REG_EDRBFOUT40, 0x0280},
    {CMC623_REG_EDRAUTOREF, 0x0059},
    {CMC623_REG_EDRACPARAMTIM, 0x2225},

    /* Vsync Calibartion */
	/*{CMC623_REG_CALVAL10, 0x000a},*/

    /* tcon output polarity */
    {CMC623_REG_TCONOUTPOL, 0x0000},

    /* tcon RGB configuration */
	{CMC623_REG_TCONRGB1, 0x0204},  /* vsw=2, hsw=4*/
	{CMC623_REG_TCONRGB2, 0x0405},  /* vbp=4, vfp=5*/
	{CMC623_REG_TCONRGB3, 0x1617},  /* hbp=22, hfp=23*/

	/* Reg update */
	{CMC623_REG_SELBANK, 0x0000},  /* select BANK0*/
	{CMC623_REG_REGMASK, 0x0000},
	{CMC623_REG_SWRESET, 0x0000},  /* SW reset*/
	{CMC623_REG_SWRESET, 0xffff},  /* !SW reset,
					(!note:sleep required after this)*/
	{CMC623_REG_RGBIFEN, 0x0001},  /* enable RGB IF*/
};

static const struct Cmc623RegisterSet cmc623_init2[] = {
	{0x00, 0x0000}, // BANK 0
	{0x01, 0x0020}, // Algorithm selection
	//{0x16, 0x155d},//drive strength 8mA
	{0xb4, 0xC064}, // PWM ratio - 0xC064
	{0xb3, 0xffff}, // up/down step
	//{0x11, 0x0082}, // Monitor Clock{for chip active check}
	//{0x10, 0x001A}, // PCLK Polarity Sel
	{0x24, 0x0001}, // Polarity Sel
	{0x0b, 0x0184}, // Clock Gating
	{0x0f, 0x0010}, // PWM clock frequency
	{0x0d, 0x1a11}, // A-Stage clk
	{0x0e, 0x1112}, // B-stage clk
	//{0x22, 0x01E0}, // H_Size
	//{0x23, 0x0320}, // V_Size
	{0x2c, 0x0fff}, // DNR bypass
	{0x2d, 0x1900}, // DNR bypass
	{0x2e, 0x0000}, // DNR bypass
	{0x2f, 0x00ff}, // DNR bypass
	//{0x3a, 0x0000}, // HDTR on DE
	{0x00, 0x0001}, // BANK 1
	//{0x09, 0x01E0}, // H_Size
	//{0x0a, 0x0320}, // V_Size
	//{0x0b, 0x01E0}, // H_Size
	//{0x0c, 0x0320}, // V_Size
	//{0x01, 0x0500}, // BF_Line
	{0x06, 0x0037}, // Refresh time
	{0x07, 0x1113}, // eDRAM
	{0x68, 0x0080}, // TCON Polarity
	{0x6c, 0x020A}, // VLW,HLW 2  10
	{0x6d, 0x0403}, // VBP,VFP 4  3
	{0x6e, 0x140A}, // HBP,HFP 20 10
	{0x00, 0x0000}, // BANK0
	{0x28, 0x0000}, // Reg. mask
	{0x09, 0x0000}, // SW rst
	{0x09, 0xffff}, // sw rst
	//delay 5ms
	{0x26, 0x0001}, // RGB IF enable
};

#if n1_ld9040
static const struct Cmc623RegisterSet cmc623_init_amoled[] =
{
	{0x00, 0x0000}, // BANK 0
	//{0x01, 0x0020}, // Algorithm selection
	//{0xb4, 0xC064}, // PWM ratio - 0xC064
	//{0xb3, 0xffff}, // up/down step
	//{0x11, 0x0082}, // Monitor Clock{for chip active check}
	//{0x10, 0x001A}, // PCLK Polarity Sel
	 {0x24, 0x0000}, // Polarity Sel //modified by Cho
	{0x0b, 0x0184}, // Clock Gating
	{0x0f, 0x0010}, // PWM clock frequency
	{0x0d, 0x1a11}, // A-Stage clk
	{0x0e, 0x1112}, // B-stage clk
	 //{0x22, 0x01E0}, // H_Size
	 //{0x23, 0x0320}, // V_Size
	{0x2c, 0x0fff}, // DNR bypass
	{0x2d, 0x1900}, // DNR bypass
	{0x2e, 0x0000}, // DNR bypass
	{0x2f, 0x00ff}, // DNR bypass
	{0x3a, 0x0000}, // HDTR on DE
	{0x00, 0x0001}, // BANK 1
	 //{0x09, 0x01E0}, // H_Size
	 //{0x0a, 0x0320}, // V_Size
	 //{0x0b, 0x01E0}, // H_Size
	 //{0x0c, 0x0320}, // V_Size
	{0x01, 0x0500}, // BF_Line
	{0x06, 0x0037}, // Refresh time
	{0x07, 0x1113}, // eDRAM
	 {0x68, 0x00C0}, // TCON Polarity  //modified by Cho 0x0040
	 {0x6c, 0x0202}, // VLW,HLW 2  2   //modified by Cho
	 {0x6d, 0x040a}, // VBP,VFP 4  10  //modified by Cho
	 {0x6e, 0x0e10}, // HBP,HFP 14 16  //modified by Cho
	{0x00, 0x0000}, // BANK0
	{0x28, 0x0000}, // Reg. mask
	{0x09, 0x0000}, // SW rst
	{0x09, 0xffff}, // sw rst
	//delay 5ms
	{0x26, 0x0001}, // RGB IF enable
};
#endif


static const struct Cmc623RegisterSet cmc623_cabcon[] = {
	/*** start of tuning **/
	{0x0000, 0x0000},	/*BANK 0  */
	{0x0001, 0x0070},	/*SCR LABC CABC*/
	{0x002c, 0x0fff},	/*DNR bypass 0x003C*/
	{0x002e, 0x0000},	/*DNR bypass 0x1010*/
	{0x003A, 0x000D},	/*HDTR DE CS*/
	{0x003B, 0x03ff},	/*DE SHARPNESS*/
	{0x003C, 0x0000},	/*NOISE LEVEL*/
	{0x003F, 0x0080},	/*CS GAIN*/
	{0x0042, 0x0000},	/*DE TH (MAX DIFF)*/
	{0x006E, 0x0000},	/*CABC Fgain*/
    {0x006F,0x0000},
    {0x0070,0x0000},
    {0x0071,0x0000},
	{0x0072, 0x2110},	/*CABC Dgain*/
    {0x0073,0x2B14},
    {0x0074,0x1e2D},
    {0x0075,0x3F00},
	{0x0076, 0x3c50},	/*PowerLUT 3C50*/
	{0x0077, 0x2D64},	/*PowerLUT 2D64*/
	{0x0078, 0x3c32},	/*PowerLUT 3C32*/
	{0x0079, 0x1E10},	/*PowerLUT 1E00*/
	{0x007a, 0x3200},	/*PowerLUT 3200*/
	{0x007C, 0x0002},	/*Dynamic LCD*/
	{0x00b4, 0x5640},	/*CABC PWM*/
	{0x00c8, 0x0000},	/*0x0000, kb	0x0000,	SCR*/
	{0x00c9, 0x0000},	/*0x0000, gc	0x1000,*/
	{0x00ca, 0xffff},	/*0xF0FF, rm	0xffff,*/
	{0x00cb, 0xffF8},	/*0xffff, yw	0xffff,*/
	{0x00cc, 0x0000},	/*0x0000, kb	0x0000,*/
	{0x00cd, 0xffff},	/*0xffff, gc	0xffff,*/
	{0x00ce, 0x0000},	/*0x1000, rm	0x1000,*/
	{0x00cf, 0xF8E8},	/*0xffff, yw	0xf0f0,*/
	{0x00d0, 0x00ff},	/*0x00ff, kb	0x00ff,*/
	{0x00d1, 0x00ff},	/*0x00ff, gc	0x00ff,*/
	{0x00d2, 0x00ff},	/*0x08ff, rm	0x00ff,*/
	{0x00d3, 0x00ff},	/*0x00ff, yw*/
	{0x0000, 0x0001},	/*BANK 1*/
	{0x0020, 0x0000},	/*GAMMA 10*/
    {0x0021,0x2000},
    {0x0022,0x2000},
    {0x0023,0x2000},
    {0x0024,0x2000},
    {0x0025,0x2000},
    {0x0026,0x2000},
    {0x0027,0x2000},
    {0x0028,0x2000},
    {0x0029,0x1808},
    {0x002A,0x1808},
    {0x002B,0x1808},
    {0x002C,0x1808},
    {0x002D,0x1808},
    {0x002E,0x1808},
    {0x002F,0x1808},
    {0x0030,0x1808},
    {0x0031,0x1808},
    {0x0032,0xa210},
    {0x0033,0xa210},
    {0x0034,0xa210},
    {0x0035,0xa210},
    {0x0036,0xa210},
    {0x0037,0xa210},
    {0x0038,0xFF00},
    {0x0020,0x0001},
	{0x0000, 0x0000},	/*BANK 0*/
	{0x0028, 0x0000},	/*Register Mask*/
	/*** end of tuning **/
};

static const struct Cmc623RegisterSet cmc623_cabcon2[] = {
/*** start of tuning **/
	{0x0000, 0x0000},	/*BANK 0*/
	{0x0001, 0x0030},	/*(SCR 7) LABC CABC*/
	{0x002c, 0x003c},	/*DNR bypass,dir_th 0x003c*/
	{0x002d, 0x0a08},	/*DNR dir_num,decont7 0x0a08*/
	{0x002e, 0x1010},	/*DNR decont5,mask_th 0x1010*/
	{0x002F, 0x0400},	/*DNR block_th 0x0400*/
	{0x003A, 0x0009},	/*HDTR (DE D) CS*/
	{0x003B, 0x03ff},	/*DE SHARPNESS*/
	{0x003C, 0x0000},	/*NOISE LEVEL*/
	{0x003F, 0x0080},	/*CS GAIN*/
	{0x0042, 0x0000},	/*DE TH (MAX DIFF)*/
	{0x006E, 0x0000},	/*CABC Fgain*/
	{0x006F,0x0000},
	{0x0070,0x0000},
	{0x0071,0x0000},
	{0x0072, 0x2110},	/*CABC Dgain*/
	{0x0073,0x2B14},
	{0x0074,0x1e2D},
	{0x0075,0x3F00},
	{0x0076, 0x3c50},	/*PowerLUT 3C50*/
	{0x0077, 0x2D64},	/*PowerLUT 2D64*/
	{0x0078, 0x3c32},	/*PowerLUT 3C32*/
	{0x0079, 0x1E10},	/*PowerLUT 1E00*/
	{0x007a, 0x3200},	/*PowerLUT 3200*/
	{0x007C, 0x0002},	/*Dynamic LCD*/
	{0x00b4, 0x5640},	/*CABC PWM*/
	{0x00c8, 0x0000},	/*0x0000, kb	0x0000,	SCR*/
	{0x00c9, 0x0000},	/*0x0000, gc	0x1000,*/
	{0x00ca, 0xffff},	/*0xF0FF, rm	0xffff,*/
	{0x00cb, 0xffF8},	/*0xffff, yw	0xffff,*/
	{0x00cc, 0x0000},	/*0x0000, kb	0x0000,*/
	{0x00cd, 0xffff},	/*0xffff, gc	0xffff,*/
	{0x00ce, 0x0000},	/*0x1000, rm	0x1000,*/
	{0x00cf, 0xF8E8},	/*0xffff, yw	0xf0f0,*/
	{0x00d0, 0x00ff},	/*0x00ff, kb	0x00ff,*/
	{0x00d1, 0x00ff},	/*0x00ff, gc	0x00ff,*/
	{0x00d2, 0x00ff},	/*0x08ff, rm	0x00ff,*/
	{0x00d3, 0x00ff},	/*0x00ff, yw*/
	{0x0000, 0x0001},	/*BANK 1*/
	{0x0020, 0x0000},	/*GAMMA bypass*/
	{0x0021,0x2000},
	{0x0022,0x2000},
	{0x0023,0x2000},
	{0x0024,0x2000},
	{0x0025,0x2000},
	{0x0026,0x2000},
	{0x0027,0x2000},
	{0x0028,0x2000},
	{0x0029,0x2000},
	{0x002A,0x2000},
	{0x002B,0x2000},
	{0x002C,0x2000},
	{0x002D,0x2000},
	{0x002E,0x2000},
	{0x002F,0x2000},
	{0x0030,0x2000},
	{0x0031,0x2000},
	{0x0032,0x2000},
	{0x0033,0x2000},
	{0x0034,0x2000},
	{0x0035,0x2000},
	{0x0036,0x2000},
	{0x0037,0x2000},
	{0x0038,0xFF00},
	{0x0020,0x1001},
	{0x0000, 0x0000},	/*BANK 0*/
	{0x0028, 0x0000},	/*Register Mask*/
/*** end of tuning **/
};

static const struct Cmc623RegisterSet cmc623_cabcon2_gamma22[] = {

/*** start of tuning **/
	{0x0000, 0x0000},	/*BANK 0*/
	{0x0001, 0x0020},	/*LABC*/
	{0x002c, 0x0fff},	/*DNR bypass 0x003C*/
	{0x002d, 0x1900},	/*DNR bypass 0x0a08*/
	{0x002e, 0x0000},	/*DNR bypass 0x1010*/
	{0x002f, 0x00ff},	/*DNR bypass 0x0400*/
	{0x003A, 0x0100},	/*HDTR DE CS*/
	{0x003B, 0x03ff},	/*DE SHARPNESS*/
	{0x003C, 0x0000},	/*NOISE LEVEL*/
	{0x003F, 0x0040},	/*CS GAIN*/
	{0x0042, 0x0000},	/*DE TH (MAX DIFF)*/
	{0x00b4, 0x4640},	/*Count PWM*/
	{0x0000, 0x0001},	/*BANK 1*/
	{0x0020, 0x0000},	/*GAMMA pls2*/
	{0x0021,0x1000},
	{0x0022,0x1000},
	{0x0023,0x1000},
	{0x0024,0x1000},
	{0x0025,0x1000},
	{0x0026,0x1000},
	{0x0027,0x1000},
	{0x0028,0x1000},
	{0x0029,0x1000},
	{0x002A,0x1000},
	{0x002B,0xa318},
	{0x002C,0xa318},
	{0x002D,0xa318},
	{0x002E,0xa318},
	{0x002F,0xa318},
	{0x0030,0xa318},
	{0x0031,0xa318},
	{0x0032,0xa318},
	{0x0033,0xa318},
	{0x0034,0xa318},
	{0x0035,0xa318},
	{0x0036,0xa318},
	{0x0037,0xa318},
	{0x0038,0xFF00},
	{0x0020,0x0001},
	{0x0000, 0x0000},	/*BANK 0*/
	{0x0028, 0x0000},	/*Register Mask*/
/*** end of tuning **/
};

static const struct Cmc623RegisterSet cmc623_cabcon3[] = {
/*** start of tuning **/
	{0x0000, 0x0000},	/*BANK 0*/
	{0x0001, 0x0070},	/*SCR LABC CABC*/
	{0x002c, 0x0fff},	/*DNR bypass 0x003C*/
	{0x002d, 0x1900},	/*DNR bypass 0x0a08*/
	{0x002e, 0x0000},	/*DNR bypass 0x1010*/
	{0x002f, 0x00ff},	/*DNR bypass 0x0400*/
	{0x003A, 0x000D},	/*HDTR DE CS*/
	{0x003B, 0x03ff},	/*DE SHARPNESS*/
	{0x003C, 0x0000},	/*NOISE LEVEL*/
	{0x003F, 0x0110},	/*CS GAIN*/
	{0x0042, 0x0000},	/*DE TH (MAX DIFF)*/
	{0x0072, 0x0000},	/*CABC Dgain*/
	{0x0073,0x0000},
	{0x0074,0x0000},
	{0x0075,0x0000},
	/*	{0x0076, 0x484d},*/	/*PowerLUT 3C50*/
	/*	{0x0077, 0x4452},*/	/*PowerLUT 2D64*/
	/*	{0x0078, 0x4845},*/	/*PowerLUT 3C32*/
	/*	{0x0079, 0x403d},*/	/*PowerLUT 1E00*/
	/*	{0x007a, 0x4500},*/	/*PowerLUT 3200*/
	{0x007C, 0x0002},	/*Dynamic LCD*/
	/*	{0x00b4, 0x5640},	/*CABC PWM*/
	{0x00c8, 0x0030},	/*kb R	SCR*/
	{0x00c9, 0x0000},	/*gc R*/
	{0x00ca, 0xffff},	/*rm R*/
	{0x00cb, 0xffff},	/*yw R*/
	{0x00cc, 0x0000},	/*kb G*/
	{0x00cd, 0xffff},	/*gc G*/
	{0x00ce, 0x0000},	/*rm G*/
	{0x00cf, 0xfff4},	/*yw G*/
	{0x00d0, 0x00ff},	/*kb B*/
	{0x00d1, 0x00ff},	/*gc B*/
	{0x00d2, 0x00ff},	/*rm B*/
	{0x00d3, 0x00ff},	/*yw B*/
	{0x0000, 0x0001},	/*BANK 1*/
	{0x0020, 0x0000},	/*GAMMA plsc_0*/
	{0x0021,0x1400},
	{0x0022,0x1400},
	{0x0023,0x1400},
	{0x0024,0x1400},
	{0x0025,0x1400},
	{0x0026,0x1400},
	{0x0027,0x1400},
	{0x0028,0x1400},
	{0x0029,0x1400},
	{0x002A,0x1400},
	{0x002B,0xac1e},
	{0x002C,0xac1e},
	{0x002D,0xac1e},
	{0x002E,0xac1e},
	{0x002F,0xac1e},
	{0x0030,0xac1e},
	{0x0031,0xac1e},
	{0x0032,0xac1e},
	{0x0033,0xac1e},
	{0x0034,0x2401},
	{0x0035,0x2016},
	{0x0036,0x1848},
	{0x0037,0x0ca0},
	{0x0038,0xFF00},
	{0x0020,0x0001},
	{0x0000, 0x0000},	/*BANK 0*/
	{0x0028, 0x0000},	/*Register Mask*/
/*** end of tuning **/
};

static const struct Cmc623RegisterSet cmc623_cabcon4[] = {
	{0x0000, 0x0000},	/*BANK 0*/
	{0x0001, 0x0070},	/*LABC CABC*/
	{0x002c, 0x0fff},	/*DNR bypass*/
	{0x002e, 0x0000},	/*DNR bypass*/
	{0x003a, 0x0009},	/*HDTR DE CS*/
	{0x003B, 0x0000},	/*DE SHARPNESS*/
	{0x003C, 0x0000},	/*NOISE LEVEL*/
	{0x003F, 0x0078},	/*CS GAIN*/
	{0x0042, 0x0000},	/*DE TH (MAX DIFF)*/
	{0x0072, 0x0000},	/*CABC Dgain*/
	{0x0073, 0x0000},
	{0x0074, 0x0000},
	{0x0075, 0x0000},
	/*{0x0076, 0x464b},*/	/*PowerLUT 3C50*/
	/*{0x0077, 0x4250},*/	/*PowerLUT 2D64*/
	/*{0x0078, 0x4643},*/	/*PowerLUT 3C32*/
	/*{0x0079, 0x3e3b},*/	/*PowerLUT 1E00*/
	/*{0x007a, 0x4300},*/	/*PowerLUT 3200*/
	/*{0x00B4, 0x5640},*/	/*CABC PWM set*/
	{0x00c8, 0x0000},	/*kb R	SCR*/
	{0x00c9, 0x0000},	/*gc R*/
	{0x00ca, 0xffff},	/*rm R*/
	{0x00cb, 0xffff},	/*yw R*/
	{0x00cc, 0x0000},	/*kb G*/
	{0x00cd, 0xffff},	/*gc G*/
	{0x00ce, 0x0000},	/*rm G*/
	{0x00cf, 0xfffb},	/*yw G*/
	{0x00d0, 0x00ff},	/*kb B*/
	{0x00d1, 0x00ff},	/*gc B*/
	{0x00d2, 0x00ff},	/*rm B*/
	{0x00d3, 0x00ff},	/*yw B*/
	{0x0000, 0x0001},	/*BANK 1*/
	{0x0020, 0x0000},	/*GAMMA ez p3c0 */
	{0x0021, 0x1a00},
	{0x0022, 0x1a00},
	{0x0023, 0x1a00},
	{0x0024, 0x1a00},
	{0x0025, 0x1a00},
	{0x0026, 0x1a00},
	{0x0027, 0x1a00},
	{0x0028, 0x1a00},
	{0x0029, 0x1a00},
	{0x002A, 0x1a00},
	{0x002B, 0x1a00},
	{0x002C, 0x1a00},
	{0x002D, 0x1a00},
	{0x002E, 0x1a00},
	{0x002F, 0x1a00},
	{0x0030, 0x1a00},
	{0x0031, 0xa414},
	{0x0032, 0xa414},
	{0x0033, 0xa414},
	{0x0034, 0xa414},
	{0x0035, 0xa414},
	{0x0036, 0xa414},
	{0x0037, 0x155a},
	{0x0038, 0xFF00},
	{0x0020, 0x0001},
	{0x0000, 0x0000},	/*BANK 0*/
	{0x0028, 0x0000},
};

static const struct Cmc623RegisterSet cmc623_init_cabcoff[] = {
/*** start of tuning **/
	{0x0000, 0x0000},	/*BANK 0*/
	{0x0001, 0x0060},	/*SCR LABC*/
	{0x002c, 0x0fff},	/*DNR bypass 0x003C*/
	{0x002e, 0x0000},	/*DNR bypass 0x1010*/
	{0x003A, 0x000D},	/*HDTR DE CS*/
	{0x003B, 0x03ff},	/*DE SHARPNESS*/
	{0x003C, 0x0000},	/*NOISE LEVEL*/
	{0x003F, 0x00C0},	/*CS GAIN*/
	{0x0042, 0x0000},	/*DE TH (MAX DIFF)*/
	{0x006E, 0x0000},	/*CABC Fgain*/
    {0x006F,0x0000},
    {0x0070,0x0000},
    {0x0071,0x0000},
	{0x0072, 0x2110},	/*CABC Dgain*/
    {0x0073,0x2B14},
    {0x0074,0x1e2D},
    {0x0075,0x3F00},
	{0x0076, 0x3c50},	/*PowerLUT 3C50*/
	{0x0077, 0x2D64},	/*PowerLUT 2D64*/
	{0x0078, 0x3c32},	/*PowerLUT 3C32*/
	{0x0079, 0x1E10},	/*PowerLUT 1E00*/
	{0x007a, 0x3200},	/*PowerLUT 3200*/
	{0x007C, 0x0002},	/*Dynamic LCD*/
	/*    {0x00b4, 0x4640},*/	/*Count PWM*/
	{0x00c8, 0x0000},	/*0x0000, kb	0x0000,	SCR*/
	{0x00c9, 0x0000},	/*0x0000, gc	0x1000,*/
	{0x00ca, 0xffff},	/*0xF0FF, rm	0xffff,*/
	{0x00cb, 0xffF8},	/*0xffff, yw	0xffff,*/
	{0x00cc, 0x0000},	/*0x0000, kb	0x0000,*/
	{0x00cd, 0xffff},	/*0xffff, gc	0xffff,*/
	{0x00ce, 0x0000},	/*0x1000, rm	0x1000,*/
	{0x00cf, 0xF8E8},	/*0xffff, yw	0xf0f0,*/
	{0x00d0, 0x00ff},	/*0x00ff, kb	0x00ff,*/
	{0x00d1, 0x00ff},	/*0x00ff, gc	0x00ff,*/
	{0x00d2, 0x00ff},	/*0x08ff, rm	0x00ff,*/
	{0x00d3, 0x00ff},	/*0x00ff, yw*/
	{0x0000, 0x0001},	/*BANK 1*/
	{0x0020, 0x0000},	/*GAMMA 8*/
    {0x0021,0x1a00},
    {0x0022,0x1a00},
    {0x0023,0x1a00},
    {0x0024,0x1a00},
    {0x0025,0x1a00},
    {0x0026,0x1a00},
    {0x0027,0x1a00},
    {0x0028,0x1a00},
    {0x0029,0x1a00},
    {0x002A,0x1a00},
    {0x002B,0x1a00},
    {0x002C,0x1a00},
    {0x002D,0x1a00},
    {0x002E,0x1a00},
    {0x002F,0x1a00},
    {0x0030,0x1a00},
    {0x0031,0x1a00},
    {0x0032,0x1a00},
    {0x0033,0xa318},
    {0x0034,0xa318},
    {0x0035,0xa318},
    {0x0036,0xa318},
    {0x0037,0xa318},
    {0x0038,0xFF00},
    {0x0020,0x0001},
	{0x0000, 0x0000},	/*BANK 0*/
	{0x0028, 0x0000},	/*Register Mask*/
/*** end of tuning **/
};

static const struct Cmc623RegisterSet cmc623_init_cabcoff2[] = {
/*** start of tuning **/
	{0x0000, 0x0000},	/*BANK 0*/
	{0x0001, 0x0020},	/*(SCR 6) LABC*/
	{0x002c, 0x003c},	/*DNR bypass,dir_th 0x003c*/
	{0x002d, 0x0a08},	/*DNR dir_num,decont7 0x0a08*/
	{0x002e, 0x1010},	/*DNR decont5,mask_th 0x1010*/
	{0x002F, 0x0400},	/*DNR block_th 0x0400*/
	{0x003A, 0x0009},	/*HDTR (DE D) CS*/
	{0x003B, 0x03ff},	/*DE SHARPNESS*/
	{0x003C, 0x0000},	/*NOISE LEVEL*/
	{0x003F, 0x00C0},	/*CS GAIN*/
	{0x0042, 0x0000},	/*DE TH (MAX DIFF)*/
	{0x006E, 0x0000},	/*CABC Fgain*/
	{0x006F,0x0000},
	{0x0070,0x0000},
	{0x0071,0x0000},
	{0x0072, 0x2110},	/*CABC Dgain*/
	{0x0073,0x2B14},
	{0x0074,0x1e2D},
	{0x0075,0x3F00},
	{0x0076, 0x3c50},	/*PowerLUT 3C50*/
	{0x0077, 0x2D64},	/*PowerLUT 2D64*/
	{0x0078, 0x3c32},	/*PowerLUT 3C32*/
	{0x0079, 0x1E10},	/*PowerLUT 1E00*/
	{0x007a, 0x3200},	/*PowerLUT 3200*/
	{0x007C, 0x0002},	/*Dynamic LCD*/
/*	{0x00b4, 0x4640},*/	/*Count PWM*/
	{0x00c8, 0x0000},	/*0x0000, kb	0x0000, SCR*/
	{0x00c9, 0x0000},	/*0x0000, gc	0x1000,*/
	{0x00ca, 0xffff},	/*0xF0FF, rm	0xffff,*/
	{0x00cb, 0xffF8},	/*0xffff, yw	0xffff,*/
	{0x00cc, 0x0000},	/*0x0000, kb	0x0000,*/
	{0x00cd, 0xffff},	/*0xffff, gc	0xffff,*/
	{0x00ce, 0x0000},	/*0x1000, rm	0x1000,*/
	{0x00cf, 0xF8E8},	/*0xffff, yw	0xf0f0,*/
	{0x00d0, 0x00ff},	/*0x00ff, kb	0x00ff,*/
	{0x00d1, 0x00ff},	/*0x00ff, gc	0x00ff,*/
	{0x00d2, 0x00ff},	/*0x08ff, rm	0x00ff,*/
	{0x00d3, 0x00ff},	/*0x00ff, yw*/
	{0x0000, 0x0001},	/*BANK 1*/
	{0x0020, 0x0000},	/*GAMMA bypass*/
	{0x0021,0x2000},
	{0x0022,0x2000},
	{0x0023,0x2000},
	{0x0024,0x2000},
	{0x0025,0x2000},
	{0x0026,0x2000},
	{0x0027,0x2000},
	{0x0028,0x2000},
	{0x0029,0x2000},
	{0x002A,0x2000},
	{0x002B,0x2000},
	{0x002C,0x2000},
	{0x002D,0x2000},
	{0x002E,0x2000},
	{0x002F,0x2000},
	{0x0030,0x2000},
	{0x0031,0x2000},
	{0x0032,0x2000},
	{0x0033,0x2000},
	{0x0034,0x2000},
	{0x0035,0x2000},
	{0x0036,0x2000},
	{0x0037,0x2000},
	{0x0038,0xFF00},
	{0x0020,0x1001},
	{0x0000, 0x0000},	/*BANK 0*/
	{0x0028, 0x0000},	/*Register Mask*/
/*** end of tuning **/
};

static const struct Cmc623RegisterSet cmc623_cabcoff3[] = {
/*** start of tuning **/
	{0x0000, 0x0000},	/*BANK 0*/
	{0x0001, 0x0060},	/*SCR LABC*/
	{0x002c, 0x0fff},	/*DNR bypass 0x003C*/
	{0x002d, 0x1900},	/*DNR bypass 0x0a08*/
	{0x002e, 0x0000},	/*DNR bypass 0x1010*/
	{0x002f, 0x00ff},	/*DNR bypass 0x0400*/
	{0x003A, 0x000D},	/*HDTR DE CS*/
	{0x003B, 0x03ff},	/*DE SHARPNESS*/
	{0x003C, 0x0000},	/*NOISE LEVEL*/
	{0x003F, 0x00a0},	/*CS GAIN*/
	{0x0042, 0x0000},	/*DE TH (MAX DIFF)*/
/*	{0x00b4, 0x4640},*/	/*Count PWM*/
	{0x00c8, 0x0030},	/*kb R	SCR*/
	{0x00c9, 0x0000},	/*gc R*/
	{0x00ca, 0xffff},	/*rm R*/
	{0x00cb, 0xfff6},	/*yw R*/
	{0x00cc, 0x0000},	/*kb G*/
	{0x00cd, 0xffff},	/*gc G*/
	{0x00ce, 0x0000},	/*rm G*/
	{0x00cf, 0xf4f6},	/*yw G*/
	{0x00d0, 0x00ff},	/*kb B*/
	{0x00d1, 0x00ff},	/*gc B*/
	{0x00d2, 0x00ff},	/*rm B*/
	{0x00d3, 0x00ff},	/*yw B*/
	{0x0000, 0x0001},	/*BANK 1*/
	{0x0020, 0x0000},	/*GAMMA pls_0*/
	{0x0021,0x1000},
	{0x0022,0x1000},
	{0x0023,0x1000},
	{0x0024,0x1000},
	{0x0025,0x1000},
	{0x0026,0x1000},
	{0x0027,0x1000},
	{0x0028,0x1000},
	{0x0029,0x1000},
	{0x002A,0xa315},
	{0x002B,0xa315},
	{0x002C,0xa315},
	{0x002D,0xa315},
	{0x002E,0xa315},
	{0x002F,0xa315},
	{0x0030,0xa315},
	{0x0031,0xa315},
	{0x0032,0xa315},
	{0x0033,0xa315},
	{0x0034,0xa315},
	{0x0035,0xa315},
	{0x0036,0xa315},
	{0x0037,0xa315},
	{0x0038,0xFF00},
	{0x0020,0x0001},
	{0x0000, 0x0000},	/*BANK 0*/
	{0x0028, 0x0000},	/*Register Mask*/
/*** end of tuning **/
};

static const struct Cmc623RegisterSet cmc623_cabcoff4[] = {
	/*start*/
	{0x0000, 0x0000},	/*BANK 0*/
	{0x0001, 0x0060},	/*LABC CABC*/
	{0x002c, 0x0fff},	/*DNR bypass*/
	{0x002e, 0x0000},	/*DNR bypass*/
	{0x003a, 0x0009},	/*HDTR DE CS*/
	{0x003B, 0x001f},	/*DE SHARPNESS*/
	{0x003C, 0x0000},	/*NOISE LEVEL*/
	{0x003F, 0x0080},	/*CS GAIN*/
	{0x0042, 0x0000},	/*DE TH (MAX DIFF)*/
	/*{0x00b4, 0x4640},*/	/*CABC PWM set*/
	{0x00c8, 0x0000},	/*kb R	SCR*/
	{0x00c9, 0x0000},	/*gc R*/
	{0x00ca, 0xffff},	/*rm R*/
	{0x00cb, 0xffff},	/*yw R*/
	{0x00cc, 0x0000},	/*kb G*/
	{0x00cd, 0xffff},	/*gc G*/
	{0x00ce, 0x0000},	/*rm G*/
	{0x00cf, 0xfff2},	/*yw G*/
	{0x00d0, 0x00ff},	/*kb B*/
	{0x00d1, 0x00ff},	/*gc B*/
	{0x00d2, 0x00ff},	/*rm B*/
	{0x00d3, 0x00ff},	/*yw B*/
	{0x0000, 0x0001},	/*BANK 1*/
	{0x0020, 0x0000},	/*GAMMA p1va0*/
	{0x0021, 0x1a00},
	{0x0022, 0x1a00},
	{0x0023, 0x1a00},
	{0x0024, 0x1a00},
	{0x0025, 0x1a00},
	{0x0026, 0x1a00},
	{0x0027, 0x1a00},
	{0x0028, 0x1a00},
	{0x0029, 0x1a00},
	{0x002A, 0x1a00},
	{0x002B, 0x1a00},
	{0x002C, 0x1a00},
	{0x002D, 0x1a00},
	{0x002E, 0x1a00},
	{0x002F, 0x1a00},
	{0x0030, 0x1a00},
	{0x0031, 0x1a00},
	{0x0032, 0xa315},
	{0x0033, 0xa315},
	{0x0034, 0xa315},
	{0x0035, 0xa315},
	{0x0036, 0xa315},
	{0x0037, 0xa315},
	{0x0038, 0xFF00},
	{0x0020, 0x0001},
	{0x0000, 0x0000},	/*BANK 0*/
	{0x0028, 0x0000},
	/*end*/
};


static const struct Cmc623RegisterSet cmc623_bypass[] = {
/*** start of tuning **/
	{0x0000, 0x0000},	/*BANK 0*/
	{0x0001, 0x0020},	/*LABC*/
	{0x002c, 0x0fff},	/*DNR bypass 0x003C*/
	{0x002d, 0x1900},	/*DNR bypass 0x0a08*/
	{0x002e, 0x0000},	/*DNR bypass 0x1010*/
	{0x002f, 0x00ff},	/*DNR bypass 0x0400*/
	{0x003a, 0x0000},	/*HDTR off*/
	{0x00B4, 0x4640},	/*Count PWM*/
	{0x0000, 0x0001},	/*BANK 1*/
	{0x0020, 0x0000},	/*GAMMA bypass*/
    {0x0021,0x2000},
    {0x0022,0x2000},
    {0x0023,0x2000},
    {0x0024,0x2000},
    {0x0025,0x2000},
    {0x0026,0x2000},
    {0x0027,0x2000},
    {0x0028,0x2000},
    {0x0029,0x2000},
    {0x002A,0x2000},
    {0x002B,0x2000},
    {0x002C,0x2000},
    {0x002D,0x2000},
    {0x002E,0x2000},
    {0x002F,0x2000},
    {0x0030,0x2000},
    {0x0031,0x2000},
    {0x0032,0x2000},
    {0x0033,0x2000},
    {0x0034,0x2000},
    {0x0035,0x2000},
    {0x0036,0x2000},
    {0x0037,0x2000},
    {0x0038,0xFF00},
    {0x0020,0x0001},
	{0x0000, 0x0000},	/*BANK 0*/
    {0x0028,0x0000},
/*** end of tuning **/
};

extern int cmc623_suspend(struct early_suspend *h);
extern int cmc623_resume(struct early_suspend *h);

#if defined(__cplusplus)
}
#endif

#endif  /*TUNE2CMC623_HEADER*/
