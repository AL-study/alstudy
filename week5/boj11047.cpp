#include <iostream>

using namespace std;

int main(){
  int N, K, remain, cnt = 0;
  cin>>N>>K;
  remain = K;
  int coin[N];
  for(int i=0; i<N; i++) {
    cin>>coin[i];
  }
  for(int i=N-1; i>=0; i--) {
    if(remain == 0) break;
    if(remain >= coin[i] && (int) remain / coin[i]) {
      cnt += (int) remain / coin[i];
      remain -= coin[i]*(int)(remain/coin[i]);
    }
  }
  cout<<cnt<<"\n";
  return 0;
}
