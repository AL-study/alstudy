#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, temp;
  cin>>N;
  vector<int> wine, sum;
  for(int i=0; i<N; i++) {
    cin>>temp;
    wine.push_back(temp);
  }
  if(N == 1) printf("%d\n", wine[0]);
  else if(N == 2) printf("%d\n", wine[0]+wine[1]);
  else {
    sum.push_back(wine[0]);
    sum.push_back(wine[0]+wine[1]);
    sum.push_back(max(sum[1], max(wine[1]+wine[2], wine[0]+wine[2])));
    sum.push_back(max(sum[2],max(sum[0]+wine[2]+wine[3], sum[1]+wine[3])));
    for(int i=4; i<N; i++) {
      sum.push_back(max(sum[i-4]+wine[i-2]+wine[i-1],max(sum[i-2]+wine[i], sum[i-3]+wine[i-1]+wine[i])));
    }
    printf("%d\n", *max_element(sum.begin(), sum.end()));
  }
  return 0;
}
