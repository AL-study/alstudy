#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
#define MM 2e6
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T, a, b;
  vector<bool> pn;
  for(int i=0; i<=MM; i++) pn.push_back(true);
  for(int i=2; i<MM; i++) {
    if(!pn[i]) continue;
    for(int j=i+i; j<=MM; j+=i) pn[j] = false;
  }
  bool chk = false;
  cin>>T;
  for(int i=0; i<T; i++) {
    cin>>a>>b;
    chk = false;
    if(a == 1 && b == 1) cout<<"NO\n";
    else if(a%2^b%2) {
      for(int i=2; i<=a+b/2; i++) {
        if(pn[i] && pn[a+b-i]) cout<<"YES\n";
        chk = true;
        break;
      }
      if(!chk) cout<<"NO\n";
    }
    else cout<<"YES\n";
  }
  return 0;
}
