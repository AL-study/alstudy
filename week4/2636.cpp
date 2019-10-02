#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, cheese, prev_cheese;
int arr[101][101];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void die() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 3) {
				arr[i][j] = 2;
			}
		}
	}
}

void dfs(int y, int x) {
	for (int z = 0; z < 4; z++) {
		int ny = y + dy[z];
		int nx = x + dx[z];
		if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
			if (arr[ny][nx] == 0) {
				arr[ny][nx] = 2;
				dfs(ny, nx);
			}
			if (arr[ny][nx] == 1) {
				arr[ny][nx] = 3;
				prev_cheese++;
			}
		}
	}
}

void boom() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 2) {
				dfs(i, j);
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) cheese++;
		}
	}
	for (int i = 0; i < N; i++) {
		arr[i][0] = 2;
		arr[i][M - 1] = 2;
	}
	for (int i = 0; i < M; i++) {
		arr[0][i] = 2;
		arr[N-1][i] = 2;
	}
	int cnt = 1;
	while (1) {
		boom();
		die();
		cheese -= prev_cheese;
		if (cheese == 0)break;
		prev_cheese = 0;
		cnt++;
	}
	printf("%d\n%d\n", cnt, prev_cheese);

	return 0;
}