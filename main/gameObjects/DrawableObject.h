#ifndef DRAWABLE_OBJECT_CLASS
#define DRAWABLE_OBJECT_CLASS

#include "TFT_eSPI.h"

class DrawableObject
{
protected:
    int x,y,w,h;
    uint32_t color;
    TFT_eSPI &tft;
public:
    DrawableObject(int x, int y,int w, int h,uint32_t color, TFT_eSPI &tft);
    virtual ~DrawableObject();
    virtual void draw() = 0;
    void moveBy(int dirx, int diry);
    void moveTo(int x, int y);

    // getters
    int getX();
    int getY();
    int getWidth();
    int getHeight();
};

#endif