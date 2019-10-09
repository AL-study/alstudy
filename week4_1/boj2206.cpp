#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int N, M, cnt = 0;
bool brk = false;
queue<pair<int, int> > route;
vector<vector<int> > map, visited;


void bfs() {
  route.push(make_pair(0,0));
  int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
  while(!route.empty()) {
    pair<int, int> curr = route.front();
    route.pop();
    int x = curr.first, y = curr.second;
    if(visited[x][y]) continue;
    if(brk && map[x][y]) continue;
    else if(map[x][y]) brk = true;
    visited[x][y] = 1;
    if(x == N-1 && y == M-1) {
      printf("%d\n", cnt);
      return;
    }
    for(int i=0; i<4; i++) {
      if(x + dx[i] >= 0 && x + dx[i] < N && y + dy[i] >= 0 && y + dy[i] < M) {
        route.push(make_pair(x+dx[i], y+dy[i]));
      }
    }
    cnt++;
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
