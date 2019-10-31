#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int n;
bool num[2000001];
vector<int> v;
void eratos(){
	for(int i=2;i<=2000000;i++){
		for(int j=i*2;j<=2000000;j+=i){
			num[j]=true;
		}
	}
}

int main(){
	eratos();
	for(int i=2;i<=2000000;i++){
		if(!num[i]){
			v.push_back(i);
		}
	}
	cin>>n;
	for(int i=0;i<n;i++){
		long long x,y;
		cin>>x>>y;
		long long z=x+y;
		if(z<4){
			cout<<"NO\n";
		}else if(z%2==0){
			cout<<"YES\n";
		}else{
			z-=2;
			bool flag=false;
			for(int i=0;i<v.size()&&(long long)v[i]*v[i]<=z;i++){
				if(z%v[i]==0){
					flag=true;
					break;
				}
			}
			if(flag==true){
				cout<<"NO\n";
			}else{
				cout<<"YES\n";
			}
		}
	}
}
