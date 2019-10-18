#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n; 
//이런식으로 구조체 자체를 정의해서 사용 할 수 있다. 
//struct node{
//	int first, second;
//};
//bool operator<(node a, node b){
//		return a.first>b.first;
//} 
//
//priority_queue <node> pq;
priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int,int> > > pq;


int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		if(temp==0){
			if(pq.empty()){
				cout<<"0\n";
			}else{
				if(pq.top().second==-1){
					cout<<pq.top().first*-1<<"\n";
				}else{
					cout<<pq.top().first<<"\n";
				}
				pq.pop();
			}
		}else{
			if(temp>=0){
				pq.push({temp,1});
			}else{
				pq.push({temp*-1,-1});
			}
		}
	}
} 

