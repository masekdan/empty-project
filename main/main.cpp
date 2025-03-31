#include <stdio.h>
#include <inttypes.h>

#include "sdkconfig.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/semphr.h"
#include "driver/gpio.h"
#include "driver/ledc.h"

#include "TFT_eSPI.h"

// global variables and macros
#include "global_vars.h"
#include "hw_config.h"

// threads codes
#include "game_loop.h"
#include "dislpay.h"
#include "controller.h"
#include "speaker.h"

// GPIO button inititalization
void init_buttons()
{
    gpio_config_t btn_config;
    btn_config.intr_type = GPIO_INTR_DISABLE;
    btn_config.mode = GPIO_MODE_INPUT;
    btn_config.pin_bit_mask = (1ULL << BUTTON_A) | (1ULL << BUTTON_B) | (1ULL << BUTTON_UP) | (1ULL << BUTTON_DOWN) | (1ULL << BUTTON_LEFT) | (1ULL << BUTTON_RIGHT);
    btn_config.pull_up_en = GPIO_PULLUP_ENABLE;
    btn_config.pull_down_en = GPIO_PULLDOWN_DISABLE;
    gpio_config(&btn_config);
}

extern "C" void app_main()
{

    gpio_set_level(GPIO_NUM_33, 1);

    tft.init();
    tft.setRotation(1);
    tft.fillRect(0, 0, DISP_WIDTH, DISP_HEIGHT, TFT_BLACK);

    init_buttons();

    controller_queue = xQueueCreate(10, sizeof(int));
    sound_queue = xQueueCreate(10,sizeof(int));
    disp_sem = xSemaphoreCreateMutex();

    if (xTaskCreate(task_game_loop, "TASK_GAME", 2048, nullptr, (configMAX_PRIORITIES - 1), nullptr) != pdPASS)
    {
        printf("Cannot create game loop task\n");
    }

    if (xTaskCreate(task_controller, "TASK_CONTROLLER", 2048, nullptr, (configMAX_PRIORITIES - 1), nullptr) != pdPASS)
    {
        printf("Cannot create controller task\n");
    }

    if (xTaskCreate(task_display, "TASK_DISPLAY", 2048, nullptr, (configMAX_PRIORITIES - 1), nullptr) != pdPASS)
    {
        printf("Cannot create display task\n");
    }

    if (xTaskCreate(task_speaker, "TASK_SPEAKER",2048,nullptr, (configMAX_PRIORITIES - 1),nullptr) != pdPASS)
    {
        printf("Cannot create speaker task\n");
    }

    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}