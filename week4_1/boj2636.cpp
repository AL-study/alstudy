#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

enum {
  AIR = 0,
  CHEESE,
  PREAIR
};

int W, H, hour, cnt;
int cheese[101][101];
bool chk[101][101];
queue<pair<int, int> > q;
const int dist[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(){
  q.push(make_pair(0, 0));
  chk[0][0] = 1;
  while(!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop();
    for(int i=0; i<4; i++) {
      int nx = x + dist[i][0], ny = y + dist[i][1];
      if(nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
      else{
        if(!chk[nx][ny]) {
          if(cheese[nx][ny] == AIR) {
            chk[nx][ny] = 1;
            q.push(make_pair(nx, ny));
          }
          else if(cheese[nx][ny] == CHEESE) {
            cheese[nx][ny] = PREAIR;
            cnt++;
          }
        }
      }
    }
  }
}

void make_air() {
  for(int i=0; i<W; i++) {
    for(int j=0; j<H; j++) {
      if(cheese[i][j] == PREAIR) cheese[i][j] = AIR;
    }
  }
}

bool check_air(){
  for(int i=0; i<W; i++) {
    for(int j=0; j<H; j++) {
      if(cheese[i][j] != AIR) return false;
    }
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>W>>H;
  for(int i=0; i<W; i++) {
    for(int j=0; j<H; j++) {
      cin>>cheese[i][j];
    }
  }
  while(!check_air()){
    cnt = 0;
    memset(chk, 0, sizeof(chk));
    bfs();
    make_air();
    hour++;
  }
  cout<<hour<<"\n"<<cnt<<"\n";
  return 0;
}
