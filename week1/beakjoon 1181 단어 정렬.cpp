#include <iostream>
#include <algorithm>
using namespace std;

bool compare(string a,string b){
	if(a.length()>b.length())
		return 0;
	else if(a.length()<b.length())
		return 1;
	else
		return a<b;
}

int main(void){
	int n;
	string data[20000]; 

	cin>>n;
	for(int i=0;i<n;i++){
		cin>>data[i];
	}
	sort(data,data+n,compare);

	for(int i=0;i<n;i++){
		if(i>0&&data[i]==data[i-1])
			continue;
		cout<<data[i]<<'\n';
	}

}
