#pragma once

class Display
{
public:
    virtual void clear() = 0;
    virtual void drawTitle(const char* text) = 0;
};