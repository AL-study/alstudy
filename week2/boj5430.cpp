#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int N, T, len, i, j, cnt, save, rever;
  char temp;
  deque<int> arr;
  deque<int>::iterator it;
  string cmd;
  bool err, num;
  
  cin>>T;
  for(i=0; i<T; i++) {
    arr.clear();
    cnt = save = rever = 0;
    err = num = rever = false;
    cin>>cmd>>N;
    len = cmd.length();
    if(N == 0) {
      for(j=0; j<2; j++) cin>>temp;
    }
    while(cnt < N) {
      cin>>temp;
      if(temp >= '0' && temp <= '9') {
        if(num) save = save * 10 + temp - '0';
        else save += temp - '0';
        num = true;
      }
      else {
        if(num) {
          arr.push_back(save);
          save = 0;
          num = false;
          cnt++;
        }
      }
    }
    for(j=0; j<len; j++) {
      if(cmd[j] == 'R') rever++;
      else if(cmd[j] == 'D' && arr.size()) {
        if(rever % 2) arr.pop_back();
        else arr.pop_front();
      }
      else {
        err = true;
        break;
      }
    }
    if(err) printf("error\n");
    else {
      printf("[");
      if(rever % 2) {
        for(j=arr.size()-1; j>=0; j--) {
          printf("%d", arr[j]);
          if(j) printf(",");
        }
      }
      else {
        for(it=arr.begin(); it!=arr.end(); it++) {
          printf("%d", *it);
          if(++it != arr.end()) printf(",");
          --it;
        }
      }
      printf("]\n");
    }
  }
  return 0;
}
