#include <iostream>
#include <cstring>
using namespace std;

const int MAX =  1e+5 + 1;
int T, N, cnt, team[MAX];
bool visited[MAX], done[MAX];

void dfs(int node){
  visited[node] = 1;
  int next = team[node];
  if(!visited[next]) {
    dfs(next);
  } else if(!done[next]) {
    for(int i=next; i!=node; i=team[i]) {
      cnt--;
    }
    cnt--;
  }
  done[node] = 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>T;
  for(int i=0; i<T; i++) {
    memset(visited, 0, sizeof(visited));
    memset(done, 0, sizeof(done));
    cin>>N;
    cnt = N;
    for(int j=1; j<=N; j++) {
      cin>>team[j];
    }
    for(int j=1; j<=N; j++) {
      dfs(j);
    }
    cout<<cnt<<"\n";
  }
  return 0;
}
