#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int t,n,m;
bool arr[1001];
bool compare(pair<int, int> a, pair<int, int> b){	
	if(a.second==b.second){
		return a.first<b.first;	
	}else{
		return a.second<b.second;
	}	
}

int main(){
	vector <pair<int, int> > v;
	cin>>t;
	for(int i=0;i<t;i++){
		memset(arr,false,sizeof(arr));
		int ans=0;
		cin>>n>>m;
		v.clear();
		for(int j=0;j<m;j++){
			int temp1,temp2;
			cin>>temp1>>temp2;
			v.push_back({temp1,temp2});
		}
		sort(v.begin(),v.end(),compare);
		
		for(int j=0;j<v.size();j++){
			for(int k=v[j].first;k<=v[j].second;k++){
				if(!arr[k]){
					arr[k]=true;
					ans++;
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
} 
