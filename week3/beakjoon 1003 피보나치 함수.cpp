#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair <int ,int > > v(41);
int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	v[0].first=1;
	v[0].second=0;
	v[1].first=0;
	v[1].second=1;
	v[2].first=1;
	v[2].second=1;
	for(int i=3;i<41;i++){
		v[i].first=v[i-1].first+v[i-2].first;
		v[i].second=v[i-1].second+v[i-2].second;
	}
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		cout<<v[temp].first<<" "<<v[temp].second<<"\n";
	}
}
