#include <iostream>
#include <cmath>
using namespace std;
int main() {
  int N, temp, ans, i;
  cin>>N;
  ans = N;
  for(i=0; i<N; i++) {
    if(cin>>temp && !!temp) {
      if(temp == 1) {
        --ans;
        continue;
      }
      for(int j=2; j<=sqrt(temp); j++) {
        if(temp % j == 0) {
          --ans;
          break;
        }
      }
    }
  }
  cout<<ans<<"\n";
  return 0;
}
