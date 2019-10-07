#include <iostream>

using namespace std;

int dp[1001],n;

int main (){
	cin>>n;
	dp[1]=1;
	dp[2]=3;
	dp[3]=5;
	
	for(int i=4;i<1001;i++){
		dp[i]=(dp[i-2]*2+dp[i-1])%10007;
	}
	cout<<dp[n];
	
}
