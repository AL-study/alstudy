#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N, temp;
  int div[N];
  cin>>N;
  for(int i=0; i<N; i++) {
    cin>>temp;
    div[i] = temp;
  }
  sort(div, div+N);
  cout<<div[0]*div[N-1]<<"\n";
  return 0;
}
