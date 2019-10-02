#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int N, M, H;
int arr[101][101][101];

int dh[] = { 0, 0, 0, 0, 1, -1};
int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };

class tomato {
public:
	int h, y, x;
	tomato(int h, int y, int x) {
		this->h = h;
		this->y = y;
		this->x = x;
	}
};

int bfs() {
	queue<pair<tomato, int> > q;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[h][i][j] == 1) {
					q.push({ tomato(h, i, j), 0 });
				}
			}
		}
	}

	int cnt = 0;
	while (!q.empty()) {
		int h = q.front().first.h;
		int y = q.front().first.y;
		int x = q.front().first.x;
		cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nh = h + dh[i];
			int ny = y + dy[i];
			int nx = x + dx[i];
			if ((nx >= 0) && (nx < M) && (ny >= 0) && (ny < N) && (nh < H) && (nh >= 0)){
				if (arr[nh][ny][nx] == 0) {
					arr[nh][ny][nx] = 1;
					q.push({ tomato(nh, ny, nx), cnt + 1 });
				}
			}

		}
	}
	return cnt;
}

int main() {
	cin >> M >> N >> H;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> arr[h][i][j];
			}
		}
	}

	int res = bfs();
	bool check = true;
	bool toma = false;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[h][i][j] == 0) {
					check = false;
					break;
				}
				if (!toma) {
					if (arr[h][i][j] == 1)
						toma = true;
				}
			}
			if (!check)break;
		}
		if (!check)break;
	}
	if (check && toma) printf("%d\n", res);
	else printf("-1\n");

	return 0;
}
