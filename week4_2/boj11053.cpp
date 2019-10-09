#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int N;
  cin>>N;
  int seq[N+1], dp[N+1];
  for(int i=1; i<=N; i++) {
    cin>>seq[i];
    dp[i] = 1;
    for(int j=1; j<i; j++) {
      if(seq[i] > seq[j] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
      }
    }
  }
  cout<<*max_element(dp+1, dp+N+1)<<"\n";
  return 0;
}
