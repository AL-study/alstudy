#include <iostream>
#include <limits.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int N, cn, temp;
int main() {
  ios_base::sync_with_stdio(false);
  vector< pair<int, int> > chicken, home;
  vector<int> bit;
  int min, cd, ans = INT_MAX;
  cin>>N>>cn;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      if(cin>>temp && !!temp) {
        if(temp == 1) home.push_back(make_pair(i, j));
        else if(temp == 2) chicken.push_back(make_pair(i, j));
      }
    }
  }
  bit.assign(cn, 1);
  for(int i=0; i<chicken.size()-cn; i++) bit.push_back(0);
  do {
    cd = 0;
    for(int i=0; i<home.size(); i++) {
      min = INT_MAX;
      for(int j=0; j<chicken.size(); j++) {
        if(bit[j]) {
          int td =abs(home[i].first-chicken[j].first) + abs(home[i].second-chicken[j].second);
          if(td < min) min = td;
        }
      }
      cd += min;
    }
    if(ans > cd) ans = cd;
  } while(prev_permutation(bit.begin(), bit.end()));
  printf("%d", ans);
  return 0;
}
