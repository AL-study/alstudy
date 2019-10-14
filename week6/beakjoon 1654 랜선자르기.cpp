#include <iostream>
#include <climits>
using namespace std;
int k,n;
long long low,height=INT_MAX;
bool possible(int arr[],long long x){
	long long num=0;
	for(int i=0;i<k;i++){
		num+=arr[i]/x;
	}
	if(num>=n){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	cin>>k>>n;
	int arr[k];
	for(int i=0;i<k;i++){
		cin>>arr[i];
		if(height<arr[i]){
			height=arr[i];
		}
	}
	long long result=0;
	while(low<=height){
		long long mid=(low+height)/2;	
		if(possible(arr,mid)){
			low=mid+1;
			result=max(result,mid);
		}else{
			height=mid-1;
		}
	}
	
	cout<<result;

}
