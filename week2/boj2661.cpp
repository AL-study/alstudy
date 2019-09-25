#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int N;
vector<int> ret;
bool chk(vector<int> str) {
  for(int i=1; i<=str.size()/2; i++) {
    int chk = 0;
    for(int j=0; j<str.size()-i; j++) {
      if(str[j] == str[j+i]) chk++;
      else chk = 0;
      if(chk == i) return false;
    }
  }
  return true;
}
void dfs(vector<int> str) {
  if(str.size() == N) {
    if(chk(str)) {
      for(int i=0; i<str.size(); i++) printf("%d", str[i]);
      exit(0);
    }
    else return;
  }
  for(int i=1; i<=3; i++) {
    str.push_back(i);
    if(!chk(str)) {
      str.pop_back();
      continue;
    }
    dfs(str);
    str.pop_back();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin>>N;
  dfs(ret);
  return 0;
}
