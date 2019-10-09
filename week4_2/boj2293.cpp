#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, k, temp;
  int val[101], cnt[10001] = {1};
  cin>>n>>k;
  for(int i=1; i<=n; i++) {
    cin>>temp;
    val[i] = temp;
  }
  cnt[0] = 1;
  for(int i=1; i<=n; ++i) {
    for(int j=val[i]; j<=k; ++j) {
      cnt[j] += cnt[j-val[i]];
    }
  }
  cout<<cnt[k]<<"\n";
  return 0;
}
