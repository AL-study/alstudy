#include <iostream>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, M, dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
  char temp;
  cin>>N>>M;
  int point[N][M], chk[N][M];
  
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      cin>>temp;
      point[i][j] = 0;
      chk[i][j] = temp-'0';
    }
  }
  point[0][0] = 1;
  queue< pair<int, int> > q;
  q.push(make_pair(0,0));
  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    chk[x][y] = -1;
    if(x == N-1 && y == M-1) break;
    for(int i=0; i<4; i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx<0 || nx>N-1 || ny<0 || ny>M-1 || chk[nx][ny]<=0) continue;
      if(chk[nx][ny]) {
        q.push(make_pair(nx,ny));
        point[nx][ny]=point[x][y]+1;
        chk[nx][ny] = -1;
      }
    }
  }
  cout<<point[N-1][M-1]<<"\n";
  return 0;
}
