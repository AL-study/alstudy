#include <iostream>
#include <queue>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, temp;
  priority_queue<int, vector<int>, greater<int> > pq;
  cin>>N;
  for(int i=0; i<N; i++) {
    cin>>temp;
    if(temp) pq.push(temp);
    else if(!pq.empty()) {
      cout<<pq.top()<<"\n";
      pq.pop();
    }
    else {
      cout<<"0\n";
    }
  }
  return 0;
}
