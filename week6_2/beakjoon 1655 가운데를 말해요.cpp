#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n,sum,change=1; 
priority_queue<int, vector<int>, greater<int> > pq_min;
priority_queue<int> pq_max;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		// 1. maxheap의 크기가 minheap의 크기와 같거나, maxheap이 1 더 크다. 
		if(pq_max.size()==pq_min.size()){
			pq_max.push(temp);
		}else{
			pq_min.push(temp);
		}
		// 2. maxheap의 top은 minheap의 top보다 작거나 같다. 
		if(!pq_max.empty()&&!pq_min.empty()&&pq_max.top()>pq_min.top()){
			int pq_max_top=pq_max.top(), pq_min_top=pq_min.top();
			pq_max.pop(),pq_min.pop();
			pq_max.push(pq_min_top);
			pq_min.push(pq_max_top);
		}
		cout<<pq_max.top()<<"\n";
	}
}



