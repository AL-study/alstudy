#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
int result,ansnum,answnum;
map <string ,pair<int,int> > m;

int main(){
	int n;
	cin>>n;
	
	string nam;
	for(int i=0; i<n;i++){
		string pn,name;
		int ans,mem,time,lan,cleng;
		cin>>pn>>name>>ans>>mem>>time>>lan>>cleng;
		if(ans==4){
			m[name].first+=1;
		}else{
			if(m[name].first==0){
				m[name].second+=1;
			}
		}
	}
	map<string, pair<int, int> >::iterator it;
	for(it = m.begin(); it != m.end(); it++){
		if(it->first=="megalusion"){
			continue;
		}
		if(it->second.first>0){
			ansnum++;
			answnum+=it->second.second;
		}
	}
	if(ansnum+answnum==0){
		cout<<0;
	}else{
		int sub=ansnum+answnum;
		printf("%.12g\n",(double)ansnum/(double)(sub)*100.0);
	}
}
