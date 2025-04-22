#ifndef SPEAKER_H
#define SPEAKER_H

#include "global_vars.h"
#include "hw_config.h"

void beep(uint32_t frequency, int duration_ms);
void task_speaker(void *t_args);

#endif