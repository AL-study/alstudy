#include <iostream>


using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	if(a<b){
		int temp;
		temp=a;
		a=b;
		b=temp;
	}
	int max=a,min=b;
	while(max%min!=0){
		int tmp=max;
		max=min;
		min=tmp%min;
	}
	int gcd=min;
	int lcm=a*b/gcd;
	
	cout<<gcd<<"\n"<<lcm;
	
	
}
