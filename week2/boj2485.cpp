#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
  return b? gcd(b, a%b) : a;
}
int main() {
  int N, pre = 0, curr, ans = 0;
  vector<int> dif, gcds;
  cin>>N;
  for(int i=0; i<N; i++) {
    cin>>curr;
    if(i) dif.push_back(abs(curr-pre));
    pre = curr;
  }
  for(int i=1; i<dif.size(); i++) gcds.push_back(gcd(dif[i-1], dif[i]));
  int min = *min_element(gcds.begin(), gcds.end());
  for(int i=0; i<dif.size(); i++) ans += (dif[i]/min - 1);
  cout<<ans<<"\n";
  return 0;
}
