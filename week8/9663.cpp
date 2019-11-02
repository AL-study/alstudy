
#include <iostream>
#include <stdlib.h>

using namespace std;

int n;
int ans;
int a[15];

bool check(int row){
	for(int i =0;i<row;i++){
		if(a[i] == a[row])return false;

		if(abs(i-row) == abs(a[i]-a[row])) return false;
	}
	return true;
}

void go(int rows){
	if (rows == n){
		ans+=1;
	}

	//다음
	//a[rows][col] -> go(rows+1)
	
	for(int col = 0;col<n;col++){
		a[rows] = col;
		
		if(check(rows)){
			go(rows+1);
		}
		a[rows] = 0;
	}
	
	

}
int main(){
	
	scanf("%d",&n);//n*n 체스판에서 퀸 n개를 놓는 방법의 수

	go(0);

	
	printf("%d\n",ans);
	return 0;
}