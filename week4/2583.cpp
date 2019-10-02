#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, cnt;
int arr[101][101];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void dfs(int y, int x) {
	arr[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
			if (arr[ny][nx] == 0) {
				dfs(ny, nx);
				cnt++;
			}
		}
	}
}

int main() {
	int K;
	cin >> N >> M >> K;
	for (int k = 0; k < K; k++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				arr[i][j] = 1;
			}
		}
	}
	vector<int> v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				cnt = 0;
				dfs(i, j);
				v.push_back(cnt + 1);
			}
		}
	}
	int siz = v.size();
	sort(v.begin(), v.end());
	printf("%d\n", siz);
	for (int i = 0; i < siz; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");

	return 0;
}