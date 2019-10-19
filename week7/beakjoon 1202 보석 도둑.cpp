#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,k;
long long ans;
priority_queue <int> pq;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	vector <pair<int, int > > jewel; 
	vector<int> bag;
	
	for(int i=0;i<n;i++){
		int temp1,temp2;
		cin>>temp1>>temp2;
		jewel.push_back({temp1,temp2});
	}
	
	for(int j=0;j<k;j++){
		int temp1;
		cin>>temp1;
		bag.push_back(temp1);
	}
	sort(jewel.begin(),jewel.end());
	sort(bag.begin(),bag.end());
	
	for(int i=0,j=0;i<k;i++){
		while(j<n&&jewel[j].first<=bag[i]){
			pq.push(jewel[j++].second);
		}
		if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
	}
	cout<<ans;
}
