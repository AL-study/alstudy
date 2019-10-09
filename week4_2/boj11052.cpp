#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N;
  cin>>N;
  int card[N+1], amount[N+1];
  for(int i=1; i<=N; i++) {
    cin>>card[i];
    amount[i] = card[i];
  }
  amount[1] = card[1];
  for(int i=2; i<=N; i++) {
    for(int j=1; j<i; j++) {
      amount[i] = max(amount[i], amount[j]+amount[i-j]);
    }
  }
  cout<<amount[N]<<"\n";
  return 0;
}
