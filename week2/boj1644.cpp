#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int N, ans = 0, sum = 0;
  bool chk;
  cin>>N;
  bool pn[N+1];
  for(int i=2; i<=N; i++) pn[i] = true;
  for(int i=2; i<=sqrt(N); i++) {
    if(pn[i] == false) continue;
    for(int j=i+i; j<=N; j+=i) {
      pn[j] = false;
    }
  }
  for(int i=2; i<=N; i++) {
    sum = 0;
    if(pn[i]) {
      sum += i;
      if(sum == N) {
        ans++;
        continue;
      }
      for(int j=i+1; j<=N; j++) {
        if(pn[j]) {
          sum += j;
          if(sum == N) {
            ans++;
            break;
          }
          else if(sum > N) break;
        }
      }
    }
  }
  cout<<ans<<"\n";
  return 0;
}
