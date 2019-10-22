#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int temp=a[0];
	cout<<a[0]<<" ";
	for(int i=1;i<n;i++){
		if(temp==a[i])continue;
		else{
			cout<<a[i]<<" ";
			temp=a[i];
		}
	}
}

