#include <iostream>
#include <cmath>

using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  bool chk = false;
  bool pn[1000001];
  for(int i=2; i<1000001; i++) pn[i] = true;
  for(int i=2; i<=sqrt(1000001); i++) {
    if(!pn[i]) continue;
    for(int j=i+i; j<=1000001; j+=i) pn[j] = false;
  }
  while(cin>>N && !!N) {
    for(int i=2; i<=N/2; i++) {
      chk = false;
      if(pn[i] && pn[N-i]) {
        cout<<N<<" = "<<i<<" + "<<N-i<<"\n";
        chk = true;
        break;
      }
    }
    if(!chk) cout<<"Goldbach's conjecture is wrong.\n";
  }
  return 0;
}
