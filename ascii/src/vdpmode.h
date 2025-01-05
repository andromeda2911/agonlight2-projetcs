#ifndef _VDPMODE_H
#define _VDPMODE_H


// DEFAULT COLOR INDEXES
enum {
    BLACK = 0,
    DARK_RED,
    DARK_GREEN,
    DARK_YELLOW,
    DARK_BLUE,
    DARK_MAGENTA,
    DARK_CYAN,
    DARK_WHITE,
    BRIGHT_BLACK,
    BRIGHT_RED,
    BRIGHT_GREEN,
    BRIGHT_YELLOW,
    BRIGHT_BLUE,
    BRIGHT_MAGENTA,
    BRIGHT_CYAN,
    BRIGHT_WHITE
};

// VDP modes
#define VDPMODE_640x480_16C       0
#define VDPMODE_640x480_4C        1
#define VDPMODE_640x480_4C_DB   129
#define VDPMODE_640x480_2C        2
#define VDPMODE_640x480_2C_DB   130
#define VDPMODE_640x240_64C       3
#define VDPMODE_640x240_16C       4
#define VDPMODE_640x240_16C_DB  132
#define VDPMODE_640x240_4C        5
#define VDPMODE_640x240_4C_DB   133
#define VDPMODE_640x240_2C        6
#define VDPMODE_640x240_2C_DB   134
#define VDPMODE_320x240_64C       8
#define VDPMODE_320x240_64C_DB  136
#define VDPMODE_320x240_16C       9
#define VDPMODE_320x240_16C_DB  137
#define VDPMODE_320x240_4C       10
#define VDPMODE_320x240_4C_DB   138
#define VDPMODE_320x240_2C       11
#define VDPMODE_320x240_2C_DB   139
#define VDPMODE_320x200_64C      12
#define VDPMODE_320x200_64C_DB  140
#define VDPMODE_320x200_16C      13
#define VDPMODE_320x200_16C_DB  141
#define VDPMODE_320x200_4C       14
#define VDPMODE_320x200_4C_DB   142
#define VDPMODE_320x200_2C       15
#define VDPMODE_320x200_2C_DB   143
#define VDPMODE_800x600_4C       16
#define VDPMODE_800x600_2C       17
#define VDPMODE_1024x768_2C      18

#define VDPMODE_DEFAULT           1

#endif