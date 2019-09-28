#include <iostream>

using namespace std;
//en= > 10ÀÇ nÁ¦°ö 
int dp[1000001],n;

int main(){
	cin>>n;
	dp[1]=0;
	dp[2]=1;
	dp[3]=1;
	for(int i=4;i<1e6+1;i++){
		if(i%2==0&&i%3==0){
			dp[i]=min(dp[i-1],dp[i/3]);
			dp[i]=min(dp[i],dp[i/2])+1;
		}else if(i%3==0){
			dp[i]=min(dp[i-1],dp[i/3])+1;
		}else if(i%2==0){
			dp[i]=min(dp[i-1],dp[i/2])+1;
		}else{
			dp[i]=dp[i-1]+1;
		}
	}
	cout<<dp[n];
}
