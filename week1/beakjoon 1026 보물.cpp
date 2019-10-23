#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool aa(int a,int b){
	return a>b;
}

int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;
	cin>>n;
	int a[n];
	int b[n];
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	sort(a,a+n);
	sort(b,b+n,aa);
	int answer=0;
	for(int i=0;i<n;i++)answer+=a[i]*b[i];
	cout<<answer;



}

