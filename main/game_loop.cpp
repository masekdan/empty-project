#include "game_loop.h"

// Main game loop
void task_game_loop(void *t_args)
{
    int btnMsg;

    test = new TestObject(250,140,20,10,TFT_PURPLE,tft);

    while (1)
    {

        xSemaphoreTake(disp_sem, portMAX_DELAY);
        if (xQueueReceive(controller_queue, &btnMsg, pdMS_TO_TICKS(10)))
        {

            switch (btnMsg)
            {
            case PRESS_A:
                break;

            case PRESS_B:
                break;

            case PRESS_UP:
                break;

            case PRESS_DOWN:
                break;

            case PRESS_LEFT:
                break;

            case PRESS_RIGHT:
                break;

            default:
                break;
            }
        }


        xSemaphoreGive(disp_sem);
        vTaskDelay(10);
    }

    vTaskDelete(NULL);
}
