#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> ans;
    int n;
    cin>>n;
    string str;
    for(int i=0;i<n;i++){
    	cin>>str;
    	if(str=="push_front"){
    		int temp;
    		cin>>temp;
			ans.insert(ans.begin(),temp);    		
		}else if(str=="push_back"){
			int temp;
    		cin>>temp;
			ans.push_back(temp); 
		}else{
			if(str=="pop_back"){
				if(ans.size()==0){
					cout<<"-1\n";
				}else{
					cout<<ans.back()<<"\n";
					ans.pop_back();	
				}
			}else if(str=="pop_front"){
				if(ans.size()==0){
					cout<<"-1\n";
				}else{
					cout<<ans[0]<<"\n";
					ans.erase(ans.begin());	
				}
			}else if(str=="size"){
				cout<<ans.size()<<"\n";
			}else if(str=="empty"){
				if(ans.size()==0)cout<<"1\n";
				else cout<<"0\n";
			}else if(str=="front"){
				if(ans.size()==0)cout<<"-1\n";
				else cout<<ans[0]<<"\n";	
			}else if(str=="back"){
				if(ans.size()==0)cout<<"-1\n";
				else cout<<ans.back()<<"\n";	
			}
		}
	}
    return 0;
} 
