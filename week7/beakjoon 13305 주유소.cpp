#include <iostream>
#include <climits>
using namespace std;

int n,edge[100001],ver[100001];
long long ans,minnum=INT_MAX;

int main(){
	cin>>n;
	
	for(int i=0;i<n-1;i++){
		cin>>edge[i];
	}
	for(int i=0;i<n;i++){
		cin>>ver[i];
		if(minnum>ver[i]){
			minnum=ver[i];
			ans+=minnum*edge[i];
		}else{
			ans+=minnum*edge[i];
		}
	}
	cout<<ans;
}
