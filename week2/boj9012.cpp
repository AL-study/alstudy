#include <iostream>
#include <stdio.h>
#include <vector>

#define lp '('
#define rp ')'

using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  int N, i, j, len;
  string temp;
  vector<int> lps, rps;
  cin>>N;
  for(i=0; i<N; i++) {
    lps.clear();
    rps.clear();
    cin>>temp;
    len = temp.length();
    for(j=0; j<len; j++) {
      if(temp[j] == lp) lps.push_back(j);
      else if(temp[j] == rp) rps.push_back(j);
    }
    len = lps.size();
    if(lps.size() == rps.size()) {
      for(j=0; j<len; j++) {
        if(j == len-1 && lps[j] < rps[j]) {
          printf("YES\n");
          continue;
        }
        if(lps[j] > rps[j]) {
          printf("NO\n");
          break;
        }
      }
    } else printf("NO\n");

  }
  return 0;
}
