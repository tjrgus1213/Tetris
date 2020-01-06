#pragma once
#include "main.h"

#ifndef UTIL_H
#define UTIL_H

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

void init();
void gotoxy(int, int);
int keyControl(int);

#endif