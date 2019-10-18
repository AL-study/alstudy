#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string str[11]={
	"..........",
	"AAACC.....",
	".AAA.....Z",
	"..AAAA..C.",
	"...BBBBB..",
	"....BBB...",
	"...ZBBB...",
	"ZZZZAAAC..",
	".....CCCC.",
	"QQ......C.",
	".........."
	};

//string str[2]={
//	"A.B.C.D",
//	".B.C.D." 
//};

int maxnum,temp=1;

int main(){

	vector<pair <char, char> > v;	

	for(int i=0;i<10;i++){
		for(int j=0;j<str[i].length()-1;j++){
			if(str[i][j]!=str[i][j+1] && str[i][j+1]!='.' &&str[i][j]!='.'){
				v.push_back({str[i][j],str[i][j+1]});
				v.push_back({str[i][j+1],str[i][j]});
			}
			if(str[i][j]!=str[i+1][j] && str[i+1][j]!='.' &&str[i][j]!='.'){
				v.push_back({str[i][j],str[i+1][j]});
				v.push_back({str[i+1][j],str[i][j]});
			}
		}
	}
	if(v.size()==0){
		cout<<"0,0";
		return 0;
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<v.size();i++){
		
		cout<<v[i].first<<" "<<v[i].second<<"\n";
	}
	for(int i=0;i<v.size()-1;i++){
		if(v[i].first==v[i+1].first){
			temp++;
		}else{
			maxnum=max(maxnum,temp);
			temp=1;
		}
	}
	
	for(int i=0;i<v.size()-1;i++){
		for(int j=i+1;j<v.size();j++){
			if(v[i].first==v[j].second && v[i].second==v[j].first){
				v.erase(v.begin()+j);
			}		
		}
	}
	
	cout<<maxnum;
	
	cout<<"\n";
	
	for(int i=0;i<v.size();i++){
		
		cout<<v[i].first<<" "<<v[i].second<<"\n";
	}
	
	cout<<v.size()<<" "<<maxnum;
}

