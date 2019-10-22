#include <iostream>
#include <algorithm>
using namespace std;

int k;
int arr[12];
int arr2[12];


void dfs(int start,int depth){
	if(depth==6){
		for(int i=0;i<6;i++){
			cout<<arr2[i]<<" ";
		}
		cout<<"\n";
		return;
	}else{
		for(int i=start;i<k;i++){
			arr2[depth]=arr[i];
			dfs(i+1,depth+1);
		}
	}
}

int main(){
	while(1){
		cin>>k;
		if(k==0)break;
		else{
			for(int i=0;i<k;i++){
				cin>>arr[i];
			}
			dfs(0,0);
			cout<<"\n";
		}
	}
}
