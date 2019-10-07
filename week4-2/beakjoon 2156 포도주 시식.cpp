#include <iostream>

using namespace std;

int dp[10001],n;

int main(){
	cin>>n;
	int arr[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	dp[1]=arr[1];
	dp[2]=arr[1]+arr[2];
	for(int i=3;i<=n;i++){
		dp[i]=max(dp[i-3]+arr[i-1]+arr[i],dp[i-2]+arr[i]);
		dp[i]=max(dp[i-1],dp[i]);
	}
	
	cout<<dp[n];

}
