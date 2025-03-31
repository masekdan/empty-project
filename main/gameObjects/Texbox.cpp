#include "Textbox.h"

Textbox::Textbox(uint16_t color, uint8_t size, TFT_eSPI &tft) : tft(tft), color(color), size(size)
{
}

void Textbox::draw(int posx, int posy, std::string value)
{
    if (value != this->val)
    {
        this->tft.setCursor(posx, posy);
        this->tft.setTextColor(this->color);
        this->tft.setTextSize(this->size);
        this->tft.fillRect(posx, posy, value.length() * 10 * size, 10 * size, TFT_BLACK);
        this->tft.print(value.c_str());
        this->val = value;
    }
}