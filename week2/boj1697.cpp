#include <iostream>
#include <queue>
#include <limits.h>

using namespace std;

int min_time = INT_MAX;
int N, K;
const int MAX = 100001;
bool chk[MAX] = {false};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>N>>K;
  queue< pair<int, int> > q;
  q.push(make_pair(N, 0));
  chk[N] = true;
  
  while(!q.empty()) {
    int cur = q.front().first;
    int time = q.front().second;
    q.pop();
    
    if(cur == K) {
      if(min_time > time) min_time = time;
      break;
    }
    if(cur-1 >= 0 && !chk[cur-1]) {
      q.push(make_pair(cur-1, time+1));
      chk[cur-1] = true;
    }
    if(cur+1 < MAX && !chk[cur+1]) {
      q.push(make_pair(cur+1, time+1));
      chk[cur-1] = true;
    }
    if(cur*2 < MAX && !chk[cur*2]) {
      q.push(make_pair(cur*2, time+1));
      chk[cur-1] = true;
    }
  }
  cout<<min_time<<"\n";
  return 0;
}
