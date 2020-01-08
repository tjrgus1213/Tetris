#pragma once
#ifndef GAME_H
#define GAME_H

#include "title.h"
#include <time.h>

bool blockdrop(double speed, int &line, int type);
bool gameStart(int level);
void gameinit();
#endif