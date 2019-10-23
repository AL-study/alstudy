#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
  int T, N, M;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > bound;
  cin>>T;
  for(int i=0; i<T; i++) {
    cin>>N>>M;
    int cnt = 0;
    bool book[1001] = {false};
    for(int j=0; j<M; j++) {
      int lb, ub;
      cin>>lb>>ub;
      bound.push(make_pair(ub, lb));
    }
    while(!bound.empty()) {
      int lb = bound.top().second;
      int ub = bound.top().first;
      bound.pop();
      for(int k=lb; k<=ub; k++) {
        if(!book[k]) {
          book[k] = true;
          cnt++;
          break;
        }
      }
    }
    cout<<cnt<<"\n";
  }
  return 0;
}
