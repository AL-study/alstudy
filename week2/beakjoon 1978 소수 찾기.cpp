#include <iostream>

using namespace std;

int n,ans;
int arr[1001]; 
 
int main(){
	cin>>n;
	arr[1]=1;
	for(int i=2;i<=1000;i++){
		if(!arr[i]){
			for(int j=i+i;j<=1000;j+=i){
				arr[j]=1;
			}
		}else{
			continue;	
		} 
	}

	
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		if(arr[temp]==0){
			ans++;
		}
	}
	cout<<ans;
}
