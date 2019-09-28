#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int N, cnt = 0;
  vector<int> ret;
  ret.push_back(0);
  ret.push_back(0);
  ret.push_back(1);
  ret.push_back(1);
  for(int i=4; i<=1000000; i++) {
    if(!(i%3) && !(i%2)) {
      ret.push_back(min(min(ret[i/3], ret[i/2]), ret[i-1])+1);
    } else if(!(i%3)) {
      ret.push_back(min(ret[i/3], ret[i-1])+1);
    } else if(!(i%2)) {
      ret.push_back(min(ret[i/2], ret[i-1])+1);
    } else {
      ret.push_back(ret[i-1]+1);
    }
  }
  cin>>N;
  cout<<ret[N]<<"\n";
}
