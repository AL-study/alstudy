#include <iostream>
#include <queue>

using namespace std;

int M,N,H;
int days[101][101][101] = {0}, visted[101][101][101] = {0};
static int dx[6] = {-1, 0, 0, 1, 0, 0}, dy[6] = {0, -1, 1, 0, 0, 0}, dz[6]={0, 0, 0, 0, -1, 1};

struct Map{
  int x,y,z;
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>M>>N>>H;
  bool brk = false;
  int tomato[N][M][H], maxDay = 0;
  queue<Map> q;
  for(int k=0; k<H; k++) {
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        cin>>tomato[i][j][k];
        if(tomato[i][j][k] > 0) {
          Map m = {i, j, k};
          q.push(m);
          visted[i][j][k] = 1;
        }
      }
    }
  }
  while(!q.empty()) {
    int x = q.front().x, y = q.front().y, z = q.front().z;
    q.pop();
    for(int i=0; i<6; i++) {
      int nx = x+dx[i], ny = y+dy[i], nz = z+dz[i];
      if(nx < 0 || nx >= N || ny <0 || ny >= M || nz < 0 || nz >= H || tomato[x][y][z] <= 0) continue;
      else if(tomato[nx][ny][nz] == 0) {
        if(visted[nx][ny][nz]) days[nx][ny][nz] = min(days[x][y][z]+1, days[nx][ny][nz]);
        else days[nx][ny][nz] = days[x][y][z] + 1;
        tomato[nx][ny][nz] = 1;
        visted[nx][ny][nz] = 1;
        Map m = {nx, ny, nz};
        q.push(m);
      }
    }
  }
  for(int k=0; k<H; k++) {
    for(int i=0; i<N; i++) {
      for(int j=0; j<M; j++) {
        if(!brk && tomato[i][j][k] == 0) {
         cout<<"-1\n";
         brk = true;
        } else {
         maxDay = max(maxDay, days[i][j][k]);
        }
      }
    }
  }
  if(!brk) cout<<maxDay<<"\n";
  return 0;
}
