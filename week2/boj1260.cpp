#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N, M, start;
vector<bool> chk;
map<int, vector<int> > line;
queue<int> ret;

void dfs(int key) {
  if(chk[key-1]) return;
  else cout<<key<<" ";
  chk[key-1] = true;
  if(!line[key].size()) return;
  for(int i=0; i<line[key].size(); i++) dfs(line[key][i]);
}

void bfs() {
  queue<int> q;
  q.push(start);
  while(!q.empty()) {
    int temp = q.front();
    q.pop();
    if(!chk[temp-1]) {
      chk[temp-1] = true;
      ret.push(temp);
      for(int i=0; i<line[temp].size(); i++) q.push(line[temp][i]);
    }
  }
}

int main() {
  int p1, p2;
  cin>>N>>M>>start;
  for(int i=0; i<N; i++) chk.push_back(false);
  for(int i=0; i<M; i++) {
    cin>>p1>>p2;
    line[p1].push_back(p2);
    line[p2].push_back(p1);
  }
  for(int i=0; i<line.size(); i++) {
    sort(line[i].begin(), line[i].end());
  }
  dfs(start);
  cout<<"\n";
  for(int i=0; i<N; i++) chk[i] = false;
  bfs();
  for(int i=0; ret.size(); i++) {
    cout<<ret.front()<<" ";
    ret.pop();
  }
  cout<<"\n";
  return 0;
}
