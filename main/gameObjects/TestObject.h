#ifndef TEST_CLASS
#define TEST_CLASS

#include "DrawableObject.h"

class TestObject : public DrawableObject
{
private:
public:
    TestObject(int x, int y, int w, int h,uint32_t color, TFT_eSPI &tft);
    void draw() override;
    ~TestObject();
};

#endif