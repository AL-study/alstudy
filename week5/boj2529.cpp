#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, cnt;
  cin>>N;
  char ieq[N];
  int maxPerm[N+1], minPerm[N+1];
  for(int i=0; i<=N; i++) {
    if(i < N) cin>>ieq[i];
    minPerm[i] = i;
    maxPerm[i] = 9-i;
  }
  do {
    cnt = 0;
    for(int i=0; i<N; i++) {
      if(ieq[i] == '>') {
        if(maxPerm[i] <= maxPerm[i+1]) break;
        else ++cnt;
      } else {
        if(maxPerm[i] >= maxPerm[i+1]) break;
        else ++cnt;
      }
    }
    if(cnt == N) {
      for(int i=0; i<=N; i++) {
        cout<<maxPerm[i];
      }
      cout<<"\n";
      break;
    }
  }while(prev_permutation(maxPerm, maxPerm+N+1));
  
  do {
    cnt = 0;
    for(int i=0; i<N; i++) {
      if(ieq[i] == '>') {
        if(minPerm[i] <= minPerm[i+1]) break;
        else ++cnt;
      } else {
        if(minPerm[i] >= minPerm[i+1]) break;
        else ++cnt;
      }
    }
    if(cnt == N) {
      for(int i=0; i<=N; i++) {
        cout<<minPerm[i];
      }
      cout<<"\n";
      break;
    }
  }while(next_permutation(minPerm, minPerm+N+1));
  
  return 0;
}
