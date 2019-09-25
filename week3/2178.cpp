#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[101][101];
int visited[101][101];

int bfs() {
	queue<pair<pair<int, int>, int> > q;
	q.push({ { 0,0 }, 1 });

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (y == N - 1 && x == M - 1) {
			return cnt;
		}
		if (visited[y][x]) continue;
		visited[y][x] = true;
		if (arr[y][x + 1] && x < M) {
			q.push({ { y, x + 1 }, cnt + 1 });
		}
		if (arr[y][x - 1] && x >= 0) {
			q.push({ { y, x - 1 }, cnt + 1 });
		}
		if (arr[y - 1][x] && y >= 0) {
			q.push({ { y - 1, x }, cnt + 1 });
		}
		if (arr[y + 1][x] && y < N ) {
			q.push({ { y + 1, x }, cnt + 1 });
		}

	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	printf("%d\n", bfs());


	return 0;
}