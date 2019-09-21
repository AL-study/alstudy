#include <iostream>
#include <cmath>
using namespace std;
int main() {
  int start, end;
  bool chk;
  cin>>start>>end;
  for(int i=start; i<=end; i++) {
    chk = true;
    for(int j=2; j<=sqrt(i); j++) {
      if(i % j == 0) {
        chk = false;
        break;
      }
    }
    if(chk && i > 1) cout<<i<<"\n";
  }
  return 0;
}
