#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, L, P, cnt = 0, it = 0;
  cin>>N;
  pair<int, int> gas[N];
  priority_queue<int> pq;
  for(int i=0; i<N; i++) {
    cin>>gas[i].first>>gas[i].second;
  }
  cin>>L>>P;
  sort(gas, gas+N);
  while(P < L) {
    while(gas[it].first <= P) {
      if(it == N) break;
      pq.push(gas[it].second);
      it++;
    }
    if(pq.empty()) break;
    cnt++;
    P += pq.top();
    pq.pop();
  }
  cout<<(P >= L ? cnt : -1)<<"\n";
  return 0;
}
