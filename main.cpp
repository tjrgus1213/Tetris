#include "game.h"

int main() {
	init();
	while (true) {
		titleDraw();
		int menu = menuDraw();
		int level = 1;
		bool gameover;

		switch (menu) {
		case 0:
			do {
				system("cls");
				gotoxy(26, 9);
				printf(" L E V E L   %d", level);
				Sleep(1000);
				outlineDraw();
				deadlineDraw();
				gameinit();
				gameover = gameStart(level);
				level++;
			} while (gameover);
			gameoverDraw();
			_getch();
			break;
		case 1:
			infoDraw();
			break;
		case 2:
			return 0;
		}
		system("cls");
	}
	system("pause");
	return 0;
}
