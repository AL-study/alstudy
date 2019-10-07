#include <iostream>

using namespace std;

int dp[10001],arr[101],k,n;

int main(){
	dp[0]=1;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n;i++){
		for(int j=arr[i];j<=k;j++){
			dp[j]+=dp[j-arr[i]];
		}
	}
	cout<<dp[k];
}
