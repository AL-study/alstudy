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
	
//	for(int j=0;j<v[1].size();j++){
//			if(v[1][j]==')'){
//				if(temp.empty()){
//					cout<<"NO\n";
//					break;
//				}else{
//					temp.pop_back();
//				}
//			}else{
//				temp.push_back(v[1][j]);
//			}
//			if(j==v[1].size()-1&&temp.empty()){
//				cout<<"YES\n";
//			}
//			
//		}
	
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
//			cout<<"j: "<<j<<"\n";
////			for(int k=0;k<temp.size();k++){
////				cout<<"i:"<<i<<"   j:"<<j<<"    temp["<<k<<"]: "<<temp[k]<<"\n";
////			}
			if(j==v[i].size()-1){
				if(temp.empty())cout<<"YES\n";
				else cout<<"NO\n";
			}
			
		}
		
	}
	
	
	
	
	return 0;
}
