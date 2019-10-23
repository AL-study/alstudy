#include <iostream>

using namespace std;

int dp[11];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
	cout.tie(0);

	cin>>n;
	
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	
	for(int i=4;i<11;i++){
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	}
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		cout<<dp[temp]<<"\n";
	}
    
    return 0;
}
