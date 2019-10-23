#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N, M;
bool brk = false, chk = false;
queue<pair<int, int> > route;
vector<vector<int> > map, visited, moving;


void bfs() {
  route.push(make_pair(0,0));
  visited[0][0] = 1;
  moving[0][0] = 1;
  int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
  while(!route.empty()) {
    pair<int, int> curr = route.front();
    int x = curr.first, y = curr.second;
    route.pop();
    cout<<x<<" "<<y<<"\n";
    if(map[x][y]) continue;
    if(x == N-1 && y == M-1) {
      printf("%d\n", moving[x][y]);
      return;
    }
    for(int i=0; i<4; i++) {
      int nx = x+dx[i], ny = y+dy[i];
      if(nx >= 0 && nx < N && ny >= 0 && y < M) {
        if(visited[nx][ny] == 0) {
          if(visited[nx][ny]) {
            chk = true;
            map[nx][ny] = 0;
          }
          route.push(make_pair(nx, ny));
          visited[nx][ny] = 1;
          moving[nx][ny] = moving[x][y] + 1;
        }
      }
    }
    if(chk) brk = true;
  }
  printf("-1\n");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int temp;
  vector<int> row;
  cin>>N>>M;
  for(int i=0; i<N; i++) {
    row.clear();
    row.assign(M,0);
    visited.push_back(row);
    moving.push_back(row);
  }
  for(int i=0; i<N; i++) {
    row.clear();
    for(int j=0; j<M; j++) {
      scanf("%1d", &temp);
      row.push_back(temp);
    }
    map.push_back(row);
  }
  bfs();
  return 0;
}
