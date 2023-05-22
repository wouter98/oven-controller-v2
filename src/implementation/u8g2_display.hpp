#pragma once

#include "display.hpp"
#include <U8g2lib.h>

#define MAIN_LEFT   0
#define MAIN_TOP    10
#define MAIN_WIDTH  128
#define MAIN_HEIGHT 34

#define TITLE_FONT u8g2_font_profont17_mf
#define TITLE_FONT_WIDTH    9
#define TITLE_FONT_HEIGHT   11

class U8g2Display : public Display
{
public:
    U8g2Display(int sclPin, int sdaPin, int rstPin);
    void clear();
    void drawTitle(const char *text);

private:
    U8G2_SH1106_128X64_NONAME_F_SW_I2C _display;
};