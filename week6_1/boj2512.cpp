#include <iostream>

using namespace std;

int N;
long long M;

long long alloc(int *budget, int limit){
  long long accum = 0;
  for(int i=0; i<N; i++) {
    if(budget[i] > limit) {
      accum += limit;
    } else {
      accum += budget[i];
    }
  }
  return accum;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>N;
  int budget[N], maxBudget = 0, ans = -1;
  for(int i=0; i<N; i++) {
    cin>>budget[i];
    maxBudget = max(maxBudget, budget[i]);
  }
  cin>>M;
  int start = 0, end = maxBudget;
  while(start <= end) {
    int mid = (start + end) / 2;
    long long temp = alloc(budget, mid);
    if(temp > M) {
      end = mid - 1;
    } else {
      if(mid > ans) ans = mid;
      start = mid + 1;
    }
  }
  cout<<ans<<"\n";
  return 0;
}
