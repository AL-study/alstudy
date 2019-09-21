#include <iostream>
#include <stdio.h>
<<<<<<< HEAD
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
=======

int brute_force(int* arr, int s, int sum) {
  if(s == sum) return 1;
  else {
    
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int N, s, sum, i;
  cin>>N>>s;
  int arr[N];
  for(i=0; i<N; i++) cin>>arr[i];
  
>>>>>>> 846ffa99965671b9d4e41fe526372401e315d70e
}
