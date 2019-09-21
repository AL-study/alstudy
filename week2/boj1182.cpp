#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;
int s, N, ans = 0;
void bf(int *arr, int idx, int sum) {
  if(idx==N){
    if(sum==s)ans++;
    return;
  }
  bf(arr, idx+1, sum+arr[idx]);
  bf(arr, idx+1, sum);
  }
int main() {
  ios_base::sync_with_stdio(false);
  int sum, i;
  vector<int> ret;
  cin>>N>>s;
  int arr[N];
  for(i=0; i<N; i++) cin>>arr[i];
  bf(arr, 0, 0);
  if(s == 0) ans--;
  printf("%d\n", ans);
  return 0;
}
