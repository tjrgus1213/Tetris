#include "title.h"

void titleDraw() {
	printf("  #########    #    #########      #             ########\n");
	printf("      #        #        #          #             #       \n");
	printf("      #        #        #          #             #       \n");
	printf("      #        #        #          #             ########\n");
	printf("      #        #        #          #             #       \n");
	printf("      #        #        #          #             #       \n");
	printf("      #        #        #          #             #       \n");
	printf("      #        #        #          #########     ########\n");
}

void infoDraw() {
	system("cls");
	printf("\n\n");
	printf("                      [�� �� ��]\n\n\n");
	printf("                  �� �� : W, A, S, D\n\n");
	printf("                  �� �� : �� �� �� �� ��\n\n\n\n\n");
	printf("       �� �� �� : �� �� ��\n");
	printf("       Github : https://github.com/tjrgus1213/Tetris \n\n");
	printf("         �����̽��ٸ� ������ ����ȭ������ �̵��մϴ�.");

	while (keyControl(1) != SUBMIT);
	return;
}

void outlineDraw() {
	system("cls");
	for (int i = 3; i < 19; i++) {
		gotoxy(14, i);
		printf("O");
	}
	for (int i = 1; i < 13; i++) {
		gotoxy(14 + i, 18);
		printf("O");
	}
	for (int i = 3; i < 19; i++) {
		gotoxy(27, i);
		printf("O");
	}
}


int menuDraw() {
	int x = 24, y = 12;
	gotoxy(x - 2, y);
	printf("> �� �� �� ��\n");
	gotoxy(x, y + 1);
	printf("�� �� �� ��\n");
	gotoxy(x, y + 2);
	printf("�� ��\n");

	x = 22;
	while (1) {
		int dir = keyControl(1);
		switch (dir) {
		case UP:
			gotoxy(x, y);
			printf(" ");
			y = y - 1;
			if (y < 12)	y = 14;
			gotoxy(x, y);
			printf(">");
			break;
		case DOWN:
			gotoxy(x, y);
			printf(" ");
			y = y + 1;
			if (y > 14) y = 12;
			gotoxy(x, y);
			printf(">");
			break;
		case SUBMIT:
			return y - 12;
		}
	}
}