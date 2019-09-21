#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,sum=0;
	cin>>n;
	vector<int> ans;
	vector<int> arr;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		arr.push_back(num);
	}
	for(int i=0;i<n-1;i++){
		arr[i]=arr[i+1]-arr[i];
	}
	int gcd=arr[0];
	for(int i=1;i<n-1;i++){
		int max=arr[i];
		while(max%gcd!=0){
			int tmp=max;
			max=gcd;
			gcd=tmp%gcd;
		}
	}
	for(int i=0;i<n-1;i++){
		sum-=gcd;
		sum+=arr[i];
	}
	sum/=gcd;

	cout<<sum;

}
