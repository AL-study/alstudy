#include <iostream>
#include <list>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		list<int> l;
		list<int>::iterator now=l.begin();
		string func,arr,temp="";
		int num;
		cin>>func;
		cin>>num;
		cin>>arr;
		bool flag=false;
		bool reverse=false;
		for(int j=1;j<arr.length();j++){
			if(arr[j]==','||arr[j]==']'){
				int tempnum=atoi(temp.c_str());
				temp="";
				if(tempnum!=0){
					l.push_back(tempnum);
				}
				
			}else	temp+=arr[j];
		}

		for(int j=0;j<func.length();j++){
			if(func[j]=='R'){
				if(l.empty())continue;
				reverse= !reverse;
			}else{
				if(l.empty()){
					flag=true;
					break;
				}
				if(reverse==true){
					now=--l.end();
					now=l.erase(now);
				}else{
					now=l.begin();
					now=l.erase(now);
				}
				
			}	
		}
		
		if(flag==true){
			cout<<"error\n";
		}else{
			if(l.empty()){
				cout<<"[]\n";
			}
			else{
				if(reverse==true){
					cout<<"[";
					list<int>::iterator it1=l.end();
					it1--;
					for(std::list<int>::iterator it = it1; it != l.begin(); it--){
						
						cout<<*it<<",";
					}
					cout<<*l.begin()<<"]";
					cout<<"\n";
				}else{
					cout<<"[";
					list<int>::iterator it=l.end();
					it--;
					for(std::list<int>::iterator it = l.begin(); it != l.end(); it++){
						if(it==--l.end())continue;
						cout<<*it<<",";
					}
					cout<<*it<<"]";
					cout<<"\n";
				}
			}
		}
	}	
}
