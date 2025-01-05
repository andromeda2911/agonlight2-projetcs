/*
 Title:		conio_agon.c
 Author:	Badre
 Created:	23/12/2023 
 Last Updated: 18/01/2024

 Modinfo:
 17/01/2024		replace getsysvar_vkeycode by kbd_code
 				added waitMsg method 
 18/01/2024		permit CTR-c on waitMsg
*/

#ifndef _CONIOAGON_H
#define _CONIOAGON_H

#include <stdbool.h>
#include <agon/vdp_key.h>
#include "vdpmode.h"

extern void clreol(void);
extern void getrtc(void);
extern void saveScrMmode(void);
extern void setSavedScrMode(void);


#define MAX_X               80
#define MAX_Y               25
#define ROW_STATUS	        24
#define ROW_FKEY	        25
#define ROW_TITLE	        1
#define AREA_HEX_DISPLAY	20
#define LEFT_MARGIN	        1
#define WIDTH_TEXT_PIXEL    8
#define HEIGHT_TEXT_PIXEL   8

static int scr_mode = VDPMODE_640x480_16C; //VDPMODE_640x480_16C;

void xprintf(int row, int col, const char * format, ...);
void clearRect(int x1, int y1, int x2, int y2, int color);
void clrscr();
void textattr(int bg, int fg);
void crlf();
//void clreol();
void clearlines(int col, int row, int height);
void statusBar(int col, int row, const char *text);
void textcolor(int fg);
void graphicColor(int mode, int color);
void textbackground(unsigned char bg);
//void drawfkeys(int col, int row, const char * const  fkeys[]);
void gotoxy(int row, int col);
void cursorEnable(bool flag);
int setmode(int mode);
bool waitMsg(const char *msg);
bool isKeyCtrl(char c);
void initSysvar();
uint8_t vdp_cursorGetXpos(void);
uint8_t vdp_cursorGetYpos(void);
bool valid_yesno(int x, int y, const char * msg);

#endif
