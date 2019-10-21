#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
int k,n;
string str[1001];
string ans;
/* 
	정렬시 숫자가 높은 순으로 정렬합니다. 
	길이가 다르다면 길이가 작은 수는 그 수의 첫자리부터 반복해서 복사해 추가합니다.
	ex) 98422 와 97의 비교 => 98422와 97979의 비교
*/ 
bool compare(string a,string b){
	int i=0;
	string tempa="";
	string tempb="";
	while(i<a.length()||i<b.length()){
		if(i>=a.length()){
			tempa+=a[i%a.length()];
		}else{
			tempa+=a[i];
		}
		if(i>=b.length()){
			tempb+=b[i%b.length()];
		}else{
			tempb+=b[i];
		}
		i++;
	}
	if(tempa==tempb){
		return a+b>b+a;
	}else{
		return tempa>tempb;
	}
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
