#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[1001][1001];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int bfs() {
	queue<pair<pair<int, int>, int> > q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1)
				q.push({ { i,j }, 0 });
		}
	}
	int cnt = 0;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		cnt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if ((nx >= 0) && (nx < M) && (ny >= 0) && (ny < N)) {
				if (arr[ny][nx] == 0) {
					arr[ny][nx] = 1;
					q.push({ {ny,nx}, cnt + 1 });
				}
			}

		}
	}
	return cnt;
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int res = bfs();
	bool check = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				check = false;
				break;
			}
		}
		if (!check)break;
	}
	if (check) printf("%d\n", res);
	else printf("-1\n");

	return 0;
}
