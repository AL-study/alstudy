#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);
	vector<int> arr;
	vector<int> arr2;
	int n,m,temp;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		arr.push_back(temp);
	}
	sort(arr.begin(),arr.end());
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>temp;
		arr2.push_back(temp);
	}
	for(int i=0;i<m;i++){
		vector<int>::iterator upper = upper_bound(arr.begin(), arr.end(), arr2[i]);
		vector<int>::iterator lower = lower_bound(arr.begin(), arr.end(), arr2[i]);
		cout<<*upper<<" "<<*lower<<" ";
	
	//	cout << upper_bound(arr.begin(), arr.end(), arr2[i]) - lower_bound(arr.begin(), arr.end(), arr2[i]) << " ";
	}
	return 0;
}
