#ifndef GAME_LOOP
#define GAME_LOOP

#include "global_vars.h"
#include "hw_config.h"
#include "esp_random.h"

int detect_colision(DrawableObject *&do1, DrawableObject *&do2);
void task_game_loop(void *t_args);

#endif