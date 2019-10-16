#include <iostream>
#include <stdio.h>

using namespace std;

int N;

long long ps(int *tree, int height) {
  long long accum = 0;
  for(int i=0; i<N; i++) {
    if(tree[i] > height) accum += (tree[i]-height);
  }
  return accum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int M, height = -1;
  cin>>N>>M;
  int tree[N];
  for(int i=0; i<N; i++) {
    cin>>tree[i];
    height = max(height, tree[i]);
  }
  int start = 0, end = height, result=0;
  while(start <= end) {
    int mid = (start+end)/2;
    long long temp = ps(tree, mid);
    if(temp >= M) {
      result=max(mid,result);
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  printf("%d\n", result);
  return 0;
}
