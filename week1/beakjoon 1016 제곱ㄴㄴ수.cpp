#include <iostream>
#include <math.h>
using namespace std;
long long minnum,maxnum,cnt;
bool arr[1000001];
int main(){
	cin>>minnum>>maxnum;
	for(long long i=2;i<=sqrt(maxnum);i++){
		long long x=minnum/(i*i);
		if(minnum%(i*i)!=0){
			x++;
		}
		while(x*i*i<=maxnum){
			arr[x*i*i-minnum]=true;
			x++;
		}
	}
	for(int i=0;i<=maxnum-minnum;i++){
		if(!arr[i]){
			cnt++;
		}
	}
	cout<<cnt;
}
