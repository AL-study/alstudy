#include <iostream>

using namespace std;

int ans[10001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		ans[temp]++;
	}
	for(int i=1;i<10001;i++)
		for(int j=0;j<ans[i];j++)
			cout<<i<<"\n";
}
