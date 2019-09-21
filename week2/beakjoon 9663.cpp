#include <iostream>
#include <stdlib.h>

using namespace std;
//arr[row][col]�� �ƴ� arr[row]=col or arr[col]=row �� ǥ 
int n,row[15],ans;

bool check(int now){
	for(int j=0;j<now;j++){
		//abs() : ���밪 ���ϴ� �Լ� ->stdlib.h
		if(row[j]==row[now] || abs(row[j]-row[now])==abs(j-now)){
			return false;�� 
		}
	}
	return true;
}

void queen(int now){
	if(now==n){
		ans++;
	}else{
		for(int i=0;i<n;i++){
			row[now]=i;
			if(check(now)){
				queen(now+1);	
			}
		}
	}
}

int main(){
	
	cin>>n;
	queen(0);
	cout<<ans;
	
}
