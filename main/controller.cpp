#include "controller.h"

// Controller thread
void task_controller(void *t_args)
{
    vTaskDelay(pdMS_TO_TICKS(200));

    int last_button_a_state = 0;
    int last_button_b_state = 0;
    int last_button_up_state = 0;
    int last_button_down_state = 0;
    int last_button_left_state = 0;
    int last_button_right_state = 0;


    while (1)
    {
        int btnMsg = 0;

        int button_a_state = gpio_get_level(BUTTON_A);
        int button_b_state = gpio_get_level(BUTTON_B);
        int button_up_state = gpio_get_level(BUTTON_UP);
        int button_down_state = gpio_get_level(BUTTON_DOWN);
        int button_left_state = gpio_get_level(BUTTON_LEFT);
        int button_right_state = gpio_get_level(BUTTON_RIGHT);

        if (button_a_state == 1 && last_button_a_state == 0)
        {
            btnMsg = 1;
        }

        if (button_b_state == 1 && last_button_b_state == 0)
        {
            btnMsg = 2;
        }

        if (button_up_state == 1 && last_button_up_state == 0)
        {
            btnMsg = 3;
        }

        if (button_down_state == 1 && last_button_down_state == 0)
        {
            btnMsg = 4;
        }

        if (button_left_state == 1 && last_button_left_state == 0)
        {
            btnMsg = 5;
        }

        if (button_right_state == 1 && last_button_right_state == 0)
        {
            btnMsg = 6;
        }

        if (btnMsg != 0)
        {
            xQueueSend(controller_queue, &btnMsg, portMAX_DELAY);
        }

        last_button_a_state = button_a_state;
        last_button_b_state = button_b_state;
        last_button_up_state = button_up_state;
        last_button_down_state = button_down_state;
        last_button_left_state = button_left_state;
        last_button_right_state = button_right_state;

        vTaskDelay(pdMS_TO_TICKS(DEBOUNCE_TIME_MS));
    }
}