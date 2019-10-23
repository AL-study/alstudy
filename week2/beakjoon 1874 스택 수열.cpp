#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);
	
	int n;
	cin>>n;
	vector<int> v;
	vector<int> now;
	vector<char> ans;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		v.push_back(num);
	}
	vector<int>::iterator it=v.begin();
	for(int i=1;i<=n;i++){
		now.push_back(i);
		ans.push_back('+');
		while(!now.empty()){
			if(now.back()==*it){
				now.pop_back();
				ans.push_back('-');
				it++;
			}else break;
			
		}
	}
	if(now.empty()){
		for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<"\n";
	}else cout<<"NO";
	
	
	
}
