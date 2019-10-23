#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
  int N, temp, sum = 0;
  priority_queue<int, vector<int>, greater<int> > pq;
  cin>>N;
  for(int i=0; i<N; i++) {
    cin>>temp;
    pq.push(temp);
  }
  while(pq.size() > 1) {
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    pq.push(a+b);
    sum += a+b;
  }
  cout<<sum<<"\n";
  return 0;
}
