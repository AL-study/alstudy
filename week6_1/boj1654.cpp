#include <iostream>

using namespace std;

int N, K;

long long cutting(int *lan, int length) {
  long long accum = 0;
  for(int i=0; i<N; i++) {
    accum += lan[i] / length;
  }
  return accum;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>N>>K;
  int lan[N], length = 0, ans = 0;
  for(int i=0; i<N; i++) {
    cin>>lan[i];
    length = max(length, lan[i]);
  }
  long long start = 1, end = length;
  while(start <= end) {
    long long mid = (start + end) / 2;
    long long temp = cutting(lan, mid);
    if(temp < K) {
      end = mid - 1;
    } else{
      start = mid + 1;
      if(ans < mid) ans = mid;
    }
  }
  cout<<ans<<"\n";
  return 0;
}
