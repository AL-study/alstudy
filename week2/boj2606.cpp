#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int main() {
  map<int, vector<int> > conn;
  vector<bool> chk;
  queue<int> q;
  int N, P, ans = 0;
  cin>>N>>P;
  chk.assign(N+1, false);
  for(int i=0; i<P; i++) {
    int c1, c2;
    cin>>c1>>c2;
    conn[c1].push_back(c2);
    conn[c2].push_back(c1);
  }
  for(int i=1; i<=N; i++) sort(conn[i].begin(), conn[i].end());
  for(int i=0; i<conn[1].size(); i++) q.push(conn[1][i]);
  
  while(!q.empty()) {
    int key = q.front();
    q.pop();
    
    if(!chk[key]) {
      chk[key] = true;
      ans++;
      for(int i=0; i<conn[key].size(); i++) q.push(conn[key][i]);
    }
  }
  ans--;
  cout<<ans<<"\n";
  return 0;
}
