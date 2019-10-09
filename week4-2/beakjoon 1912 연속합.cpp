#include <iostream>

using namespace std;

int dp[100001],n,maxnum;

int main(){
	
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	dp[0]=arr[0];
	maxnum=arr[0];
	for(int i=1;i<n;i++){
		dp[i]=max(dp[i-1]+arr[i],arr[i]);
		maxnum=max(maxnum,dp[i]);
	}
	cout<<maxnum;
	
}
