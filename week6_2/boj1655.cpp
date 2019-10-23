#include <iostream>
#include <queue>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  priority_queue<int, vector<int>, greater<int> > minHeap;
  priority_queue<int> maxHeap;
  int N, temp;
  cin>>N;
  for(int i=0; i<N; i++) {
    cin>>temp;
    if(maxHeap.empty() && minHeap.empty()) maxHeap.push(temp);
    else if(maxHeap.size() == minHeap.size()) maxHeap.push(temp);
    else minHeap.push(temp);
    
    if(!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
      int cur = maxHeap.top();
      maxHeap.pop();
      maxHeap.push(minHeap.top());
      minHeap.pop();
      minHeap.push(cur);
    }
    cout<<maxHeap.top()<<"\n";
  }
  return 0;
}
