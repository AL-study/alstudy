#include <iostream>

using namespace std;

int main(void) {
    int x,y;
    int dp[25][25];
    cin>>x>>y;
    if(x>=25||y>=25){
        cout<<"false";
        return 0;
    }
    int max;
    if(x>y){
        max=x;
    }else{
        max=y;
    }

    for(int i=1;i<max;i++){
        dp[0][i]=1;
        dp[i][0]=1;
    }
    for(int i=1;i<max;i++){
        for(int j=1;j<max;j++){
            dp[j][i]=dp[j-1][i]+dp[j][i-1];
        }
    }
    int a,b;
    cin>>a>>b;
    
    cout<<a+b<<"\n";
    cout<<dp[a][b];
    return 0;
}
