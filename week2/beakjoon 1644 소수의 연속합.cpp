#include <iostream>
using namespace std;

int n,m,ans,sum;
bool arr[4000001]; 
 
int main(){
	cin>>n;
	arr[1]=true;
	for(int i=2;i<=4000000;i++){
		if(!arr[i]){
			for(int j=i+i;j<=4000000;j+=i){
				arr[j]=true;
			}
		}else{
			continue;	
		} 
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	
	for(int i=2;i<=n;i++){
		if(arr[i]==true)continue;
		for(int j=i;j<=n;j++){
			if(arr[j]==false){
					sum+=j;
			}
			if(sum==n){
				ans++;
				break;
			}else if(sum>n){
				break;
			}
		}
		sum=0;
	}
	
	cout<<ans;
}
