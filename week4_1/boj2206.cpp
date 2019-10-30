#include <cstdio>
#include <queue>

using namespace std;

struct Info {
  int x, y, w;
};

int N, M;
int map[1001][1001];
int dist[1001][1001][2];

int bfs() {
  queue<Info> route;
  Info info = {0, 0, 0};
  route.push(info);
  dist[0][0][0] = 1;
  int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
  while(!route.empty()) {
    int x = route.front().x, y = route.front().y, w = route.front().w;
    route.pop();
    if(x == N-1 && y == M-1) {
      return dist[x][y][w];
    }
    for(int i=0; i<4; i++) {
      int nx = x+dx[i], ny = y+dy[i];
      if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if(dist[nx][ny][w]) continue;
      if(!map[nx][ny]) {
        dist[nx][ny][w] = dist[x][y][w] + 1;
        Info ninfo = {nx, ny, w};
        route.push(ninfo);
      } else if(!w) {
        dist[nx][ny][1] = dist[x][y][w] + 1;
        Info ninfo = {nx, ny, 1};
        route.push(ninfo);
      }
    }
  }
  return -1;
}

int main() {
  scanf("%d %d", &N, &M);
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      scanf("%1d", &map[i][j]);
    }
  }
  printf("%d\n", bfs());
  return 0;
}
