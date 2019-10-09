#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> tile;
  int N;
  cin>>N;
  tile.push_back(1);
  tile.push_back(2);
  for(int i=2; i<N; i++) {
    tile.push_back((tile[i-1]+tile[i-2])%10007);
  }
  cout<<tile[N-1]<<"\n";
  return 0;
}
