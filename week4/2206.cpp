#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[1001][1001];
int visited[1001][1001][2];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int bfs() {
	queue<pair<pair<int, int>, pair<int, int> > > q;
	q.push({ { 0,0 }, { 1,1 } });

	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int wall = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if ((y == N - 1) && (x == M - 1)) {
			return cnt;
		}
		
		for (int t = 0; t < 4; t++) {
			int fy = y + dy[t];
			int fx = x + dx[t];
			if ((fx >= 0) && (fx < M) && (fy >= 0) && (fy < N)) {

				if (arr[fy][fx] && wall) {
					visited[fy][fx][1] = 1;
					q.push({ {fy,fx}, {0,cnt + 1} });
				}
				else if (arr[fy][fx] == 0 && visited[fy][fx][wall] == 0) {
					visited[fy][fx][wall] = 1;
					q.push({ {fy,fx}, {wall,cnt + 1} });
				}
			}
		}
	}

	return -1;
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