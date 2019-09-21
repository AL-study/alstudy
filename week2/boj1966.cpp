#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  vector< vector<int> > input;
  vector<int> order, location;
  int test_case, N, i, j, temp, size, max, ans, front;
  cin>>test_case;
  for(i=0; i<test_case; i++) {
    cin>>N>>temp;
    location.push_back(temp);
    order.clear();
    for(j=0; j<N; j++) {
      cin>>temp;
      order.push_back(temp);
    }
    input.push_back(order);
  }
  for(i=0; i<test_case; i++) {
    size = input[i].size();
    ans = 0;
    temp = location[i];
    while(1) {
      max = *max_element(input[i].begin(), input[i].end());
      front = input[i].front();
      input[i].erase(input[i].begin());
      if(max > front) {
        input[i].push_back(front);
        if(temp) temp--;
        else temp = input[i].size() - 1;
      }
      else {
        ans++;
        if(temp) temp--;
        else break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
