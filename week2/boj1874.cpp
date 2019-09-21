#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int i, N, temp, num = 1;
  stack<int> input;
  vector<char> ret;
  cin>>N;
  int arr[N];
  for(i=0; i<N; i++) cin>>arr[i];
  i=0;
  while(num <= N) {
    if(input.empty() || input.top() != arr[i]) {
      input.push(num++);
      ret.push_back('+');
    }
    else {
      input.pop();
      ret.push_back('-');
      i++;
    }
  }
  while(!input.empty()) {
    if(arr[i] == input.top()) {
      input.pop();
      ret.push_back('-');
      i++;
    }
    else break;
  }
  if(!input.empty()) printf("NO\n");
  else {
    int size = ret.size();
    for(i=0; i<size; i++) printf("%c\n", ret[i]);
  }
  return 0;
}
