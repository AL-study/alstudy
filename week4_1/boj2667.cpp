#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int N, cnt = 0;
int comlex[625] = {0}, apart[25][25];
static int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
queue<pair<int, int> > q;
priority_queue<int, vector<int>, greater<int> > pq;

void dfs(int x, int y, int key) {
  apart[x][y] = key;
  for(int i=0; i<4; i++) {
    int nx = x+dx[i], ny = y+dy[i];
    if(nx < 0 || nx >= N || ny < 0 || ny >= N || apart[nx][ny] != 1) continue;
    dfs(nx, ny, key);
  }
}

int main(){
  int cnt = 0;
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      scanf("%1d", &apart[i][j]);
    }
  }
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      if(apart[i][j] == 1) {
        cnt++;
        dfs(i, j, cnt+1);
      }
    }
  }
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      if(apart[i][j] > 1) {
        comlex[apart[i][j]-2]++;
      }
    }
  }
  sort(comlex, comlex+cnt);
  printf("%d\n", cnt);
  for(int i=0; i<cnt; i++) {
    printf("%d\n", comlex[i]);
  }
  return 0;
}
