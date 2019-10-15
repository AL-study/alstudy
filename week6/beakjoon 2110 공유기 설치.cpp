#include <iostream>
#include <algorithm>
using namespace std;

int n,c,low,high;

int main(){
	
	cin>>n>>c;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	high=arr[n-1];
	int result=0;
	while(low<=high){
		int mid=(low+high)/2;
		int before_idx=0,num=1;
		for(int i=0;i<n;i++){
			if(arr[i]-arr[before_idx]>=mid){
				before_idx=i;
				num++;
			}
		}
		
		if(num>=c){
			result=max(result,mid);
			low=mid+1;
		}else{
			high=mid-1;
		}
	}
	cout<<result;
}
