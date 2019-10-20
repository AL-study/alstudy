#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int n,l,p,ans,now,maxnum,idx,i;
vector<pair <int, int > > v;
priority_queue<int> pq;
int main(){
	
	cin>>n;
	for(int i=0;i<n;i++){
		int temp1,temp2;
		cin>>temp1>>temp2;
		v.push_back({temp1,temp2});
	}
	cin>>l>>p;
	sort(v.begin(),v.end());
	while (p < l) {
        while (v[i].first <= p) {
            if (i == n)break;
            pq.push(v[i].second);
            i++;
        }
        if (!pq.size())break;
        ans++;
        p += pq.top();
        pq.pop();
    }
    if(p>=l){
    	cout<<ans;
	}else{
		cout<<-1;
	}
} 
