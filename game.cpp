#include "game.h"

char ary[10][21];

void gameinit() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 20; j++)
			ary[i][j] = ' ';

	for (int i = 0; i < 10; i++)
		ary[i][20] = '#';
}

void blockdrop(int block) {
	int x = 20, y = 0;
	double start;
	while (y < 20) {
		start = clock();
		while ((clock() - start) / CLOCKS_PER_SEC < 0.3 && y < 20) {
			switch (keyControl(2)) {
			case LEFT:
				break;
			case RIGHT:
				break;
			}
		}
		y++;
	}
}

struct block {
public:
	block(int t) {
		type = t;
		//타입별로 점 위치 지정
	}

	void turnBlock() {

	}

	bool dropBlock() {
		for (int i = 0; i < 4; i++) {
			if (ary[dot[i][0]][dot[i][1] + 1] == '#')
				return false;
		}
		for (int i = 0; i < 4; i++)
			dot[i][1]++;
	}

	void moveBlock(int dir) {
		if (dir == LEFT) {
			for (int i = 0; i < 4; i++)
				if (dot[i][0] == 15) // 값
					return;
			for (int i = 0; i < 4; i++)
				dot[i][0]--;
		}
		else {
			for (int i = 0; i < 4; i++)
				if (dot[i][0] == 25) // 값
					return;
			for (int i = 0; i < 4; i++)
				dot[i][0]++;
		}
	}

	void printBlock(char c) {
		gotoxy(dot[0][0], dot[0][1]);
		printf("%c", c);
		gotoxy(dot[1][0], dot[1][1]);
		printf("%c", c);
		gotoxy(dot[2][0], dot[2][1]);
		printf("%c", c);
		gotoxy(dot[3][0], dot[3][1]);
		printf("%c", c);
	}

private:
	int type;
	int dot[4][2];
};