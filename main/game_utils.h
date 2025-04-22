#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include "global_vars.h"
#include "hw_config.h"
#include <vector>

extern std::vector<int> go_ost;
extern std::vector<int> w_ost;

int detect_collision(DrawableObject *&do1, DrawableObject *&do2);
void game_over();
void end_game();
void play_sound(int sound);
void pause_game();

#endif