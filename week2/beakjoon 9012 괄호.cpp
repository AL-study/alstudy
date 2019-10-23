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
	vector<string> v;

	for(int i=0;i<n;i++){
		string st;
		cin>>st;
		v.push_back(st);
	}
	for(int i=0;i<v.size();i++){
		vector<char> temp;
		for(int j=0;j<v[i].size();j++){
			if(v[i][j]==')'){
				if(temp.empty()){
					cout<<"NO\n";
					break;
				}else{
					temp.pop_back();
				}
			}else{
				temp.push_back(v[i][j]);
			}

			if(j==v[i].size()-1){
				if(temp.empty())cout<<"YES\n";
				else cout<<"NO\n";
			}
			
		}
		
	}
	
	
	
	
	return 0;
}
