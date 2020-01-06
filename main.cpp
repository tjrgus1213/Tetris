#include "game.h"

int main() {
	init();
	while (true) {
		titleDraw();
		int menu = menuDraw();
		switch (menu) {
		case 0:
			outlineDraw();
			gameinit();
			srand((unsigned int)time(0));
			while(true)
				blockdrop(rand() % 7);
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
