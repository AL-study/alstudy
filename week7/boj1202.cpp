#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, K;
  long long price = 0;
  cin>>N>>K;
  priority_queue<pair<int, int> > gem;
  multiset<int> bag;
  for(int i=0; i<N; i++) {
    int m, v;
    cin>>m>>v;
    gem.push(make_pair(v,m));
  }
  for(int i=0; i<K; i++) {
    int temp;
    cin>>temp;
    bag.insert(temp);
  }
  while(!gem.empty()) {
    pair<int, int> top = gem.top();
    auto it = bag.lower_bound(top.second);
    gem.pop();
    if(it == bag.end()) {
      continue;
    }
    price += top.first;
    bag.erase(it);
  }
  cout<<price<<"\n";
  return 0;
}
