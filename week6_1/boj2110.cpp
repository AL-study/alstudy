#include <iostream>
#include <algorithm>
 
using namespace std;

int N, C;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>N>>C;
  int home[N];
  for(int i=0; i<N; i++) {
    cin>>home[i];
  }
  sort(home, home+N);
  int left = 1, right = home[N-1] - home[0], ans;
  while(left <= right) {
    int mid = (left + right) / 2;
    int cnt = 1;
    int start = home[0];
    for(int i=1; i<N; i++) {
      if(home[i] - start >= mid) {
        cnt++;
        start = home[i];
      }
    }
    if(cnt >= C) {
      ans = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  cout<<ans<<"\n";
  return 0;
}
