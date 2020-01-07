#include "game.h"

char ary[14][21];

struct block {
public:
	block(int t) {
		type = t; // x = 20 y = 3
		switch (t) {
		case 0: // 네모
			dot[0][0] = 20;	dot[0][1] = 1;
			dot[1][0] = 21;	dot[1][1] = 1;
			dot[2][0] = 20;	dot[2][1] = 2;
			dot[3][0] = 21;	dot[3][1] = 2;
			break;
		case 1: // 작대기
			dot[0][0] = 20;	dot[0][1] = 2;
			dot[1][0] = 20;	dot[1][1] = 1;
			dot[2][0] = 20;	dot[2][1] = 3;
			dot[3][0] = 20;	dot[3][1] = 4;
			break;
		case 2: // ㄱㄴ
			dot[0][0] = 21;	dot[0][1] = 1;
			dot[1][0] = 20;	dot[1][1] = 1;
			dot[2][0] = 21;	dot[2][1] = 2;
			dot[3][0] = 22;	dot[3][1] = 2;
			break;
		case 3: // ㄴㄱ
			dot[0][0] = 20;	dot[0][1] = 1;
			dot[1][0] = 21;	dot[1][1] = 1;
			dot[2][0] = 20;	dot[2][1] = 2;
			dot[3][0] = 19;	dot[3][1] = 2;
			break;
		case 4: // ㄱ
			dot[0][0] = 21;	dot[0][1] = 1;
			dot[1][0] = 20;	dot[1][1] = 1;
			dot[2][0] = 22;	dot[2][1] = 1;
			dot[3][0] = 22;	dot[3][1] = 2;
			break;
		case 5: // ㄴ
			dot[0][0] = 21;	dot[0][1] = 1;
			dot[1][0] = 20;	dot[1][1] = 1;
			dot[2][0] = 22;	dot[2][1] = 1;
			dot[3][0] = 20;	dot[3][1] = 2;
			break;
		case 6: // ㅗ
			dot[0][0] = 21;	dot[0][1] = 1;
			dot[1][0] = 20;	dot[1][1] = 2;
			dot[2][0] = 21;	dot[2][1] = 2;
			dot[3][0] = 22;	dot[3][1] = 2;
			break;
		}
	}

	void turnBlock() {
		int temp[4][2];
		switch (type) {
		case 0:
			return;
		case 1:
			if (dot[0][0] == dot[1][0]) {
				temp[1][0] = dot[0][0] - 1;
				temp[2][0] = dot[0][0] + 1;
				temp[3][0] = dot[0][0] + 2;

				temp[1][1] = dot[0][1];
				temp[2][1] = dot[0][1];
				temp[3][1] = dot[0][1];
			}
			else {
				temp[1][1] = dot[0][1] - 1;
				temp[2][1] = dot[0][1] + 1;
				temp[3][1] = dot[0][1] + 2;

				temp[1][0] = dot[0][0];
				temp[2][0] = dot[0][0];
				temp[3][0] = dot[0][0];
			}
			break;
		default:
			for (int i = 1; i < 4; i++) {
				if (dot[0][0] < dot[i][0]) {		// 오른쪽
					temp[i][0] = dot[i][1] - dot[0][1] + dot[0][0];
					temp[i][1] = dot[0][1] - 1;
				}
				else if (dot[0][1] > dot[i][1]) {	// 위
					temp[i][0] = dot[0][0] - 1;
					temp[i][1] = dot[0][0] - dot[i][0] + dot[0][1];
				}
				else if (dot[0][0] > dot[i][0]) {	// 왼
					temp[i][0] = dot[i][1] - dot[0][1] + dot[0][0];
					temp[i][1] = dot[0][1] + 1;
				}
				else if(dot[0][1] < dot[i][1]) {								// 아
					temp[i][0] = dot[0][0] + 1;
					temp[i][1] = dot[0][0] - dot[i][0] + dot[0][1];
				}
				else {
					temp[i][0] = dot[i][0];
					temp[i][1] = dot[i][1];
				}
			}
			break;
		}
		for(int i = 1; i < 4; i++)
			if (ary[temp[i][0] - 14][temp[i][1]] == '#')
				return;
		for (int i = 1; i < 4; i++) {
			dot[i][0] = temp[i][0];
			dot[i][1] = temp[i][1];
		}
	}

	bool dropBlock() {
		for (int i = 0; i < 4; i++) {
			if (ary[dot[i][0] - 14][dot[i][1] + 1] == '#')
				return false;
		}
		for (int i = 0; i < 4; i++)
			dot[i][1]++;
		return true;
	}

	void moveBlock(int dir) {
		if (dir == LEFT) {
			for (int i = 0; i < 4; i++)
				if (ary[dot[i][0] - 15][dot[i][1]] == '#') // 값
					return;
			for (int i = 0; i < 4; i++)
				dot[i][0]--;
		}
		else {
			for (int i = 0; i < 4; i++)
				if (ary[dot[i][0] - 13][dot[i][1]] == '#') // 값
					return;
			for (int i = 0; i < 4; i++)
				dot[i][0]++;
		}
	}

	bool isfull() {
		for (int i = 0; i < 4; i++) {
			if (ary[dot[i][0] - 14][dot[i][1]] == '#')
				return true;
		}
		return false;
	}

	void checkAry() {
		int i, j, ind = 0;
		int line[4];
		bool is;
		for (i = 0; i < 4; i++) {
			for (j = 1; j < 14; j++) {
				if (ary[j][dot[i][1]] != '#')
					break;
			}
			if (j == 14) {
				is = false;
				for (int k = 0; k < ind; k++) {
					if (line[k] == dot[i][1])
						is = true;
				}
				if (!is)
					line[ind++] = dot[i][1];
			}
		}

		for (int i = 0; i < ind; i++) {
			for (int x = 1; x < 14; x++) {
				for (int y = line[i]; y > 0; y--) {
					ary[x][y] = ary[x][y - 1];
				}
			}
		}
		if (ind > 0) {
			for (int y = 1; y < 18; y++) {
				gotoxy(15, y);
				for (int x = 1; x < 13; x++)
					printf("%c", ary[x][y]);
			}
		}
	}

	void saveBlock() {
		for (int i = 0; i < 4; i++) {
			ary[dot[i][0] - 14][dot[i][1]] = '#';
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

void gameinit() {
	for (int i = 1; i < 13; i++)
		for (int j = 0; j < 20; j++)
			ary[i][j] = ' ';
	for (int i = 0; i < 20; i++)
		ary[0][i] = '#';
	for (int i = 0; i < 20; i++)
		ary[13][i] = '#';
	for (int i = 0; i < 14; i++)
		ary[i][18] = '#';
}

bool blockdrop(int type) {
	double start;
	block nb = block(type);
	if (nb.isfull())
		return false;

	while (true) {
		start = clock();
		while ((clock() - start) / CLOCKS_PER_SEC < 0.3) {
			switch (keyControl(2)) {
			case LEFT:
				nb.printBlock(' ');
				nb.moveBlock(LEFT);
				nb.printBlock('#');
				break;
			case RIGHT:
				nb.printBlock(' ');
				nb.moveBlock(RIGHT);
				nb.printBlock('#');
				break;
			case DOWN:
				start -= 250;
				break;
			case SUBMIT:
				nb.printBlock(' ');
				nb.turnBlock();
				nb.printBlock('#');
				break;
			}
		}
		nb.printBlock(' ');
		if (!nb.dropBlock()) {
			nb.printBlock('#');
			nb.saveBlock();
			nb.checkAry();
			break;
		}
		else
			nb.printBlock('#');
	}
	return true;
}