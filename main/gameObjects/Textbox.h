#ifndef TEXTBOX_CLASS
#define TEXTBOX_CLASS

#include "TFT_eSPI.h"
#include <string>

class Textbox {
    private:
        TFT_eSPI &tft;
        uint16_t color;
        std::string val;
        uint8_t size;
    public:
        Textbox(uint16_t color,uint8_t size, TFT_eSPI& tft);
        void draw(int posx, int posy, std::string value);
};

#endif