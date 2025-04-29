#include "TestObject.h"

TestObject::TestObject(int x, int y, int w, int h,uint16_t color, TFT_eSPI &tft) : DrawableObject(x,y,w,h,color,tft)
{

}

void TestObject::draw()
{
    tft.fillRect(this->x,this->y,this->w,this->h,this->color);
}

TestObject::~TestObject()
{
    tft.fillRect(this->x,this->y,this->w,this->h,TFT_BLACK);
}
