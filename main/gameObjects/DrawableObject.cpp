#include "DrawableObject.h"

DrawableObject::DrawableObject(int x, int y, int w, int h, uint32_t color, TFT_eSPI &tft) : x(x), y(y), w(w), h(h), color(color), tft(tft)
{
}

void DrawableObject::moveBy(int dirx, int diry)
{
    this->tft.fillRect(this->x, this->y, this->w, this->h, TFT_BLACK);
    this->x += dirx;
    this->y += diry;
}

void DrawableObject::moveTo(int x, int y)
{
    this->tft.fillRect(this->x, this->y, this->w, this->h, TFT_BLACK);
    this->x = x;
    this->y = y;
}

DrawableObject::~DrawableObject()
{
    
}

int DrawableObject::getX()
{
    return this->x;
}

int DrawableObject::getY()
{
    return this->y;
}

int DrawableObject::getWidth()
{
    return this->w;
}

int DrawableObject::getHeight()
{
    return this->h;
}