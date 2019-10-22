#include <iostream>
#include <queue>
using namespace std;

int main(){
	int t;
	cin>>t;
	int ans[t];
	for(int i=0;i<t;i++){
		int n,m;
		cin>>n>>m;
		queue<pair<int,int> > q;
		priority_queue<int> pq;
		int count=1;
		for(int j=0;j<n;j++){
			int temp;
			cin>>temp;
			//q.push(pair<int,int>(j,temp));
			q.push({j,temp});
			pq.push(temp);
		}
		while(!q.empty()){
			int index=q.front().first;
			int value=q.front().second;
			q.pop();
			int pq_value=pq.top();
			if(pq_value==value){
				if(index==m){
					ans[i]=count;
					break;
				}
				count++;
				pq.pop();
			}else{
				q.push({index,value});
				//q.push(pair<int,int>(index,value));
			}
			
		}
	}
	for(int i=0;i<t;i++){
		cout<<ans[i]<<"\n";
	}
}
