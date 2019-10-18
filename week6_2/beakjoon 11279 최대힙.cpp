#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n; 

priority_queue <int> pq;

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
				cout<<pq.top()<<"\n";

				pq.pop();
			}
		}else{
			pq.push(temp);
		}
	}
} 

