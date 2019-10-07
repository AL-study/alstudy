#include <iostream>

using namespace std;

int dp[1001],ans,n,maxnum;

int main(){
	cin>>n;
	int arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(arr[i]>arr[j]){
				if(dp[j]>maxnum){
					maxnum=dp[j];
				}
			}
		}
		dp[i]=maxnum+1;
		maxnum=0;
		ans=max(dp[i],ans);
	}
	
	cout<<ans;
}
