#include <iostream>
#include <cmath>

using namespace std;

int n,m,ans;
bool arr[1000001]; 
 
int main(){
	cin>>n>>m;
	arr[1]=true;
	for(int i=2;i<=1000000;i++){
		if(!arr[i]){
			for(int j=i+i;j<=1000000;j+=i){
				arr[j]=true;
			}
		}else{
			continue;	
		} 
	}

	
	for(int i=n;i<=m;i++){
		if(arr[i]==false){
			cout<<i<<"\n";
		}
	}
}
