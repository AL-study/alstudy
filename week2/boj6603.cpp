#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void dfs(int start, int depth, int k, int* entire, int* cur) {
  if(depth == 6) {
    for(int i=0; i<depth; i++) printf("%d ", cur[i]);
    printf("\n");
  } else {
    for(int i=start; i<k; i++) {
      cur[depth] = entire[i];
      dfs(i+1, depth+1, k, entire, cur);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int N, i, j;
  int total[12], cur[12];
  while(cin>>N && !!N) {
    for(i=0; i<N; i++) {
      cin>>total[i];
    }
    dfs(0, 0, N, total, cur);
    printf("\n");
  }
  return 0;
}
