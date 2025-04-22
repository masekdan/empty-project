#include "speaker.h"

// freq 1-2300
void beep(uint32_t frequency, int duration_ms) {

    ledc_timer_config_t timer_conf = {
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .duty_resolution = LEDC_TIMER_2_BIT,
        .timer_num = LEDC_TIMER_0,
        .freq_hz = frequency,
        .clk_cfg = LEDC_AUTO_CLK
    };
    ledc_timer_config(&timer_conf);

    ledc_channel_config_t channel_conf = {
        .gpio_num = AUDIO,
        .speed_mode = LEDC_LOW_SPEED_MODE,
        .channel = LEDC_CHANNEL_0,
        .intr_type = LEDC_INTR_DISABLE,
        .timer_sel = LEDC_TIMER_0,
        .duty = 2,
        .hpoint = 0
    };
    ledc_channel_config(&channel_conf);

    vTaskDelay(pdMS_TO_TICKS(duration_ms));

    ledc_stop(LEDC_LOW_SPEED_MODE, LEDC_CHANNEL_0, 0);
}


void task_speaker(void *t_args)
{
    int sound;
    while (1)
    {
        if (xQueueReceive(sound_queue, &sound, pdMS_TO_TICKS(portMAX_DELAY)))
        {
            switch (sound)
            {
            case 1:
                beep(800,50);
                break;
            
            case 2:
                beep(1000,50);
                break;
            
            case 3:
                beep(1200,50);
                break;

            case 4:
                beep(1400,50);
                break;

            case 5:
                beep(1600,50);
                break;
            
            case 6:
                beep(1800,50);
                break;
            
            case 7:
                beep(2000,50);
                break;

            case 8:
                beep(2200,50);
                break;

            default:
                break;
            }
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}