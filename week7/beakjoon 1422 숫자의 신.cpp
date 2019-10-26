#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
int k,n;
string str[1001];
string ans;

bool compare(string a,string b){
	return a+b>b+a;
}
int main(){
	cin>>k>>n;
	string num[k];
	int gon=0,idx=0;
	for(int i=0;i<k;i++){
		cin>>num[i];
	}
	sort(num,num+k,compare);
	if(n==k){
		for(int i=0;i<k;i++){
			ans+=num[i];
		}
	}else{
		for(int i=0;i<k;i++){
			if(gon<atoi(num[i].c_str())){
				gon=atoi(num[i].c_str());
				idx=i;
			}
		}
		for(int i=0;i<k;i++){
			if(i==idx){
				for(int j=0;j<n-k;j++){
					stringstream s;
					s<<gon;
					ans+=s.str();
				}
			}
			ans+=num[i];
		}
	}
	cout<<ans;
}
