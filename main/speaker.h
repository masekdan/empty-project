#ifndef SPEAKER_H
#define SPEAKER_H

#include "global_vars.h"
#include "hw_config.h"

#define LEDC_CHANNEL LEDC_CHANNEL_0
#define LEDC_TIMER LEDC_TIMER_0
#define LEDC_MODE LEDC_LOW_SPEED_MODE
#define LEDC_DUTY 512

void beep(uint32_t frequency, int duration_ms);
void task_speaker(void *t_args);

#endif