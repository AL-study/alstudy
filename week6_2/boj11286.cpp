#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

struct cmp {
  bool operator()(int v1, int v2) {
    if(abs(v1) == abs(v2)) return v1 > v2;
    else return abs(v1) > abs(v2);
  }
};

int main(){
  int N, temp;
  cin>>N;
  priority_queue<int, vector<int>, cmp> pq;
  for(int i=0; i<N; i++) {
    cin>>temp;
    if(temp) pq.push(temp);
    else if(!pq.empty()) {
      cout<<pq.top()<<"\n";
      pq.pop();
    } else {
      cout<<"0\n";
    }
  }
  return 0;
}
