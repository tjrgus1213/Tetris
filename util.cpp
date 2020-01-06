#include "util.h"


void init() {
	system("mode con cols=60 lines=20 | title 게 임 제 목");
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}



void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}


int keyControl(int mode) {
	char temp;
	if (mode == 1) {
		while (true) {
			temp = _getch();
			switch (temp) {
			case 'w':
			case 'W':
				return UP;
			case 's':
			case 'S':
				return DOWN;
			case 'a':
			case 'A':
				return LEFT;
			case 'd':
			case 'D':
				return RIGHT;
			case ' ':
				return SUBMIT;

			}
		}
	}
	else {
		while (true) {
			if (_kbhit()) {
				temp = _getch();
			}
			else
				return -1;

			switch (temp) {
			case 'w':
			case 'W':
				return UP;
			case 's':
			case 'S':
				return DOWN;
			case 'a':
			case 'A':
				return LEFT;
			case 'd':
			case 'D':
				return RIGHT;
			case ' ':
				return SUBMIT;

			}
		}
	}

}