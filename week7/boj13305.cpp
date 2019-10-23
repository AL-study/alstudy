#include <stdio.h>

int main(){
  int N, dist[100001];
  long cost, temp = 1e+9;
  long long ans = 0;
  scanf("%d", &N);
  for(int i=0; i<N-1; i++) {
    scanf("%d", &dist[i]);
  }
  for(int i=0; i<N-1; i++) {
    scanf("%d", &cost);
    if(temp > cost) temp = cost;
    ans += temp * dist[i];
  }
  printf("%lld\n", ans);
  return 0;
}
