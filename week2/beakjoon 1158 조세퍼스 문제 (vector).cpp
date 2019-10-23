#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> v;
	for(int i=1;i<=n;i++){
		v.push_back(i);
	}
	vector<int>::iterator it=v.begin();
	cout<<"<";
	for(int i=0;i<n-1;i++){
		for(int j=0;j<k-1;j++){
			++it;
			if(it==v.end())it=v.begin();	
		}
		cout<<*it<<", ";
		it=v.erase(it);
		if(it==v.end())it=v.begin();	
	}
	cout<<*it<<">";
}
