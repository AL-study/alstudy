#include <iostream>

using namespace std;

int n;
long long m;

bool arrsum(int *arr,int height_temp){
	long long num=0;
	for(int i=0;i<n;i++){
		if(arr[i]-height_temp>0){
			num+=arr[i]-height_temp;
		}
	}
	if(num>=m)return true;
	else return false;
}


int main(){
	cin>>n>>m;
	int arr[n];
	long long low=0,height=-1;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(height<arr[i]){
			height=arr[i];
		}
	}
	
	long long result =0;
	while(low <= height){
		long long mid=(low+height)/2;
		if(arrsum(arr,mid)){
			result=max(result,mid);
			low=mid+1;
		}else{
			height=mid-1;
		}
	}
	cout<<result;
	
	
	return 0;
}
