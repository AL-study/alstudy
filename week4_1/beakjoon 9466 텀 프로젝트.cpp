#include <iostream>
#include <cstring>
using namespace std;

int t,n,cnt,arr[100001];
// 싸이클을 확인하기 위한 배열 done 
bool c[100001],done[100001];

void dfs(int start){
	c[start]=true;
	int next=arr[start];
	if(!c[next]){
		dfs(next);
	}else if(!done[next]){
		for(int i=next;i !=start;i=arr[i]){
			cnt++;
		}
		cnt++;
	}
	done[start]=true;
}

int main(){
	cin>>t;
	for(int i=0;i<t;i++){
		memset(c,false,sizeof(c));
		memset(done,false,sizeof(done));
		cnt=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>arr[j];
		}
		for(int j=1;j<=n;j++){
			if(!c[j]){
				dfs(j);
			}
		}
		cout<<n-cnt<<"\n";
	}
}
