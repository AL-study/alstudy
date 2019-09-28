#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T, temp;
  vector< pair<int, int> > ret;
  
  ret.push_back(make_pair(1,0));
  ret.push_back(make_pair(0,1));
  
  for(int i=2; i<=40; i++) {
    ret.push_back(make_pair(ret[i-1].first+ret[i-2].first, ret[i-1].second+ret[i-2].second));
  }
  
  cin>>T;
  for(int i=0; i<T; i++) {
    cin>>temp;
    cout<<ret[temp].first<<" "<<ret[temp].second<<"\n";
  }
  return 0;
}
