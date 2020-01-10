#pragma once
#include "util.h"

#ifndef TITLE_H
#define TITLE_H

#define CENTER 21
#define LEFT_LINE 11
#define RIGHT_LINE 33
#define INFO_LEFT_LINE 37
#define INFO_RIGHT_LINE 56
#define INFO_CENTER (INFO_LEFT_LINE + INFO_RIGHT_LINE) / 2
void titleDraw();
int menuDraw();
void infoDraw();
void outlineDraw();
void deadlineDraw();
void nextBlockDraw(int);
void gameoverDraw();

#endif