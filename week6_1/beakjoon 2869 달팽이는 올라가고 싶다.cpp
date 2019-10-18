#include <iostream>
using namespace std;
long long a,b,v;
int main(){
	long long x;
	cin>>a>>b>>v;
	if((v-a)%(a-b)!=0){
		x=(v-a)/(a-b);
		x++;
	}else{
		x=(v-a)/(a-b);
	}
	cout<<x+1;
}
