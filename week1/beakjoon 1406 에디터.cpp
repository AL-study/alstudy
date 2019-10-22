#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;
int main(){
	ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    list<char> ans;
    string str;
    string temp;
    cin>>str;
	for(int i=0;i<str.length();i++)ans.push_back(str[i]);
    int n;
    cin>>n;
    list<char>::iterator iter = ans.end();
    for(int i=0;i<n;i++){
    	list<char>::iterator start=ans.begin(), end=ans.end();
    	cin>>temp;
    	if(temp=="L"&&iter!=start)iter--;
		else if(temp=="D"&&iter!=end)iter++;
		else if(temp=="B"&&iter!=start)iter=ans.erase(--iter);	
		else if(temp=="P"){
    		string temp2="";
    		cin>>temp2;
    		ans.insert(iter,temp2[0]);
		}
	}
	for(std::list<char>::iterator it = ans.begin(); it != ans.end(); it++)cout<<*it;
} 
