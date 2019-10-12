#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	sort(a,a+n);
	int max=0;
	for(int i=0;i<n;i++){
		if(max<a[i]*(n-i)) max=a[i]*(n-i);
	} 
	cout<<max;
} 
