/*
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int arr[9][9];

bool k = false;

bool check(int map[9][9], int i, int j) {
	bool v[10] = { false };
	bool h[10] = { false };
	for (int x = 0; x < 9; x++) {
		if (v[map[i][x]] && map[i][x] != 0) return false;
		if (h[map[x][j]] && map[x][j] != 0) return false;
		v[map[i][x]] = true;
		h[map[x][j]] = true;
	}
	int y = (i / 3)*3;
	int x = (j / 3)*3;
	bool c[10] = { false };
	for (int a = y; a < y + 3; a++) {
		for (int b = x; b < x + 3; b++) {
			if (c[map[a][b]] && map[a][b] != 0) return false;
			c[map[a][b]] = true;
		}
	}
	return true;
}

void dfs(int map[9][9], int cnt) {
	if (cnt == 0) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				arr[i][j] = map[i][j];
			}
		}
		k = true;
		return;
	}
	if (k) return;
	int y, x;
	for (y = 0; y < 9; y++) {
		for (x = 0; x < 9; x++) {
			if (map[y][x] == 0) {
				for (int n = 1; n < 10; n++) {
					map[y][x] = n;
					if (check(map, y, x)) {	
						dfs(map, cnt - 1);
					}
					map[y][x] = 0;
				}
			}
			if (map[y][x] == 0) return;
		}
	}

}

int main() {

	int map[9][9];
	int cnt = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) cnt++;
		}
	}
	
	dfs(map, cnt);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}


	return 0;
}
*/