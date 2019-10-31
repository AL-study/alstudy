#include <iostream>
#include <math.h>

using namespace std;

int n;
bool num[1000001];

void eratos(){
	for(int i=2;i<sqrt(1000000);i++){
		for(int j=i*2;j<=1000000;j+=i){
			num[j]=true;
		}
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	eratos();
	while(1){
		cin>>n;
		if(n==0){
			break;
		}else{
			for(int i=3;i<10000001;i++){
				if(!num[i]&&!num[n-i]){
					cout<<n<<" = "<<i<<" + "<<n-i<<"\n";
					break;
				}
			}
		}
	}
}
