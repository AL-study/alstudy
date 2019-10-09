#include <iostream>

using namespace std;

int main() {
  int tile[1001], N;
  tile[1] = 1;
  tile[2] = 3;
  for(int i=3; i<= 1000; i++) {
    tile[i] = (tile[i-1] + tile[i-2]*2) % 10007;
  }
  cin>>N;
  cout<<tile[N]<<"\n";
  return 0;
}
