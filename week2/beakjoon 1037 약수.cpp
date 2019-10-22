#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
 
int main(){
	vector<int> v;
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	cout<<v[0]*v[n-1];
}
