#include <iostream>
#include <algorithm>
using namespace std;

int bsearch(int arr[],int start,int end,int x){
	int mid=(start+end)/2;
	if(start>end)return 0;
	if(arr[mid]==x)return 1;
	if(arr[mid]<x)return bsearch(arr,mid+1,end,x);
	else if (arr[mid]>x)return	bsearch(arr,start,mid-1,x);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);
	int n,m;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	cin>>m;
	int arr2[m];
	for(int i=0;i<m;i++)cin>>arr2[i];
	for(int i=0;i<m;i++)cout<<bsearch(arr,0,n-1,arr2[i])<<"\n";
	return 0;
}
