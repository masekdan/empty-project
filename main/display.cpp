#include "dislpay.h"

void task_display(void *t_args)
{

    while (1)
    {
        xSemaphoreTake(disp_sem, portMAX_DELAY);
        // drawing of objects
        xSemaphoreGive(disp_sem);
        vTaskDelay(10);
    }
}
