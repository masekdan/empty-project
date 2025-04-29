#include "DrawableObject.h"

/// @brief Drawable Object constructor
DrawableObject::DrawableObject(int x, int y, int w, int h, uint32_t color, TFT_eSPI &tft) : x(x), y(y), w(w), h(h), color(color), tft(tft)
{
}

/// @brief Moves drawable by direction
/// @param dirx direction on x axis - negative left, positive right
/// @param diry direction on y axis - negative up, positive down
void DrawableObject::moveBy(int dirx, int diry)
{
    this->tft.fillRect(this->x, this->y, this->w, this->h, TFT_BLACK);
    this->x += dirx;
    this->y += diry;
}

/// @brief Moves drawable object to point set by coordinates
/// @param x X Coordinate
/// @param y Y Coordinate
void DrawableObject::moveTo(int x, int y)
{
    this->tft.fillRect(this->x, this->y, this->w, this->h, TFT_BLACK);
    this->x = x;
    this->y = y;
}

/// @brief Drawable Object destructors
DrawableObject::~DrawableObject()
{
    
}

/// @brief Getter of the x coordinate
/// @return x coordinate
int DrawableObject::getX()
{
    return this->x;
}

/// @brief Getter of the y coordinate
/// @return y coordinate
int DrawableObject::getY()
{
    return this->y;
}

/// @brief Getter of the width
/// @return width of the object
int DrawableObject::getWidth()
{
    return this->w;
}

/// @brief Getter of the height
/// @return height of the object
int DrawableObject::getHeight()
{
    return this->h;
}