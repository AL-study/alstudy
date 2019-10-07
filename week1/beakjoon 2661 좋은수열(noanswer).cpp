#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,num;
string arr;
string temp1,temp2;
void dfs(char start,int depth){
	if(depth==n){
		int len = arr.length();
    	int loop = len / 2;
    	int start = len - 1;
    	int end = len;
	    for (int i = 2; i <= loop; i++) {
			for(int j=0; j<i-1;j++){
				temp1 = arr.substr(j*i,i);
				temp2 = arr.substr((j+1)*i,i);
				//cout<<"aa:"<<temp1<<" "<<temp2<<"\n";

				if(temp1==temp2) return;
			}
    	}
	
		
		cout<<arr;
		exit(0);
		return;
	}
	if(start=='1'){
		arr[depth]='2';
		dfs('2',depth+1);
		arr[depth]='3';
		dfs('3',depth+1);
	}else if(start=='2'){
		arr[depth]='1';
		dfs('1',depth+1);
		arr[depth]='3';
		dfs('3',depth+1);
	}else if(start=='3'){
		arr[depth]='1';
		dfs('1',depth+1);
		arr[depth]='2';
		dfs('2',depth+1);
	}
	
}

int main(){
	
	cin>>n;
	for(int i=0;i<n;i++)
		arr+="M";
	
	
	arr[0]='1';
	dfs('1',1);
	arr[0]='2';
	dfs('2',1);
	arr[0]='3';
	dfs('3',1);
	
}
