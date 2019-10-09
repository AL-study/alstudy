#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N, temp;
  cin>>N;
  int num[N], dp[N];
  for(int i=0; i<N; i++) {
    cin>>temp;
    num[i] = temp;
  }
  dp[0] = num[0];
  for(int i=1; i<N; i++) {
    dp[i] = max(dp[i-1]+num[i], num[i]);
  }
  cout<<*max_element(dp, dp+N)<<"\n";
  return 0;
}
