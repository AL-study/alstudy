#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n,sum; 
priority_queue< int, vector<int>, greater<int> > pq;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		pq.push(temp);
	}
	while(!pq.empty()){
		if(pq.size()==1){
			cout<<sum;
			exit(0);
		}
		int t1=pq.top();
		pq.pop();
		t1+=pq.top();
		pq.pop();
		sum+=t1;
		pq.push(t1);
	}
}



