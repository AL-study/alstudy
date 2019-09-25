#include <iostream>
#include <queue>
#include <string>
using namespace std;
typedef struct {
	int x;
	int y;
}Point;
char map[101][101];
int N, M;
int visit[101][101];
queue < pair<Point, int> > Q;
int d[][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
bool isOutSideMap(int x, int y) {
	if (x < 1 || x > N || y <1 || y>M) {
		return true;
	}
	return false;
}
int BFS(int x, int y) {
	int res;
	visit[x][y] = 1;
	Point startPoint = { x,y };
	Q.push({ startPoint, 1 });
	while (!Q.empty()) {
		Point front = Q.front().first;
		int nowLevel = Q.front().second;
		Q.pop();
		if (front.x == N && front.y == M) {
			res = nowLevel;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int tmpX = front.x + d[i][0];
			int tmpY = front.y + d[i][1];
			if (isOutSideMap(tmpX, tmpY)) {
				continue;
			}
			else {
				if (!visit[tmpX][tmpY] && map[tmpX][tmpY] == '1') {
					visit[tmpX][tmpY] = 1;
					Point tmp = { tmpX,tmpY };
					Q.push({ tmp, nowLevel + 1 });
				}
			}
		}
	}
	return res;
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf(" %c", &map[i][j]);
		}
	}

	int res = BFS(1, 1);
	printf("%d\n", res);
	return 0;
}