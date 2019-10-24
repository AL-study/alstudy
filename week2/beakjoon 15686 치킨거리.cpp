#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
int n,m,c,result=INT_MAX;
vector<pair<int,int> > home, chicken;
vector<int> v;
int main(){
	cin>>n>>m;
	int arr[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			if(arr[i][j]==2){
				c++;
				chicken.push_back({i,j});
			}else if(arr[i][j] == 1){
				home.push_back({i,j});
			}
		}
	}
	for(int i=0;i<c-m;i++){
		v.push_back(0);
	}
	for(int i=0;i<m;i++){
		v.push_back(1);
	}
	do{
		int ans=0;
		for(int i=0;i<home.size();i++){
			int minnum=INT_MAX;
			for(int j=0;j<chicken.size();j++){
				if(v[j]) minnum=min(minnum,abs(home[i].first-chicken[j].first)+abs(home[i].second-chicken[j].second));
			}
			ans+=minnum;
		}
		result=min(ans,result);
	}while(next_permutation(v.begin(),v.end()));
	cout<<result;
	return 0;
}
