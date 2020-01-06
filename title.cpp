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
	printf("                      [조 작 법]\n\n\n");
	printf("                  이 동 : W, A, S, D\n\n");
	printf("                  선 택 : 스 페 이 스 바\n\n\n\n\n");
	printf("       개 발 자 : 장 석 현\n");
	printf("       Github : https://github.com/tjrgus1213/Tetris \n\n");
	printf("         스페이스바를 누르면 메인화면으로 이동합니다.");

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
	printf("> 게 임 시 작\n");
	gotoxy(x, y + 1);
	printf("게 임 정 보\n");
	gotoxy(x, y + 2);
	printf("종 료\n");

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