#include <iostream>
using namespace std;
int main(){
	int n,k,result=0;
	cin>>n;
	int m[n];
	cin>>k;
	for(int i=0;i<n;i++){
		cin>>m[i];
	}
	for(int i=(sizeof(m)/4)-1;i>=0;i--){
		result+=k/m[i];
		k%=m[i];
	}
	cout<<result;	
} 
