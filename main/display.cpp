#include "display.h"

void task_display(void *t_args)
{

    Textbox msg(TFT_WHITE,1,tft);
    while (1)
    {
        xSemaphoreTake(disp_sem, portMAX_DELAY);
        // drawing of objects
        test->draw();
        msg.draw(30,20,"This is an empty project.");
        xSemaphoreGive(disp_sem);
        vTaskDelay(10);
    }
}
