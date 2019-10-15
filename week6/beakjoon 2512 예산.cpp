#include <iostream>

using namespace std;

int n;
long long sum,high,low,mid,result,m;

bool possible(int arr[]){
	long long num=0;
	for(int i=0;i<n;i++){
		if(arr[i]>mid){
			num+=mid;
		}else{
			num+=arr[i];
		}
	}
	if(num<=m){
		return true;
	}else return false;
}

int main(){
	
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
		if(high<arr[i]){
			high=arr[i];
		}
	}
	cin>>m;
	if(sum<=m){
		cout<<high;
	}else{
		while(low<=high){
			mid=(high+low)/2;
			if(possible(arr)){
				result=max(result,mid);
				low=mid+1;
			}else{
				high=mid-1;
			}	
		}
		cout<<result;
	}
}
