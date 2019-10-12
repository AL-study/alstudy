#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,start,end,ans;

bool compare(pair<int, int> a, pair<int, int> b){

	if(a.second==b.second){
		return a.first<b.first;
	}else{
		return a.second<b.second;
	}
	
}

int main(){
	vector <pair <int, int > > v;
	
	cin>>n;
	for(int i=0;i<n;i++){
		int temp1,temp2;
		cin>>temp1>>temp2;
		v.push_back({temp1,temp2});
	}

	sort(v.begin(),v.end(),compare);

	for(int i=0;i<n;i++){
		if(v[i].first>=start){
			start=v[i].second;
			ans++;
		}
	}
	cout<<ans;
}

