#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int i, N, pos;
  vector<int>::iterator iter;
  vector<int> init, ret;
  cin>>N>>pos;
  for(i=0; i<N; i++) init.push_back(i+1);
  iter = init.begin();
  while(!init.empty()) {
    for(i=1; i<pos; i++) {
      iter++;
      if(iter == init.end()) iter = init.begin();
    }
    ret.push_back(*iter);
    iter = init.erase(iter);
    if(iter == init.end()) iter = init.begin();
  }
  printf("<");
  int size = ret.size();
  for(i=0; i<size; i++) {
    printf("%d", ret[i]);
    if(i<size-1) printf(", ");
  }
  printf(">");
  return 0;
}
