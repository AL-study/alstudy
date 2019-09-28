#include <iostream>

using namespace std;

int main() {
  int num[501][501];
  int N, temp;
  cin>>N;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=i; j++) {
      cin>>temp;
      num[i][j] = temp;
    }
  }
  
  for(int i=N; i>1; i--) {
    for(int j=1; j<N; j++) {
      num[i-1][j] = max(num[i][j]+num[i-1][j], num[i][j+1]+num[i-1][j]);
    }
  }
  cout<<num[1][1]<<"\n";
  return 0;
}
