#include <iostream>
#include <list>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	list<int> l;
	for(int i=1;i<=n;i++){
		l.push_back(i);
	}
	list<int>::iterator it=l.begin();
	cout<<"<";
	for(int i=0;i<n-1;i++){
		for(int j=0;j<k-1;j++){
			++it;
			if(it==l.end())it++;	
		}
		cout<<*it<<", ";
		it=l.erase(it);
		if(it==l.end())it++;	
	}
	cout<<*it<<">";
}
