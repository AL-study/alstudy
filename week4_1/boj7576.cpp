#include <iostream>
#include <queue>

using namespace std;

int M,N;
int days[1001][1001] = {0}, visted[1001][1001] = {0};
static int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>M>>N;
  bool brk = false;
  int tomato[N][M], maxDay = 0;
  queue<pair<int, int> > q;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      cin>>tomato[i][j];
      if(tomato[i][j] > 0) {
        q.push(make_pair(i, j));
        visted[i][j] = 1;
      }
    }
  }
  while(!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    for(int i=0; i<4; i++) {
      int nx = x+dx[i], ny = y+dy[i];
      if(nx < 0 || nx >= N || ny <0 || ny >= M || tomato[x][y] <= 0) continue;
      else if(tomato[nx][ny] == 0) {
        if(visted[nx][ny]) days[nx][ny] = min(days[x][y]+1, days[nx][ny]);
        else days[nx][ny] = days[x][y] + 1;
        tomato[nx][ny] = 1;
        visted[nx][ny] = 1;
        q.push(make_pair(nx, ny));
      }
    }
  }
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      if(!brk && tomato[i][j] == 0) {
        cout<<"-1\n";
        brk = true;
      }
      else {
        maxDay = max(maxDay, days[i][j]);
      }
    }
  }
  if(!brk) cout<<maxDay<<"\n";
  return 0;
}
