#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int T, N, i, dp[11];
  cin>>T;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  for(i=4; i<11; i++) dp[i] = dp[i-1]+ dp[i-2] + dp[i-3];
  for(i=0; i<T; i++) {
    cin>>N;
    printf("%d\n", dp[N]);
  }
  return 0;
}
