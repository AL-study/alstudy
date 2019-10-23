#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
	if(a.first<b.first)return 1;
	else if(a.first>b.first)return 0;
	else return a.second<b.second;
}

int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;
	cin>>n;
	vector< pair< int, int> > xy;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		xy.push_back(pair<int, int>(x,y));	
	}
	sort(xy.begin(),xy.end(),compare);
	for(int i=0;i<n;i++){
		cout<<xy[i].first<<" "<<xy[i].second<<"\n";	
	}

}

