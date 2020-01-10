#include "title.h"

void titleDraw() {
	printf("\n\n\n");
	printf("  ■■■■■  ■■■■  ■■■■■  ■■■■  ■■■  ■■■■\n");
	printf("      ■      ■            ■      ■    ■    ■    ■      \n");
	printf("      ■      ■            ■      ■■■■    ■    ■      \n");
	printf("      ■      ■■■■      ■      ■          ■    ■■■■\n");
	printf("      ■      ■            ■      ■■        ■          ■\n");
	printf("      ■      ■            ■      ■  ■      ■          ■\n");
	printf("      ■      ■■■■      ■      ■    ■  ■■■  ■■■■\n");
}

void gameoverDraw() {
	system("cls");
	printf("\n\n\n");
	printf("    □□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("    □□■■■■□□□□■□□□□■■□□□■■□■■■■□\n");
	printf("    □■□□□□□□□■□■□□□■□■□■□■□■□□□□\n");
	printf("    □■□□□□□□□■□■□□□■□■□■□■□■■■■□\n");
	printf("    □■□□■■□□■■■■■□□■□□■□□■□■□□□□\n");
	printf("    □■□□□■□□■□□□■□□■□□□□□■□■□□□□\n");
	printf("    □□■■■■□■□□□□□■□■□□□□□■□■■■■□\n");
	printf("    □□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("    □□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	printf("    □□■■■□□■□□□□□■□■■■■■□□■■■■□□\n");
	printf("    □■□□□■□■□□□□□■□■□□□□□□■□□□■□\n");
	printf("    □■□□□■□□■□□□■□□■■■■■□□■■■■□□\n");
	printf("    □■□□□■□□■□□□■□□■□□□□□□■■□□□□\n");
	printf("    □■□□□■□□□■□■□□□■□□□□□□■□■□□□\n");
	printf("    □□■■■□□□□□■□□□□■■■■■□□■□□■■□\n");
	printf("    □□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
	gotoxy(CENTER + 5, 22);
	printf("Press any Key");
	Sleep(300);
}

void infoDraw() {
	system("cls");
	printf("\n\n");
	printf("                      [조 작 법]\n\n\n");
	printf("                  이 동 : W, A, S, D\n\n");
	printf("                  선 택, 회 전 : 스 페 이 스 바\n\n\n\n\n");
	printf("       개 발 자 : 장 석 현\n");
	printf("       Github : https://github.com/tjrgus1213/Tetris \n\n");
	printf("         스페이스바를 누르면 메인화면으로 이동합니다.");

	while (keyControl(1) != SUBMIT);
	return;
}

void outlineDraw() {
	system("cls");
	for (int i = 4; i < 22; i++) { // info left line
		gotoxy(INFO_LEFT_LINE, i);
		printf("│");
	}
	for (int i = 4; i < 22; i++) { // info right line
		gotoxy(INFO_RIGHT_LINE, i);
		printf("│");
	}
	for (int i = 1; i < 10; i++) { // horizon
		gotoxy(INFO_LEFT_LINE + i * 2, 3);
		printf("─");
		gotoxy(INFO_LEFT_LINE + i * 2, 10);
		printf("─");
		gotoxy(INFO_LEFT_LINE + i * 2, 16);
		printf("─");
		gotoxy(INFO_LEFT_LINE + i * 2, 22);
		printf("─");
		
	}
	{
		gotoxy(INFO_LEFT_LINE, 3);
		printf("┌");
		gotoxy(INFO_RIGHT_LINE, 3);
		printf("┐");
		gotoxy(INFO_LEFT_LINE, 10);
		printf("├");
		gotoxy(INFO_RIGHT_LINE, 10);
		printf("┤");
		gotoxy(INFO_LEFT_LINE, 16);
		printf("├");
		gotoxy(INFO_RIGHT_LINE, 16);
		printf("┤");
		gotoxy(INFO_LEFT_LINE, 22);
		printf("└");
		gotoxy(INFO_RIGHT_LINE, 22);
		printf("┘");
	}
	for (int i = 3; i < 23; i++) { // game left line
		gotoxy(LEFT_LINE, i);
		printf("▩");
	}
	for (int i = 1; i < 11; i++) { // game bottom line
		gotoxy(LEFT_LINE + i * 2, 22);
		printf("▩");
	}
	for (int i = 3; i < 23; i++) { // game right line
		gotoxy(RIGHT_LINE, i);
		printf("▩");
	}

	gotoxy(INFO_LEFT_LINE + 7, 4);
	printf("N E X T");
	gotoxy(INFO_LEFT_LINE + 7, 12);
	printf("L I N E");
	gotoxy(INFO_LEFT_LINE + 6, 18);
	printf("L E V E L");
}

void nextBlockDraw(int type) {
	for (int j = 5; j < 10; j++) {
		gotoxy(INFO_LEFT_LINE + 1, j);
		printf("                  ");
	}
	switch (type) {
	case 0:
		gotoxy(INFO_CENTER, 6);
		printf("■■");
		gotoxy(INFO_CENTER, 7);
		printf("■■");
		return;
	case 1:
		gotoxy(INFO_CENTER - 2, 7);
		printf("■■■■");
		return;
	case 2:
		gotoxy(INFO_CENTER - 1, 6);
		printf("■■");
		gotoxy(INFO_CENTER + 1, 7);
		printf("■■");
		return;
	case 3:
		gotoxy(INFO_CENTER - 1, 7);
		printf("■■");
		gotoxy(INFO_CENTER + 1, 6);
		printf("■■");
		return;
	case 4:
		gotoxy(INFO_CENTER - 1, 6);
		printf("■■■");
		gotoxy(INFO_CENTER + 3, 7);
		printf("■");
		return;
	case 5:
		gotoxy(INFO_CENTER - 1, 6);
		printf("■■■");
		gotoxy(INFO_CENTER - 1, 7);
		printf("■");
		return;
	case 6:
		gotoxy(INFO_CENTER, 6);
		printf("■");
		gotoxy(INFO_CENTER - 2, 7);
		printf("■■■");
		return;
	}
}

void deadlineDraw() {
	gotoxy(LEFT_LINE + 2, 6);
	printf("_  _  _  _  _  _  _");
}

int menuDraw() {
	int x = 27, y = 17;
	gotoxy(x - 2, y);
	printf("> 게 임 시 작");
	gotoxy(x, y + 1);
	printf("게 임 정 보");
	gotoxy(x, y + 2);
	printf("   종 료");

	x = 25;
	while (1) {
		int dir = keyControl(1);
		switch (dir) {
		case UP:
			gotoxy(x, y);
			printf(" ");
			y = y - 1;
			if (y < 17)	y = 19;
			gotoxy(x, y);
			printf(">");
			break;
		case DOWN:
			gotoxy(x, y);
			printf(" ");
			y = y + 1;
			if (y > 19) y = 17;
			gotoxy(x, y);
			printf(">");
			break;
		case SUBMIT:
			return y - 17;
		}
	}
}