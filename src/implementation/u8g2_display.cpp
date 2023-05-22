#include "u8g2_display.hpp"

#include <Arduino.h>
U8g2Display::U8g2Display(int sclPin, int sdaPin, int rstPin)
    : _display(U8G2_R0, sclPin, sdaPin, rstPin)
{
    _display.begin();
}

void U8g2Display::clear()
{
}

void U8g2Display::drawTitle(const char *title)
{
    Serial.print("Printing text ");
    Serial.print(title);

    _display.clearBuffer();
    _display.setFont(u8g2_font_profont17_mf);

    int titleLen = sizeof(title) / sizeof(char);
    int left = 0.5 * (MAIN_WIDTH - (TITLE_FONT_WIDTH * titleLen - 1));
    int top = MAIN_TOP + 0.5 * MAIN_HEIGHT + TITLE_FONT_HEIGHT / 2;
    // BOX = 0, 10, 128, 34
    _display.setCursor(left, top);
    _display.print(title);
    _display.sendBuffer();
}